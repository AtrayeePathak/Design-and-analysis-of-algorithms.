 #include <stdio.h>

int main() {
    int n ;
    printf("enter the number of elements:");
    scanf("%d",&n);

  int arr[n];

  printf("Enter  integers: ");

  // taking input and storing it in an array
  for(int i = 0; i < n; ++i) {
     scanf("%d", &arr[i]);
  
  }
  for (int i=0;i<n;i++){
      int current=arr[i];
      int j=i-1;
      while(arr[j]>current&&j>0){
        arr[j+1]=arr[j];
        j--;
      }
      
    arr[j+1]=current;
  }        
  printf("the sorted array is:");
    for(int i=0;i<n;i++){
        printf("%d ", arr[i]);
    }
      
}


