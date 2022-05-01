#include <goods.hpp>

class Node;

class Port {
 protected:
  Node& owner_;
  Node* connected_node_;
};

class OutputPort : Port {
 public:
  bool Put(Goods thing);

 private:
  InputPort* port_;
};

class InputPort : Port {
 public:
  bool Take(Goods thing);

 private:
  OutputPort* port_;
};