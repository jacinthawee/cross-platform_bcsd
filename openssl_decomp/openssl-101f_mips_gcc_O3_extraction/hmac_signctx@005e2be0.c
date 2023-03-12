
undefined4 hmac_signctx(int param_1,int param_2,int *param_3,undefined4 param_4)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_20;
  int local_1c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_1c = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar5 = *(int *)(param_1 + 0x14);
  iVar4 = param_2;
  uVar2 = (*(code *)PTR_EVP_MD_CTX_md_006a85fc)(param_4);
  iVar3 = (*(code *)PTR_EVP_MD_size_006a8f2c)(uVar2);
  if (-1 < iVar3) {
    *param_3 = iVar3;
    if (param_2 == 0) {
      uVar2 = 1;
      goto LAB_005e2c74;
    }
    iVar3 = (*(code *)PTR_HMAC_Final_006a8ba8)(iVar5 + 0x14,param_2,&local_20);
    iVar4 = param_2;
    if (iVar3 != 0) {
      uVar2 = 1;
      *param_3 = local_20;
      goto LAB_005e2c74;
    }
  }
  uVar2 = 0;
LAB_005e2c74:
  if (local_1c == *(int *)puVar1) {
    return uVar2;
  }
  iVar3 = local_1c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  (*(code *)PTR_HMAC_CTX_set_flags_006aa770)
            (*(int *)(iVar3 + 0x14) + 0x14,*(uint *)(iVar4 + 8) & 0xfffffeff);
  (*(code *)PTR_EVP_MD_CTX_set_flags_006a8600)(iVar4,0x100);
  *(code **)(iVar4 + 0x14) = int_update;
  return 1;
}

