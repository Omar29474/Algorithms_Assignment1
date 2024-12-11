#include <iostream>
using namespace std;

// 1: Fibonacci Series
// Fibonacci series using recursion:
int Recursion(int n) {
    if (n <= 1)
        return n;
    else
    return Recursion(n - 1) + Recursion(n - 2);
}

// Fibonacci series using divide and conquer (matrix multiplication):
void multiplyMatrix(int N[2][2], int M[2][2]) {
    int r[2][2];
    r[0][0] = N[0][0] * M[0][0] + N[0][1] * M[1][0];
    r[0][1] = N[0][0] * M[0][1] + N[0][1] * M[1][1];
    r[1][0] = N[1][0] * M[0][0] + N[1][1] * M[1][0];
    r[1][1] = N[1][0] * M[0][1] + N[1][1] * M[1][1];

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            N[i][j] = r[i][j];
}

void powerMatrix(int N[2][2], int n) {
    if (n <= 1) return;
    int M[2][2] = {{1, 1}, {1, 0}};
    powerMatrix(N, n / 2);
    multiplyMatrix(N, N);
    if (n % 2 != 0) {
        multiplyMatrix(N, M);
    }
}

int fibMatrix(int n) {
    if (n == 0) return 0;
    int N[2][2] = {{1, 1}, {1, 0}};
    powerMatrix(N, n - 1);
    return N[0][0];
}

// Fibonacci series using dynamic programming:
int dynamicprogramming(int n) {
    if (n <= 1)
        return n;
    int fib[n + 1];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib[n];
}

int main() {
    int n;
    cout << "Enter the number (n): ";
    cin >> n;
    cout << "Recursion: " << Recursion(n) << endl;
    cout << "Matrix multiplication: " << fibMatrix(n) << endl;
    cout << "Dynamic Programming: " << dynamicprogramming(n) << endl;
    return 0;
}
