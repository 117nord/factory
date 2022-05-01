#include <chrono>
#include <port.hpp>
#include <vector>

enum class NodeType { kSource, kTransform, kSink };
enum class NodeStatus { kOk, kStarved, kJammed, kError };

class Node {
 public:
  Node() = delete;
  Node(NodeType type, int nb_inputs,
       int nb_outputs /* simulation function parameter */);
  virtual ~Node() = default;

  // TODO: I don't know yet what return type I need here.
  // The return value must help figure out when the whole system is stable, e.g.
  // when the simulation is complete. I have a feeling that I will need multiple
  // pass unless I can figure out an order of node simulation that equalizes in
  // one pass.
  // For now, just returning a status for the node.
  virtual NodeStatus simulate(std::chrono::milliseconds dt) = 0;

 protected:
  int id_;
  const NodeType type_;
  std::vector<InputPort> inputs_;
  std::vector<OutputPort> outputs_;
  std::vector<Goods> content_;

 private:
  static int last_id;
};