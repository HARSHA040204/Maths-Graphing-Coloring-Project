#include <iostream>
#include <vector>

const int N = 6;  // Number of stations

// Function to print the station colors (channels)
void printStationsChannels(int colors[]) {
    std::vector<int> channels[N];  // Vector to store stations with the same channel

    // Group stations by color
    for (int i = 0; i < N; i++) {
        channels[colors[i]].push_back(i + 1);  // +1 to match station numbering starting at 1
    }

    // Print the stations for each channel
    for (int i = 0; i < N; i++) {
        if (!channels[i].empty()) {
            std::cout << "Channel " << i + 1 << ": Stations ";
            for (int j = 0; j < channels[i].size(); j++) {
                std::cout << channels[i][j];
                if (j < channels[i].size() - 1) std::cout << ", ";
            }
            std::cout << std::endl;
        }
    }
}

// Function to find the minimum color for a node
int getMinColor(bool graph[N][N], int colors[], int node) {
    bool available[N] = {false};  // Colors available for the node

    // Check colors of adjacent nodes and mark them as unavailable
    for (int i = 0; i < N; ++i) {
        if (graph[node][i] && colors[i] != -1) {
            available[colors[i]] = true;
        }
    }

    // Find the first color that is not assigned to adjacent nodes
    int color;
    for (color = 0; color < N; color++) {
        if (!available[color]) break;
    }

    return color;  // Return the minimum available color
}

// Function to apply graph coloring
int graphColoring(bool graph[N][N], int colors[]) {
    for (int i = 0; i < N; i++) colors[i] = -1;  // Initialize colors for all nodes to -1

    // Assign colors to nodes
    for (int i = 0; i < N; i++) {
        colors[i] = getMinColor(graph, colors, i);
    }

    // Find the maximum color ID used which is the number of channels
    int maxColor = 0;
    for (int i = 0; i < N; i++) {
        if (colors[i] > maxColor) maxColor = colors[i];
    }

    return maxColor + 1;  // +1 because colors start from 0
}

int main() {
    // Distance matrix as provided
    int distances[N][N] = {
        {0, 85, 175, 200, 50, 100},
        {85, 0, 125, 175, 100, 160},
        {175, 125, 0, 100, 200, 250},
        {200, 175, 100, 0, 210, 220},
        {50, 100, 200, 210, 0, 100},
        {100, 160, 250, 220, 100, 0}
    };

    // Create graph from distance matrix, true if distance is within 150 miles
    bool graph[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            graph[i][j] = (i != j && distances[i][j] <= 150);
        }
    }

    int colors[N];  // Array to store the color assigned to each station
    int numChannels = graphColoring(graph, colors);
    std::cout << "Minimum number of channels needed: " << numChannels << std::endl;

    // Print the stations that share the same channel
    printStationsChannels(colors);

    return 0;
}

