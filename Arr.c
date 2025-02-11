#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int *RandFillIntArr(int size) // for int
{
    int *arr = (int *)malloc(size * sizeof(int));
    srand(time(NULL));
    printf("[ ");
    for (int i = 0; i < size; i++)
    {
        *(arr + i) = (int)(rand() % 100);
        printf("%d ", *(arr + i));
    }
    printf("]\n");

    return arr;
}

float *RandFillFloatArr(int size) // for float
{
    float *arr = (float *)malloc(size * sizeof(float));
    srand(time(NULL));

    printf("[ ");
    for (int i = 0; i < size; i++)
    {
        *(arr + i) = (float)rand() / RAND_MAX * 100.0f;
        printf("%.3f ", *(arr + i));
    }
    printf("]\n");

    return arr;
}

char *RandFillCharArr(int size) // for char
{
    char *arr = (char *)malloc(size * sizeof(char));
    srand(time(NULL));

    printf("[ ");
    for (int i = 0; i < size; i++)
    {
        *(arr + i) = (char)(rand() % 255);
        printf("%c ", *(arr + i));
    }
    printf("]\n");

    return arr;
}

int RecursFind(int *arr, int val, int size) // for int
{
    static int i = 0;

    if (size <= i)
    {
        printf("%d: Nothing was found!\n", val);
        return -1;
    }

    if (*(arr + i) == val)
    {
        printf("%d is found!\n", val);
        return val;
    }

    i++;
    return RecursFind(arr, val, size);
}

float RecursFind(float *arr, float val, int size) // for float
{
    static int i = 0;

    if (size <= i)
    {
        printf("%.3f: Nothing was found!\n", val);
        return -1;
    }

    if (*(arr + i) == val)
    {
        printf("%.3f is found!\n", val);
        return val;
    }

    i++;
    return RecursFind(arr, val, size);
}

char RecursFind(char *arr, char val, int size) // for char
{
    static int i = 0;

    if (size <= i)
    {
        printf("\'%c\': Nothing was found!\n", val);
        return -1;
    }

    if (*(arr + i) == val)
    {
        printf("\'%c\' is found!\n", val);
        return val;
    }

    i++;
    return RecursFind(arr, val, size);
}

int BinarySearch(int *arr, int val, int size) // for int
{
    int a = 0, b = size - 1;

    while (a <= b)
    {
        int md = (a + b) / 2;

        if (*(arr + md) == val)
        {
            printf("%d is found!\n", val);
            return val;
        }

        if (*(arr + md) < val)
        {
            a = md + 1;
        }
        else
        {
            b = md - 1;
        }
    }

    printf("Nothing was found!\n");
    return -1;
}

float BinarySearch(float *arr, float val, int size) // for float
{
    int a = 0, b = size - 1;

    while (a <= b)
    {
        int md = (a + b) / 2;

        if (*(arr + md) == val)
        {
            printf("%d is found!\n", val);
            return val;
        }

        if (*(arr + md) < val)
        {
            a = md + 1;
        }
        else
        {
            b = md - 1;
        }
    }

    printf("Nothing was found!\n");
    return -1;
}

char BinarySearch(char *arr, char val, int size) // for char
{
    int a = 0, b = size - 1;

    while (a <= b)
    {
        int md = (a + b) / 2;

        if (*(arr + md) == val)
        {
            printf("%d is found!\n", val);
            return val;
        }

        if (*(arr + md) < val)
        {
            a = md + 1;
        }
        else
        {
            b = md - 1;
        }
    }

    printf("Nothing was found!\n");
    return -1;
}

void ChooseType(int **int_arr, float **float_arr, char **char_arr, int size)
{
    char ch = '0';

    while (ch == '0')
    {
        printf("\n i - integer\n f - float\n c - character\n q - exit\nChoose your value type: ");
        scanf("%c", &ch);

        switch (ch)
        {
        case 'i':
            *int_arr = RandFillIntArr(size);
            RecursFind(*int_arr, 24, size);
            break;

        case 'f':
            *float_arr = RandFillFloatArr(size);
            RecursFind(*float_arr, 0.003, size);
            break;

        case 'c':
            *char_arr = RandFillCharArr(size);
            RecursFind(*char_arr, '$', size);
            break;

        case 'q':
            return;
            break;

        default:
            ch = '0';
            break;
        }
    }
}

int main()
{
    int *int_arr = NULL;
    float *float_arr = NULL;
    char *char_arr = NULL;

    ChooseType(&int_arr, &float_arr, &char_arr, 10);

    free(int_arr);
    free(float_arr);
    free(char_arr);
    return 0;
}
