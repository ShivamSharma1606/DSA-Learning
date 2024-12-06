#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Helper functions for alphabet manipulation
char prevLetter(char c) {
    return (c == 'A') ? 'Z' : c - 1;
}

char nextLetter(char c) {
    return (c == 'Z') ? 'A' : c + 1;
}

// Extract a layer from the matrix
vector<char> extractLayer(vector<vector<char>> &subMatrix, int layer) {
    vector<char> elements;
    int n = subMatrix.size();

    // Top row
    for (int i = layer; i < n - layer; ++i)
        elements.push_back(subMatrix[layer][i]);

    // Right column
    for (int i = layer + 1; i < n - layer - 1; ++i)
        elements.push_back(subMatrix[i][n - layer - 1]);

    // Bottom row (if applicable)
    if (layer < n - layer - 1) {
        for (int i = n - layer - 1; i >= layer; --i)
            elements.push_back(subMatrix[n - layer - 1][i]);
    }

    // Left column (if applicable)
    if (layer < n - layer - 1) {
        for (int i = n - layer - 2; i > layer; --i)
            elements.push_back(subMatrix[i][layer]);
    }

    return elements;
}

// Insert a layer back into the matrix
void insertLayer(vector<vector<char>> &subMatrix, int layer, const vector<char> &elements) {
    int n = subMatrix.size();
    int idx = 0;

    // Top row
    for (int i = layer; i < n - layer; ++i)
        subMatrix[layer][i] = elements[idx++];

    // Right column
    for (int i = layer + 1; i < n - layer - 1; ++i)
        subMatrix[i][n - layer - 1] = elements[idx++];

    // Bottom row (if applicable)
    if (layer < n - layer - 1) {
        for (int i = n - layer - 1; i >= layer; --i)
            subMatrix[n - layer - 1][i] = elements[idx++];
    }

    // Left column (if applicable)
    if (layer < n - layer - 1) {
        for (int i = n - layer - 2; i > layer; --i)
            subMatrix[i][layer] = elements[idx++];
    }
}

// Rotate and transform a layer
void rotateLayer(vector<char> &elements, int k, bool isClockwise) {
    int n = elements.size();
    vector<char> rotated(n);

    // Apply rotation
    for (int i = 0; i < n; ++i) {
        int newPos = isClockwise ? (i + k) % n : (i - k + n) % n;
        rotated[newPos] = elements[i];
    }

    // Apply letter transformation
    for (int i = 0; i < n; ++i) {
        rotated[i] = isClockwise ? nextLetter(rotated[i]) : prevLetter(rotated[i]);
    }

    elements = rotated;
}

// Solve the matrix rotation problem
void rotateMatrix(int N, vector<vector<char>> &matrix, vector<tuple<int, int, int>> &queries) {
    for (auto &[row, col, size] : queries) {
        // Extract the sub-matrix
        vector<vector<char>> subMatrix(size, vector<char>(size));
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                subMatrix[i][j] = matrix[row + i][col + j];

        // Process layers
        int numLayers = (size + 1) / 2;
        for (int layer = 0; layer < numLayers; ++layer) {
            vector<char> elements = extractLayer(subMatrix, layer);
            int k = layer + 1;  // Layer index (1-based)

            if (k % 2 == 1) {
                // Odd layer: Counterclockwise rotation
                rotateLayer(elements, k, false);
            } else {
                // Even layer: Clockwise rotation
                rotateLayer(elements, k, true);
            }

            insertLayer(subMatrix, layer, elements);
        }

        // Place the modified sub-matrix back into the original matrix
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                matrix[row + i][col + j] = subMatrix[i][j];
    }
}

int main() {
    // Input
    int N;
    cin >> N;
    vector<vector<char>> matrix(N, vector<char>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> matrix[i][j];

    int K;
    cin >> K;
    vector<tuple<int, int, int>> queries(K);
    for (int i = 0; i < K; ++i) {
        int row, col, size;
        cin >> row >> col >> size;
        queries[i] = {row, col, size};
    }

    // Solve the problem
    rotateMatrix(N, matrix, 
