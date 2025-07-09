#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

std::vector<int> getPath(TreeNode* root, int target) {
    std::vector<int> path;
    std::function<bool(TreeNode*)> dfs = [&](TreeNode* node) {
        if (!node) return false;
        path.push_back(node->val);
        if (node->val == target) return true;
        if (dfs(node->left) || dfs(node->right)) return true;
        path.pop_back();
        return false;
    };
    dfs(root);
    return path;
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (!subRoot) return true;
    if (!root) return false;
    std::function<bool(TreeNode*, TreeNode*)> dfs = [&](TreeNode* r, TreeNode* s) {
        if (!s) return true;
        if (!r) return false;
        if (r->val != s->val) return false;
        return dfs(r->left, s->left) && dfs(r->right, s->right);
    };
    if (dfs(root, subRoot)) return true;
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}