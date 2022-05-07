#include <inventory-sink.hpp>
#include <logger.hpp>

using namespace std::chrono_literals;

InventorySink::InventorySink(GoodsType target)
    : target_{target}, sink_time{1s}, Node{NodeType::kSink, 1, 0} {}

NodeStatus InventorySink::simulate(std::chrono::milliseconds dt) {
  logger(LogLevel::kDebug) << "simulating inventory sink " << get_id() << "\n";
  return NodeStatus::kOk;
}
