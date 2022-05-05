# factory
Exploration of a product transformation system.

# wip

# todo

1. Node is the basic construction block of the system but I need multiple "types" of nodes: conveyors, smelters, inventory_source, inventory_sink, ...
Each "type" of node has different characteristics (number of I/O and simulation function).
I will need multiple instances of each type. 
I doń't want to use a class hierarchy for this because there will be too much boiler plate code to write.
The "type" of node determines all the node member variable.
  - It's a construction schema.
  - It also determines the visual aspects.
  - And the simulation code.

I can use a Schema class and create an instance of schema for each "type" using a function pointer for the simulation function.
But the simulation function can't access the Node's member variables.
=> It can if it is a friend function but the Node class must know all simulation functions.

Maybe I can use the Barton-Nackman trick to have the template declare the fucntion as a friend or something? https://h-deb.clg.qc.ca/Sujets/Divers--cplusplus/Truc-Barton-Nackman.html

Let's start with a class hierarchy, it may not be that bad in terms of boiler plate and it will be simple.

# done

- Now using a node pointer vector in the node class to store nodes.
  - Because using base class pointers is the only way to store polymorphic objects in a vector.
- It is like a single, global factory.
- using pointers as node references.