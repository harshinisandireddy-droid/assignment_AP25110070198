#include <stdio.h>

struct Student {
    char name[50];
    int age;
    int total_marks;
};

void show(struct Student s[]) {
    int i;
    printf("\nStudent Details:\n");
    for (i = 0; i < 2; i++) {
        printf("\nStudent %d\n", i + 1);
        printf("Name: %s\n", s[i].name);
        printf("Age: %d\n", s[i].age);
        printf("Total Marks: %d\n", s[i].total_marks);
    }
}

int main() {
    struct Student s[2];
    int i;
    float average;

    for (i = 0; i < 2; i++) {
        printf("\nEnter details of student %d\n", i + 1);

        printf("Enter name: ");
        scanf("%s", s[i].name);

        printf("Enter age: ");
        scanf("%d", &s[i].age);

        printf("Enter total marks: ");
        scanf("%d", &s[i].total_marks);
    }

    show(s);

    average = (s[0].total_marks + s[1].total_marks) / 2.0;
    printf("\nAverage of total marks = %.2f\n", average);

    return 0;
}
