#include <iostream>
using namespace std;
typedef int ElementType;

class BST_Node
{
public:
	ElementType Data;
	BST_Node *Left;
	BST_Node *Right;

	BST_Node() = default;
	BST_Node(ElementType t) : Data(t)
	{
		Left = Right = nullptr;
	}
};

BST_Node *Find(ElementType Target, BST_Node *BST)
{
	if (!BST)
	{
		// cout<<"flag";
		return nullptr; /*查找失败*/
	}
	if (Target > BST->Data)
		return Find(Target, BST->Right); /*在右子树中继续查找*/
	else if (Target < BST->Data)
		return Find(Target, BST->Left); /*在左子树中继续查找*/
	else								/* Target == BST->Data */
		return BST;						/*查找成功，返回结点的找到结点的地址*/
}

BST_Node *FindMin(BST_Node *root)
{
	if (!root)
		return root;
	BST_Node *temp = root;
	while (temp->Left)
		temp = temp->Left;
	return temp;
}

BST_Node *Insert(ElementType Data, BST_Node *BST)
{

	// start with the BST node
	BST_Node *curr = BST;

	// pointer to store the parent of the current node
	BST_Node *parent = nullptr;

	// if the tree is empty, create a new node and set it as BST
	if (BST == nullptr)
	{
		BST = new BST_Node(Data);
		return BST;
	}

	// traverse the tree and find the parent node of the given Data
	while (curr != nullptr)
	{
		// update the parent to the current node
		parent = curr;

		// if the given Data is less than the current node, go to the
		// Left subtree; otherwise, go to the Right subtree.
		if (Data < curr->Data)
			curr = curr->Left;
		else
			curr = curr->Right;
	}

	// construct a node and assign it to the appropriate parent pointer
	if (Data < parent->Data)
		parent->Left = new BST_Node(Data);
	else
		parent->Right = new BST_Node(Data);

	return BST;
}

BST_Node *Delete(ElementType Data, BST_Node *BST)
{

	BST_Node *curr = BST;
	BST_Node *prev = nullptr;

	// Check if the Data is actually
	// present in the BST.
	// the variable prev points to
	// the parent of the Data to be deleted.
	while (curr != nullptr && curr->Data != Data)
	{
		prev = curr;
		if (Data < curr->Data)
			curr = curr->Left;
		else
			curr = curr->Right;
	}

	if (curr == nullptr)
	{
		// cout << "Key " << Data << " not found in the"
		// 	 << " provided BST.\n";
		return BST;
	}

	// Check if the node to be
	// deleted has atmost one child.
	if (curr->Left == nullptr || curr->Right == nullptr)
	{

		// newCurr will replace
		// the node to be deleted.
		BST_Node *newCurr;

		// if the Left child does not exist.
		if (curr->Left == nullptr)
			newCurr = curr->Right;
		else
			newCurr = curr->Left;

		// check if the node to
		// be deleted is the BST.
		if (prev == nullptr)
			return newCurr;

		// check if the node to be deleted
		// is prev's Left or Right child
		// and then replace this with newCurr
		if (curr == prev->Left)
			prev->Left = newCurr;
		else
			prev->Right = newCurr;

		// free memory of the
		// node to be deleted.
		delete curr;
	}

	// node to be deleted has
	// two children.
	else
	{
		BST_Node *p = nullptr;
		BST_Node *temp;

		// Compute the inorder successor
		temp = curr->Right;
		while (temp->Left != nullptr)
		{
			p = temp;
			temp = temp->Left;
		}

		// check if the parent of the inorder
		// successor is the curr or not(i.e. curr=
		// the node which has the same Data as
		// the given Data by the user to be
		// deleted). if it isn't, then make the
		// the Left child of its parent equal to
		// the inorder successor'd Right child.
		if (p != nullptr)
			p->Left = temp->Right;

		// if the inorder successor was the
		// curr (i.e. curr = the node which has the
		// same Data as the given Data by the
		// user to be deleted), then make the
		// Right child of the node to be
		// deleted equal to the Right child of
		// the inorder successor.
		else
			curr->Right = temp->Right;

		curr->Data = temp->Data;
		delete temp;
	}
	return BST;
}

void Inorder(BST_Node *root)
{
	if (!root)
		return;
	Inorder(root->Left);
	cout << root->Data << ' ';
	Inorder(root->Right);
}

void destoryBST(BST_Node *root)
{
	if (!root)
		return;
	destoryBST(root->Left);
	destoryBST(root->Right);
	delete root;
}