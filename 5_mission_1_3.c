#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int** copying_arr(int row_size, int col_size, int arr [][col_size]);
void arr_print(int **get_arr, int row_size,int col_size);
int * copy_sort_arr(int n, int sort_arr[]);

int * sort(int n, int sort_arr[]);

int main(void){

    printf("Mssion_1 \n");

    int arr[6][5] = {{8, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15},{16, 17, 18, 19, 20}, {21, 22, 23, 24, 25}, {26, 27, 28, 29, 30}};

    int row_size = sizeof(arr)/sizeof(arr[0]);
    int col_size = sizeof(arr[0])/sizeof(int);

    printf("2차원 배열 사이즈\n");
    printf("row_size : %i \n", row_size );
    printf("col_size : %i \n", col_size );

    printf("2차원 배열 복사\n");
    int ** get_arr = copying_arr(row_size, col_size, arr);

    printf("2차원 배열 출력\n");
    arr_print(get_arr, row_size, col_size);


    printf("\nMission_3 \n ---버블정렬----  \n ");

    int n = 7;
    int sort_arr[7] = { 0, 25, 10, 17, 6, 12, 9 };

    printf("\n 배열을 포인터로 형변환하여 저장하기 위한 작업 \n ");
    int *copied_arr= copy_sort_arr(n, sort_arr);

    int *sorted_arr= sort(n, copied_arr);

	printf("\n 정렬된 배열 \n ");
    printf("{");
    for(int i=0;i<n;i++){
        printf("%i, ", *(sorted_arr+i+1));
    }
    printf("}\n ");
}

int** copying_arr(int row_size, int col_size, int arr [][col_size]){
	int ** copy_arr = malloc(sizeof(int)*row_size*col_size+1);

	for(int k=0;k<row_size;k++){
        *(copy_arr+k) = malloc(sizeof(int)*col_size+1);
    }

    for(int i=0;i<row_size;i++){
        for(int j=0;j<col_size;j++){
            *(*(copy_arr+i)+j) = arr[i][j];
        }
    }
    return copy_arr;
}

void arr_print(int **get_arr,int row_size,int col_size ){
	for(int i=0;i<row_size;i++){
        printf("{");
        for(int j=0;j<col_size;j++){

            printf("%i ",*(*(get_arr+i)+j));
            if(j!=col_size-1){
                printf(",");
            }
        }
        printf("}\n");
    }
}


int * copy_sort_arr(int n, int sort_arr[]){
	int *copy_arr = malloc(sizeof(int)*n+1);

	for(int i=0;i<n+1;i++){
		*(copy_arr+i) = *(sort_arr+i);
	}
	return copy_arr;
}


int * sort(int n, int *sort_arr){
    int tmp;
    for(int i=0;i<n;i++){
        printf("\n");
        for(int j=0;j<n-i-1;j++){
            if(*(sort_arr+j)>*(sort_arr+j+1)){
                tmp = *(sort_arr+j);
                *(sort_arr+j) = *(sort_arr+j+1);
                *(sort_arr+j+1) = tmp;
            }
            printf("%i, ", sort_arr[j]);
        }
    }
    return sort_arr;
}