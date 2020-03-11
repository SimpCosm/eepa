/*
 * File Name: B.cpp
 * Author: Houmin <houmin.wei@pku.edu.cn>
 * Created: 29/02/2020
 * Description:
 *  Solution for [Simple Calculator](http://eepa.openjudge.cn/2020practice03/B)
 */
#include <algorithm>
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
const char number = '8';
const char quit = 'q';
const char print = ';';
const char name = 'a';
const char let = 'L';
const string declkey = "let";
class Variable {
public:
    string name;
    double value;
    Variable(string n, double v) :name(n), value(v) {}
};
vector<Variable>var_table;
class Token {
public:
    Token(char ch)
    {
        kind = ch; value = 0;
    }
    Token(char ch, double val)
    {
        kind = ch; value = val;
    }
    Token(char ch, string n)
    {
        kind = ch; name = n;
    }
    char kind;
    double value;
    string name;
};
class Token_stream {
public:
    Token_stream();
    Token get();
    void putback(Token t);
private:
    bool full{ false };
    Token buffer;
};
void Token_stream::putback(Token t)
{
    buffer = t;
    full = true;
}
Token Token_stream::get()
{
    if (full) { full = false; return buffer; }
    char ch;
    cin >> ch;
    switch (ch) {
    case'(':case')':case';':case'q':
    case'+':case'-':case'*':case'/':
    case'{':case'}':case'=':
        return Token{ ch };
    case'.':case'0':case'1':case'2':
    case'3':case'4':case'5':case'6':
    case'7':case'8':case'9':
    {
        cin.putback(ch);
        double val;
        cin >> val;
        return Token{ number,val };
    }
    default:
        if (isalpha(ch)) {
            string s;
            s += ch;
            while (cin.get(ch)&&(isalpha(ch)|| isdigit(ch)))s += ch;
            cin.putback(ch);
            if (s == declkey)return Token(let);
            return Token(name, s);
        }
    }
}

Token_stream::Token_stream() :full(false), buffer(0)    //Token_stream构造函数
{}
Token_stream ts;

double expression();
double primary() {
    Token t = ts.get();
    switch (t.kind) {
    case'(':
    {
        double d = expression();
        t = ts.get();
        return d;
    }
    case'{':
    {
        double d = expression();
        t = ts.get();
        return d;
    }
    case number:
        return t.value;
    case '-':
        return -primary();
    case'+':
        return primary();
    case name:
    {
        for (int i = 0; i < var_table.size(); ++i)
        {
            if (t.name == var_table[i].name)
                return var_table[i].value;
        }
    }
    }
}
double term() {
    double left = primary();
    while (true) {
        Token t = ts.get();
        switch (t.kind) {
        case'*':left *= primary(); break;
        case'/':
        {
            double d = primary();

            left /= d; break;
        }
        default:ts.putback(t); return left;
        }
    }
}
double expression()
{
    double left = term();
    while (true) {
        Token t = ts.get();
        switch (t.kind) {
        case'+':left += term(); break;
        case'-':left -= term(); break;
        default:ts.putback(t); return left;
        }
    }
}

double get_value(string s)                                       //获得变量值
{
    for (int i = 0; i < var_table.size(); ++i)
    {
        if (var_table[i].name == s)return var_table[i].value;
    }
}
void set_value(string s, double d)                               //设置变量值
{
    for (int i = 0; i < var_table.size(); ++i)
    {
        if (var_table[i].name == s)
        {
            var_table[i].value = d;
            return;
        }
    }
}
double declaration();
Token statement()
{
    Token t = ts.get();
    double d = 0, e = 0;
    switch (t.kind) {
    case let:
        d = declaration();
        return Token(name, d);
    default:
        ts.putback(t);
        e = expression();
        return Token(number, e);
    }
}

void calculate()
{
    while (cin)
    {
        Token t = ts.get();
        while (t.kind == print)
            t = ts.get();
        if (t.kind == quit)
            return;
        ts.putback(t);
        Token s = statement();
        if (s.kind == number)
            cout << fixed << setprecision(6) << s.value << endl;
    }
}

bool is_declared(string var)
{
    for (int i = 0; i < var_table.size(); ++i)
        if (var_table[i].name == var)return true;
    return false;
}

double define_name(string var, double val)
{
    var_table.push_back(Variable(var, val));
    return val;
}

double declaration()
{
    Token t = ts.get();
    string var_name = t.name;
    Token t2 = ts.get(); // eat '='
    double d = expression();
    define_name(var_name, d);
    return d;
}

int main()
{
    define_name("pi", 3.1415926535);
    define_name("e", 2.7182818284);

    calculate();
    return 0;

}
