/*
 * File Name: A.cpp
 * Author: Houmin <houmin.wei@pku.edu.cn>
 * Created: 22/02/2020
 * Description:
 *  Solution for number sort using *selection sort* algorithm. Original
 * problem is [here](http://eepa.openjudge.cn/2020practice01/A). See
 * selection sort: https://en.wikipedia.org/wiki/Selection_sort
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int size = 3;

/*
 * As we all know, we already have a sort function in STL.
 * See: http://www.cplusplus.com/reference/algorithm/sort
 * Here we present one simple implementation for *sort*, you
 * can always do much better.
 */
void Sort(vector<int>& array, int begin, int end) {
    // corner case check
    if (begin < 0 || end > array.size()-1)
        return;

    for (int i = begin; i <= end-1; i++) {
        int minIndex = i;
        for (int j = i+1; j <= end; j++) {
            if (array[minIndex] > array[j])
                minIndex = j;
        }
        // see *swap*: http://www.cplusplus.com/reference/utility/swap
        swap(array[i], array[minIndex]);
    }
}

int main() {
    vector<int> array(3, 0);
    for (int i = 0; i < size; i++)
        cin >> array[i];

    Sort(array, 0, size-1);

    for (int i = 0; i < size-1; i++)
        cout << array[i] << ',';
    cout << array[size-1] << endl;

    return 0;
}

