//
// Created by eadan on 4/1/2019.
//

#ifndef SCANNER_ERRORREPORTER_H
#define SCANNER_ERRORREPORTER_H
enum ErrorType{
    //De comunicacion
            NotEnoughArguments,
            CouldntOpenFile,
            RollbackError,
            InvalidToken
};
void reportError(ErrorType type);

#endif //SCANNER_ERRORREPORTER_H
