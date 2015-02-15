class treap
{
	struct Node
	{
	    Node *ch[2];
	    int r;
	    int v;
	    int s;
	    Node (int v):v(v) {ch[0] = ch[1] = NULL; r = rand(); s = 1;}
	    bool operator < (const Node &rhs) const {return r < rhs.r;}
	    int cmp(int x) const {if (x == v) return -1; return x < v ? 0 : 1;}
	    void maintain()
	    {
	        s = 1;
	        if (ch[0] != NULL) s += ch[0]->s;
	        if (ch[1] != NULL) s += ch[1]->s;
	    }
	};

	void rotate(Node* &o, int d)
	{
	    Node* k = o->ch[d^1]; o->ch[d^1] = k->ch[d]; k->ch[d] = o;
	    o->maintain(); k->maintain(); o = k;
	}

	void insert(Node* &o, int x)
	{
	    if (o == NULL) o = new Node(x);
	    else
	    {
	        int d = (x < o->v ? 0 : 1);
	        insert(o->ch[d], x);
	        if (o->ch[d] > o) rotate(o, d^1);
	    }
	    o->maintain();
	}

	void remove(Node* &o, int x)
	{
	    int d = o->cmp(x);
	    if (d == -1)
	    {
	        Node* u = o;
	        if (o->ch[0] != NULL && o->ch[1] != NULL)
	        {
	            int d2 = (o->ch[0] > o->ch[1] ? 1 : 0);
	            rotate(o, d2); remove(o->ch[d2], x);
	        }
	        else
	        {
	            if (o->ch[0] == NULL) o = o->ch[1];
	            else o = o->ch[0];
	            delete u;
	        }
	    }
	    else remove(o->ch[d], x);
	    if (o != NULL) o->maintain();
	}

	int kth(Node* o, int k)
	{
	    if (o == NULL || k <= 0 || k > o->s) return 0;
	    int s = (o->ch[1] == NULL ? 0 : o->ch[1]->s);
	    if (k == s+1) return o->v;
	    else if (k <= s) return kth(o->ch[1], k);
	    else return kth(o->ch[0], k-s-1);
	}

	void mergeto(Node* &src, Node* &des)
	{
	    if (src->ch[0] != NULL) mergeto(src->ch[0], des);
	    if (src->ch[1] != NULL) mergeto(src->ch[1], des);
	    insert(des, src->v);
	    delete src;
	    src = NULL;
	}

	void removetree(Node* &x)
	{
	    if (x->ch[0] != NULL) removetree(x->ch[0]);
	    if (x->ch[1] != NULL) removetree(x->ch[1]);
	    delete x;
	    x = NULL;
	}
}T;