#ifndef CPP_MOVE_OLDRESOURCEEXCEPTION_H
#define CPP_MOVE_OLDRESOURCEEXCEPTION_H

#include <stdexcept>

using std::runtime_error;
using std::string;

class OldResourceException : public runtime_error {
private:
    int errorCode;
public:
    OldResourceException() = delete;
    OldResourceException(string const & message, int errorCode);

    [[nodiscard]] int getErrorCode() const;
};


#endif //CPP_MOVE_OLDRESOURCEEXCEPTION_H
