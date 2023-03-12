
void OBJ_NAME_do_all_sorted(int type,fn *fn,void *arg)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  undefined4 uVar5;
  int local_34;
  int local_30;
  void *local_2c;
  int local_28;
  code *local_24;
  int *local_20;
  int local_1c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_1c = *(int *)PTR___stack_chk_guard_006aabf0;
  local_34 = type;
  iVar2 = (*(code *)PTR_lh_num_items_006a9450)(names_lh);
  local_2c = CRYPTO_malloc(iVar2 << 2,"o_names.c",0x141);
  local_30 = 0;
  iVar2 = 0;
  local_24 = do_all_sorted_fn;
  local_20 = &local_34;
  local_28 = type;
  (*(code *)PTR_lh_doall_arg_006a94bc)(names_lh,do_all_fn_LHASH_DOALL_ARG,&local_28);
  (*(code *)PTR_qsort_006aaa94)(local_2c,local_30,4,do_all_sorted_cmp);
  if (0 < local_30) {
    do {
      iVar3 = iVar2 * 4;
      iVar2 = iVar2 + 1;
      (*fn)(*(OBJ_NAME **)((int)local_2c + iVar3),arg);
    } while (iVar2 < local_30);
  }
  pvVar4 = local_2c;
  CRYPTO_free(local_2c);
  if (local_1c == *(int *)puVar1) {
    return;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar2 = names_lh;
  puVar1 = PTR_lh_doall_006a95b0;
  if (names_lh != 0) {
    uVar5 = *(undefined4 *)(names_lh + 0x20);
    *(undefined4 *)(names_lh + 0x20) = 0;
    free_type = pvVar4;
    (*(code *)puVar1)(iVar2,names_lh_free_LHASH_DOALL);
    if ((int)pvVar4 < 0) {
      (*(code *)PTR_lh_free_006a8518)(names_lh);
      (*(code *)PTR_sk_pop_free_006a8158)(name_funcs_stack,name_funcs_free);
      names_lh = 0;
      name_funcs_stack = 0;
    }
    else {
      *(undefined4 *)(names_lh + 0x20) = uVar5;
    }
  }
  return;
}

