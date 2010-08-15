#ifndef CAESARCIPHER_H
#define CAESARCIPHER_H

#include "textcipher.h"

namespace cipher {

/**
 * Class that can be used to encrypt/decrypt a text with
 * the classic Caeasar cipher method.
 *
 * This cipher shifts the characters with a given constant number.
 * Every character is converted to lowercase, and if the character
 * is not from the english alphabet, it is skipped!
 *
 * Example:
 *  plain text: Hello World!
 *  shift number: 3
 *  result: khoorzruog (helloworld)
 **/
class CaesarCipher : public TextCipher {
    unsigned int mShift;
public:
    CaesarCipher(const unsigned int shiftValue);
    unsigned int getShift();
    void setShift(const unsigned int val);

    std::string encrypt(const std::string& plainText) const;
    std::string decrypt(const std::string& cipherText) const;
};
} //namespace cipher
#endif // CAESARCIPHER_H
