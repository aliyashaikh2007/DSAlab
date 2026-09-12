#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct contact{
    char name[50];
    char phone[50];
    struct contact *next;
};

struct contact *head = NULL;


/*inserting at the beginning*/
void insertatbeginning(){
    struct contact *newcontact;
    newcontact=(struct contact *)malloc(sizeof(struct contact));
    printf("Enter name: ");
    scanf("%s", newcontact->name);
    printf("Enter phone number: ");
    scanf("%s", newcontact->phone);
    newcontact->next = head;
    head = newcontact;
    printf("Contact added successfully!\n");
}


/*inserting at the end*/
void insertatend(){
    struct contact *newcontact, *temp;
    (struct contact *)malloc(sizeof(struct contact));
    printf("Enter name: ");
    scanf("%s", newcontact->name);
    printf("Enter phone number: ");
    scanf("%s", newcontact->phone);
    newcontact->next = NULL;
    if(head==NULL){
        head=newcontact;
    } else {temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newcontact;
    }
    printf("Contact added successfully!\n");
}


/*delete contact by name*/
void deletecontact(){
    struct contact *temp,*prev;
    char name[50];
    printf("Enter name of contact to delete: ");
    scanf("%s", name);
    temp=head;
    while(temp!=NULL){
        if(strcmp(temp->name,name)==0){
            if(temp==head){
                head=temp->next;
            } else {
                prev->next=temp->next;
            }
            free(temp);
            printf("Contact deleted successfully!\n");
            return;
        }
        prev=temp;
        temp=temp->next;
    }
    printf("Contact not found!\n");
}


/*search contact by name*/
void searchcontact(){
    struct contact *temp;
    char name[50];
    printf("Enter name of contact to search: ");
    scanf("%s", name);
    temp=head;
    while(temp!=NULL){
        if(strcmp(temp->name,name)==0){
            printf("Contact found!\n");
            printf("Name: %s, Phone: %s\n", temp->name, temp->phone);
            return;
        }
        temp=temp->next;
    }
    printf("Contact not found!\n");
}


/*display all contacts*/
void displaycontacts(){
    struct contact *temp;
    if(head==NULL){
        printf("No contacts found!\n");
        return;
    }
    temp=head;
    printf("Contacts:\n");
    while(temp!=NULL){
        printf("Name: %s,\nPhone: %s\n", temp->name, temp->phone);
        temp=temp->next;
    }
}

/*free all allocated memory*/
void freecontacts(){
    struct contact *temp;
    while(head!=NULL){
        temp=head;
        head=head->next;
        free(temp);
    }
}


int main(){
    int choice;
    do
    {
        printf("CONTACT MANAGEMENT SYSTEM\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Delete contact\n");
        printf("4. Search contact\n");
        printf("5. Display contacts\n");
        printf("6. Free contacts\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);


        switch(choice)
        {
            case 1:
                insertatbeginning();
                break;
            case 2:
                insertatend();
                break;
            case 3:
                deletecontact();
                break;
            case 4:
                searchcontact();
                break;
            case 5:
                displaycontacts();
                break;
            case 6:
                freecontacts();
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!=7);


    return 0;
    
}
