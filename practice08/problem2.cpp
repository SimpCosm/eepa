#include <tchar.h>
#include <vector>
#include "Simple_window.h"
#include "Graph.h"
using namespace std;
using namespace Graph_lib;

int _tmain(int argc, _TCHAR* argv[]) {
	int baseX = 200;
	int baseY = 200;
	// 参考系原点的绝对坐标
	Simple_window win(Point(200, 200), 600, 400, "Test");
	// 墙体
	Graph_lib::Rectangle wall(Point(baseX, baseY), 200, 175);
	wall.set_fill_color(Color::white);
	// 门
	Graph_lib::Rectangle door(Point(baseX + 75, baseY + 75), 50, 100);
	door.set_fill_color(Color::red);
	// 两扇窗子
	Graph_lib::Rectangle windowLeft(Point(baseX + 22, baseY + 30), 40, 40);
	windowLeft.set_fill_color(Color::black);
	Graph_lib::Rectangle windowRight(Point(baseX + 138, baseY + 30), 40, 40);
	windowRight.set_fill_color(Color::black);
	// 屋顶
	Closed_polyline roof;
	roof.add(Point(baseX - 40, baseY));
	roof.add(Point(baseX + 240, baseY));
	roof.add(Point(baseX + 100, baseY - 150));
	roof.set_fill_color(Color::dark_blue);
	// 烟囱
	Graph_lib::Rectangle chimney(Point(baseX + 160, baseY - 140), 40, 100);
	chimney.set_fill_color(Color::black);
	// 三个烟圈
	vector<Circle*> smokes;
	vector<vector<int>> smokeDescs = { {190, -160, 20}, {200, -175, 30}, {205, -180, 30} }; // X坐标，Y坐标，半径
	for (vector<int> smokeDesc : smokeDescs) {
		Circle* smoke = new Circle(Point(baseX + smokeDesc[0], baseY + smokeDesc[1]), smokeDesc[2]);
		smoke->set_color(Color::black);
		smokes.push_back(smoke);
	}

	// 把他们全都attach上
	win.attach(wall);
	win.attach(door);
	win.attach(windowLeft);
	win.attach(windowRight);
	win.attach(chimney);
	win.attach(roof);
	for (Circle* smoke : smokes)
		win.attach(*smoke);
	win.wait_for_button();
	return 0;

}