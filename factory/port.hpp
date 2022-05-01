#include <cassert>
#include <goods.hpp>

class Node;

class Port {
 public:
  Port() = delete;
  Port(Port& p) = delete;
  Port(Port&& p) = delete;

  Port(Node& owner) : owner_{owner}, connected_node_{nullptr} {};

  virtual void disconnect() { connected_node_ = nullptr; };

 protected:
  Node& owner_;
  Node* connected_node_;
};

class OutputPort : public Port {
  friend class InputPort;

 public:
  OutputPort() = delete;
  OutputPort(OutputPort& p) = delete;
  OutputPort(OutputPort&& p) = delete;

  OutputPort(Node& owner) : Port{owner}, port_{nullptr} {};
  bool connect_to(Node& dst, int port_idx);
  void disconnect() override {
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
  bool Put(Goods thing);

 private:
  InputPort* port_;
};

class InputPort : public Port {
  friend class OutputPort;

 public:
  InputPort() = delete;
  InputPort(InputPort& p) = delete;
  InputPort(InputPort&& p) = delete;

  InputPort(Node& owner) : Port{owner}, port_{nullptr} {};

  void disconnect() override {
    Port::disconnect();
    if (port_) {
      port_->connected_node_ = nullptr;
      port_->port_ = nullptr;
      port_ = nullptr;
    }
  };
  bool Take(Goods thing);

 private:
  OutputPort* port_;
};