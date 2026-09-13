#include<stdio.h>
int main(){
    int marks[100],n,choice; 
    printf("enter the numbers of student:\n");
    scanf("%d",&n);

    do{
        printf("====================================\n"); 
        printf("STUDETNS MARKS MANAGEMENT SYSTEM\n");
        printf("1. insert marks\n");
        printf("2. display marks\n");
        printf("3. delete marks\n");
        printf("4. bubble sort marks\n");
        printf("5. linear search\n");
        printf("6. binary search\n");
        printf("7. terminate\n");
        printf("====================================\n"); 
        printf("enter your choice:\n");
        scanf("%d",&choice);

    switch(choice){

        case 1:
            printf("enter the marks of %d students:\n", n);
            for(int i=0;i<n;i++){
                scanf("%d",&marks[i]);
            }
            printf("Marks inserted successfully.\n");
            break;

        case 2:
            if (n == 0) {
                printf("No marks to display.\n");
            } else {
                printf("the marks of students are:\n");
                for(int i=0;i<n;i++){
                    printf("%d\n",marks[i]);
                }
                printf("\n");
            }
            break;

        case 3:
            if (n == 0) {
                printf("No marks to delete.\n");
                break;
            } else {
                int pos;
                printf("enter the position of the mark to delete (1 to %d):\n", n);
                scanf("%d",&pos);
                if(pos<1 || pos>n){
                    printf("Invalid index.\n");
                } else {
                    for(int i=pos-1;i<n-1;i++){
                        marks[i] = marks[i+1];
                    }
                    n--;
                    printf("Mark deleted successfully.\n");
                }   
            }
            break;

        case 4:
            if (n == 0) {
                printf("No marks to sort.\n");
                break;
            } else {
                for(int i=0;i<n-1;i++){
                    for(int j=0;j<n-i-1;j++){
                        if(marks[j]>marks[j+1]){
                            int temp = marks[j];
                            marks[j] = marks[j+1];
                            marks[j+1] = temp;
                        }
                    }
                }
                printf("Marks sorted successfully.\n");
            }
            break; 
        case 5:
            if (n == 0) {
                printf("No marks to search.\n");
                break;
            } else {
                int key, found = 0;
                printf("enter the mark to search:\n");
                scanf("%d",&key);
                for(int i=0;i<n;i++){
                    if(marks[i]==key){
                        printf("Mark found at position %d\n",i+1);
                        found = 1;
                        break;
                    }
                }
                if(found==0){
                    printf("Mark not found.\n");
                }
            }
            break;
        case 6:
            if (n == 0) {
                printf("No marks to search.\n");
                break;
            } else {
                int key, found = 0, low = 0, high = n - 1, mid;
                printf("enter the mark to search:\n");
                scanf("%d",&key);
                while(low <= high){
                    mid = (low + high) / 2;
                    if(marks[mid] == key){
                        printf("Mark found at position %d\n",mid+1);
                        found = 1;
                        break;
                    } else if(marks[mid] < key){
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }
                if(found==0){
                    printf("Mark not found.\n");
                }
            }
            break;
        case 7:
            printf("Terminating the program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");       
    }
} while(choice != 7);

    return 0;
}
