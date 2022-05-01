#include <conveyor.hpp>
#include <inventory-sink.hpp>
#include <inventory-source.hpp>

int main() {
  using namespace std::chrono_literals;
  InventorySource source{GoodsType::kIronOre};
  Conveyor conveyor{};
  InventorySink sink{};

  connect(source, 0, conveyor, 0);
  connect(conveyor, 0, sink, 0);

  source.simulate(1000ms);
  conveyor.simulate(1000ms);
  sink.simulate(1000ms);
}
