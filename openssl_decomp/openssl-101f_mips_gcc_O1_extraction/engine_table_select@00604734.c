
int engine_table_select(int *param_1,undefined4 param_2)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 local_34 [4];
  int local_24;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_24 = *(int *)PTR___stack_chk_guard_006aabf0;
  if (*param_1 == 0) {
    iVar3 = 0;
    goto LAB_00604880;
  }
  (*(code *)PTR_ERR_set_mark_006aa8a0)();
  (*(code *)PTR_CRYPTO_lock_006a926c)(9,0x1e,"eng_table.c",0x102);
  if ((*param_1 == 0) ||
     (local_34[0] = param_2, iVar2 = (*(code *)PTR_lh_retrieve_006a84b0)(*param_1,local_34),
     iVar2 == 0)) {
    iVar3 = 0;
  }
  else {
    if (((*(int *)(iVar2 + 8) == 0) ||
        (iVar3 = (*(code *)PTR_engine_unlocked_init_006aa898)(), iVar3 == 0)) &&
       (iVar4 = *(int *)(iVar2 + 0xc), *(int *)(iVar2 + 0xc) == 0)) {
      do {
        iVar5 = iVar4 + 1;
        iVar3 = (*(code *)PTR_sk_value_006a7f24)(*(undefined4 *)(iVar2 + 4),iVar4);
        if (iVar3 == 0) goto LAB_006048b4;
        iVar4 = iVar5;
      } while (((*(int *)(iVar3 + 0x5c) < 1) && ((table_flags & 1) != 0)) ||
              (iVar5 = (*(code *)PTR_engine_unlocked_init_006aa898)(iVar3), iVar5 == 0));
      if ((iVar3 != *(int *)(iVar2 + 8)) &&
         (iVar4 = (*(code *)PTR_engine_unlocked_init_006aa898)(iVar3), iVar4 != 0)) {
        if (*(int *)(iVar2 + 8) != 0) {
          (*(code *)PTR_engine_unlocked_finish_006aa894)(*(int *)(iVar2 + 8),0);
        }
        *(int *)(iVar2 + 8) = iVar3;
        *(undefined4 *)(iVar2 + 0xc) = 1;
        goto LAB_00604850;
      }
    }
    else {
      iVar3 = *(int *)(iVar2 + 8);
    }
LAB_006048b4:
    *(undefined4 *)(iVar2 + 0xc) = 1;
  }
LAB_00604850:
  (*(code *)PTR_CRYPTO_lock_006a926c)(10,0x1e,"eng_table.c",0x148);
  (*(code *)PTR_ERR_pop_to_mark_006aa8a4)();
LAB_00604880:
  if (local_24 == *(int *)puVar1) {
    return iVar3;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iVar3 = *(int *)PTR___stack_chk_guard_006aabf0;
  (*(code *)PTR_lh_doall_arg_006a94bc)();
  if (iVar3 != *(int *)puVar1) {
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    while (iVar3 = (*(code *)PTR_sk_pop_006a9ec4)(initialized_engines), iVar3 != 0) {
      (*(code *)PTR_ENGINE_finish_006a80c4)(iVar3);
    }
    iVar3 = (*(code *)PTR_sk_free_006a7f80)(initialized_engines);
    initialized_engines = 0;
    return iVar3;
  }
  return *(int *)puVar1;
}

