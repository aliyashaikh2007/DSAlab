#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct contact {
    char name[50];
    char phone[50];
    struct contact *next;
};

struct contact *head = NULL;


/*inserting at the beginning*/
void insertatbeginning() {
    struct contact *newcontact;
    (struct contact *)malloc(sizeof(struct contact));
    printf("Enter name: ");
    scanf("%s", contact->name);
    printf("Enter phone number: ");
    scanf("%s", contact->phone);
    newcontact->next = head;
    head = newcontact;
    printf("Contact added successfully!\n");
}


/*inserting at the end*/
void insertatend() {
    struct contact *newcontact, *temp;
    (struct contact *)malloc(sizeof(struct contact));
    printf("Enter name: ");
    scanf("%s", contact->name);
    printf("Enter phone number: ");
    scanf("%s", contact->phone);
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
