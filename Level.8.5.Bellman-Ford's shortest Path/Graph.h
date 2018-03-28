#ifndef GRAPH_H
#define GRAPH_H
#include <list>
#include <map>
class Graph
{
public:
	Graph(int vertices);
	
	void addEdge(int vertex, int adjacentVertex, int weight);

	//void BFS(int start);
	//bool isCyclic();
	int minDistance(int dist[], bool sptSet[]);
	int printSolution(int dist[]);
	void dijkstra(int src);
	bool BellmanFord(int start);

private:
	int numVertices;
	//int** adjacents;
	std::list<std::pair<int,int>>* adjacents;
	//bool isCyclicUtil(int vertex, bool visited[], bool* stack);

};
#endif // !GRAPH_H

