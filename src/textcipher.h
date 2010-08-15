#ifndef TEXTCIPHER_H
#define TEXTCIPHER_H

#include <string>

namespace cipher {

/**
 * TextCipher is the base class for the cipher classes.
 * The encrypt/decrypt methods must be overridden in every subclass.
 **/
class TextCipher {
public:
    TextCipher();
    virtual ~TextCipher();

    virtual std::string encrypt(const std::string& plainText) const = 0;
    virtual std::string decrypt(const std::string& cipherText) const = 0;
};

}//namespace cipher
#endif // TEXTCIPHER_H
