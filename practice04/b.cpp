/**
 * @file b.cpp
 * @author shiwenhao
 * @brief 姓名和年龄对排序
 * @version 0.1
 * @date 2020-03-11
 *
 * @copyright Copyright (c) 2020
 *
描述
输入两行，分别是5个名字和5个年龄。

你的程序要做的事情是对名字排序，并且输出(name[i], age[i])对

输入
两行，分别是5个名字和年龄
输出
排序后的姓名年龄对，对和对之间以空格分开
样例输入
Tom Jerry Bob Alice Carol
79 79 19 18 21
样例输出
(Alice, 18) (Bob, 19) (Carol, 21) (Jerry, 79) (Tom, 79)
 */

// 鉴于此时的学习进度，使用较为初级的C++语法。在学习了后面的知识之后可以尝试使用类和运算符重载实现

#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::swap;
using std::vector;

const int kNumStudent = 5;

void SortName(vector<string>& name, vector<int>& age) {
  // 此处假设name和age大小相同
  // 插入排序
  const int kSize = name.size();
  for (int i = 0; i < kSize - 1; ++i) {
    int swap_index = i;
    for (int j = i + 1; j < kSize; ++j) {
      if (name[j] < name[swap_index]) swap_index = j;
    }
    swap(name[i], name[swap_index]);
    swap(age[i], age[swap_index]);
  }
}

void PrintNameAgePair(const string& name, int age) {
  cout << '(' << name << ", " << age << ')';
}

void PrintNameAge(const vector<string>& name, const vector<int>& age) {
  const int kSize = name.size();
  PrintNameAgePair(name[0], age[0]);
  for (int i = 1; i < kSize; ++i) {
    cout << ' ';
    PrintNameAgePair(name[i], age[i]);
  }
  cout << endl;
}

int main() {
  vector<string> name(kNumStudent);
  vector<int> age(kNumStudent);
  for (int i = 0; i < kNumStudent; ++i) cin >> name[i];
  for (int i = 0; i < kNumStudent; ++i) cin >> age[i];
  SortName(name, age);
  PrintNameAge(name, age);
  return 0;
}