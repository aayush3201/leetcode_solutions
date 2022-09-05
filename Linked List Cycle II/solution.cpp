/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        set<ListNode *> visited;
        ListNode * pointer = head;
        while(pointer != nullptr){
            if(visited.find(pointer) != visited.end())
                return pointer;
            visited.insert(pointer);
            pointer = pointer->next;
        }
        return nullptr;
    }
};
