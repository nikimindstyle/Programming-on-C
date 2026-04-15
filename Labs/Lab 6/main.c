#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 256

int main() {
    FILE *src_file = 0;
    FILE *dst_file = 0;
    
    char buffer[MAX_LINE];
    char last_name[50], first_name[50], mid_name[50];
    int birth_year = 0;
    int k;

    src_file = fopen("database.txt", "r");
    if (src_file == 0) {
        printf("ERROR\n");
        printf("Please create the file.\n");
        return 0;
    }
    
    
    dst_file = fopen("filtered_result.txt", "w");
    if (dst_file == 0) {
        printf("ERROR\n");
        fclose(src_file);
        return 0;
    }
    while (!feof(src_file)) {
        memset(buffer, 0, MAX_LINE);
        
        if (fgets(buffer, MAX_LINE, src_file) == 0) {
            break; 
        }
        if (strlen(buffer) < 5) continue; 
        if (sscanf(buffer, "%s %s %s %d", last_name, first_name, mid_name, &birth_year) != 4) {
            continue;
        }
        if (birth_year > 1980 && (last_name[0] == 'O' || last_name[0] == 'o')) {
            fprintf(dst_file, "%s %s %s %d\n", last_name, first_name, mid_name, birth_year);
            printf("%s %s (%d)\n", last_name, first_name, birth_year);
        }
    }
    fclose(src_file);
    fclose(dst_file);
    return 0;
}
