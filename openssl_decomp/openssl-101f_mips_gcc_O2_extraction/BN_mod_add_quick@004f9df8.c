
int BN_mod_add_quick(BIGNUM *r,BIGNUM *a,BIGNUM *b,BIGNUM *m)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_BN_uadd_006a96d0)();
  if (iVar1 == 0) {
    return 0;
  }
  iVar1 = BN_ucmp(r,m);
  if (-1 < iVar1) {
                    /* WARNING: Could not recover jumptable at 0x004f9e74. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*(code *)PTR_BN_usub_006a96d4)(r,r,m);
    return iVar1;
  }
  return 1;
}

