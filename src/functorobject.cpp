#include "functorobject.h"

using cipher::FunctorObject;
using cipher::EncryptFunctor;
using cipher::DecryptFunctor;
using cipher::FunctorWrapper;

/***********************************************************
 ***                    FunctorObject                    ***
 ***********************************************************/

FunctorObject::FunctorObject(TextCipher* cipherObj)
    : mCipher(cipherObj)
{
}

FunctorObject::~FunctorObject(){
}

/***********************************************************
 ***                    EncryptObject                    ***
 ***********************************************************/

EncryptFunctor::EncryptFunctor(TextCipher* cipherObj)
    : FunctorObject(cipherObj)
{
}


std::string EncryptFunctor::operator()(const std::string& str) {
    return mCipher->encrypt(str);
}

/***********************************************************
 ***                    DecryptObject                    ***
 ***********************************************************/

DecryptFunctor::DecryptFunctor(TextCipher* cipherObj)
    : FunctorObject(cipherObj)
{
}

std::string DecryptFunctor::operator()(const std::string& str) {
    return mCipher->decrypt(str);
}

/***********************************************************
 ***                    FunctorWrapper                    ***
 ***********************************************************/

FunctorWrapper::FunctorWrapper(FunctorObject* functor) {
    mFunctor = functor;
}

std::string FunctorWrapper::operator()(const std::string& str) {
    if(mFunctor) {
        return mFunctor->operator()(str);
    } else {
        return "";
    }
}

void FunctorWrapper::setFunctorObject(FunctorObject* functor) {
    mFunctor = functor;
}
FunctorObject* FunctorWrapper::getFunctorObject() const{
    return mFunctor;
}
