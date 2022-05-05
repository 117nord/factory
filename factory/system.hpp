#ifndef SYSTEM_HPP_INCLUDED
#define SYSTEM_HPP_INCLUDED

#include <chrono>
#include <memory>
#include <node.hpp>
#include <vector>

enum class SystemStatus { kOk, kWarning, kError };

class System {
 public:
  System() = default;
  void add_node(std::unique_ptr<Node> node);
  SystemStatus simulate(std::chrono::milliseconds dt);

#ifndef NDEBUG
  void log_all_nodes() const;
#endif

 private:
  std::vector<std::unique_ptr<Node>> nodes_;
};

#endif