#ifndef NODE_HPP_INCLUDED
#define NODE_HPP_INCLUDED

#include <chrono>
#include <port.hpp>
#include <vector>

enum class NodeType { kSource, kTransform, kSink };
enum class NodeStatus { kOk, kStarved, kJammed, kError };

class Node {
 public:
  Node() = delete;
  Node(const Node&) = delete;
  Node(Node&&) = default;
  Node& operator=(Node&) = delete;

  Node(NodeType type, std::size_t nb_inputs,
       std::size_t nb_outputs /* simulation function parameter */);
  virtual ~Node() = default;
  int get_id() const { return id_; };
  NodeType get_type() const { return type_; };

  // TODO: I don't know yet what return type I need here.
  // The return value must help figure out when the whole system is stable, e.g.
  // when the simulation is complete. I have a feeling that I will need multiple
  // pass unless I can figure out an order of node simulation that equalizes in
  // one pass.
  // For now, just returning a status for the node.
  virtual NodeStatus simulate(std::chrono::milliseconds dt) = 0;

#ifndef NDEBUG
  void debug_log() const;
#endif

  // Connects the ports in both direction.
  friend bool connect(Node& src_node, int src_port_idx, Node& dst_node,
                      int dst_port_idx);

 protected:
  std::vector<InputPort> inputs_;
  std::vector<OutputPort> outputs_;
  std::vector<Goods> content_;

 private:
  static std::size_t last_id;
  std::size_t id_;  // const
  NodeType type_;   // const
};

#endif