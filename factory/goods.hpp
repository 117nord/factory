#ifndef GOODS_HPP_INCLUDED
#define GOODS_HPP_INCLUDED

enum class GoodsType { kUndefined, kCarbon, kIronOre };

class Goods {
 public:
  static const int kDefaultTemp = 20;

  Goods() : type_{GoodsType::kUndefined}, temperature_{kDefaultTemp} {};
  Goods(const GoodsType type, int temperature = kDefaultTemp)
      : type_{type}, temperature_{temperature} {};

 private:
  const GoodsType type_;
  int temperature_;
};

#endif