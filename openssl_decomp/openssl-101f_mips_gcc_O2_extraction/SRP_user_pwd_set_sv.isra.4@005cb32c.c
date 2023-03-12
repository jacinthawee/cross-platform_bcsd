
int * SRP_user_pwd_set_sv_isra_4(int *param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined *puVar1;
  uint uVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  undefined auStack_9e8 [2500];
  int local_24;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_24 = *(int *)PTR___stack_chk_guard_006aabf0;
  uVar2 = (*(code *)PTR_strlen_006aab30)(param_3);
  if ((uVar2 < 0x9c5) && (uVar2 = (*(code *)PTR_strlen_006aab30)(param_4), uVar2 < 0x9c5)) {
    uVar4 = t_fromb64(auStack_9e8,param_4);
    iVar6 = (*(code *)PTR_BN_bin2bn_006a89f0)(auStack_9e8,uVar4,0);
    *param_2 = iVar6;
    if (iVar6 != 0) {
      uVar4 = t_fromb64(auStack_9e8,param_3);
      iVar6 = (*(code *)PTR_BN_bin2bn_006a89f0)(auStack_9e8,uVar4,0);
      piVar3 = (int *)(uint)(iVar6 != 0);
      *param_1 = iVar6;
      goto LAB_005cb3ac;
    }
  }
  piVar3 = (int *)0x0;
LAB_005cb3ac:
  if (local_24 == *(int *)puVar1) {
    return piVar3;
  }
  iVar6 = local_24;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  piVar3 = (int *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x14,"srp_vfy.c",0xf6);
  if (piVar3 != (int *)0x0) {
    iVar5 = (*(code *)PTR_sk_new_null_006a80a4)();
    *piVar3 = iVar5;
    if (iVar5 != 0) {
      iVar5 = (*(code *)PTR_sk_new_null_006a80a4)();
      piVar3[1] = iVar5;
      if (iVar5 != 0) {
        piVar3[3] = 0;
        piVar3[4] = 0;
        piVar3[2] = 0;
        if (iVar6 == 0) {
          return piVar3;
        }
        iVar6 = (*(code *)PTR_BUF_strdup_006a80dc)(iVar6);
        piVar3[2] = iVar6;
        if (iVar6 == 0) {
          (*(code *)PTR_sk_free_006a7f80)(*piVar3);
          (*(code *)PTR_sk_free_006a7f80)(piVar3[1]);
          (*(code *)PTR_CRYPTO_free_006a7f88)(piVar3);
          return (int *)0x0;
        }
        return piVar3;
      }
    }
    (*(code *)PTR_CRYPTO_free_006a7f88)(piVar3);
  }
  return (int *)0x0;
}

