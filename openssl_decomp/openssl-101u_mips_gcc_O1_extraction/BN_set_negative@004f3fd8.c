
void BN_set_negative(BIGNUM *b,int n)

{
  if (n != 0) {
    b->neg = (uint)(b->top != 0);
    return;
  }
  b->neg = 0;
  return;
}

