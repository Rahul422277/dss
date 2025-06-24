#include <stdio.h>

void linearSearch(int arr[], int n, int key) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == key) {
            printf("Linear Search: Element found at index %d\n", i);
            return;
        }
    }
    printf("Linear Search: Element not found\n");
}

void binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid] == key) {
            printf("Binary Search: Element found at index %d\n", mid);
            return;
        } else if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    printf("Binary Search: Element not found\n");
}

int main() {
    int arr[100], n, key;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter sorted array elements:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter key to search: ");
    scanf("%d", &key);

    linearSearch(arr, n, key);
    binarySearch(arr, n, key);

    return 0;
}
