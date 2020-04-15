
#include <iostream>
#include <string>

#include "GUI.h"
#include "Graph.h"
#include "Simple_window.h"
#include "Window.h"

class Box {
 public:
  /*Delete all unnecessary constructors*/
  Box() = delete;
  Box(const Box &) = delete;
  Box &operator=(const Box &) = delete;

  /**
   * @brief Construct a new Box object
   *
   * @param x up left corner
   * @param y low right corner
   * @param r radius of pie
   */
  Box(Point x, Point y, int r);

  /**
   * @brief Attach element of Box to window
   *
   * @param win the reference to window want to attach
   */
  void Attach(Graph_lib::Window &win);

  /**
   * @brief Set the color of edge
   *
   * @param c Color
   */
  void SetColor(Color c);

  /**
   * @brief Set the Fill Color
   *
   * @param c Color
   */
  void SetFillColor(Color c);

  /**
   * @brief Set the line style
   *
   * @param s Line style
   */
  void SetStyle(Line_style s);

  /**
   * @brief Move the box
   *
   * @param dx the distance in x direction
   * @param dy the distance in y direction
   */
  void Move(int dx, int dy);

 private:
  Rectangle rec_w_; /*< Wider rectangle*/
  Rectangle rec_h_; /*< Higher rectangle*/
  Line line[4];     /* 4 edge of box*/
  Arc pie[4];       /* 4 corner*/
};

/*************************************************************************
 * Box's implement
 * ***********************************************************************/

Box::Box(Point x, Point y, int r)
    : rec_w_({x.x, x.y + r}, {y.x, y.y - r}),
      rec_h_({x.x + r, x.y}, {y.x - r, y.y}),
      line{{{x.x + r, x.y}, {y.x - r, x.y}},
           {{y.x, x.y + r}, {y.x, y.y - r}},
           {{x.x + r, y.y}, {y.x - r, y.y}},
           {{x.x, x.y + r}, {x.x, y.y - r}}},
      pie{{{x.x + r, x.y + r}, r, r, 90, 180},
          {{y.x - r, x.y + r}, r, r, 0, 90},
          {{y.x - r, y.y - r}, r, r, 270, 360},
          {{x.x + r, y.y - r}, r, r, 180, 270}} {
  rec_w_.set_color(Color::invisible);
  rec_h_.set_color(Color::invisible);
}

void Box::Attach(Graph_lib::Window &win) {
  win.attach(rec_w_);
  win.attach(rec_h_);
  for (int i = 0; i < 4; ++i) win.attach(pie[i]);
  for (int i = 0; i < 4; ++i) win.attach(line[i]);
}

void Box::SetColor(Color c) {
  for (int i = 0; i < 4; ++i) {
    pie[i].set_color(c);
    line[i].set_color(c);
  }
}

void Box::SetFillColor(Color c) {
  for (int i = 0; i < 4; ++i) pie[i].set_fill_color(c);
  rec_w_.set_fill_color(c);
  rec_h_.set_fill_color(c);
}

void Box::SetStyle(Line_style s) {
  for (int i = 0; i < 4; ++i) {
    pie[i].set_style(s);
    line[i].set_style(s);
  }
}

int main() {
  Simple_window win({0, 0}, 1000, 600, "test");

  const Color fill_color = Color::dark_green;

  vector<Rectangle *> recs;
  recs.push_back(new Rectangle({50, 100}, {200, 200}));  /*shape*/
  recs.push_back(new Rectangle({70, 400}, {220, 500}));  /*square*/
  recs.push_back(new Rectangle({780, 200}, {980, 400})); /*display_engine*/
  Box window({350, 250}, {600, 350}, 20);
  for (int i = 0; i < (int)recs.size(); ++i) {
    recs[i]->set_fill_color(fill_color);
    win.attach(reference_to<Rectangle>(recs[i]));
  }
  window.SetFillColor(fill_color);
  window.Attach(win);

  vector<Line *> lines;
  lines.push_back(new Line({200, 150}, {350, 300})); /* shape to window*/
  lines.push_back(new Line({220, 450}, {350, 300})); /* square to window*/
  lines.push_back(
      new Line({780, 300}, {600, 300})); /* display_engine to window*/
  for (int i = 0; i < (int)lines.size(); ++i) {
    win.attach(reference_to<Line>(lines[i]));
  }

  const int font_size = 20;
  const Point mid_points[] = {{125, 150}, {145, 450}, {880, 300}, {475, 300},
                              {290, 200}, {300, 400}, {700, 280}};
  const string words[] = {"Shape",    "Square",   "Display Engine", "Window",
                          "attach()", "attach()", "draw()"};
  vector<Text *> texts;
  for (int i = 0; i < sizeof(mid_points) / sizeof(Point); ++i) {
    const int word_length = (int)words[i].size();
    /**
     * Point in Text's constructor aligned to the left and baseline of the font.
     * Font size is approximate height of a font in pixels, and wight is
     * approximate half of height.
     */
    int dx = font_size * word_length / 4;
    int dy = font_size / 2;
    texts.push_back(
        new Text({mid_points[i].x - dx, mid_points[i].y + dy}, words[i]));
    texts[i]->set_font_size(font_size);
    win.attach(reference_to<Text>(texts[i]));
  }

  win.wait_for_button();
  for (int i = 0; i < (int)lines.size(); ++i) {
    delete lines[i];
    lines[i] = nullptr;
  }
  return 0;
}
