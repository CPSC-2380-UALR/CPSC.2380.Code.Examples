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

void Graph::BFS(int start)
{
	bool* visited = new bool[numVertices];
	for (int i = 0; i < numVertices; i++)
	{
		visited[i] = false;
	}
	list <int> queue;

	visited[start] = true;
	queue.push_back(start);

	while (!queue.empty())
	{
		start = queue.front();
		cout << start << " ";
		queue.pop_front();

		for (auto vertex : adjacents[start])
		{
			if (!visited[vertex])
			{
				visited[vertex] = true;
				queue.push_back(vertex);
			}
		}
	}
}