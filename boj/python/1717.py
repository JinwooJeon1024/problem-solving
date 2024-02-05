def find(x):
    if x == parent[x]:
        return x
    parent[x] = find(parent[x])
    return parent[x]

def union(x, y):
    x = find(x)
    y = find(y)
    if x == y:
        return
    if x < y:
        parent[y] = x
    else:
        parent[x] = y

def solve(k, a, b):
    if k == 0:
        union(a, b)
    else:
        if a == b or find(a) == find(b):
            print("YES")
        else:
            print("NO")

n, m = map(int, input().split())
parent = [i for i in range(n + 1)]

for _ in range(m):
    k, a, b = map(int, input().split())
    solve(k, a, b)
