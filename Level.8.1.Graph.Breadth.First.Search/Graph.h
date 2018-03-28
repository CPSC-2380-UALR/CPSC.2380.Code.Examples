#ifndef GRAPH_H
#define GRAPH_H
#include <list>
class Graph
{
public:
	Graph(int vertices);
	
	void addEdge(int vertex, int adjacentVertex);

	void BFS(int start);
private:
	int numVertices;
	std::list<int>* adjacents;

};
#endif // !GRAPH_H

