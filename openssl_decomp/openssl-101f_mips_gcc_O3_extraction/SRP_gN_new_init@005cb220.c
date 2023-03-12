
int * SRP_gN_new_init(undefined *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  undefined4 uVar6;
  int iVar7;
  char *pcVar8;
  undefined4 uVar9;
  int *unaff_s0;
  undefined auStack_13d8 [2500];
  int iStack_a14;
  int *piStack_a0c;
  undefined *puStack_a08;
  undefined *puStack_a04;
  undefined auStack_9d8 [2500];
  int *local_14;
  
  puStack_a04 = PTR___stack_chk_guard_006aabf0;
  uVar9 = 0x11e;
  pcVar8 = "srp_vfy.c";
  local_14 = *(int **)PTR___stack_chk_guard_006aabf0;
  piVar2 = (int *)(*(code *)PTR_CRYPTO_malloc_006a8108)(8);
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    iVar3 = (*(code *)PTR_BUF_strdup_006a80dc)(param_1);
    *piVar2 = iVar3;
    unaff_s0 = piVar2;
    if (iVar3 != 0) {
      pcVar8 = (char *)t_fromb64(auStack_9d8,param_1);
      uVar9 = 0;
      iVar3 = (*(code *)PTR_BN_bin2bn_006a89f0)(auStack_9d8);
      piVar2[1] = iVar3;
      param_1 = auStack_9d8;
      if (iVar3 != 0) goto LAB_005cb2c8;
      (*(code *)PTR_CRYPTO_free_006a7f88)(*piVar2);
    }
    (*(code *)PTR_CRYPTO_free_006a7f88)(piVar2);
    piVar2 = (int *)0x0;
  }
LAB_005cb2c8:
  if (local_14 == *(int **)puStack_a04) {
    return piVar2;
  }
  piVar2 = local_14;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iStack_a14 = *(int *)PTR___stack_chk_guard_006aabf0;
  piStack_a0c = unaff_s0;
  puStack_a08 = param_1;
  uVar4 = (*(code *)PTR_strlen_006aab30)(uVar9);
  if ((uVar4 < 0x9c5) && (uVar4 = (*(code *)PTR_strlen_006aab30)(param_4), uVar4 < 0x9c5)) {
    uVar6 = t_fromb64(auStack_13d8,param_4);
    iVar3 = (*(code *)PTR_BN_bin2bn_006a89f0)(auStack_13d8,uVar6,0);
    *(int *)pcVar8 = iVar3;
    if (iVar3 != 0) {
      uVar9 = t_fromb64(auStack_13d8,uVar9);
      iVar3 = (*(code *)PTR_BN_bin2bn_006a89f0)(auStack_13d8,uVar9,0);
      piVar5 = (int *)(uint)(iVar3 != 0);
      *piVar2 = iVar3;
      goto LAB_005cb3ac;
    }
  }
  piVar5 = (int *)0x0;
LAB_005cb3ac:
  if (iStack_a14 == *(int *)puVar1) {
    return piVar5;
  }
  iVar3 = iStack_a14;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  piVar2 = (int *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x14,"srp_vfy.c",0xf6);
  if (piVar2 != (int *)0x0) {
    iVar7 = (*(code *)PTR_sk_new_null_006a80a4)();
    *piVar2 = iVar7;
    if (iVar7 != 0) {
      iVar7 = (*(code *)PTR_sk_new_null_006a80a4)();
      piVar2[1] = iVar7;
      if (iVar7 != 0) {
        piVar2[3] = 0;
        piVar2[4] = 0;
        piVar2[2] = 0;
        if (iVar3 == 0) {
          return piVar2;
        }
        iVar3 = (*(code *)PTR_BUF_strdup_006a80dc)(iVar3);
        piVar2[2] = iVar3;
        if (iVar3 == 0) {
          (*(code *)PTR_sk_free_006a7f80)(*piVar2);
          (*(code *)PTR_sk_free_006a7f80)(piVar2[1]);
          (*(code *)PTR_CRYPTO_free_006a7f88)(piVar2);
          return (int *)0x0;
        }
        return piVar2;
      }
    }
    (*(code *)PTR_CRYPTO_free_006a7f88)(piVar2);
  }
  return (int *)0x0;
}

