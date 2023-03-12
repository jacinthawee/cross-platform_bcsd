
X509_ALGORS * d2i_X509_ALGORS(X509_ALGORS **a,uchar **in,long len)

{
  int *piVar1;
  uint uVar2;
  X509_ALGORS *pXVar3;
  
  piVar1 = *(int **)PTR___stack_chk_guard_006a9ae8;
  uVar2 = (uint)X509_ALGORS_it[0];
  if (X509_ALGORS_it._16_4_ == 0) {
    if (uVar2 < 7) {
                    /* WARNING: Could not recover jumptable at 0x005619f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      pXVar3 = (X509_ALGORS *)(*(code *)(&switchD_005619f8::switchdataD_0066a17c)[uVar2])();
      return pXVar3;
    }
  }
  else if (uVar2 < 7) {
                    /* WARNING: Could not recover jumptable at 0x00561550. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pXVar3 = (X509_ALGORS *)(*(code *)(&switchD_00561550::switchdataD_0066a160)[uVar2])();
    return pXVar3;
  }
  if (piVar1 == *(int **)PTR___stack_chk_guard_006a9ae8) {
    return (X509_ALGORS *)0x0;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  return *(X509_ALGORS **)(in[1] + *piVar1);
}

