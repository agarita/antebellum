#include <iostream>
#include <unordered_map>
#include "colorTable.h"
#include "Utils/ErrorReporter.h"

bool TokenForNewLine(TokenType type);

int main(int argc, char* argv[]) {
    if(argc<2)
        reportError(NotEnoughArguments);


    Scanner *mysca=new Scanner(argv[1]);
    //
    // mysca.run();
    mysca->Initiize();

    std::ofstream html;
    html.open(".//report.html");
    if (!html.is_open())
        reportError(CouldntOpenFile);


    //This inserts into header
    html << "<!DOCTYPE html><html><head></head><body style='background-color:#000000'>\n"
    << R"( <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css" integrity="sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T" crossorigin="anonymous">)"
    <<"<div class=\"container\"><div class=\"row\">\n"
      "    <div class=\"col-8\">";

    std::unordered_map<TokenType ,int> frequencies;
    Token actualToken = mysca->getToken();
    while (actualToken.type!=t_EOF){

        // This is to avoid blocking the file output
        if(actualToken.type!=t_error){
            ++frequencies[actualToken.type];
            html << "<span style='color:#" << colorTable[actualToken.type] << "' style='font-weight: bold'>" << actualToken.lexeme << " </span>\n";
            if(TokenForNewLine(actualToken.type))
                html<<"<br />";

        }


        actualToken=mysca->getToken();
    }
    html<< R"(</div><div class="col-4"><table class="table table-dark" ><tr><th>Familia</th><th>Frecuencia</th></tr>)";

    for (auto& it: frequencies) {
        html<<"<tr>\n"
            <<"<td>"<<it.first<<"</td>\n"
            <<"<td>"<<it.second<<"</td>\n"
              "  </tr>";
    }

    //This ends the file
    html << "</table></div></body></html>";
    html.close();

    std::cout << "HTML done" << std::endl;
    return EXIT_SUCCESS;




    /*Token t = mysca.getToken();
    while (t.type!=t_EOF){
        std::cout << t.lexeme << std::endl;
        t = mysca.getToken();
    }*/
}

bool TokenForNewLine(TokenType type) {
    switch (type){
        case t_end_ins:
        case t_initum:
        case t_finis:
        case t_furibundus:
        case t_coniugo:
        case t_commutabilis:
        case t_corpus:
        case t_perpetus:
        case t_exemplar:
        case t_firmamentum:
            return true;
    }
    return false;
}