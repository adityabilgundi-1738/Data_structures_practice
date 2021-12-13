#include<vector>
#include<climits>
#include<math.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    int lengthofLL(ListNode* head){
        int len = 0;
        while(head != NULL){
            len++;
            head = head->next;
        }
        return len;
    };
    
public:
    int getDecimalValue(ListNode* head) {
        int lenLL = lengthofLL(head);
        int decimal = 0;
        for (int i = lenLL; i>0 ; i--){
            decimal += (head->val) * pow(2,i-1);
            head = head->next;
        }
        return decimal;
    };
};