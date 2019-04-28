#include <string>
#include <cstring>
#include "Scanner.h"
#include "../Utils/ErrorReporter.h"
/*
void Scanner::run() {
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
                    //if (foward == &buffer[0][BUFFSIZE]) {
                        f=fgets(buffer[1], BUFFSIZE+1, (FILE *) file);
                        foward = buffer[1];
                    } else if (foward == &buffer[1][BUFFSIZE]) {
                        f=fgets(buffer[0], BUFFSIZE+1, (FILE *) file);
                        foward = buffer[0];
                    } else
                        endAll = true;//
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
                currentState=qERROR;
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
                      currentState!=qERROR&&
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
                resqueue.push(tokens[qERROR]);
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
*/
Token Scanner::getToken() {
    Token res;
    State state=q0;
    lexeme="";
    clearStack();
    char c;
    push(bad, bad);
    while (state!=qERROR){
        c=NextChar();
        //inputPos++;

        // If it is q0, reset the lexeme (to avoid whitespaces)
        specialStates:
        switch (state) {
            case q0:
                lexeme="";
                clearStack();
                push(bad, bad);
                break;
            case qBComm:
                if(c!='#')
                    continue;
                break;
            case qHash_Hash:
                if(c!='\n')
                    continue;
                break;
            case qERROR:
                if(tokens.find((State)stack.top().first)==tokens.end()){
                    if(isValidID(lexeme)){
                        lexeme.pop_back();
                        state= static_cast<State>(q1ID +lexeme.size() - 1);
                        clearStack();
                        push(state, input);
                        break;
                    }
                    else if(stack.top().first>=qBeginStr
                            &&stack.top().first<=q30Str){
                        state= static_cast<State>(q1Str);
                        clearStack();
                        push(state, input);
                    }
                    else if(stack.top().first==qBCommHash){
                        state= static_cast<State>(qBComm);
                        clearStack();
                        push(state, input);
                    }

                }
                continue;
                break;
        }
        lexeme+=c;
        c=tolower(c);
        // We already failed
        if(failed.find({state,input})!=failed.end()) {
            break;
        }
        if(tokens.find(state)!=tokens.end()) {
            clearStack();
        }
        push(state, input);
        /*if(tokens.find(state)==tokens.end())
            break;*/
        // Remember that if it is not in the table will return 0
        // which is same as qERROR
        state=nextState[{state,c}];
        if(state==qERROR)
            goto specialStates;
        //c=NextChar();
    }
    while (tokens.find(state)==tokens.end()
            &&static_cast<State>(stack.top().first)!=bad){
        failed.insert({state,input});
        state= static_cast<State>(stack.top().first);
        input = stack.top().second;
        stack.pop();
        lexeme.pop_back();
        Rollback();

    }

    // Find the token type
    if(tokens.find(state)!=tokens.end()){
        res= tokens[state];
        // Add the lexeme
        res.lexeme = (char *) malloc(lexeme.size()+1);
        strcpy(res.lexeme,lexeme.c_str());
    } else{
        reportError(InvalidToken);
        res = Token(t_error);
        res.attrib=input;
        JumpToSafePoint();
    }

    // Remember to return t_EOF infinitely if there is no
    // tokens left to send
    if(state==qEOF)
        Rollback();

    return res;
}

void Scanner::Initiize() {
    //file = fopen(filename, "r");
    file.open(filename);
    input=0;
    fence=0;
    Fill(0);
}

char * Scanner::Fill(int i) {
    //return fgets(buffer+i, BUFFSIZE, (FILE *) file, '\000');
    file.get(buffer+i, BUFFSIZE+1, '\000');
    return nullptr;

}

void Scanner::Rollback() {
    if(input==fence)
        reportError(RollbackError);
    input=(--input)%(2*BUFFSIZE);
}

char Scanner::NextChar() {
    char res = buffer[input];
    input=(++input)%(2*BUFFSIZE);
    if(input%BUFFSIZE==0){
        Fill(input);
        fence=(input+BUFFSIZE)%(2*BUFFSIZE);
    }
    return res;
}

void Scanner::clearStack() {
    std::stack<std::pair<int,int>> empty;
    stack.swap(empty);
}

void Scanner::push(int i, int j) {
    stack.push({i,j});

}

void Scanner::JumpToSafePoint() {
    char c;
    input++;
    c=NextChar();
    while(true){
        switch (c){
            case 0:
            case ' ':
            case '\t':
            case '\n':
            case '.':
                return;

        }
        c=NextChar();
    }

}

bool Scanner::isValidCharForIDs(char c) {
    return isalnum(c);
}

/**
 * Returns if a string is a valid ID OR empty
 * @param str
 * @return
 */
bool Scanner::isValidID(std::string str) {

    return str.empty() ? true:(isalpha(str[0])
    && find_if_not(str.begin()+1, str.end()-1, isalnum) == str.end()-1
    && str.size()<33);
}

