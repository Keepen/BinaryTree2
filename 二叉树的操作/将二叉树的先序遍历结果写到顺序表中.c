#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct TreeNode {
	char value;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;

//�������
TreeNode* createNode(char value) {
	TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
	root->value = value;
	root->left = NULL;
	root->right = NULL;
	return root;
}

//����������д��˳�����
char *arr;
int size;
TreeNode* preOrder(TreeNode* root) {
	if (root == NULL) {
		return NULL;
	}
	arr[size++] = root->value;
	preOrder(root->left);
	preOrder(root->right);
	return root;
}

//����һ�ö����������
int depthTree(TreeNode* root) {
	if (root == NULL) {
		return 0;
	}
	int left = depthTree(root->left);
	int right = depthTree(root->right);
	return (left > right ? left : right) + 1;
}


//�ж��������Ƿ�Ϊ����
bool isMirror(TreeNode* p,TreeNode* q) {
	//�Ƚ����п�
	//��������Ϊ���������ǻ�Ϊ����
	if (p == NULL && q == NULL) {
		return true;
	}
	//ֻ��һ�����ǿ�������Ȼ����Ϊ����
	if (p == NULL || q == NULL) {
		return false;
	}
	//һ����������������һ��������������ͬ����Ϊ����
	return p->value == q->value&&
		isMirror(p->left, q->right) &&
		isMirror(p->right, q->left);
}

//����������Ƿ�����ͬ����
bool isSame(TreeNode* p, TreeNode* q) {
	//�Ƚ����п�
	//��������Ϊ�գ�������ͬ����
	if (p == NULL && q == NULL) {
		return true;
	}
	//ֻ��һ�����ǿ�������ز�����ͬ����
	if (p == NULL || q == NULL) {
		return false;
	}
	//�����������������ͬ����������ͬ������ֵ��ͬ
	return p->value == q->value&&
		isSame(p->left, q->left) &&
		isSame(p->right, q->right);
}

//�ж�һ�����Ƿ��ǶԳ�������������������������Գ�
bool isSymmetry(TreeNode* root) {
	//�Ƚ����п�
	//����һ���ǶԳ���
	if (root == NULL) {
		return true;
	}
	//�ж����������Ƿ�Ϊ����
	return isMirror(root->left, root->right);
}

//�ж�һ�����Ƿ�����һ����������
bool isSubTree(TreeNode* p, TreeNode* q) {
	//����ת��Ϊ��һ������Ѱ���Ƿ���һ��������һ������ͬ
	//�Ӹ��ڵ㿪ʼ������Ӹ���ʼ����ͬ����֤��qһ����p������
	//�����ǣ�����p����������Ѱ��
	//��������û���ҵ���������������Ѱ��

	//����ǿ�������ֱ�ӷ���false
	if (p == NULL) {
		return false;
	}
	//���ҵ���q���ڵ���ͬ�Ľ��
	if (isSame(p,q)) {
		return true;
	}
	return isSubTree(p->left, q) || isSubTree(p->right, q);

}

//�ж��Ƿ���ƽ�������
bool isBalance(TreeNode* root) {
	//�������������ĸ߶Ȳ����1
	//����һ��ƽ�������
	if (root == NULL) {
		return true;
	}
	if (isBalance(root->left) == false) {
		return false;
	}
	if (isBalance(root->right) == false) {
		return false;
	}

	int differ = depthTree(root->left) - depthTree(root->right);
	if (differ > 1 || differ < -1) {
		return false;
	}
	else {
		return true;
	}
}

void test() {

	//TreeNode* a = createNode('A');
	//TreeNode* b = createNode('B');
	//TreeNode* c = createNode('B');
	//TreeNode* d = createNode('C');
	//TreeNode* e = createNode('D');
	//TreeNode* f = createNode('D');
	//TreeNode* g = createNode('C');
	//a->left = b; a->right = c;
	//b->left = d; b->right = e;
	//c->left = f; c->right = g;

	//TreeNode* aa = createNode('A');
	//TreeNode* bb = createNode('B');
	//TreeNode* cc = createNode('C');
	//TreeNode* dd = createNode('D');
	//aa->left = bb; aa->right = cc;
	//bb->left = dd;

	//arr = (char*)malloc(sizeof(char) * 100000);
	//TreeNode* tree = preOrder(a);
	//for (int i = 0; i < size; ++i) {
	//	printf("%c  ", arr[i]);
	//}
	//bool key = isMirror(a, aa);
	//if (key == true) {
	//	printf("��������Ϊ���񣡣���\n");
	//}
	//else {
	//	printf("����������Ϊ���񣡣���\n");
	//}
	//bool same = isSame(a, aa);
	//if (same == true) {
	//	printf("��������ͬ������\n");
	//}
	//else {
	//	printf("����������ͬ������\n");
	//}

	//bool symmetry = isSymmetry(a);
	//if (symmetry == true) {
	//	printf("������һ�öԳ���������\n");
	//}
	//else {
	//	printf("��������һ�öԳ���������\n");
	//}


	TreeNode* a = createNode('A');
	TreeNode* b = createNode('B');
	TreeNode* c = createNode('C');
	TreeNode* d = createNode('D');
	a->left = b; a->right = c;
	b->right = d;

	TreeNode* cc = createNode('B');
	TreeNode* dd = createNode('D');
	cc->right = dd;

	bool isSub = isSubTree(a, cc);
	if (isSub) {
		printf("cc��a��һ������������\n");
	}
	else {
		printf("cc����a��һ������������\n");
	}

	int depth = depthTree(a);
	printf("�ö�����������ǣ�%d\n", depth);

	bool bal = isBalance(a);
	if (bal) {
		printf("�ö�������һ��ƽ�������������\n");
	}
	else {
		printf("�ö���������һ��ƽ�������������\n");
	}



}

int main() {
	test();
	system("pause");
	return 0;
}