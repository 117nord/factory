#include <inventory-source.hpp>
#include <logger.hpp>

using namespace std::chrono_literals;

InventorySource::InventorySource(GoodsType product)
    : src_type_{product},
      production_time_{1s},
      Node{NodeType::kSource, 0, 1} {};

NodeStatus InventorySource::simulate(std::chrono::milliseconds dt) {
  logger(LogLevel::kDebug) << "simulating inventory source " << get_id()
                           << "\n";
  return NodeStatus::kOk;
}
