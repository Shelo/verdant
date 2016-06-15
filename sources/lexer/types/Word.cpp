#include "Word.hpp"

Word::Word(int32_t tag, std::string lexeme):
    Token(tag),
    lexeme(lexeme)
{

}

std::string & Word::get_lexeme()
{
    return lexeme;
}

std::string Word::to_string()
{
    return get_lexeme();
}
