#include "phoenixLib.h"

char * setArray(char src[], int maxLength); // Установить значения для массива.
char * sortArray(char* src, int lengthOfArray); // Отсортировать массив.
void getArray(char src[], unsigned int lengthOfString, int numberOfString); // Вывести массив.

char helper[2];

int main(){
    translateOutput();

    char str[] = {0};
    puts(setArray(str, 5));
    getArray(str, strlen(str), 1);
    sortArray(str,1);
    return 0;
}

char * setArray(char src[], int maxLength){
    puts("\nВведите строку: ");
    gets(src); // Ввод строки.

    if (strlen(src) > maxLength) setArray(src, maxLength); // Проверка длины, если превышает, то рекурсивно вызывается с теми же параметрами.
    return src;
}


void getArray(char src[], unsigned int lengthOfString, int numberOfString){
    printf(
            "\nНомер строки: %d, длина строки: %d, значение: %s",
            numberOfString, // Номер строки.
            lengthOfString, // Длина
            src // Значение
            );
}
/* Сделать чёткую функцию.
 Расположить строки в алфавитном порядке // Задание.
 1.	Массив // На вход.
 2.	Размерность массива
 -----------------------
 1. Количество перестановок // На выход.
 2. Первая буква первой строки
*/
char * sortArray(char* src, int lengthOfArray){
    int temp[] = {0};

    unsigned int n = 0, i = 0;

    while(src[i] != '\0'){
        temp[i] = (int) tolower(src[i]);
        n++; // Размер массива temp
        i++;
    }

    unsigned int k = 0, j;
    for(i = 0 ; i < n - 1; i++) {
        for(j = 0 ; j < n - i - 1 ; j++) {
            if(temp[j] > temp[j+1]) {
                int interim = temp[j];
                temp[j] = temp[j+1] ;
                temp[j+1] = interim;
                k++;
            }
        }
    } // Сортировка массива temp

    for (i = 0; temp[i] != '\0'; i++){ // Перевод из ASCII в char.
        src[i] = (char) temp[i];
    }

    printf("\n%s", src);
    helper[0] = (char) k;
    helper[1] = src[0];
    return helper;
}