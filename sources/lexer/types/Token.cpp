#include "Token.hpp"


Token::Token(int32_t tag) :
    tag(tag)
{

}

int32_t Token::get_tag()
{
    return tag;
}

std::string Token::to_string()
{
    return std::string(1, (char) tag);
}
