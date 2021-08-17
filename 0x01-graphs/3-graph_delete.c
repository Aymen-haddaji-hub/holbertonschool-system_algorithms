#include "graphs.h"

/**
 * graph_delete - A function that completely deletes a graph.
 * @graph: a pointer to the graph to be deleted.
 * Returns: Nothing (void)
 */

void graph_delete(graph_t *graph)
{
	vertex_t *new, *tmp;
	edge_t *edge, *edge_tmp;

	if (!graph)
		return;

	new = graph->vertices;
	while (new)
	{
		free(new->content);
		edge = new->edges;
		while (edge)
		{
			edge_tmp = edge;
			edge = edge->next;
			free(edge_tmp);
		}

		tmp = new;
		new = new->next;
		free(tmp);
	}

	free(graph);
}
