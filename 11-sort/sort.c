#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t)) 

// �迭�� ����ϴ� �Լ�
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// ���� ������ ����
void generateRandomData(int arr[]) {
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 1000; 
    }
}

// ���� ���� �Լ�
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

        // ���� ���� ��� (10���� ����, 20 ������ ���)
        if ((i + 1) % 20 == 10 || i == SIZE - 2) {

            printf("\nStep %d: ", i + 1);
            printArray(arr, SIZE);
        }
    }
}

// ���� ���� �Լ�
void doInsertionSort(int arr[]) {
    int totalComparisons = 0; // �� �� Ƚ��
    int numTrials = 20;       // 20�� �ݺ�

    for (int trial = 0; trial < numTrials; trial++) {
        // ���ο� ���� ������ ����
        generateRandomData(arr);

        int comparisons = 0; // �� ���� ���� ���� �� Ƚ��
        for (int i = 1; i < SIZE; i++) {
            int key = arr[i];
            int j = i - 1;

            // ���� ��ġ�� ã���鼭 ��
            while (j >= 0 && arr[j] > key) {
                comparisons++;    // �� Ƚ�� ����
                arr[j + 1] = arr[j];
                j--;
            }
            if (j >= 0) {
                comparisons++; // ������ �� Ƚ��
            }
            arr[j + 1] = key;
        }
        totalComparisons += comparisons;
    }

    // ��� �� Ƚ�� ���
    printf("\n\nInsertion Sort Compare Average: %.2f\n", (double)totalComparisons / numTrials);

    // ���� ���� ��� ���
    printf("Insertion Sort Result:\n");
    printArray(arr, SIZE);
}

// ���� ���� �Լ�
void doBubbleSort(int arr[]) {
    int totalMoves = 0;  // �� �̵� Ƚ��
    int numTrials = 20;  // 20�� �ݺ�

    for (int trial = 0; trial < numTrials; trial++) {
        // ���ο� ���� ������ ����
        generateRandomData(arr);

        int moves = 0; // ���� �õ��� �̵� Ƚ��
        for (int i = 0; i < SIZE - 1; i++) {
            for (int j = 0; j < SIZE - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp;
                    SWAP(arr[j], arr[j + 1], temp);
                    moves += 3; // SWAP���� �� 3ȸ �̵�
                }
            }
        }
        totalMoves += moves;
    }

    // ��� �̵� Ƚ�� ���
    printf("\n\nBubble Sort Move Average: %.2f\n", (double)totalMoves / numTrials);

    // ���� ���� ��� ���
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
