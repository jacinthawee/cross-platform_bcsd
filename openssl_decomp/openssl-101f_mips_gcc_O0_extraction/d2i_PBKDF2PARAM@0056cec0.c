
PBKDF2PARAM * d2i_PBKDF2PARAM(PBKDF2PARAM **a,uchar **in,long len)

{
  int *piVar1;
  uint uVar2;
  PBKDF2PARAM *pPVar3;
  
  piVar1 = *(int **)PTR___stack_chk_guard_006aabf0;
  uVar2 = (uint)PBKDF2PARAM_it[0];
  if (PBKDF2PARAM_it._16_4_ == 0) {
    if (uVar2 < 7) {
                    /* WARNING: Could not recover jumptable at 0x00565630. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      pPVar3 = (PBKDF2PARAM *)(*(code *)(&switchD_00565630::switchdataD_0066aba0)[uVar2])();
      return pPVar3;
    }
  }
  else if (uVar2 < 7) {
                    /* WARNING: Could not recover jumptable at 0x005651a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pPVar3 = (PBKDF2PARAM *)(*(code *)(&switchD_005651a0::switchdataD_0066ab84)[uVar2])();
    return pPVar3;
  }
  if (piVar1 == *(int **)PTR___stack_chk_guard_006aabf0) {
    return (PBKDF2PARAM *)0x0;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  return *(PBKDF2PARAM **)(in[1] + *piVar1);
}

