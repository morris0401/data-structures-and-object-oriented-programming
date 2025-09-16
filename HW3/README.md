# HW3

This directory contains the files for **HW3**.

## 📄 Project Introduction

### Project Introduction

This project involves the design and implementation of a graph system using C++ with a focus on data structures and object-oriented programming. The primary objective is to develop a system capable of manipulating graphs, which are defined as a set of nodes (V) and edges (E). Key constraints include a maximum of 1000 nodes and 1000 edges, a maximum node degree of 1000, and no support for parallel edges. Node positions are confined to the x-z plane, with the y-coordinate always set to zero.

### Methods Used

The core of the implementation requires modifying and utilizing predefined `GRAPH_NODE` and `GRAPH_EDGE` data structures, allowing for additional data members and functions as needed. The system must support the following fundamental graph manipulation operations:

*   **Node Management:**
    *   `int addNode(float x, float y, float z, float r = 1.0);`: Adds a node at a specified (x, y, z) position and radius, returning its unique ID.
    *   Deletion of a selected node and all its attached edges.
*   **Edge Management:**
    *   `int addEdge(int nodeID_0, int nodeID_1);`: Adds an edge between two specified nodes, returning its unique ID.
*   **Graph Generation Algorithms:** Functions to create various graph topologies:
    *   `void createDefaultGraph();`: Creates a simple predefined graph.
    *   `void createNet_Circular(int n, int num_layers);`: Arranges nodes in concentric circles with specific layer and inter-layer connections.
    *   `void createNet_Square(int n, int num_layers);`: Arranges nodes in square grids, potentially with a central void.
    *   `void createNet_RadialCircular(int n);`: Arranges nodes radially around a central node.
    *   `void createRandomGraph_DoubleCircles(int n);`: Generates nodes in two circles with randomly created edges based on proximity and non-intersection with the inner circle.
*   **Query Functions:**
    *   `int getNumOfNodes() const;`: Retrieves the total number of nodes.
    *   `void getNodeInfo(int nodeIndex, double &r, vector3 &p) const;`: Returns the position and radius of a node by its index.
    *   `int getNumOfEdges() const;`: Retrieves the total number of edges.
    *   `vector3 getNodePositionOfEdge(int edgeIndex, int nodeIndex) const;`: Returns the position of a node connected to a specific edge.
*   **Utility Function:**
    *   `GRAPH_NODE *findNearestNode(double x, double z, double &cur_distance2) const;`: Identifies the nearest node to a given (x, z) coordinate, storing the squared distance.

### Experimental Procedures

The system's functionality is demonstrated through user interaction via keyboard and mouse, generating and manipulating graphs.

*   **Graph Creation:**
    *   Press '1': Create the default graph.
    *   Press '2': Create a circular net graph (`createNet_Circular(12, 3)` example).
    *   Press '3': Create a square net graph (`createNet_Square(3, 11)` example).
    *   Press '4': Create a radial circular graph (`createNet_RadialCircular(24)` example).
    *   Press '5': Create a random double circle graph (`createRandomGraph_DoubleCircles(24)` example).
*   **Graph Modification (Interactive):**
    *   Mouse left click: Select/unselect a node (selected nodes are highlighted in red).
    *   Select two nodes: Automatically creates an edge between them.
    *   Press 'Delete': Deletes the currently selected node and all its attached edges.
    *   Press 'Spacebar': Unselects the currently selected node.
*   **Dynamic Parameters:**
    *   When using `createRandomGraph_DoubleCircles`, press '<' to decrease the number of nodes per circle (minimum 3) and '>' to increase (maximum 36).
*   **Automatic Deletion:**
    *   Press 'd': Toggles an automatic node deletion process with a 250ms delay.

### Summary of Experimental Results

The PDF primarily outlines the requirements and expected visual outcomes of the graph generation functions rather than presenting empirical results or performance metrics. It shows visual representations for `createDefaultGraph`, `createNet_Circular`, `createNet_Square`, `createNet_RadialCircular`, and `createRandomGraph_DoubleCircles`, demonstrating the desired topological structures for each function's output. The document also illustrates the interaction for node selection, edge creation, and node deletion by showing graph states before and after these operations. No quantitative data on efficiency, scalability, or algorithm performance is provided.

### Potential Improvements

Based on the assignment scope and stated constraints, potential improvements could include:

*   **Extended Graph Functionality:** Implement common graph traversal algorithms (e.g., BFS, DFS) and pathfinding algorithms (e.g., Dijkstra's, A*).
*   **Handling Directed/Weighted Graphs:** Extend the `GRAPH_EDGE` structure and related functions to support directed edges and assign weights to edges.
*   **Parallel Edges:** Implement support for parallel edges, which are explicitly excluded in the current assumptions.
*   **Error Handling:** Implement robust error handling for operations like attempting to add an edge to non-existent nodes or exceeding graph limits.
*   **Advanced Visualization:** Incorporate more sophisticated visualization options, such as customizable node/edge colors, labels, and dynamic layouts.
*   **Performance Optimization:** For graphs exceeding the specified limits, consider more advanced data structures (e.g., adjacency lists for sparse graphs) or algorithms for better performance.
*   **Undo/Redo Functionality:** Add the ability to undo or redo graph modifications.

### How to Run and Reproduce

The system is designed for interactive use with keyboard and mouse input. Upon launching the application, console messages will guide the user.

*   **Graph Creation:** Press '1', '2', '3', '4', or '5' on the keyboard to generate the corresponding graph type as described in the "Experimental Procedures" section.
*   **Node Count Adjustment (for `createRandomGraph_DoubleCircles`):** While displaying a double circle graph (created with '5'), use the '<' and '>' keys to decrease or increase the number of nodes in each circle, respectively.
*   **Node/Edge Manipulation:**
    *   Use the left mouse button to click on a node to select it. A selected node will be highlighted in red. Clicking the same node again will unselect it.
    *   To create an edge, select two different nodes. The system will automatically connect them.
*   **Node Deletion:**
    *   Select a node using the left mouse button.
    *   Press the 'Delete' key on the keyboard to remove the selected node and all edges connected to it.
*   **Unselect Node:** Press the 'Spacebar' key to unselect any currently selected node.
*   **Automatic Deletion:** Press 'd' to toggle an automatic deletion process for nodes, which operates with a 250-millisecond delay.

## 📂 Files

- `base_class.h`
- `graph_basics.h`
- `hw03_01_GraphSystem.pdf`
- `myBasicTools.cpp`
- `myBasicTools.h`
- `mySystemApp.cpp`
- `mySystemApp.h`
- `mySystemApp_HandleEvents.cpp`
- `mySystemApp_draw.cpp`
- `mySystem_2048.cpp`
- `mySystem_2048.h`
- `mySystem_2048_draw.cpp`
- `mySystem_GraphSystem.cpp`
- `mySystem_GraphSystem.h`
- `mySystem_GraphSystem_draw.cpp`
- `mySystem_ImageEditor.cpp`
- `mySystem_ImageEditor.h`
- `mySystem_ImageEditor_draw.cpp`

A detailed project description and summary can be found in the [main repository README](../README.md).

