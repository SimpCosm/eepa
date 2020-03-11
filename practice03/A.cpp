/*
 * File Name: A.cpp
 * Author: Houmin <houmin.wei@pku.edu.cn>
 * Created: 29/02/2020
 * Description:
 *  Solution for [Simple Calculator](http://eepa.openjudge.cn/2020practice03/A)
 */
#include <iostream>
#include <iomanip>
using namespace std;

const char number = '8';
const char quit ='\n';


inline void error(const string& s)
{
    throw runtime_error(s);
}


class token
{
public:
    char kind;
    double value;
    token(char ch)
        :kind(ch), value(0) {}
    token(char ch, double val)
        :kind(ch), value(val) {}
};

class token_stream
{
public:
    token_stream();
    token get();
    void putback(token t);
private:
    token buffer;
    bool full;
};

token_stream::token_stream()
    :full(false), buffer(0)    // no Token in buffer
{

}

token_stream ts;


void token_stream::putback(token t)

{
    if (full) error("putback() into a full buffer");
    buffer = t;       // copy t to buffer
    full = true;      // buffer is now full
}

token token_stream::get()
{
    if (full)
    {
        full = false;
        return buffer;
    }
    char ch;
    cin >>noskipws>> ch;

    switch (ch)
    {
        case quit:
        case '+':
        case '-':
        case '*':
        case '/':
        case '(':case ')':case '{':case '}':
            return token(ch);
        case '0': case '1': case '2': case '3': case '4': case '5':
        case '6': case '7': case '8': case '9':
        case '.':
        {
            cin.putback(ch);
            double val;
            cin >> val;
            return token(number, val);
        }
        default:
            error("bad token");
            return token(ch);
    }
}

double expression();
double term();
double primary();
//循环调用


double expression()
{
    double left = term();
    token t = ts.get();
    while (true)
    {
        switch (t.kind)
        {
            case '+':
                left += term();
                t = ts.get();
                break;
            case '-':
                left -= term();
                t = ts.get();
                break;
            default:
                ts.putback(t);
                return left;
        }
    }
}

double term()
{
    double left = primary();
    token t = ts.get();
    while (true)
    {
        switch (t.kind)
        {
            case '*':
                left *= primary();
                t = ts.get();
                break;
            case '/':
            {
                double d = primary();
                if (d == 0) error("divide by zero");
                left /= d;
                t = ts.get();
                break;
            }
            default:
                ts.putback(t);
                return left;
        }
    }
}

double primary()
{
    token t = ts.get();
    while (true)
    {
        switch (t.kind)
        {
            case number:
                return t.value;
            case '(':
            {
                double d = expression();
                t = ts.get();
                if (t.kind != ')') error("')' expected");
                return d;
            }
            case '{':
            {
                double d = expression();
                t = ts.get();
                return d;
            }
            default:
                error("primary expected");
                return 0;
        }
    }
}



int main()
{
    try {
        double val = 0;
        while (cin) {
            token t = ts.get();
            if (t.kind == quit) {
                cout << fixed << setprecision(6) << val << endl;
                break;
            }

            else {
                ts.putback(t);
                val = expression();
            }
        }
    }

    catch (exception & e) {
        cerr << e.what() << endl;
        return 1;
    }

    catch (...) {
        cerr << "exception \n";
        return 2;
    }
}
