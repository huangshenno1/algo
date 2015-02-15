/*
 * Treap指针-小根堆实现样例程序 for 数算实习
 * AUTH: Nettle
 * DATE: 2012.11.7
 */
 
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;
 
class cTreap {
	/*
	 * 指针实现Treap
	 * weight采用小根堆的方式维护
	 */
private:
	struct sNode {																		// Treap节点
		int data;																		// data域
		int weight;																		// weight域
		sNode *lch, *rch;																// 左右儿子的指针
		sNode(int key):data(key), weight(rand()) {										// 构造函数初始化
			lch = rch = NULL;
		}
	};
	typedef sNode* pNode;																// 定义指针类型
 
	pNode root;																			// 根指针
 
	void leftRotate(pNode &rt) {														// 左旋
		pNode p = rt -> lch;
		rt -> lch = p -> rch;
		p -> rch = rt;
		rt = p;
		return ;
	}
 
	void rightRotate(pNode &rt) {														// 右旋
		pNode p = rt -> rch;
		rt -> rch = p -> lch;
		p -> lch = rt;
		rt = p;
		return ;
	}
 
	void removeAll(pNode &rt) {															// 删除所有节点
		if (!rt) return ;
		removeAll(rt -> lch);
		removeAll(rt -> rch);
		delete rt;
		rt = NULL;
		return ;
	}
 
	void insert(const int key, pNode &rt) {												// 递归插入节点
		if (!rt) {																		// 如果当前节点为空的叶子节点
			rt = new sNode(key);
			return ;
		}
		if (key < rt -> data) {															// 插入值小于当前值，插入左子树
			insert(key, rt -> lch);
			if (rt -> lch -> weight < rt -> weight)										// 维护weight域
				leftRotate( rt );
		}	else {																		// 插入值大于等于当前值，插入右子树
			insert(key, rt -> rch);
			if (rt -> rch -> weight < rt -> weight)										// 维护weight域
				rightRotate( rt );
		}
		return ;
	}
 
	void remove(const int key, pNode &rt) {
		if (!rt) return ;																// 如果访问到空节点，删除值不存在
		if (rt -> data == key) {														// 当前值为删除值
			if (!rt -> lch && !rt -> rch) {												// 没有儿子，直接删除
				delete rt;
				rt = NULL;
				return ;
			}	
			if (!rt -> rch) {															// 只有左儿子，将左儿子旋转到当前位置
				leftRotate( rt );
				remove(key, rt -> rch);													// 继续递归删除
				return ;
			}
			if (!rt -> lch) {															// 只有右儿子，将右儿子旋转到当前位置
				rightRotate( rt );
				remove(key, rt -> lch);                                                 // 继续递归删除
				return ;
			}
			if (rt -> lch -> weight < rt -> rch -> weight) {							// 两个儿子都存在，选择权值小的一个
				leftRotate( rt );
				remove(key, rt -> rch);
			}	else {
				rightRotate( rt );
				remove(key, rt -> lch);
			}
			return ;
		}
		if (key < rt -> data) remove(key, rt -> lch);									// 若当前值不等于删除值，根据删除值查找子树
			else remove(key, rt -> rch);
		return ;
	}
 
	bool quary(const int key, pNode rt) {												// 查询key值是否在Treap中
		if (!rt) return false;															// 查找到空叶子节点，key不存在于Treap
		if (rt -> data == key) return true;												// 查找到目标值
		if (rt -> data < key) return quary(key, rt -> lch);								// 根据当前值继续二分查找
			else return quary(key, rt -> rch);
	}
 
	void print(pNode rt) {																// 使用括号表示法递归打印当前树
		if (!rt) return ;
		cout << "[";
		print(rt -> lch);
		cout << rt -> data << ':' << rt -> weight;
		print(rt -> rch);
		cout << "]";
		return ;
	}
 
public:
	cTreap():root(NULL) {																// 构造函数，初始化随机器
		srand(time(NULL));
	}
	~cTreap() {																			// 析构函数
		removeAll( root );
	}
 
	void insert(const int key) {														// 插入key值
		insert(key, root);
		return ;
	}
 
	void remove(const int key) {														// 删除key值
		remove(key, root);
		return ;
	}
 
	bool quary(const int key) {															// 查询key值
		return quary(key, root);
	}
 
	void print() {																		// 打印Treap
		if (root) print(root);
		else cout << "Empty treap";
		cout << endl;
		return ;
	}
};
 
int main() {
	/*
	 * Treap样例程序
	 * 5种指令：
	 * +-----+-----------------------------------+
	 * | 格式| 含义                              |
	 * +-----+-----------------------------------+
	 * | I x | 向Treap中插入x                    |
	 * | D x | 删除Treap中的x(有多个x只删除一个) |
	 * | Q x | 查询x是否在Treap中                |
	 * | P	 | 括号表示法打印Treap               |
	 * | E	 | 退出程序                          |
	 * +-----+-----------------------------------+
	 */
	cTreap *myTreap = new cTreap;
	string cmd;																			// 指令
	int key;																			// key值
	do {
		cin >> cmd;
		switch (cmd[0]) {
		case 'I':
			cin >> key;
			myTreap -> insert(key);
			break;
		case 'D':
			cin >> key;
			myTreap -> remove(key);
			break;
		case 'Q':
			cin >> key;
			if (myTreap -> quary(key)) cout << 'T' << endl;
			else cout << 'F' << endl;
			break;
		case 'P':
			myTreap -> print();
			break;
		case 'E':
			return 0;
		}
	}	while (true);
	delete myTreap;
    return 0;
}