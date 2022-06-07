#include <functional>
#include <logger.hpp>
#include <node.hpp>

std::size_t Node::last_id{0};

Node::Node(NodeType type, std::size_t nb_inputs,
           std::size_t nb_outputs /* simulation function parameter */)
    : id_{last_id++}, type_{type}, inputs_{}, outputs_{} {
  logger(LogLevel::kDebug) << "Creating node id " << id_ << "\n";

  inputs_.reserve(nb_inputs);
  for (int i = 0; i < nb_inputs; i++) {
    inputs_.emplace_back(this);
  }

  outputs_.reserve(nb_outputs);
  for (int i = 0; i < nb_outputs; i++) {
    outputs_.emplace_back(this);
  }
}

#ifndef NDEBUG
void Node::debug_log() const {
  std::ostream& ostream = logger(LogLevel::kDebug);
  ostream << "Node " << id_ << ", type: " << static_cast<int>(type_) << "\n";
  for (const InputPort& port : inputs_) {
    port.debug_log();
  };
  for (const OutputPort& port : outputs_) {
    port.debug_log();
  };
}
#endif

bool connect(Node& src_node, int src_port_idx, Node& dst_node,
             int dst_port_idx) {
  logger(LogLevel::kDebug) << "Connecting node " << src_node.get_id()
                           << " to node " << dst_node.get_id() << std::endl;

  src_node.outputs_[src_port_idx].connect_to(&dst_node,
                                             dst_node.inputs_[dst_port_idx]);
  dst_node.inputs_[dst_port_idx].connect_from(&src_node,
                                              src_node.outputs_[src_port_idx]);

  return true;
}
