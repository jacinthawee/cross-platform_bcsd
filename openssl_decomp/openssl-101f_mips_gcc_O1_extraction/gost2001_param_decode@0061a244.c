
uint gost2001_param_decode(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 unaff_s3;
  undefined4 uStack_60;
  int iStack_5c;
  undefined *puStack_54;
  int iStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  code *pcStack_44;
  undefined *local_30;
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  
  puStack_54 = PTR___stack_chk_guard_006aabf0;
  local_30 = &_gp;
  local_20 = 0;
  local_1c = *(int *)PTR___stack_chk_guard_006aabf0;
  local_28 = param_3;
  local_24 = param_2;
  iStack_50 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)();
  uVar6 = local_24;
  iVar5 = local_28;
  iVar2 = (**(code **)(local_30 + -0x691c))(&local_20);
  if (iVar2 == 0) {
LAB_0061a34c:
    uVar3 = 0;
  }
  else {
    unaff_s3 = (**(code **)(local_30 + -0x7cb4))(local_20);
    (**(code **)(local_30 + -0x7ddc))(local_20);
    if (iStack_50 == 0) {
      iStack_50 = (**(code **)(local_30 + -0x7c38))();
      uVar6 = 0x32b;
      iVar5 = iStack_50;
      iVar2 = (**(code **)(local_30 + -0x69fc))(param_1);
      if (iVar2 == 0) goto LAB_0061a34c;
    }
    uVar6 = unaff_s3;
    iVar2 = fill_GOST2001_params(iStack_50);
    uVar3 = (uint)(iVar2 != 0);
  }
  if (local_1c == *(int *)puStack_54) {
    return uVar3;
  }
  pcStack_44 = gost94_param_decode;
  iVar2 = local_1c;
  (**(code **)(local_30 + -0x5328))();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  uStack_60 = 0;
  iStack_5c = *(int *)PTR___stack_chk_guard_006aabf0;
  uStack_4c = param_1;
  uStack_48 = unaff_s3;
  iVar4 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)();
  iVar5 = (*(code *)PTR_d2i_ASN1_OBJECT_006a95c4)(&uStack_60,uVar6,iVar5);
  if (iVar5 == 0) {
LAB_0061a468:
    uVar3 = 0;
  }
  else {
    uVar6 = (*(code *)PTR_OBJ_obj2nid_006a822c)(uStack_60);
    (*(code *)PTR_ASN1_OBJECT_free_006a8104)(uStack_60);
    if (iVar4 == 0) {
      iVar4 = (*(code *)PTR_DSA_new_006a8624)();
      iVar5 = (*(code *)PTR_EVP_PKEY_assign_006a94e4)(iVar2,0x32c,iVar4);
      if (iVar5 == 0) goto LAB_0061a468;
    }
    iVar5 = (*(code *)PTR_fill_GOST94_params_006aa718)(iVar4,uVar6);
    uVar3 = (uint)(iVar5 != 0);
  }
  if (iStack_5c == *(int *)puVar1) {
    return uVar3;
  }
  iVar5 = iStack_5c;
  uVar3 = (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (*(int *)(iVar5 + 0x14) != 0) {
                    /* WARNING: Could not recover jumptable at 0x0061a490. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar3 = (*(code *)PTR_EC_KEY_free_006a82d8)();
    return uVar3;
  }
  return uVar3;
}

