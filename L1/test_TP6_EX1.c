#include <stdio.h>

void printList(cellule* head) {
    if (isListEmpty(head)) {
        printf("List is empty");
        return;
    }
    cellule* current = head;
    do {
        printf("%d ", current->val);
        current = current->suiv;
    } while (current != head);
    printf("\n");
}

int main() {
    // Test case 1: Create a circular list with 5 elements
    cellule* list1 = createCircularList(5);
    printf("List 1: ");
    printList(list1);

    // Test case 2: Check if the list is empty
    int isEmpty1 = isListEmpty(list1);
    printf("Is List 1 empty? %s\n", isEmpty1 ? "Yes" : "No");

    // Test case 3: Count the number of elements in the list
    int count1 = countElements(list1);
    printf("Number of elements in List 1: %d\n", count1);

    // Test case 4: Get the element at position 3
    cellule* element1 = getElementAtPosition(list1, 3);
    if (element1 != NULL) {
        printf("Element at position 3 in List 1: %d\n", element1->val);
    }

    // Test case 5: Insert value 6 before value 3 in List 1
    insertBeforeValue(list1, 3, 6);
    printf("List 1 after inserting 6 before 3: ");
    printList(list1);

    // Test case 6: Delete value 4 from List 1
    deleteValue(&list1, 4);
    printf("List 1 after deleting 4: ");
    printList(list1);

    return 0;
}int main() {
    // Test case 1: Create a circular list with 5 elements
    cellule* list1 = createCircularList(5);
    printf("List 1: ");
    printList(list1);

    // Test case 2: Check if the list is empty
    int isEmpty1 = isListEmpty(list1);
    printf("Is List 1 empty? %s\n", isEmpty1 ? "Yes" : "No");

    // Test case 3: Count the number of elements in the list
    int count1 = countElements(list1);
    printf("Number of elements in List 1: %d\n", count1);

    // Test case 4: Get the element at position 3
    cellule* element1 = getElementAtPosition(list1, 3);
    if (element1 != NULL) {
        printf("Element at position 3 in List 1: %d\n", element1->val);
    }

    // Test case 5: Insert value 6 before value 3 in List 1
    insertBeforeValue(list1, 3, 6);
    printf("List 1 after inserting 6 before 3: ");
    printList(list1);

    // Test case 6: Delete value 4 from List 1
    deleteValue(&list1, 4);
    printf("List 1 after deleting 4: ");
    printList(list1);

    return 0;
}