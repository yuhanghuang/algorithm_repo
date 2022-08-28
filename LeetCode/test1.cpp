/*f(x) 是 x! 末尾是 0 的数量。回想一下 x! = 1 * 2 * 3 * ... * x，且 0! = 1 。

例如， f(3) = 0 ，因为 3! = 6 的末尾没有 0 ；而 f(11) = 2 ，因为 11!= 39916800 末端有 2 个 0 。
给定 k，找出返回能满足 f(x) = k 的非负整数 x 的数量。
*/

class Solution {
public:
    int preimageSizeFZF(int k) {
        if (k<=1) return 5;
        // return f(k+1)-f(k);
        return f(k)-f(k-1);
    }

// 计算number的阶乘有多少个0
    long count_zero(long number){
        long count =0;
        while(number){
            count+=number/5;
            number = number/5;
        }
        return count;
    }

// 计算第一次出现number个0的数字为多少 10=5*2 每多一组5*2就会多一个0
// 在阶乘中每隔5个数就会多一个0
/*
f(1)=0;
f(2)=0;
f(3)=0;
f(4)=0;
f(5)=1;
f(6)=1;
f(7)=1;
f(8)=1;
f(9)=1;
f(10)=2;
*/
    int f(long number){
        long min =0;
        long max = 1e10;
        long mid;
        long temp;
        while (min <= max){
            mid = min + (max-min)/2;
            if(count_zero(mid)<=number){
                min = mid+1;
                temp = mid;
            }
            else{
                max = mid -1;
            }
        }
        return temp;

}
};