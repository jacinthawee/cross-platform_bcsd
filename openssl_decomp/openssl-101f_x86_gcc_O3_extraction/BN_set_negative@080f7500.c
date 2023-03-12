
void BN_set_negative(BIGNUM *b,int n)

{
  uint uVar1;
  
  uVar1 = 0;
  if (n != 0) {
    uVar1 = (uint)(b->top != 0);
  }
  b->neg = uVar1;
  return;
}

