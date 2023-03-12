
int BN_mod_add(BIGNUM *r,BIGNUM *a,BIGNUM *b,BIGNUM *m,BN_CTX *ctx)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = (*(code *)PTR_BN_add_006a96c8)();
  if ((iVar1 != 0) && (iVar1 = (*(code *)PTR_BN_div_006a967c)(0,r,r,m,ctx), iVar1 != 0)) {
    if (r->neg == 0) {
      return 1;
    }
    UNRECOVERED_JUMPTABLE = (code *)PTR_BN_sub_006a96cc;
    if (m->neg == 0) {
      UNRECOVERED_JUMPTABLE = (code *)PTR_BN_add_006a96c8;
    }
                    /* WARNING: Could not recover jumptable at 0x004f9de8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*UNRECOVERED_JUMPTABLE)(r,r,m);
    return iVar1;
  }
  return 0;
}

