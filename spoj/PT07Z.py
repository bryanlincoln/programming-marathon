from collections import defaultdict

graph = defaultdict(set);

n = int(input())

for x in range(1, n):
    u = input()
    v = input()
    graph[u].add(v)

for x in graph:
    print(x + "=>" + x)