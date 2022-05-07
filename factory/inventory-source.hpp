#ifndef INVENTORY_SOURCE_HPP_INCLUDED
#define INVENTORY_SOURCE_HPP_INCLUDED

#include <chrono>
#include <goods.hpp>
#include <node.hpp>

class InventorySource : public Node {
 public:
  InventorySource(GoodsType product);
  NodeStatus simulate(std::chrono::milliseconds dt) override;
  GoodsType get_src_type() const { return src_type_; };
  void set_src_type(GoodsType type) { src_type_ = type; };

 private:
  GoodsType src_type_;
  std::chrono::milliseconds production_time_;
};

#endif