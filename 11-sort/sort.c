#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t)) 

// 배열을 출력하는 함수
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 랜덤 데이터 생성
void generateRandomData(int arr[]) {
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 1000; 
    }
}

// 선택 정렬 함수
void doSelectionSort(int arr[]) {
    int i, j, minIdx, temp;
    for (i = 0; i < SIZE - 1; i++) {
        minIdx = i;
        for (j = i + 1; j < SIZE; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }

        SWAP(arr[minIdx], arr[i], temp);

        // 정렬 과정 출력 (10부터 시작, 20 단위로 출력)
        if ((i + 1) % 20 == 10 || i == SIZE - 2) {

            printf("\nStep %d: ", i + 1);
            printArray(arr, SIZE);
        }
    }
}

// 삽입 정렬 함수
void doInsertionSort(int arr[]) {
    int totalComparisons = 0; // 총 비교 횟수
    int numTrials = 20;       // 20번 반복

    for (int trial = 0; trial < numTrials; trial++) {
        // 새로운 랜덤 데이터 생성
        generateRandomData(arr);

        int comparisons = 0; // 한 번의 삽입 정렬 비교 횟수
        for (int i = 1; i < SIZE; i++) {
            int key = arr[i];
            int j = i - 1;

            // 삽입 위치를 찾으면서 비교
            while (j >= 0 && arr[j] > key) {
                comparisons++;    // 비교 횟수 증가
                arr[j + 1] = arr[j];
                j--;
            }
            if (j >= 0) {
                comparisons++; // 마지막 비교 횟수
            }
            arr[j + 1] = key;
        }
        totalComparisons += comparisons;
    }

    // 평균 비교 횟수 출력
    printf("\n\nInsertion Sort Compare Average: %.2f\n", (double)totalComparisons / numTrials);

    // 최종 정렬 결과 출력
    printf("Insertion Sort Result:\n");
    printArray(arr, SIZE);
}

// 버블 정렬 함수
void doBubbleSort(int arr[]) {
    int totalMoves = 0;  // 총 이동 횟수
    int numTrials = 20;  // 20번 반복

    for (int trial = 0; trial < numTrials; trial++) {
        // 새로운 랜덤 데이터 생성
        generateRandomData(arr);

        int moves = 0; // 현재 시도의 이동 횟수
        for (int i = 0; i < SIZE - 1; i++) {
            for (int j = 0; j < SIZE - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp;
                    SWAP(arr[j], arr[j + 1], temp);
                    moves += 3; // SWAP마다 값 3회 이동
                }
            }
        }
        totalMoves += moves;
    }

    // 평균 이동 횟수 출력
    printf("\n\nBubble Sort Move Average: %.2f\n", (double)totalMoves / numTrials);

    // 최종 정렬 결과 출력
    printf("Bubble Sort Result:\n");
    printArray(arr, SIZE);
}


int main() {
    int randomData[SIZE];
    srand(time(0)); 
    printf("Selection Sort:\n");
    generateRandomData(randomData);  
    doSelectionSort(randomData);     
    doInsertionSort(randomData);     
    doBubbleSort(randomData); 
    return 0;
}
