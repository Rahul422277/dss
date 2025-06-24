#include <stdio.h>

int main() {
    int a[100], n, key;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter element to search (Linear Search): ");
    scanf("%d", &key);

    for(int i = 0; i < n; i++) {
        if(a[i] == key) {
            printf("Element found at index %d\n", i);
            return 0;
        }
    }
    printf("Element not found\n");
    return 0;
}

