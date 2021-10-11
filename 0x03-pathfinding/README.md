# Pathfinding
### Contains pathfinding algorithms like Dijkstra's shortest path and A* to get shortest path
## 0. Backtracking - Array
Write a function that searches for the first path from a starting point to a target point within a two-dimensional array.

    Prototype: queue_t *backtracking_array(char **map, int rows, int cols, point_t const *start, point_t const *target);
    Where:
        map is the pointer to a read-only two-dimensional array
            A 0 represents a walkable cell
            A 1 represents a blocked cell
        rows and cols are respectively the number of rows and columns of map
        start stores the coordinates of the starting point
        target stores the coordinates of the target point
    Your function must return a queue, in which each node is a point in the path from start to target (See example)
    You’ll have to use recursive backtracking to find the first working path from start to target
    For each visited cell, you’ll have to explore neighbour cells in the following order:
        RIGHT
        BOTTOM
        LEFT
        TOP
    You’ll have to print each visited cell as in the example below
