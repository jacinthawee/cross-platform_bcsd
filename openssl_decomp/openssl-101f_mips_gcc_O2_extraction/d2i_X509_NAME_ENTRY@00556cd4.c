
X509_NAME_ENTRY * d2i_X509_NAME_ENTRY(X509_NAME_ENTRY **a,uchar **in,long len)

{
  int *piVar1;
  uint uVar2;
  X509_NAME_ENTRY *pXVar3;
  
  piVar1 = *(int **)PTR___stack_chk_guard_006aabf0;
  uVar2 = (uint)X509_NAME_ENTRY_it[0];
  if (X509_NAME_ENTRY_it._16_4_ == 0) {
    if (uVar2 < 7) {
                    /* WARNING: Could not recover jumptable at 0x00565630. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      pXVar3 = (X509_NAME_ENTRY *)(*(code *)(&switchD_00565630::switchdataD_0066abc0)[uVar2])();
      return pXVar3;
    }
  }
  else if (uVar2 < 7) {
                    /* WARNING: Could not recover jumptable at 0x005651a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pXVar3 = (X509_NAME_ENTRY *)(*(code *)(&switchD_005651a0::switchdataD_0066aba4)[uVar2])();
    return pXVar3;
  }
  if (piVar1 == *(int **)PTR___stack_chk_guard_006aabf0) {
    return (X509_NAME_ENTRY *)0x0;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  return *(X509_NAME_ENTRY **)(in[1] + *piVar1);
}

