
int BN_nnmod(BIGNUM *r,BIGNUM *m,BIGNUM *d,BN_CTX *ctx)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = (*(code *)PTR_BN_div_006a855c)(0,r,m,d,ctx);
  if (iVar1 != 0) {
    if (r->neg != 0) {
      UNRECOVERED_JUMPTABLE = (code *)PTR_BN_sub_006a85a8;
      if (d->neg == 0) {
        UNRECOVERED_JUMPTABLE = (code *)PTR_BN_add_006a85a4;
      }
                    /* WARNING: Could not recover jumptable at 0x004f7348. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (*UNRECOVERED_JUMPTABLE)(r,r,d);
      return iVar1;
    }
    iVar1 = 1;
  }
  return iVar1;
}

