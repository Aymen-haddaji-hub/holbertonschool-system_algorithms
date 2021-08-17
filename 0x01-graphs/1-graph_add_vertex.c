#include "graphs.h"

/**
 * graph_add_vertex - Adds a new vertex to a graph
 * @graph: Graph
 * @str: New vertes str
 * Return: a vertex pointer on succes or NULL
 */

vertex_t *graph_add_vertex(graph_t *graph, const char *str)
{
	vertex_t *new = NULL, *tmp = NULL;

	if (!str || !graph)
		return (NULL);
	tmp = graph->vertices;
	while (tmp)
	{
		if (!strcmp(tmp->content, str))
			return (NULL);
		if (!tmp->next)
			break;
		tmp = tmp->next;
	}
	new = malloc(sizeof(*tmp));
	if (!new)
		return (NULL);
	new->content = strdup(str);
	new->index = 0;
	new->edges = NULL;
	new->nb_edges = 0;
	new->next = NULL;
	if (!tmp)
	{
		new->index = 0;
		graph->vertices = new;
	}
	else
	{
		new->index = tmp->index + 1;
		tmp->next = new;
	}
	graph->nb_vertices++;
	return (new);
}
