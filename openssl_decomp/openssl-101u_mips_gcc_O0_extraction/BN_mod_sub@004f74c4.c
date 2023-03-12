
int BN_mod_sub(BIGNUM *r,BIGNUM *a,BIGNUM *b,BIGNUM *m,BN_CTX *ctx)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = (*(code *)PTR_BN_sub_006a85a8)();
  if ((iVar1 != 0) && (iVar1 = (*(code *)PTR_BN_div_006a855c)(0,r,r,m,ctx), iVar1 != 0)) {
    if (r->neg == 0) {
      return 1;
    }
    UNRECOVERED_JUMPTABLE = (code *)PTR_BN_sub_006a85a8;
    if (m->neg == 0) {
      UNRECOVERED_JUMPTABLE = (code *)PTR_BN_add_006a85a4;
    }
                    /* WARNING: Could not recover jumptable at 0x004f7574. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*UNRECOVERED_JUMPTABLE)(r,r,m);
    return iVar1;
  }
  return 0;
}

