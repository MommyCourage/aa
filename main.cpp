#include <iostream>

using namespace std;

void printArray(int arr[], int size) {
    // виводжу кожен елемент масиву на консоль циклом
    for (int i = 0; i < size; i++) {
        cout << arr[i] << '\t';
    }
    cout << endl;
}
void sortArray(int arr[], int size) {
    // сортую елементи масива за зростанням за допомогою вкладеного циклу
    for (int i = 0, temp; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (arr[i] > arr[j]) {
                temp =  arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
void countOfDifferent(int arr[], int size) {
    int count = 1;
    for (int i = 1, j; i < size; i++) {
        for (j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                break;
            }
        }
        if (i == j) {
            count++;
        }
   }

   cout << "Count of different elements in the array: " << count << endl;
}
void removeMissingInSecond(int arr1[], int arr2[], int size) {
    for (int i = 0, temp = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (arr1[i] == arr2[j]) {
                temp = 0;
                break;
            }
            else {
                temp = 1;
            }
        }
        if (temp == 1) {
            arr1[i] = 0;
        }
    }
}
void specSortArray(int arr[], int size) {
    int firstNegativePos;
    // розміщую додатні елементи на початку масиву
    for (int i = 0, j = 0, temp; i < size; i++) {
        if (arr[i] >= 0) {
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            j++;
        }
    }
    // знаходжу номер першого від'ємного елемента
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            firstNegativePos = i;
            break;
        }
    }
    // сортую додатні елементи за зростанням
    for (int i = 0, temp; i < firstNegativePos; i++) {
        for (int j = 0; arr[j] >= 0; j++) {
            if (arr[i] < arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    // сортую від'ємні елементи за спаданням
    for (int i = firstNegativePos, temp; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    // огологую конст. змінну для зберігання розміру масивів, а також змінні самих масивів
    const int size = 5;
    int arr1[size], arr2[size];

    // прошу заповнити перший масив
    for (int i = 0; i < size; i++) {
        cout << "Enter the " << i << "th element of the first array: ";
        cin >> arr1[i];
    }
    cout << endl;
    // прошу заповнити другий масив
    for (int i = 0; i < size; i++) {
        cout << "Enter the " << i << "th element of the second array: ";
        cin >> arr2[i];
    }

    cout << endl;

    // сортую масиви власною функцією
    sortArray(arr1, size);
    sortArray(arr2, size);

    // виводжу на консоль відсортовані масиви та кількість неоднакових елементів у них за допомогою функцій
    cout << "YOUR SORTED ARRAYS: " << endl;
    printArray(arr1, size);
    countOfDifferent(arr1, size);
    printArray(arr2, size);
    countOfDifferent(arr2, size);

    cout << endl;

    // видаляю з першого масиву елементи, яких нема у другому масиві, за допомогою функції
    cout << "FIRST ARRAY WITHOUT THE ELEMENTS THAT ARE ABSENT IN SECOND ARRAY: " << endl;
    removeMissingInSecond(arr1, arr2, size);
    printArray(arr1, size);

    cout << endl;

    // сортую перший масив згідно з умовою за допомогою функції
    cout << "THE ARRAYS SORTED BY CONDITION: " << endl;
    specSortArray(arr1, size);
    printArray(arr1, size);
    specSortArray(arr2, size);
    printArray(arr2, size);

    return 0;
}
