#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   //   Write your code here
   // There is 3 way to solve
   // 1 using Sort
   // sort(arr, arr+n);

   // 2 By Count
   /*
   int zero = 0, one = 0, two = 0;
   for(int i=0; i<n; i++){
      if(arr[i] == 0)
         zero++;
      else if(arr[i] == 1)
         one++;
      else
         two++;
   }
   int index = 0;
   while(zero--){
      arr[index] = 0;
      index++;\
   }

   while(one--){
      arr[index] = 1;
      index++;
   }

   while(two--){
      arr[index] = 2;
      index++;
   }
   */

   // 3 By inplace change
   int zero = 0, one = 0, two = n-1;
   while(one<=two){
      if(arr[one] == 0){
         swap(arr[zero],arr[one]);
         zero++;
         one++;
      }else if(arr[one] == 1){
         one++;
      }else if(arr[one] == 2){
         swap(arr[one], arr[two]);
         two--;
      }
   }
}