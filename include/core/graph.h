#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H

#include "edge.h"
#include "vertice.h"

struct graph {
    int n_vertices;
    int n_edges;
    struct graph_vertice *vertices;
    struct graph_edge *edges;
};

int graph_graph_create(int n_vertices, int n_edges, struct graph *graph);
int graph_graph_destroy(struct graph *graph);
int graph_graph_add_vertice(struct graph *graph, struct graph_vertice *vertice);
int graph_graph_add_edge(struct graph *graph, struct graph_edge *edge);
int graph_graph_remove_vertice_by_id(struct graph *graph, int id);
int graph_graph_remove_edge_by_id(struct graph *graph, int id);

#endif //GRAPH_GRAPH_H