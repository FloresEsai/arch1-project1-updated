#ifndef _HISTORY_
#define _HISTORY_

typedef struct s_Item {
	int id;
	char* str;
	struct s_Item* next;
} Item;

typedef struct s_List {
	Item* root;
} List;

/* Initialize the linked list to keep the history.
   @return List* - the initialized linked list
*/
List* init_history(void);

/* Add a history item to the end of the list.
   @param List* list - the linked list
   @param char* str - the string to store
   @return void
*/
void add_history(List* list, char* str);

/* Retrieve the string stored in the node where Item->id == id.
   @param List* list - the linked list
   @param int id - the id of the Item to find
   @return char* - the string stored in the node
*/
char* get_history(List* list, int id);

/* Print the entire contents of the list.
   @param List* list - the linked list
   @return void
*/
void print_history(List* list);

/* Free the history list and the strings it references.
   @param List* list - the linked list
   @return void
*/
void free_history(List* list);

#endif