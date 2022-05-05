#include <conveyor.hpp>
#include <inventory-sink.hpp>
#include <inventory-source.hpp>
#include <memory>
#include <system.hpp>

int main() {
  using namespace std::chrono_literals;
  System system{};
  std::unique_ptr<Node> source =
      std::make_unique<InventorySource>(GoodsType::kIronOre);
  std::unique_ptr<Node> conveyor = std::make_unique<Conveyor>();
  std::unique_ptr<Node> sink = std::make_unique<InventorySink>();

  connect(*source, 0, *conveyor, 0);
  connect(*conveyor, 0, *sink, 0);

  system.add_node(std::move(source));
  system.add_node(std::move(conveyor));
  system.add_node(std::move(sink));

  system.log_all_nodes();
  system.simulate(1000ms);
}
