#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Record{
    int roll;
    char name[100];
    int score;
    struct Record* next;
};

struct Record* createRecord(int roll, char* name, int score){
    struct Record* newRecord = (struct Record*)malloc(sizeof(struct Record));
    newRecord->roll = roll;
    strcpy(newRecord->name, name);
    newRecord->score = score;
    newRecord->next = NULL;

    return newRecord;
}

struct Record* addRecord(struct Record* head){
    printf("Enter details for student record\n");
    int roll, score;
    char name[100];
    printf("Enter roll number: ");
    scanf("%d", &roll);
    printf("Enter name:");
    scanf("%s", name);
    printf("Enter score:");
    scanf("%d", &score);

    struct Record* temp = head;
    while(temp){
        if(temp->roll == roll){
            printf("Roll number must be unique. Try again\n");
            return head;
        }
        temp = temp->next;
    }

    struct Record* newRecord = createRecord(roll, name, score);
    if(head == NULL){
        return newRecord;
    }
    struct Record* current = head;
    while(current->next != NULL){
        current = current->next;
    }
    current->next = newRecord;
    return head;
}   

void printRecords(struct Record* head){
    if(head == NULL){
        printf("No record found\n");
        return;
    }
    printf("Roll Name Score\n");
    struct Record* current = head;
    while(current != NULL){
        printf("%d %s %d\n",current->roll, current->name, current->score);
        current = current->next;
    }
}

struct Record* deleteRecord(struct Record* head,int roll){
    if(head->roll == roll){
        struct Record* temp = head->next;
        free(head);
        return temp;
    }
    struct Record* current = head;
    while(current->next != NULL){
        if(current->next->roll == roll){
            if(current->next->next == NULL){
                current->next = NULL;
                break;
            }
            struct Record* rec = current->next;
            current->next = rec->next;
            free(rec);
        }
        current = current->next;
    }
    return head;
}

int main() {
    int choice, roll;
    struct Record* head = NULL;

    do {
        printf("\n--- Student Record Management System ---\n");
        printf("1. Add Record\n");
        printf("2. Display All Records\n");
        printf("3. Delete a Record\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = addRecord(head);
                break;
            case 2:
                printRecords(head);
                break;
            case 3:
                printf("Enter roll number to be deleted: ");
                scanf("%d", &roll);
                head = deleteRecord(head, roll);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 0);

    return 0;
}