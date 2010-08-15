#include "dummycipher.h"

using cipher::DummyCipher;

DummyCipher::DummyCipher()
    : TextCipher()
{
}

DummyCipher::~DummyCipher()
{
}

/**
 * Returns the same text
 **/
std::string DummyCipher::encrypt(const std::string& plainText) const {
    return plainText;
}

/**
 * Returns the same text
 **/
std::string DummyCipher::decrypt(const std::string& cipherText) const {
    return cipherText;
}
