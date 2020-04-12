
#include <iostream>
#include <string>

#include "GUI.h"
#include "Graph.h"
#include "Simple_window.h"
#include "Window.h"

struct BinaryNode {
  Shape* shape_;
  Line* line_;
  Text* text_;
  Point point_;
  BinaryNode(Shape* shape = nullptr, Line* line = nullptr, Point point = {0, 0})
      : shape_(shape), line_(line), point_(point), text_(nullptr) {}
};

class BinaryTree {
 public:
  BinaryTree(Point top, unsigned level_num, Line_style style);
  virtual ~BinaryTree();
  void Draw();
  void Attach(Graph_lib::Window& win);
  int GetLevel() const { return level_num_; }
  Point GetTop() const { return top_; }
  void SetText(unsigned node_index, const string& str);

  static const int kHeightInterval_ = 50;
  static const int kWidthInterval_ = 50;
  static const int kNodeSize_ = 20;
  static const int kFontSize = 10;

 protected:
  virtual Shape* CreateNode(Point center_point);
  vector<BinaryNode> nodes_;

 private:
  Graph_lib::Window* win_;
  unsigned level_num_;
  Point top_;
  Line_style line_style_;
};

BinaryTree::BinaryTree(Point top, unsigned level_num, Line_style style)
    : top_(top),
      level_num_(level_num),
      line_style_(style),
      nodes_((1 << level_num) - 1),
      win_(nullptr) {}

void BinaryTree::Draw() {
  int index = 1;
  nodes_[0].shape_ = CreateNode(top_);
  nodes_[0].point_ = top_;
  nodes_[0].line_ = nullptr;
  for (int level = 1; level < level_num_; ++level) {
    int node_num = 1 << level;
    int interval =
        (1 << (level_num_ - level - 1)) * BinaryTree::kWidthInterval_;
    int y = top_.y + BinaryTree::kHeightInterval_ * level;
    int x = top_.x - interval * (node_num - 1) / 2;
    for (int node = 0; node < node_num; ++node) {
      int parent = ((index + 1) >> 1) - 1;
      nodes_[index].point_ = {x, y};
      if (index != 0) {
        nodes_[index].line_ =
            new Line(nodes_[parent].point_, nodes_[index].point_);
        nodes_[index].line_->set_style(line_style_);
      }
      nodes_[index].shape_ = CreateNode(nodes_[index].point_);
      x += interval;
      index++;
    }
  }
}

Shape* BinaryTree::CreateNode(Point center) {
  Circle* shape = new Circle(center, BinaryTree::kNodeSize_);
  shape->set_fill_color(Color::yellow);
  return shape;
}

void BinaryTree::Attach(Graph_lib::Window& win) {
  win_ = &win;
  for (int i = 1; i < nodes_.size(); ++i)
    win.attach(reference_to<Line>(nodes_[i].line_));
  for (int i = 0; i < nodes_.size(); ++i) {
    win.attach(reference_to<Shape>(nodes_[i].shape_));
    if (nodes_[i].text_) win.attach(reference_to<Text>(nodes_[i].text_));
  }
}

BinaryTree::~BinaryTree() {
  while (!nodes_.empty()) {
    delete nodes_.back().shape_;
    delete nodes_.back().line_;
    delete nodes_.back().text_;
    nodes_.pop_back();
  }
}

void BinaryTree::SetText(unsigned node_index, const string& str) {
  if (node_index >= nodes_.size()) return;
  if (nodes_[node_index].text_) {
    if (win_) {
      win_->detach(*nodes_[node_index].text_);
    }
    delete nodes_[node_index].text_;
    nodes_[node_index].text_ = nullptr;
  }
  int x =
      nodes_[node_index].point_.x - str.length() * BinaryTree::kFontSize / 4;
  int y = nodes_[node_index].point_.y + BinaryTree::kFontSize / 2;
  nodes_[node_index].text_ = new Text({x, y}, str);
  nodes_[node_index].text_->set_font_size(BinaryTree::kFontSize);
  if (win_) {
    win_->attach(reference_to<Line>(nodes_[node_index].text_));
    win_->redraw();
  }
}

class TriangleBinaryTree : public BinaryTree {
 public:
  TriangleBinaryTree(Point top, unsigned level, Line_style style)
      : BinaryTree(top, level, style) {}

 protected:
  Shape* CreateNode(Point xy) override;
};

Shape* TriangleBinaryTree::CreateNode(Point xy) {
  Polygon* shape = new Polygon();
  shape->add({xy.x, xy.y - BinaryTree::kNodeSize_});
  shape->add({xy.x - BinaryTree::kNodeSize_, xy.y + BinaryTree::kNodeSize_});
  shape->add({xy.x + BinaryTree::kNodeSize_, xy.y + BinaryTree::kNodeSize_});
  shape->set_fill_color(Color::green);
  return shape;
}

int main() {
  Simple_window win({0, 0}, 800, 600, "Binary tree");
  TriangleBinaryTree tree({400, 50}, 5, Line_style::solid);
  tree.Draw();
  for (int i = 0; i < (1 << 5) - 1; ++i) {
    tree.SetText(i, to_string(i));
  }
  tree.Attach(win);
  win.wait_for_button();
  for (int i = 0; i < (1 << 5) - 1; ++i) {
    tree.SetText(i, to_string(i + 1));
  }
  win.wait_for_button();
  return 0;
}
