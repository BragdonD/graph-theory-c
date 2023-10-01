#include <stdlib.h>
#include <stdio.h>
#include "core/edge.h"
#include "core/vertice.h"

/**
 * @brief Create a graph graph_edge
 * @param id The id of the graph_edge
 * @param start The start node of the graph_edge
 * @param end The end node of the graph_edge
 * @param direction The direction of the graph_edge
 * @param weight The weight of the graph_edge
 * @param edge The graph_edge to create
 * @return 1 if success, 0 otherwise
 * @note The id must be positive
 * @note The start and end nodes must be valid
*/
int graph_edge_create(int id, struct graph_vertice *start, struct graph_vertice *end, enum graph_edge_direction direction, int weight, struct graph_edge *edge)
{
    if(edge != NULL)
    {
        perror("graph_edge_create: edge is not NULL");
        return 0;
    }

    if(id < 0)
    {
        perror("graph_edge_create: id is negative");
        return 0;
    }

    if (start == NULL)
    {
        perror("graph_edge_create: start is NULL");
        return 0;
    }

    if (end == NULL)
    {
        perror("graph_edge_create: end is NULL");
        return 0;
    }

    edge = (struct graph_edge*)malloc(sizeof(struct graph_edge));
    if(edge == NULL)
    {
        perror("graph_edge_create: malloc failed");
        return 0;
    }

    edge->id = id;
    edge->start = start;
    edge->end = end;
    edge->weight = weight;
    edge->direction = direction;

    return 1;
}

/**
 * @brief Destroy a graph graph_edge
 * @param edge The graph_edge to destroy
 * @return 1 if success, 0 otherwise
*/
int graph_edge_destroy(struct graph_edge *edge)
{
    if(edge == NULL)
    {
        perror("graph_edge_destroy: edge is NULL");
        return 0;
    }

    free(edge);
    return 1;
}

/**
 * @brief Set the id of a graph graph_edge
 * @param edge The graph_edge to set the id
 * @param id The id to set
 * @return 1 if success, 0 otherwise
*/
int graph_edge_set_id(struct graph_edge *edge, int id)
{
    if(edge == NULL)
    {
        perror("graph_edge_set_id: edge is NULL");
        return 0;
    }
    if(id < 0)
    {
        perror("graph_edge_set_id: id is negative");
        return 0;
    }

    edge->id = id;
    return 1;
}

/**
 * @brief Set the start node of a graph graph_edge
 * @param edge The graph_edge to set the start node
 * @param start The start node to set
 * @return 1 if success, 0 otherwise
 * @note The start node must be valid
*/
int graph_edge_set_start(struct graph_edge *edge, struct graph_vertice *start)
{
    if(edge == NULL)
    {
        perror("graph_edge_set_start: edge is NULL");
        return 0;
    }
    if(start == NULL)
    {
        perror("graph_edge_set_start: start is NULL");
        return 0;
    }

    edge->start = start;
    return 1;
}

/**
 * @brief Set the end node of a graph graph_edge
 * @param edge The graph_edge to set the end node
 * @param end The end node to set
 * @return 1 if success, 0 otherwise
 * @note The end node must be valid
*/
int graph_edge_set_end(struct graph_edge *edge, struct graph_vertice *end)
{
    if(edge == NULL)
    {
        perror("graph_edge_set_end: edge is NULL");
        return 0;
    }
    if(end == NULL)
    {
        perror("graph_edge_set_end: end is NULL");
        return 0;
    }

    edge->end = end;
    return 1;
}

/**
 * @brief Set the weight of a graph graph_edge
 * @param edge The graph_edge to set the weight
 * @param weight The weight to set
 * @return 1 if success, 0 otherwise
 * @note The weight must be positive
*/
int graph_edge_set_weight(struct graph_edge *edge, int weight)
{
    if(edge == NULL)
    {
        perror("graph_edge_set_weight: edge is NULL");
        return 0;
    }
    if(weight < 0)
    {
        perror("graph_edge_set_weight: weight is negative");
        return 0;
    }

    edge->weight = weight;
    return 1;
}

/**
 * @brief Set the direction of a graph graph_edge
 * @param edge The graph_edge to set the direction
 * @param direction The direction to set
 * @return 1 if success, 0 otherwise
*/
int graph_edge_set_direction(struct graph_edge *edge, enum graph_edge_direction direction)
{
    if(edge == NULL)
    {
        perror("graph_edge_set_direction: edge is NULL");
        return 0;
    }

    edge->direction = direction;
    return 1;
}

/**
 * @brief Print a graph graph_edge
 * @param edge The graph_edge to print
*/
void graph_edge_print(struct graph_edge *edge)
{
    if(edge == NULL)
    {
        perror("graph_edge_print: edge is NULL");
        return;
    }

    printf("Edge {\n");
    printf("\tId: %d\n", edge->id);
    printf("\tStart: %d\n", edge->start->id);
    printf("\tEnd: %d\n", edge->end->id);
    printf("\tWeight: %d\n", edge->weight);
    printf("\tDirection: %d\n", edge->direction);
    printf("}\n");
}
