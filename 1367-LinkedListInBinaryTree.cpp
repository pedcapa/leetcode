class Solution {
public:
    bool check(ListNode* head,TreeNode* root){
        if(head->next==nullptr){
            return true;
        }
        if(root->left && root->left->val==head->next->val && check(head->next,root->left)==true){
            return true;
        }
        if(root->right&& root->right->val==head->next->val && check(head->next,root->right)==true){
            return true;
        }
        return false;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!root){
            return false;
        }
        if((root->val==head->val) && check(head,root)){
            return true;
        }
        return isSubPath(head,root->left)||isSubPath(head,root->right);
    }
};
