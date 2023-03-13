
int BN_mod_add(BIGNUM *r,BIGNUM *a,BIGNUM *b,BIGNUM *m,BN_CTX *ctx)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = BN_add(r,a,b);
  if ((iVar1 != 0) && (iVar1 = BN_div((BIGNUM *)0x0,r,r,m,ctx), iVar1 != 0)) {
    if (r->neg == 0) {
      return 1;
    }
    UNRECOVERED_JUMPTABLE = BN_sub;
    if (m->neg == 0) {
      UNRECOVERED_JUMPTABLE = BN_add;
    }
                    /* WARNING: Could not recover jumptable at 0x080f770d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*UNRECOVERED_JUMPTABLE)();
    return iVar1;
  }
  return 0;
}

