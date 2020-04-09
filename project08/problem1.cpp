#include <tchar.h>
#include <vector>
#include "Simple_window.h"
#include "Graph.h"
using namespace std;
using namespace Graph_lib;

int _tmain(int argc, _TCHAR* argv[]) {
	Point p1(200, 200);
	Simple_window win(p1, 600, 400, "Test");
	vector<Graph_lib::Rectangle*> recs;
	for (int i = 0; i < 9; i++) {
		auto rec = new Graph_lib::Rectangle(Point(100 + 50 * (i % 3), 100 + 50 * (i / 3)), 50, 50); // 计算出坐标
		rec->set_fill_color(i % 2 == 0 ? Color::red : Color::white); // 红白相间
		recs.push_back(rec);
		win.attach(*recs.back());
	}
	win.wait_for_button();
	return 0;
}