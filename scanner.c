#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<ctype.h>
#include"scanner.h"

enum TokenType {
        INT_TK = 1001,
        IDENT_TK = 1002,
        OP_TK = 1003,
        ERROR_TK = -1,
        EOF_TK = 1004,
        KW_TK = 1005
};

enum State {
        S1 = 0,
        S2 = 1,
        S3 = 2,
        S4 = 3,
        S5 = 4,
        S6 = 5,
        S7 = 6,
        S8 = 7
};

const char *const specialChar[] = {
        "=","<",">",":",";","+","-","*","/","^",
        ".","(",")",",","{","}","[","]","|","&"
};


const char *const IDENTIFIER = "ID_TK";
const char *const INTEGER = "INT_TK";

const char *const KW0 = "START_TK";
const char *const KW1 = "STOP_TK";
const char *const KW2 = "WHILE_TK";
const char *const KW3 = "REPEAT_TK";
const char *const KW4 = "UNTIL_TK";
const char *const KW5 = "LABEL_TK";
const char *const KW6 = "RETURN_TK";
const char *const KW7 = "CIN_TK";
const char *const KW8 = "COUT_TK";
const char *const KW9 = "TAPE_TK";
const char *const KW10 = "JUMP_TK";
const char *const KW11 = "IF_TK";
const char *const KW12 = "THEN_TK";
const char *const KW13 = "PICK_TK";
const char *const KW14 = "CREATE_TK";
const char *const KW15 = "SET_TK";
const char *const KW16 = "FUNC_TK";

const char *const OPERATOR = "OPERATOR_TK";

const char *const keyWords[] = {
        "start", "stop", "while", "repeat", "until", "label", "return",
        "cin", "cout", "tape", "jump", "if", "then", "pick", "create",
        "set", "func"
};

const int FSATABLE[][26] = {
//       =        <        >        :        ;        +        -        *        /        ^        .        (        )        ,        {        }        [        ]        |        &        !        a-Z      0-9      _        /n       EOF
        {S4,      OP_TK,   OP_TK,   S6,      OP_TK,   OP_TK,   OP_TK,   OP_TK,   OP_TK,   OP_TK,   OP_TK,   OP_TK,   OP_TK,   OP_TK,   OP_TK,   OP_TK,   OP_TK,   OP_TK,   S7,      S8,      ERROR_TK,S2,      S3,      ERROR_TK,S1,      EOF_TK  },//S1
        {IDENT_TK,IDENT_TK,IDENT_TK,IDENT_TK,IDENT_TK,IDENT_TK,IDENT_TK,IDENT_TK,IDENT_TK,IDENT_TK,IDENT_TK,IDENT_TK,IDENT_TK,IDENT_TK,IDENT_TK,IDENT_TK,IDENT_TK,IDENT_TK,IDENT_TK,IDENT_TK,IDENT_TK,S2,      S2,      S2,      IDENT_TK,IDENT_TK},//S2
        {INT_TK,  INT_TK,  INT_TK,  INT_TK,  INT_TK,  INT_TK,  INT_TK,  INT_TK,  INT_TK,  INT_TK,  INT_TK,  INT_TK,  INT_TK,  INT_TK,  INT_TK,  INT_TK,  INT_TK,  INT_TK,  INT_TK,  INT_TK,  INT_TK,  INT_TK,  S3,      INT_TK,  INT_TK,  INT_TK},  //S3
        {OP_TK,   OP_TK,   OP_TK,   OP_TK,   OP_TK,   OP_TK,   OP_TK,   OP_TK,   OP_TK,   OP_TK,   OP_TK,   OP_TK,   OP_TK,   OP_TK,   OP_TK,   OP_TK,   OP_TK,   OP_TK,   OP_TK,   OP_TK,   S5,      OP_TK,   OP_TK,   OP_TK,   OP_TK,   OP_TK},   //S4
        {OP_TK,   ERROR_TK,ERROR_TK,ERROR_TK,ERROR_TK,ERROR_TK,ERROR_TK,ERROR_TK,ERROR_TK,ERROR_TK,ERROR_TK,ERROR_TK,ERROR_TK,ERROR_TK,ERROR_TK,ERROR_TK,ERROR_TK,ERROR_TK,ERROR_TK,ERROR_TK,ERROR_TK,ERROR_TK,ERROR_TK,ERROR_TK,ERROR_TK,ERROR_TK},//S5
        {OP_TK,   OP_TK,   OP_TK,   OP_TK,   OP_TK,   OP_TK,   OP_TK,   OP_TK,   OP_TK,   OP_TK,   OP_TK,   OP_TK,   OP_TK,   OP_TK,   OP_TK,   OP_TK,   OP_TK,   OP_TK,   OP_TK,   OP_TK,   OP_TK,   OP_TK,   OP_TK,   OP_TK,   OP_TK,   OP_TK},   //S6
        {ERROR_TK,ERROR_TK,ERROR_TK,ERROR_TK,ERROR_TK,ERROR_TK,ERROR_TK,ERROR_TK,ERROR_TK,ERROR_TK,ERROR_TK,ERROR_TK,ERROR_TK,ERROR_TK,ERROR_TK,ERROR_TK,ERROR_TK,ERROR_TK,OP_TK,   ERROR_TK,ERROR_TK,ERROR_TK,ERROR_TK,ERROR_TK,ERROR_TK,ERROR_TK},//S7
        {ERROR_TK,ERROR_TK,ERROR_TK,ERROR_TK,ERROR_TK,ERROR_TK,ERROR_TK,ERROR_TK,ERROR_TK,ERROR_TK,ERROR_TK,ERROR_TK,ERROR_TK,ERROR_TK,ERROR_TK,ERROR_TK,ERROR_TK,ERROR_TK,ERROR_TK,OP_TK,   ERROR_TK,ERROR_TK,ERROR_TK,ERROR_TK,ERROR_TK,ERROR_TK} //S8
};


void testFunction(){
        printf("%d\n", FSATABLE[0][0]);
}
