#include "main.h"
#include "util.h"

#include <iostream>
#include <string>
#include <math.h>
#include <cstring>

#pragma once

struct min_node;

void build_min_heap(min_node* edges, int size);
void min_heapify(min_node* edges, int i, int n);
min_node minimum(min_node* edges);
min_node extract_min(min_node* edges);

void decrease_key(min_node* edges, int x, int k);
void insert(min_node* edges, int x);

class heap
{
};