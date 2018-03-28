#ifndef GRAPH_H
#define GRAPH_H
#include <list>
class Graph
{
public:
	Graph(int vertices);
	
	void addEdge(int vertex, int adjacentVertex);

	void DFS(int start);
private:
	void DFSRecursive(int vertex, bool visited[]);
	int numVertices;
	std::list<int>* adjacents;

};
#endif // !GRAPH_H

