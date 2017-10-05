while True:
    N = int(input())
    if N == 0:
        break
    isPrinted = [False]*(N+5)

    line = input().split(",")

    for r in line:
        if '-' in r:
            L_R = r.split('-')
            L = int(L_R[0])
            R = int(L_R[1])
            if L > R:
                continue
            else:
                for i in range(L,min(N,R)+1):
                    isPrinted[i] = True
        else:
            L = int(r)
            if L <= N:
                isPrinted[L] = True

    ans = 0
    for i in range(1,N+1):
        if isPrinted[i]:
            ans += 1

    print(ans)
