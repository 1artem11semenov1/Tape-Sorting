#include <iostream>
#include <fstream>
#include "Tape.hpp"
#include "Sorter.hpp"

int main(int argc, char* argv[]){
    Tape* test = new Tape(argv[1]);
    Tape* testOut = new Tape(argv[2]);
    int N;
    N = atoi(argv[3]);

    Sorter s(test, testOut, N);
    s.natMergeSort();

    return 0;
}