#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
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
	//注意华氏度转摄氏度的公式
	for (auto info : vecinfo){
		outfile << info.hour << " " << fixed << setprecision(2) << (info.temperature - 32) / 1.8 << endl;
	}
	outfile.close();
	return 0;
}