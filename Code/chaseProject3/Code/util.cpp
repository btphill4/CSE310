#include "util.h"
#include "main.h"
#include "heap.h"

#include <iostream>
#include <string>
#include <math.h>
#include <cstring>
#include <climits>

using namespace std;

/* 
	As you know, Dijkstra’s algorithm solves the single-source shortest-paths problem on a weighted, directed
	graph G = (V, E) for the case in which all edge weights are non-negative. Therefore, we assume w(u, v) ≥ 0
	for each directed edge (u, v) ∈ E.

	Dijkstra’s algorithm maintains a set S of vertices whose final shortest-path weights from the source s
	have already been determined. The algorithm repeatedly selects the vertex u ∈ V − S with the minimum
	shortest-path estimate, adds u to S, and relaxes all edges leaving u.
	You are to implement Dijkstra’s algorithm using the psuedocode that follows, using a min-priority queue
	Q of vertices keyed by their distance values, and an adjacency list representation for G. The functions
	Initialize-Single-Source and Relax were provided and discussed in class.

	Initialize-Single-Source(G, s) {Initialize distance and predecessor of each vertex v ∈ V }
	S = ∅ {S is initially empty because no shortest-paths are determined yet}
	Q = V {Use Insert(Q, v) to insert each vertex v ∈ V into the min-priority queue Q}
	while ( Q != ∅ ) do
		u = Extract-Min(Q) {Extract the vertex u with current minimum distance from Q}
		S = S ∪ {u} {Add u into the set S of vertices whose final shortest-path has been determined}
		for each vertex v adjacent to u do
			Relax(u, v, w) {If the distance to v decreases to d 0, then Decrease-Key(Q, v, d0 )}
		end for
	end while
*/

// source node is where we're starting

min_node* dijkstra(node_entry** adjacency_list, int s, int t, int size) //Doesn't work 
{
	min_node* S = new min_node[size]; // n size
	min_node* Q = new min_node[size]; // n size

	initialize_single_source(adjacency_list, Q, s, size);

	build_min_heap(Q, size);

	// Q is a min-heap now

	// S = ∅
	for (int i = 0; i < size; i++)
	{
		S[i].current_node = NULL;
		S[i].previous_node = NULL;
		S[i].weight = 0;
	}
	int j = 0;
	// Q = V
	while (j < size) //Q != ∅
	{
		min_node u = extract_min(Q);
		int position = u.current_node->node_position;
		S[position] = u;

		for (int i = 1; i <= size; i++)
		{
			if (S[i].current_node != NULL)
			{
				relax(adjacency_list, Q, u.current_node->node_position, S[i].current_node->node_position);
			}			
		}
		//cout << "Test" << endl;
		j++;
	}
	return S;
}


void initialize_single_source(node_entry** adjacency_list, min_node* Q, int s, int size) // G, s // initializes the min heap array
{
	// for each of the vertex v in V[G] do ( d[v] = infinity pi[v] = NIL ) d[s] = 0
	// s needs to be the index of the node in the node table

	/*Q[0].current_node = NULL;
	Q[0].previous_node = NULL;
	Q[0].weight = 0;*/

	for (int i = 1; i <= size; i ++)
	{
		node_entry* current_pointer = (adjacency_list[i]);

		Q[i].current_node = current_pointer;
		Q[i].previous_node = NULL;
		Q[i].weight = INT_MAX; //((10)^99)
	}

	Q[s].weight = 0;

	// path[0].current = //source;
	
}

void relax(node_entry** adjacency_list, min_node* vertices, int u, int v) // u, v, w
{
	// if the distance of d[v] > d[u] + w(u, v)
			// then d[v] = d[u] + w(u, v)
				// prev[v] = u

	int weight = get_weight(adjacency_list, u, v);

	if (vertices[v].weight > vertices[u].weight + weight)
	{
		vertices[v].weight = vertices[u].weight + weight;
		vertices[v].previous_node = vertices[u].current_node;
	}
}


int get_weight(node_entry** adjacency_list, int u, int v)
{
	edge_entry* pointer = (adjacency_list[u]->edge_list);

	while (pointer != NULL)
	{
		if (pointer->pointer->node_position == v)
		{
			return pointer->weight;
		}
		else
		{
			pointer = pointer->next;
		}
	}

	//cout << "There is no edge from u to v" << endl;
	return 0;
}