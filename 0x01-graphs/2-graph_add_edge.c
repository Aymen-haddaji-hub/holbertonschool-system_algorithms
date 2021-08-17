#include "graphs.h"

/**
 * init_edge - verify for connection between
 * source and destination.
 * @vertex_source: pointer to src vertex.
 * @vertex_destination: pointer to dest vertex.
 * Return: 1 if connection exist otherwise 0.
 **/


int init_edge(vertex_t *vertex_source, vertex_t *vertex_destination)
{
	edge_t *tmp = NULL;

	if (!vertex_source || vertex_destination)
		return (0);

	tmp = vertex_source->edges;

	while (tmp)
	{
		if (tmp->dest == vertex_destination)
			return (1);

		tmp = tmp->next;
	}

	return (0);
}

/**
 * get_vertex - find the vertex that contain str.
 * @graph: pointer to graph
 * @s: pointer to string
 * Return: pointer to found vertex or NULL on failure
 **/

vertex_t *get_vertex(graph_t *graph, const char *s)
{
	vertex_t *tmp;

	if (!graph || !s)
		return (NULL);

	tmp = graph->vertices;

	while (tmp)
	{
		if (strcmp(tmp->content, s) == 0)
			return (tmp);
		tmp = tmp->next;
	}

	return (NULL);
}

/**
 * connect_edge - connect 2 vertices with new edge.
 * @vertex_source: pointer to src vertex
 * @vertex_destination: pointer to dest vertex
 * Return: returns 1 on success otherwise 0
 **/

int connect_edge(vertex_t *vertex_source, vertex_t *vertex_destination)
{
	edge_t *tmp, *new;

	if (!vertex_source || !vertex_destination)
		return (0);

	tmp = vertex_source->edges;

	new = NULL;

	while (tmp && tmp->next)
		tmp = tmp->next;

	new = malloc(sizeof(*new));

	if (!new)
		return (0);

	new->dest = vertex_destination;
	new->next = NULL;

	if (!vertex_source->edges)
	{
		vertex_source->edges = new;
		vertex_source->nb_edges += 1;
		return (1);
	}
	else
	{
		tmp->next = new;
		vertex_source->nb_edges += 1;
		return (1);
	}

	return (0);
}

/**
 * graph_add_edge - adds an edge between two vertices to an existing graph
 * @graph: pointer to the graph to add the edge to
 * @src: string identifying the vertex to make the connection from
 * @dest: string identifying the vertex to connect to
 * @type: type of edge
 * Return: returns 1 on success or 0 in failure.
 */

int graph_add_edge(graph_t *graph, const char *src, const char *dest,
			 edge_type_t type)
{
	vertex_t *vertex_source, *vertex_destination;

	if (!graph || !src || !dest ||
		 (type != UNIDIRECTIONAL && type != BIDIRECTIONAL))
		return (0);

	vertex_source = get_vertex(graph, src);
	vertex_destination = get_vertex(graph, dest);

	if (type == BIDIRECTIONAL)
	{
		if (init_edge(vertex_source, vertex_destination)
			&& init_edge(vertex_destination, vertex_source))
			return (1);

		if (!connect_edge(vertex_source, vertex_destination))
			return (0);

		if (!connect_edge(vertex_destination, vertex_source))
			return (0);
	}
	else
	{
		if (init_edge(vertex_source, vertex_destination))
			return (1);

		if (!connect_edge(vertex_source, vertex_destination))
			return (0);
	}

	return (1);
}
