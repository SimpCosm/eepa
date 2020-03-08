#include <iostream>
using namespace std;

unsigned long long arrange(unsigned long long m, unsigned long long n) {
    unsigned long long result = 1;
    while (n--)
        result *= m--;
    return result;
}

unsigned long long compose(unsigned long long m, unsigned long long n) {
    if ((n << 1) > m)
        n = m - n;
    unsigned long long result = arrange(m, n);
    do {
        result /= n;
    } while (--n);
    return result;
}

int main() {
    unsigned long long a, b, result;
    char kind;
    cin >> a >> b >> kind;
    if (b == 0 || b == a)
        result = 1;
    else if (kind == 'P')
        result = arrange(a, b);
    else
        result = compose(a, b);
    cout << result;
    return 0;
}
