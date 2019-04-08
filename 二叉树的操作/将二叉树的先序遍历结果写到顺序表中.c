#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct TreeNode {
	char value;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;

//创建结点
TreeNode* createNode(char value) {
	TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
	root->value = value;
	root->left = NULL;
	root->right = NULL;
	return root;
}

//先序遍历结果写入顺序表中
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

//计算一棵二叉树的深度
int depthTree(TreeNode* root) {
	if (root == NULL) {
		return 0;
	}
	int left = depthTree(root->left);
	int right = depthTree(root->right);
	return (left > right ? left : right) + 1;
}


//判断两棵树是否互为镜像
bool isMirror(TreeNode* p,TreeNode* q) {
	//先进行判空
	//两棵树均为空树，就是互为镜像
	if (p == NULL && q == NULL) {
		return true;
	}
	//只有一棵树是空树，必然不互为镜像
	if (p == NULL || q == NULL) {
		return false;
	}
	//一棵树的左子树与另一棵树的右子树相同，则互为镜像
	return p->value == q->value&&
		isMirror(p->left, q->right) &&
		isMirror(p->right, q->left);
}

//检查两棵树是否是相同的树
bool isSame(TreeNode* p, TreeNode* q) {
	//先进行判空
	//两棵树均为空，则是相同的树
	if (p == NULL && q == NULL) {
		return true;
	}
	//只有一棵树是空树，则必不是相同的树
	if (p == NULL || q == NULL) {
		return false;
	}
	//其他情况，左子树相同，右子树相同，结点的值相同
	return p->value == q->value&&
		isSame(p->left, q->left) &&
		isSame(p->right, q->right);
}

//判断一棵树是否是对称树——左子树与右子树镜像对称
bool isSymmetry(TreeNode* root) {
	//先进行判空
	//空树一定是对称树
	if (root == NULL) {
		return true;
	}
	//判断左右子树是否互为镜像
	return isMirror(root->left, root->right);
}

//判断一棵树是否是另一颗树的子树
bool isSubTree(TreeNode* p, TreeNode* q) {
	//将其转化为在一棵树中寻找是否有一颗树与另一棵树相同
	//从根节点开始，如果从根开始就相同，就证明q一定是p的子树
	//根不是，就在p的左子树中寻找
	//左子树中没有找到，就在右子树中寻找

	//如果是空树，就直接返回false
	if (p == NULL) {
		return false;
	}
	//先找到与q根节点相同的结点
	if (isSame(p,q)) {
		return true;
	}
	return isSubTree(p->left, q) || isSubTree(p->right, q);

}

//判断是否是平衡二叉树
bool isBalance(TreeNode* root) {
	//任意左右子树的高度差不超过1
	//空树一定平衡二叉树
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
	//	printf("两棵树互为镜像！！！\n");
	//}
	//else {
	//	printf("两棵树不互为镜像！！！\n");
	//}
	//bool same = isSame(a, aa);
	//if (same == true) {
	//	printf("两棵树相同！！！\n");
	//}
	//else {
	//	printf("两棵树不相同！！！\n");
	//}

	//bool symmetry = isSymmetry(a);
	//if (symmetry == true) {
	//	printf("该树是一棵对称树！！！\n");
	//}
	//else {
	//	printf("该树不是一棵对称树！！！\n");
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
		printf("cc是a的一棵子树！！！\n");
	}
	else {
		printf("cc不是a的一棵子树！！！\n");
	}

	int depth = depthTree(a);
	printf("该二叉树的深度是：%d\n", depth);

	bool bal = isBalance(a);
	if (bal) {
		printf("该二叉树是一棵平衡二叉树！！！\n");
	}
	else {
		printf("该二叉树不是一棵平衡二叉树！！！\n");
	}



}

int main() {
	test();
	system("pause");
	return 0;
}