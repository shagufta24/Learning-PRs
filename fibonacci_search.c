#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    char id[20];
    char name[50];
    int group;
    int index;
};

//To swap two elements of struct array
void swap(struct student *x, struct student *y)
{
    struct student temp = *x;
    *x = *y;
    *y = temp;
}

void selectionSort(struct student arr[], int n, int opt, char search[])
{
    int i, j, min;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (opt == 1)
            {
                if (strcmp(arr[j].id, arr[min].id) < 0)
                    min = j;
            }
            else if (opt == 2)
            {
                if (strcmp(arr[j].name, arr[min].name) < 0)
                    min = j;
            }
            else if (opt == 3)
            {
                if (arr[j].group < arr[min].group)
                    min = j;
            }
        }
        swap(&arr[min], &arr[i]);
    }
}

int min(int x, int y)
{
    return (x <= y) ? x : y;
}

int fibonacciSearch(struct student arr[], char x[], int n, int opt)
{
    //Opening output file
    FILE *output;
    output = fopen("DAALab_output1.txt", "a");
    if (output == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    int fib2 = 0;          // (m-2)'th Fibonacci No.
    int fib1 = 1;          // (m-1)'th Fibonacci No.
    int fib = fib2 + fib1; // m'th Fibonacci

    // fib stores the smallest Fibonacci Number greater than or equal to n
    while (fib < n)
    {
        fib2 = fib1;
        fib1 = fib;
        fib = fib2 + fib1;
    }

    // Eliminated range from front of array
    int offset = -1;

    while (fib > 1)
    {
        // Checking if fib2 is a valid location
        int i = min(offset + fib2, n - 1);

        // Search by Roll number
        if (opt == 1)
        {
            // If x is greater than the value at index fib2, cut the subarray array from offset to i
            if (strcmp(arr[i].id, x) < 0)
            {
                fib = fib1;
                fib1 = fib2;
                fib2 = fib - fib1;
                offset = i;
            }

            //If x is greater than the value at index fib2, cut the subarray after i+1
            else if (strcmp(arr[i].id, x) > 0)
            {
                fib = fib2;
                fib1 = fib1 - fib2;
                fib2 = fib - fib1;
            }

            // Element found
            else
            {
                fprintf(output, "%s %s %d\n", arr[i].id, arr[i].name, arr[i].group);
                fprintf(output, "Index: %d\n", arr[i].index);
                return arr[i].index;
            }
        }

        // Search by name
        if (opt == 2)
        {
            // If x is greater than the value at index fib2, cut the subarray array from offset to i
            if (strcmp(arr[i].name, x) < 0)
            {
                fib = fib1;
                fib1 = fib2;
                fib2 = fib - fib1;
                offset = i;
            }

            //If x is greater than the value at index fib2, cut the subarray after i+1
            else if (strcmp(arr[i].name, x) > 0)
            {
                fib = fib2;
                fib1 = fib1 - fib2;
                fib2 = fib - fib1;
            }

            // Element found
            else
            {
                fprintf(output, "%s %s %d\n", arr[i].id, arr[i].name, arr[i].group);
                fprintf(output, "Index: %d\n", arr[i].index);
                return arr[i].index;
            }
        }

        //Search by group
        if (opt == 3)
        {
            // If x is greater than the value at index fib2, cut the subarray array from offset to i
            if (arr[i].group < atoi(x))
            {
                fib = fib1;
                fib1 = fib2;
                fib2 = fib - fib1;
                offset = i;
            }

            //If x is greater than the value at index fib2, cut the subarray after i+1
            else if (arr[i].group > atoi(x))
            {
                fib = fib2;
                fib1 = fib1 - fib2;
                fib2 = fib - fib1;
            }

            // Element found
            else
            {
                fprintf(output, "%s %s %d\n", arr[i].id, arr[i].name, arr[i].group);
                fprintf(output, "Index: %d\n", arr[i].index);
                return arr[i].index;
            }
        }
    }

    // comparing the last element with x
    if (opt == 1) //Roll no
    {
        if (fib1 && strcmp(arr[offset + 1].name, x) == 0)
        {
            fprintf(output, "%s %s %d\n", arr[offset + 1].id, arr[offset + 1].name, arr[offset + 1].group);
            fprintf(output, "Index: %d\n", arr[offset + 1].index);
            return offset + 1;
        }
    }
    if (opt == 2) //Name
    {
        if (fib1 && strcmp(arr[offset + 1].name, x) == 0)
        {
            fprintf(output, "%s %s %d\n", arr[offset + 1].id, arr[offset + 1].name, arr[offset + 1].group);
            fprintf(output, "Index: %d\n", arr[offset + 1].index);
            return offset + 1;
        }
    }

    if (opt == 3) //Group
    {
        if (fib1 && arr[offset + 1].group == atoi(x))
        {
            fprintf(output, "%s %s %d\n", arr[offset + 1].id, arr[offset + 1].name, arr[offset + 1].group);
            fprintf(output, "Index: %d\n", arr[offset + 1].index);
            return offset + 1;
        }
    }

    // element not found
    fprintf(output, "Element not found.\n");
    return -1;
}

int main(int argc, char *argv[])
{

    if (argc == 3)
    {
        //Option for searching criteria
        int opt = atoi(argv[1]);

        if (opt == 1 || opt == 2 || opt == 3)
        {
            //Which element to search for
            char search[30];
            strcpy(search, argv[2]);

            int i = 0;
            int total = 86;
            struct student slist[total];

            //Reading input file
            FILE *fp;
            fp = fopen("DAALab_input1.txt", "r");
            if (fp == NULL)
            {
                printf("Error opening file\n");
                return 1;
            }

            //Assigning indices
            while (fscanf(fp, "%s %s %i", slist[i].id, slist[i].name, &(slist[i].group)) != EOF)
            {
                slist[i].index = i;
                i++;
            }

            //Clearing output file
            fp = fopen("DAALab_output1.txt", "w");
            if (fp == NULL)
            {
                printf("Error opening file\n");
                return 1;
            }

            //Sorting
            selectionSort(slist, total, opt, search);

            //Running fibonacci search
            int ind = fibonacciSearch(slist, search, total, opt);
            printf("Found at position %d\n", ind);

            fclose(fp);
            return 0;
        }
        else
        {
            printf("\nInvalid input.");
            return 1;
        }
    }
    else
    {
        printf("\nInvalid input.");
        return 1;
    }
}
