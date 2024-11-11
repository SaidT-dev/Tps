#include <stdio.h>
#include <stdlib.h>

typedef struct cellule{ 
    int val;
    struct cellule* suiv;
} cellule;



/*------------------1------------------*/
cellule* createCircularList(int n) {
    cellule* head = NULL;
    cellule* current = NULL;

    // Create the first node
    head = (cellule*)malloc(sizeof(cellule));
    if (head == NULL) {
        printf("Memory allocation failed");
        return NULL;
    }
    head->val = 1;
    head->suiv = NULL;
    current = head;

    // Create the remaining nodes
    for (int i = 2; i <= n; i++) {
        cellule* newNode = (cellule*)malloc(sizeof(cellule));
        if (newNode == NULL) {
            printf("Memory allocation failed");
            return NULL;
        }
        newNode->val = i;
        newNode->suiv = NULL;
        current->suiv = newNode;
        current = newNode;
    }

    // Make the list circular
    current->suiv = head;

    return head;
}

/*------------------2------------------*/
int isListEmpty(cellule* head) {
    if (head == NULL) {
        return 1;
    } else {
        return 0;
    }
}

/*------------------3------------------*/
int countElements(cellule* head) {
    int count = 0;
    if (isListEmpty(head)) {
        return count;
    }
    cellule* current = head;
    do {
        count++;
        current = current->suiv;
    } while (current != head);
    return count;
}

/*------------------4------------------*/
cellule* getElementAtPosition(cellule* head, int position) {
    if (isListEmpty(head)) {
        printf("List is empty");
        return NULL;
    }
    cellule* current = head;
    int count = 1;
    do {
        if (count == position) {
            return current;
        }
        current = current->suiv;
        count++;
    } while (current != head);
    printf("Position out of range");
    return NULL;
}

/*------------------5------------------*/
void insertBeforeValue(cellule* head, int valueU, int valueV) {
    if (isListEmpty(head)) {
        printf("List is empty");
        return;
    }
    cellule* current = head;
    cellule* previous = NULL;
    do {
        if (current->val == valueU) {
            cellule* newNode = (cellule*)malloc(sizeof(cellule));
            if (newNode == NULL) {
                printf("Memory allocation failed");
                return;
            }
            newNode->val = valueV;
            newNode->suiv = current;
            if (previous == NULL) {
                // Insert at the beginning of the list
                head = newNode;
            } else {
                previous->suiv = newNode;
            }
            return;
        }
        previous = current;
        current = current->suiv;
    } while (current != head);
    printf("Value U not found in the list");
}

/*------------------6------------------*/
void deleteValue(cellule** head, int value) {
    if (isListEmpty(*head)) {
        printf("List is empty");
        return;
    }
    cellule* current = *head;
    cellule* previous = NULL;
    do {
        if (current->val == value) {
            if (previous == NULL) {
                // Deleting the first node
                *head = current->suiv;
                free(current);
                current = *head;
            } else {
                previous->suiv = current->suiv;
                free(current);
                current = previous->suiv;
            }
        } else {
            previous = current;
            current = current->suiv;
        }
    } while (current != *head);
}

/*------------------Supp------------------*/
void printList(cellule* head) {
    cellule* current = head;
    do {
        printf("%d ", current->val);
        current = current->suiv;
    } while (current != head);
    printf("\n");
}

int main() {
    // Create a circular list with 5 nodes
    cellule* head = createCircularList(5);

    // Test the isListEmpty function
    int isEmpty = isListEmpty(head);
    if (isEmpty) {
        printf("The list is empty.\n");
    } else {
        printf("The list is not empty.\n");
    }

    // Test the countNodes function
    int count = countElements(head);
    printf("The list has %d nodes.\n", count);

    // Test the getElementAtPosition function
    cellule* element = getElementAtPosition(head, 3);
    if (element != NULL) {
        printf("The element at position 3 has the value %d.\n", element->val);
    }

    // Test the insertBeforeValue function
    insertBeforeValue(head, 3, 10);
    printf("After inserting 10 before 3, the list is: ");
    printList(head);

    // Free the memory allocated for the list
    cellule* temp = head;
    cellule* next;
    do {
        next = temp->suiv;
        free(temp);
        temp = next;
    } while (temp != head);

    return 0;
}