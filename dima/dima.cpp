#include <stdio.h>
#include <stdlib.h>




void writeEmp(int emp) {
    FILE* fpointer = fopen_s("emp.txt", "a");
    for (int i = 0; i < emp; i++) {
        printf("Enter first name: ");
        char name1[20];
        scanf("%s", name1);
        fprintf(fpointer, name1);

        printf("Enter last name: ");
        char name2[20];
        scanf_s("%s", name2);
        fprintf(fpointer, " %s \n", name2);

        for (int j = 1; j < 8; j++) {
            int det;
            printf("Enter number of details made in %d day of the week: ", j);
            scanf_s("%d", &det);
            fprintf(fpointer, "%d ", det);

        }
    }

    fclose(fpointer);
}


int main()
{
    writeEmp(2);

    return 0;
}

