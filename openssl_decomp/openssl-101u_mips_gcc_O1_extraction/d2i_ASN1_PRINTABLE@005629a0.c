
ASN1_STRING * d2i_ASN1_PRINTABLE(ASN1_STRING **a,uchar **in,long len)

{
  int *piVar1;
  uint uVar2;
  ASN1_STRING *pAVar3;
  
  piVar1 = *(int **)PTR___stack_chk_guard_006a9ae8;
  uVar2 = (uint)ASN1_PRINTABLE_it[0];
  if (ASN1_PRINTABLE_it._16_4_ == 0) {
    if (uVar2 < 7) {
                    /* WARNING: Could not recover jumptable at 0x005619f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      pAVar3 = (ASN1_STRING *)(*(code *)(&switchD_005619f8::switchdataD_0066a17c)[uVar2])();
      return pAVar3;
    }
  }
  else if (uVar2 < 7) {
                    /* WARNING: Could not recover jumptable at 0x00561550. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pAVar3 = (ASN1_STRING *)(*(code *)(&switchD_00561550::switchdataD_0066a160)[uVar2])();
    return pAVar3;
  }
  if (piVar1 == *(int **)PTR___stack_chk_guard_006a9ae8) {
    return (ASN1_STRING *)0x0;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  return *(ASN1_STRING **)(in[1] + *piVar1);
}
