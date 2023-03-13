
void bn_free(BIGNUM **param_1,int param_2)

{
  BIGNUM *a;
  
  a = *param_1;
  if (a != (BIGNUM *)0x0) {
    if ((*(byte *)(param_2 + 0x14) & 1) == 0) {
      BN_free(a);
    }
    else {
      BN_clear_free(a);
    }
    *param_1 = (BIGNUM *)0x0;
  }
  return;
}

