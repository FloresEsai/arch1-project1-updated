#include <stdio.h>
#include <stdlib.h>
#include <history.h>
#include <tokenizer.h>

/**
 * Initialize the linked list to keep the history.
 *
 * @return Pointer to the newly created list.
 */
List* init_history(void);

/**
 * Add a history item to the end of the list.
 *
 * @param list Pointer to the linked list.
 * @param str Pointer to the string to store.
 */
void add_history(List* list, char* str);

/**
 * Retrieve the string stored in the node where Item->id == id.
 *
 * @param list Pointer to the linked list.
 * @param id The id of the Item to find.
 * @return Pointer to the string stored in the node, or NULL if not found.
 */
char* get_history(List* list, int id);

/**
 * Print the entire contents of the list.
 *
 * @param list Pointer to the linked list.
 */
void print_history(List* list);

/**
 * Free the history list and the strings it references.
 *
 * @param list Pointer to the linked list.
 */
void free_history(List* list);

List* init_history(void) {
    List* list = malloc(sizeof(List)); // allocates memory the size of the list
    list->root = malloc(sizeof(Item)); // allocates memory for the initial item known as root
    return list;
}

void add_history(List* list, char* str) {
    int id = 1;
    Item* temp = list->root;

    while (temp->next != NULL) {
        temp = temp->next;
        id++;
    }

    // allocate memory for the given string
    temp->next = malloc(sizeof(Item));
    temp->next->str = copy_str(str, strlen(str) + 1);
    temp->next->id = id;
}

char* get_history(List* list, int id) {
    Item* item = list->root;
    while (item != NULL) {
        if (item->id == id) { // if we reach the desired token we return it to the user
            return item->str;
        }
        item = item->next;
    }
    return NULL;
}

void print_history(List* list) {
    Item* temp = list->root->next;
    while (temp != NULL) {
        printf("%d. %s", temp->id, temp->str);
        temp = temp->next;
    }
}

void free_history(List* list) {
    Item* curr = list->root;
    while (curr->next != NULL) {
        Item* prev = curr; // the current node that is to be freed
        curr = curr->next;
        free(prev->str);
        free(prev);
    }
    free(curr->str); // free the string in the last node
    free(curr);      // free the last node
    free(list);      // free the list
}