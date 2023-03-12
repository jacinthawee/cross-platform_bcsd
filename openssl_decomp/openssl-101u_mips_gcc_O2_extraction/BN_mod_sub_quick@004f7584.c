
int BN_mod_sub_quick(BIGNUM *r,BIGNUM *a,BIGNUM *b,BIGNUM *m)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_BN_sub_006a85a8)();
  if ((iVar1 != 0) && (iVar1 = 1, r->neg != 0)) {
                    /* WARNING: Could not recover jumptable at 0x004f75f4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*(code *)PTR_BN_add_006a85a4)(r,r,m);
    return iVar1;
  }
  return iVar1;
}

