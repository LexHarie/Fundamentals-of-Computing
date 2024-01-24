void update(int *a, int *b)
{
  int temp1 = *a;
  int temp2 = *b;

  *a = temp1 + temp2;
  *b = (temp1 - temp2) < 0 ? temp2 - temp1 : temp1 - temp2;
}