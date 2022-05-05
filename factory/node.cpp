#include <algorithm>
#include <functional>
#include <logger.hpp>
#include <node.hpp>

std::vector<Node*> Node::nodes_{};

Node::Node(NodeType type, std::size_t nb_inputs,
           std::size_t nb_outputs /* simulation function parameter */)
    : id_{nodes_.size()}, type_{type}, inputs_{}, outputs_{} {
  logger(LogLevel::kDebug) << "Creating node id " << id_ << "\n";

  inputs_.reserve(nb_inputs);
  for (int i = 0; i < nb_inputs; i++) {
    inputs_.emplace_back(this);
  }

  outputs_.reserve(nb_outputs);
  for (int i = 0; i < nb_outputs; i++) {
    outputs_.emplace_back(this);
  }

  nodes_.emplace_back(this);
}

#ifndef NDEBUG
void Node::debug_log() const {
  std::ostream& ostream = logger(LogLevel::kDebug);
  ostream << "Node " << id_ << ", type: " << static_cast<int>(type_) << "\n";
  std::for_each(inputs_.cbegin(), inputs_.cend(),
                [](const InputPort& p) { p.debug_log(); });
  std::for_each(outputs_.cbegin(), outputs_.cend(),
                [](const OutputPort& p) { p.debug_log(); });
}

void Node::log_all_nodes() {
  std::for_each(nodes_.cbegin(), nodes_.cend(),
                [](const Node* p) { p->debug_log(); });
}
#endif

bool connect(Node* src_node, int src_port_idx, Node* dst_node,
             int dst_port_idx) {
  src_node->outputs_[src_port_idx].connect_to(dst_node,
                                              dst_node->inputs_[dst_port_idx]);
  dst_node->inputs_[dst_port_idx].connect_from(
      src_node, src_node->outputs_[src_port_idx]);

  return true;
}
