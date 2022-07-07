#include<string.h>
#include<stdio.h>
#include<stdlib.h>
int bx,by,dx,dy;
int ok[30][30],v[30][30],cnt[30][30];
int count1,count2;

//判断当前的坐标是否合法
int valid(int x,int y){
    return(x<30 && y< 30);
}
//判断(x1,y1)与(x2,y2)是否重合
int equal(int x1, int y1, int x2, int y2) {
    return (x1 == x2) && (y1 == y2);
}

//判断当前(x,y)是否在马(bx,by)的攻击范围之内 将不可以蹩马腿同时(x,y)在马的攻击范围内，\
都可以收到攻击 有8个方向可以进行攻击
int attack(int x, int y) {
    return (!equal(bx + 1, by, dx, dy) && equal(bx + 2, by + 1, x, y)) ||
           (!equal(bx, by + 1, dx, dy) && equal(bx + 1, by + 2, x, y)) ||
           (!equal(bx - 1, by, dx, dy) && equal(bx - 2, by - 1, x, y)) ||
           (!equal(bx, by - 1, dx, dy) && equal(bx - 1, by - 2, x, y)) ||
           (!equal(bx, by - 1, dx, dy) && equal(bx + 1, by - 2, x, y)) ||
           (!equal(bx + 1, by, dx, dy) && equal(bx + 2, by - 1, x, y)) ||
           (!equal(bx - 1, by, dx, dy) && equal(bx - 2, by + 1, x, y)) ||
           (!equal(bx, by + 1, dx, dy) && equal(bx - 1, by + 2, x, y));
}

int finish(int x,int y){
    return(x==dx && y==dy);
}

//计算当前坐标(x,y)可以走到的所有地方，在数组中保存
void calc(int cx,int cy,int nx[],int ny[])
{
        count1 =0;
        count2 =0;
        if (!(equal(cx + 1, cy, bx, by)) && !(equal(cx + 1, cy, dx, dy)) && valid(cx + 2, cy + 1)) {
        nx[count1++]=cx+2;
        ny[count2++]=cy+1;
        // nx.push_back(cx + 2);
        // ny.push_back(cy + 1);
    }
    // 竖着走
    if (!(equal(cx, cy + 1, bx, by)) && !(equal(cx, cy + 1, dx, dy)) && valid(cx + 1, cy + 2)) {
        nx[count1++]=cx+1;
        ny[count2++]=cy+2;
        // nx.push_back(cx + 1);
        // ny.push_back(cy + 2);
    }
}

int dfs(int x,int y)
{
    if(x>30 || y>30) return 0;
    if(attack(x,y)) return 0;
    if(finish(x,y)) return 1;
    if (v[x][y]) return cnt[x][y];
    int nx[40];
    int ny[40];
    memset(nx,0,sizeof(nx));
    memset(ny,0,sizeof(ny));
    calc(x,y,nx,ny);
    int ans = 0;
    for (int i = 0; i < count1; i++) {
        ans += dfs(nx[i], ny[i]);
    }
    v[x][y] = 1;
    return cnt[x][y] = ans;

}

int main() 
{
    printf("请输入A 的马和将的坐标 bx, by 和 dx, dy\n");    
    scanf("%d %d %d %d",&bx,&by,&dx,&dy);
    //假设可以进行横着走t1次数，竖着走t2次数。
    printf("%d\n",dfs(0,0));


}