/*
 * Treapָ��-С����ʵ���������� for ����ʵϰ
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
	 * ָ��ʵ��Treap
	 * weight����С���ѵķ�ʽά��
	 */
private:
	struct sNode {																		// Treap�ڵ�
		int data;																		// data��
		int weight;																		// weight��
		sNode *lch, *rch;																// ���Ҷ��ӵ�ָ��
		sNode(int key):data(key), weight(rand()) {										// ���캯����ʼ��
			lch = rch = NULL;
		}
	};
	typedef sNode* pNode;																// ����ָ������
 
	pNode root;																			// ��ָ��
 
	void leftRotate(pNode &rt) {														// ����
		pNode p = rt -> lch;
		rt -> lch = p -> rch;
		p -> rch = rt;
		rt = p;
		return ;
	}
 
	void rightRotate(pNode &rt) {														// ����
		pNode p = rt -> rch;
		rt -> rch = p -> lch;
		p -> lch = rt;
		rt = p;
		return ;
	}
 
	void removeAll(pNode &rt) {															// ɾ�����нڵ�
		if (!rt) return ;
		removeAll(rt -> lch);
		removeAll(rt -> rch);
		delete rt;
		rt = NULL;
		return ;
	}
 
	void insert(const int key, pNode &rt) {												// �ݹ����ڵ�
		if (!rt) {																		// �����ǰ�ڵ�Ϊ�յ�Ҷ�ӽڵ�
			rt = new sNode(key);
			return ;
		}
		if (key < rt -> data) {															// ����ֵС�ڵ�ǰֵ������������
			insert(key, rt -> lch);
			if (rt -> lch -> weight < rt -> weight)										// ά��weight��
				leftRotate( rt );
		}	else {																		// ����ֵ���ڵ��ڵ�ǰֵ������������
			insert(key, rt -> rch);
			if (rt -> rch -> weight < rt -> weight)										// ά��weight��
				rightRotate( rt );
		}
		return ;
	}
 
	void remove(const int key, pNode &rt) {
		if (!rt) return ;																// ������ʵ��սڵ㣬ɾ��ֵ������
		if (rt -> data == key) {														// ��ǰֵΪɾ��ֵ
			if (!rt -> lch && !rt -> rch) {												// û�ж��ӣ�ֱ��ɾ��
				delete rt;
				rt = NULL;
				return ;
			}	
			if (!rt -> rch) {															// ֻ������ӣ����������ת����ǰλ��
				leftRotate( rt );
				remove(key, rt -> rch);													// �����ݹ�ɾ��
				return ;
			}
			if (!rt -> lch) {															// ֻ���Ҷ��ӣ����Ҷ�����ת����ǰλ��
				rightRotate( rt );
				remove(key, rt -> lch);                                                 // �����ݹ�ɾ��
				return ;
			}
			if (rt -> lch -> weight < rt -> rch -> weight) {							// �������Ӷ����ڣ�ѡ��ȨֵС��һ��
				leftRotate( rt );
				remove(key, rt -> rch);
			}	else {
				rightRotate( rt );
				remove(key, rt -> lch);
			}
			return ;
		}
		if (key < rt -> data) remove(key, rt -> lch);									// ����ǰֵ������ɾ��ֵ������ɾ��ֵ��������
			else remove(key, rt -> rch);
		return ;
	}
 
	bool quary(const int key, pNode rt) {												// ��ѯkeyֵ�Ƿ���Treap��
		if (!rt) return false;															// ���ҵ���Ҷ�ӽڵ㣬key��������Treap
		if (rt -> data == key) return true;												// ���ҵ�Ŀ��ֵ
		if (rt -> data < key) return quary(key, rt -> lch);								// ���ݵ�ǰֵ�������ֲ���
			else return quary(key, rt -> rch);
	}
 
	void print(pNode rt) {																// ʹ�����ű�ʾ���ݹ��ӡ��ǰ��
		if (!rt) return ;
		cout << "[";
		print(rt -> lch);
		cout << rt -> data << ':' << rt -> weight;
		print(rt -> rch);
		cout << "]";
		return ;
	}
 
public:
	cTreap():root(NULL) {																// ���캯������ʼ�������
		srand(time(NULL));
	}
	~cTreap() {																			// ��������
		removeAll( root );
	}
 
	void insert(const int key) {														// ����keyֵ
		insert(key, root);
		return ;
	}
 
	void remove(const int key) {														// ɾ��keyֵ
		remove(key, root);
		return ;
	}
 
	bool quary(const int key) {															// ��ѯkeyֵ
		return quary(key, root);
	}
 
	void print() {																		// ��ӡTreap
		if (root) print(root);
		else cout << "Empty treap";
		cout << endl;
		return ;
	}
};
 
int main() {
	/*
	 * Treap��������
	 * 5��ָ�
	 * +-----+-----------------------------------+
	 * | ��ʽ| ����                              |
	 * +-----+-----------------------------------+
	 * | I x | ��Treap�в���x                    |
	 * | D x | ɾ��Treap�е�x(�ж��xֻɾ��һ��) |
	 * | Q x | ��ѯx�Ƿ���Treap��                |
	 * | P	 | ���ű�ʾ����ӡTreap               |
	 * | E	 | �˳�����                          |
	 * +-----+-----------------------------------+
	 */
	cTreap *myTreap = new cTreap;
	string cmd;																			// ָ��
	int key;																			// keyֵ
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