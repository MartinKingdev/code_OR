# Graph Theory Project (Graphe 2.0)

This project provides basic structures and algorithms for graph theory in C++. It allows you to manipulate oriented or non-oriented graphs, add edges, compute vertex degrees, check connectivity, compute the chromatic number, and run Dijkstra's algorithm.

## Project Structure

- `graph.hpp`: Definition of the `Graph` class and its methods.
- `graph.cpp`: Implementation of the `Graph` class methods.
- `graphAlgorithms.cpp`: Graph algorithms, including `DjikstraAlgorithm`.
- `main.cpp`: Example usage, reads the graph from `graphe.txt`, displays properties, and runs algorithms.
- `graphe.txt`: Example graph (list of edges).
- `readcsv.cpp`: Example for reading CSV files.
- `.vscode/tasks.json`: Build configuration for VS Code.

## Compilation

To compile the project with g++:

```sh
g++ main.cpp graph.cpp -o graphe
```

Or use the predefined build task in VS Code.

## Usage

The main program reads the graph from `graphe.txt`, displays vertices and their successors, checks connectivity, computes the chromatic number, and runs Dijkstra's algorithm.

## Author

Academic project for graph theory.
by Bonaventure DANFI
