#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int roll;
    char name[50];
    float score;
} Student;

typedef int (*CompareFunc)(const void *, const void *);

void sort(Student *students, int n, CompareFunc cmp) {
    Student temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (cmp(&students[i], &students[j]) > 0) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}


// Compare by roll number (ascending)
int compare_roll_asc(const void *a, const void *b) {
    Student *studentA = (Student *)a;
    Student *studentB = (Student *)b;
    return studentA->roll - studentB->roll;
}

// Compare by roll number (descending)
int compare_roll_desc(const void *a, const void *b) {
    Student *studentA = (Student *)a;
    Student *studentB = (Student *)b;
    return studentB->roll - studentA->roll;
}

// Compare by score (ascending)
int compare_score_asc(const void *a, const void *b) {
    Student *studentA = (Student *)a;
    Student *studentB = (Student *)b;
    if (studentA->score > studentB->score) return 1;
    if (studentA->score < studentB->score) return -1;
    return 0;
}

// Compare by score (descending)
int compare_score_desc(const void *a, const void *b) {
    Student *studentA = (Student *)a;
    Student *studentB = (Student *)b;
    if (studentA->score < studentB->score) return 1;
    if (studentA->score > studentB->score) return -1;
    return 0;
}

void print_students(Student *students, int n) {
    printf("Roll\tName\t\tScore\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%s\t%.2f\n", students[i].roll, students[i].name, students[i].score);
    }
}

int main() {
    int n;
    printf("Enter number of students:");
    scanf("%d",&n);
    Student students[n];
    for(int i=0; i<n; i++){
        printf("Enter details of student %d\n",i+1);
        printf("Enter roll: ");
        scanf("%d",&students[i].roll);
        printf("Enter name: ");
        scanf("%s",students[i].name);
        printf("Enter score: ");
        scanf("%f",&students[i].score);
    }

    int criteria, order;
    
    printf("Select sorting criteria:\n");
    printf("1. Roll Number\n");
    printf("2. Score\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &criteria);
    
    printf("Select sorting order:\n");
    printf("1. Ascending\n");
    printf("2. Descending\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &order);
    
    CompareFunc cmp = NULL;

    if (criteria == 1 && order == 1) {
        cmp = compare_roll_asc;
    } 
    else if (criteria == 1 && order == 2) {
        cmp = compare_roll_desc;
    } 
    else if (criteria == 2 && order == 1) {
        cmp = compare_score_asc;
    } 
    else if (criteria == 2 && order == 2) {
        cmp = compare_score_desc;
    } 
    else {
        printf("Invalid input. Exiting.\n");
        return 1;
    }

    sort(students, n, cmp);

    printf("\nSorted list of students:\n");
    print_students(students, n);

    return 0;
}
