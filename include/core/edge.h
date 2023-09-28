#ifndef GRAPH_EDGE_H
#define GRAPH_EDGE_H

typedef struct graph_node;

struct graph_edge
{
    int id;
    struct graph_node *start;
    struct graph_node *end;
    int weight;
};

int graph_edge_create(int id, struct graph_node *start, struct graph_node *end, int weight, struct graph_edge *edge);
int graph_edge_destroy(struct graph_edge *edge);
int graph_edge_set_id(struct graph_edge *edge, int id);
int graph_edge_set_start(struct graph_edge *edge, struct graph_node *start);
int graph_edge_set_end(struct graph_edge *edge, struct graph_node *end);
int graph_edge_set_weight(struct graph_edge *edge, int weight);

#endif //GRAPH_EDGE_H