
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void OBJ_NAME_do_all(int type,fn *fn,void *arg)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  void *num;
  code *pcVar4;
  int *piVar5;
  undefined4 uVar6;
  int iStack_64;
  int iStack_60;
  void *pvStack_5c;
  int iStack_58;
  code *pcStack_54;
  int *piStack_50;
  int iStack_4c;
  undefined *puStack_48;
  int local_18;
  fn *local_14;
  void *local_10;
  int local_c;
  
  puStack_48 = PTR___stack_chk_guard_006a9ae8;
  pcVar4 = do_all_fn_LHASH_DOALL_ARG;
  piVar5 = &local_18;
  local_c = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar3 = names_lh;
  local_18 = type;
  local_14 = fn;
  local_10 = arg;
  (*(code *)PTR_lh_doall_arg_006a83a0)();
  if (local_c == *(int *)puStack_48) {
    return;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iStack_4c = *(int *)PTR___stack_chk_guard_006a9ae8;
  iStack_64 = iVar3;
  iVar2 = (*(code *)PTR_lh_num_items_006a8330)(names_lh);
  num = (void *)(iVar2 << 2);
  pvStack_5c = CRYPTO_malloc((int)num,"o_names.c",0x13a);
  if (pvStack_5c != (void *)0x0) {
    iStack_60 = 0;
    pcStack_54 = do_all_sorted_fn;
    piStack_50 = &iStack_64;
    iVar2 = 0;
    iStack_58 = iVar3;
    (*(code *)PTR_lh_doall_arg_006a83a0)(names_lh,do_all_fn_LHASH_DOALL_ARG,&iStack_58);
    (*(code *)PTR_qsort_006a9988)(pvStack_5c,iStack_60,4,do_all_sorted_cmp);
    if (0 < iStack_60) {
      do {
        iVar3 = iVar2 * 4;
        iVar2 = iVar2 + 1;
        (*pcVar4)(*(undefined4 *)((int)pvStack_5c + iVar3),piVar5);
      } while (iVar2 < iStack_60);
    }
    num = pvStack_5c;
    CRYPTO_free(pvStack_5c);
  }
  if (iStack_4c == *(int *)puVar1) {
    return;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar3 = names_lh;
  puVar1 = PTR_lh_doall_006a8490;
  if (names_lh != 0) {
    uVar6 = *(undefined4 *)(names_lh + 0x20);
    *(undefined4 *)(names_lh + 0x20) = 0;
    free_type = num;
    (*(code *)puVar1)(iVar3,names_lh_free_LHASH_DOALL);
    if ((int)num < 0) {
      (*(code *)PTR_lh_free_006a7418)(names_lh);
      (*(code *)PTR_sk_pop_free_006a7058)(name_funcs_stack,name_funcs_free);
      names_lh = 0;
      name_funcs_stack = 0;
    }
    else {
      *(undefined4 *)(names_lh + 0x20) = uVar6;
    }
  }
  return;
}

