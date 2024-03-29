#include "main.h"

#include <iostream>
#include <string>
#include <math.h>
#include <cstring>

#pragma once

/*
struct map {
	struct node_entry* previous;
	struct node_entry* current;	
	int distance;

};*/

struct min_node {
	struct node_entry* previous_node;
	struct node_entry* current_node;
	int weight;
};

min_node* dijkstra(node_entry** adjacency_list, int s, int t, int size);
void initialize_single_source(node_entry** adjacency_list, min_node*, int s, int size);
void relax(node_entry** adjacency_list, min_node* vertices, int u, int v);
int get_weight(node_entry** adjacency_list, int u, int v);

class util
{
};

