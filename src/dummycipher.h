#ifndef DUMMYCIPHER_H
#define DUMMYCIPHER_H

#include "textcipher.h"
#include <string>

namespace cipher {

/**
 * It's a dummy class, only for testing
 **/
class DummyCipher : public cipher::TextCipher {
    public:
        DummyCipher();
        ~DummyCipher();

        std::string encrypt(const std::string& plainText) const;
        std::string decrypt(const std::string& cipherText) const;
};

} //namespace cipher
#endif // DUMMYCIPHER_H
