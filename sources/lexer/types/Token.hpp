#ifndef VERDANT_TOKEN_HPP
#define VERDANT_TOKEN_HPP


#include <string>

enum Tag : int32_t
{
    IDENTIFIER = 256,

    AND,
    OR,

    EQUALS,
    NOT_EQUALS,

    IF,
    ELSE,

    RETURN,

    INTEGER,
    FLOAT,
    DOUBLE,

    STRING
};

class Token
{
private:
    int32_t tag;

public:
    Token(int32_t tag);

    int32_t get_tag();

    virtual std::string to_string();
};


#endif //VERDANT_TOKEN_HPP
