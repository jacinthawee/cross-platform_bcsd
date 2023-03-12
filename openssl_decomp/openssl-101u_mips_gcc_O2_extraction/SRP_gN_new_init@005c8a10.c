
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
  
  puStack_a04 = PTR___stack_chk_guard_006a9ae8;
  uVar9 = 0x132;
  pcVar8 = "srp_vfy.c";
  local_14 = *(int **)PTR___stack_chk_guard_006a9ae8;
  piVar2 = (int *)(*(code *)PTR_CRYPTO_malloc_006a7008)(8);
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    iVar3 = (*(code *)PTR_BUF_strdup_006a6fdc)(param_1);
    *piVar2 = iVar3;
    unaff_s0 = piVar2;
    if (iVar3 != 0) {
      pcVar8 = (char *)t_fromb64(auStack_9d8,param_1);
      uVar9 = 0;
      iVar3 = (*(code *)PTR_BN_bin2bn_006a7904)(auStack_9d8);
      piVar2[1] = iVar3;
      param_1 = auStack_9d8;
      if (iVar3 != 0) goto LAB_005c8ab8;
      (*(code *)PTR_CRYPTO_free_006a6e88)(*piVar2);
    }
    (*(code *)PTR_CRYPTO_free_006a6e88)(piVar2);
    piVar2 = (int *)0x0;
  }
LAB_005c8ab8:
  if (local_14 == *(int **)puStack_a04) {
    return piVar2;
  }
  piVar2 = local_14;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iStack_a14 = *(int *)PTR___stack_chk_guard_006a9ae8;
  piStack_a0c = unaff_s0;
  puStack_a08 = param_1;
  uVar4 = (*(code *)PTR_strlen_006a9a24)(uVar9);
  if ((uVar4 < 0x9c5) && (uVar4 = (*(code *)PTR_strlen_006a9a24)(param_4), uVar4 < 0x9c5)) {
    uVar6 = t_fromb64(auStack_13d8,param_4);
    iVar3 = (*(code *)PTR_BN_bin2bn_006a7904)(auStack_13d8,uVar6,0);
    *(int *)pcVar8 = iVar3;
    if (iVar3 != 0) {
      uVar9 = t_fromb64(auStack_13d8,uVar9);
      iVar3 = (*(code *)PTR_BN_bin2bn_006a7904)(auStack_13d8,uVar9,0);
      piVar5 = (int *)(uint)(iVar3 != 0);
      *piVar2 = iVar3;
      goto LAB_005c8b9c;
    }
  }
  piVar5 = (int *)0x0;
LAB_005c8b9c:
  if (iStack_a14 == *(int *)puVar1) {
    return piVar5;
  }
  iVar3 = iStack_a14;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  piVar2 = (int *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x14,"srp_vfy.c",0x10e);
  if (piVar2 != (int *)0x0) {
    iVar7 = (*(code *)PTR_sk_new_null_006a6fa4)();
    *piVar2 = iVar7;
    if (iVar7 != 0) {
      iVar7 = (*(code *)PTR_sk_new_null_006a6fa4)();
      piVar2[1] = iVar7;
      if (iVar7 != 0) {
        piVar2[3] = 0;
        piVar2[4] = 0;
        piVar2[2] = 0;
        if (iVar3 == 0) {
          return piVar2;
        }
        iVar3 = (*(code *)PTR_BUF_strdup_006a6fdc)(iVar3);
        piVar2[2] = iVar3;
        if (iVar3 == 0) {
          (*(code *)PTR_sk_free_006a6e80)(*piVar2);
          (*(code *)PTR_sk_free_006a6e80)(piVar2[1]);
          (*(code *)PTR_CRYPTO_free_006a6e88)(piVar2);
          return (int *)0x0;
        }
        return piVar2;
      }
    }
    (*(code *)PTR_CRYPTO_free_006a6e88)(piVar2);
  }
  return (int *)0x0;
}

