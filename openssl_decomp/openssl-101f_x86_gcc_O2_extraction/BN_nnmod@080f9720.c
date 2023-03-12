
int BN_nnmod(BIGNUM *r,BIGNUM *m,BIGNUM *d,BN_CTX *ctx)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = BN_div((BIGNUM *)0x0,r,m,d,ctx);
  if (iVar1 != 0) {
    if (r->neg != 0) {
      UNRECOVERED_JUMPTABLE = BN_sub;
      if (d->neg == 0) {
        UNRECOVERED_JUMPTABLE = BN_add;
      }
                    /* WARNING: Could not recover jumptable at 0x080f976f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (*UNRECOVERED_JUMPTABLE)();
      return iVar1;
    }
    iVar1 = 1;
  }
  return iVar1;
}

