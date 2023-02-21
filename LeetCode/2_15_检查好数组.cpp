/*给你一个正整数数组 nums，你需要从中任选一些子集，然后将子集中每一个数乘以一个 任意整数，并求出他们的和。

假如该和结果为 1，那么原数组就是一个「好数组」，则返回 True；否则请返回 False
*/

/*
「裴蜀定理」的内容为:对于不全为零的任意整数a和b,记g= gcd(a,b),其中gcd(a,b)为a和b的最大公约数，则对于任意整数x和y都满足aXx+bxy是g的倍数,特别地，存在整数x和y满足aXx+bxy= g。

「裴蜀定理」也可以推广到多个整数的情况。对于不全为零的任意n个整数a1, a,...an,记这n个数的最大公约数为g,则对于任意n个整数x1,2x....xn都满足2n 1a;Xxi是g的倍数。一个重要的推论是:正
整数a1到an的最大公约数是1的充分必要条件是存在n个整数x1到xn满足2n_ 1q;Xxi= 1。
*/
class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int g=nums[0];
        for(int i=0;i<nums.size();i++)
        {
            g=gcd(g,nums[i]);
        }
        return g==1;
    }
}; 