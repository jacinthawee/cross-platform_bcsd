
int BN_mod_sqr(BIGNUM *r,BIGNUM *a,BIGNUM *m,BN_CTX *ctx)

{
  int iVar1;
  
  iVar1 = BN_sqr(r,a,ctx);
  if (iVar1 != 0) {
    iVar1 = (*(code *)PTR_BN_div_006a855c)(0,r,r,m,ctx);
  }
  return iVar1;
}
