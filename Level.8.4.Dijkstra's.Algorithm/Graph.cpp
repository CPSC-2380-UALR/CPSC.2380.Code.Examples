#include <iostream>
#include "Graph.h"
using namespace std;
Graph::Graph(int vertices)
{
	this->numVertices = vertices;
	adjacents = new int*[vertices];
	for (int i = 0; i < vertices; i++)
	{
		adjacents[i] = new int[vertices];
		for (int j = 0; j < vertices; j++)
		{
			adjacents[i][j] = 0;
		}
	}
}

void Graph::addEdge(int vertex, int adjacentVertex, int weight)
{
	adjacents[vertex][adjacentVertex] = weight;
	adjacents[adjacentVertex][vertex] = weight;
}

int Graph::minDistance(int dist[], bool sptSet[])
{
	int min = INT_MAX, minIndex;
	for (int vertex = 0; vertex < numVertices; vertex++)
	{
		if (sptSet[vertex] == false && dist[vertex] <= min)
		{
			min = dist[vertex];
			minIndex = vertex;
		}
	}
	return minIndex;
}

int Graph::printSolution(int dist[])
{
	cout << "Vertex \tDistance From Source\n";
	for (int i = 0; i < numVertices; i++)
	{
		cout << i << "\t" << dist[i] << endl;
	}
	return 0;
}

void Graph::dijkstra(int src)
{
	int* dist = new int[numVertices];
	bool* sptSet = new bool[numVertices];

	for (int i = 0; i < numVertices; i++)
	{
		dist[i] = INT_MAX;
		sptSet[i] = false;
	}

	dist[src] = 0;
	for (int count = 0; count < numVertices - 1; count++)
	{
		// Pick the minimum distance vertex from the set of vertices not
		// yet processed. u is always equal to src in first iteration.
		int u = minDistance(dist, sptSet);

		sptSet[u] = true;

		for (int v = 0; v < numVertices; v++)
		{
			// Update dist[v] only if is not in sptSet, there is an edge from 
			// u to v, and total weight of path from src to  v through u is 
			// smaller than current value of dist[v]
			if (!sptSet[v] && adjacents[u][v] && dist[u] != INT_MAX
				&& dist[u] + adjacents[u][v] < dist[v])
				dist[v] = dist[u] + adjacents[u][v];

		}
		
	}
	printSolution(dist);
}

//void Graph::BFS(int start)
//{
//	bool* visited = new bool[numVertices];
//	for (int i = 0; i < numVertices; i++)
//	{
//		visited[i] = false;
//	}
//	list <int> queue;
//
//	visited[start] = true;
//	queue.push_back(start);
//
//	while (!queue.empty())
//	{
//		start = queue.front();
//		cout << start << " ";
//		queue.pop_front();
//
//		for (auto vertex : adjacents[start])
//		{
//			if (!visited[vertex])
//			{
//				visited[vertex] = true;
//				queue.push_back(vertex);
//			}
//		}
//	}
//}

//bool Graph::isCyclic()
//{
//	bool * visited = new bool[numVertices];
//	bool * stack = new bool[numVertices];
//	for (int i = 0; i < numVertices; i++)
//	{
//		visited[i] = false;
//		stack[i] = false;
//	}
//	
//	for (int i = 0; i < numVertices; i++)
//	{
//		if (isCyclicUtil(i, visited, stack))
//			return true;
//	}
//	return false;
//}
//
//bool Graph::isCyclicUtil(int vertex, bool visited[], bool * stack)
//{
//	if (visited[vertex] == false)
//	{
//		visited[vertex] = true;
//		stack[vertex] = true;
//
//		for (auto adjacent : adjacents[vertex])
//		{
//			if (!visited[adjacent] && isCyclicUtil(adjacent, visited, stack))
//			{
//				return true;
//			}
//			else if (stack[adjacent])
//			{
//				return true;
//			}
//
//		}
//	}
//	stack[vertex] = false;
//	return false;
//	return false;
//}
