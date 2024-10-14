//brute force approach
//tc: nlogm + m and sc: m (m=size of map which is equal to n/2 +1)

//optimal approach using bucket
//tc: 2n and sc: 1

#include <bits/stdc++.h> 
void twoNonRepeatingElements(int arr[], int n)
{
   // Write your code here.
   long long xxor=0;

   for(int i=0;i<n;i++){

      xxor=xxor^arr[i];
   }
  
   int rightMost = (xxor&(xxor-1))^xxor;  //to get the most set bit
   // this give help to distinguish number by finding the bits which are different
   // rightmost give the first bit which are different in two number

   int b1=0;
   int b2=0;

   for(int i=0;i<n;i++){

      if(arr[i]&rightMost){
         b1=b1^arr[i];
      }else{
         b2=b2^arr[i];
      }
   }

   if(b1>b2){
      cout<<b2<<" "<<b1;
   }else cout<<b1<<" "<<b2;

}
