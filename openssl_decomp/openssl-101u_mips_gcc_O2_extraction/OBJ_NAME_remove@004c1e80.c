
/* WARNING: Restarted to delay deadcode elimination for space: ram */

int OBJ_NAME_remove(char *name,int type)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  void *num;
  code *pcVar4;
  uint *in_a2;
  uint **ppuVar5;
  uint **unaff_s0;
  undefined *unaff_s2;
  undefined4 uVar6;
  int iStack_a4;
  int iStack_a0;
  void *pvStack_9c;
  int iStack_98;
  code *pcStack_94;
  int *piStack_90;
  int iStack_8c;
  undefined *puStack_88;
  undefined *puStack_84;
  undefined *puStack_80;
  uint *puStack_58;
  uint *puStack_54;
  uint *puStack_50;
  int iStack_4c;
  uint **ppuStack_48;
  code *pcStack_44;
  undefined *local_30;
  uint local_24 [2];
  char *local_1c;
  uint *local_14;
  
  puStack_84 = PTR___stack_chk_guard_006a9ae8;
  local_30 = &_gp;
  local_14 = *(uint **)PTR___stack_chk_guard_006a9ae8;
  puStack_54 = local_14;
  if (names_lh != 0) {
    puStack_54 = local_24;
    local_24[0] = type & 0xffff7fff;
    local_1c = name;
    unaff_s0 = (uint **)(*(code *)PTR_lh_delete_006a8390)(names_lh);
    if (unaff_s0 != (uint **)0x0) {
      unaff_s2 = &_gp_1;
      if (name_funcs_stack != 0) {
        iVar2 = (**(code **)(local_30 + -0x7fb4))();
        puStack_54 = *unaff_s0;
        if ((int)puStack_54 < iVar2) {
          iVar2 = (**(code **)(local_30 + -0x7fbc))(name_funcs_stack);
          in_a2 = unaff_s0[3];
          puStack_54 = *unaff_s0;
          (**(code **)(iVar2 + 8))(unaff_s0[2]);
        }
      }
      CRYPTO_free(unaff_s0);
      iVar2 = 1;
      goto LAB_004c1f28;
    }
  }
  iVar2 = 0;
LAB_004c1f28:
  if (local_14 == *(uint **)puStack_84) {
    return iVar2;
  }
  pcStack_44 = OBJ_NAME_do_all;
  puStack_58 = local_14;
  (**(code **)(local_30 + -0x5330))();
  puStack_88 = PTR___stack_chk_guard_006a9ae8;
  pcVar4 = do_all_fn_LHASH_DOALL_ARG;
  ppuVar5 = &puStack_58;
  iStack_4c = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar2 = names_lh;
  puStack_50 = in_a2;
  ppuStack_48 = unaff_s0;
  (*(code *)PTR_lh_doall_arg_006a83a0)();
  iVar3 = *(int *)puStack_88;
  if (iStack_4c == iVar3) {
    return iVar3;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iStack_8c = *(int *)PTR___stack_chk_guard_006a9ae8;
  iStack_a4 = iVar2;
  puStack_80 = unaff_s2;
  iVar3 = (*(code *)PTR_lh_num_items_006a8330)(names_lh);
  num = (void *)(iVar3 << 2);
  pvStack_9c = CRYPTO_malloc((int)num,"o_names.c",0x13a);
  if (pvStack_9c != (void *)0x0) {
    iStack_a0 = 0;
    pcStack_94 = do_all_sorted_fn;
    piStack_90 = &iStack_a4;
    iVar3 = 0;
    iStack_98 = iVar2;
    (*(code *)PTR_lh_doall_arg_006a83a0)(names_lh,do_all_fn_LHASH_DOALL_ARG,&iStack_98);
    (*(code *)PTR_qsort_006a9988)(pvStack_9c,iStack_a0,4,do_all_sorted_cmp);
    if (0 < iStack_a0) {
      do {
        iVar2 = iVar3 * 4;
        iVar3 = iVar3 + 1;
        (*pcVar4)(*(undefined4 *)((int)pvStack_9c + iVar2),ppuVar5);
      } while (iVar3 < iStack_a0);
    }
    num = pvStack_9c;
    CRYPTO_free(pvStack_9c);
  }
  if (iStack_8c == *(int *)puVar1) {
    return *(int *)puVar1;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar2 = names_lh;
  puVar1 = PTR_lh_doall_006a8490;
  if (names_lh != 0) {
    uVar6 = *(undefined4 *)(names_lh + 0x20);
    *(undefined4 *)(names_lh + 0x20) = 0;
    free_type = num;
    (*(code *)puVar1)(iVar2,names_lh_free_LHASH_DOALL);
    iVar2 = names_lh;
    if ((int)num < 0) {
      (*(code *)PTR_lh_free_006a7418)(names_lh);
      iVar2 = (*(code *)PTR_sk_pop_free_006a7058)(name_funcs_stack,name_funcs_free);
      names_lh = 0;
      name_funcs_stack = 0;
    }
    else {
      *(undefined4 *)(names_lh + 0x20) = uVar6;
    }
  }
  return iVar2;
}

