/**
 * @file a.cpp
 * @author shiwenhao
 * @brief 斐波那契数列
 * @version 0.1
 * @date 2020-03-11
 *
 * @copyright Copyright (c) 2020
 *
描述
构造斐波那契数列，输入是x,y和n。

x和y分别是第一个数和第二个数，n是需要构造的斐波那契数列的长度

输出构造出来的斐波那契数列，以空格分隔

输入
输入的x, y, n
输出
输出构造出来的斐波那契数列，以空格分隔
样例输入
1 2 5
样例输出
1 2 3 5 8
 */

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
  int data[3], n;
  cin >> data[0] >> data[1] >> n;
  int z = 0;
  // 特殊情况处理
  if (n <= 0) return 0;
  cout << data[0];
  if (n >= 1) cout << " " << data[1];
  /**
   * 斐波那契数列数列每个数只和前两个数有关，因此可以只保存两个历史结果减少内存使用
   */
  for (int i = 2; i < n; ++i) {
    data[i % 3] = data[(i + 1) % 3] + data[(i + 2) % 3];
    cout << " " << data[i % 3];
  }
  cout << endl;
}