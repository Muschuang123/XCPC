// 一个元素的父亲元素 就是当前 山峰上最大的 / 当前山谷里最小的
// 左/右 孩子分别是 向 左/右 找 山谷中比它大的第一个 / 山峰上比它小的第一个
const int maxn = 1e7 + 7;
int stk[maxn], ls[maxn], rs[maxn];

// 0-index is invalid
void build(vector<i64> &w, int n) {
    int top = 0;
    for (int i = 1; i <= n; i++) {
        int k = top;                            // top 表示操作前的栈顶，k 表示当前栈顶
        while (k > 0 && w[stk[k]] > w[i]) k--;  // 维护右链上的节点
        if (k > 0) rs[stk[k]] = i;              // 栈顶元素.右儿子 := 当前元素
        if (k < top) ls[i] = stk[k + 1];        // 当前元素.左儿子 := 上一个被弹出的元素
        stk[++k] = i;                           // 当前元素入栈
        top = k;
    }
}