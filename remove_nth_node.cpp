#include <iostream>
#include<stack>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
private: 
    int get_num(ListNode* head) {
        stack<int> st; 
        ListNode* ptr = head; 
        while (ptr) {
            st.push(ptr->val); 
            ptr = ptr->next; 
        } 

        int tens = (st.size()-1) * 10, result = 0; 
        while (!st.empty()) {
            result += (st.top() * tens); 
            tens -= 10; 
        }
        return result;
    }
    ListNode* create_list(int num) {
        ListNode* ptr = new ListNode(-1,nullptr); 
        ListNode* ret = ptr; 
        while (num > 0) {
            ptr->next = new ListNode(num % 10, nullptr); 
            ptr = ptr->next; 
            num /= 10; 
        }
        return ptr->next; 
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1) return l2; 
        if (!l2) return l1; 
        return create_list(get_num(l1)+get_num(l2));  
    }
};
/*

*/