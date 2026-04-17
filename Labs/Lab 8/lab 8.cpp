#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COUNT 4
#define MAX_NAME 50

// === Task 7: Basic structure ===
struct human {
    char name[MAX_NAME];
    char surname[MAX_NAME];
    int birth_year;
};

// === Task 8: Extended structure (added gender and height) ===
struct human_full {
    char name[MAX_NAME];
    char surname[MAX_NAME];
    int birth_year;
    char gender;      // 'm' or 'f'
    float height;     // in meters
};

// === Task 7: Sort by year (bubble sort) ===
void sort_by_year(struct human arr[], int n) {
    struct human temp;
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

// === Task 8: Extended sort function (can sort by different fields) ===
void sort_full_array(struct human_full arr[], int n, int sort_key) {
    struct human_full temp;
    int i, j;
    int swap;
    
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            swap = 0;
            
            // Same logic as Task 7, but with choices
            if (sort_key == 1) {  // By year
                if (arr[j].birth_year > arr[j + 1].birth_year) swap = 1;
            }
            else if (sort_key == 2) {  // By surname
                if (strcmp(arr[j].surname, arr[j + 1].surname) > 0) swap = 1;
            }
            else if (sort_key == 3) {  // By gender
                if (arr[j].gender > arr[j + 1].gender) swap = 1;
            }
            else if (sort_key == 4) {  // By height
                if (arr[j].height > arr[j + 1].height) swap = 1;
            }
            
            if (swap) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// === Task 7: Print function ===
void print_humans(struct human arr[], int n) {
    int i;
    printf("\n%-20s %-20s %s\n", "Surname", "Name", "Year");
    printf("------------------------------------------------\n");
    for (i = 0; i < n; i++) {
        printf("%-20s %-20s %d\n", arr[i].surname, arr[i].name, arr[i].birth_year);
    }
}

// === Task 8: Extended print function ===
void print_full_humans(struct human_full arr[], int n) {
    int i;
    printf("\n%-20s %-15s %-6s %-6s %s\n", "Surname", "Name", "Year", "Sex", "Height");
    printf("------------------------------------------------------------\n");
    for (i = 0; i < n; i++) {
        printf("%-20s %-15s %-6d %-6c %.2f\n", 
               arr[i].surname, arr[i].name, arr[i].birth_year, 
               arr[i].gender, arr[i].height);
    }
}

// === Task 7 function ===
void task7() {
    struct human people[COUNT];
    struct human sorted_people[COUNT];
    int i;

    printf("\n=== Task 7: Sort by Birth Year ===\n");
    printf("\nEnter data for %d people:\n", COUNT);
    
    for (i = 0; i < COUNT; i++) {
        printf("\nPerson %d:\n", i + 1);
        printf("Surname: ");
        scanf("%s", people[i].surname);
        printf("Name: ");
        scanf("%s", people[i].name);
        printf("Birth year: ");
        scanf("%d", &people[i].birth_year);
    }

    // Copy array (as required in task)
    for (i = 0; i < COUNT; i++) {
        sorted_people[i] = people[i];
    }

    // Sort the copy
    sort_by_year(sorted_people, COUNT);

    printf("\n=== Original Array ===\n");
    print_humans(people, COUNT);

    printf("\n=== Sorted by Birth Year ===\n");
    print_humans(sorted_people, COUNT);
}

// === Task 8 function (extended version of Task 7) ===
void task8() {
    struct human_full people_full[COUNT];
    FILE *f;
    int i, sort_option;

    printf("\n=== Task 8: Sort Data from File ===\n");
    
    f = fopen("people_full.txt", "r");
    if (f == NULL) {
        printf("ERROR: Could not open file people_full.txt\n");
        printf("Please create the file in the project folder.\n");
        return;
    }

    // Read from file (similar to keyboard input in Task 7)
    i = 0;
    while (i < COUNT && fscanf(f, "%s %s %d %c %f", 
           people_full[i].surname, 
           people_full[i].name, 
           &people_full[i].birth_year, 
           &people_full[i].gender, 
           &people_full[i].height) == 5) {
        i++;
    }
    fclose(f);
    
    if (i == 0) {
        printf("File is empty or has invalid format.\n");
        return;
    }
    
    printf("Records loaded: %d\n", i);

    // Choose sort criteria (extension of Task 7)
    printf("\nSelect sort criteria:\n");
    printf("1 - Birth Year (same as Task 7)\n");
    printf("2 - Surname\n");
    printf("3 - Gender\n");
    printf("4 - Height\n");
    printf("Your choice: ");
    scanf("%d", &sort_option);

    sort_full_array(people_full, i, sort_option);

    printf("\n=== Sort Result ===\n");
    print_full_humans(people_full, i);
}

// === Main menu ===
int main() {
    int choice;

    printf("=================================\n");
    printf("   LABORATORY WORK 6\n");
    printf("   Structures and Sorting\n");
    printf("=================================\n");
    
    while (1) {
        printf("\nSelect task:\n");
        printf("1 - Task 7 (Basic structures, keyboard input)\n");
        printf("2 - Task 8 (Extended structures, file input)\n");
        printf("0 - Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            task7();
        }
        else if (choice == 2) {
            task8();
        }
        else if (choice == 0) {
            printf("Goodbye!\n");
            break;
        }
        else {
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
