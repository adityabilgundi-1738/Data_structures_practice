#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode* right;
    TreeNode* left;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    int getval(ListNode* head, int index){
        ListNode* current = head;
        int count = 0;
        while(current != NULL){
            if(count == index) return (current->val);
            count++;
            current = current->next;
        }
        return 0;
    }
    TreeNode* recurse(ListNode* head, int start, int end){
        if(start > end){
            return NULL;
        }
        int mid = (start + end + 1)/2;
        TreeNode* root = new TreeNode(getval(head,mid));
        root->left = recurse(head,start,mid - 1);
        root->right = recurse(head, mid + 1,end);
        
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head){
        int len = 0;
        
        if(head == NULL){
            return NULL;
        }
        else if(head -> next == NULL){
            TreeNode* root = new TreeNode(head->val);
            return root;
        }
        else{
            ListNode* temp = head;
            while(temp != NULL){
                len++;
                temp = temp->next;
            }
            temp = NULL;
            delete temp;
        }
        return recurse(head,0,len-1);
    }
};

int main(){

    return 0;
}
