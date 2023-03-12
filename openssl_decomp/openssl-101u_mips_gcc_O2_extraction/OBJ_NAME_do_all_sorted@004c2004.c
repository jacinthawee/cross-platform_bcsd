
void OBJ_NAME_do_all_sorted(int type,fn *fn,void *arg)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  void *num;
  undefined4 uVar4;
  int local_34;
  int local_30;
  void *local_2c;
  int local_28;
  code *local_24;
  int *local_20;
  int local_1c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_1c = *(int *)PTR___stack_chk_guard_006a9ae8;
  local_34 = type;
  iVar2 = (*(code *)PTR_lh_num_items_006a8330)(names_lh);
  num = (void *)(iVar2 << 2);
  local_2c = CRYPTO_malloc((int)num,"o_names.c",0x13a);
  if (local_2c != (void *)0x0) {
    local_30 = 0;
    local_24 = do_all_sorted_fn;
    local_20 = &local_34;
    iVar2 = 0;
    local_28 = type;
    (*(code *)PTR_lh_doall_arg_006a83a0)(names_lh,do_all_fn_LHASH_DOALL_ARG,&local_28);
    (*(code *)PTR_qsort_006a9988)(local_2c,local_30,4,do_all_sorted_cmp);
    if (0 < local_30) {
      do {
        iVar3 = iVar2 * 4;
        iVar2 = iVar2 + 1;
        (*fn)(*(OBJ_NAME **)((int)local_2c + iVar3),arg);
      } while (iVar2 < local_30);
    }
    num = local_2c;
    CRYPTO_free(local_2c);
  }
  if (local_1c == *(int *)puVar1) {
    return;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar2 = names_lh;
  puVar1 = PTR_lh_doall_006a8490;
  if (names_lh != 0) {
    uVar4 = *(undefined4 *)(names_lh + 0x20);
    *(undefined4 *)(names_lh + 0x20) = 0;
    free_type = num;
    (*(code *)puVar1)(iVar2,names_lh_free_LHASH_DOALL);
    if ((int)num < 0) {
      (*(code *)PTR_lh_free_006a7418)(names_lh);
      (*(code *)PTR_sk_pop_free_006a7058)(name_funcs_stack,name_funcs_free);
      names_lh = 0;
      name_funcs_stack = 0;
    }
    else {
      *(undefined4 *)(names_lh + 0x20) = uVar4;
    }
  }
  return;
}

