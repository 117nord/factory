#ifndef PORT_HPP_INCLUDED
#define PORT_HPP_INCLUDED

#include <cassert>
#include <goods.hpp>

class Node;

class Port {
 public:
  Port() = delete;
  Port(Port& p) = delete;
  Port(Port&& p) = default;

  Port(Node* owner) : owner_{owner}, connected_node_{nullptr} {};

  virtual void disconnect() { connected_node_ = nullptr; };

 protected:
  Node* owner_;
  Node* connected_node_;
};

class InputPort;

class OutputPort : public Port {
  friend class InputPort;

 public:
  OutputPort() = delete;
  OutputPort(OutputPort& p) = delete;
  OutputPort(OutputPort&& p) = default;

  OutputPort(Node* owner) : Port{owner}, port_{nullptr} {};
  bool connect_to(Node* dst, InputPort& port);
  void disconnect() override;
  bool Put(Goods thing);
#ifndef NDEBUG
  void debug_log() const;
#endif

 private:
  InputPort* port_;
};

class InputPort : public Port {
  friend class OutputPort;

 public:
  InputPort() = delete;
  InputPort(InputPort& p) = delete;
  InputPort(InputPort&& p) = default;

  InputPort(Node* owner) : Port{owner}, port_{nullptr} {};

  bool connect_from(Node* src, OutputPort& port);
  void disconnect() override;
  bool Take(Goods thing);
#ifndef NDEBUG
  void debug_log() const;
#endif
 private:
  OutputPort* port_;
};

#endif