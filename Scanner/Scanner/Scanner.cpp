#include <string>
#include <cstring>
#include "Scanner.h"
#include "../Utils/ErrorReporter.h"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "hicpp-avoid-goto"
Token Scanner::getToken() {
    init:
    short strCounter = 0;
    lexeme = "";
    clearStack();
    char c;
    push(bad);
    goto q0;

    q0:
    c = NextChar();
    lexeme+=c;
    push(q0);
    switch (c) {
        default:
            reportError(UnknownCharacter, &c);
            goto out;
        case ' ':
        case '\t':
        case '\n':
            goto init;
            break;
        case '\000':
            clearStack();
            push(qEOF);
            goto out;
        case 'b':
        case 'B':
        case 'h':
        case 'H':
        case 'j':
        case 'J':
        case 'k':
        case 'w':
        case 'y':
        case 'z':
        case 'K':
        case 'W':
        case 'Y':
        case 'Z':
            goto q1ID;
        case 'a':
        case 'A':
            goto qa;
        case 'c':
        case 'C':
            goto qc;
        case 'd':
        case 'D':
            goto qd;
        case 'e':
        case 'E':
            goto qe;
        case 'f':
        case 'F':
            goto qf;
        case 'i':
        case 'I':
            goto qi;
        case 'l':
        case 'L':
            goto ql;
        case 'g':
        case 'G':
            goto qg;
        case 'm':
        case 'M':
            goto qm;
        case 'o':
        case 'O':
            goto qo;
        case 'n':
        case 'N':
            goto qn;
        case 'p':
        case 'P':
            goto qp;
        case 'q':
        case 'Q':
            goto qq;
        case 'r':
        case 'R':
            goto qr;
        case 's':
        case 'S':
            goto qs;
        case 't':
        case 'T':
            goto qt;
        case 'u':
        case 'U':
            goto qu;
        case 'v':
        case 'V':
            goto qv;
        case 'x':
        case 'X':
            goto qx;
        case '{':
            goto qLCB;
        case '}':
            goto qRCB;
        case '.':
            goto qDot;
        case ':':
            goto qColon;
        case '@':   
            goto qAt;
        case '\'':
            goto qBeginChr;
        case '(':
            goto qPI;
        case ')':
            goto qPD;
        case '#':
            goto qHash;
        case '<':
            goto qLT; 
        case'[':
            goto qLSB;
        case ']':
            goto qRSB;
        case ',':
            goto qComma;
        case '&':
            goto qAnd;
        case '=':
            goto qEquals;
        case'>':
            goto qGT;
        case '\"':
            strCounter=0;
            goto qBeginStr;
        case '-':
            goto qMinus;
        case '+':
            goto qPlus;
        case '*':
            goto qMult;
        case '%':
            goto qPercent;
        case '/':
            goto qDiv;
        case '|':
            goto qPipe;
        case '1':
        case '2':
            goto qNumDec8;
        case '3':
            goto qNumDec11;
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            goto qNumDec2;
        case '0':
            goto qZero;
    }

    qNumDec2:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qNumDec);
    switch (c) {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            goto qNumDec4;
        default:
            goto out;
    }
    qNumDec3:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qNumDec);
    switch (c) {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
            goto qNumDec4;
        case '7':
            goto qNumDec9;
        case '8':
        case '9':
            goto qNumDec10;
        default:
            goto out;
    }
    qNumDec4:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qNumDec);
    switch (c) {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            goto qNumDec10;
        default:
            goto out;
    }

    //El 5 es el -
    qNumDec6:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qNumDec);
    switch (c) {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
            goto qNumDec4;
        case '7':
            goto qNumDec12;
        case '8':
        case '9':
            goto qNumDec10;
        default:
            goto out;
    }
    qNumDec7:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qNumDec);
    goto out;

    qNumDec8:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qNumDec);
    switch (c) {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            goto qNumDec2;
        default:
            goto out;
    }
    qNumDec9:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qNumDec);
    switch (c) {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
            goto qNumDec10;
        case '6':
            goto qNumDec13;
        case '7':
        case '8':
        case '9':
            goto qNumDec7;
        default:
            goto out;
    }

    qNumDec10:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qNumDec);
    switch (c) {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            goto qNumDec7;
        default:
            goto out;
    }
    qNumDec11:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qNumDec);
    switch (c) {
        case '0':
        case '1':
            goto qNumDec2;
        case '2':
            goto qNumDec3;
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            goto qNumDec4;
        default:
            goto out;
    }
    qNumDec12:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qNumDec);
    switch (c) {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
            goto qNumDec10;
        case '6':
            goto qNumDec14;
        case '7':
        case '8':
        case '9':
            goto qNumDec7;
        default:
            goto out;
    }
    qNumDec13:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qNumDec);
    switch (c) {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
            goto qNumDec7;
        default:
            goto out;
    }
    qNumDec14:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qNumDec);
    switch (c) {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
            goto qNumDec7;
        default:
            goto out;
    }
    qNumDec15:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qNumDec);
    switch (c) {
        case '0':
        case '1':
            goto qNumDec2;
        case '2':
            goto qNumDec6;
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            goto qNumDec4;
        default:
            goto out;
    }
    qZero:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qNumDec);
    switch (c) {
        case 'r':
        case 'R':
            goto qNumRomMid;
        case 'x':
        case 'X':
            goto qNumHexMid;
        default:
            goto out;
    }



    qNumHexMid:
    c = NextChar();
    lexeme+=c;
    push(qNumHexMid);
    switch (c) {
        case '0':
            goto qNumHex5;
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
            goto qNumHex7;
        case '8':
        case '9':
        case 'a':
        case 'A':
        case 'b':
        case 'B':
        case 'c':
        case 'C':
        case 'd':
        case 'D':
        case 'e':
        case 'E':
        case 'f':
        case 'F':
            goto qNumHex2;
        default:
            goto out;//TODO: Report empty hex numeral
    }

    qNumHex2:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qNumHex);
    switch (c) {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        case 'a':
        case 'A':
        case 'b':
        case 'B':
        case 'c':
        case 'C':
        case 'd':
        case 'D':
        case 'e':
        case 'E':
        case 'f':
        case 'F':
            goto qNumHex3;
        default:
            goto out;
    }

    qNumHex3:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qNumHex);
    switch (c) {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        case 'a':
        case 'A':
        case 'b':
        case 'B':
        case 'c':
        case 'C':
        case 'd':
        case 'D':
        case 'e':
        case 'E':
        case 'f':
        case 'F':
            goto qNumHex5;
        default:
            goto out;
    }
    qNumHex5:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qNumHex);
    goto out;

    qNumHex7:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qNumHex);
    switch (c) {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        case 'a':
        case 'A':
        case 'b':
        case 'B':
        case 'c':
        case 'C':
        case 'd':
        case 'D':
        case 'e':
        case 'E':
        case 'f':
        case 'F':
            goto qNumHex2;
        default:
            goto out;
    }

    // NUMEROS ROMANOS
    qNumRomMid:
    c = NextChar();
    lexeme+=c;
    push(qNumRomMid);
    switch (c) {
        case 'c':
        case 'C':
            goto qNumRom5;
        case 'd':
        case 'D':
            goto qNumRom6;
        case 'i':
        case 'I':
            goto qNumRom7;
        case 'l':
        case 'L':
            goto qNumRom8;
        case 'm':
        case 'M':
            goto qNumRom9;
        case 'v':
        case 'V':
            goto qNumRom10;
        case 'x':
        case 'X':
            goto qNumRom11;
        default:
            goto out;//TODO: Report empty roman numeral
    }

    qNumRom6:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qNumRom);
    switch (c) {
        case 'c':
        case 'C':
            goto qNumRom14;
        case 'i':
        case 'I':
            goto qNumRom7;
        case 'l':
        case 'L':
            goto qNumRom8;
        case 'v':
        case 'V':
            goto qNumRom10;
        case 'x':
        case 'X':
            goto qNumRom11;
        default:
            goto out;
    }

    qNumRom14:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qNumRom);
    switch (c) {
        case 'c':
        case 'C':
            goto qNumRom12;
        case 'i':
        case 'I':
            goto qNumRom7;
        case 'l':
        case 'L':
            goto qNumRom8;
        case 'v':
        case 'V':
            goto qNumRom10;
        case 'x':
        case 'X':
            goto qNumRom11;
        default:
            goto out;
    }

    qNumRom8:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qNumRom);
    switch (c) {
        case 'i':
        case 'I':
            goto qNumRom7;
        case 'v':
        case 'V':
            goto qNumRom10;
        case 'x':
        case 'X':
            goto qNumRom17;
        default:
            goto out;
    }

    qNumRom10:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qNumRom);
    switch (c) {
        case 'i':
        case 'I':
            goto qNumRom19;
        default:
            goto out;
    }

    qNumRom19:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qNumRom);
    switch (c) {
        case 'i':
        case 'I':
            goto qNumRom15;
        default:
            goto out;
    }

    qNumRom9:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qNumRom);
    switch (c) {
        case 'c':
        case 'C':
            goto qNumRom5;
        case 'd':
        case 'D':
            goto qNumRom6;
        case 'i':
        case 'I':
            goto qNumRom7;
        case 'l':
        case 'L':
            goto qNumRom8;
        case 'm':
        case 'M':
            goto qNumRom18;
        case 'v':
        case 'V':
            goto qNumRom10;
        case 'x':
        case 'X':
            goto qNumRom11;
        default:
            goto out;
    }

    qNumRom18:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qNumRom);
    switch (c) {
        case 'c':
        case 'C':
            goto qNumRom5;
        case 'd':
        case 'D':
            goto qNumRom6;
        case 'i':
        case 'I':
            goto qNumRom7;
        case 'l':
        case 'L':
            goto qNumRom8;
        case 'm':
        case 'M':
            goto qNumRom21;
        case 'v':
        case 'V':
            goto qNumRom10;
        case 'x':
        case 'X':
            goto qNumRom11;
        default:
            goto out;
    }

    qNumRom21:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qNumRom);
    switch (c) {
        case 'c':
        case 'C':
            goto qNumRom5;
        case 'd':
        case 'D':
            goto qNumRom6;
        case 'i':
        case 'I':
            goto qNumRom7;
        case 'l':
        case 'L':
            goto qNumRom8;
        case 'v':
        case 'V':
            goto qNumRom10;
        case 'x':
        case 'X':
            goto qNumRom11;
        default:
            goto out;
    }

    qNumRom11:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qNumRom);
    switch (c) {
        case 'c':
        case 'C':
        case 'l':
        case 'L':
            goto qNumRom2;
        case 'i':
        case 'I':
            goto qNumRom7;
        case 'v':
        case 'V':
            goto qNumRom10;
        case 'x':
        case 'X':
            goto qNumRom20;
        default:
            goto out;
    }

    qNumRom2:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qNumRom);
    switch (c) {
        case 'i':
        case 'I':
            goto qNumRom7;
        case 'v':
        case 'V':
            goto qNumRom10;
        default:
            goto out;
    }

    qNumRom17:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qNumRom);
    switch (c) {
        case 'i':
        case 'I':
            goto qNumRom7;
        case 'v':
        case 'V':
            goto qNumRom10;
        case 'x':
        case 'X':
            goto qNumRom20;
        default:
            goto out;
    }

    qNumRom20:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qNumRom);
    switch (c) {
        case 'i':
        case 'I':
            goto qNumRom7;
        case 'v':
        case 'V':
            goto qNumRom10;
        case 'x':
        case 'X':
            goto qNumRom12;
        default:
            goto out;
    }



    qNumRom12:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qNumRom);
    switch (c) {
        case 'c':
        case 'C':
            goto qNumRom13;
        case 'i':
        case 'I':
            goto qNumRom7;
        case 'l':
        case 'L':
            goto qNumRom8;
        case 'v':
        case 'V':
            goto qNumRom10;
        case 'x':
        case 'X':
            goto qNumRom11;
        default:
            goto out;
    }

    qNumRom5:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qNumRom);
    switch (c) {
        case 'c':
        case 'C':
            goto qNumRom12;
        case 'd':
        case 'D':
        case 'm':
        case 'M':
            goto qNumRom13;
        case 'i':
        case 'I':
            goto qNumRom7;
        case 'l':
        case 'L':
            goto qNumRom8;
        case 'v':
        case 'V':
            goto qNumRom10;
        case 'x':
        case 'X':
            goto qNumRom11;
        default:
            goto out;
    }

    qNumRom13:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qNumRom);
    switch (c) {
        case 'i':
        case 'I':
            goto qNumRom7;
        case 'l':
        case 'L':
            goto qNumRom8;
        case 'v':
        case 'V':
            goto qNumRom10;
        case 'x':
        case 'X':
            goto qNumRom11;
        default:
            goto out;
    }

    qNumRom7:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qNumRom);
    switch (c) {
        case 'i':
        case 'I':
            goto qNumRom15;
        case 'v':
        case 'V':
        case 'x':
        case 'X':
            goto qNumRom16;
        default:
            goto out;
    }

    qNumRom15:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qNumRom);
    switch (c) {
        case 'i':
        case 'I':
            goto qNumRom16;
        default:
            goto out;
    }

    qNumRom16:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qNumRom);
    goto out;



    qLSB:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qLSB);
    switch (c) {
        case '>':
            goto qLSB_GT;
        case '<':
            goto qLSB_LT;
        case '&':
            goto qLSB_and;
        case '#':
            goto qLSB_hash;
        default:
           goto out;
    }

    qLSB_GT:
    c = NextChar();
    lexeme+=c;
    push(qLSB_GT);
    if(c=='>')
        goto qLSB_GT_GT;
    else
        goto out;
    
    qLSB_GT_GT:
    c = NextChar();
    lexeme+=c;
    push(qLSB_GT_GT);
    if(c==']')
        goto qLSB_GT_GT_RSB;
    else
        goto out;

    qLSB_GT_GT_RSB:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qLSB_GT_GT_RSB);
    goto out;

    qLSB_LT:
    c = NextChar();
    lexeme+=c;
    push(qLSB_LT);
    if(c=='<')
        goto qLSB_LT_LT;
    else
        goto out;
    
    qLSB_LT_LT:
    c = NextChar();
    lexeme+=c;
    push(qLSB_LT_LT);
    if(c==']')
        goto qLSB_LT_LT_RSB;
    else
        goto out;

    qLSB_LT_LT_RSB:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qLSB_LT_LT_RSB);
    goto out;

    qLSB_and:
    c = NextChar();
    lexeme+=c;
    push(qLSB_and);
    if(c=='?')
        goto qLSB_and_question;
    else
        goto out;
    
    qLSB_and_question:
    c = NextChar();
    lexeme+=c;
    push(qLSB_and_question);
    if(c==']')
        goto qLSB_and_question_RSB;
    else
        goto out;

    qLSB_and_question_RSB:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qLSB_and_question_RSB);
    goto out;

    qLSB_hash:
    c = NextChar();
    lexeme+=c;
    push(qLSB_hash);
    if(c=='?')
        goto qLSB_hash_question;
    else
        goto out;
    
    qLSB_hash_question:
    c = NextChar();
    lexeme+=c;
    push(qLSB_hash_question);
    if(c==']')
        goto qLSB_hash_question_RSB;
    else
        goto out;

    qLSB_hash_question_RSB:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qLSB_hash_question_RSB);
    goto out;


    qRSB:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qRSB);
    goto out;

    qComma:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qComma);
    goto out;

    qAnd:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qAnd);
    switch (c) {
        case '#':
            goto qAnd_hash;
        case '+':
            goto qAnd_plus;
        case '?':
            goto qAnd_question;
        default:
            goto out;
    }

    qAnd_hash:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qAnd_hash);
    goto out;

    qAnd_plus:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qAnd_plus);
    if(c=='=')
        goto qAnd_plus_equals;
    else
        goto out;

    qAnd_plus_equals:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qAnd_plus_equals);
    goto out;

    qAnd_question:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qAnd_question);
    if(c=='=')
        goto qAnd_question_equals;
    else
        goto out;

    qAnd_question_equals:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qAnd_question_equals);
    goto out;


    qPlus:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qPlus);
    if(c=='=') 
        goto qPlus_equals;
    else
        goto out;

    qPlus_equals:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qPlus_equals);
    goto out;

    qMult:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qMult);
    if(c=='=') 
        goto qMult_equals;
    else
        goto out;

    qMult_equals:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qMult_equals);
    goto out;

    qPercent:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qPercent);
    if(c=='=') 
        goto qPercent_equals;
    else
        goto out;

    qPercent_equals:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qPercent_equals);
    goto out;

    qDiv:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qDiv);
    if(c=='=') 
        goto qDiv_equals;
    else
        goto out;

    qDiv_equals:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qDiv_equals);
    goto out;

    qPipe:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qPipe);
    switch (c) {
        case '+':
            goto qPipe_Plus;
        case '-':
            goto qPipe_Minus;
        case '*':
            goto qPipe_Mult;
        case '/':
            goto qPipe_Div;
        case '^':
            goto qPipe_Up;
        case '>':
            goto qPipe_GT;
        case '<':
            goto qPipe_LT;
        case '|':
            goto qPipe_Pipe;
        default:
            goto out;
    }

    qPipe_Plus:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qPipe_Plus);
    if (c=='=')
        goto qPipe_Plus_equals;
    else
        goto out;

    qPipe_Plus_equals:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qPipe_Plus_equals);
    goto out;

    qPipe_Minus:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qPipe_Minus);
    if (c=='=')
        goto qPipe_Minus_equals;
    else
        goto out;

    qPipe_Minus_equals:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qPipe_Minus_equals);
    goto out;

    qPipe_Mult:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qPipe_Mult);
    if (c=='=')
        goto qPipe_Mult_equals;
    else
        goto out;

    qPipe_Mult_equals:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qPipe_Mult_equals);
    goto out;

    qPipe_Div:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qPipe_Div);
    if (c=='=')
        goto qPipe_Div_equals;
    else
        goto out;

    qPipe_Div_equals:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qPipe_Div_equals);
    goto out;

    qPipe_Up:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qPipe_Up);
    goto out;

    qPipe_GT:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qPipe_GT);
    goto out;

    qPipe_LT:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qPipe_LT);
    goto out;

    qPipe_Pipe:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qPipe_Pipe);
    goto out;





    qMinus:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qMinus);
    switch (c) {
        case '>':
            goto qMinus_GT;
        case '=':
            goto qMinus_equals;
        case '1':
        case '2':
            goto qNumDec8;
        case '3':
            goto qNumDec15;
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            goto qNumDec2;
        default:
            goto out;
    }

    qMinus_GT:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qMinus_GT);
    goto out;

    qMinus_equals:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qMinus_equals);
    goto out;


    qBeginStr:
    strCounter++; //Esto es para evitar hacer los 31 estados de cada string
    c = NextChar();
    lexeme+=c;
    push(qBeginStr);
    if(c=='\"')
        goto qFinalizeStr;
    else if (strCounter<31)
        goto qBeginStr;
    else
        goto out; //TODO: Reportar error de string muy grande y saltar al proximo \"

    qFinalizeStr: //TODO again, no estoy seguro si leer un chr mas
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qFinalizeStr);
    goto out;



    qGT:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qGT);
    switch (c) {
        case '=':
            goto qGT_equals;
        case '<':
            goto qGT_LT;
        default:
            goto out;
    }

    qGT_equals:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qGT_equals);
    goto out;

    qGT_LT:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qGT_LT);
    goto out;

    qLT:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qLT);
    switch (c) {
        case '#':
            goto qBComm;
        case '=':
            goto qLT_equals;
        case '-':
            goto qLT_Minus;
        default:
            goto out;
    }

    qLT_equals:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qLT_equals);
    goto out;

    qLT_Minus:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qLT_Minus);
    goto out;

    qBComm:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qBComm);
    if(c=='#') 
        goto qBCommHash;
    else
        goto qBComm;

    qBCommHash:
    c = NextChar();
    lexeme+=c;
    push(qBCommHash);
    if(c=='>'){
        clearStack();
        goto init;

    } else if(c=='#')
        goto qBCommHash;
    else
        goto qBComm;



    // TODO revisar que los parentesis, equals y .... no me acuerdo
    // no se si deberian obtener un nuevo simbolo o no

    qEquals:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qEquals);
    goto out;


    qPI:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qPI);
    goto out;

    qPD:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qPD);
    goto out;


    qBeginChr:
    c = NextChar();
    lexeme+=c;
    push(qBeginChr);
    if(c<=127) // TODO Revisar esta condicion
        goto qChar;
    else
        goto out;

    // COMENTARIOS

    qHash:
    c = NextChar();
    lexeme+=c;
    push(qHash);
    if(c=='#')
        goto qHash_Hash;
    else if(c=='>')
        goto qHash_GT;
    else
        goto out;

    qHash_GT:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qHash_GT); // TODO: Report ending comment block without start
    goto out;

    qHash_Hash:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qHash_Hash);
    if(c=='\n'){
        clearStack();// Esto es para evitar que se pushee un token de comentario
        goto init;
    }
    else
        goto qHash_Hash;

    // FIN DE COMENTARIOS

    qChar:
    c = NextChar();
    lexeme+=c;
    push(qChar);
    if(c=='\'')
        goto qFinalizeChar;
    else
        goto out;

    qFinalizeChar:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qFinalizeChr);
    goto out;


    qAt:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qAt);
    if (c=='@')
        goto qAt_At;
    else
        goto out;

    qAt_At:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qAt_At);
    goto out;

    qa:
    c = NextChar();
    lexeme+=c;
    push(qa);
    switch (c) {
        case 'e':
        case 'E':
            goto qae;
        case 'u':
        case 'U':
            goto qau;
        default:
            if (isalnum(c))
                goto q2ID;
            else
                goto out;
    }

    qae:
    c = NextChar();
    lexeme+=c;
    push(qae);
    if (c=='g'||c=='G')
        goto qaeg;
    else if (isalnum(c))
        goto q3ID;
    else
        goto out;

    qaeg:
    c = NextChar();
    lexeme+=c;
    push(qaeg);
    if (c=='e'||c=='E')
        goto qaege;
    else if (isalnum(c))
        goto q4ID;
    else
        goto out;

    qaege:
    c = NextChar();
    lexeme+=c;
    push(qaege);
    if (c=='r'||c=='R')
        goto qaeger;
    else if (isalnum(c))
        goto q5ID;
    else
        goto out;

    qaeger:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qaeger);
    if (isalnum(c))
        goto q6ID;
    else
        goto out;

    qau:
    c = NextChar();
    lexeme+=c;
    push(qau);
    switch (c){
        case 'c':
        case 'C':
            goto qauc;
        case 't':
        case 'T':
            goto qaut;
        default:
            if (isalnum(c))
                goto q3ID;
            else
                goto out;
    }

    qauc:
    c = NextChar();
    lexeme+=c;
    push(qauc);
    if (c=='t'||c=='T')
        goto qauct;
    else if (isalnum(c))
        goto q4ID;
    else
        goto out;

    qauct:
    c = NextChar();
    lexeme+=c;
    push(qauct);
    if (c=='u'||c=='U')
        goto qauctu;
    else if (isalnum(c))
        goto q5ID;
    else
        goto out;

    qauctu:
    c = NextChar();
    lexeme+=c;
    push(qauctu);
    if (c=='m'||c=='M')
        goto qauctum;
    else if (isalnum(c))
        goto q6ID;
    else
        goto out;
    
    qauctum:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qauctum);
    if (isalnum(c))
        goto q7ID;
    else
        goto out;
    
    qaut:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qaut);
    switch (c){
        case '=':
            goto qaut_equals;
        case 'e':
        case 'E':
            goto qaute;
        default:
            if (isalnum(c))
                goto q4ID;
            else
                goto out;
    }

    
    qaut_equals:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qaut_equals);
    goto out;

    
    qaute:
    c = NextChar();
    lexeme+=c;
    push(qaute);
    if (c=='m'||c=='M')
        goto qautem;
    else if (isalnum(c))
        goto q5ID;
    else
        goto out;
    
    qautem:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qautem);
    if (isalnum(c))
        goto q6ID;
    else
        goto out;
    
    qc:
    c = NextChar();
    lexeme+=c;
    push(qc);
    switch (c){
        case 'a':
        case 'A':
            goto qca;
        case 'e':
        case 'E':
            goto qce;
        case 'l':
        case 'L':
            goto qcl;
        case 'o':
        case 'O':
            goto qco;
        default:
            if (isalnum(c))
                goto q2ID;
            else
                goto out;
    }
    
    qca:
    c = NextChar();
    lexeme+=c;
    push(qca);
    switch (c){
        case 's':
        case 'S':
            goto qcas;
        case 't':
        case 'T':
            goto qcat;
        default:
            if (isalnum(c))
                goto q3ID;
            else
                goto out;
    }
    
    qcat:
    c = NextChar();
    lexeme+=c;
    push(qcat);
    if (c=='e'||c=='E')
        goto qcate;
    else if (isalnum(c))
        goto q4ID;
    else
        goto out;
    
    qcate:
    c = NextChar();
    lexeme+=c;
    push(qcate);
    if (c=='n'||c=='N')
        goto qcaten;
    else if (isalnum(c))
        goto q5ID;
    else
        goto out;
    
    qcaten:
    c = NextChar();
    lexeme+=c;
    push(qcaten);
    if (c=='a'||c=='A')
        goto qcatena;
    else if (isalnum(c))
        goto q6ID;
    else
        goto out;
    
    qcatena:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qcatena);
    if (isalnum(c))
        goto q7ID;
    else
        goto out;
    
    qcas:
    c = NextChar();
    lexeme+=c;
    push(qcas);
    if (c=='u'||c=='U')
        goto qcasu;
    else if (isalnum(c))
        goto q4ID;
    else
        goto out;
    
    qcasu:
    c = NextChar();
    lexeme+=c;
    push(qcasu);
    if (c=='s'||c=='S')
        goto qcasus;
    else if (isalnum(c))
        goto q5ID;
    else
        goto out;
    
    qcasus:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qcasus);
    if (isalnum(c))
        goto q6ID;
    else
        goto out;
    
    qce:
    c = NextChar();
    lexeme+=c;
    push(qce);
    if (c=='r'||c=='R')
        goto qcer;
    else if (isalnum(c))
        goto q3ID;
    else
        goto out;
    
    qcer:
    c = NextChar();
    lexeme+=c;
    push(qcer);
    if (c=='t'||c=='T')
        goto qcert;
    else if (isalnum(c))
        goto q4ID;
    else
        goto out;
    
    qcert:
    c = NextChar();
    lexeme+=c;
    push(qcert);
    if (c=='u'||c=='U')
        goto qcertu;
    else if (isalnum(c))
        goto q5ID;
    else
        goto out;
    
    qcertu:
    c = NextChar();
    lexeme+=c;
    push(qcertu);
    if (c=='s'||c=='S')
        goto qcertus;
    else if (isalnum(c))
        goto q6ID;
    else
        goto out;
    
    qcertus:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qcertus);
    if (isalnum(c))
        goto q7ID;
    else
        goto out;
    
    qcl:
    c = NextChar();
    lexeme+=c;
    push(qcl);
    if (c=='a'||c=='A')
        goto qcla;
    else if (isalnum(c))
        goto q3ID;
    else
        goto out;
    
    qcla:
    c = NextChar();
    lexeme+=c;
    push(qcla);
    if (c=='u'||c=='U')
        goto qclau;
    else if (isalnum(c))
        goto q4ID;
    else
        goto out;
    
    qclau:
    c = NextChar();
    lexeme+=c;
    push(qclau);
    if (c=='d'||c=='D')
        goto qclaud;
    else if (isalnum(c))
        goto q5ID;
    else
        goto out;
    
    qclaud:
    c = NextChar();
    lexeme+=c;
    push(qclaud);
    if (c=='e'||c=='E')
        goto qclaude;
    else if (isalnum(c))
        goto q6ID;
    else
        goto out;
    
    qclaude:
    c = NextChar();
    lexeme+=c;
    push(qclaude);
    if (c=='o'||c=='O')
        goto qclaudeo;
    else if (isalnum(c))
        goto q7ID;
    else
        goto out;
    
    qclaudeo:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qclaudeo);
    if (isalnum(c))
        goto q8ID;
    else
        goto out;
    
    qco:
    c = NextChar();
    lexeme+=c;
    push(qco);
    switch (c) {
        case 'm':
        case 'M':
            goto qcom;
        case 'n':
        case 'N':
            goto qcon;
        case 'r':
        case 'R':
            goto qcor;
        default:
            if (isalnum(c))
                goto q3ID;
            else
                goto out;
    }
    
    qcom:
    c = NextChar();
    lexeme+=c;
    push(qcom);
    if (c=='m'||c=='M')
        goto qcomm;
    else if (isalnum(c))
        goto q3ID;
    else
        goto out;

    
    qcomm:
    c = NextChar();
    lexeme+=c;
    push(qcomm);
    if (c=='u'||c=='U')
        goto qcommu;
    else if (isalnum(c))
        goto q4ID;
    else
        goto out;

    
    qcommu:
    c = NextChar();
    lexeme+=c;
    push(qcommu);
    if (c=='t'||c=='T')
        goto qcommut;
    else if (isalnum(c))
        goto q5ID;
    else
        goto out;

    
    qcommut:
    c = NextChar();
    lexeme+=c;
    push(qcommut);
    if (c=='a'||c=='A')
        goto qcommuta;
    else if (isalnum(c))
        goto q6ID;
    else
        goto out;

    
    qcommuta:
    c = NextChar();
    lexeme+=c;
    push(qcommuta);
    if (c=='b'||c=='B')
        goto qcommutab;
    else if (isalnum(c))
        goto q7ID;
    else
        goto out;

    
    qcommutab:
    c = NextChar();
    lexeme+=c;
    push(qcommutab);
    if (c=='i'||c=='I')
        goto qcommutabi;
    else if (isalnum(c))
        goto q8ID;
    else
        goto out;

    
    qcommutabi:
    c = NextChar();
    lexeme+=c;
    push(qcommutabi);
    if (c=='l'||c=='L')
        goto qcommutabil;
    else if (isalnum(c))
        goto q9ID;
    else
        goto out;

    
    qcommutabil:
    c = NextChar();
    lexeme+=c;
    push(qcommutabil);
    if (c=='i'||c=='I')
        goto qcommutabili;
    else if (isalnum(c))
        goto q10ID;
    else
        goto out;

    
    qcommutabili:
    c = NextChar();
    lexeme+=c;
    push(qcommutabili);
    if (c=='s'||c=='S')
        goto qcommutabilis;
    else if (isalnum(c))
        goto q11ID;
    else
        goto out;

    
    qcommutabilis:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qcommutabilis);
    if (isalnum(c))
        goto q12ID;
    else
        goto out;
    
    qcon:
    c = NextChar();
    lexeme+=c;
    push(qcon);
    if (c=='i'||c=='I')
        goto qconi;
    else if (isalnum(c))
        goto q4ID;
    else
        goto out;
    
    qconi:
    c = NextChar();
    lexeme+=c;
    push(qconi);
    if (c=='u'||c=='U')
        goto qconiu;
    else if (isalnum(c))
        goto q5ID;
    else
        goto out;
    
    qconiu:
    c = NextChar();
    lexeme+=c;
    push(qconiu);
    if (c=='g'||c=='G')
        goto qconiug;
    else if (isalnum(c))
        goto q6ID;
    else
        goto out;
    
    qconiug:
    c = NextChar();
    lexeme+=c;
    push(qconiug);
    if (c=='o'||c=='O')
        goto qconiugo;
    else if (isalnum(c))
        goto q7ID;
    else
        goto out;
    
    qconiugo:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qconiugo);
    if (isalnum(c))
        goto q8ID;
    else
        goto out;

    
    qcor:
    c = NextChar();
    lexeme+=c;
    push(qcor);
    if (c=='p'||c=='P')
        goto qcorp;
    else if (isalnum(c))
        goto q4ID;
    else
        goto out;
    
    qcorp:
    c = NextChar();
    lexeme+=c;
    push(qcorp);
    if (c=='u'||c=='U')
        goto qcorpu;
    else if (isalnum(c))
        goto q5ID;
    else
        goto out;
    
    qcorpu:
    c = NextChar();
    lexeme+=c;
    push(qcorpu);
    if (c=='s'||c=='S')
        goto qcorpus;
    else if (isalnum(c))
        goto q6ID;
    else
        goto out;
    
    qcorpus:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qcorpus);
    if (isalnum(c))
        goto q7ID;
    else
        goto out;
    
    qd:
    c = NextChar();
    lexeme+=c;
    push(qd);
    switch (c) {
        case 'e':
        case 'E':
            goto qde;
        case 'i':
        case 'I':
            goto qdi;
        case 'u':
        case 'U':
            goto qdu;
        default:
            if (isalnum(c))
                goto q2ID;
            else
                goto out;
    }
    
    qde:
    c = NextChar();
    lexeme+=c;
    push(qde);
    switch (c) {
        case 'c':
        case 'C':
            goto qdec;
        case 't':
        case 'T':
            goto qdet;
        default:
            if (isalnum(c))
                goto q3ID;
            else
                goto out;
    }

    
    qdet:
    c = NextChar();
    lexeme+=c;
    push(qdet);
    if (c=='r'||c=='R')
        goto qdetr;
    else if (isalnum(c))
        goto q4ID;
    else
        goto out;
    
    qdetr:
    c = NextChar();
    lexeme+=c;
    push(qdetr);
    if (c=='i'||c=='I')
        goto qdetri;
    else if (isalnum(c))
        goto q5ID;
    else
        goto out;
    
    qdetri:
    c = NextChar();
    lexeme+=c;
    push(qdetri);
    if (c=='m'||c=='M')
        goto qdetrim;
    else if (isalnum(c))
        goto q6ID;
    else
        goto out;
    
    qdetrim:
    c = NextChar();
    lexeme+=c;
    push(qdetrim);
    if (c=='e'||c=='E')
        goto qdetrime;
    else if (isalnum(c))
        goto q7ID;
    else
        goto out;
    
    qdetrime:
    c = NextChar();
    lexeme+=c;
    push(qdetrime);
    if (c=='n'||c=='N')
        goto qdetrimen;
    else if (isalnum(c))
        goto q8ID;
    else
        goto out;
    
    qdetrimen:
    c = NextChar();
    lexeme+=c;
    push(qdetrimen);
    if (c=='t'||c=='T')
        goto qdetriment;
    else if (isalnum(c))
        goto q9ID;
    else
        goto out;
    
    qdetriment:
    c = NextChar();
    lexeme+=c;
    push(qdetriment);
    if (c=='u'||c=='U')
        goto qdetrimentu;
    else if (isalnum(c))
        goto q10ID;
    else
        goto out;
    
    qdetrimentu:
    c = NextChar();
    lexeme+=c;
    push(qdetrimentu);
    if (c=='m'||c=='M')
        goto qdetrimentum;
    else if (isalnum(c))
        goto q11ID;
    else
        goto out;
    
    qdetrimentum:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qdetrimentum);
    if (isalnum(c))
        goto q12ID;
    else
        goto out;
    
    qdec:
    c = NextChar();
    lexeme+=c;
    push(qdec);
    if (c=='r'||c=='R')
        goto qdecr;
    else if (isalnum(c))
        goto q4ID;
    else
        goto out;
    
    qdecr:
    c = NextChar();
    lexeme+=c;
    push(qdecr);
    if (c=='e'||c=='E')
        goto qdecre;
    else if (isalnum(c))
        goto q5ID;
    else
        goto out;
    
    qdecre:
    c = NextChar();
    lexeme+=c;
    push(qdecre);
    if (c=='m'||c=='M')
        goto qdecrem;
    else if (isalnum(c))
        goto q6ID;
    else
        goto out;
    
    qdecrem:
    c = NextChar();
    lexeme+=c;
    push(qdecrem);
    if (c=='e'||c=='E')
        goto qdecreme;
    else if (isalnum(c))
        goto q7ID;
    else
        goto out;
    
    qdecreme:
    c = NextChar();
    lexeme+=c;
    push(qdecreme);
    if (c=='n'||c=='N')
        goto qdecremen;
    else if (isalnum(c))
        goto q8ID;
    else
        goto out;
    
    qdecremen:
    c = NextChar();
    lexeme+=c;
    push(qdecremen);
    if (c=='t'||c=='T')
        goto qdecrement;
    else if (isalnum(c))
        goto q9ID;
    else
        goto out;
    
    qdecrement:
    c = NextChar();
    lexeme+=c;
    push(qdecrement);
    if (c=='u'||c=='U')
        goto qdecrementu;
    else if (isalnum(c))
        goto q10ID;
    else
        goto out;
    
    qdecrementu:
    c = NextChar();
    lexeme+=c;
    push(qdecrementu);
    if (c=='m'||c=='M')
        goto qdecrementum;
    else if (isalnum(c))
        goto q11ID;
    else
        goto out;
    
    qdecrementum:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qdecrementum);
    if (isalnum(c))
        goto q12ID;
    else
        goto out;
    
    qdi:
    c = NextChar();
    lexeme+=c;
    push(qdi);
    switch (c) {
        case 'r':
        case 'R':
            goto qdir;
        case 't':
        case 'T':
            goto qdit;
        case 'x':
        case 'X':
            goto qdix;
        case 'e':
        case 'E':
            goto qdie;
        default:
            if (isalnum(c))
                goto q3ID;
            else
                goto out;
    }
    
    qdir:
    c = NextChar();
    lexeme+=c;
    push(qdir);
    if (c=='e'||c=='E')
        goto qdire;
    else if (isalnum(c))
        goto q4ID;
    else
        goto out;
    
    qdire:
    c = NextChar();
    lexeme+=c;
    push(qdire);
    if (c=='c'||c=='C')
        goto qdirec;
    else if (isalnum(c))
        goto q5ID;
    else
        goto out;
    
    qdirec:
    c = NextChar();
    lexeme+=c;
    push(qdirec);
    if (c=='t'||c=='T')
        goto qdirect;
    else if (isalnum(c))
        goto q6ID;
    else
        goto out;
    
    qdirect:
    c = NextChar();
    lexeme+=c;
    push(qdirect);
    if (c=='u'||c=='U')
        goto qdirectu;
    else if (isalnum(c))
        goto q7ID;
    else
        goto out;
    
    qdirectu:
    c = NextChar();
    lexeme+=c;
    push(qdirectu);
    if (c=='s'||c=='S')
        goto qdirectus;
    else if (isalnum(c))
        goto q8ID;
    else
        goto out;
    
    qdirectus:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qdirectus);
    if (isalnum(c))
        goto q9ID;
    else
        goto out;
    
    qdit:
    c = NextChar();
    lexeme+=c;
    push(qdit);
    if (c=='o'||c=='O')
        goto qdito;
    else if (isalnum(c))
        goto q4ID;
    else
        goto out;
    
    qdito:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qdito);
    if (isalnum(c))
        goto q5ID;
    else
        goto out;

    
    qdix:
    c = NextChar();
    lexeme+=c;
    push(qdix);
    if (c=='i'||c=='I')
        goto qdixi;
    else if (isalnum(c))
        goto q4ID;
    else
        goto out;
    
    qdixi:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qdixi);
    if (isalnum(c))
        goto q5ID;
    else
        goto out;

    qdie:
    c = NextChar();
    lexeme+=c;
    push(qdie);
    if (c=='m'||c=='M')
        goto qdiem;
    else if (isalnum(c))
        goto q4ID;
    else
        goto out;
    
    qdiem:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qdiem);
    if (isalnum(c))
        goto q5ID;
    else
        goto out;

    
    qdu:
    c = NextChar();
    lexeme+=c;
    //if is accepting clear stack
    push(qdu);
    if (c=='a'||c=='A')
        goto qdua;
    else if (isalnum(c))
        goto q3ID;
    else
        goto out;

 
    qdua:
    c = NextChar();
    lexeme+=c;
    //if is accepting clear stack
    push(qdua);
    if (c=='l'||c=='L')
        goto qdual;
    else if (isalnum(c))
        goto q4ID;
    else
        goto out;

    
    qdual:
    c = NextChar();
    lexeme+=c;
    //if is accepting clear stack
    push(qdual);
    if (c=='i'||c=='I')
        goto qduali;
    else if (isalnum(c))
        goto q5ID;
    else
        goto out;

    
    qduali:
    c = NextChar();
    lexeme+=c;
    //if is accepting clear stack
    push(qduali);
    if (c=='s'||c=='S')
        goto qdualis;
    else if (isalnum(c))
        goto q6ID;
    else
        goto out;

    
    qdualis:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qdualis);
    if (isalnum(c))
        goto q7ID;
    else
        goto out;

    
    qe:
    c = NextChar();
    lexeme+=c;
    push(qe);
    switch (c) {
        case 'f':
        case 'F':
            goto qef;
        case 's':
        case 'S':
            goto qes;
        case 't':
        case 'T':
            goto qet;
        case 'x':
        case 'X':
            goto qex;
        default:
            if (isalnum(c))
                goto q2ID;
            else
                goto out;
    }

    
    qef:
    c = NextChar();
    lexeme+=c;
    push(qef);
    if (c=='f'||c=='F')
        goto qeff;
    else if (isalnum(c))
        goto q3ID;
    else
        goto out;

    
    qeff:
    c = NextChar();
    lexeme+=c;
    push(qeff);
    if (c=='i'||c=='I')
        goto qeffi;
    else if (isalnum(c))
        goto q4ID;
    else
        goto out;

    
    qeffi:
    c = NextChar();
    lexeme+=c;
    push(qeffi);
    if (c=='c'||c=='C')
        goto qeffic;
    else if (isalnum(c))
        goto q5ID;
    else
        goto out;

    
    qeffic:
    c = NextChar();
    lexeme+=c;
    push(qeffic);
    if (c=='i'||c=='I')
        goto qeffici;
    else if (isalnum(c))
        goto q6ID;
    else
        goto out;

    
    qeffici:
    c = NextChar();
    lexeme+=c;
    push(qeffici);
    if (c=='o'||c=='O')
        goto qefficio;
    else if (isalnum(c))
        goto q7ID;
    else
        goto out;

    
    qefficio:
    c = NextChar();
    lexeme+=c;
    clearStack();    
    push(qefficio);
    if (isalnum(c))
        goto q8ID;
    else
        goto out;

    
    qes:
    c = NextChar();
    lexeme+=c;
    push(qes);
    switch (c) {
        case 'c':
        case 'C':
            goto qesc;
        case 't':
        case 'T':
            goto qest;
        default:
            if (isalnum(c))
                goto q3ID;
            else
                goto out;
    }

    
    qest:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qest);
    if (isalnum(c))
        goto q4ID;
    else
        goto out;

    
    qesc:
    c = NextChar();
    lexeme+=c;
    push(qesc);
    if (c=='r'||c=='R')
        goto qescr;
    else if (isalnum(c))
        goto q4ID;
    else
        goto out;

    
    qescr:
    c = NextChar();
    lexeme+=c;
    push(qescr);
    if (c=='i'||c=='I')
        goto qescri;
    else if (isalnum(c))
        goto q5ID;
    else
        goto out;

    
    qescri:
    c = NextChar();
    lexeme+=c;
    push(qescri);
    if (c=='b'||c=='B')
        goto qescrib;
    else if (isalnum(c))
        goto q6ID;
    else
        goto out;

    
    qescrib:
    c = NextChar();
    lexeme+=c;
    push(qescrib);
    if (c=='o'||c=='O')
        goto qescribo;
    else if (isalnum(c))
        goto q7ID;
    else
        goto out;

    
    qescribo:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qescribo);
    if (isalnum(c))
        goto q8ID;
    else
        goto out;

    
    qet:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qet);
    if (c=='=')
        goto qet_equals;
    else if (isalnum(c))
        goto q3ID;
    else
        goto out;

    
    qet_equals:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qet_equals);
    goto out;
    // TODO: Revisar que esto est'e bien

    
    qex:
    c = NextChar();
    lexeme+=c;
    push(qex);
    if(c=='e'||c=='E')
        goto qexe;
    else if (isalnum(c))
        goto q3ID;
    else
        goto out;

    
    qexe:
    c = NextChar();
    lexeme+=c;
    push(qexe);
    if(c=='m'||c=='M')
        goto qexem;
    else if (isalnum(c))
        goto q4ID;
    else
        goto out;

    
    qexem:
    c = NextChar();
    lexeme+=c;
    push(qexem);
    if(c=='p'||c=='P')
        goto qexemp;
    else if (isalnum(c))
        goto q5ID;
    else
        goto out;

    
    qexemp:
    c = NextChar();
    lexeme+=c;
    push(qexemp);
    if(c=='l'||c=='L')
        goto qexempl;
    else if (isalnum(c))
        goto q6ID;
    else
        goto out;

    
    qexempl:
    c = NextChar();
    lexeme+=c;
    push(qexempl);
    if(c=='a'||c=='A')
        goto qexempla;
    else if (isalnum(c))
        goto q7ID;
    else
        goto out;

    
    qexempla:
    c = NextChar();
    lexeme+=c;
    push(qexempla);
    if(c=='r'||c=='R')
        goto qexemplar;
    else if (isalnum(c))
        goto q8ID;
    else
        goto out;

    
    qexemplar:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qexemplar);
    if (isalnum(c))
        goto q9ID;
    else
        goto out;

    
    qf:
    c = NextChar();
    lexeme+=c;
    push(qf);
    switch (c) {
        case 'a':
        case 'A':
            goto qfa;
        case 'i':
        case 'I':
            goto qfi;
        case 'r':
        case 'R':
            goto qfr;
        case 'u':
        case 'U':
            goto qfu;
        default:
            if (isalnum(c))
                goto q2ID;
            else
                goto out;
    }

    
    qfa:
    c = NextChar();
    lexeme+=c;
    push(qfa);
    if(c=='l'||c=='L')
        goto qfal;
    else if (isalnum(c))
        goto q3ID;
    else
        goto out;

    
    qfal:
    c = NextChar();
    lexeme+=c;
    push(qfal);
    if(c=='s'||c=='S')
        goto qfals;
    else if (isalnum(c))
        goto q4ID;
    else
        goto out;

    
    qfals:
    c = NextChar();
    lexeme+=c;
    push(qfals);
    if(c=='i'||c=='I')
        goto qfalsi;
    else if (isalnum(c))
        goto q5ID;
    else
        goto out;

    
    qfalsi:
    c = NextChar();
    lexeme+=c;
    push(qfalsi);
    if(c=='d'||c=='D')
        goto qfalsid;
    else if (isalnum(c))
        goto q6ID;
    else
        goto out;

    
    qfalsid:
    c = NextChar();
    lexeme+=c;
    push(qfalsid);
    if(c=='i'||c=='I')
        goto qfalsidi;
    else if (isalnum(c))
        goto q7ID;
    else
        goto out;

    
    qfalsidi:
    c = NextChar();
    lexeme+=c;
    push(qfalsidi);
    if(c=='c'||c=='C')
        goto qfalsidic;
    else if (isalnum(c))
        goto q8ID;
    else
        goto out;

    
    qfalsidic:
    c = NextChar();
    lexeme+=c;
    push(qfalsidic);
    if(c=='u'||c=='U')
        goto qfalsidicu;
    else if (isalnum(c))
        goto q9ID;
    else
        goto out;

    
    qfalsidicu:
    c = NextChar();
    lexeme+=c;
    push(qfalsidicu);
    if(c=='s'||c=='S')
        goto qfalsidicus;
    else if (isalnum(c))
        goto q10ID;
    else
        goto out;

    
    qfalsidicus:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qfalsidicus);
    if (isalnum(c))
        goto q11ID;
    else
        goto out;

    
    qfi:
    c = NextChar();
    lexeme+=c;
    push(qfi);
    if(c=='r'||c=='R')
        goto qfir;
    else if(c=='n'||c=='N')
        goto qfin;
    else if (isalnum(c))
        goto q3ID;
    else
        goto out;

    
    qfir:
    c = NextChar();
    lexeme+=c;
    push(qfir);
    if(c=='m'||c=='M')
        goto qfirm;
    else if (isalnum(c))
        goto q4ID;
    else
        goto out;

    
    qfirm:
    c = NextChar();
    lexeme+=c;
    push(qfirm);
    if(c=='a'||c=='A')
        goto qfirma;
    else if (isalnum(c))
        goto q5ID;
    else
        goto out;

    
    qfirma:
    c = NextChar();
    lexeme+=c;
    push(qfirma);
    if(c=='m'||c=='M')
        goto qfirmam;
    else if (isalnum(c))
        goto q6ID;
    else
        goto out;

    
    qfirmam:
    c = NextChar();
    lexeme+=c;
    push(qfirmam);
    if(c=='e'||c=='E')
        goto qfirmame;
    else if (isalnum(c))
        goto q7ID;
    else
        goto out;

    
    qfirmame:
    c = NextChar();
    lexeme+=c;
    push(qfirmame);
    if(c=='n'||c=='N')
        goto qfirmamen;
    else if (isalnum(c))
        goto q8ID;
    else
        goto out;

    
    qfirmamen:
    c = NextChar();
    lexeme+=c;
    push(qfirmamen);
    if(c=='t'||c=='T')
        goto qfirmament;
    else if (isalnum(c))
        goto q9ID;
    else
        goto out;

    
    qfirmament:
    c = NextChar();
    lexeme+=c;
    push(qfirmament);
    if(c=='u'||c=='U')
        goto qfirmamentu;
    else if (isalnum(c))
        goto q10ID;
    else
        goto out;

    
    qfirmamentu:
    c = NextChar();
    lexeme+=c;
    push(qfirmamentu);
    if(c=='m'||c=='M')
        goto qfirmamentum;
    else if (isalnum(c))
        goto q11ID;
    else
        goto out;

    
    qfirmamentum:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qfirmamentum);
    if (isalnum(c))
        goto q12ID;
    else
        goto out;    

    
    qfin:
    c = NextChar();
    lexeme+=c;
    push(qfin);
    if(c=='i'||c=='I')
        goto qfini;
    else if (isalnum(c))
        goto q4ID;
    else
        goto out;

    
    qfini:
    c = NextChar();
    lexeme+=c;
    push(qfini);
    if(c=='s'||c=='S')
        goto qfinis;
    else if (isalnum(c))
        goto q5ID;
    else
        goto out;

    
    qfinis:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qfinis);
    if (isalnum(c))
        goto q6ID;
    else
        goto out;    

    
    qfr:
    c = NextChar();
    lexeme+=c;
    push(qfr);
    if(c=='a'||c=='A')
        goto qfra;
    else if (isalnum(c))
        goto q3ID;
    else
        goto out;

    
    qfra:
    c = NextChar();
    lexeme+=c;
    push(qfra);
    if(c=='c'||c=='C')
        goto qfrac;
    else if (isalnum(c))
        goto q4ID;
    else
        goto out;

    
    qfrac:
    c = NextChar();
    lexeme+=c;
    push(qfrac);
    if(c=='t'||c=='T')
        goto qfract;
    else if (isalnum(c))
        goto q5ID;
    else
        goto out;

    
    qfract:
    c = NextChar();
    lexeme+=c;
    push(qfract);
    if(c=='i'||c=='I')
        goto qfracti;
    else if (isalnum(c))
        goto q6ID;
    else
        goto out;

    
    qfracti:
    c = NextChar();
    lexeme+=c;
    push(qfracti);
    if(c=='o'||c=='O')
        goto qfractio;
    else if (isalnum(c))
        goto q7ID;
    else
        goto out;

    
    qfractio:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qfractio);
    if (isalnum(c))
        goto q8ID;
    else
        goto out;

    
    qfu:
    c = NextChar();
    lexeme+=c;
    push(qfu);
    if(c=='r'||c=='R')
        goto qfur;
    else if (isalnum(c))
        goto q3ID;
    else
        goto out;

    
    qfur:
    c = NextChar();
    lexeme+=c;
    push(qfur);
    if(c=='i'||c=='I')
        goto qfuri;
    else if (isalnum(c))
        goto q4ID;
    else
        goto out;

    
    qfuri:
    c = NextChar();
    lexeme+=c;
    push(qfuri);
    if(c=='b'||c=='B')
        goto qfurib;
    else if (isalnum(c))
        goto q5ID;
    else
        goto out;

    
    qfurib:
    c = NextChar();
    lexeme+=c;
    push(qfurib);
    if(c=='u'||c=='U')
        goto qfuribu;
    else if (isalnum(c))
        goto q6ID;
    else
        goto out;

    
    qfuribu:
    c = NextChar();
    lexeme+=c;
    push(qfuribu);
    if(c=='n'||c=='N')
        goto qfuribun;
    else if (isalnum(c))
        goto q7ID;
    else
        goto out;

    
    qfuribun:
    c = NextChar();
    lexeme+=c;
    push(qfuribun);
    if(c=='d'||c=='D')
        goto qfuribund;
    else if (isalnum(c))
        goto q8ID;
    else
        goto out;

    
    qfuribund:
    c = NextChar();
    lexeme+=c;
    push(qfuribund);
    if(c=='u'||c=='U')
        goto qfuribundu;
    else if (isalnum(c))
        goto q9ID;
    else
        goto out;

    
    qfuribundu:
    c = NextChar();
    lexeme+=c;
    push(qfuribundu);
    if(c=='s'||c=='S')
        goto qfuribundus;
    else if (isalnum(c))
        goto q10ID;
    else
        goto out;

    
    qfuribundus:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qfuribundus);
    if (isalnum(c))
        goto q11ID;
    else
        goto out;

    
    qi:
    c = NextChar();
    lexeme+=c;
    push(qi);
    switch (c) {
        case 'g':
        case 'G':
            goto qig;
        case 'm':
        case 'M':
            goto qim;
        case 'n':
        case 'N':
            goto qin;
        case 't':
        case 'T':
            goto qit;
        default:
            if (isalnum(c))
                goto q2ID;
            else
                goto out;
    }

    
    qig:
    c = NextChar();
    lexeme+=c;
    push(qig);
    if(c=='n'||c=='N')
        goto qign;
    else if (isalnum(c))
        goto q3ID;
    else
        goto out;
    
    qign:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qign);
    if (isalnum(c))
        goto q4ID;
    else
        goto out;

    
    qim:
    c = NextChar();
    lexeme+=c;
    push(qim);
    if(c=='a'||c=='A')
        goto qima;
    else if(c=='p'||c=='P')
        goto qimp;
    else if (isalnum(c))
        goto q3ID;
    else
        goto out;
    
    qima:
    c = NextChar();
    lexeme+=c;
    push(qima);
    if(c=='g'||c=='G')
        goto qimag;
    else if (isalnum(c))
        goto q4ID;
    else
        goto out;

    
    qimag:
    c = NextChar();
    lexeme+=c;
    push(qimag);
    if(c=='o'||c=='O')
        goto qimago;
    else if (isalnum(c))
        goto q5ID;
    else
        goto out;

    
    qimago:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qimago);
    if (isalnum(c))
        goto q6ID;
    else
        goto out;

    
    qimp:
    c = NextChar();
    lexeme+=c;
    push(qimp);
    if(c=='o'||c=='O')
        goto qimpo;
    else if (isalnum(c))
        goto q4ID;
    else
        goto out;
    
    qimpo:
    c = NextChar();
    lexeme+=c;
    push(qimpo);
    if(c=='n'||c=='N')
        goto qimpon;
    else if (isalnum(c))
        goto q5ID;
    else
        goto out;
    
    qimpon:
    c = NextChar();
    lexeme+=c;
    push(qimpon);
    if(c=='o'||c=='O')
        goto qimpono;
    else if (isalnum(c))
        goto q6ID;
    else
        goto out;
    
    qimpono:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qimpono);
    if (isalnum(c))
        goto q7ID;
    else
        goto out;

    
    qin:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qin);
    if(c=='c'||c=='C')
        goto qinc;
    else if(c=='i'||c=='I')
        goto qini;
    else if (isalnum(c))
        goto q3ID;
    else
        goto out;

    
    qinc:
    c = NextChar();
    lexeme+=c;
    push(qinc);
    if(c=='r'||c=='R')
        goto qincr;
    else if (isalnum(c))
        goto q4ID;
    else
        goto out;

    
    qincr:
    c = NextChar();
    lexeme+=c;
    push(qincr);
    if(c=='e'||c=='E')
        goto qincre;
    else if (isalnum(c))
        goto q5ID;
    else
        goto out;

    
    qincre:
    c = NextChar();
    lexeme+=c;
    push(qincre);
    if(c=='m'||c=='M')
        goto qincrem;
    else if (isalnum(c))
        goto q6ID;
    else
        goto out;

    
    qincrem:
    c = NextChar();
    lexeme+=c;
    push(qincrem);
    if(c=='e'||c=='E')
        goto qincreme;
    else if (isalnum(c))
        goto q7ID;
    else
        goto out;

    
    qincreme:
    c = NextChar();
    lexeme+=c;
    push(qincreme);
    if(c=='n'||c=='N')
        goto qincremen;
    else if (isalnum(c))
        goto q8ID;
    else
        goto out;

    
    qincremen:
    c = NextChar();
    lexeme+=c;
    push(qincremen);
    if(c=='t'||c=='T')
        goto qincrement;
    else if (isalnum(c))
        goto q9ID;
    else
        goto out;

    
    qincrement:
    c = NextChar();
    lexeme+=c;
    push(qincrement);
    if(c=='u'||c=='U')
        goto qincrementu;
    else if (isalnum(c))
        goto q10ID;
    else
        goto out;

    
    qincrementu:
    c = NextChar();
    lexeme+=c;
    push(qincrementu);
    if(c=='m'||c=='M')
        goto qincrementum;
    else if (isalnum(c))
        goto q11ID;
    else
        goto out;

    
    qincrementum:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qincrementum);
    if (isalnum(c))
        goto q12ID;
    else
        goto out;

    
    qini:
    c = NextChar();
    lexeme+=c;
    push(qini);
    if(c=='t'||c=='T')
        goto qinit;
    else if (isalnum(c))
        goto q4ID;
    else
        goto out;

    
    qinit:
    c = NextChar();
    lexeme+=c;
    push(qinit);
    if(c=='u'||c=='U')
        goto qinitu;
    else if (isalnum(c))
        goto q5ID;
    else
        goto out;

    
    qinitu:
    c = NextChar();
    lexeme+=c;
    push(qinitu);
    if(c=='m'||c=='M')
        goto qinitum;
    else if (isalnum(c))
        goto q6ID;
    else
        goto out;

    
    qinitum:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qinitum);
    if (isalnum(c))
        goto q7ID;
    else
        goto out;

    
    qit:
    c = NextChar();
    lexeme+=c;
    push(qit);
    if(c=='e'||c=='E')
        goto qite;
    else if (isalnum(c))
        goto q3ID;
    else
        goto out;

    
    qite:
    c = NextChar();
    lexeme+=c;
    push(qite);
    if(c=='r'||c=='R')
        goto qiter;
    else if (isalnum(c))
        goto q4ID;
    else
        goto out;

    
    qiter:
    c = NextChar();
    lexeme+=c;
    push(qiter);
    if(c=='o'||c=='O')
        goto qitero;
    else if (isalnum(c))
        goto q5ID;
    else
        goto out;

    
    qitero:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qitero);
    if (isalnum(c))
        goto q6ID;
    else
        goto out;    

    
    ql:
    c = NextChar();
    lexeme+=c;
    push(ql);
    if(c=='e'||c=='E')
        goto qle;
    else if(c=='i'||c=='I')
        goto qli;
    else if (isalnum(c))
        goto q2ID;
    else
        goto out;

    
    qle:
    c = NextChar();
    lexeme+=c;
    push(qle);
    if(c=='c'||c=='C')
        goto qlec;
    else if (isalnum(c))
        goto q3ID;
    else
        goto out;

    
    qlec:
    c = NextChar();
    lexeme+=c;
    push(qlec);
    if(c=='t'||c=='T')
        goto qlect;
    else if (isalnum(c))
        goto q4ID;
    else
        goto out;

    
    qlect:
    c = NextChar();
    lexeme+=c;
    push(qlect);
    if(c=='i'||c=='I')
        goto qlecti;
    else if (isalnum(c))
        goto q5ID;
    else
        goto out;

    
    qlecti:
    c = NextChar();
    lexeme+=c;
    push(qlecti);
    if(c=='o'||c=='O')
        goto qlectio;
    else if (isalnum(c))
        goto q6ID;
    else
        goto out;

    
    qlectio:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qlectio);
    if (isalnum(c))
        goto q7ID;
    else
        goto out;

    
    qli:
    c = NextChar();
    lexeme+=c;
    push(qli);
    if(c=='b'||c=='B')
        goto qlib;
    else if(c=='g'||c=='G')
        goto qlig;
    else if (isalnum(c))
        goto q3ID;
    else
        goto out;

    
    qlib:
    c = NextChar();
    lexeme+=c;
    push(qlib);
    if(c=='e'||c=='E')
        goto qlibe;
    else if (isalnum(c))
        goto q4ID;
    else
        goto out;

    
    qlibe:
    c = NextChar();
    lexeme+=c;
    push(qlibe);
    if(c=='r'||c=='R')
        goto qliber;
    else if (isalnum(c))
        goto q5ID;
    else
        goto out;

    
    qliber:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qliber);
    if (isalnum(c))
        goto q6ID;
    else
        goto out;

    
    qlig:
    c = NextChar();
    lexeme+=c;
    push(qlig);
    if(c=='o'||c=='O')
        goto qligo;
    else if (isalnum(c))
        goto q4ID;
    else
        goto out;

    
    qligo:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qligo);
    if (isalnum(c))
        goto q5ID;
    else
        goto out;

    
    qg:
    c = NextChar();
    lexeme+=c;
    push(qg);
    if(c=='r'||c=='R')
        goto qgr;
    else if (isalnum(c))
        goto q2ID;
    else
        goto out;
    
    qgr:
    c = NextChar();
    lexeme+=c;
    push(qgr);
    if(c=='a'||c=='A')
        goto qgra;
    else if (isalnum(c))
        goto q3ID;
    else
        goto out;
    
    qgra:
    c = NextChar();
    lexeme+=c;
    push(qgra);
    if(c=='d'||c=='D')
        goto qgrad;
    else if (isalnum(c))
        goto q4ID;
    else
        goto out;
    
    qgrad:
    c = NextChar();
    lexeme+=c;
    push(qgrad);
    if(c=='u'||c=='U')
        goto qgradu;
    else if (isalnum(c))
        goto q5ID;
    else
        goto out;
    
    qgradu:
    c = NextChar();
    lexeme+=c;
    push(qgradu);
    if(c=='s'||c=='S')
        goto qgradus;
    else if (isalnum(c))
        goto q6ID;
    else
        goto out;
    
    qgradus:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qgradus);
    if (isalnum(c))
        goto q7ID;
    else
        goto out;

    
    qm:
    c = NextChar();
    lexeme+=c;
    push(qm);
    if(c=='e'||c=='E')
        goto qme;
    else if (isalnum(c))
        goto q2ID;
    else
        goto out;

    
    qme:
    c = NextChar();
    lexeme+=c;
    push(qme);
    if(c=='n'||c=='N')
        goto qmen;
    else if (isalnum(c))
        goto q3ID;
    else
        goto out;

    
    qmen:
    c = NextChar();
    lexeme+=c;
    push(qmen);
    if(c=='t'||c=='T')
        goto qment;
    else if (isalnum(c))
        goto q4ID;
    else
        goto out;

    
    qment:
    c = NextChar();
    lexeme+=c;
    push(qment);
    if(c=='i'||c=='I')
        goto qmenti;
    else if (isalnum(c))
        goto q5ID;
    else
        goto out;

    
    qmenti:
    c = NextChar();
    lexeme+=c;
    push(qmenti);
    if(c=='r'||c=='R')
        goto qmentir;
    else if (isalnum(c))
        goto q6ID;
    else
        goto out;

    
    qmentir:
    c = NextChar();
    lexeme+=c;
    push(qmentir);
    if(c=='i'||c=='I')
        goto qmentiri;
    else if (isalnum(c))
        goto q7ID;
    else
        goto out;
    
    
    qmentiri:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qmentiri);
    if (isalnum(c))
        goto q8ID;
    else
        goto out;

    
    qo:
    c = NextChar();
    lexeme+=c;
    push(qo);
    if(c=='p'||c=='P')
        goto qop;
    else if(c=='r'||c=='R')
        goto qor;
    else if (isalnum(c))
        goto q2ID;
    else
        goto out;

    
    qop:
    c = NextChar();
    lexeme+=c;
    push(qop);
    if(c=='u'||c=='U')
        goto qopu;
    else if (isalnum(c))
        goto q3ID;
    else
        goto out;

    
    qopu:
    c = NextChar();
    lexeme+=c;
    push(qopu);
    if(c=='s'||c=='S')
        goto qopus;
    else if (isalnum(c))
        goto q4ID;
    else
        goto out;

    
    qopus:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qopus);
    if (isalnum(c))
        goto q5ID;
    else
        goto out;

    
    qor:
    c = NextChar();
    lexeme+=c;
    push(qor);
    if(c=='d'||c=='D')
        goto qord;
    else if (isalnum(c))
        goto q3ID;
    else
        goto out;

    
    qord:
    c = NextChar();
    lexeme+=c;
    push(qord);
    if(c=='o'||c=='O')
        goto qordo;
    else if (isalnum(c))
        goto q4ID;
    else
        goto out;

    
    qordo:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qordo);
    if (isalnum(c))
        goto q5ID;
    else
        goto out;

    
    qn:
    c = NextChar();
    lexeme+=c;
    push(qn);
    switch (c) {
        case 'e':
        case 'E':
            goto qne;
        case 'o':
        case 'O':
            goto qno;
        case 'u':
        case 'U':
            goto qnu;
        default:
            if (isalnum(c))
                goto q2ID;
            else
                goto out;
    }

    
    qne:
    c = NextChar();
    lexeme+=c;
    push(qne);
    if(c=='c'||c=='C')
        goto qnec;
    else if (isalnum(c))
        goto q3ID;
    else
        goto out;

    
    qnec:
    c = NextChar();
    lexeme+=c;
    push(qnec);
    if(c=='o'||c=='O')
        goto qneco;
    else if (isalnum(c))
        goto q4ID;
    else
        goto out;

    
    qneco:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qneco);
    if (isalnum(c))
        goto q5ID;
    else
        goto out;

    
    qno:
    c = NextChar();
    lexeme+=c;
    push(qno);
    switch (c) {
        case 'm':
        case 'M':
            goto qnom;
        case 'n':
        case 'N':
            goto qnon;
        case 'v':
        case 'V':
            goto qnov;
        default:
            if (isalnum(c))
                goto q3ID;
            else
                goto out;
    }

    
    qnom:
    c = NextChar();
    lexeme+=c;
    push(qnom);
    if(c=='e'||c=='E')
        goto qnome;
    else if (isalnum(c))
        goto q4ID;
    else
        goto out;

    
    qnome:
    c = NextChar();
    lexeme+=c;
    push(qnome);
    if(c=='n'||c=='N')
        goto qnomen;
    else if (isalnum(c))
        goto q5ID;
    else
        goto out;

    
    qnomen:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qnomen);
    if (isalnum(c))
        goto q6ID;
    else
        goto out;
    
    qnon:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qnon);
    if (isalnum(c))
        goto q4ID;
    else
        goto out;

    qnov:
    c = NextChar();
    lexeme+=c;
    push(qnov);
    if(c=='i'||c=='I')
        goto qnovi;
    else if (isalnum(c))
        goto q4ID;
    else
        goto out;

    qnovi:
    c = NextChar();
    lexeme+=c;
    push(qnovi);
    if(c=='s'||c=='S')
        goto qnovis;
    else if (isalnum(c))
        goto q5ID;
    else
        goto out;

    qnovis:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qnovis);
    if (isalnum(c))
        goto q6ID;
    else
        goto out;


    qnu:
    c = NextChar();
    lexeme+=c;
    push(qnu);
    if(c=='m'||c=='M')
        goto qnum;
    else if (isalnum(c))
        goto q3ID;
    else
        goto out;

    
    qnum:
    c = NextChar();
    lexeme+=c;
    push(qnum);
    if(c=='e'||c=='E')
        goto qnume;
    else if (isalnum(c))
        goto q4ID;
    else
        goto out;

    
    qnume:
    c = NextChar();
    lexeme+=c;
    push(qnume);
    if(c=='r'||c=='R')
        goto qnumer;
    else if (isalnum(c))
        goto q5ID;
    else
        goto out;

    
    qnumer:
    c = NextChar();
    lexeme+=c;
    push(qnumer);
    if(c=='u'||c=='U')
        goto qnumeru;
    else if (isalnum(c))
        goto q6ID;
    else
        goto out;

    
    qnumeru:
    c = NextChar();
    lexeme+=c;
    push(qnumeru);
    if(c=='s'||c=='S')
        goto qnumerus;
    else if (isalnum(c))
        goto q7ID;
    else
        goto out;

    
    qnumerus:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qnumerus);
    if (isalnum(c))
        goto q8ID;
    else
        goto out;

    
    qp:
    c = NextChar();
    lexeme+=c;
    push(qp);
    switch (c) {
        case 'a':
        case 'A':
            goto qpa;
        case 'e':
        case 'E':
            goto qpe;
        case 'r':
        case 'R':
            goto qpr;
        default:
            if (isalnum(c))
                goto q2ID;
            else
                goto out;
    }

    
    qpa:
    c = NextChar();
    lexeme+=c;
    push(qpa);
    switch (c) {
        case 'n':
        case 'N':
            goto qpan;
        case 't':
        case 'T':
            goto qpat;
        default:
            if (isalnum(c))
                goto q3ID;
            else
                goto out;
    }

    
    qpan:
    c = NextChar();
    lexeme+=c;
    push(qpan);
    if(c=='i'||c=='I')
        goto qpani;
    else if (isalnum(c))
        goto q4ID;
    else
        goto out;

    
    qpani:
    c = NextChar();
    lexeme+=c;
    push(qpani);
    if(c=='s'||c=='S')
        goto qpanis;
    else if (isalnum(c))
        goto q5ID;
    else
        goto out;

    
    qpanis:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qpanis);
    if (isalnum(c))
        goto q6ID;
    else
        goto out;

    
    qpat:
    c = NextChar();
    lexeme+=c;
    push(qpat);
    if(c=='e'||c=='E')
        goto qpate;
    else if (isalnum(c))
        goto q4ID;
    else
        goto out;

    
    qpate:
    c = NextChar();
    lexeme+=c;
    push(qpate);
    if(c=='n'||c=='N')
        goto qpaten;
    else if (isalnum(c))
        goto q5ID;
    else
        goto out;

    
    qpaten:
    c = NextChar();
    lexeme+=c;
    push(qpaten);
    if(c=='t'||c=='T')
        goto qpatent;
    else if (isalnum(c))
        goto q6ID;
    else
        goto out;

    
    qpatent:
    c = NextChar();
    lexeme+=c;
    push(qpatent);
    if(c=='i'||c=='I')
        goto qpatenti;
    else if (isalnum(c))
        goto q7ID;
    else
        goto out;

    
    qpatenti:
    c = NextChar();
    lexeme+=c;
    push(qpatenti);
    if(c=='b'||c=='B')
        goto qpatentib;
    else if (isalnum(c))
        goto q8ID;
    else
        goto out;

    
    qpatentib:
    c = NextChar();
    lexeme+=c;
    push(qpatentib);
    if(c=='u'||c=='U')
        goto qpatentibu;
    else if (isalnum(c))
        goto q9ID;
    else
        goto out;

    
    qpatentibu:
    c = NextChar();
    lexeme+=c;
    push(qpatentibu);
    if(c=='s'||c=='S')
        goto qpatentibus;
    else if (isalnum(c))
        goto q10ID;
    else
        goto out;

    
    qpatentibus:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qpatentibus);
    if (isalnum(c))
        goto q11ID;
    else
        goto out;

    
    qpe:
    c = NextChar();
    lexeme+=c;
    push(qpe);
    if(c=='r'||c=='R')
        goto qper;
    else if (isalnum(c))
        goto q3ID;
    else
        goto out;


    
    qper:
    c = NextChar();
    lexeme+=c;
    push(qper);
    if(c=='p'||c=='P')
        goto qperp;
    else if(c=='s'||c=='S')
        goto qperg;
    else if (isalnum(c))
        goto q4ID;
    else
        goto out;


    
    qperp:
    c = NextChar();
    lexeme+=c;
    push(qperp);
    if(c=='e'||c=='E')
        goto qperpe;
    else if (isalnum(c))
        goto q5ID;
    else
        goto out;

    
    qperpe:
    c = NextChar();
    lexeme+=c;
    push(qperpe);
    if(c=='t'||c=='T')
        goto qperpet;
    else if (isalnum(c))
        goto q6ID;
    else
        goto out;

    
    qperpet:
    c = NextChar();
    lexeme+=c;
    push(qperpet);
    if(c=='u'||c=='U')
        goto qperpetu;
    else if (isalnum(c))
        goto q7ID;
    else
        goto out;

    
    qperpetu:
    c = NextChar();
    lexeme+=c;
    push(qperpetu);
    if(c=='s'||c=='S')
        goto qperpetus;
    else if (isalnum(c))
        goto q8ID;
    else
        goto out;

    
    qperpetus:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qperpetus);
    if (isalnum(c))
        goto q9ID;
    else
        goto out;

    
    qperg:
    c = NextChar();
    lexeme+=c;
    push(qperg);
    if(c=='o'||c=='O')
        goto qpergo;
    else if (isalnum(c))
        goto q5ID;
    else
        goto out;

    
    qpergo:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qpergo);
    if (isalnum(c))
        goto q6ID;
    else
        goto out;

    
    qpr:
    c = NextChar();
    lexeme+=c;
    push(qpr);
    if(c=='o'||c=='O')
        goto qpro;
    else if (isalnum(c))
        goto q3ID;
    else
        goto out;

    
    qpro:
    c = NextChar();
    lexeme+=c;
    push(qpro);
    if(c=='p'||c=='P')
        goto qprop;
    else if (isalnum(c))
        goto q4ID;
    else
        goto out;;

    
    qprop:
    c = NextChar();
    lexeme+=c;
    push(qprop);
    if(c=='e'||c=='E')
        goto qprope;
    else if (isalnum(c))
        goto q5ID;
    else
        goto out;

    
    qprope:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qprope);
    if (isalnum(c))
        goto q6ID;
    else
        goto out;

    
    qq:
    c = NextChar();
    lexeme+=c;
    push(qq);
    if(c=='u'||c=='U')
        goto qqu;
    else if (isalnum(c))
        goto q2ID;
    else
        goto out;


    
    qqu:
    c = NextChar();
    lexeme+=c;
    push(qqu);
    if(c=='a'||c=='A')
        goto qqua;
    else if (isalnum(c))
        goto q3ID;
    else
        goto out;


    
    qqua:
    c = NextChar();
    lexeme+=c;
    push(qqua);
    if(c=='n'||c=='N')
        goto qquan;
    else if (isalnum(c))
        goto q4ID;
    else
        goto out;


    
    qquan:
    c = NextChar();
    lexeme+=c;
    push(qquan);
    if(c=='t'||c=='T')
        goto qquant;
    else if (isalnum(c))
        goto q5ID;
    else
        goto out;


    
    qquant:
    c = NextChar();
    lexeme+=c;
    push(qquant);
    if(c=='u'||c=='U')
        goto qquantu;
    else if (isalnum(c))
        goto q6ID;
    else
        goto out;


    
    qquantu:
    c = NextChar();
    lexeme+=c;
    push(qquantu);
    if(c=='s'||c=='S')
        goto qquantus;
    else if (isalnum(c))
        goto q7ID;
    else
        goto out;


    
    qquantus:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qquantus);
    if (isalnum(c))
        goto q8ID;
    else
        goto out;


    
    qr:
    c = NextChar();
    lexeme+=c;
    push(qr);
    if(c=='e'||c=='E')
        goto qre;
    else if (isalnum(c))
        goto q2ID;
    else
        goto out;


    
    qre:
    c = NextChar();
    lexeme+=c;
    push(qre);
    if(c=='d'||c=='D')
        goto qred;
    else if(c=='s'||c=='S')
        goto qres;
    else if (isalnum(c))
        goto q3ID;
    else
        goto out;


    
    qred:
    c = NextChar();
    lexeme+=c;
    push(qred);
    if(c=='i'||c=='I')
        goto qredi;
    else if (isalnum(c))
        goto q4ID;
    else
        goto out;

    
    qredi:
    c = NextChar();
    lexeme+=c;
    push(qredi);
    if(c=='t'||c=='T')
        goto qredit;
    else if (isalnum(c))
        goto q5ID;
    else
        goto out;

    
    qredit:
    c = NextChar();
    lexeme+=c;
    push(qredit);
    if(c=='u'||c=='U')
        goto qreditu;
    else if (isalnum(c))
        goto q6ID;
    else
        goto out;

    
    qreditu:
    c = NextChar();
    lexeme+=c;
    push(qreditu);
    if(c=='s'||c=='S')
        goto qreditus;
    else if (isalnum(c))
        goto q7ID;
    else
        goto out;

    
    qreditus:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qreditus);
    if (isalnum(c))
        goto q8ID;
    else
        goto out;


    
    qres:
    c = NextChar();
    lexeme+=c;
    push(qres);
    if(c=='c'||c=='C')
        goto qresc;
    else if (isalnum(c))
        goto q4ID;
    else
        goto out;


    
    qresc:
    c = NextChar();
    lexeme+=c;
    push(qresc);
    if(c=='r'||c=='R')
        goto qrescr;
    else if (isalnum(c))
        goto q5ID;
    else
        goto out;


    
    qrescr:
    c = NextChar();
    lexeme+=c;
    push(qrescr);
    if(c=='i'||c=='I')
        goto qrescri;
    else if (isalnum(c))
        goto q6ID;
    else
        goto out;


    
    qrescri:
    c = NextChar();
    lexeme+=c;
    push(qrescri);
    if(c=='b'||c=='B')
        goto qrescrib;
    else if (isalnum(c))
        goto q7ID;
    else
        goto out;


    
    qrescrib:
    c = NextChar();
    lexeme+=c;
    push(qrescrib);
    if(c=='o'||c=='O')
        goto qrescribo;
    else if (isalnum(c))
        goto q8ID;
    else
        goto out;


    
    qrescribo:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qrescribo);
    if (isalnum(c))
        goto q9ID;
    else
        goto out;

    
    qs:
    c = NextChar();
    lexeme+=c;
    push(qs);
    switch (c) {
        case 'a':
        case 'A':
            goto qsa;
        case 'c':
        case 'C':
            goto qsc;
        case 'i':
        case 'I':
            goto qsa;
        case 'u':
        case 'U':
            goto qsu;
        default:
            if (isalnum(c))
                goto q2ID;
            else
                goto out;
    }

    qsa:
    c = NextChar();
    lexeme+=c;
    push(qsa);
    if(c=='l'||c=='L')
        goto qsal;
    else if (isalnum(c))
        goto q3ID;
    else
        goto out;

    qsal:
    c = NextChar();
    lexeme+=c;
    push(qsal);
    if(c=='i'||c=='I')
        goto qsali;
    else if (isalnum(c))
        goto q4ID;
    else
        goto out;

    qsali:
    c = NextChar();
    lexeme+=c;
    push(qsali);
    if(c=='r'||c=='R')
        goto qsalir;
    else if (isalnum(c))
        goto q5ID;
    else
        goto out;

    qsalir:
    c = NextChar();
    lexeme+=c;
    push(qsalir);
    if(c=='e'||c=='E')
        goto qsalire;
    else if (isalnum(c))
        goto q6ID;
    else
        goto out;

    qsalire:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qsalire);
    if(c=='e'||c=='E')
        goto qsalire;
    else if (isalnum(c))
        goto q7ID;
    else
        goto out;
    
    qsc:
    c = NextChar();
    lexeme+=c;
    push(qsc);
    if(c=='r'||c=='R')
        goto qscr;
    else if (isalnum(c))
        goto q3ID;
    else
        goto out;

    
    qscr:
    c = NextChar();
    lexeme+=c;
    push(qscr);
    if(c=='i'||c=='I')
        goto qscri;
    else if (isalnum(c))
        goto q4ID;
    else
        goto out;

    
    qscri:
    c = NextChar();
    lexeme+=c;
    push(qscri);
    if(c=='p'||c=='P')
        goto qscrip;
    else if (isalnum(c))
        goto q5ID;
    else
        goto out;

    
    qscrip:
    c = NextChar();
    lexeme+=c;
    push(qscrip);
    if(c=='t'||c=='T')
        goto qscript;
    else if (isalnum(c))
        goto q6ID;
    else
        goto out;

    
    qscript:
    c = NextChar();
    lexeme+=c;
    push(qscript);
    if(c=='u'||c=='U')
        goto qscriptu;
    else if (isalnum(c))
        goto q7ID;
    else
        goto out;

    
    qscriptu:
    c = NextChar();
    lexeme+=c;
    push(qscriptu);
    if(c=='r'||c=='R')
        goto qscriptur;
    else if (isalnum(c))
        goto q8ID;
    else
        goto out;

    
    qscriptur:
    c = NextChar();
    lexeme+=c;
    push(qscriptur);
    if(c=='a'||c=='A')
        goto qscriptura;
    else if (isalnum(c))
        goto q9ID;
    else
        goto out;

    
    qscriptura:
    c = NextChar();
    lexeme+=c;
    push(qscriptura);
    if(c=='m'||c=='M')
        goto qscripturam;
    else if (isalnum(c))
        goto q10ID;
    else
        goto out;

    
    qscripturam:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qscripturam);
    if (isalnum(c))
        goto q11ID;
    else
        goto out;

    
    qsi:
    c = NextChar();
    lexeme+=c;
    push(qsi);
    if(c=='g'||c=='G')
        goto qsig;
    else if (isalnum(c))
        goto q3ID;
    else
        goto out;

    
    qsig:
    c = NextChar();
    lexeme+=c;
    push(qsig);
    if(c=='l'||c=='L')
        goto qsigl;
    else if (isalnum(c))
        goto q4ID;
    else
        goto out;

    
    qsigl:
    c = NextChar();
    lexeme+=c;
    push(qsigl);
    if(c=='a'||c=='A')
        goto qsigla;
    else if (isalnum(c))
        goto q5ID;
    else
        goto out;

    
    qsigla:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qsigla);
    if (isalnum(c))
        goto q6ID;
    else
        goto out;

    
    qsu:
    c = NextChar();
    lexeme+=c;
    push(qsu);
    if(c=='m'||c=='M')
        goto qsum;
    else if (isalnum(c))
        goto q3ID;
    else
        goto out;

    
    qsum:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qsum);
    if (isalnum(c))
        goto q4ID;
    else
        goto out;

    
    qt:
    c = NextChar();
    lexeme+=c;
    push(qt);
    if(c=='e'||c=='E')
        goto qte;
    else if (isalnum(c))
        goto q2ID;
    else
        goto out;

    
    qte:
    c = NextChar();
    lexeme+=c;
    push(qte);
    if(c=='m'||c=='M')
        goto qtem;
    else if (isalnum(c))
        goto q3ID;
    else
        goto out;

    
    qtem:
    c = NextChar();
    lexeme+=c;
    push(qtem);
    if(c=='p'||c=='P')
        goto qtemp;
    else if (isalnum(c))
        goto q4ID;
    else
        goto out;

    
    qtemp:
    c = NextChar();
    lexeme+=c;
    push(qtemp);
    if(c=='u'||c=='U')
        goto qtempu;
    else if (isalnum(c))
        goto q5ID;
    else
        goto out;

    
    qtempu:
    c = NextChar();
    lexeme+=c;
    push(qtempu);
    if(c=='s'||c=='S')
        goto qtempus;
    else if (isalnum(c))
        goto q6ID;
    else
        goto out;

    
    qtempus:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qtempus);
    if (isalnum(c))
        goto q7ID;
    else
        goto out;

    
    qu:
    c = NextChar();
    lexeme+=c;
    push(qu);
    if(c=='s'||c=='S')
        goto qus;
    else if (isalnum(c))
        goto q2ID;
    else
        goto out;

    
    qus:
    c = NextChar();
    lexeme+=c;
    push(qus);
    if(c=='q'||c=='Q')
        goto qusq;
    else if (isalnum(c))
        goto q3ID;
    else
        goto out;

    
    qusq:
    c = NextChar();
    lexeme+=c;
    push(qusq);
    if(c=='u'||c=='U')
        goto qusqu;
    else if (isalnum(c))
        goto q4ID;
    else
        goto out;

    
    qusqu:
    c = NextChar();
    lexeme+=c;
    push(qusqu);
    if(c=='e'||c=='E')
        goto qusque;
    else if (isalnum(c))
        goto q5ID;
    else
        goto out;

    
    qusque:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qusque);
    if (isalnum(c))
        goto q6ID;
    else
        goto out;

    
    qv:
    c = NextChar();
    lexeme+=c;
    push(qv);
    if(c=='e'||c=='E')
        goto qve;
    else if (isalnum(c))
        goto q2ID;
    else
        goto out;
    
    qve:
    c = NextChar();
    lexeme+=c;
    push(qve);
    if(c=='r'||c=='R')
        goto qver;
    else if (isalnum(c))
        goto q3ID;
    else
        goto out;
    
    qver:
    c = NextChar();
    lexeme+=c;
    push(qver);
    if(c=='i'||c=='I')
        goto qveri;
    else if (isalnum(c))
        goto q4ID;
    else
        goto out;
    
    qveri:
    c = NextChar();
    lexeme+=c;
    push(qveri);
    if(c=='d'||c=='D')
        goto qverid;
    else if (isalnum(c))
        goto q5ID;
    else
        goto out;
    
    qverid:
    c = NextChar();
    lexeme+=c;
    push(qverid);
    if(c=='i'||c=='I')
        goto qveridi;
    else if (isalnum(c))
        goto q6ID;
    else
        goto out;
    
    qveridi:
    c = NextChar();
    lexeme+=c;
    push(qveridi);
    if(c=='c'||c=='C')
        goto qveridic;
    else if (isalnum(c))
        goto q7ID;
    else
        goto out;
    
    qveridic:
    c = NextChar();
    lexeme+=c;
    push(qveridic);
    if(c=='u'||c=='U')
        goto qveridicu;
    else if (isalnum(c))
        goto q8ID;
    else
        goto out;
    
    qveridicu:
    c = NextChar();
    lexeme+=c;
    push(qveridicu);
    if(c=='s'||c=='S')
        goto qveridicus;
    else if (isalnum(c))
        goto q9ID;
    else
        goto out;
    
    qveridicus:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qveridicus);
    if (isalnum(c))
        goto q10ID;
    else
        goto out;

    
    qx:
    c = NextChar();
    lexeme+=c;
    push(qx);
    if(c=='a'||c=='A')
        goto qxa;
    else if (isalnum(c))
        goto q2ID;
    else
        goto out;

    
    qxa:
    c = NextChar();
    lexeme+=c;
    push(qxa);
    if(c=='u'||c=='U')
        goto qxau;
    else if (isalnum(c))
        goto q3ID;
    else
        goto out;

    
    qxau:
    c = NextChar();
    lexeme+=c;
    push(qxau);
    if(c=='t'||c=='T')
        goto qxaut;
    else if (isalnum(c))
        goto q4ID;
    else
        goto out;

    
    qxaut:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qxaut);
    if(c=='=')
        goto qxaut_equals;
    else if (isalnum(c))
        goto q5ID;
    else
        goto out;

    
    qxaut_equals:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qxaut_equals);
    goto out;
    // TODO check this

    // IDENTIFICADORES

    q1ID:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(q1ID);
    if (isalnum(c))
        goto q2ID;
    else
        goto out;

    q2ID:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(q2ID);
    if (isalnum(c))
        goto q3ID;
    else
        goto out;

    q3ID:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(q3ID);
    if (isalnum(c))
        goto q4ID;
    else
        goto out;

    q4ID:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(q4ID);
    if (isalnum(c))
        goto q5ID;
    else
        goto out;

    q5ID:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(q5ID);
    if (isalnum(c))
        goto q6ID;
    else
        goto out;

    q6ID:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(q6ID);
    if (isalnum(c))
        goto q7ID;
    else
        goto out;

    q7ID:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(q7ID);
    if (isalnum(c))
        goto q8ID;
    else
        goto out;

    q8ID:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(q8ID);
    if (isalnum(c))
        goto q9ID;
    else
        goto out;

    q9ID:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(q9ID);
    if (isalnum(c))
        goto q10ID;
    else
        goto out;

    q10ID:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(q10ID);
    if (isalnum(c))
        goto q11ID;
    else
        goto out;

    q11ID:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(q11ID);
    if (isalnum(c))
        goto q12ID;
    else
        goto out;

    q12ID:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(q12ID);
    if (isalnum(c))
        goto q13ID;
    else
        goto out;

    q13ID:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(q13ID);
    if (isalnum(c))
        goto q14ID;
    else
        goto out;

    q14ID:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(q14ID);
    if (isalnum(c))
        goto q15ID;
    else
        goto out;

    q15ID:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(q15ID);
    if (isalnum(c))
        goto q16ID;
    else
        goto out;

    q16ID:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(q16ID);
    if (isalnum(c))
        goto q17ID;
    else
        goto out;

    q17ID:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(q17ID);
    if (isalnum(c))
        goto q18ID;
    else
        goto out;

    q18ID:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(q18ID);
    if (isalnum(c))
        goto q19ID;
    else
        goto out;

    q19ID:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(q19ID);
    if (isalnum(c))
        goto q20ID;
    else
        goto out;

    q20ID:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(q20ID);
    if (isalnum(c))
        goto q21ID;
    else
        goto out;

    q21ID:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(q21ID);
    if (isalnum(c))
        goto q22ID;
    else
        goto out;

    q22ID:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(q22ID);
    if (isalnum(c))
        goto q23ID;
    else
        goto out;

    q23ID:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(q23ID);
    if (isalnum(c))
        goto q24ID;
    else
        goto out;

    q24ID:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(q24ID);
    if (isalnum(c))
        goto q25ID;
    else
        goto out;

    q25ID:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(q25ID);
    if (isalnum(c))
        goto q26ID;
    else
        goto out;

    q26ID:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(q26ID);
    if (isalnum(c))
        goto q27ID;
    else
        goto out;

    q27ID:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(q27ID);
    if (isalnum(c))
        goto q28ID;
    else
        goto out;

    q28ID:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(q28ID);
    if (isalnum(c))
        goto q29ID;
    else
        goto out;

    q29ID:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(q29ID);
    if (isalnum(c))
        goto q30ID;
    else
        goto out;

    q30ID:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(q30ID);
    if (isalnum(c))
        goto q31ID;
    else
        goto out;

    q31ID:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(q31ID);
    goto out;
    // TODO revisar esto

    qLCB:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qLCB);
    goto out;

    qRCB:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qRCB);
    goto out;


    qDot:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qDot);
    goto out;

    qColon:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qColon);
    if (c=='=')
        goto qColon_equals;
    else
        goto out;

    qColon_equals:
    c = NextChar();
    lexeme+=c;
    clearStack();
    push(qColon_equals);
    goto out;
    



    

    out:
    //stack.pop();
    lexeme.pop_back();
    Rollback();
    while (tokens.find(stack.top()) == tokens.end()
           && static_cast<State>(stack.top()) != bad) {
        //failed.insert({state,input});
        //state= static_cast<State>(stack.top().first);
        //input = stack.top().second;
        stack.pop();
        lexeme.pop_back();
        Rollback();

    }
    end:
    Token res;
    // Find the token type
    if (tokens.find(stack.top()) != tokens.end()) {
        res = tokens[stack.top()];
        // Add the lexeme
        res.lexeme = (char *) malloc(lexeme.size() + 1);
        strcpy(res.lexeme, lexeme.c_str());
    } else {
        reportError(InvalidToken);
        res = Token(t_error);
        res.attrib = input;
        JumpToSafePoint();
    }

    // Remember to return t_EOF infinitely if there is no
    // tokens left to send
    if (stack.top() == qEOF)
        Rollback();

    return res;

}
#pragma clang diagnostic pop

