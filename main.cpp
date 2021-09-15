#include "Lexer.h"
#include "iostream"

using namespace std;

int main(int argc, char** argv) {

    if (argv[1]){
        std::string filename = argv[1];
    }
    else {
        cout << "Missing commandline argument\n\n";
    }

    Lexer* lexer = new Lexer();

    // TODO
    cout << "Hello world!";







    delete lexer;
    return 0;
}