
ASN1_UTF8STRING * d2i_ASN1_UTF8STRING(ASN1_UTF8STRING **a,uchar **in,long len)

{
  int *piVar1;
  uint uVar2;
  ASN1_UTF8STRING *pAVar3;
  
  piVar1 = *(int **)PTR___stack_chk_guard_006aabf0;
  uVar2 = (uint)ASN1_UTF8STRING_it[0];
  if (ASN1_UTF8STRING_it._16_4_ == 0) {
    if (uVar2 < 7) {
                    /* WARNING: Could not recover jumptable at 0x00565630. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      pAVar3 = (ASN1_UTF8STRING *)(*(code *)(&switchD_00565630::switchdataD_0066abc0)[uVar2])();
      return pAVar3;
    }
  }
  else if (uVar2 < 7) {
                    /* WARNING: Could not recover jumptable at 0x005651a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pAVar3 = (ASN1_UTF8STRING *)(*(code *)(&switchD_005651a0::switchdataD_0066aba4)[uVar2])();
    return pAVar3;
  }
  if (piVar1 == *(int **)PTR___stack_chk_guard_006aabf0) {
    return (ASN1_UTF8STRING *)0x0;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  return *(ASN1_UTF8STRING **)(in[1] + *piVar1);
}
