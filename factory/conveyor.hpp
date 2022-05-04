#ifndef CONVEYOR_HPP_INCLUDED
#define CONVEYOR_HPP_INCLUDED

#include <goods.hpp>
#include <node.hpp>
#include <vector>

class Conveyor : public Node {
 public:
  static constexpr float kLength{5.0};        // length in meters
  static constexpr float kDefaultSpeed{1.0};  // speed in meters/second

  Conveyor(float speed = kDefaultSpeed)
      : speed_{speed}, Node{NodeType::kTransform, 1, 1} {}

  NodeStatus simulate(std::chrono::milliseconds dt) override;

 private:
  float speed_;
};

#endif