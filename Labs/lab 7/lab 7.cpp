#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COUNT 4
#define MAX_NAME 50

struct human {
    char name[MAX_NAME];
    char surname[MAX_NAME];
    int birth_year;
};

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

void print_humans(struct human arr[], int n) {
    int i;
    printf("\n%-20s %-20s %s\n", "Surname", "Name", "Year");
    printf("------------------------------------------------\n");
    for (i = 0; i < n; i++) {
        printf("%-20s %-20s %d\n", arr[i].surname, arr[i].name, arr[i].birth_year);
    }
}

int main() {
    struct human people[COUNT];
    struct human sorted_people[COUNT];
    int i;

    printf("\nEnter data for 4 people:\n");
    
    for (i = 0; i < COUNT; i++) {
        printf("\nHuman %d:\n", i + 1);
        printf("Surname: ");
        scanf("%s", people[i].surname);
        printf("Name: ");
        scanf("%s", people[i].name);
        printf("Birth year: ");
        scanf("%d", &people[i].birth_year);
    }

    for (i = 0; i < COUNT; i++) {
        sorted_people[i] = people[i];
    }

    sort_by_year(sorted_people, COUNT);

    print_humans(people, COUNT);

    printf("\n Sort by birth year\n");
    print_humans(sorted_people, COUNT);

    printf("\nDone.\n");
    return 0;
}
