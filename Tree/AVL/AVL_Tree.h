/* VScode_Version */

#pragma once

#include <iostream>
#include <queue>

#define RG register
#define LL long long
#define ULL unsigned long long
#define INF 0x7fffffff
#define MAXN 500
typedef int ElementType;
using namespace std;

struct AVLNode
{
    int Num = -INF;
    AVLNode *left;
    AVLNode *right;
    int height = -INF;
};

int getHeight(AVLNode *T)
{
    if (T == nullptr)
        return 0;
    if (T->height != -INF)
        return T->height;
    int h = max(getHeight(T->left), getHeight(T->right)) + 1;
    T->height = h;
    return h;
}


AVLNode *LL_Rotate(AVLNode *A)
{ /* 注意：A必须有一个左子结点B */
    /* 将A与B做左单旋，更新A与B的高度，返回新的根结点B */
    AVLNode *B = A->left;
    A->left = B->right;
    B->right = A;
    A->height = max(getHeight(A->left), getHeight(A->right)) + 1;
    B->height = max(getHeight(B->left), getHeight(A->right)) + 1;
    return B;
}

AVLNode *RR_Rotate(AVLNode *A)
{
    AVLNode *B = A->right;
    A->right = B->left;
    B->left = A;
    A->height = max(getHeight(A->left), getHeight(A->right)) + 1;
    B->height = max(getHeight(B->left), getHeight(A->right)) + 1;
    return B;
}

AVLNode *LR_Rotate(AVLNode *A)
{ /* 注意：A必须有一个左子结点B，且B必须有一个右子结点C */
    /* 将A、B与C做两次单旋，返回新的根结点C */
    A->left = RR_Rotate(A->left);
    return LL_Rotate(A);
}

AVLNode *RL_Rotate(AVLNode *A)
{
    A->right = LL_Rotate(A->right);
    return RR_Rotate(A);
}

AVLNode *Find(ElementType Target, AVLNode *AVLT)
{
	if (!AVLT)
	{
		// cout<<"flag";
		return nullptr; /*查找失败*/
	}
	if (Target > AVLT->Num)
		return Find(Target, AVLT->right); /*在右子树中继续查找*/
	else if (Target < AVLT->Num)
		return Find(Target, AVLT->left); /*在左子树中继续查找*/
	else								/* Target == AVLT->Num */
		return AVLT;						/*查找成功，返回结点的找到结点的地址*/
}

AVLNode *Insert(AVLNode *R, int num)
{
    /* 将X插入AVL树T中，并且返回调整后的AVL树(的根节点) */

    if (!R) /* 若插入空树，则新建包含一个结点的树 */
    {
        R = new AVLNode;
        R->height = 1;
        R->Num = num;
        R->left = R->right = nullptr;
        return R;
    }
    else if (num < R->Num) /* 插入T的左子树 */
    {
        R->left = Insert(R->left, num);
        /* 如果需要左旋 */
        if (getHeight(R->left) - getHeight(R->right) == 2)
        {
            if (num < R->left->Num)
                R = LL_Rotate(R);
            else
                R = LR_Rotate(R);
        }
    }
    else if (num > R->Num) /* 插入T的右子树 */
    {
        R->right = Insert(R->right, num);
        /* 如果需要右旋 */
        if (getHeight(R->left) - getHeight(R->right) == -2)
        {
            if (num > R->right->Num)
                R = RR_Rotate(R);
            else
                R = RL_Rotate(R);
        }
    }

    R->height = max(getHeight(R->left), getHeight(R->right)) + 1;
    return R;
}

AVLNode *Delete(AVLNode *R, int num)
{
    //* STEP 1: 标准BST的删除
    if (!R)
        return R;

    if (num < R->Num)
    {
        R->left = Delete(R->left, num);
    }
    else if (num > R->Num)
    {
        R->right = Delete(R->right, num);
    }

    else
    {
        if (!R->left || !R->right)
        {
            AVLNode *temp = R->left ? R->left : R->right;
            if (!temp)// No child case
            {
                temp = R;
                R = nullptr;
            }
            else
                *R = *temp;
            delete temp;
        }
        else    // 根节点有两个孩子的情况：用其后继的值（最小上界）代替根节点值
        {
            AVLNode *temp = R->right;
            while (temp->left)
                temp = temp->left;

            R->Num = temp->Num;
            R->right = Delete(R->right, temp->Num);
        }
    }

    // 整棵树只有根节点的情况
    if (!R)
        return R;

    //* STEP 2:更新当前结点的高度
    R->height = max(getHeight(R->left), getHeight(R->right)) + 1;

    //* STEP 3:检查该节点的平衡因子，若不平衡则调整
    int BF = getHeight(R->left) - getHeight(R->right);
    if (BF == 2)
    {
        if (getHeight(R->left->left) - getHeight(R->left->right)>=0)
            R = LL_Rotate(R);
        else
            R = LR_Rotate(R);
    }
    if (BF == -2)
    {
        if (getHeight(R->right->left) - getHeight(R->right->right)<0)
            R = RR_Rotate(R);
        else
            R = RL_Rotate(R);
    }

    return R;
}


