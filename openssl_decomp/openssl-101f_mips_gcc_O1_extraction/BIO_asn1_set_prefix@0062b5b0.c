
int BIO_asn1_set_prefix(BIO *b,undefined1 *prefix,undefined1 *prefix_free)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  puVar4 = (undefined4 *)&DAT_00000095;
  puVar5 = (undefined4 *)0x0;
  iVar2 = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar3 = (*(code *)PTR_BIO_ctrl_006a7f18)();
  if (iVar2 == *(int *)puVar1) {
    return iVar3;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iVar2 = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar3 = (*(code *)PTR_BIO_ctrl_006a7f18)();
  if (0 < iVar3) {
    *puVar4 = uStack_4c;
    *puVar5 = uStack_48;
  }
  if (iVar2 == *(int *)puVar1) {
    return iVar3;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  puVar4 = (undefined4 *)&DAT_00000097;
  puVar5 = (undefined4 *)0x0;
  iVar2 = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar3 = (*(code *)PTR_BIO_ctrl_006a7f18)();
  if (iVar2 == *(int *)puVar1) {
    return iVar3;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iVar2 = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar3 = (*(code *)PTR_BIO_ctrl_006a7f18)();
  if (0 < iVar3) {
    *puVar4 = uStack_b4;
    *puVar5 = uStack_b0;
  }
  if (iVar2 == *(int *)puVar1) {
    return iVar3;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  return (int)_bignum_nist_p_192;
}

