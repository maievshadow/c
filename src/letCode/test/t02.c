//
// Created by redredmaple on 1/3/19.
//

void list_test(int argc, char ** argv)
{
    //l

    struct ListNode * l1 = initList();
    struct ListNode * l2 = initList();

    insertList(l1, 0, 1);
    insertList(l2, 0, 9);
    insertList(l2, 1, 9);

    struct ListNode * l3 = addTwoNumbers(l1, l2);

    prList(l1);
    prList(l2);
    prList(l3);
}

