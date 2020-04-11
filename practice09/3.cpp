
#include <iostream>
#include <string>

#include "GUI.h"
#include "Graph.h"
#include "Simple_window.h"
#include "Window.h"

int main() {
  Simple_window win({0, 0}, 800, 600, "09-3");
  const int radius = 200;
  const int center_x = 400;
  const int center_y = 300;
  Circle c({center_x, center_y}, radius);
  c.set_color(Color::red);
  win.attach(c);
  Circle mark({400, 100}, 20);
  mark.set_fill_color(Color::black);
  win.attach(mark);
  int now_x = 400;
  int now_y = 100;
  int now_angle = 0;
  while (true) {
    win.wait_for_button();
    now_angle += 15;
    now_angle %= 360;
    /**
     * sin and cos use value in radians not degree
     */
    int next_x =
        double(radius) * sin((double)now_angle * M_PI / 180) + (double)center_x;
    int next_y = -double(radius) * cos((double)now_angle * M_PI / 180) +
                 (double)center_y;
    mark.move(next_x - now_x, next_y - now_y);
    now_x = next_x;
    now_y = next_y;
  }
  return 0;
}
