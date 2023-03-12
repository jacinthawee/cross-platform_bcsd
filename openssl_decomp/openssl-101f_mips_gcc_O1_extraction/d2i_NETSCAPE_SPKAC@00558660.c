
NETSCAPE_SPKAC * d2i_NETSCAPE_SPKAC(NETSCAPE_SPKAC **a,uchar **in,long len)

{
  int *piVar1;
  uint uVar2;
  NETSCAPE_SPKAC *pNVar3;
  
  piVar1 = *(int **)PTR___stack_chk_guard_006aabf0;
  uVar2 = (uint)NETSCAPE_SPKAC_it[0];
  if (NETSCAPE_SPKAC_it._16_4_ == 0) {
    if (uVar2 < 7) {
                    /* WARNING: Could not recover jumptable at 0x00565630. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      pNVar3 = (NETSCAPE_SPKAC *)(*(code *)(&switchD_00565630::switchdataD_0066abc0)[uVar2])();
      return pNVar3;
    }
  }
  else if (uVar2 < 7) {
                    /* WARNING: Could not recover jumptable at 0x005651a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pNVar3 = (NETSCAPE_SPKAC *)(*(code *)(&switchD_005651a0::switchdataD_0066aba4)[uVar2])();
    return pNVar3;
  }
  if (piVar1 == *(int **)PTR___stack_chk_guard_006aabf0) {
    return (NETSCAPE_SPKAC *)0x0;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  return *(NETSCAPE_SPKAC **)(in[1] + *piVar1);
}

