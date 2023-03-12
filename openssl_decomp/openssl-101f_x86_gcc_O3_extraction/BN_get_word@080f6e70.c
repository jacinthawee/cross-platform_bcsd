
ulong BN_get_word(BIGNUM *a)

{
  ulong uVar1;
  
  uVar1 = 0xffffffff;
  if ((a->top < 2) && (uVar1 = 0, a->top == 1)) {
    return *a->d;
  }
  return uVar1;
}

