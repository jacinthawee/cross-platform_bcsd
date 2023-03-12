
uint gost94_param_decode(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 local_20;
  int local_1c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_20 = 0;
  local_1c = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar2 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)();
  iVar3 = (*(code *)PTR_d2i_ASN1_OBJECT_006a95c4)(&local_20,param_2,param_3);
  if (iVar3 == 0) {
LAB_0061a468:
    uVar5 = 0;
  }
  else {
    uVar4 = (*(code *)PTR_OBJ_obj2nid_006a822c)(local_20);
    (*(code *)PTR_ASN1_OBJECT_free_006a8104)(local_20);
    if (iVar2 == 0) {
      iVar2 = (*(code *)PTR_DSA_new_006a8624)();
      iVar3 = (*(code *)PTR_EVP_PKEY_assign_006a94e4)(param_1,0x32c,iVar2);
      if (iVar3 == 0) goto LAB_0061a468;
    }
    iVar2 = (*(code *)PTR_fill_GOST94_params_006aa718)(iVar2,uVar4);
    uVar5 = (uint)(iVar2 != 0);
  }
  if (local_1c == *(int *)puVar1) {
    return uVar5;
  }
  iVar2 = local_1c;
  uVar5 = (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (*(int *)(iVar2 + 0x14) != 0) {
                    /* WARNING: Could not recover jumptable at 0x0061a490. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar5 = (*(code *)PTR_EC_KEY_free_006a82d8)();
    return uVar5;
  }
  return uVar5;
}

