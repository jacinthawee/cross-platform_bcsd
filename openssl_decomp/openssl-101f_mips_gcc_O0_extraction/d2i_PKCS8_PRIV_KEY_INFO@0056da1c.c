
PKCS8_PRIV_KEY_INFO * d2i_PKCS8_PRIV_KEY_INFO(PKCS8_PRIV_KEY_INFO **a,uchar **in,long len)

{
  int *piVar1;
  uint uVar2;
  PKCS8_PRIV_KEY_INFO *pPVar3;
  
  piVar1 = *(int **)PTR___stack_chk_guard_006aabf0;
  uVar2 = (uint)PKCS8_PRIV_KEY_INFO_it[0];
  if (PKCS8_PRIV_KEY_INFO_it._16_4_ == 0) {
    if (uVar2 < 7) {
                    /* WARNING: Could not recover jumptable at 0x00565630. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      pPVar3 = (PKCS8_PRIV_KEY_INFO *)(*(code *)(&switchD_00565630::switchdataD_0066aba0)[uVar2])();
      return pPVar3;
    }
  }
  else if (uVar2 < 7) {
                    /* WARNING: Could not recover jumptable at 0x005651a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pPVar3 = (PKCS8_PRIV_KEY_INFO *)(*(code *)(&switchD_005651a0::switchdataD_0066ab84)[uVar2])();
    return pPVar3;
  }
  if (piVar1 == *(int **)PTR___stack_chk_guard_006aabf0) {
    return (PKCS8_PRIV_KEY_INFO *)0x0;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  return *(PKCS8_PRIV_KEY_INFO **)(in[1] + *piVar1);
}

