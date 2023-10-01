#ifndef GRAPH_EDGE_H
#define GRAPH_EDGE_H

#include "vertice.h"

enum graph_edge_direction
{
    IN,
    OUT,
    BOTH
};

struct graph_edge
{
    int id;
    struct graph_vertice *start;
    struct graph_vertice *end;
    int weight;
    enum graph_edge_direction direction;
};

int graph_edge_create(int id, struct graph_vertice *start, struct graph_vertice *end, enum graph_edge_direction direction, int weight, struct graph_edge *edge);
int graph_edge_destroy(struct graph_edge *edge);
int graph_edge_set_id(struct graph_edge *edge, int id);
int graph_edge_set_start(struct graph_edge *edge, struct graph_vertice *start);
int graph_edge_set_end(struct graph_edge *edge, struct graph_vertice *end);
int graph_edge_set_weight(struct graph_edge *edge, int weight);
int graph_edge_set_direction(struct graph_edge *edge, enum graph_edge_direction direction);
void graph_edge_print(struct graph_edge *edge);

#endif // GRAPH_EDGE_H