#include <stdio.h>
#include <stdlib.h>
#include "error_msgs.h"

struct Error get_error(int _error_code){
    struct Error error;
    error.code = _error_code;

    char* message;

    //Make the error structs from error codes(enum in .h)
    switch(_error_code){
        case ERR_BUFFER_NULL:
            message = "A buffer is null."
            error.message = message;
        break;
        case ERR_BUFFER_OUT_OF_BOUNDS:
            message = "A buffer has recieved input data bigger than allowed."
            error.message = message;
        break;
        case ERR_DS_FULL:
            message = "The datastructure is full.";
            error.message = message;
        break;
        case ERR_DS_EMPTY_ON_CALL:
            message = "The called datastructure has no elements."
            error.message = message
        break;
    }

    return error;
}

//Throw Error
void throwError(int _error_code){
    Error error = get_error(_error_code);

    printf("{ERROR}: %s\n", error.message);
    printf("[|| EXITING PROGRAM ||]\n");
    exit(_error_code);
}

void throwWarning(int _error_code){
    Error error = get_error(_error_code);

    printf("{WARNING}: %s\n", error.message);
}
