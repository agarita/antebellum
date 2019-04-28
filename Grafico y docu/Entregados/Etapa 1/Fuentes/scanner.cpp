#include <cstring>
#include "scanner.h"

Token scanner::getToken() {
    if(resqueue.empty())
        return {t_EOF};
    Token res = this->resqueue.front();
    resqueue.pop();
    return res;

}

void scanner::run() {
    currentState = initialState;
    int lineini = 0, colini = 0, line = 0, col = 0,lexsize=0;
    char*f;
    bool inLineComment=false,inBlockComment=false,endAll=false;
    char lexeme[255];
    file = fopen(filename, "r");

    buffer[0][BUFFSIZE ] = '\000';
    buffer[1][BUFFSIZE ] = '\000';

    if (file != NULL) {
        f=fgets(buffer[1], BUFFSIZE+1, (FILE *) file);
        base = buffer[1];
        foward = buffer[1];

        while (true) {
            char character = *foward;
            if(character>='A'&&character<='Z') //todo: Fix this, deberia guardar bien las mayusculas
                character=character-'A'+'a';

            //todo: Por alguna razon no puedo terminar con comentarios de linea un programa
            switch (*foward++) {

                case '\n':
                    line++;
                    col = 0;
                    inLineComment=false;
                    if(qHash_Hash)
                        currentState=q0;

                    break;
                case '\000':
                    /*if (foward == &buffer[0][BUFFSIZE]) {
                        f=fgets(buffer[1], BUFFSIZE+1, (FILE *) file);
                        foward = buffer[1];
                    } else if (foward == &buffer[1][BUFFSIZE]) {
                        f=fgets(buffer[0], BUFFSIZE+1, (FILE *) file);
                        foward = buffer[0];
                    } else
                        endAll = true;*/
                    strncpy(buffer[0], buffer[1], BUFFSIZE);
                    f=fgets(buffer[1], BUFFSIZE+1, (FILE *) file);
                    if(f==NULL) {
                        endAll=true;
                        inLineComment= false;
                    }
                    else {
                        foward = buffer[1];
                    }
                    continue;
                    break;
            }

            col++;

            switch (currentState){
                case q0:
                    lineini = line;
                    colini = col;
                    lexsize=0;
                    base = foward;
                    break;
                case qLT_Hash:
                    inBlockComment=true;
                    currentState=q0;
                    break;
                case qHash:
                    if (character=='>'){
                        inBlockComment= false;
                        currentState=q0;
                        continue;

                    }
                    if(inBlockComment)
                        currentState=q0;
                    break;

                case qHash_Hash:
                    inLineComment=true;
                    break;

            }

            //Esto es para fumar comentarios
            if ((inLineComment||(inBlockComment&&character!='#'))&&!endAll)
                continue;

            if (this->nextState.find(std::make_pair(currentState, character)) !=
                this->nextState.end()) {   //Si hay un siguiente estado
                currentState = this->nextState[std::make_pair(currentState,
                                                              character)];                    //Vaya traigalo, no sea vago
                lexeme[lexsize++] = character;

            } else if(currentState==qBeginChr&&character!='\''){
                currentState = qChar;
                lexeme[lexsize++] = character;

            } else if(currentState==q31Str||currentState==qChar){
                currentState=s_error_not_in_automata;
                foward--;
                lexsize--;
                col--;
            } else if (currentState<qFinalizeStr&&currentState>=qBeginStr) {//Si son validos, nos pasamos a los estados de id
                    currentState = static_cast<State>(static_cast<int>(currentState) + 1);
                    lexeme[lexsize++] = character;

            }else if (currentState!=qFinalizeStr&&
                      currentState!=qFinalizeChr&&
                      currentState!=qChar&&
                      currentState!=q0&&
                      currentState!=s_error_not_in_automata&&
                      !(currentState>=qm3&&currentState<=qm32768)&&
                      !(currentState>=q3&&currentState<=q32767)&&
                      (('0' <= character && character <= '9') ||
                       ('a' <= character && character <= 'z'))) {//Si son validos, nos pasamos a los estados de id
                currentState = static_cast<State>(static_cast<int>(q1ID) + lexsize );
                lexeme[lexsize++] = character;
            } else if (tokens.find(currentState) !=
                       tokens.end()) {                                         //No habia? bueno, el ultimo estado tiene token?
                auto res = tokens[currentState];                                                            //Vamo' a guardarlo
                res.line = lineini;
                res.column = colini;

                res.lexeme = (char *) malloc(lexsize);
                lexeme[lexsize] = '\000';
                strncpy(res.lexeme, lexeme, lexsize+1);
                foward--;
                lineini = line;
                colini = --col;
                base = foward;
                resqueue.push(
                        res);                                                                         //Guardemos ese tokensillo
                currentState = q0;
            } else {
                resqueue.push(tokens[s_error_not_in_automata]);
                currentState = q0;
                lineini = line;
                colini = --col;
                //No tenia token? We got a problemirijillo  (Creo que en la tabla de estrellas deberia tener un valor de 1 o 0, not sure)
                //continue;
            }


            if (endAll)
                return;
        }
    }

}

