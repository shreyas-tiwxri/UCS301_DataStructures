//a
#include <iostream>
using namespace std;

class DiagonalMatrix {
    int* A;
    int n;
public:
    DiagonalMatrix(int size) {
        n = size;
        A = new int[n];
    }
    void set(int i, int j, int value) {
        if (i == j) A[i - 1] = value;
    }
    int get(int i, int j) {
        return (i == j) ? A[i - 1] : 0;
    }
};