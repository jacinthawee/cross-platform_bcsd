
NETSCAPE_SPKI * d2i_NETSCAPE_SPKI(NETSCAPE_SPKI **a,uchar **in,long len)

{
  int *piVar1;
  uint uVar2;
  NETSCAPE_SPKI *pNVar3;
  
  piVar1 = *(int **)PTR___stack_chk_guard_006aabf0;
  uVar2 = (uint)NETSCAPE_SPKI_it[0];
  if (NETSCAPE_SPKI_it._16_4_ == 0) {
    if (uVar2 < 7) {
                    /* WARNING: Could not recover jumptable at 0x00565630. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      pNVar3 = (NETSCAPE_SPKI *)(*(code *)(&switchD_00565630::switchdataD_0066abc0)[uVar2])();
      return pNVar3;
    }
  }
  else if (uVar2 < 7) {
                    /* WARNING: Could not recover jumptable at 0x005651a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pNVar3 = (NETSCAPE_SPKI *)(*(code *)(&switchD_005651a0::switchdataD_0066aba4)[uVar2])();
    return pNVar3;
  }
  if (piVar1 == *(int **)PTR___stack_chk_guard_006aabf0) {
    return (NETSCAPE_SPKI *)0x0;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  return *(NETSCAPE_SPKI **)(in[1] + *piVar1);
}

