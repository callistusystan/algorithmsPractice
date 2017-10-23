def fac(n):
    if n == 0 or n == 1:
        return 1
    return n * fac(n-1)

def solve(A, N, P):
    res = A**(fac(N))
    return res%P

T = int(input())

for t in range(T):
    A,N,P = [int(_) for _ in input().split()]
    print("Case #{}: {}".format(t+1, solve(A,N,P)))
