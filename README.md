# CSE 199, Winter 2021 - Nora Yinxuan Du

This repository contains codes and solutions for USACO contests from past years. More details in below.

## 2019 US Open, Bronze

Important links for the contest:
- main website: http://www.usaco.org/index.php?page=open19results
- problem descriptions:
	- **Bucket Brigade**: http://www.usaco.org/index.php?page=viewproblem2&cpid=939
	- **Milk Factory**: http://www.usaco.org/index.php?page=viewproblem2&cpid=940
	- **Cow Evolution**: http://www.usaco.org/index.php?page=viewproblem2&cpid=941

Solution summary:
- **Bucket Brigade**
	> Keyword: Graph, Greedy, BFS, Recursion
	> 
	> [My Code Here](https://github.com/CaoAssignments/cse199-wi21-nora-yinxuan-du/blob/main/2019%20US%20Open/buckets.cpp)

Different from the most fundamental question about finding the shortest path between two nodes in a graph, this problem sets up 'Rock' grid(s), places we are not allowed to go, and 'Lake' grid, where we can stop as long as we get to the neighboring grid. By this observation, to solve the question, we can just adjust our codes based on the BFS template: 1. for 'Rock' grid(s), we can just do another check before we move to the next grid; 2. for the 'Lake' grid, we can check if the expected next grid is 'Lake' grid so that we know the current grid is valid as an ending grid.

USACO official provides a greedy solution but it assumes that each special grid appears exact one time. However, it is not guaranteed in the problem description.

- **Milk Factory**
	> Keyword: Graph, Union Find, Tree
	>
	> [My Code Here](https://github.com/CaoAssignments/cse199-wi21-nora-yinxuan-du/blob/main/2019%20US%20Open/factory.cpp)

Given n nodes and (n - 1) parent-child relationship(s), this problem wants you to find whether such a graph has a tree structure and print the root of the tree. I provide a Union Find solution here. It makes sense because for every node, we don't need to care about its parent node. We only need to keep track of its root (ancestor). Note that it also works if we have different number of parent-child relationship(s).

Catching the condition that we always have (n - 1) edge(s), USACO official solves this problem perfectly by checking the indegree and outegree of each node.

- **Cow Evolution**
	> Keyword: Inclusion - Exclusion, String, Tree
	> 
	> [My Code Here](https://github.com/CaoAssignments/cse199-wi21-nora-yinxuan-du/blob/main/2019%20US%20Open/evolution.cpp)

My code referenced by the official solution. Check the details [here](http://www.usaco.org/current/data/sol_evolution_bronze_open19.html)
