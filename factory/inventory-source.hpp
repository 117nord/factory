#ifndef INVENTORY_SOURCE_HPP_INCLUDED
#define INVENTORY_SOURCE_HPP_INCLUDED

#include <goods.hpp>
#include <node.hpp>

class InventorySource : public Node {
 public:
  InventorySource(GoodsType target)
      : target_{target}, Node{NodeType::kSource, 0, 1} {}
  NodeStatus simulate(std::chrono::milliseconds dt) override;

 private:
  GoodsType target_;
};

#endif