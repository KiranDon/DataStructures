#include<stdio.h>
 
main()
{
   int array[100], key, i, n, count = 0;
 
   printf("Enter the number of elements in array\n");
   scanf("%d",&n);
 
   printf("Enter %d numbers\n", n);
 
   for ( i = 0 ; i < n ; i++ )
      scanf("%d",&array[i]);
 
   printf("Enter the number to search\n");
   scanf("%d",&key);
 
   for ( i = 0 ; i < n ; i++ )
   {
      if ( array[i] == key )    
      {
         printf("%d is present at location %d.\n", key, i+1);
     count++;
      }
   }
   if ( count == 0 )
      printf("%d is not present in array.\n", key);
   else
      printf("%d is present %d times in array.\n", key, count);
 
   return 0;
}

