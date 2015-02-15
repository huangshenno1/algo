//Ïß¶ÎÊ÷_Çø¼ä

int val[maxn*4], lazy[maxn*4];  

void update(int x, int rt, int L, int R)  
{  
    lazy[rt] = x;  
    val[rt] = x;  
}  
  
void query(int ql, int qr, int x, int rt = 1, int L = 1, int R = tot)  
{  
    if (ql <= L && R <= qr)  
    {  
        update(x, rt, L, R);  
        return;  
    }  
    int M = (L+R) >> 1;  
    if (lazy[rt])  
    {  
        update(lazy[rt], lhs, L, M);  
        update(lazy[rt], rhs, M+1, R);  
        lazy[rt] = 0;  
    }  
    if (ql <= M) query(ql, qr, x, lhs, L, M);  
    if (qr > M) query(ql, qr, x, rhs, M+1, R);  
}  
  
void init(int rt = 1, int L = 1, int R = tot)  
{  
    val[rt] = 0; lazy[rt] = 0;  
    if (L == R) return;  
    int M = (L+R) >> 1;  
    init(lhs, L, M);  
    init(rhs, M+1, R);  
} 