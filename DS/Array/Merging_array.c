#include <stdio.h>

int main() {
   int arr1[100];
   int arr2[100];
   int arr12[100];

   for (int i = 0; i<=4;i++)
      {
         printf("Enter Your elements for 1st array: ");

         scanf("%d", &arr1[i]);
      }

   for (int i = 0; i<=4;i++)
      {
         printf("Enter Your elements for 2nd array: ");

         scanf("%d", &arr2[i]);
      }

      for (int i = 0; i<=4; i++) {
         arr12[i] = arr1[i];
      }
      
      for (int i = 0, j = 5; i<=4 && j<=9; i++, j++) {

         arr12[j] = arr1[i];
      }

      for (int i = 0; i<=10; i++){
         printf("%d\n", arr12[i]);
      }
   return 0;
}
