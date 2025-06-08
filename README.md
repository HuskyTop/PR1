# PR1 (12 варіант)

### Отже, згідно з моїм варіантом, мені треба було, використовуючи стандарт ANSI C, створити програму на мові С, яка б:
### Заповнювала масив випадковими значеннями, використовуючи покажчики.<br>Мала функцію пошуку заданого значення в цьому масиві за допомогою рекурсії.<br>Мала б додаткову функцію для бінарного пошуку, якщо масив відсортований.<br>Отримала б можливість вибору типу даних (int, float, char) через параметри командного рядка.
### Поглянемо на код:
```
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int *RandFillIntArr(int size)
{
    int *arr = (int *)malloc(size * sizeof(int));
    printf("[ ");
    for (int i = 0; i < size; i++)
    {
        *(arr + i) = rand() % 100;
        printf("%d ", *(arr + i));
    }
    printf("]\n");
    return arr;
}

float *RandFillFloatArr(int size)
{
    float *arr = (float *)malloc(size * sizeof(float));
    printf("[ ");
    for (int i = 0; i < size; i++)
    {
        *(arr + i) = (float)rand() / RAND_MAX * 100.0f;
        printf("%.3f ", *(arr + i));
    }
    printf("]\n");
    return arr;
}

char *RandFillCharArr(int size)
{
    char *arr = (char *)malloc(size * sizeof(char));
    printf("[ ");
    for (int i = 0; i < size; i++)
    {
        *(arr + i) = (char)(rand() % 255);
        printf("%c ", *(arr + i));
    }
    printf("]\n");
    return arr;
}

int RecursFindInt(int *arr, int val, int size, int i)
{
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
    return RecursFindInt(arr, val, size, i + 1);
}

float RecursFindFloat(float *arr, float val, int size, int i)
{
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
    return RecursFindFloat(arr, val, size, i + 1);
}

char RecursFindChar(char *arr, char val, int size, int i)
{
    if (size <= i)
    {
        printf("'%c': Nothing was found!\n", val);
        return -1;
    }
    if (*(arr + i) == val)
    {
        printf("'%c' is found!\n", val);
        return val;
    }
    return RecursFindChar(arr, val, size, i + 1);
}

int BinarySearchInt(int *arr, int val, int size)
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
            a = md + 1;
        else
            b = md - 1;
    }
    printf("Nothing was found!\n");
    return -1;
}

float BinarySearchFloat(float *arr, float val, int size)
{
    int a = 0, b = size - 1;
    while (a <= b)
    {
        int md = (a + b) / 2;
        if (*(arr + md) == val)
        {
            printf("%.3f is found!\n", val);
            return val;
        }
        if (*(arr + md) < val)
            a = md + 1;
        else
            b = md - 1;
    }
    printf("Nothing was found!\n");
    return -1;
}

char BinarySearchChar(char *arr, char val, int size)
{
    int a = 0, b = size - 1;
    while (a <= b)
    {
        int md = (a + b) / 2;
        if (*(arr + md) == val)
        {
            printf("'%c' is found!\n", val);
            return val;
        }
        if (*(arr + md) < val)
            a = md + 1;
        else
            b = md - 1;
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
        scanf(" %c", &ch);  // пробіл перед %c щоб пропустити символ '\n'

        switch (ch)
        {
        case 'i':
            *int_arr = RandFillIntArr(size);
            RecursFindInt(*int_arr, 24, size, 0);
            break;

        case 'f':
            *float_arr = RandFillFloatArr(size);
            RecursFindFloat(*float_arr, 0.003f, size, 0);
            break;

        case 'c':
            *char_arr = RandFillCharArr(size);
            RecursFindChar(*char_arr, '$', size, 0);
            break;

        case 'q':
            return;

        default:
            printf("Invalid input. Try again.\n");
            ch = '0';
            break;
        }
    }
}

int main()
{
    srand(time(NULL)); // ініціалізуємо лише один раз

    int *int_arr = NULL;
    float *float_arr = NULL;
    char *char_arr = NULL;

    ChooseType(&int_arr, &float_arr, &char_arr, 10);

    free(int_arr);
    free(float_arr);
    free(char_arr);
    return 0;
}
```

### Оскільки у С не підтримується перевантаження функцій, то всі імена для ф-цій прийшлося робити унікальними.
### При запуску вилізає меню із запропонованим списком типів даних.<br>При виборі, створюється випадковий масив із цього типу даних, а потім шукається наперед задане у коді значення. При успіху - пише, що значення знайдене, а при невдачі - не знайдене.
### Проглянемо всі можливі види варіанти роботи з програмою
### Exit and input error
![image](https://github.com/user-attachments/assets/0fe551d1-a2d9-4be8-8b6e-918bd483e23d)
![image](https://github.com/user-attachments/assets/990a8ade-8974-4c28-b98d-bbe5f03f2cd9)
### Integer:
![image](https://github.com/user-attachments/assets/a1972c70-daab-4635-b8cc-666c4d08c8b8)
### Float:
![image](https://github.com/user-attachments/assets/e486b18f-ddf5-464c-a553-05d7c213bf10)
### Char:
![image](https://github.com/user-attachments/assets/08072f96-a9db-43d3-afca-1c0eea3ba0fe)
