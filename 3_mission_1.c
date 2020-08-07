#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int number_of_answer = 10;
int answer_arr[10] = {1,2,3,4,5,1,2,3,4,5};
int sum = 50;

bool check_answer_amount(int argc);

int main(int argc, string argv[]){
    
    //정답갯수 확인
    if(check_answer_amount(argc)==true){
        return 1;
    }

    //전달받은 정답을 String 형에서 int 형의 값으로 저장
    int stu_answer[number_of_answer];

    for(int k =0 ; k<number_of_answer;k++){
        stu_answer[k] = atoi(argv[k+1]);
    }

    //정답체크(잘못된 정답형태를 고르는 작업 포함)
    for(int i=0;i<number_of_answer;i++){
        if(stu_answer[i]<=0 ||  stu_answer[i]>5){
            printf("%i 번의 답을 확인해주세요!! 답의 범위는 1~5까지 입니다.\n", i+1);
            return -1;
        }else if(stu_answer[i]==answer_arr[i]){
            sum+=5;
        }
    }

    printf("==============학점평가================\n");

    switch(sum*2/10){
        case 12 :  printf("점수 %i : D \n", sum );
            break;
        case 13 :  printf("점수 %i : D+ \n", sum );
            break;
        case 14 :  printf("점수 %i : C \n", sum );
            break;
        case 15 :  printf("점수 %i : C+ \n", sum );
            break;
        case 16 :  printf("점수 %i : B \n", sum );
            break;
        case 17 :  printf("점수 %i : B+ \n", sum );
            break;
        case 18 :  printf("점수 %i : A \n", sum );
            break;
        case 19 :  printf("점수 %i : A+ \n", sum );
            break;
        case 20 :  printf("점수 %i : A+ \n", sum );
            break;
        default :
            printf("점수 %i : F \n", sum );
    }

    // if(sum<60){
    //     printf("점수 %i : F \n", sum );
    // }else if(sum<65){
    //     printf("점수 %i : D \n", sum );
    // }else if(sum<70){
    //     printf("점수 %i : D+ \n", sum );
    // }else if(sum<75){
    //     printf("점수 %i : C \n", sum );
    // }else if(sum<80){
    //     printf("점수 %i : C+ \n", sum );
    // }else if(sum<85){
    //     printf("점수 %i : B \n", sum );
    // }else if(sum<90){
    //     printf("점수 %i : B+  \n", sum );
    // }else if(sum<95){
    //     printf("점수 %i : A  \n", sum );
    // }else if(sum<=100){
    //     printf("점수 %i : A+ \n", sum );
    // }


}

bool check_answer_amount(int argc){
    bool check = false;
    if(argc != number_of_answer+1){
        printf("문제는 10문제 입니다. 현재 %i 개의 답안을 제출했습니다. 10개의 답안을 모두 제출하세요 \n",argc-1);
        check = true;
        return check;
    }
    return check;
}