// https://leetcode.com/problems/search-in-a-binary-search-tree

struct TreeNode
{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode()
      : val(0),
        left(nullptr),
        right(nullptr)
  {
  }
  TreeNode(int x)
      : val(x),
        left(nullptr),
        right(nullptr)
  {
  }
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x),
        left(left),
        right(right)
  {
  }
};

class Solution
{
 public:
  TreeNode* searchBST(TreeNode* root, int val)
  {
    // Recursive version.
    //   if (root == nullptr)
    //   {
    //     return nullptr;
    //   }
    //   else if (root->val == val)
    //   {
    //     return root;
    //   }
    //   else if (root->val > val)
    //   {
    //     return searchBST(root->left, val);
    //   }
    //   else
    //   {
    //     return searchBST(root->right, val);
    //   }
    // }

    // Iterative version.
    while (true)
    {
      if (root == nullptr)
      {
        return nullptr;
      }
      else if (root->val == val)
      {
        return root;
      }
      else if (root->val > val)
      {
        root = root->left;
      }
      else
      {
        root = root->right;
      }
    }
  }
};

int main()
{
  return 0;
}
