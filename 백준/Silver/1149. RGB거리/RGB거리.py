n = int(input())
costs = []

for _ in range(n):
    r, g, b = map(int, input().split())
    costs.append((r, g, b))

dp = [[0] * 3 for _ in range(n)]
dp[0] = costs[0]

R, G, B= 0,1,2

for i in range(1, n):
    dp[i][R] = min(dp[i - 1][G], dp[i - 1][B]) + costs[i][0]
    dp[i][G] = min(dp[i - 1][R], dp[i - 1][B]) + costs[i][1]
    dp[i][B] = min(dp[i - 1][R], dp[i - 1][G]) + costs[i][2]

result = min(dp[n-1])
print(result)