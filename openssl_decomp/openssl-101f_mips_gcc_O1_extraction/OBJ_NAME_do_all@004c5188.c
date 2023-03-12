
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void OBJ_NAME_do_all(int type,fn *fn,void *arg)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  code *pcVar5;
  int *piVar6;
  undefined4 uVar7;
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
  
  puStack_48 = PTR___stack_chk_guard_006aabf0;
  pcVar5 = do_all_fn_LHASH_DOALL_ARG;
  piVar6 = &local_18;
  local_c = *(int *)PTR___stack_chk_guard_006aabf0;
  iStack_58 = names_lh;
  local_18 = type;
  local_14 = fn;
  local_10 = arg;
  (*(code *)PTR_lh_doall_arg_006a94bc)();
  if (local_c == *(int *)puStack_48) {
    return;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iStack_4c = *(int *)PTR___stack_chk_guard_006aabf0;
  iStack_64 = iStack_58;
  iVar2 = (*(code *)PTR_lh_num_items_006a9450)(names_lh);
  pvStack_5c = CRYPTO_malloc(iVar2 << 2,"o_names.c",0x141);
  iStack_60 = 0;
  iVar2 = 0;
  pcStack_54 = do_all_sorted_fn;
  piStack_50 = &iStack_64;
  (*(code *)PTR_lh_doall_arg_006a94bc)(names_lh,do_all_fn_LHASH_DOALL_ARG,&iStack_58);
  (*(code *)PTR_qsort_006aaa94)(pvStack_5c,iStack_60,4,do_all_sorted_cmp);
  if (0 < iStack_60) {
    do {
      iVar3 = iVar2 * 4;
      iVar2 = iVar2 + 1;
      (*pcVar5)(*(undefined4 *)((int)pvStack_5c + iVar3),piVar6);
    } while (iVar2 < iStack_60);
  }
  pvVar4 = pvStack_5c;
  CRYPTO_free(pvStack_5c);
  if (iStack_4c == *(int *)puVar1) {
    return;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar2 = names_lh;
  puVar1 = PTR_lh_doall_006a95b0;
  if (names_lh != 0) {
    uVar7 = *(undefined4 *)(names_lh + 0x20);
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
      *(undefined4 *)(names_lh + 0x20) = uVar7;
    }
  }
  return;
}

