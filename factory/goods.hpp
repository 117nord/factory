#ifndef GOODS_HPP_INCLUDED
#define GOODS_HPP_INCLUDED

enum class GoodsType { kUndefined, kCarbon, kIronOre };

class Goods {
 public:
  // TODO: default temp is not a characteristic of goods, but of the environment
  // where the good is. An inventory source should produce goods at the
  // temperature of the inventory storage.
  static const int kDefaultTemp = 20;

  Goods() : type_{GoodsType::kUndefined}, temperature_{kDefaultTemp} {};
  Goods(const GoodsType type, int temperature = kDefaultTemp)
      : type_{type}, temperature_{temperature} {};
  GoodsType get_type() const { return type_; };
  void set_type(GoodsType type) { type_ = type; };

 private:
  GoodsType type_;

  int temperature_;
};

#endif