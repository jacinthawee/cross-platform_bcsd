
int BN_is_bit_set(BIGNUM *a,int n)

{
  uint uVar1;
  
  if (-1 < n) {
    uVar1 = 0;
    if (n >> 5 < a->top) {
      uVar1 = a->d[n >> 5] >> ((byte)n & 0x1f) & 1;
    }
    return uVar1;
  }
  return 0;
}

