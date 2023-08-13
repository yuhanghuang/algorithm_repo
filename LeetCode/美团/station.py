def shortestDistance(n:int, a:list[int], x:int,y:int):
    dp = [0] *n
    dp[x-1] = 0
    result1=0
    result2=0
    for i in range(x-1,y-1):
        result1+=a[i]
    print(result1)
    for j in range(y-1,x-1+n):
        result2+=a[j]
    return min(result1,result2)
# 示例输入
n = 5
a =[2,3,4,5,1]
x=1
y=4
#输出最短距离
print(shortestDistance(n,a,x,y))
