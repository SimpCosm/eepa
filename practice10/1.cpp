
#include <iostream>
#include <string>

#include "GUI.h"
#include "Graph.h"
#include "Simple_window.h"
#include "Window.h"

class StripedRectangle {
 public:
  StripedRectangle(Point xy, int w, int h, int interval)
      : rec_(xy, w, h), lines_(h / interval - 1) {
    int line_num = h / interval;
    int base_y = h % interval / 2 + interval;
    for (int i = 0; i < line_num; ++i) {
      lines_[i] = new Line({xy.x + 1, xy.y + i * interval + base_y},
                           {xy.x + w - 1, xy.y + i * interval + base_y});
    }
  }
  ~StripedRectangle() {
    while (!lines_.empty()) {
      delete lines_.back();
      lines_.pop_back();
    }
  }

  void Attach(Graph_lib::Window& win) {
    win.attach(rec_);
    for (int i = 0; i < (int)lines_.size(); ++i)
      win.attach(reference_to<Line>(lines_[i]));
  }

 private:
  Rectangle rec_;
  vector<Line*> lines_;
};

int main() {
  Simple_window win({0, 0}, 800, 600, "10-1");
  StripedRectangle rec({100, 100}, 500, 400, 31);
  rec.Attach(win);
  win.wait_for_button();
  return 0;
}
