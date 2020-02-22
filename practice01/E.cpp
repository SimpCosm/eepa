/*
 * File Name: E.cpp
 * Author: Houmin <houmin.wei@pku.edu.cn>
 * Created: 22/02/2020
 * Description:
 *  Solution for find prime number using *Sieve of Eratosthenes* algorithm.
 *  Original problem is [here](http://eepa.openjudge.cn/2020practice01/E).
 *  See Sieve of Eratosthenes: https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
 */
#include <iostream>
#include <vector>
using namespace std;

/*
 * Simple code from wikipedia
 */
int eratosthenes(int bottombound, int upperbound){
    std::vector<bool> flag(upperbound+1, true);
	flag[0] = flag[1] = false; //exclude 0 and 1

	for(int i = 2; i <= upperbound; ++i)
	    if(flag[i]) // if i is prime number
		    for(int j = i*i; j <= upperbound; j += i)
			    flag[j] = false;

    int count = 0;
    for (int i = bottombound; i <= upperbound; ++i) {
        if (flag[i])
            count++;
    }
    return count;
}

int main() {
    int bottom, upper;
    cin >> bottom >> upper;
    cout << eratosthenes(bottom, upper) << endl;
    return 0;
}