void Scanner::Initiize() {
    //file = fopen(filename, "r");
    file.open(filename);
    if(!file.is_open()){
       reportError(CouldntOpenFile);
       return;
    }

    input = 0;
    fence = 0;
    Fill(0);
}

char *Scanner::Fill(int i) {
    //return fgets(buffer+i, BUFFSIZE, (FILE *) file, '\000');
    file.get(buffer + i, BUFFSIZE + 1, '\000');
    return nullptr;

}

void Scanner::Rollback() {
    if (input == fence)
        reportError(RollbackError);
    input = (--input) % (2 * BUFFSIZE);

}

char Scanner::NextChar() {
    char res = buffer[input];
    input = (++input) % (2 * BUFFSIZE);
    if (input % BUFFSIZE == 0) {
        Fill(input);
        fence = (input + BUFFSIZE) % (2 * BUFFSIZE);
    }
    return res;
}

void Scanner::clearStack() {
    std::stack<State> empty;
    stack.swap(empty);
}

void Scanner::push(State i) {
    stack.push(i);

}

void Scanner::JumpToSafePoint() {
    char c;
    input++;
    c = NextChar();
    lexeme="";
    lexeme+=c;
    while (true) {
        switch (c) {
            case 0:
            case ' ':
            case '\t':
            case '\n':
            case '.':
                return;

        }
        c = NextChar();
        lexeme+=c;
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

    return str.empty() ? true : (isalpha(str[0])
                                 && find_if_not(str.begin() + 1, str.end() - 1, isalnum) == str.end() - 1
                                 && str.size() < 33);
}