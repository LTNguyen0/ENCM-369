// globals.c
// ENCM 369 Winter 2018 Lab 1 Exercise B

void copy(int *dest, const int *src, int n)
{
  int k;
  for (k = 0; k < n; k++)
    dest[k] = src[k];

  // point one (which is AFTER the loop is finished)

  return;
}


void reverse(int *to, const int *from, int n)
{
  int *pastend;
  pastend = to + n;
  from += n;
  while (to != pastend) {
    from--;
    *to = *from;

    // point two

    to++;
  }

  // point three
}

int aa[] = {1001, 2002, 3003, 4004};
int bb[4];
int cc = 600;

void update_cc(int z)
{
  cc += z;
}

int main(void)
{
  int dd[6];
  int ee[4] = {110, 220, 330, 440}; 

  update_cc(40);
  copy(dd, aa, 4);
  update_cc(7);
  reverse(bb, ee, 4);
  update_cc(6);
  return 0;
}
