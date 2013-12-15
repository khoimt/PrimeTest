#include <iostream>

using namespace std;

int main()
{
    int a,d,n,a2i,rs;
    cout << "a, d, N: ";
    cin >> a >> d >> n;
    cout << "a^d % N= ";
    rs = 1;
    a2i = a;
    while (d) {
        if (d & 1) rs = (rs * a2i) % n;
        d >>= 1;
        a2i = (a2i * a2i) % n;
    }
    cout << rs << endl;

    return 0;
}
