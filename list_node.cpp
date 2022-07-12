#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<stack>
#include<malloc.h>
using namespace std;
struct list_node
{
    /* data */
    int value;
    list_node *next;
};

// 方法1：只逆序打印，不改变结构。采用递归，到达尾结点时打印输出，\
否则进入下一个结点的递归，当递归一层层退出的时候，便可以实现从尾到头的打印。
// 逆序打印
void reverse_print(list_node *head)
{
    if(head!=NULL)
    {
        if (head->next!=NULL)
        {
            reverse_print(head->next);
            /* code */
        }
        cout<<head->value<<" ";
        
    }
}

// 方法2：头插法，改变结构。从第二个结点开始往后，依次把每\
个结点移至链表头部，要注意最后链表不要是断裂的。
list_node *reverse_List1(list_node *head){
    if (head==NULL)
    {
        /* code */
        return NULL;
    }
    list_node *p = head->next;
    list_node *newHead = head;
    while (p!=NULL)
    {
        /* code */
        head->next = p->next;
        p->next = newHead;
        newHead = p;
        p=head->next;
    }   
    return newHead;
}

// 方法3：改变指针方向。从头结点开始，依次把结点的next指针断\
开指向该结点的前结点。要注意保存好，前结点、当前结点和下一个结点。
list_node * reverse_List2(list_node *pHead){
    list_node *pre=NULL;
    list_node *p=NULL;
    while (pHead!=NULL)
    {
        /* code */
        p = pHead->next;
        pHead->next=pre;
        pre = pHead;//保存phead节点
        pHead=p;  //更新pHead节点
    }
    return pre;
}   
// 方法4：只逆序打印，不改变结构。利用栈的后进先出来实现逆序。
void reverse_List3(list_node *pHead)
{
    std::stack<list_node*> nodes;
    list_node *p=pHead;
    while (p!=  NULL)
    {
        /* code */
        nodes.push(p);
        p=p->next;
    }
    while (!nodes.empty())
    {
        /* code */
        p =nodes.top();
        cout<<p->value<<" ";
        nodes.pop();
    }
    cout<<endl;
    
}

int main(){
    int n;
    cin>>n;
    list_node* head = NULL;
    // list_node* s=new malloc(sizeof(list_node));
    list_node* p = NULL;
    list_node* q = NULL;
    for (int i = 0; i < n; i++)
    {
        /* code */
        q=new list_node;
        cin>>q->value;
        if (head==NULL)
        {
            /* code */
            head = q;
            p=head;
        }
        else{
            p->next=q;
            p =p->next;
        }
        
    }
    if (head==NULL)
    {
        /* code */
        return 0;
    }
    p->next=NULL;
    //head是第一个节点 不是头节点
    cout<<"递归逆序打印"<<endl;
    list_node * temp=new list_node;
    temp=head;
    reverse_print(head);
    cout<<endl<<"头插法反转链表"<<endl;
    list_node * reverse;
    reverse= reverse_List1(head);
    p = reverse;  //reverse是第一个节点，是有值的
    while (p!=NULL)
    {
        /* code */
        cout<<p->value<<" ";
        p=p->next;
    }
    cout<<endl<<"改变指针方向反转链表"<<endl;
    p = reverse_List2(reverse);
    while (p!=NULL)
    {
        /* code */
        cout<<p->value<<" ";
        // q=p;
        p=p->next;
        // delete q;

    }
    cout<<endl;
    cout<<"利用栈逆序输出"<<endl;
    reverse_List3(temp);
    return 0;
       
}