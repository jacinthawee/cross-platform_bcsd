
int * tree_find_sk(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined *puVar1;
  undefined **ppuVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined **ppuVar6;
  int iVar7;
  undefined *local_30 [3];
  undefined auStack_24 [4];
  undefined4 local_20;
  int local_14;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_30[0] = auStack_24;
  ppuVar6 = local_30;
  local_14 = *(int *)PTR___stack_chk_guard_006aabf0;
  local_20 = param_2;
  ppuVar2 = (undefined **)(*(code *)PTR_sk_find_006a906c)();
  if (ppuVar2 == (undefined **)0xffffffff) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)(*(code *)PTR_sk_value_006a7f24)(param_1);
    ppuVar6 = ppuVar2;
  }
  if (local_14 != *(int *)puVar1) {
    iVar5 = local_14;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    iVar7 = 0;
    do {
      iVar4 = (*(code *)PTR_sk_num_006a7f2c)(*(undefined4 *)(iVar5 + 4));
      if (iVar4 <= iVar7) {
        return (int *)0x0;
      }
      iVar4 = iVar7 + 1;
      piVar3 = (int *)(*(code *)PTR_sk_value_006a7f24)(*(undefined4 *)(iVar5 + 4),iVar7);
      iVar7 = iVar4;
    } while (((undefined **)piVar3[1] != ppuVar6) ||
            (iVar4 = (*(code *)PTR_OBJ_cmp_006a9de4)(*(undefined4 *)(*piVar3 + 4),param_3),
            iVar4 != 0));
    return piVar3;
  }
  return piVar3;
}

