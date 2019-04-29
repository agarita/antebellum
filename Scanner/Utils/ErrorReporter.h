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
            InvalidToken,
            UnknownCharacter
};
void reportError(ErrorType type, void* atrib= nullptr);

#endif //SCANNER_ERRORREPORTER_H
