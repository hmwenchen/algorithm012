#include <vector>
#include <stack>


// Definition for a Node.
class Node {
public:
    int val;
    std::vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, std::vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    std::vector<int> preorder(Node* root) {
        if (!root) {
            return std::vector<int>{};
        }
        std::stack<Node*> nodeStack{};
        std::vector<int> result{};
        nodeStack.push(root);
        while (!nodeStack.empty()) {
            Node* current = nodeStack.top();
            nodeStack.pop();
            result.push_back(current->val);
            for (int i = current->children.size() - 1; i >= 0; --i) {
                nodeStack.push(current->children[i]);
            }
        }
        return result;
    }
};