#include <iostream>


int** my2DAlloc(int row, int col) {
    int i;

    int header = row * sizeof(int*);
    int data = row * col * sizeof(int);

    int** rowptr = (int**)malloc(header + data);
    if (rowptr == NULL) return NULL;

    int* buf = (int*)(rowptr + row);
    for (int i = 0; i < row; i++)
        rowptr[i] = buf + i * col;

    return rowptr;
}

int main()
{
    std::cout << "Hello World!\n";

    int** test = my2DAlloc(3, 3);    
    free(test);
}

