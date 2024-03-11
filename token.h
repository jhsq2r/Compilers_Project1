#ifndef TOKEN_H
#define TOKEN_H

struct Token {
        char *idTk;
        char *tokenInstance;
        char *lineCharNum;
        struct Token *next;
};

#endif
