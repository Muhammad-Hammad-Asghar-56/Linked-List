#include <stdlib.h>
#include <iostream>
using namespace std;
class Node
{
public:
    int value = 0;
    Node *next = NULL;
    Node *previous = NULL;

public:
    Node()
    {
        next = NULL;
        previous = NULL;
    }
    Node(int x)
    {
        value = x;
        next = NULL;
        previous = NULL;
    }
};
class LinkList
{
public:
    Node *head = new Node();
    Node *Tail = new Node();

public:
    LinkList(void)
    {
        head = NULL;
        Tail = NULL;
    }; // constructor
    LinkList(Node *headPointer)
    {
        head = headPointer;
        Tail = headPointer;
    }; // constructor

    ~LinkList(void); // destructor
    bool isEmpty() { return head == NULL; }
    Node *insertAtHead(int x) // insert at start of list
    {
        Node *newNode = new Node(x);
        if (head != NULL)
        {
            head->previous = newNode;
            newNode->next = head;
            head = newNode;
            head->previous = Tail;
        }
        else
        {
            head = newNode;
            head->previous = Tail;
            head->next = head;
        }

        if (Tail == NULL) // Tail is empty
        {
            Tail = head;
            head->previous = Tail;
        }
        else
        {
            head->previous = Tail;
            Tail->next = head;
        }
    }
    Node *insertAtEnd(int x) // insert at end of list
    {
        Node *newNode = new Node(x);
        if (head == NULL)
        {
            return insertAtHead(x);
        }
        Tail->next = newNode;
        newNode->previous = Tail;
        newNode->next = head;
        head->previous = newNode;
        Tail = newNode;
        return newNode;
    }
    Node *insertNode(int index, int x) // insert at the given index
    {

        Node *current = head;
        int i = 0;
        while (i < index)
        {
            current = current->next;
            i++;
        }
        if (current == head)
        {
            insertAtHead(x);
        }
        else if (current == Tail)
        {
            insertAtEnd(x);
        }
        else
        {

            Node *newNode = new Node(x);

            newNode->previous = current->previous;
            newNode->next = current;

            current->previous->next = newNode;
            current->previous = newNode;
        }
    }
    bool findNode(int x) // search for data value x in the list
    {
        Node *currentNodePointer = head;
        if (currentNodePointer != NULL)
        {
            do
            {
                if (currentNodePointer->value == x)
                {
                    return true;
                }
                else
                {
                    currentNodePointer = currentNodePointer->next;
                }
            } while (currentNodePointer != head);
        }
        return false;
    }
    bool deleteNode(int x) // delete all occurrences of x
    {
        Node *currentNode = head;
        if (currentNode != NULL)
        {
            do
            {
                if (currentNode->value == x)
                {
                    Node *next = currentNode->next;
                    if (currentNode == head)
                    { // its mean the node is the first in the list
                        deleteFromStart();
                    }
                    else if (currentNode == Tail)
                    { // its mean the node is the first in the list
                        deleteFromEnd();
                    }
                    else
                    {
                        currentNode->previous->next = currentNode->next;
                        currentNode->next->previous = currentNode->previous;
                    }
                }

                currentNode = currentNode->next;
            } while (currentNode != head);
        }
        return 1;
    }
    bool deleteFromStart() // deletes starting node of list
    {
        head = head->next;
        head->previous = Tail;
        Tail->next = head;
    }
    bool deleteFromEnd() // deletes last node of list
    {
        Tail = Tail->previous;
        Tail->next = head;
        head->previous = Tail;
    }
    void displayList(void)
    {
        Node *currentNode = head;
        do
        {
            cout << currentNode->value << endl;
            currentNode = currentNode->next;

        } while (currentNode != head);
    }
    Node *reverseList()
    { // reverses the linklist and returns a new list
        Node *start = head;
        Node *end = Tail;
        Node *current = head;
        do
        {
            Node *nexttemp = current->next;
            Node *prevtemp = current->previous;
            current->next = prevtemp;
            current->previous = nexttemp;
            current = nexttemp;
        } while (current != start);
        // current->next=end;
        // current->previous=current->next;
        Tail = start;
        head = end;
        return head;
    }
    Node *sortListBubbleSort(Node *list)
    { // sorts the input-ed list
        int temp = 0;
        Node *unSortedElement = list;
        do
        {
            Node *checkElementsPointer = unSortedElement->next;
            while (checkElementsPointer != head)
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
        } while (unSortedElement != head);
    }
    Node *sortByInsertionSort(Node *list)
    {
        Node *currentPointer = list;
        do
        {
            int value = currentPointer->value;
            Node *previous = currentPointer->previous;
            while (previous->next != head && value <= previous->value)
            {
                previous->next->value = previous->value;
                previous = previous->previous;
            }
            previous->next->value = value;
            currentPointer = currentPointer->next;
        } while (currentPointer != head);
        return NULL;
    }
    Node *removeDuplicates(Node *list)
    { // removes duplicates from list
        Node *previousPointer = NULL;
        Node *currentPointer = list;
        while (currentPointer != NULL)
        {
            if (isValueExisted(currentPointer))
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
        list2->previous = current;
        return list1;
    }
    Node *interestLists(Node *list1, Node *list2)
    { // results contains intersection of two lists
        LinkList *interestedList = new LinkList();
        Node *currentCheckPointerList1 = list1;
        do
        {
            // if (isValueExisted(currentCheckPointerList1, list2))
            if (isValueExisted(currentCheckPointerList1, list2))
            {
                if (interestedList->head == NULL)
                {
                    interestedList->insertAtHead(currentCheckPointerList1->value);
                }
                else
                {
                    interestedList->insertAtEnd(currentCheckPointerList1->value);
                }
            }
            currentCheckPointerList1 = currentCheckPointerList1->next;
        } while (currentCheckPointerList1 != head);
        return interestedList->head;
    }

    // Helping Functions
    bool isValueExisted(Node *key, Node *list)
    {
        Node *currentNode = list;
        while (currentNode != list->previous)
        {
            if (currentNode != key)
            {
                break;
            }
            if (currentNode->value == key->value)
            {
                currentNode->previous->next = currentNode->next;
                return true;
            }
            else
            {
                currentNode = currentNode->next;
            }
        }
        return false;
    }
    bool isValueExisted(Node *key)
    {
        Node *currentNode = key->previous;
        while (currentNode->previous != Tail && currentNode != key)
        {
            if (currentNode->value == key->value)
            {
                return true;
            }
            else
            {
                currentNode = currentNode->previous;
            }
        }
        return false;
    }
};
main()
{
    /*                                     Intersection */
    LinkList *list = new LinkList();
    list->insertAtHead(10);
    list->insertAtEnd(20);
    list->insertAtEnd(30);

    LinkList *list2 = new LinkList();
    list2->insertAtHead(40);
    list2->insertAtEnd(20);
    list2->insertAtEnd(30);

    Node *newlistHead = list->interestLists(list->head, list2->head);
    LinkList *IntersectList = new LinkList(newlistHead);
    cout << "-------------------" << endl;
    IntersectList->displayList();
    // _________________________________________________________________________________________________
    /*                                      Merge */
    // LinkList *list = new LinkList();
    // list->insertAtHead(10);
    // list->insertAtEnd(20);
    // list->insertAtEnd(30);

    // LinkList *list2 = new LinkList();
    // list2->insertAtHead(40);
    // list2->insertAtEnd(30);
    // list2->insertAtEnd(20);
    // list->head=list->mergeLists(list->head,list2->head);
    // cout << "-------------------" << endl;
    // list->displayList();

    // _________________________________________________________________________________________________
    /*                                      Insert At */
    // LinkList *list = new LinkList();
    // list->insertAtHead(10);
    // list->insertAtEnd(30);
    // list->insertAtEnd(50);
    // list->insertAtEnd(100);
    // // list->insertNode(0, 20);
    // // list->insertNode(1, 50);
    // // list->deleteNode(10);
    // // list->deleteNode(100);
    // // list->deleteFromStart();
    // // list->deleteFromEnd();
    // list->displayList();
    //__________________________________________________________________________________________________
    /*                                      Delete */
    // LinkList *list = new LinkList();
    // list->insertAtHead(10);
    // list->insertAtEnd(30);
    // list->insertAtEnd(50);
    // list->insertAtEnd(100);
    // list->deleteNode(10);
    // list->deleteNode(100);
    // list->deleteFromStart();
    // list->deleteFromEnd();
    // list->displayList();
    //__________________________________________________________________________________________________
    /*                                      Reverse */
    // LinkList *list = new LinkList();
    // list->insertAtHead(10);
    // list->insertAtEnd(20);
    // list->insertAtEnd(30);
    // list->insertNode(20,90);
    // list->insertNode(5,40);
    // list->insertAtEnd(50);
    // list->insertAtEnd(100);
    // list->displayList();
    // list->reverseList();
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
    // list->sortListBubbleSort(list->head);
    // // list->sortByInsertionSort(list->head);
    // list->displayList();
}
