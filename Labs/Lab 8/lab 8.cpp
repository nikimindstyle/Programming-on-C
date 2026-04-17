#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COUNT 20
#define MAX_NAME 50

struct person {
    char name[MAX_NAME];
    char surname[MAX_NAME];
    int birth_year;
    char gender;
    float height;
};


void sort_by_year(struct person arr[], int n) {
    struct person temp;
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j].birth_year > arr[j + 1].birth_year) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


void sort_by_surname(struct person arr[], int n) {
    struct person temp;
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j].surname, arr[j + 1].surname) > 0) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


void sort_by_gender(struct person arr[], int n) {
    struct person temp;
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j].gender > arr[j + 1].gender) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


void sort_by_height(struct person arr[], int n) {
    struct person temp;
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j].height > arr[j + 1].height) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


void print_table(struct person arr[], int n) {
    int i;
    printf("\n%-20s %-15s %-6s %-6s %s\n", "Surname", "Name", "Year", "Sex", "Height");
    printf("------------------------------------------------------------\n");
    for (i = 0; i < n; i++) {
        printf("%-20s %-15s %-6d %-6c %.2f\n", 
               arr[i].surname, arr[i].name, arr[i].birth_year, 
               arr[i].gender, arr[i].height);
    }
}

int main() {
    struct person people[COUNT];
    FILE *f;
    int i, count;
    int choice;

    printf("=== Task 8: Sort People Data ===\n\n");
    
    f = fopen("people.txt", "r");
    if (f == NULL) {
        printf("ERROR: Could not open file people.txt\n");
        printf("Please create the file in the project folder.\n");
        return 1;
    }


    count = 0;
    while (count < COUNT && fscanf(f, "%s %s %d %c %f", 
           people[count].surname, 
           people[count].name, 
           &people[count].birth_year, 
           &people[count].gender, 
           &people[count].height) == 5) {
        count++;
    }
    fclose(f);
    
    if (count == 0) {
        printf("File is empty or has invalid format!\n");
        return 1;
    }
    
    printf("Loaded %d records.\n", count);

    printf("\nOriginal data:\n");
    print_table(people, count);


    printf("\nSelect sort criteria:\n");
    printf("1 - Birth Year\n");
    printf("2 - Surname\n");
    printf("3 - Gender\n");
    printf("4 - Height\n");
    printf("Your choice: ");
    scanf("%d", &choice);


    if (choice == 1) {
        sort_by_year(people, count);
        printf("\n=== Sorted by Birth Year ===\n");
    }
    else if (choice == 2) {
        sort_by_surname(people, count);
        printf("\n=== Sorted by Surname ===\n");
    }
    else if (choice == 3) {
        sort_by_gender(people, count);
        printf("\n=== Sorted by Gender ===\n");
    }
    else if (choice == 4) {
        sort_by_height(people, count);
        printf("\n=== Sorted by Height ===\n");
    }
    else {
        printf("Invalid choice!\n");
        return 1;
    }

    print_table(people, count);

    printf("\nDone.\n");
    return 0;
}
