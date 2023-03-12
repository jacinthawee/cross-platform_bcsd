
ASN1_PRINTABLESTRING * d2i_ASN1_PRINTABLESTRING(ASN1_PRINTABLESTRING **a,uchar **in,long len)

{
  int *piVar1;
  uint uVar2;
  ASN1_PRINTABLESTRING *pAVar3;
  
  piVar1 = *(int **)PTR___stack_chk_guard_006aabf0;
  uVar2 = (uint)ASN1_PRINTABLESTRING_it[0];
  if (ASN1_PRINTABLESTRING_it._16_4_ == 0) {
    if (uVar2 < 7) {
                    /* WARNING: Could not recover jumptable at 0x00565630. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      pAVar3 = (ASN1_PRINTABLESTRING *)(*(code *)(&switchD_00565630::switchdataD_0066aba0)[uVar2])()
      ;
      return pAVar3;
    }
  }
  else if (uVar2 < 7) {
                    /* WARNING: Could not recover jumptable at 0x005651a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pAVar3 = (ASN1_PRINTABLESTRING *)(*(code *)(&switchD_005651a0::switchdataD_0066ab84)[uVar2])();
    return pAVar3;
  }
  if (piVar1 == *(int **)PTR___stack_chk_guard_006aabf0) {
    return (ASN1_PRINTABLESTRING *)0x0;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  return *(ASN1_PRINTABLESTRING **)(in[1] + *piVar1);
}

