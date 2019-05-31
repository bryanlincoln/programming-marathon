n = int(input())
while n > 0:
    n -= 1
    pq = input()
    p, q = pq.split()
    p, q = int(p), int(q)
    erdos = {}
    for i in range(p):
        paper = input()
        authors = paper.split(":")[0].split("., ")

        print(authors)