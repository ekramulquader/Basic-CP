#include<stdio.h>
#include<stdlib.h>
int* MaxMin(int* arr,int low,int high){

  /*Handle Edge Cases*/
  if(arr == NULL || low < 0 || high < 0 || low > high) return NULL;
  
  /*Allocate Array Dynamically*/
  int *result = (int*)malloc(2*sizeof(int));
  if(!result) return NULL;

  /*If One Element is in the Array*/
  if(low == high){
    result[0] = arr[high];
    result[1] = arr[low];
    return result;  
  }

  /*If Two Elements are in the Array*/
  if(high-low == 1){
    if(arr[high]>arr[low]){
      result[0] = arr[high];
      result[1] = arr[low];
    }
    else{
      result[0] = arr[low];
      result[1] = arr[high];
    }
    return result;
  }

  /*Dividing Step*/
  int mid = high - (high-low)/2;
  int* left = MaxMin(arr,low,mid);
  int* right = MaxMin(arr,mid+1,high);

  if(left == NULL || right == NULL){
    free(result);
    free(left);
    free(right);
    return NULL;
  }

  /*Conquering Step*/
  result[0] = (left[0]<right[0])?right[0]:left[0];
  result[1] = (left[1]>right[1])?right[1]:left[1];

  free(left);
  free(right);

  return result;
}

int main(){
  int arr[] = {45,87,-6,0,5,12,1};
  int size = sizeof(arr) / sizeof(arr[0]);
  int *result = MaxMin(arr,0,size-1);

  if (result != NULL){
    printf("Min = %d\n", result[1]);
    printf("Max = %d\n", result[0]);
    free(result);
  }
  return 0;
}