#include <stdio.h>
#include <stdlib.h>

typedef struct {
	void *next; 
	int data;
} Node;

Node *head = NULL;


Node *addNode(int data) {
	
	Node *new = NULL; 
	if (head == NULL) {
		
		new = malloc(sizeof(Node));
		if (new == NULL) {
			return NULL;
		}

		new->data = data; 
		head = new; 
		new->next = NULL;
	} else {

		new = malloc(sizeof(Node));
		if (new == NULL) {
			return NULL; 
		}
		new->data = data; 
		new->next = head; 
		head = new; 
	}
	return new; 
}
int removeNode(int data) {
	Node *current = head; 
	Node *prev = head;
	while(current != NULL) {
		if(current->data == data) {
			if(current == head) {
				head = current->next;
			} else {
				prev->next = current->next;
				free(current); 
				current = NULL;
			}
			return 1;

		}
		prev = current; 
		current = current->next;
	}
	
	return 0; 
}
int insertNode(int pos, int data) { 
	Node *current = head; 
	Node *prev = head; 
	Node *new = malloc(sizeof(Node));
	int count = 1;  
	while(current != NULL) {
		if(count == pos) {
			if(current == head) {
				addNode(data);
				return 1; 
			}
			new->data = data; 
			prev->next = new; 
			new->next = current;
			return 1; 
		} else {
			count++;
			prev = current; 
			current = current->next; 
		}
		
	}
	return 0;
}
void printList() {
	Node *current = head; 
	while (current != NULL) {
		printf("%d->", current->data);
		current = current->next;
	}
}

void printMenu() {
	printf("\nOptions \n");

	printf("\t1. Add Node \n");
	printf("\t2. Remove Node \n");
	printf("\t3. Insert Node \n");
	printf("\t4. Print your List \n");
	printf("\t5. QUIT \n");
	return;
}

int main() {

	int opt = -1; 
	while (opt != 5)  {
		printMenu(); 
		int num_received = scanf("%d", &opt);
		if (num_received == 1 && opt > 0 && opt <= 5) {
			switch(opt) {
				case 1: 
					printf("What Data should be inserted: \n");
					scanf("%d", &opt); 
					Node *new = addNode(opt);
					break;
				case 2: 
					printf("What Data should be removed: \n");
					scanf("%d", &opt);
					int succ = removeNode(opt);
					if(succ == 0) {
						printf("Couldnt find Node \n");
					} else {
						printf("Node Removed \n");
					}
					
					break; 
				case 3: 
					printf("What Data should be inserted: \n");
					scanf("%d", &opt);
					int pos;
					printf("Where should the Data be inserted: \n");
					scanf("%d", &pos);
					succ = insertNode(pos, opt);
					if(succ == 0) {
						printf("Couldnt find Node \n");
					} else {
						printf("Node Inserted \n");
					}
					break;
				case 4: 
					printList();
					break;

				case 5:
					break;
			}
		}
	}

	return 0;
}
