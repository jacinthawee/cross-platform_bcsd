
int BN_reciprocal(BIGNUM *r,BIGNUM *m,int len,BN_CTX *ctx)

{
  BIGNUM *a;
  int iVar1;
  
  BN_CTX_start(ctx);
  a = BN_CTX_get(ctx);
  if (a != (BIGNUM *)0x0) {
    iVar1 = BN_set_bit(a,len);
    if (iVar1 != 0) {
      iVar1 = (*(code *)PTR_BN_div_006a967c)(r,0,a,m,ctx);
      if (iVar1 != 0) goto LAB_005022d8;
    }
  }
  len = -1;
LAB_005022d8:
  BN_CTX_end(ctx);
  return len;
}

