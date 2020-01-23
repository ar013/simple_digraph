# A simple C++ directed graph library
###### (note: for a python implementation fo this library, see my other [repository](https://github.com/arodriguez-013/simple_digraph_py)
See [here](https://en.wikipedia.org/wiki/Directed_graph) for a description of directed graphs

This library is meant to provide an interface to generate simple directed graphs. It allows for adding nodes and edges, as well as updating node labels. Once the graph is created with all nodes and edges, just call the 'dumpToFile()' method on the graph object with the desired filename and an output file in the following format will be created:

```
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
```

### Generating graph from output file:

To generate graphs from an output file, you will need to have [graphviz](https://www.graphviz.org/) installed. Once installed you can generate a graph into either a PDF or PNG file using the 'dot' command. For example, the command to generate a graph into a PNG named graph.png from an output file named output.dot is:

```
	dot -Tpng output.dot -o graph.png
```

Here is an example of a directed graph generated from the above output file:
<p align="center"><img src="https://github.com/ar013/simple_digraph/blob/master/example/graph.png"></p>

Alternatively, you can use the [web-based version of graphviz](http://www.webgraphviz.com/) to generate the graphs by simply copying and pasting your output file into the textbox. (Note: I do NOT recommend this method for larger graphs)

### Contributing:

This was a very simple implementation, written quickly to help me generate Control Flow Graphs. As such I am aware there are many features compatible with graphviz that can easily be implemented and added to this library. Please feel free to build off of this and contribute your work to this repository.
