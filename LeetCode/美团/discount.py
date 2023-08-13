def calculateMinimumPrice(n, menu, x, y):
    for k in menu:
        if(k[0]<k[1]):
            print("error")
            return 0
    sum=0
    for i in menu:
        sum+=i[0]
    discount=0
    for i in menu:
        discount+=i[1]
    result1=discount
    if(sum>=x):
        result2=sum-y
    else:
        result2=sum
    print(min(result1,result2))

# if __name__=="__main__":
# 示例输入
n = int(input())
menu = []
for _ in range(n):
    original_price, discount_price = map(float, input().split())
    menu.append((original_price, discount_price))
x, y = map(float, input().split())
# print(n)
# print(menu[0][0])
# print(menu[0][1])
# print(x)
# print(y)
minimum_price = calculateMinimumPrice(n, menu, int(x), int(y))
# print(minimum_price)
