#ifndef FUNCTOROBJECT_H
#define FUNCTOROBJECT_H

#include <string>
#include <functional>
#include "textcipher.h"

namespace cipher {

class FunctorObject : public std::unary_function<std::string, std::string>{
protected:
    TextCipher* mCipher;
public:
    FunctorObject(TextCipher* cipherObj);
    virtual ~FunctorObject();
    virtual std::string operator()(const std::string& str) = 0;
};

class EncryptFunctor : public FunctorObject {
public:
    EncryptFunctor(TextCipher* cipherObj);
    std::string operator()(const std::string& str);
};

class DecryptFunctor : public FunctorObject {
public:
    DecryptFunctor(TextCipher* cipherObj);
    std::string operator()(const std::string& str);
};

class FunctorWrapper {
public:
    FunctorWrapper(FunctorObject* functor);
    std::string operator()(const std::string& str);
    void setFunctorObject(FunctorObject* functor);
    FunctorObject* getFunctorObject() const;
private:
    FunctorObject* mFunctor;
};

} //namespace cipher
#endif // FUNCTOROBJECT_H
