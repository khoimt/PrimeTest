#include <iostream>
using namespace std;
bool isPrime (long long n) {
    if (n <= 3) return true;
    if ((n & 1) == 0 || (n % 3) == 0)  return false;
    long long i = 5;
    while (i * i <= n) {
        if ((n % i) == 0) return false;
        int j = i + 2;
        if (j*j <= n && (n % j) == 0) return false;
        i += 6;
    }
    return true;
}
int main() {
    long long n = 200560490131ll;
    cout << n << " is prime" << endl;
    return 0;
}
