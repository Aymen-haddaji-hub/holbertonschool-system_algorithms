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
	new = malloc(sizeof(vertex_t));
	if (!new)
		return (NULL);
	new->content = strdup(str);
	if (!new->content)
	{
		free(new);
		return (NULL);
	}
	new->index = graph->nb_vertices++;
	if (tmp)
		tmp->next = new;
	else
		graph->vertices = new;
	return (new);
}
