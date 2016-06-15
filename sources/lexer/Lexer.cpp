#include "Lexer.hpp"
#include <unistd.h>

Lexer::Lexer(std::shared_ptr<std::string> source) :
    source(source)
{
    reserve(std::make_shared<Word>(Tag::IF, "if"));
    reserve(std::make_shared<Word>(Tag::ELSE, "else"));
    reserve(std::make_shared<Word>(Tag::RETURN, "return"));
}

void Lexer::reserve(std::shared_ptr<Word> word)
{
    words[word->get_lexeme()] = word;
}

void Lexer::process()
{
    peek = source->at(cursor);

    while (has_next()) {
        auto token = scan();

        if (token != nullptr) {
            std::cout << token->to_string() << std::endl;
            tokens.push_back(token);
        }

        usleep(1000 * 100);
    }
}

std::shared_ptr<Token> Lexer::scan()
{
    skip_whitespace();

    switch (peek) {
        case '=':
            if (next_is('=')) {
                return std::make_shared<Word>(Tag::EQUALS, "==");
            } else {
                return std::make_shared<Token>('=');
            }

            break;
        default:
            break;
    }

    // Numbers: [0-9]+(\.[0-9]+f?)?
    if (isdigit(peek)) {
        std::stringstream buffer;
        buffer << peek;

        while (next() && isdigit(peek)) {
            buffer << peek;
        }

        if (peek == '.') {
            buffer << peek;

            while (next() && isdigit(peek)) {
                buffer << peek;
            }

            if (peek == 'f') {
                return std::make_shared<Word>(Tag::FLOAT, buffer.str());
            } else {
                return std::make_shared<Word>(Tag::DOUBLE, buffer.str());
            }
        } else {
            if (isalpha(peek)) {
                if (peek == 'f') {
                    if (next() && isalpha(peek)) {
                        throw "Invalid number at line";
                    }

                    return std::make_shared<Word>(Tag::FLOAT, buffer.str());
                } else {
                    throw "Invalid number";
                }
            }

            return std::make_shared<Word>(Tag::INTEGER, buffer.str());
        }
    }

    // Identifiers [a-zA-Z][a-zA-Z0-9]+
    if (isalpha(peek)) {
        std::stringstream buffer;
        buffer << peek;

        while (next() && isalnum(peek)) {
            buffer << peek;
        }

        std::string lexeme = buffer.str();

        auto iterator = words.find(lexeme);
        if (iterator != words.end()) {
            return iterator->second;

        } else {
            auto token = std::make_shared<Word>(Tag::IDENTIFIER, lexeme);
            reserve(token);

            return token;
        }
    }

    // Strings.
    auto string = match_string();

    if (string != nullptr) {
        return string;
    }

    auto token = std::make_shared<Token>(peek);

    clean_peek();
    return token;
}

bool Lexer::has_next()
{
    return cursor + 1 < source->size();
}

void Lexer::skip_whitespace()
{
    for (;;next()) {
        if (peek == ' ' || peek == '\t') {
            continue;
        } else if (peek == '\n') {
            line++;
        } else {
            break;
        }
    }
}

bool Lexer::next()
{
    cursor++;

    if (cursor < source->size()) {
        peek = source->at(cursor);

        return true;
    }

    return false;
}

bool Lexer::next_is(char c)
{
    if (next()) {
        auto tmp = peek;
        clean_peek();
        return tmp == c;
    }

    return false;
}

bool Lexer::match(char c)
{
    return peek == c;
}

void Lexer::clean_peek()
{
    peek = ' ';
}

std::shared_ptr<String> Lexer::match_string()
{
    if (peek == '"') {
        std::stringstream buffer;
        bool escape = false;

        while (next() && (peek != '"' || escape)) {
            // in case we're encountered with the escape symbol, enable escaping,
            // which lasts for just the next char.
            if (peek == '\\' && !escape) {
                escape = true;

            } else {
                // match specially escaped symbols (\n, \t)
                if (escape) {
                    if (peek == 'n') {
                        buffer << "\n";
                    } else if (peek == 't') {
                        buffer << "\t";
                    } else {
                        buffer << peek;
                    }
                } else {
                    buffer << peek;
                }

                escape = false;
            }
        }

        clean_peek();

        return std::make_shared<String>(buffer.str());
    }

    return nullptr;
}
