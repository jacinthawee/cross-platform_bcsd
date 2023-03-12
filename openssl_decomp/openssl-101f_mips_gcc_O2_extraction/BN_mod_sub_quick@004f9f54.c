
int BN_mod_sub_quick(BIGNUM *r,BIGNUM *a,BIGNUM *b,BIGNUM *m)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_BN_sub_006a96cc)();
  if ((iVar1 != 0) && (iVar1 = 1, r->neg != 0)) {
                    /* WARNING: Could not recover jumptable at 0x004f9fc4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*(code *)PTR_BN_add_006a96c8)(r,r,m);
    return iVar1;
  }
  return iVar1;
}

