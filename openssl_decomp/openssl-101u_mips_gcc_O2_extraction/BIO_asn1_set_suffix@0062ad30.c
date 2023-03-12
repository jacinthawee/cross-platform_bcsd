
int BIO_asn1_set_suffix(BIO *b,undefined1 *suffix,undefined1 *suffix_free)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  puVar4 = (undefined4 *)&DAT_00000097;
  puVar5 = (undefined4 *)0x0;
  iVar2 = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar3 = (*(code *)PTR_BIO_ctrl_006a6e18)();
  if (iVar2 == *(int *)puVar1) {
    return iVar3;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iVar2 = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar3 = (*(code *)PTR_BIO_ctrl_006a6e18)();
  if (0 < iVar3) {
    *puVar4 = uStack_4c;
    *puVar5 = uStack_48;
  }
  if (iVar2 == *(int *)puVar1) {
    return iVar3;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  return (int)_bignum_nist_p_192;
}

