#include <stdio.h>

void show_binary(unsigned int num);
unsigned int setbits(unsigned int x, int p, int n, unsigned int y);
unsigned int invert(unsigned int x, int p, int n);
unsigned int rightrot(unsigned int x, int n);

int main()
{
  unsigned int x;
  int n;
  
  while(scanf("%d %d", &x, &n))
    {
      puts("Przed operacja: ");
      show_binary(x);
      
      puts("Po operacji: ");
      show_binary(rightrot(x, n));
    }
  return 0;
}

void show_binary(unsigned int num)
{
  int size = 8 * sizeof(unsigned int); /* convert it to bits */
  char buffer[size];
  int i, cnt, zeros;

  i = 0;
  while(num > 0)
    {
      buffer[i++] = (num % 2) + '0';
      num /= 2;
    }
  
  zeros = size - i;
  
  cnt = 1;
  while(zeros)
    {
      putchar('0');
      if(!(cnt % 4))
	putchar(' ');

      cnt++;
      zeros--;
    }

  --i;
  while(i >= 0)
    {
      putchar(buffer[i--]);
      if((i+1) % 4 == 0)
	putchar(' ');
    }
  
  putchar('\n');
}

unsigned int setbits(unsigned int x, int p, int n, unsigned int y)
{
  unsigned int m1, m2;

   m1 = y & (~(~0 << n));
   m2 = ~(~((~0 << n) | m1) << (p - n + 1));

   m1 <<= p - n + 1;

   return (x | m1) & m2;
}

unsigned int invert(unsigned int x, int p, int n)
{
  unsigned int m1, m2;
  
  m1 = ~(~0 << n) << p-n+1;
  m2 = ~(((x >> (p-n+1)) & (~(~0 << n))) << (p-n+1));

  return (m1 | x) & m2;
}


unsigned int rightrot(unsigned int x, int n)
{
  int size = sizeof(unsigned) * 8;
  return ((0 | (x >> n)) | (x << (size - n)));
}
