#include <inventory-source.hpp>
#include <logger.hpp>

NodeStatus InventorySource::simulate(std::chrono::milliseconds dt) {
  logger(LogLevel::kDebug) << "simulating inventory source " << id_ << "\n";
  return NodeStatus::kOk;
}
