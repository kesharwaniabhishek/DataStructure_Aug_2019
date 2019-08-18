// Sorting.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int arr[5] = {7,5,8,2,9};

void insertion()
{
    
   int key =-1,j;
   for(int i = 1;i<5;i++)
    {
        key = arr[i];
        for(j = i-1; (j>=0) && (arr[j]>key); j--)
        {
         
           printf("key = %d, arr[j+1] = %d, arr[j] = %d\n",key,arr[j+1], arr[j]);
           arr[i] = arr[j];           
        }
        arr[j+1] = key;
    }
}
void print()
{

   for(int i =0;i<5;i++)
   {
      printf("%d,",arr[i]);
   }
}
void BubbuleSort()
{
   

   for(int i=0;i<5;i++)
   {
      for(int j=i+1;j<5;j++)
      {
        
         if(arr[i]>arr[j])
         {
            int k = arr[i];
            arr[i] = arr[j];
            arr[j] = k;
         }
      }
   }
}

void SelectionSort()
{
    int key = -1;
    for(int i=0;i<4;i++)
    {
       key = i;
       for(int j=i+1;j<5;j++)
       {
           if(arr[j]<arr[key])
              key = j;
       }
       if(key !=i)
       {
         int temp = arr[i];
         arr[i] = arr[key];
         arr[key] = temp;
       }
    }
}

int BinariSearch()
{
   int value =9,low =0,high = 5,mid;
   mid = (low+high)/2;
   while(low<=high)
   {
        if(arr[mid]==value)
           break;
        if(value > arr[mid])
        {
             low = mid+1;
        }
        else
        {
            high = mid-1;
        }
       mid = (low+high)/2;
   }

  printf("Value searched on index %d value = %d",mid,arr[mid]);
  return mid;
}
int _tmain(int argc, _TCHAR* argv[])
{
	
   SelectionSort();
    print();
   BinariSearch();
  
   getchar();
   return 0;
}

