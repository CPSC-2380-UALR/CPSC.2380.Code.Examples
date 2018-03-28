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

bool Graph::isCyclic()
{
	bool * visited = new bool[numVertices];
	bool * stack = new bool[numVertices];
	for (int i = 0; i < numVertices; i++)
	{
		visited[i] = false;
		stack[i] = false;
	}
	
	for (int i = 0; i < numVertices; i++)
	{
		if (isCyclicUtil(i, visited, stack))
			return true;
	}
	return false;
}

bool Graph::isCyclicUtil(int vertex, bool visited[], bool * stack)
{
	if (visited[vertex] == false)
	{
		visited[vertex] = true;
		stack[vertex] = true;

		for (auto adjacent : adjacents[vertex])
		{
			if (!visited[adjacent] && isCyclicUtil(adjacent, visited, stack))
			{
				return true;
			}
			else if (stack[adjacent])
			{
				return true;
			}

		}
	}
	stack[vertex] = false;
	return false;
	return false;
}
