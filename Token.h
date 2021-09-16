#ifndef TOKEN_H
#define TOKEN_H
#include <string>

enum class TokenType {
    COLON,
    COLON_DASH,
    QUERIES,
    // TODO: add the other types of tokens
    UNDEFINED
};

class Token
{
private:

    // TODO: add member variables for information needed by Token
    // I'm adding in all of the member variables.
    TokenType type;
    std::string description;
    int line;


public:
    Token(TokenType type, std::string description, int line);

    // TODO: add other needed methods
};

#endif // TOKEN_H

