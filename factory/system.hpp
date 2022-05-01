#include <chrono>
#include <node.hpp>
#include <vector>

enum class SystemStatus { kOK, kWarning, kError };

class System {
 public:
  System() = default;
  bool add_node(Node node);
  SystemStatus simulate(std::chrono::milliseconds dt);

 private:
  // I want to minimize memory management so starting with node values instead
  // of pointers. But since node must point to each other, and vector elements
  // can change address, I can't use raw pointers in node "links", I will need
  // to use node indexes in the system node vector.
  // Not sure if I like this or not.
  std::vector<Node> nodes_;
};