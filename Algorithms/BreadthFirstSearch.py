from collections import deque

def breadthFirstSearch(graph, s, t):
    visited = [False for i in graph]
    visited[s] = True
    queue = deque()

    queue.append(s)

    while len(queue) > 0:
        cur = queue.popleft()
        for vertex, hasEdge in enumerate(graph[cur]):
            if hasEdge and not visited[vertex]:
                if vertex == t:
                    return True
                queue.append(vertex)
                visited[vertex] = True
    return False


graph = [[0,1,0,0],
         [1,0,1,0],
         [0,1,0,0],
         [0,0,0,0]]

# True
print(breadthFirstSearch(graph, 0, 2))
# False
print(breadthFirstSearch(graph, 0, 3))
