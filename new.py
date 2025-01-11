def dfs(room, graph, visited, result):
    # Mark the current room as visited
    visited[room] = True
    
    # Initialize counts for paths and neighbors
    path_count = 0
    neighbor_count = 0
    
    # Iterate through neighbors of the current room
    for neighbor in graph[room]:
        # If the neighbor is Room 1 (self-loop), increase path count
        if neighbor == 1:
            path_count += 1
        # If the neighbor is unvisited, perform DFS
        elif not visited[neighbor]:
            neighbor_count += 1
            path, neighbor = dfs(neighbor, graph, visited, result)
            path_count += path
            neighbor_count += neighbor
    
    # If there's a cycle, mark the room as having infinite paths
    if neighbor_count > 1:
        result[room] = -1
    # If there's only one neighbor or no neighbors, mark the room with appropriate path count
    elif neighbor_count == 0 or path_count == 0:
        result[room] = 0
    elif path_count == 1:
        result[room] = 1
    else:
        result[room] = 2
    
    # Return the path count and neighbor count for parent DFS call
    return path_count, neighbor_count

def count_paths(T, test_cases):
    for t in range(T):
        N, M = test_cases[t]['N'], test_cases[t]['M']
        graph = {i: [] for i in range(1, N + 1)}
        
        # Construct the graph
        for _ in range(M):
            Xi, Yi = test_cases[t]['connections'][_]
            graph[Xi].append(Yi)
        
        # Initialize result list and visited array
        result = [0] * (N + 1)
        visited = [False] * (N + 1)
        
        # Perform DFS from Room 1
        dfs(1, graph, visited, result)
        
        # Output the result for this test case
        print(" ".join(map(str, result[1:])))

# Input reading
T = int(input())
test_cases = []
for _ in range(T):
    N, M = map(int, input().split())
    connections = [tuple(map(int, input().split())) for _ in range(M)]
    test_cases.append({'N': N, 'M': M, 'connections': connections})

# Call the function to count paths and output results
count_paths(T, test_cases)
