#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Arama yapilacak dizinin tüm elemanlarini liste halinde ekrana bastirir.
void display(int arr[], int sizee){

    int i;
    printf("[");
    for(i = 0; i < sizee; i++){
        printf(" %d ", arr[i]);
    }
    printf("]\n");

}

int binary_searching(int arr[], int sizee, int value, int low, int high){

    int mid;

    mid = low + (high - low) / 2;   // orta deðer hesaplama.

    // arama islemi belirli bir kosula kadar devam etmeli. low degiskeni high degiskeninden kücük ya da esit ise islem gerçeklessin.
    while(low <= high){

        if(arr[mid] == value){
            return mid;
        }

        else if(arr[mid] > value){
            high = mid - 1;
            return binary_searching(arr,sizee,value,low,high);
            // Recursive fonksinyon mantiğini kullanarak fonksiyonu kendi içinde tekrar cagırarak yeni high degeri ile islem yapmasini saglar.

        }
        else{
            low = mid + 1;
            return binary_searching(arr, sizee, value, low, high);
            // Recursive fonksinyon mantiğini kullanarak fonksiyonu kendi içinde tekrar cagırarak yeni low degeri ile islem yapmasini saglar.

        }

    }

    return -1;

}

int main()
{
    int array[] = {10,14,19,26,27,31,33,35,42,44,55};
    int sizee, value, result, low, high;
    sizee = sizeof(array) / sizeof(int);    // Arama yapilacak dizinin boyutunu hesaplar.
    low = 0;
    high = sizee - 1;

    display(array, sizee);
    printf("Searched item:"); scanf("%d", &value);
    result = binary_searching(array, sizee, value, low, high);

    if (result != -1){
        printf("index of searched item: %d", result);
    }

    else{
        printf("Searched item is not in array!");
    }

    return 0;
}
