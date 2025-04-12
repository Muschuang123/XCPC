#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const int N = 1000 + 10;
const int maxn = 5e6 + 10;
const int inf = 0x3f3f3f3f;

int e[maxn], l[maxn], r[maxn];
int idx;

void init() // 初始化
{
    // 0 表示左端点，1 表示右端点
    r[0] = 1; // 0 号点的右边是 1 号点
    l[1] = 0; // 1 号点的左边是 0 号点
    idx = 2;  // 下标为 0 和 1 的结点被占用了;这两个点是链表的边界，不是真实的结点
}

void add(int k, int x) // 在下标为 k 的结点的右边插入结点 x
{
    e[idx] = x;
    r[idx] = r[k];
    l[idx] = k;

    l[r[k]] = idx; // ( 1 )
    r[k] = idx;    // ( 2 )
    // ( 1 )( 2 ) 代码前后顺序不能改变
    idx++;
}

void remove(int k) // 删除下标为 k 的结点
{
    r[l[k]] = r[k]; // 调整该结点前后两个结点的指针
    l[r[k]] = l[k];
}

int main()
{
    init(); // 不要忘了初始化

    int m;
    scanf("%d", &m);

    while (m--)
    {
        int k, x;
        string op;
        cin >> op;
        if (op == "L")
        {
            cin >> x;
            add(0, x);
        }
        else if (op == "R")
        {
            cin >> x;
            add(l[1], x);
        }
        else if (op == "D")
        {
            cin >> k;
            remove(k + 1); // 注意下标的转换
        }
        else if (op == "IL")
        {
            cin >> k >> x;
            add(l[k + 1], x); // 注意下标的转换
        }
        else if (op == "IR")
        {
            cin >> k >> x;
            add(k + 1, x); // 注意下标的转换
        }
    }

    for (int i = r[0]; i != 1; i = r[i])
        cout << e[i] << " ";
    // 注意与单链表不同 i 的初始值是第一个结点的下标 链表的终止条件是 NULL 结点的下标 1  下一个 i 是下一个结点的下标
    cout << endl;
    return 0;
}