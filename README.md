# 📊 Design and Analysis of Algorithms

![Language](https://img.shields.io/badge/language-C-blue.svg)
![Last Commit](https://img.shields.io/badge/last%20commit-May%202025-green)
![Course](https://img.shields.io/badge/course-DAA-orange)

This repository contains implementations of fundamental algorithms and data structures as part of the **Design and Analysis of Algorithms** course. All implementations are written in C language with a focus on efficiency, readability, and proper analysis.

## 📑 Table of Contents

- [Overview](#-overview)
- [Assignment List](#-assignment-list)
- [How to Run](#-how-to-run)
- [Implementation Details](#-implementation-details)
- [Time and Space Complexity](#-time-and-space-complexity)
- [Contributing](#-contributing)
- [Resources](#-resources)

## 🔍 Overview

This repository is organized into assignment folders, each containing implementations of specific algorithms. The focus is on understanding fundamental algorithm design paradigms and analyzing their efficiency.

## 📚 Assignment List

### Assignment 01: Searching Algorithms
- **[Linear Search](ASSIGNMENT%2001/01_LinearSearch.c)**: Simple sequential search algorithm
- **[Binary Search](ASSIGNMENT%2001/02_BinarySearch.c)**: Efficient search algorithm for sorted arrays

### Assignment 02: Sorting Algorithms
- **[Merge Sort](ASSIGNMENT%2002/01_MergeSort.c)**: Divide and conquer sorting algorithm
- **[Quick Sort](ASSIGNMENT%2002/02_QuickSort.c)**: Efficient sorting method with partitioning

### Assignment 03: Divide and Conquer
- **[Maximum and Minimum Element](ASSIGNMENT%2003/01_MaxAndMinUsingDivideAndConquer.c)**: Finding max/min using divide and conquer
- **[Strassen's Matrix Multiplication](ASSIGNMENT%2003/02_StrassenMatrixMultiplication.c)**: Optimized matrix multiplication

### Assignment 04: Graph Traversal
- **[Depth First Search (DFS)](ASSIGNMENT%2004/01_DFS.c)**: Graph traversal algorithm
- **[Breadth First Search (BFS)](ASSIGNMENT%2004/02_BFS.c)**: Level-order traversal of graphs

### Assignment 05: Shortest Path Algorithm
- **[Dijkstra's Algorithm](ASSIGNMENT%2005/01_DijkstraAlgo.c)**: Finding shortest path in weighted graphs

### Assignment 06: Backtracking
- **[N-Queen Problem](ASSIGNMENT%2006/01_NQueen.c)**: Classic backtracking challenge

### Assignment 07: Dynamic Programming
- **[0/1 Knapsack Problem](ASSIGNMENT%2007/01_KnapsackUsingDP.c)**: Optimization using dynamic programming

### Assignment 08: Greedy Algorithms
- **[Fractional Knapsack](ASSIGNMENT%2008/01_FracKnapsack.c)**: Greedy approach to knapsack problem
- **[Job Sequencing](ASSIGNMENT%2008/02_JobSeqUsingGreedy.c)**: Scheduling jobs for maximum profit

## 🚀 How to Run

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/DAA-ASSIGNMENTS.git
   ```

2. Navigate to the desired algorithm folder:
   ```bash
   cd "DAA ASSIGNMENTS/ASSIGNMENT XX"
   ```

3. Compile the C program:
   ```bash
   gcc XX_AlgorithmName.c -o algorithm
   ```

4. Execute the program:
   ```bash
   ./algorithm
   ```

## 🧩 Implementation Details

Each implementation includes:
- Proper documentation and comments
- Input/output examples
- Core algorithm implementation
- Supporting utility functions

## ⏱️ Time and Space Complexity

| Algorithm | Time Complexity (Average) | Time Complexity (Worst) | Space Complexity |
|-----------|---------------------------|-------------------------|------------------|
| Linear Search | O(n) | O(n) | O(1) |
| Binary Search | O(log n) | O(log n) | O(1) |
| Merge Sort | O(n log n) | O(n log n) | O(n) |
| Quick Sort | O(n log n) | O(n²) | O(log n) |
| DFS | O(V + E) | O(V + E) | O(V) |
| BFS | O(V + E) | O(V + E) | O(V) |
| Dijkstra's Algorithm | O(V² + E) | O(V² + E) | O(V + E) |
| N-Queen | O(n!) | O(n!) | O(n) |
| Knapsack (DP) | O(n×W) | O(n×W) | O(n×W) |
| Job Sequencing | O(n²) | O(n²) | O(n) |
| Fractional Knapsack | O(n log n) | O(n log n) | O(1) |

## 🤝 Contributing

Contributions are welcome! If you'd like to improve implementations or add new algorithms:

1. Fork the repository
2. Create your feature branch: `git checkout -b feature/new-algorithm`
3. Commit your changes: `git commit -m 'Add new algorithm'`
4. Push to the branch: `git push origin feature/new-algorithm`
5. Submit a pull request

## 📚 Resources

- Introduction to Algorithms by Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, and Clifford Stein
- The Algorithm Design Manual by Steven S. Skiena
- GeeksforGeeks: [https://www.geeksforgeeks.org/](https://www.geeksforgeeks.org/)
- VisuAlgo: [https://visualgo.net/](https://visualgo.net/)