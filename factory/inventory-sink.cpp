#include <inventory-sink.hpp>
#include <logger.hpp>

NodeStatus InventorySink::simulate(std::chrono::milliseconds dt) {
  logger(LogLevel::kDebug) << "simulating inventory sink " << id_ << "\n";
  return NodeStatus::kOk;
}
