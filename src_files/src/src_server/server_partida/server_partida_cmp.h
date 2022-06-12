#ifndef SERVER_PARTIDA_CMP_H
#define SERVER_PARTIDA_CMP_H

#include <string>


struct PartidaCmp {
    bool operator()(const std::string& lhs, const std::string& rhs) const {
        if (lhs < rhs) {
            return true;
        }
        return false;
    }
};

#endif //SERVER_PARTIDA_CMP_H
