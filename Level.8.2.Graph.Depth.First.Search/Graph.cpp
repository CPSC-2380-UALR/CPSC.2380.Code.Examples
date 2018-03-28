#include <iostream>
#include "Graph.h"
using namespace std;
Graph::Graph(int vertices)
{
	this->numVertices = vertices;
	adjacents = new list<int>[numVertices];
}

void Graph::addEdge(int vertex, int adjacentVertex)
{
	adjacents[vertex].push_back(adjacentVertex);
	adjacents[adjacentVertex].push_back(vertex);
}

void Graph::DFS(int start)
{
	bool* visited = new bool[numVertices];
	for (int i = 0; i < numVertices; i++)
	{
		visited[i] = false;
	}
	
	DFSRecursive(start, visited);
}

void Graph::DFSRecursive(int vertex, bool visited[])
{
	visited[vertex] = true;
	cout << vertex << " ";

	for (auto adjVertex : adjacents[vertex])
	{
		if (!visited[adjVertex])
		{
			DFSRecursive(adjVertex, visited);
		}
	}
}
