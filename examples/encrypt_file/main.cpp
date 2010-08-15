#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <iterator>
#include "../../src/caesarcipher.h"
#include "../../src/functorobject.h"

using namespace std;

int main(int argc, char** argv) {
    cipher::CaesarCipher caesar(5);

    ifstream input("lyrics.txt");
    ofstream output("lyrics_encrypted.txt");
    if(!input.good() || !output.good()) {
        cerr << "Input or output file cannot be opened! Terminating..." << endl;
        return -1;
    }

    cipher::FunctorObject* functor = new cipher::DecryptFunctor(&caesar);
    cipher::FunctorWrapper wrapper(functor);
    transform(istream_iterator<string>(input), istream_iterator<string>(), ostream_iterator<string>(output), wrapper);
    delete functor;
    functor = 0;
    wrapper.setFunctorObject(0);

    return 0;
}
