#include "graphs.h"

/**
 * init_edge - verify for connection between
 * source and destination.
 * @src: pointer to src vertex.
 * @dest: pointer to dest vertex.
 * Return: 1 if connection exist otherwise 0.
 **/

int init_edge(vertex_t *src, vertex_t *dest)
{
	edge_t *tmp;

	if (!src || !dest)
		return (0);

	tmp = src->edges;

	while (tmp)
	{
		if (tmp->dest == dest)
			return (0);

		tmp = tmp->next;
	}
	return (0);
}

/**
 * get_vertex - find the vertex that contain str.
 * @graph: pointer to graph
 * @str: pointer to string
 * Return: pointer to found vertex or NULL on failure
 **/

vertex_t *get_vertex(graph_t *graph, const char *str)
{
	vertex_t *tmp = NULL;

	if (!graph || !str)
		return (NULL);

	tmp = graph->vertices;

	while (tmp)
	{
		if (strcmp(tmp->content, str) == 0)
			return (tmp);
		tmp = tmp->next;
	}

	return (NULL);
}

/**
 * connect_edge - connect 2 vertices with new edge.
 * @src: pointer to src vertex
 * @dest: pointer to dest vertex
 * Return: returns 1 on success otherwise 0
 **/

int connect_edge(vertex_t *src, vertex_t *dest)
{
	edge_t *tmp, *new;

	if (!src || !dest)
		return (0);

	tmp = src->edges;

	new = NULL;

	while (tmp && tmp->next)
		tmp = tmp->next;

	new = malloc(sizeof(*new));

	if (!new)
		return (0);

	new->dest = dest;
	new->next = NULL;
	if (!src->edges)
	{
		src->edges = new;
		src->nb_edges += 1;
		return (1);
	}
	else
	{
		tmp->next = new;
		src->nb_edges += 1;
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
 * Return: returns 1 on success otheriwse 0
 */
int graph_add_edge(graph_t *graph,
				 const char *src,
				const char *dest,
				edge_type_t type)
{
	vertex_t *source, *destination;

	if (!graph || !src || !dest ||
			(type != UNIDIRECTIONAL && type != BIDIRECTIONAL))
		return (0);

	source = get_vertex(graph, src);
	destination = get_vertex(graph, dest);

	if (!source)
		return (0);

	if (!destination)
		return (0);

	if (type == BIDIRECTIONAL)
	{
		if (init_edge(source, destination) && init_edge(destination, source))
			return (1);

		if (!connect_edge(source, destination) && !connect_edge(destination, source))
			return (0);
	}
	else
	{
		if (init_edge(source, destination))
			return (1);

		if (!connect_edge(source, destination))
			return (0);
	}

	return (1);
}
