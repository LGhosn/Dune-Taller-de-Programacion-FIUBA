#ifndef COMMON_SOCKET_ERROR_H_
#define COMMON_SOCKET_ERROR_H_

#include <exception>

#define BUFF_LEN 256

class SocketError: public std::exception {
private:
    char msg_error[BUFF_LEN];

public:
    SocketError() noexcept;
    SocketError(const char *fmt, ...) noexcept;
    virtual const char *what() const noexcept;
    virtual ~SocketError() noexcept = default;
};
#endif  // COMMON_SOCKET_ERROR_H_
