#include "digraph.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>

/****************************** NODE FUNCTIONS ******************************/
Node::Node() {
  this->name = "NAME";
  this->label = "LABEL";
}

Node::Node(std::string name) {
  this->name = name;
  this->label = name;
}

Node::Node(std::string name, std::string label) {
  this->name = name;
  this->label = label;
}

void Node::updateLabel(std::string newLabel) 
  { this->label = newLabel; }

bool Node::operator==(const Node& rhs) 
  { return !(this->name).compare(rhs.name); } 
/****************************************************************************/

/****************************** EDGE FUNCTIONS ******************************/
Edge::Edge() {
  this->head = (Node *) NULL;
  this->tail = (Node *) NULL;
}

Edge::Edge(Node *head, Node *tail) {
  this->head = head;
  this->tail = tail;

  u_int32_t strSize = (head->name).size() + (tail->name).size() + 8;
  char tmp[strSize];
  sprintf(tmp, "\"%s\" -> \"%s\"", (head->name).c_str(), (tail->name).c_str());
  this->str = std::string(tmp);
}

bool Edge::operator==(const Edge& rhs) {
  bool headsMatch = (this->head) == (rhs.head);
  bool tailsMatch = (this->tail) == (rhs.tail);
  return headsMatch && tailsMatch;
} 
/****************************************************************************/

/***************************** GRAPH FUNCTIONS ******************************/
Graph::Graph() {
  this->name = "GRAPHNAME";
  this->nodes = std::vector<Node>();
  this->edges = std::vector<Edge>();
}

Graph::Graph(std::string graphName) {
  this->name = graphName;
  this->nodes = std::vector<Node>();
  this->edges = std::vector<Edge>();
}

void Graph::addNode(Node node) {
  if( !(this->contains(node)) )
    { (this->nodes).push_back(node); }
}

void Graph::addEdge(Edge edge) {
  if( !(this->contains(edge)) ) {
    if( (this->contains(*(edge.head))) &&  (this->contains(*(edge.tail))) )
      { (this->edges).push_back(edge); }
  }
}

bool Graph::contains(Node node) {
  std::vector<Node>::iterator it;
  it = std::find((this->nodes).begin(), (this->nodes).end(), node);
  return (it != (this->nodes).end());
}

bool Graph::contains(Edge edge) {
  std::vector<Edge>::iterator it;
  it = std::find((this->edges).begin(), (this->edges).end(), edge);
  return (it != (this->edges).end());
}

void Graph::dumpToFile(std::string fileName) {
  std::ofstream outfile;
  outfile.open(fileName);
  std::cout << "--------------------------------------------" << std::endl;
  std::cout << "GENERATING DIGRAPH:" << std::endl;
  std::cout << "\t- Graph Name: " << this->name << std::endl;
  std::cout << "\t\t- Nodes: " << ((this->nodes).size()) << std::endl;
  std::cout << "\t\t- Edges: " << ((this->edges).size()) << std::endl;

  outfile << "digraph \"" << (this->name) << "\" {" << std::endl;
  for( u_int32_t i = 0; i < ((this->nodes).size()); i++ ) {
    outfile << "\t\"" << nodes[i].name << "\"";
    outfile << "\t[label = \"" << nodes[i].label << "\"]";
    outfile << std::endl;
  }
  outfile << std::endl;
  for( u_int32_t i = 0; i < ((this->edges).size()); i++ )
    { outfile << "\t" << edges[i].str << std::endl; }  
  
  outfile << "}";
  outfile.close();
  std::cout << "\t\t- FileName: " << fileName << std::endl;
  std::cout << "--------------------------------------------" << std::endl;

}
/***************************************************************************/
