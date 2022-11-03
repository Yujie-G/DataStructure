class Node
{
    public:
    Node():Data{0},left{nullptr},right{nullptr}{}
    int Data;
    int Height;
    Node *left;
    Node *right;

};
typedef Node* Tree;