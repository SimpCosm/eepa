/*
本题可以初步学会与文件相关操作。
*/
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
struct Reading {    //温度数据读取
	int hour;                // 在[0:23]区间取值的小时数
	double temperature;      // 华氏温度
};
vector<Reading> vecinfo;
int main(){
	int _hour;
	double _temperature;
	//重定向到文件输入
	while (cin >> _hour >> _temperature){
		Reading r;
		r.hour = _hour;
		r.temperature = _temperature;
		vecinfo.push_back(r);
	}

	ofstream outfile;//输出文件流
	outfile.open("store_temps.txt");//默认是覆盖写入
	/*
	outfile.open("store_temps.txt", ios::out|ios::app);不能用此追加写入,可以参考下面文章
	https://blog.csdn.net/cfl997/article/details/103387997?depth_1-utm_source=distribute.pc_relevant.none-task&utm_source=distribute.pc_relevant.none-task
	把元素写入文件
	*/
	for (auto info : vecinfo){
		outfile << info.hour << " " << info.temperature << endl;
	}
	outfile.close();
	return 0;
}