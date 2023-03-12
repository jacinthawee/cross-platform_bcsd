
/* WARNING: Restarted to delay deadcode elimination for space: ram */

int OBJ_NAME_remove(char *name,int type)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  code *pcVar5;
  uint *in_a2;
  uint **ppuVar6;
  uint **unaff_s0;
  undefined1 *unaff_s2;
  undefined4 uVar7;
  int iStack_a4;
  int iStack_a0;
  void *pvStack_9c;
  int iStack_98;
  code *pcStack_94;
  int *piStack_90;
  int iStack_8c;
  undefined *puStack_88;
  undefined *puStack_84;
  undefined1 *puStack_80;
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
  
  puStack_84 = PTR___stack_chk_guard_006aabf0;
  local_30 = &_gp;
  local_14 = *(uint **)PTR___stack_chk_guard_006aabf0;
  puStack_54 = local_14;
  if (names_lh != 0) {
    puStack_54 = local_24;
    local_24[0] = type & 0xffff7fff;
    local_1c = name;
    unaff_s0 = (uint **)(*(code *)PTR_lh_delete_006a94ac)(names_lh);
    if (unaff_s0 != (uint **)0x0) {
      unaff_s2 = &_ITM_registerTMCloneTable;
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
      goto LAB_004c5128;
    }
  }
  iVar2 = 0;
LAB_004c5128:
  if (local_14 == *(uint **)puStack_84) {
    return iVar2;
  }
  pcStack_44 = OBJ_NAME_do_all;
  puStack_58 = local_14;
  (**(code **)(local_30 + -0x5328))();
  puStack_88 = PTR___stack_chk_guard_006aabf0;
  pcVar5 = do_all_fn_LHASH_DOALL_ARG;
  ppuVar6 = &puStack_58;
  iStack_4c = *(int *)PTR___stack_chk_guard_006aabf0;
  iStack_98 = names_lh;
  puStack_50 = in_a2;
  ppuStack_48 = unaff_s0;
  (*(code *)PTR_lh_doall_arg_006a94bc)();
  iVar2 = *(int *)puStack_88;
  if (iStack_4c == iVar2) {
    return iVar2;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iStack_8c = *(int *)PTR___stack_chk_guard_006aabf0;
  iStack_a4 = iStack_98;
  puStack_80 = unaff_s2;
  iVar2 = (*(code *)PTR_lh_num_items_006a9450)(names_lh);
  pvStack_9c = CRYPTO_malloc(iVar2 << 2,"o_names.c",0x141);
  iStack_a0 = 0;
  iVar2 = 0;
  pcStack_94 = do_all_sorted_fn;
  piStack_90 = &iStack_a4;
  (*(code *)PTR_lh_doall_arg_006a94bc)(names_lh,do_all_fn_LHASH_DOALL_ARG,&iStack_98);
  (*(code *)PTR_qsort_006aaa94)(pvStack_9c,iStack_a0,4,do_all_sorted_cmp);
  if (0 < iStack_a0) {
    do {
      iVar3 = iVar2 * 4;
      iVar2 = iVar2 + 1;
      (*pcVar5)(*(undefined4 *)((int)pvStack_9c + iVar3),ppuVar6);
    } while (iVar2 < iStack_a0);
  }
  pvVar4 = pvStack_9c;
  CRYPTO_free(pvStack_9c);
  if (iStack_8c == *(int *)puVar1) {
    return *(int *)puVar1;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar2 = names_lh;
  puVar1 = PTR_lh_doall_006a95b0;
  if (names_lh != 0) {
    uVar7 = *(undefined4 *)(names_lh + 0x20);
    *(undefined4 *)(names_lh + 0x20) = 0;
    free_type = pvVar4;
    (*(code *)puVar1)(iVar2,names_lh_free_LHASH_DOALL);
    iVar2 = names_lh;
    if ((int)pvVar4 < 0) {
      (*(code *)PTR_lh_free_006a8518)(names_lh);
      iVar2 = (*(code *)PTR_sk_pop_free_006a8158)(name_funcs_stack,name_funcs_free);
      names_lh = 0;
      name_funcs_stack = 0;
    }
    else {
      *(undefined4 *)(names_lh + 0x20) = uVar7;
    }
  }
  return iVar2;
}

