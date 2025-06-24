a#include <stdio.h>

int main() {
    int a[100], n, key;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements in sorted order:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter element to search (Binary Search): ");
    scanf("%d", &key);

    int low = 0, high = n - 1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(a[mid] == key) {
            printf("Element found at index %d\n", mid);
            return 0;
        } else if(a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    printf("Element not found\n");
    return 0;
}
