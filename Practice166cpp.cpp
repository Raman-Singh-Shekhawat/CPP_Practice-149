// 167. Check Balanced: Given a binary tree, check if it is balanced. Return true if given binary tree is balanced, false otherwise.

/**********************************************************
    Following is the Binary Tree Node class structure

    template <typename T>
    class BinaryTreeNode {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

***********************************************************/

pair<bool, int> helper(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        pair<bool, int> ans;
        ans.first = true;
        ans.second = 0;
        return ans;
    }
    pair<bool, int> leftAns = helper(root->left);
    pair<bool, int> rightAns = helper(root->right);
    pair<bool, int> ans;
    ans.second = max(leftAns.second, rightAns.second) + 1;
    ans.first = ((abs(leftAns.second - rightAns.second) <= 1) && rightAns.first && leftAns.first);
    return ans;
}

bool isBalanced(BinaryTreeNode<int> *root)
{
    return helper(root).first;
}