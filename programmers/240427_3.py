def solution(n, moves):
    answer = []
    pos = [n - i for i in range(n)]
    M = n
    m = 1
    for move in moves:
        if move > 0:
            M += 1
            pos[move - 1] = M
        else:
            m -= 1
            pos[- move - 1] = m
    t = [(card + 1, p) for card, p in enumerate(pos)]
    t.sort(key = lambda p: p[1])
    answer = [p[0] for p in t]
    return [answer[n - i - 1] for i in range(n)]