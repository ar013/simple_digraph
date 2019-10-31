#ifndef SIMPLE_DIGRAPH
#define SIMPLE_DIGRAPH

/***********************************************/
/***       Author: Andres Rodriguez II       ***/
/***              Version: 1.0               ***/
/***********************************************/

#include <string>
#include <vector>

struct Node {
  Node();
  Node(std::string name);
  Node(std::string name, std::string label);

  void updateLabel(std::string newLabel);
  bool operator==(const Node& rhs);

  std::string name;
  std::string label;  
};

struct Edge {
  Edge();
  Edge(Node *head, Node *tail);

  bool operator==(const Edge& rhs);

  Node *head;
  Node *tail;
  std::string str;
};

class Graph {
  public: 
    Graph();
    Graph(std::string graphName);

    void addNode(Node node);
    void addEdge(Edge edge);
    bool contains(Node node);
    bool contains(Edge edge);
    void dumpToFile(std::string fileName);

  private:
    std::string name;
    std::vector<Node> nodes; /* NODES IN GRAPH */
    std::vector<Edge> edges; /* EDGES IN GRAPH */
};

#endif
