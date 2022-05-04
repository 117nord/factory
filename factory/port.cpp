#include <logger.hpp>
#include <node.hpp>
#include <port.hpp>

bool OutputPort::connect_to(Node& dst, InputPort& port) {
  disconnect();
  connected_node_ = &dst;
  port_ = &port;

  return true;
};

void OutputPort::disconnect() {
  if (connected_node_) {
    assert((connected_node_ == port_->connected_node_) &&
           "connections need to be bidirectional");
  }
  Port::disconnect();
  if (port_) {
    port_->connected_node_ = nullptr;
    port_->port_ = nullptr;
    port_ = nullptr;
  }
};

#ifndef NDEBUG
void OutputPort::debug_log() const {
  std::ostream& ostream = logger(LogLevel::kDebug);
  ostream << "Output port of node " << owner_.get_id() << " connected to node "
          << connected_node_->get_id() << "\n";
}
#endif

void InputPort::disconnect() {
  Port::disconnect();
  if (port_) {
    port_->connected_node_ = nullptr;
    port_->port_ = nullptr;
    port_ = nullptr;
  }
};

bool InputPort::connect_from(Node& src, OutputPort& port) {
  disconnect();
  connected_node_ = &src;
  port_ = &port;
  return true;
}

#ifndef NDEBUG
void InputPort::debug_log() const {
  std::ostream& ostream = logger(LogLevel::kDebug);
  ostream << "Input port of node " << owner_.get_id() << " connected to node "
          << connected_node_->get_id() << "\n";
}
#endif
