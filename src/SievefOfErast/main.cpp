#include <iostream>
using namespace std;

bool arr[1000000];
int main() {
    int n = 100;
    for (int i = 4; i <= n; i+=2) arr[i] = true;

    int i = 3;
    while (i * i <= n) {
        i += 2;
        if (arr[i]) continue;
        int j = i + i;
        while (j <= n) {
            arr[j] = true;
            j += i;
        }
    }

    for (int i = 2; i <= n; i++) {
        if (!arr[i]) cout << i << ' ';
    }
    return 0;
}
