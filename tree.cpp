#include<iostream>
#include<stack>
#include<queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x, TreeNode *l = NULL, TreeNode *r = NULL) : val(x), left(l), right(r) {}
};

void preorder1(TreeNode *root)
{
	if (root == NULL) return;
	cout << root->val << " ";
	preorder1(root->left);
	preorder1(root->right);
}
void inorder1(TreeNode *root)
{
	if (root == NULL) return;
	inorder1(root->left);
	cout << root->val << " ";
	inorder1(root->right);
}
void postorder1(TreeNode *root)
{
	if (root == NULL) return;
	postorder1(root->left);
	postorder1(root->right);
	cout << root->val << " ";
}

TreeNode* createTree(int *a,int i,int n){
	TreeNode* p;
	if (i >= n)//||a[i]==0
		return NULL;
	p = (TreeNode *)malloc(sizeof(TreeNode));
	p->val = a[i];
	p->left = createTree(a, 2 * i + 1, n);
	p->right = createTree(a, 2 * i + 2, n);
	return p;
}

void preorder2(TreeNode *root){
	if (!root) return;
	stack<TreeNode*> stack;
	stack.push(root);
	while (!stack.empty()){
		TreeNode* temp = stack.top();
		cout << temp->val << " ";
		stack.pop();
		if (temp->right != NULL)
			stack.push(temp->right);
		if (temp->left != NULL)
			stack.push(temp->left);
	}
}
void postorder2(TreeNode *root){
	if (!root) return;
	stack<TreeNode*> stack1, stack2;
	stack1.push(root);
	while (!stack1.empty()){
		TreeNode* temp = stack1.top();
		stack2.push(temp);
		stack1.pop();
		if (temp->left != NULL)
			stack1.push(temp->left);
		if (temp->right != NULL)
			stack1.push(temp->right);
	}
	while (!stack2.empty()){
		TreeNode* temp = stack2.top();
		cout << temp->val << " ";
		stack2.pop();
	}
}

void preorder(TreeNode* root){
	/* 先序遍历(非递归)
	思路：访问T->data后，将T入栈，遍历左子树；遍历完左子树返回时，栈顶元素应为T，出栈，再先序遍历T的右子树。
	*/
	if (!root) return;
	stack<TreeNode*> stack;
	TreeNode* p = root;
	while (p != NULL || !stack.empty()){
		if (p != NULL){
			stack.push(p);
			cout << p->val << " ";
			p = p->left;
		}
		else{
			p = stack.top();			
			stack.pop();
			p = p->right;
		}
	}
}
void inorder(TreeNode* root){
	/*T是要遍历树的根指针，中序遍历要求在遍历完左子树后，访问根，再遍历右子树。
         先将T入栈，遍历左子树；遍历完左子树返回时，栈顶元素应为T，出栈，访问T->data，再中序遍历T的右子树。
		 */
	if (!root) return;
	stack<TreeNode*> stack;
	TreeNode* p = root;
	while (p!=NULL || !stack.empty()){
		if (p!=NULL){
			stack.push(p);
			p = p->left;
		}
		else{
			p = stack.top();
			cout << p->val << " ";
			stack.pop();
			p = p->right;
		}
	}
}

void postorder(TreeNode* root){
	if (!root) return;
	stack<TreeNode*> stack;
	TreeNode *q,*p = root;
	do{
		while (p != NULL){
			stack.push(p);
			p = p->left;
		}
		q = NULL;
		while (!stack.empty()){
			p = stack.top();
			stack.pop();
			if (p->right == q){
				cout << p->val << " ";
				q = p;
			}
			else{
				stack.push(p);
				p = p->right;
				break;
			}
		}
	} while (!stack.empty());
}

void levelorder(TreeNode* root){
	if (!root) return;
	queue<TreeNode*> queue;
	queue.push(root);
	while (!queue.empty()){
		TreeNode* p = queue.front();
		cout << p->val << " ";
		queue.pop();
		if (p->left != NULL){
			queue.push(p->left);
		}
		if (p->right != NULL){
			queue.push(p->right);
		}
	}
}

void levelorder1(TreeNode* root){
	if (!root) return;
	queue<TreeNode*> queue1,queue2;
	queue1.push(root);
	while (!queue1.empty()){
		while (!queue1.empty()){
			TreeNode* p = queue1.front();
			cout << p->val << " ";
			queue1.pop();
			if (p->left != NULL){
				queue2.push(p->left);
			}
			if (p->right != NULL){
				queue2.push(p->right);
			}
		}		
		swap(queue1, queue2);
		cout << endl;
	}
}

/*
int main(){
	int a[7] = { 1, 2, 3, 4, 5, 6, 7 };
	int b[10] = { 1, 2, 3, 4, 5, 6, 7,8,9,10 };
	TreeNode* head = createTree(a, 0, 7);
	preorder2(head);
	cout << endl;
	preorder(head);
	cout << endl;
	inorder1(head);
	cout << endl;
	inorder(head);
	cout << endl;
	postorder(head);
	cout << endl;
	postorder2(head);
	cout << endl;
	levelorder(head);
	cout << endl;
	levelorder1(head);
	system("pause");
}
*/