
int BN_mod_lshift1_quick(BIGNUM *r,BIGNUM *a,BIGNUM *m)

{
  int iVar1;
  
  iVar1 = BN_lshift1(r,a);
  if (iVar1 == 0) {
    return 0;
  }
  iVar1 = BN_cmp(r,m);
  if (-1 < iVar1) {
                    /* WARNING: Could not recover jumptable at 0x004f78ec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*(code *)PTR_BN_sub_006a85a8)(r,r,m);
    return iVar1;
  }
  return 1;
}

