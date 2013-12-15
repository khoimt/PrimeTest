#include <iostream>

using namespace std;

int base[] = {0,2,3,5,7,11,13,17};
int limit[] = {0,2047,
                1373653,
                25326001,
                3215031751,
                2152302898747,
                3474749660383,
                3415500717128321};

int main()
{
    long long N = 499979;
    long long d = N - 1, s= 0;
    while(!(d & 1)) {
        d >>= 1;
        s++;
    }

    long long d1 = d;
    int sw;
    for (int i = 1; i < 8; i++) {
        sw = 0;
        long long a = base[i], prod = 1, a2j = a, d = d1;

        while (d) {
            if (d & 1) prod = (prod * a2j) % N;
            d >>= 1;
            a2j = (a2j * a2j) % N;
        }

        if ((prod == 1) || (prod == (N - 1))) goto label1;
        else {
            for (int j = 1; j <= s - 1; j++) {
                prod = prod * prod % N;
                if (prod == 1) goto label2;
                if (prod == N - 1) goto label1;
            }
        }
        goto label2;
        label1: if (N < limit[i]) {
            sw = 1; goto label2;
        }
    }
    label2: if (sw == 0) {
        cout << N << " is composite" << endl;
    } else {
        cout << N << " is prime" << endl;
    }

    return 0;
}
