#ifndef GRAPH_H
#define GRAPH_H
#include <list>
class Graph
{
public:

	Graph(int vertices);
	
	void addEdge(int vertex, int adjacentVertex);

	void BFS(int start);
	bool isCyclic();

private:
	int numVertices;
	std::list<int>* adjacents;

	bool isCyclicUtil(int vertex, bool visited[], bool* stack);

};
#endif // !GRAPH_H

