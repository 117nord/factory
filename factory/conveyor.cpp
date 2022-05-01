#include <conveyor.hpp>
#include <logger.hpp>

NodeStatus Conveyor::simulate(std::chrono::milliseconds dt) {
  logger(LogLevel::kDebug) << "simulating conveyor " << id_ << "\n";
  return NodeStatus::kOk;
}
