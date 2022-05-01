#include <goods.hpp>
#include <node.hpp>
#include <vector>

class Conveyor : public Node {
 public:
  static const float kLength{5.0};        // length in meters
  static const float kDefaultSpeed{1.0};  // speed in meters/second

  Conveyor(float speed = kDefaultSpeed)
      : speed_{speed}, Node{NodeType::kTransform, 1, 1} {}

  NodeStatus simulate(std::chrono::milliseconds dt) override;

 private:
  float speed_;
};
