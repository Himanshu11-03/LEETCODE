/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    Node(int _val) : val(_val), next(nullptr), random(nullptr) {}
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        unordered_map<Node*, Node*> m;
        Node* newHead = new Node(head->val);
        m[head] = newHead;

        Node* oldTemp = head->next;
        Node* newTemp = newHead;

        while (oldTemp != nullptr) {
            Node* copyNode = new Node(oldTemp->val);
            newTemp->next = copyNode;
            m[oldTemp] = copyNode;   

            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }
        oldTemp = head;
        newTemp = newHead;

        while (oldTemp != nullptr) {
            newTemp->random = m[oldTemp->random];

            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        return newHead;
    }
};