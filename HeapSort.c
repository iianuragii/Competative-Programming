// Heap Sort in C
  
  #include <stdio.h>
  

  int k = 0;
  void swap(int *a, int *b) 
  {
    int temp = *a;
    *a = *b;
    *b = temp;
    k++;
  }
  
  void heapify(int arr[], int n, int i) 
  {
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && arr[left] > arr[largest])
      largest = left;
  
    if (right < n && arr[right] > arr[largest])
      largest = right;
  
    // Swap and continue heapifying if root is not largest
    if (largest != i) {
      swap(&arr[i], &arr[largest]);
      heapify(arr, n, largest);
    }
  }
  
  // Main function to do heap sort
  void heapSort(int arr[], int n)
  {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);
  
    // Heap sort
    for (int i = n - 1; i >= 0; i--) 
    {
      swap(&arr[0], &arr[i]);
      heapify(arr, i, 0);
    }
  }
  
  void printArray(int arr[], int n)
  {
    for (int i = 0; i < n; ++i)
      printf("%d ", arr[i]);
    printf("\n");
  }
  
  int main() {
    int arr[1000];
    for(int i = 0; i < 1000;i++)
    {
        arr[i] = rand() % 1000;
    }
    printArray(arr, 1000);
    heapSort(arr, 1000);
  
    printf("Sorted array is \n");
    printArray(arr, 1000);
    printf("T(n) = %d",k);
  }
