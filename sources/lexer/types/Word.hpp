#ifndef VERDANT_WORD_HPP
#define VERDANT_WORD_HPP

#include "Token.hpp"


class Word : public Token
{
private:
    std::string lexeme;

public:
    Word(int32_t tag, std::string lexeme);

    std::string & get_lexeme();

    virtual std::string to_string() override;
};


#endif //VERDANT_WORD_HPP
