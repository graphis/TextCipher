#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <iterator>
#include "../../src/caesarcipher.h"
#include "../../src/functorobject.h"

using namespace std;

void print_usage();

int main(int argc, char** argv) {
    if(argc < 5) {
	print_usage();
	return -1;
    }
    enum Mode{ENCRYPT, DECRYPT};
    Mode m;
    if(!strcmp(argv[3], "encrypt")) {
	m = ENCRYPT;
    } else if(!strcmp(argv[3], "decrypt")){
	m = DECRYPT;
    } else {
	print_usage();
	return -1;
    }
    string ifName(argv[1]);
    string ofName(argv[2]);
    const int shift = atoi(argv[4]);
    cipher::CaesarCipher caesar(shift);

    ifstream input(ifName.c_str());
    ofstream output(ofName.c_str());
    if(!input.good() || !output.good()) {
        cerr << "Input or output file cannot be opened! Terminating..." << endl;
        return -1;
    }

    cipher::FunctorObject* functor;
    m == ENCRYPT ? 
		functor = new cipher::EncryptFunctor(&caesar) :
		functor = new cipher::DecryptFunctor(&caesar);
		    
    cipher::FunctorWrapper wrapper(functor);
    transform(istream_iterator<string>(input), istream_iterator<string>(), ostream_iterator<string>(output), wrapper);
    delete functor;
    functor = 0;
    wrapper.setFunctorObject(0);

    return 0;
}

void print_usage() {
    cout << "Usage: main <input_file> <output_file> <encrypt/decrypt> <shift>" << endl;
}