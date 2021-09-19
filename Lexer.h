#ifndef LEXER_H
#define LEXER_H
#include <vector>
#include "Automaton.h"
#include "Token.h"

class Lexer
{
private:
    std::vector<Automaton*> automata;
    std::vector<Token*> tokens;

    void CreateAutomata();

    // TODO: add any other private methods here (if needed)


    //Let's make all the numbers we need for a lexer here as well!
    int lineNumber;
    int maxRead;
    Automaton* maxAutomaton;

    Token* newToken;

public:
    Lexer();
    ~Lexer();

    void Run(std::string& input);



    std::string toString() const
    {
        int tokenSize = tokens.size();
        std::stringstream out;

        for(int i = 0; i < tokens.size(); i++){
            out << tokens[i]->toString();
        }
        out << "Total Tokens = "<< tokenSize;
        return out.str();
    }

    friend std::ostream& operator<< (std::ostream& os,  Lexer& myclass)
    {
        os << myclass.toString();
        return os;
    }

};

#endif // LEXER_H

