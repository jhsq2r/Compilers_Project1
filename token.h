#ifndef TOKEN_H
#define TOKEN_H

struct Token {
        char *idTk;
        char *tokenInstance;
        int lineNum;
        int charNum;
};

#endif
