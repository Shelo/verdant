#ifndef VERDANT_STRING_HPP
#define VERDANT_STRING_HPP


#include "Token.hpp"

class String : public Token
{
private:
    std::string text;

public:
    String(std::string lexeme) :
            Token(Tag::STRING),
            text(lexeme)
    {

    }

    std::string get_text();

    virtual std::string to_string() override;
};


#endif //VERDANT_STRING_HPP
