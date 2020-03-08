#include <iostream>
using namespace std;

unsigned long arrange(unsigned long m, unsigned long n) {
    unsigned long result = 1;
    while (n--)
        result *= m --;
    return result;
}

unsigned long compose(unsigned long m, unsigned long n) {
    if ((n << 1) < m)
        n = m - n;
    unsigned long result = arrange(m, m - n);
    while (--n)
        result /= n;
    return result;
}

int main() {
  unsigned long a,b,result;
  char kind;
  cin>>a>>b>>kind;
  switch (kind) {
  case 'P':
      cout << arrange(a, b) << endl;
      break;
  default:
      cout << compose(a, b) << endl;
  }
  return 0;
}
