void askingAndPrinting(int a[], int b, int c)
{
  int count = 0;
  int i;
  int even[c];
  for (i = 0; i <= b; i++)
  {
    if (a[i] % 2 == 0)
    {
      if (count < 5)
      {
        even[i] = a[i];
      }
      count++;
    }
    else
    {
      break;
    }
  }

  for (i = 0; i <= c; i++)
  {
    printf("%d \n", even[i]);
  }
}