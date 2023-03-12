
uint gost94_param_decode(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 local_20;
  int local_1c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_20 = 0;
  local_1c = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar2 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)();
  iVar3 = (*(code *)PTR_d2i_ASN1_OBJECT_006a84a4)(&local_20,param_2,param_3);
  if (iVar3 == 0) {
LAB_0061997c:
    uVar5 = 0;
  }
  else {
    uVar4 = (*(code *)PTR_OBJ_obj2nid_006a712c)(local_20);
    (*(code *)PTR_ASN1_OBJECT_free_006a7004)(local_20);
    if (iVar2 == 0) {
      iVar2 = (*(code *)PTR_DSA_new_006a7528)();
      iVar3 = (*(code *)PTR_EVP_PKEY_assign_006a83cc)(param_1,0x32c,iVar2);
      if (iVar3 == 0) goto LAB_0061997c;
    }
    iVar2 = (*(code *)PTR_fill_GOST94_params_006a960c)(iVar2,uVar4);
    uVar5 = (uint)(iVar2 != 0);
  }
  if (local_1c == *(int *)puVar1) {
    return uVar5;
  }
  iVar2 = local_1c;
  uVar5 = (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (*(int *)(iVar2 + 0x14) != 0) {
                    /* WARNING: Could not recover jumptable at 0x006199a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar5 = (*(code *)PTR_EC_KEY_free_006a71d4)();
    return uVar5;
  }
  return uVar5;
}

