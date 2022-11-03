typedef int ElementType;
struct Node
{
    ElementType Data;
    Node *Left;
    Node *Right;
};

Node* Find(ElementType Target, Node* BST)
{
	if (!BST) return nullptr; /*查找失败*/
	if (Target > BST->Data)
		return Find(Target, BST->Right); /*在右子树中继续查找*/
	else if (Target < BST->Data)
		return Find(Target, BST->Left); /*在左子树中继续查找*/
	else /* Target == BST->Data */
		return BST; /*查找成功，返回结点的找到结点的地址*/

}

Node* FindMin(Node* B)
{
    if(!B)return B;
    Node *temp = B;
    while(temp->Left)temp = temp->Left;
    return temp;
}

Node* Insert(ElementType Data,Node* BST)
{
	if (!BST) {
		/*若原树为空，生成并返回一个结点的二叉搜索树*/
		BST = new Node;
        BST->Data = Data;
		BST->Left = BST->Right = nullptr;
	}
	else /*开始找要插入元素的位置*/
		if (Data < BST->Data)
			BST->Left = Insert(Data, BST->Left);
	/*递归插入左子树*/
		else if (Data > BST->Data)
			BST->Right = Insert(Data, BST->Right);
	/*递归插入右子树*/
	/* else X已经存在，什么都不做 */
	return BST;
}

Node* Delete(ElementType Data, Node* BST)
{
	Node* Tmp;
	if (!BST) ;//cout<<"要删除的元素未找到!";
	else if (Data < BST->Data)
		BST->Left = Delete(Data, BST->Left); /* 左子树递归删除 */
	else if (Data > BST->Data)
		BST->Right = Delete(Data, BST->Right); /* 右子树递归删除 */
	else /*找到要删除的结点 */
		if (BST->Left && BST->Right) { /*被删除结点有左右两个子结点 */
			Tmp = FindMin(BST->Right);
			/*在右子树中找最小的元素填充删除结点*/
			BST->Data = Tmp->Data;
			BST->Right = Delete(BST->Data, BST->Right);
			/*在删除结点的右子树中删除最小元素*/
		}
		else { /*被删除结点有一个或无子结点*/
			Tmp = BST;
			if (!BST->Left) /* 有右孩子或无子结点*/
				BST = BST->Right;
			else if (!BST->Right) /*有左孩子或无子结点*/
				BST = BST->Left;
		}
	return BST;
}
