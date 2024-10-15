#ifndef ERROR_MSGS
#define ERROR_MSGS

typedef struct Error{
    char* message;
    int code;
} Error;

typedef enum{
    ERR_DEFAULT,
    ERR_BUFFER_NULL,
    ERR_BUFFER_OUT_OF_BOUNDS,
    ERR_DS_FULL,
    ERR_DS_EMPTY_ON_CALL,
} ERROR_CODE;

void throwError(int _error_code);
void throwWarning(int _error_code);

#endif
