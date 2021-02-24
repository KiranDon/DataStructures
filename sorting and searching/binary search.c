#include <stdio.h>
int main()
{
  int i, first, last, mid, n, key, array[100];

  printf("Enter number of elements\n");
  scanf("%d", &n);

  printf("Enter %d integers\n", n);

  for (i= 0; i < n; i++)
    scanf("%d", &array[i]);

  printf("Enter value to find\n");
  scanf("%d", &key);

  first = 0;
  last = n - 1;
  mid = (first+last)/2;

  while (first <= last)
   {
    if (key > array[mid])
      first = mid + 1;
    else if (array[mid] == key) 
    {
      printf("%d found at location %d.\n", key, mid+1);
      break;
    }
    else
      last = mid- 1;

    mid= (first + last)/2;
  }
  if (first > last)
    printf("Not found! %d isn't present in the list.\n", key);

  return 0;
}
