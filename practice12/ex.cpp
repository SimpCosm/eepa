#include <iostream>
#include <stdexcept>

using namespace std;

/*1. Write a function, char* strdup(const char*), that copies a C-style string
   into memory it allocates on the free store. Do not use any standard library
   functions. Do not use subscripting; use the dereference operator * instead.
*/
int length(const char* s){
    int len = 0;
    while(*s++) len++;
    return len;
}

char* strdup(const char* s){
    int len = length(s);
    char* buf = new char[len];
    for(int i = 0; i < len; i++)
        buf[i] = s[i];
    buf[len] = '\0';
    return buf;
}
/*
2. Write a function, char* findx(const char* s, const char* x), that finds the
   first occurrence of the C-style string x ins. Do not use any standard library
   functions. Do not use subscripting; use the dereference operator * instead.
*/
const char* findx(const char* s, const char* x){
    while(*s++){
        const char* p = s;
        const char* q = x;
        while(*p++ == *q++);
        if(*q == '\0') return s;
    }
    return nullptr;
}

void memory_test() {
    int cnt = 0;
    while (1) {
        int *p = new int[256 * 1024];  // sizeof(int) = 4
        cnt++;                  // increase cnt for 1MB
        cout << cnt << endl;
    }
}

const char* my_cin() {
    int len = 0;
    char s;
    char *p = NULL;
    char *tmp = NULL;

    while (cin >> noskipws >> s) {
        if (s == '!') {
            break;
        }

        p = new char[len];
        for (int i = 0; i < len; i++)
            p[i] = tmp[i];
        p[len] = s;
        p[len+1] = '\0';
        delete [] tmp;
        tmp = p;
        len++;
    }
    return p;
}

int main(int argc, char const *argv[])
{
    char* s1 = strdup("Nice To Meet You!");
    cout << s1 << endl;

    const char* s2 = findx("Hello Wor!", "World!");
    if (s2 == nullptr) cout << "nullptr" <<endl;

    const char* s3 = findx("Hello Wor!", "Wor!");
    cout << s3 <<endl;

    // memory_test();

    cout << my_cin() << endl;

    return 0;
}
