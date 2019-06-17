while True:
    n, d = map(int, input().split(" "))
    if n == d == 0: break
    print(pow(n, d))