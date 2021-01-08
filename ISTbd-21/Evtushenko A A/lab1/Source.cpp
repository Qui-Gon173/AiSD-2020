#include <iostream>
using namespace std;

int main() {

    int arr[10]; 
    cout << "Enter the array" << endl;
    for (int i = 0; i < 10; i++) {
        cin >> arr[i]; //считали массив
    }

    int key; // создали переменную в которой будет находиться искомое значение (ключ)

    cout << endl << endl << "Enter the key: "; cin >> key; // считали ключ
    int answer = -1; 
    for (int i = 0; i < 10; i++) {
        if (arr[i] == key) { // проверяем равен ли arr[i] ключу
            answer = i;
        }
    }
    if (answer == -1) {
        cout << endl << "Key is not found" << endl;
    }
    else {
        cout << "Key is in the cell #" << answer << endl << endl;
    }
    system("pause");
    return 0;
}