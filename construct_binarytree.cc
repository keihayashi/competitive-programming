#include <iostream>
#include <vector>
using namespace std;

// 問題文が見つからない。buildSubTreeの引数の意味が知りたい。
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {} // これは何？
};

class Solution {
public:
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) { // order does not matter.
    return buildSubTree(inorder, postorder, 0, inorder.size(), 0, postorder.size());
  }
  TreeNode* buildSubTree(vector<int>&inorder, vector<int>&postorder, int istart, int iend, int pstart, int pend) {
    if (istart == iend) {
      return NULL;
    } else if (istart == iend-1) {
      return new TreeNode(inorder[istart]);
    } else {
      int rootv = postorder[pend-1];
      TreeNode *rootnode = new TreeNode(rootv);
      int t;
      for (t = istart; t < iend; t++) {
        if (rootv == inorder[t]) {
          break;
        }
      }
      rootnode->left = buildSubTree(inorder, postorder, istart, t, pstart, pstart+t-istart);
      rootnode->right = buildSubTree(inorder, postorder, t+1, iend, pstart+t-istart, pend-1);
      return rootnode;
    }
  }
};

int main()
{
  vector<int> inorder;
  inorder.push_back(1);
  inorder.push_back(2);
  inorder.push_back(3);
  inorder.push_back(4);
  inorder.push_back(5);
  inorder.push_back(6);
  vector<int> postorder;
  postorder.push_back(1);
  postorder.push_back(2);
  postorder.push_back(4);
  postorder.push_back(6);
  postorder.push_back(5);
  postorder.push_back(3);
  Solution solution;
  TreeNode *nodex = solution.buildTree(inorder, postorder);
  for (int i = 0; nodex != NULL; i++) {
      cout << nodex->val << endl;
      nodex = nodex->left;
  }
  return 0;
}
