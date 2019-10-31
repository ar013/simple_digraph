# A simple C++ directed graph library

See [here](https://en.wikipedia.org/wiki/Directed_graph) for a description of directed graphs

This library is meant to provide an interface to generate simple directed graphs. It allows for adding nodes and edges, as well as updating node labels. Once the graph is created with all nodes and edges, just call the 'dumpToFile()' method on the graph object with the desired filename and an output file in the following format will be created:

'''
digraph "GRAPH NAME" {
	"n1"	[label = "n1"]
	"n2"	[label = "n2"]
	"n3"	[label = "n3"]
	"n4"	[label = "n4"]
	"n5"	[label = "n5"]

	"n1" -> "n2"
	"n2" -> "n3"
	"n2" -> "n4"
	"n4" -> "n1"
	"n3" -> "n5"
}
'''

### Generating graph from output file:

To generate graphs from an output file, you will need to have graphviz installed. Once installed you can generate a graph into either a PDF or PNG file using the 'dot' command. For example, the command to generate a graph into a PNG named graph.png from an output file named output.dot is:

'''
	dot -Tpng output.dot -o graph.png
'''

Here is an example of a directed graph generated from the above output file:
![Example directed graph](example/graph.png?raw=true "Example directed graph")
