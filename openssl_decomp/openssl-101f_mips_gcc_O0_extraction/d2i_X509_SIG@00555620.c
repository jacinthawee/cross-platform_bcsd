
X509_SIG * d2i_X509_SIG(X509_SIG **a,uchar **in,long len)

{
  int *piVar1;
  uint uVar2;
  X509_SIG *pXVar3;
  
  piVar1 = *(int **)PTR___stack_chk_guard_006aabf0;
  uVar2 = (uint)X509_SIG_it[0];
  if (X509_SIG_it._16_4_ == 0) {
    if (uVar2 < 7) {
                    /* WARNING: Could not recover jumptable at 0x00565630. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      pXVar3 = (X509_SIG *)(*(code *)(&switchD_00565630::switchdataD_0066aba0)[uVar2])();
      return pXVar3;
    }
  }
  else if (uVar2 < 7) {
                    /* WARNING: Could not recover jumptable at 0x005651a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pXVar3 = (X509_SIG *)(*(code *)(&switchD_005651a0::switchdataD_0066ab84)[uVar2])();
    return pXVar3;
  }
  if (piVar1 == *(int **)PTR___stack_chk_guard_006aabf0) {
    return (X509_SIG *)0x0;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  return *(X509_SIG **)(in[1] + *piVar1);
}
