#include <logger.hpp>
#include <node.hpp>

int Node::last_id = 0;

Node::Node(NodeType type, int nb_inputs,
           int nb_outputs /* simulation function parameter */)
    : id_{last_id++}, type_{type}, inputs_{nb_inputs}, outputs_{nb_outputs} {
  logger(LogLevel::kDebug) << "Creating node id " << id_ << "\n";
}

bool connect(Node& src_node, int src_port_idx, Node& dst_node,
             int dst_port_idx) {
  src_node.outputs_[src_port_idx]
}
