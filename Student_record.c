#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    float marks;
    struct Student *next;
};

struct Student *head = NULL;

void addStudent();
void displayStudents();
void searchStudent();
void sortStudents();
void deleteStudent();

int main() {
    int choice;

    while (1) {
        printf("\n===== Student Record Management System =====\n");
        printf("1. Add Student Record\n");
        printf("2. Display All Records\n");
        printf("3. Search Student (by Roll No)\n");
        printf("4. Sort Students (by Roll No)\n");
        printf("5. Delete Student Record\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                sortStudents();
                break;
            case 5:
                deleteStudent();
                break;
            case 6:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void addStudent() {
    struct Student *newNode, *temp;
    newNode = (struct Student *)malloc(sizeof(struct Student));

    printf("Enter Roll Number: ");
    scanf("%d", &newNode->roll);
    printf("Enter Name: ");
    scanf("%s", newNode->name);
    printf("Enter Marks: ");
    scanf("%f", &newNode->marks);

    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    printf("Student record added successfully.\n");
}

void displayStudents() {
    struct Student *temp = head;

    if (head == NULL) {
        printf("No student records found.\n");
        return;
    }

    printf("\nRoll No\tName\tMarks\n");
    while (temp != NULL) {
        printf("%d\t%s\t%.2f\n", temp->roll, temp->name, temp->marks);
        temp = temp->next;
    }
}

void searchStudent() {
    int roll;
    struct Student *temp = head;

    printf("Enter Roll Number to search: ");
    scanf("%d", &roll);

    while (temp != NULL) {
        if (temp->roll == roll) {
            printf("Record Found!\n");
            printf("Roll No: %d\nName: %s\nMarks: %.2f\n",
                   temp->roll, temp->name, temp->marks);
            return;
        }
        temp = temp->next;
    }
    printf("Student record not found.\n");
}

void sortStudents() {
    struct Student *i, *j;
    int tempRoll;
    float tempMarks;
    char tempName[50];

    if (head == NULL) {
        printf("No records to sort.\n");
        return;
    }

    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->roll > j->roll) {
                tempRoll = i->roll;
                i->roll = j->roll;
                j->roll = tempRoll;

                tempMarks = i->marks;
                i->marks = j->marks;
                j->marks = tempMarks;

                strcpy(tempName, i->name);
                strcpy(i->name, j->name);
                strcpy(j->name, tempName);
            }
        }
    }
    printf("Student records sorted successfully.\n");
}

void deleteStudent() {
    int roll;
    struct Student *temp = head, *prev = NULL;

    printf("Enter Roll Number to delete: ");
    scanf("%d", &roll);

    if (head == NULL) {
        printf("No records available.\n");
        return;
    }

    if (head->roll == roll) {
        temp = head;
        head = head->next;
        free(temp);
        printf("Student record deleted successfully.\n");
        return;
    }

    while (temp != NULL && temp->roll != roll) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Student record not found.\n");
    } else {
        prev->next = temp->next;
        free(temp);
        printf("Student record deleted successfully.\n");
    }
}
