
#include <stdio.h>
#define SIZE 10

int hashTable[SIZE];

// Initialize hash table
void initialize() {
    int i;
    for(i = 0; i < SIZE; i++) {
        hashTable[i] = -1;
    }
}

// Hash function
int hashFunction(int key) {
    return key % SIZE;
}

// Insert book ID using Linear Probing
void insert(int key) {
    int index = hashFunction(key);
    int i;

    for(i = 0; i < SIZE; i++) {
        int newIndex = (index + i) % SIZE;

        if(hashTable[newIndex] == -1) {
            hashTable[newIndex] = key;
            printf("Book ID inserted successfully!\n");
            return;
        }
    }

    printf("Hash table is full!\n");
}

// Search for a book ID
void search(int key) {
    int index = hashFunction(key);
    int i;

    for(i = 0; i < SIZE; i++) {
        int newIndex = (index + i) % SIZE;

        if(hashTable[newIndex] == key) {
            printf("Book ID found at index %d\n", newIndex);
            return;
        }

        if(hashTable[newIndex] == -1) {
            break;
        }
    }

    printf("Book ID not found!\n");
}

// Display hash table
void display() {
    int i;

    printf("\nHash Table:\n");

    for(i = 0; i < SIZE; i++) {
        if(hashTable[i] == -1)
            printf("%d : Empty\n", i);
        else
            printf("%d : %d\n", i, hashTable[i]);
    }
}

int main() {
    int choice, key;

    initialize();

    do {
        printf("\n--- Library Book Indexing ---");
        printf("\n1. Insert Book ID");
        printf("\n2. Search Book ID");
        printf("\n3. Display Hash Table");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter Book ID: ");
                scanf("%d", &key);
                insert(key);
                break;

            case 2:
                printf("Enter Book ID to search: ");
                scanf("%d", &key);
                search(key);
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while(choice != 4);

    return 0;
}
