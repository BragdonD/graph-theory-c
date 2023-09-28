#include <stdio.h>
#include "core/vertice.h"

/**
 * @brief Create a graph vertice
 * @param id The id of the vertice
 * @param data The data of the vertice
 * @param weight The weight of the vertice
 * @param vertice The vertice to create
 * @return 1 if success, 0 otherwise
 * @note The id must be positive
*/
int graph_vertice_create(int id, graph_vertice_data data, int weight, struct graph_vertice* vertice)
{
    if (vertice != NULL) 
    {
        perror("graph_vertice_create: vertice is not NULL");
        return 0;
    }

    // Check the data
    if (id < 0)
    {
        perror("graph_vertice_create: id is negative");
        return 0;
    }

    vertice = (struct graph_vertice*)malloc(sizeof(struct graph_vertice));
    if (vertice == NULL)
    {
        perror("graph_vertice_create: malloc failed");
        return 0;
    }

    vertice->id = id;
    vertice->data = data;
    vertice->weight = weight;
    return 1;
}

/**
 * @brief Destroy a graph vertice
 * @param vertice The vertice to destroy
 * @return 1 if success, 0 otherwise
 * @note The data is not freed
*/
int graph_vertice_destroy(struct graph_vertice* vertice)
{
    if (vertice == NULL)
    {
        perror("graph_vertice_destroy: vertice is NULL");
        return 0;
    }

    free(vertice);
    return 1;
}

/**
 * @brief Set the id of a graph vertice
 * @param vertice The vertice to set the id
 * @param id The id to set
 * @return 1 if success, 0 otherwise
 * @note The id must be positive
*/
int graph_vertice_set_id(struct graph_vertice* vertice, int id)
{
    if (vertice == NULL)
    {
        perror("graph_vertice_set_id: vertice is NULL");
        return 0;
    }

    if (id < 0)
    {
        perror("graph_vertice_set_id: id is negative");
        return 0;
    }

    vertice->id = id;
    return 1;
}

/**
 * @brief Set the data of a graph vertice
 * @param vertice The vertice to set the data
 * @param data The data to set
 * @return 1 if success, 0 otherwise
*/
int graph_vertice_set_data(struct graph_vertice* vertice, graph_vertice_data data)
{
    if (vertice == NULL)
    {
        perror("graph_vertice_set_data: vertice is NULL");
        return 0;
    }

    vertice->data = data;
    return 1;
}

/**
 * @brief Set the weight of a graph vertice
 * @param vertice The vertice to set the weight
 * @param weight The weight to set
 * @return 1 if success, 0 otherwise
*/
int graph_vertice_set_weight(struct graph_vertice* vertice, int weight)
{
    if (vertice == NULL)
    {
        perror("graph_vertice_set_weight: vertice is NULL");
        return 0;
    }

    vertice->weight = weight;
    return 1;
}