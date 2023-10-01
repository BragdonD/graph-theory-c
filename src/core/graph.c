#include <stdlib.h>
#include <stdio.h>
#include "core/graph.h"
#include "core/vertice.h"
#include "core/edge.h"

/**
 * @brief Create a graph
 * @param graph The graph to create
 * @return 1 if success, 0 otherwise
*/
int graph_graph_create(struct graph *graph)
{
    if (graph != NULL)
    {
        perror("graph_graph_create: graph is not NULL");
        return 0;
    }

    graph = (struct graph*)malloc(sizeof(struct graph));
    if (graph == NULL)
    {
        perror("graph_graph_create: malloc failed");
        return 0;
    }

    graph->vertices = NULL;
    graph->edges = NULL;
    graph->n_edges = 0;
    graph->n_vertices = 0;
    return 1;
}

/**
 * @brief Destroy a graph
 * @param graph The graph to destroy
 * @return 1 if success, 0 otherwise
*/
int graph_graph_destroy(struct graph *graph)
{
    if(graph == NULL)
    {
        perror("graph_graph_destroy: graph is NULL");
        return 0;
    }
    if(graph->edges != NULL) {
        free(graph->edges);
        graph->edges = NULL;
    }
    if(graph->vertices != NULL) {
        free(graph->vertices);
        graph->vertices = NULL;
    }
    free(graph);
    return 1;
}

/**
 * @brief Add a vertice to a graph
 * @param graph The graph to add the vertice to
 * @param vertice The vertice to add
 * @return 1 if success, 0 otherwise
 * @note The vertice must not already be in the graph
*/
int graph_graph_add_vertice(struct graph *graph, struct graph_vertice *vertice)
{
    if(graph == NULL)
    {
        perror("graph_graph_add_vertice: graph is NULL");
        return 0;
    }

    if(vertice == NULL)
    {
        perror("graph_graph_add_vertice: vertice is NULL");
        return 0;
    }

    if(graph_find_vertice_by_id(graph, vertice->id) != NULL)
    {
        perror("graph_graph_add_vertice: vertice already exists");
        return 0;
    }
    
    struct graph_vertice **new_vertices = (struct graph_vertice**)realloc(graph->vertices, sizeof(struct graph_vertice*) * (graph->n_vertices + 1));
    if(new_vertices == NULL)
    {
        perror("graph_graph_add_vertice: realloc failed");
        return 0;
    }
    graph->vertices = new_vertices;
    graph->vertices[graph->n_vertices - 1] = vertice;
    graph->n_vertices++;
    return 1;
}

/**
 * @brief Find a vertice in a graph by its id
 * @param graph The graph to search in
 * @param id The id of the vertice to find
 * @return The vertice if found, NULL otherwise
 * @note The vertices must exist in the graph
*/
int graph_graph_add_edge(struct graph *graph, struct graph_edge *edge)
{
    if(graph == NULL)
    {
        perror("graph_graph_add_edge: graph is NULL");
        return 0;
    }

    if(edge == NULL)
    {
        perror("graph_graph_add_edge: edge is NULL");
        return 0;
    }

    if (graph_find_edge_by_id(graph, edge->id) != NULL)
    {
        perror("graph_graph_add_edge: edge already exists");
        return 0;
    }

    if (graph_find_vertice_by_id(graph, edge->start->id) == NULL)
    {
        perror("graph_graph_add_edge: start vertice does not exist");
        return 0;
    }

    if (graph_find_vertice_by_id(graph, edge->end->id) == NULL)
    {
        perror("graph_graph_add_edge: end vertice does not exist");
        return 0;
    }

    struct graph_edge **new_edges = (struct graph_edge**)realloc(graph->edges, sizeof(struct graph_edge*) * (graph->n_edges + 1));
    if(new_edges == NULL)
    {
        perror("graph_graph_add_edge: realloc failed");
        return 0;
    }
    graph->edges = new_edges;
    graph->edges[graph->n_edges - 1] = edge;
    graph->n_edges++;
    return 1;
}

