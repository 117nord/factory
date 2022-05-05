#include <system.hpp>

// The system takes ownership of the node.
void System::add_node(std::unique_ptr<Node> node) {
  nodes_.emplace_back(std::move(node));
}

SystemStatus System::simulate(std::chrono::milliseconds dt) {
  for (auto& p : nodes_) {
    p->simulate(dt);
  }
  return SystemStatus::kOk;
}

#ifndef NDEBUG
void System::log_all_nodes() const {
  for (const auto& p : nodes_) {
    p->debug_log();
  };
}
#endif
