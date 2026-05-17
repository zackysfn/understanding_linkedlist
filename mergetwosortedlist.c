/*
     Definition for singly-linked list.
    
      struct ListNode {
         int val;
          struct ListNode *next;
      };
*/

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {

    //buat node dummy
    struct ListNode dummy;
    struct ListNode* curr = &dummy;
    dummy.next = NULL;


    //lakukan perbandingan ke masing-masing head di tiap list selagi tidak ada list yang kosong
    while (list1 != NULL && list2 != NULL) {
        if (list1->val <= list2->val) {
            curr->next = list1;    
            list1 = list1->next;   
        } else {
            curr->next = list2;    
            list2 = list2->next;   
        }
        curr = curr->next;        
    }

    if (list1 != NULL) {
        curr->next = list1;
    } else {
        curr->next = list2;
    }

    return dummy.next; //kembalikan alamat node yang ditunjuk dummy yang merupakan head dari sorted list dari 2 list yang sudah di merge tadi
}
