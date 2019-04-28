#include <iostream>
#include "prettyPrinting.h"

int main() {
    char str[20] = "test.txt";
    scanner mysca=scanner(str);
    mysca.run();
    /*Token t = mysca.getToken();
    while (t.type!=t_EOF){
        std::cout << t.lexeme << std::endl;
        t = mysca.getToken();
    }*/
    crearHTML(mysca);
    return 0;
}