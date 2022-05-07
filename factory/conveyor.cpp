#include <conveyor.hpp>
#include <logger.hpp>

NodeStatus Conveyor::simulate(std::chrono::milliseconds dt) {
  logger(LogLevel::kDebug) << "simulating conveyor " << get_id() << "\n";
  return NodeStatus::kOk;
}
