#include "graph.h"

#include <iostream>
#include <string>
#include <math.h>
#include <cstring>

using namespace std;

void get_edges(node_entry** nodes, int max_edges)
{
	// This method grabs the m number of edges listed in the .txt file and stores the edges into the adjacency list

	string u_str, v_str, w_str;
	int u, v, w;

	for (int i = 0; i < max_edges; i++)
	{
		cin >> u_str; // cin u
		cin >> v_str; // cin v
		cin >> w_str; // cin w
		cin.ignore(100, '\n'); // ignore rest of line

		u = stoi(u_str); // string-to-integer
		v = stoi(v_str);
		w = stoi(w_str);

		//cout << u << " " << v << " " << w << endl; // Used for debugging

		insert_edge(nodes, u, v, w); // calling insert_edges method, which does exactly that
	}

}

void insert_edge(node_entry** nodes, int u, int v, int w)
{
	// After grabbing the line of integers we'll insert them into the adjacency list

	node_entry* u_pointer = (nodes[u]); // Point to the u node in the adjacency list
	node_entry* v_pointer = (nodes[v]); // Point to the v node
	edge_entry* edge_pointer = u_pointer->edge_list; // pointer to the edges  associated with node u

	if (edge_pointer == NULL) // If an edge has yet to be stored that leaves node u...
	{
		edge_entry* new_entry = new edge_entry(); // Create the new link

		u_pointer->node_position = u; // set the u node to u (int)
		u_pointer->edge_list = new_entry; // Add the new link to the edge list
		new_entry->pointer = v_pointer; // Add the v node to the new link's pointer
		new_entry->weight = w; // Of weight w
		new_entry->next = NULL; // Setting next to NULL

		return;
	}
	else
	{
		while (edge_pointer->next != NULL) // However if the edge list in the u node isn't NULL, find the next NULL link
		{
			edge_pointer = edge_pointer->next;
		}

		edge_entry* new_entry = new edge_entry();

		edge_pointer->next = new_entry;
		new_entry->pointer = v_pointer;
		new_entry->weight = w;
		new_entry->next = NULL;
	}

}

void create_array(node_entry** nodes, min_heap* array, int m, int n) // m = edges n = nodes // Doesnt matter I dont end up calling this anyway in my dij
{
	for (int i = 1, j = 0; i <= n; i++)
	{
		node_entry* prev_pointer = (nodes[i]);
		edge_entry* current_pointer = (nodes[i]->edge_list);

		while (current_pointer != NULL)
		{
			array[j].previous_node = prev_pointer;
			array[j].current_node = current_pointer->pointer;
			array[j].weight = current_pointer->weight;

			j++;
			current_pointer = current_pointer->next;
		}
	}
}