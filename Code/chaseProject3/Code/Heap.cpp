#include "Heap.hpp"
#include "main.h"
#include "util.h"
#include <iostream>
#include <string>
#include <math.h>
#include <cstring>

using namespace std;

/*
	A priority queue is a data structure for maintaining a set S of elements, each with an associated value called
	a key. Priority queues come in two forms: Max-priority queues and min-priority queues. Our focus is on a
	min-priority queue because Dijkstra’s algorithm finds the shortest path to each vertex from a source, i.e., it
	works to minimize the path length.

	A min-priority queue supports four operations:

	1. Insert(S, x): Inserts the element x into the set S, which is equivalent to the operation S = S ∪ {x}.
	2. Minimum(S): Returns the element of S with the smallest key.
	3. Extract-Min(S): Removes and returns the element of S with the smallest key.
	4. Decrease-Key(S, x, k): Decreases the value of element x’s key to a new value k, where k is less than
	or equal to x’s current key value
*/


void build_min_heap(min_node* edges, int size) // Builds an initial min heap
{
	for (int i = floor(size / 2); i >= 0; i--)
	{
		min_heapify(edges, i, size);
	}
}

void min_heapify(min_node* edges, int i, int n) // Given two points in the array floats the nodes into sorted position
{
	int left = 2 * i;
	int right = 2 * i + 1;
	int smallest;

	if (left < n && edges[left].weight < edges[i].weight)
	{
		smallest = left;
	}
	else
	{
		smallest = i;
	}
	if (right < n && edges[right].weight < edges[smallest].weight)
	{
		smallest = right;
	}
	if (smallest != i)
	{
		swap(edges[i], edges[smallest]);
		min_heapify(edges, smallest, n);
	}
}

min_node minimum(min_node* edges) // Grabs minimum element
{
	return edges[1]; // Return the minimum element is the root element in the min heap
}

min_node extract_min(min_node* edges) // Pulls out the min element and deletes it from min_heap
{
	int length = sizeof(edges);
	min_node min = edges[1];
	edges[1] = edges[length];
	length = length - 1;
	min_heapify(edges, 1, length);

	return min;
}

void decrease_key(min_node* edges, int x, int k) // Might not be correct due to ".weight" 's
{
	if (k > edges[x].weight)
	{
		cout << "New value is greater than current value, can't be inserted" << endl;
		return;
	}
	edges[x].weight = k;
	while (x > 1 && edges[x/2].weight > edges[x].weight)
	{
		swap(edges[x/2], edges[x]);
		x = x / 2;
	}
}

void insert(min_node* edges, int x) // Insertion into min heap
{
	int length = sizeof(edges);
	length = length + 1;
	edges[length].weight = -1;
	decrease_key(edges, length, x);
}