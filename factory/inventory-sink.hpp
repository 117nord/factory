#ifndef INVENTORY_SINK_HPP_INCLUDED
#define INVENTORY_SINK_HPP_INCLUDED

#include <goods.hpp>
#include <node.hpp>

// One sink can only consume one type of goods.
// If target is not set, it will be set to the first good that comes in.
class InventorySink : public Node {
 public:
  InventorySink(GoodsType target = GoodsType::kUndefined)
      : target_{target}, Node{NodeType::kSink, 1, 0} {}
  NodeStatus simulate(std::chrono::milliseconds dt) override;

 private:
  GoodsType target_;
};

#endif