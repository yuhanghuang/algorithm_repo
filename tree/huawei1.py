arr=list(map(int,input().split()))
limit = int(input())
# arr = [1,4,2,5,5,1,6]
# arr = [1,7,8,8,10,2,4,9]
# limit = 7

n = len(arr)
avrg = limit//n
#print(avrg)
sum1 = 0
n1=0
for i in arr:
    if i <= avrg:
        sum1+=i
        n1+=1
#print(sum1)
n2 = n-n1
#print(n2)
print((limit-sum1)//n2)