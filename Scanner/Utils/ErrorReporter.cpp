//
// Created by eadan on 4/1/2019.
//

#include <iostream>
#include "ErrorReporter.h"
void reportError(ErrorType type, void* atrib){
    switch (type){
        case UnknownCharacter:
            std::cout<<"[WARNING] Unknown Character ("<<*(int*)atrib<<")\n";
            return;
        case NotEnoughArguments:
            std::cout<<"[ERROR] Not enough arguments passed to the program";
            exit(EXIT_FAILURE);
        case CouldntOpenFile:
            std::cout<<"[ERROR] Error opening file";
            exit(EXIT_FAILURE);
        case RollbackError:
            std::cout<<"[ERROR] Unable to do rollback on the scanner";
            exit(EXIT_FAILURE); //Todo: Recuperarse de este error
        case InvalidToken:
            std::cout<<"[ERROR] Invalid token found"<<std::endl;
            break;
    }
}