#include <conveyor.hpp>
#include <inventory-sink.hpp>
#include <inventory-source.hpp>

int main() {
  using namespace std::chrono_literals;
  InventorySource source{GoodsType::kIronOre};
  Conveyor conveyor{};
  InventorySink sink{};

  source.connect_to(conveyor);
  conveyor.connect_to(sink);

  source.simulate(1000ms);
  conveyor.simulate(1000ms);
  sink.simulate(1000ms);
}
