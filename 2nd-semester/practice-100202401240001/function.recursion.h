void recursivePrinting(int a[], int b, int i)
{
  if (i < b)
  {
    if (a[i] % 2 == 0 && a[i] != 0)
    {
      printf("%d \n", a[i]);
    }
    recursivePrinting(a, b, i + 1);
  }
}
