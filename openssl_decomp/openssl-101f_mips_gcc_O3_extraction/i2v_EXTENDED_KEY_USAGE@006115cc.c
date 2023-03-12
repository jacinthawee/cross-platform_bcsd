
undefined4 i2v_EXTENDED_KEY_USAGE(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 local_74 [2];
  undefined auStack_6c [80];
  int local_1c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_1c = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar4 = 0;
  local_74[0] = param_3;
  while( true ) {
    iVar2 = (*(code *)PTR_sk_num_006a7f2c)(param_2);
    if (iVar2 <= iVar4) break;
    uVar3 = (*(code *)PTR_sk_value_006a7f24)(param_2,iVar4);
    (*(code *)PTR_i2t_ASN1_OBJECT_006a9d64)(auStack_6c,0x50,uVar3);
    (*(code *)PTR_X509V3_add_value_006a8ea4)(0,auStack_6c,local_74);
    iVar4 = iVar4 + 1;
  }
  if (local_1c == *(int *)puVar1) {
    return local_74[0];
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
                    /* WARNING: Could not recover jumptable at 0x006116c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar3 = (*(code *)PTR_ASN1_item_d2i_006a9798)();
  return uVar3;
}

