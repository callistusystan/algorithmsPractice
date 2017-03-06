def depthFirstSearchIterative(graph, s, t):
    visited = [False for _ in graph]
    stack = [s]
    visited[s] = True

    while len(stack) > 0:
        cur = stack.pop()
        for vertex, hasEdge in enumerate(graph[cur]):
            if hasEdge and not visited[vertex]:
                if vertex == t:
                    return True
                visited[vertex] = True
                stack.append(vertex)
    return False

def depthFirstSearchRecursive(graph, s, t, visited = None):
    if visited is None:
        visited = [False for _ in graph]

    visited[s] = True
    if s == t:
        return True

    for vertex, hasEdge in enumerate(graph[s]):
        if hasEdge and not visited[vertex]:
            if depthFirstSearchRecursive(graph, vertex, t, visited):
                return True
    return False

graph = [[0,1,0,0],
         [1,0,1,0],
         [0,1,0,0],
         [0,0,0,0]]

# True
print(depthFirstSearchIterative(graph, 0, 2))
# False
print(depthFirstSearchIterative(graph, 0, 3))

# True
print(depthFirstSearchRecursive(graph, 0, 2))
# False
print(depthFirstSearchRecursive(graph, 0, 3))