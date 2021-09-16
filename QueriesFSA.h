#ifndef CS236_PROJECT1_QUERIESFSA_H
#define CS236_PROJECT1_QUERIESFSA_H

#include "Automaton.h"
#include <string>

class QueriesFSA : public Automaton
{
private:
  void S1(const std::string& input){
      if (input[index] == 'u'){
          inputRead++;
          index++;
          S2(input);
      }
  }
    void S2(const std::string& input){
        if (input[index] == 'e'){
            inputRead++;
            index++;
            S3(input);
        }
    }
    void S3(const std::string& input){
        if (input[index] == 'r'){
            inputRead++;
            index++;
            S4(input);
        }
    }
    void S4(const std::string& input){
        if (input[index] == 'i'){
            inputRead++;
            index++;
            S5(input);
        }
    }
    void S5(const std::string& input){
        if (input[index] == 'e'){
            inputRead++;
            index++;
            S6(input);
        }
    }
    void S6(const std::string& input){
        if (input[index] == 's'){
            inputRead++;
            //accept state!
        }
    }


public:
    QueriesFSA() : Automaton(TokenType:: QUERIES) {}


  void S0(const std::string& input){
        if (input[index] == 'Q'){
            inputRead++;
            index++;
            S1(input);
        }
        else{
            Serr();
        }
    }



};

#endif //CS236_PROJECT1_QUERIESFSA_H
