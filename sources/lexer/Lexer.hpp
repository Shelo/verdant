#ifndef VERDANT_LEXER_HPP
#define VERDANT_LEXER_HPP


#include <vector>
#include <map>
#include <iostream>
#include <sstream>

#include "types/Token.hpp"
#include "types/Word.hpp"
#include "types/String.hpp"

class Lexer
{
private:
    std::vector<std::shared_ptr<Token>> tokens;
    std::map<std::string, std::shared_ptr<Word>> words;

    size_t cursor = 0;
    size_t line = 0;

    char peek;

    std::shared_ptr<std::string> source;

    void reserve(std::shared_ptr<Word> word);

    bool has_next();

    bool next();

    void skip_whitespace();

    bool next_is(char c);

    std::shared_ptr<Token> scan();

    void clean_peek();

    std::shared_ptr<String> match_string();

    void log(std::string key, std::string message);

public:
    Lexer(std::shared_ptr<std::string> source);

    void process();
};


#endif //VERDANT_LEXER_HPP
