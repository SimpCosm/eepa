# 上机作业 12

1. 编写一个函数 `char* strdup(const char*)`, 将 C 风格字符串复制到自由空间上分配的内存中，函数返回指向自由空间存储字符串的指针，请根据字符串的实际长度从自由空间申请合适大小的内存，不要使用任何标准库提供的函数。（注： C 风格字符串是一个以 0 为结尾的字符数组，最后一个字符的 ASCII 值为 0 。）

参考代码：
```c
int length(const char* s){
    int len = 0;
    while(*s++) len++;
    return len;
}

char* strdup(const char* s){
    char* buf = new char[length(s)];
    // while(*buf++ = *s++);
    for(int i = 0; buf[i] = s[i]; i++);
    return buf;
}
```

2.  编写一个函数`const char* findx(const char* s, const char* x）`,在C风格字符串s中查找字符串x首次出现的位置，函数返回指向该位置的指针。

参考代码：
```c
const char* findx(const char* s, const char* x){
    while(*s++){
        const char* p = s;
        const char* q = x;
        while(*p++ == *q++);
        if(*q == '\0') return s;
    }
    return nullptr;
}
```

3.  计算机的内存是有限的，程序可以从自由存储区动态申请的内存也是有限的。编写程序测试一下你的程序最多可以申请多大的内存，内存耗尽时会发生什么情况？（通过无限循环分配内存而不释放）

**解释**：本题主要考察对于内存的理解，程序的运行会消耗内存，如果每次通过 new 动态向操作系统申请内存而不 delete 掉，就会形成一大堆的内存碎片。为了测试程序最多可以申请多大的内存，可以一直 new 而不 delete，如参考代码所示。

根据不同机器的硬件条件，本代码在不同的机器上运行会得到不同的结果。

参考代码：
```c
void memory_test() {
    int cnt = 0;
    while (1) {
        int *p = new int[256 * 1024];  // sizeof(int) = 4
        cnt++;                  // increase cnt for 1MB
        cout << cnt << endl;
    }
}
```

4.  编写一个程序从cin读取字符保存到自由空间分配的数组中，读取字符直到输入感叹号（!）为止。考虑当输入的字符数量超过预先从自由空间分配的数组长度时该如何处理。

**解释**：本地主要是考察如果输入字符数量超过了自由空间分配的数组长度时候该如何处理，这里的参考代码用了最直接的思路，就是每一次输入一个字符就重新申请一段新的内存，然后将之前保存的复制过来。这种思路当然直接粗暴而低效，但是比起有些同学固定分配内存大小而不考虑溢出的情况，则要好得多。

为了实现更加高效的动态数组，可以参考 STL 中 vector 的实现，看它是如何同时兼顾效率和性能的。
参考代码：
```c

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
```
