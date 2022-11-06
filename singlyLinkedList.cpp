#include <stdlib.h>
#include <iostream>
using namespace std;
class Node
{
public:
    int value = 0;
    Node *next = NULL;

public:
    Node()
    {
        next = NULL;
    }
    Node(int x)
    {
        value = x;
        next = NULL;
    }
};
class LinkList
{
public:
    Node *head = new Node();

public:
    LinkList(void) { head = NULL; }                     // constructor
    LinkList(Node *headPointer) { head = headPointer; } // constructor

    ~LinkList(void); // destructor
    bool isEmpty() { return head == NULL; }
    Node *insertNode(int index, int x) // insert at the given index
    {
        if (index == 0)
        {
            insertAtHead(x);
        }
        else
        {
            Node *previous = NULL;
            Node *current = head;
            int i = 0;
            while (current != NULL && i < index)
            {
                previous = current;
                current = current->next;
                i++;
            }

            Node *newNode = new Node(x);
            previous->next = newNode;
            newNode->next = current;
        }
    }
    Node *insertAtHead(int x) // insert at start of list
    {
        Node *newNode = new Node(x);
        newNode->next = head;
        head = newNode;
    }
    Node *insertAtEnd(int x) // insert at end of list
    {
        Node *currentNodePointer = head;
        while (currentNodePointer->next != NULL)
        {
            currentNodePointer = currentNodePointer->next;
        }
        Node *newNode = new Node(x);
        currentNodePointer->next = newNode;
    }
    bool findNode(int x) // search for data value x in the list
    {
        Node *currentNodePointer = head;
        while (currentNodePointer->next != NULL)
        {
            if (currentNodePointer->value == x)
            {
                return true;
            }
            else
            {
                currentNodePointer = currentNodePointer->next;
            }
        }
        return false;
    }
    bool deleteNode(int x) // delete all occurrences of x
    {
        Node *previousNode = NULL;
        Node *currentNode = head;
        while (currentNode->next != NULL)
        {
            if (currentNode->value == x)
            {
                previousNode->next = currentNode->next;
            }
            else
            {
                previousNode = currentNode;
                currentNode = currentNode->next;
            }
        }
    }
    bool deleteFromStart() // deletes starting node of list
    {
        head = head->next;
    }
    bool deleteFromEnd() // deletes last node of list
    {
        Node *previousNode = NULL;
        Node *currentNode = head;
        while (true)
        {
            if (currentNode->next == NULL)
            {
                previousNode->next = NULL;
                break;
            }
            else
            {
                previousNode = currentNode;
                currentNode = currentNode->next;
            }
        }
    }
    void displayList(void)
    {
        Node *currentNode = head;
        while (currentNode != NULL)
        {
            cout << currentNode->value << endl;
            currentNode = currentNode->next;
        }
    }
    Node *reverseList()
    { // reverses the linklist and returns a new list
        Node *previous = NULL;
        Node *current = head;
        Node *next = current->next;
        while (next != NULL)
        {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
            // next=current->next;
        }
        head = previous;
        return head;
    }
    Node *sortList(Node *list)
    { // sorts the input-ed list
        int temp = 0;
        Node *unSortedElement = list;
        while (unSortedElement != NULL)
        {
            Node *checkElementsPointer = unSortedElement->next;
            while (checkElementsPointer != NULL)
            {
                if (checkElementsPointer->value < unSortedElement->value)
                {
                    temp = unSortedElement->value;
                    unSortedElement->value = checkElementsPointer->value;
                    checkElementsPointer->value = temp;
                }
                checkElementsPointer = checkElementsPointer->next;
            }
            unSortedElement = unSortedElement->next;
        }
    }
    Node *removeDuplicates(Node *list)
    { // removes duplicates from list
        Node *previousPointer = NULL;
        Node *currentPointer = list;
        while (currentPointer != NULL)
        {
            if (isValueExisted(currentPointer, list))
            {
                previousPointer->next = currentPointer->next;
                currentPointer = currentPointer->next;
            }
            else
            {
                previousPointer = currentPointer;
                currentPointer = currentPointer->next;
            }
        }
        return list;
    }
    Node *mergeLists(Node *list1, Node *list2)
    { // merges two lists
        Node *current = list1;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = list2;
        return list1;
    }
    Node *interestLists(Node *list1, Node *list2)
    { // results contains intersection of two lists
        Node *newhead = NULL;
        Node *newListPointer = NULL;
        Node *currentCheckPointerList1 = list1;
        while (currentCheckPointerList1 != NULL)
        {
            Node *nextList1Pointer = currentCheckPointerList1->next;
            if (isValueExisted(currentCheckPointerList1, list2))
            {
                if (newhead == NULL)
                {
                    // currentCheckPointerList1->next;
                    newhead = currentCheckPointerList1;
                    newListPointer = newhead;
                }
                else
                {
                    newListPointer->next = currentCheckPointerList1;
                    newListPointer = currentCheckPointerList1;
                }
                //
            }
            currentCheckPointerList1 = nextList1Pointer;
        }
        return newhead;
    }

    // Helping Functions
    bool isValueExisted(Node *key, Node *list)
    {
        Node *currentNode = list;
        while (currentNode->next != NULL && currentNode != key)
        {
            if (currentNode->value == key->value)
            {
                return true;
            }
            else
            {
                currentNode = currentNode->next;
            }
        }
        return false;
    }
};
main()
{
    /*                                     Intersection */
    // LinkList *list = new LinkList();
    // list->insertAtHead(10);
    // list->insertAtEnd(20);
    // list->insertAtEnd(30);

    // LinkList *list2 = new LinkList();
    // list2->insertAtHead(40);
    // list2->insertAtEnd(20);
    // list2->insertAtEnd(30);

    // Node *newlistHead = list->interestLists(list->head, list2->head);
    // LinkList *IntersectList = new LinkList(newlistHead);
    // cout << "-------------------" << endl;
    // IntersectList->displayList();
    // _________________________________________________________________________________________________
    /*                                      Merge */
    // LinkList *list = new LinkList();
    // list->insertAtHead(10);
    // list->insertAtEnd(20);
    // list->insertAtEnd(30);

    // LinkList *list2 = new LinkList();
    // list2->insertAtHead(40);
    // list2->insertAtEnd(20);
    // list2->insertAtEnd(30);

    // list->head=list->mergeLists(list->head,list2->head);
    // cout << "-------------------" << endl;
    // list->displayList();

    // _________________________________________________________________________________________________
    /*                                      Insert At */
    // LinkList *list = new LinkList();
    // list->insertAtHead(10);
    // list->insertAtEnd(20);
    // list->insertAtEnd(30);
    // list->insertNode(0, 50);
    // list->displayList();

    // _________________________________________________________________________________________________
    /*                                      Sort  */
    // LinkList *list = new LinkList();
    // list->insertAtHead(50);
    // list->insertAtEnd(10);
    // list->insertAtEnd(200);
    // list->insertAtEnd(20);
    // list->insertAtEnd(210);
    // list->insertAtEnd(220);
    // list->insertAtEnd(0);
    // list->sortList(list->head);
    // list->displayList();
}
