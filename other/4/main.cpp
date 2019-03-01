#include <iostream>
using namespace std;
struct List
{
    int value;
    List* next;
};

static List* Head = nullptr, *End = nullptr;
static int massive[] = {1,2,3,4,5,6,7,8,9,10};

List* Adding() {
    List* head = nullptr, *current = nullptr;
    for (size_t i = 0; i < sizeof(massive)/sizeof(massive[0]); ++i) {
        if (!current) {
            current = new List();
            current->value = massive[i];
            head = current;
            current->next = nullptr;
        } else {
            current->next = new List();
            current = current->next;
            current->value = massive[i];
            current->next = nullptr;
        }
    }
    Head = head;
    End = current;
    return head;
}

void Print(List* list) {
 	while (list) {
 		cout << list->value << " ";
 		list = list->next;
 	}
 	cout << endl;
 }

 void Free(List* &Head) {
 	List* temp = nullptr;
 	while (Head) {
 		temp = Head->next;
 		delete Head;
 		Head = temp;
 	}
 }
int main() {
    List* current = Adding(), *after_current = nullptr;
    int min = current->value;
    int i = 0;
    bool flag = true;
    while (current) {
        i++;
        if (current == Head && flag) {
            after_current = current;
        } else if (current != End ){
            after_current = current->next;
        }

        if (after_current == Head && flag) {
            List* adding = new List(); adding->value = i;
            if (after_current->value % 2) {
                adding->next = current->next;
                current->next = adding;
                Head = adding;
                List* deleting = current;
                current = adding;
                delete deleting;
                flag = false;
            } else if (flag) {
                adding->next = current->next;
                current->next = adding;
                Head = current;
                current = current->next;
                flag = false;
            }
        } else if (after_current == End) {
            List* adding = new List(); adding->value = i;
            if (after_current->value % 2) {
                List* deleting = after_current;
                current->next = adding;
                delete deleting;
                break;
            } else {
                after_current->next = adding;
                break;
            }
        } else {
            List* adding = new List(); adding->value = static_cast<int>(i);
            if (after_current->value % 2) {
                adding->next = after_current->next;
                current = current->next = adding;
            } else {
                adding->next = after_current->next;
                after_current->next = adding;
                current = after_current->next;
            }
        }
    }
    Print(Head);
    Free(Head);
    return 0;
}