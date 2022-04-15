#include <stdio.h>
#include <stdlib.h>

void output(int *array, int size){
    int i;
    printf("Массив: ");
    for(i = 0; i< size; i++){
        printf("%d  ", array[i]);
    }    
    printf("\n");
}

void input(int *array, int size){
    int i = 0;
    for( ; i < size; i++){
        printf("array[%d] = ", i);
        scanf("%d", &array[i]);
        printf("\n");
    }
    output(array, size);
}

void removal(int *array, int size){
    int count, value;
    int i, j;
    printf("Сколько элементов удалить?\t");
    scanf("%d", &count);
    while(count > 0){
        printf("Какой элемент удалить? \t" );
        scanf("%d", &value);
        for(i = 0; i < size ; i++){
            if (array[i] == value){
                for( j = i; j < (size-1); j++){
                    array[j] = array[j+1]; 
                }  
                i--;
                size--;
            }
        } 
        count--;
    }
    output(array, size);
}

void adding(int *array, int size){
    int count, pos, value;
    int i;
    printf("Сколько элементов добавить?\t");
    scanf("%d", &count);
    while(count > 0){
        printf("Какой элемент хотите добавить в массив?\t");
        scanf("%d", &value);
        printf("На какую позицию хотите добавить элемент?\t");
        scanf("%d", &pos);
        if(pos > (size+1) || pos <= 0){
            printf("Данная позиция недоступна. Введите от 1 до %d\t", size);
            count++;
        }
        else{
            for(i = size; i >= pos; i--){
                array[i] = array[i-1];
            }
            array[i] = value;
            size++;
        }
        count--;
    }
    output(array, size);
}

int main(){
    int *array1, *array2;
    int size1, size2;
    
    printf("Введите размер первого массива:\t");
    scanf("%d", &size1);
    array1 = (int*)malloc(size1 * sizeof(int));
    input(array1, size1);
    removal(array1, size1);
    adding(array1, size1);
    
    printf("Введите размер второго массива:\t");
    scanf("%d", &size2);
    array2 = (int*)malloc(size2 * sizeof(int));
    input(array2, size2);
    removal(array2, size2);
    adding(array2, size2);
    
    return 0;
}
