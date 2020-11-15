#include <iostream>

using namespace std;

int main()
{
    const int length = 10;
    int arr[length] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int key;

    cin >> key;

    for (int i = 0; i < length; i++) {
        if (arr[i] == key) {
            cout << "\n" << "INDEX: " << i << endl;
            break;
        }

        if (i == length - 1) {
            if (arr[i] != key) {
                cout << "\n" << "There is no match."<< endl;
                break;
            }
        }
    }
}
