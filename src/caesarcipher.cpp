#include <sstream>
#include <string>
#include <algorithm>
#include "caesarcipher.h"

using cipher::CaesarCipher;
using cipher::TextCipher;

/**
 * Construcor, that sets the shift value.
 *
 * @param shiftValue: the number that we want to shift the characters with
 **/
CaesarCipher::CaesarCipher(const unsigned int shiftValue)
    : TextCipher(), mShift(shiftValue)
{
}

/**
 * Sets the shift value
 *
 * @param val: the new shift value
 **/
void CaesarCipher::setShift(const unsigned int val) {
    mShift = val;
}

/**
 * Returns the shift value
 *
 * @return the currently used shift value
 **/
unsigned int CaesarCipher::getShift() {
    return mShift;
}

/**
 * Encrypts the given plain text with the currently set shift value
 *
 * @param plainText: the text we want to encrypt
 * @return the encrypted text
 **/
std::string CaesarCipher::encrypt(const std::string& plainText) const {
    std::stringstream ss;
    for(std::string::const_iterator it = plainText.begin(); it != plainText.end(); ++it) {
        const char ch = tolower(*it) - 'a';
        if(ch >= 0 && ch <= 25) {
            ss << static_cast<char>((ch + mShift) % 26 + 'a');
        }
    }
    return ss.str();
}

/**
 * Decrypts the given text with the currently set shift value
 *
 * @param cipherText: the text we want to decrypt
 * @return the decrypted text
 **/
std::string CaesarCipher::decrypt(const std::string& cipherText) const {
    std::stringstream ss;
    for(std::string::const_iterator it = cipherText.begin(); it != cipherText.end(); ++it) {
        const char ch = tolower(*it) - 'a';
        if(ch >= 0 && ch <= 25) {
            int v = ch - mShift;
            if(v < 0) v = 26+v;
            ss << static_cast<char>(v % 26 + 'a');
        }
    }
    return ss.str();
}








