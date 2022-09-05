/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        int i = 0;
        int n = countNodes(head);
        ListNode * ptr = head;
        ListNode * end = getEnd(head);
        ListNode * prev = nullptr;
        while(i<n){
            if(i%2==1){
                if(end != ptr){
                    prev->next = ptr->next;
                    end->next = ptr;
                    end = ptr;
                    ptr->next = nullptr;                
                }
            } else {
                prev = ptr;
            }
            i++;
            ptr = prev->next;
        }
        return head;
    }
    
    int countNodes(ListNode* head){
        int c = 0;
        ListNode * ptr = head;
        while(ptr != nullptr){
            c++;
            ptr = ptr->next;
        }
        return c;
    }
    
    ListNode * getEnd(ListNode* head){
        ListNode * ptr = head;
        if(head == nullptr)
            return nullptr;
        while(ptr->next != nullptr)
            ptr = ptr->next;
        return ptr;
    }
};
