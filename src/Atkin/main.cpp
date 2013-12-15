#include <iostream>
#include <cmath>

using namespace std;

void findPrimes(int arraySize);
bool isPrime[100000000];
int main()
{
    int arraySize = 10000000;

    int sqrtArraySize;
    sqrtArraySize = sqrt(arraySize);

    for (int x = 1; x <= sqrtArraySize; x++) {
        for (int y = 1; y <= sqrtArraySize; y++) {
            int n = 4 * x * x + y * y;
            if (n <= arraySize && (n % 12 == 1 || n % 12 == 5)) isPrime[n] = !isPrime[n];

            n = 3 * x * x + y * y;
            if (n <= arraySize && (n % 12 == 7)) isPrime[n] = !isPrime[n];

            if (x > y) {
                n = 3 * x * x - y * y;
                if (n <=arraySize && n % 12 == 11) isPrime[n] = !isPrime[n];
            }
        }//end 2nd FOR LOOP
    }//end 1st FOR LOOP

    for (int n = 5; n <= sqrtArraySize; n++) {
        if (isPrime[n]) {
            int omit = n * n;
            for (int k = omit; k <=arraySize; k +=omit)
                isPrime[k] = false;
        }
    }

    for (int x = 2; x <= arraySize; x++)
        if (isPrime[x])
            cout << x << "\t" << flush;

    return 0;
}
