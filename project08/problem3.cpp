#include <tchar.h>
#include <vector>
#include "Simple_window.h"
#include "Graph.h"
using namespace std;
using namespace Graph_lib;

int _tmain(int argc, _TCHAR* argv[]) {
	int baseX = 200;
	int baseY = 150; // 参考系原点的绝对坐标
	int radius = 46; // 半径
	int width = 4; // 线宽
	Simple_window win(Point(200, 200), 600, 400, "Test");
	vector<vector<int>> circleLocations = { {0, 0}, {100, 0}, {200, 0}, {50, 50}, {150, 50} }; // 5个圈圈的相对坐标
	vector<Color> colors = {Color::blue, Color::black, Color::red, Color::yellow, Color::green}; // 5个圈圈的颜色
	vector<Circle*> circles;
	for (int i = 0; i < 5; i++) {
		Circle* cir = new Circle(Point(baseX + circleLocations[i][0], baseY + circleLocations[i][1]), radius);
		cir->set_color(colors[i]);
		cir->set_style(Line_style(Line_style::solid, width));
		circles.push_back(cir);
	}
	for (Circle* cir : circles)
		win.attach(*cir);
	win.wait_for_button();
	return 0;
}