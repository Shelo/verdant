#include <iostream>
#include "sources/lexer/Lexer.hpp"

using namespace std;

int main() {
    Lexer lexer(std::make_shared<std::string>("if (123f == hello) { return \"Es\\\\ca\\\"pe \\n\t\tthis\"; }"));

    try {
        lexer.process();
    } catch (const char * exception) {
        std::cerr << exception << std::endl;
    }

    return 0;
}
