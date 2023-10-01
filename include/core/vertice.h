#ifndef GRAPH_VERTICE_H
#define GRAPH_VERTICE_H

typedef void* graph_vertice_data;
typedef void(*graph_vertice_printer)(void*);

struct graph_vertice {
    int id; // could be swapp to a char* for uuid
    graph_vertice_data data; // adapt to the data type
    int weight; // either known or need to be computed from the data
};

int graph_vertice_create(int id, graph_vertice_data data, int weight, struct graph_vertice* vertice);
int graph_vertice_destroy(struct graph_vertice* vertice);
int graph_vertice_set_id(struct graph_vertice* vertice, int id);
int graph_vertice_set_data(struct graph_vertice* vertice, graph_vertice_data data);
int graph_vertice_set_weight(struct graph_vertice* vertice, int weight);
void graph_vertice_print(struct graph_vertice* vertice, graph_vertice_printer func_print_data);

#endif //GRAPH_VERTICE_H