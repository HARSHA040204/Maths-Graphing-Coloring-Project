# Frequency Assignment using Graph Coloring

This project explores the application of graph coloring in frequency assignment, specifically addressing the challenge of determining the number of different channels needed for six stations located at varying distances. The goal is to ensure that two stations within 150 miles of each other cannot use the same channel.

## Problem Statement

Given the distances between six stations, the task is to find the minimum number of channels required for broadcasting. The constraint is that stations within 150 miles of each other must operate on different channels.

## Solution Approach

### 1. Graph Creation

We use a graph to represent the relationships between stations. Nodes represent stations, and edges connect stations within 150 miles of each other.

### 2. Greedy Algorithm

We employ a greedy algorithm for graph coloring to determine the minimum number of channels needed. The algorithm assigns colors (channels) to stations while ensuring that adjacent stations do not share the same color.

### 3. Implementation

The solution is implemented in C++ to create the graph, apply the greedy algorithm, and output the minimum number of channels required.


## Visualization

Python scripts are provided to visualize the graph and the assigned channels. Ensure you have the required Python libraries installed:
   ```bash
   pip install networkx matplotlib
   ```

Run the visualization script:
   ```bash
   pip install matplotlib
   ```

