#include <stdio.h>

int BinarySearch(int* arr, int low, int high, int key) {
  /*Handle Edge Cases */
  if (low < 0 || high < 0 || low > high)
      return -1;

  /* Calculate Middle Index */
  int mid = low + (high - low) / 2;

  /* Check the position of key and divide further */
  if (arr[mid] == key) return mid;
  else if (arr[mid] > key) return BinarySearch(arr, low, mid - 1, key);
  else return BinarySearch(arr, mid + 1, high, key);
}

int main() {
  int arr[] = {4, 5, 9, 11, 12, 17, 19};
  int size = sizeof(arr)/ sizeof(int);
  int key = 1;

  int index = BinarySearch(arr,0,size-1,key);

  if (index == -1) printf("Element not found\n");
  else printf("Element %d is found at index %d\n", key, index);

  return 0;
}
