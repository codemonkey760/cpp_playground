#include "OldResourceException.h"

OldResourceException::OldResourceException(string const & message, int errorCode):
runtime_error(message.c_str())
{
    this->errorCode = errorCode;
}

int OldResourceException::getErrorCode() const
{
    return this->errorCode;
}