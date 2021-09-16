#include "Lexer.h"
#include "iostream"
#include "ColonAutomaton.h"
#include "ColonDashAutomaton.h"
#include "QueriesFSA.h"

#include <cctype>


using namespace std;

Lexer::Lexer() {
    CreateAutomata();
}

Lexer::~Lexer() {
    // TODO: need to clean up the memory in `automata` and `tokens`
}

void Lexer::CreateAutomata() {
    automata.push_back(new ColonAutomaton());
    automata.push_back(new ColonDashAutomaton());
    automata.push_back(new QueriesFSA());
    // TODO: Add the other needed automata here
}

void Lexer::Run(std::string& input) {



    int inputSize = input.size();


    //We set this to 1
    lineNumber = 1;

    while (input.size() > 0)
    {
        maxRead = 0;
        maxAutomaton = automata[1];
        /*   Each automaton runs with the same input
        foreach automaton in automata {
                inputRead = automaton.Start(input)
                if (inputRead > maxRead) {
                    set maxRead to inputRead
                    set maxAutomaton to automaton
                }
        }*/

        /// Run all the FSA on the input
        for(int i = 0; i < automata.size(); i++){

                unsigned int inputRead = automata[i]->Start(input);
                if (inputRead > maxRead){
                    maxRead = inputRead;
                    maxAutomaton = automata[i];
                }
        }

        // No we put the best match in our tokens
        if (maxRead > 0){
            string tokenInput;
            for (int i =0; i < maxRead;i++){
                tokenInput += input[i];
            }
            newToken = maxAutomaton->CreateToken(tokenInput, lineNumber);
            for (int i = 0; i<maxAutomaton->NewLinesRead(); i++){
                lineNumber++;
            }
            tokens.push_back(newToken);

        }

    }
    // TODO: convert this pseudo-code with the algorithm into actual C++ code
    /*
    set lineNumber to 1
    // While there are more characters to tokenize
    loop while input.size() > 0 {
        set maxRead to 0
        set maxAutomaton to the first automaton in automata

        // TODO: you need to handle whitespace inbetween tokens

        // Here is the "Parallel" part of the algorithm */


        /* Here is the "Max" part of the algorithm
        if maxRead > 0 {
            set newToken to maxAutomaton.CreateToken(...)
                increment lineNumber by maxAutomaton.NewLinesRead()
                add newToken to collection of all tokens
        }
        // No automaton accepted input
        // Create single character undefined token
        else {
            set maxRead to 1
                set newToken to a  new undefined Token
                (with first character of input)
                add newToken to collection of all tokens
        }
        // Update `input` by removing characters read to create Token
        remove maxRead characters from input
    }
    add end of file token to all tokens
    */
}