/**
 * @brief Remove a vertice from a graph
 * @param graph The graph to remove the vertice from
 * @param id The id of the vertice to remove
 * @return 1 if success, 0 otherwise
 * @note this does not handle the vertice memory
*/
int graph_graph_remove_vertice_by_id(struct graph *graph, int id)
{
    if(graph == NULL)
    {
        perror("graph_graph_remove_vertice_by_id: graph is NULL");
        return 0;
    }
    if(graph->vertices == NULL)
    {
        perror("graph_graph_remove_vertice_by_id: graph->vertices is NULL");
        return 0;
    }
    for(size_t i = 0; i < graph->n_vertices; i++)
    {
        if(graph->vertices[i]->id == id)
        {
            free(graph->vertices[i]);
            for(size_t j = i; j < graph->n_vertices - 1; j++)
            {
                graph->vertices[j] = graph->vertices[j + 1];
            }
            graph->vertices[graph->n_vertices] = NULL;
            graph->n_vertices--; //realloc will be done when we add a new vertice
            return 1;
        }
    }
}

/**
 * @brief Remove an edge from a graph
 * @param graph The graph to remove the edge from
 * @param id The id of the edge to remove
 * @return 1 if success, 0 otherwise
 * @note this does not handle the edge memory
*/
int graph_graph_remove_edge_by_id(struct graph *graph, int id)
{
    if(graph == NULL)
    {
        perror("graph_graph_remove_edge_by_id: graph is NULL");
        return 0;
    }
    if(graph->edges == NULL)
    {
        perror("graph_graph_remove_edge_by_id: graph->edges is NULL");
        return 0;
    }
    for(size_t i = 0; i < graph->n_edges; i++)
    {
        if(graph->edges[i]->id == id)
        {
            free(graph->edges[i]);
            for(size_t j = i; j < graph->n_edges - 1; j++)
            {
                graph->edges[j] = graph->edges[j + 1];
            }
            graph->edges[graph->n_edges] = NULL;
            graph->n_edges--; //realloc will be done when we add a new edge
            return 1;
        }
    }
}

/**
 * @brief Find an edge in a graph by its id
 * @param graph The graph to search in
 * @param id The id of the edge to find
 * @return The edge if found, NULL otherwise
*/
struct graph_edge *graph_find_edge_by_id(struct graph *graph, int id)
{
    if(graph == NULL)
    {
        perror("graph_find_edge_by_id: graph is NULL");
        return NULL;
    }

    if(graph->edges == NULL)
    {
        perror("graph_find_edge_by_id: graph->edges is NULL");
        return NULL;
    }

    for(size_t i = 0; i < graph->n_edges; i++)
    {
        if(graph->edges[i]->id == id)
        {
            return graph->edges[i];
        }
    }
    return NULL;
}

/**
 * @brief Find a vertice in a graph by its id
 * @param graph The graph to search in
 * @param id The id of the vertice to find
 * @return The vertice if found, NULL otherwise
*/
struct graph_vertice *graph_find_vertice_by_id(struct graph *graph, int id)
{
    if(graph == NULL)
    {
        perror("graph_find_vertice_by_id: graph is NULL");
        return NULL;
    }

    if(graph->vertices == NULL)
    {
        perror("graph_find_vertice_by_id: graph->vertices is NULL");
        return NULL;
    }

    for(size_t i = 0; i < graph->n_vertices; i++)
    {
        if(graph->vertices[i]->id == id)
        {
            return graph->vertices[i];
        }
    }
    return NULL;
}

/**
 * @brief Print a graph
 * @param graph The graph to print
 * @param func_print_data The function to print the data of a vertice
 * @note The function must be able to print the data of a vertice
*/
void graph_graph_print(struct graph *graph, graph_vertice_printer func_print_data)
{
    if(graph == NULL)
    {
        perror("graph_graph_print: graph is NULL");
        return;
    }
    printf("Graph {\n");
    printf("\tVertices: %zu\n", graph->n_vertices);
    printf("\tEdges: %zu\n", graph->n_edges);
    if(graph->n_vertices != 0)
    {
        printf("Vertices:\n");
        for(size_t i = 0; i < graph->n_vertices; i++)
        {
            graph_vertice_print(graph->vertices[i], func_print_data);
        }
    }
    if(graph->n_edges != 0)
    {
        printf("Edges:\n");
        for(size_t i = 0; i < graph->n_edges; i++)
        {
            graph_edge_print(graph->edges[i]);
        }
    }
    printf("}\n");
}