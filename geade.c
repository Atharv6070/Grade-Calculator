#include <stdio.h>

#define MAX_STUDENTS 50

typedef struct {
    char name[50];
    float grade;
} Student;

void addStudent(Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Cannot add more students.\n");
        return;
    }
    printf("Enter student name: ");
    scanf("%s", students[*count].name);
    printf("Enter student grade: ");
    scanf("%f", &students[*count].grade);
    (*count)++;
}

void displayStudents(Student students[], int count) {
    printf("Student List:\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Grade: %.2f\n", students[i].name, students[i].grade);
    }
}

float calculateAverage(Student students[], int count) {
    float sum = 0;
    for (int i = 0; i < count; i++) {
        sum += students[i].grade;
    }
    return sum / count;
}

int main() {
    Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    do {
        printf("1. Add Student\n2. Display Students\n3. Calculate Average Grade\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(students, &count); break;
            case 2: displayStudents(students, count); break;
            case 3: printf("Average Grade: %.2f\n", calculateAverage(students, count)); break;
            case 4: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}
