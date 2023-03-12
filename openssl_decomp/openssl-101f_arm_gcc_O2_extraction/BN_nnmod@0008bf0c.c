
int BN_nnmod(BIGNUM *r,BIGNUM *m,BIGNUM *d,BN_CTX *ctx)

{
  code *pcVar1;
  int iVar2;
  
  iVar2 = BN_div((BIGNUM *)0x0,r,m,d,ctx);
  if (iVar2 != 0) {
    if (r->neg != 0) {
      pcVar1 = BN_sub;
      if (d->neg == 0) {
        pcVar1 = BN_add;
      }
                    /* WARNING: Could not recover jumptable at 0x0008bf4c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar2 = (*(pcVar1 + 1))(r,r,d);
      return iVar2;
    }
    iVar2 = 1;
  }
  return iVar2;
}

