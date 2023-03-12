
/* WARNING: Restarted to delay deadcode elimination for space: ram */

int ASN1_STRING_set_default_mask_asc(char *p)

{
  bool bVar1;
  undefined *puVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  undefined1 *puVar9;
  undefined4 in_a3;
  undefined1 *unaff_s6;
  int aiStack_128 [5];
  int iStack_114;
  int iStack_10c;
  undefined *puStack_108;
  int *piStack_104;
  undefined1 *puStack_100;
  undefined **ppuStack_f8;
  undefined1 *puStack_f4;
  int aiStack_c8 [5];
  int iStack_b4;
  int *piStack_ac;
  undefined *puStack_a8;
  char *pcStack_a4;
  undefined1 *puStack_a0;
  code *pcStack_9c;
  code *pcStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined *puStack_78;
  int iStack_6c;
  undefined *apuStack_68 [5];
  int iStack_54;
  undefined *puStack_50;
  char *pcStack_4c;
  char *local_18;
  int *local_14;
  
  puStack_50 = PTR___stack_chk_guard_006aabf0;
  puStack_100 = (undefined1 *)0x5;
  pcStack_a4 = "MASK:";
  local_14 = *(int **)PTR___stack_chk_guard_006aabf0;
  iVar3 = (*(code *)PTR_strncmp_006aaa7c)();
  if (iVar3 == 0) {
    if (p[5] == '\0') {
LAB_0056bd60:
      iVar3 = 0;
    }
    else {
      puStack_100 = (undefined1 *)0x0;
      pcStack_a4 = (char *)&local_18;
      uVar4 = (*(code *)PTR_strtoul_006aab38)(p + 5);
      if (*local_18 == '\0') goto LAB_0056bda4;
      iVar3 = 0;
    }
  }
  else {
    pcStack_a4 = "nombstr";
    iVar3 = (*(code *)PTR_strcmp_006aac20)(p);
    if (iVar3 == 0) {
      uVar4 = 0xffffd7ff;
    }
    else {
      pcStack_a4 = &DAT_0066c4b8;
      iVar3 = (*(code *)PTR_strcmp_006aac20)(p);
      if (iVar3 == 0) {
        uVar4 = 0xfffffffb;
      }
      else {
        pcStack_a4 = "utf8only";
        iVar3 = (*(code *)PTR_strcmp_006aac20)(p);
        if (iVar3 == 0) {
          uVar4 = 0x2000;
        }
        else {
          pcStack_a4 = "default";
          iVar3 = (*(code *)PTR_strcmp_006aac20)(p);
          if (iVar3 != 0) goto LAB_0056bd60;
          uVar4 = 0xffffffff;
        }
      }
    }
LAB_0056bda4:
    iVar3 = 1;
    global_mask = uVar4;
  }
  if (local_14 == *(int **)puStack_50) {
    return iVar3;
  }
  piVar6 = local_14;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_a8 = PTR___stack_chk_guard_006aabf0;
  ppuStack_f8 = apuStack_68;
  puStack_78 = &_gp;
  iStack_6c = 0;
  iStack_54 = *(int *)PTR___stack_chk_guard_006aabf0;
  pcStack_88 = table_cmp_BSEARCH_CMP_FN;
  piStack_ac = &iStack_6c;
  if (piVar6 != (int *)0x0) {
    piStack_ac = piVar6;
  }
  apuStack_68[0] = &_gp;
  pcStack_4c = p;
  iVar3 = (*(code *)PTR_OBJ_bsearch__006a9488)(ppuStack_f8,tbl_standard,0x13,0x14);
  if (iVar3 == 0) {
    unaff_s6 = &_ITM_registerTMCloneTable;
    if (stable != 0) {
      iVar3 = (**(code **)(puStack_78 + -0x6e74))(stable,ppuStack_f8);
      if (-1 < iVar3) {
        iVar3 = (**(code **)(puStack_78 + -0x7fbc))(stable,iVar3);
        if (iVar3 != 0) goto LAB_0056bee8;
      }
    }
    pcStack_88 = (code *)(global_mask & 0x2806);
    iVar3 = (**(code **)(puStack_78 + -0x60e8))(piStack_ac,pcStack_a4,puStack_100,in_a3);
  }
  else {
LAB_0056bee8:
    pcStack_88 = *(code **)(iVar3 + 0xc);
    if ((*(uint *)(iVar3 + 0x10) & 2) == 0) {
      pcStack_88 = (code *)((uint)pcStack_88 & global_mask);
    }
    uStack_80 = *(undefined4 *)(iVar3 + 8);
    uStack_84 = *(undefined4 *)(iVar3 + 4);
    iVar3 = (**(code **)(puStack_78 + -0x5fd4))(piStack_ac,pcStack_a4,puStack_100,in_a3);
  }
  iVar5 = 0;
  if (0 < iVar3) {
    iVar5 = *piStack_ac;
  }
  if (iStack_54 == *(int *)puStack_a8) {
    return iVar5;
  }
  pcStack_9c = ASN1_STRING_TABLE_get;
  aiStack_c8[0] = iStack_54;
  (**(code **)(puStack_78 + -0x5328))();
  puStack_108 = PTR___stack_chk_guard_006aabf0;
  piStack_104 = aiStack_c8;
  iVar5 = 0x14;
  iVar3 = 0x13;
  puVar9 = tbl_standard;
  iStack_b4 = *(int *)PTR___stack_chk_guard_006aabf0;
  puStack_a0 = puStack_100;
  iStack_10c = (*(code *)PTR_OBJ_bsearch__006a9488)(piStack_104);
  if (iStack_10c == 0) {
    puStack_100 = &_ITM_registerTMCloneTable;
    if (stable != 0) {
      puVar9 = (undefined1 *)piStack_104;
      piVar6 = (int *)(*(code *)PTR_sk_find_006a906c)();
      if (-1 < (int)piVar6) {
        iStack_10c = (*(code *)PTR_sk_value_006a7f24)(stable);
        puVar9 = (undefined1 *)piVar6;
      }
    }
  }
  if (iStack_b4 == *(int *)puStack_108) {
    return iStack_10c;
  }
  iVar8 = iStack_b4;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar2 = PTR___stack_chk_guard_006aabf0;
  iStack_114 = *(int *)PTR___stack_chk_guard_006aabf0;
  puStack_f4 = unaff_s6;
  if (stable == 0) {
    stable = (*(code *)PTR_sk_new_006a91b4)(sk_table_cmp);
    if (stable == 0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x81,0x41,"a_strnid.c",0xdd);
      iVar3 = 0;
      goto LAB_0056c1a8;
    }
  }
  aiStack_128[0] = iVar8;
  piVar6 = (int *)(*(code *)PTR_OBJ_bsearch__006a9488)
                            (aiStack_128,tbl_standard,0x13,0x14,table_cmp_BSEARCH_CMP_FN);
  if (piVar6 == (int *)0x0) {
    if (stable != 0) {
      iVar7 = (*(code *)PTR_sk_find_006a906c)(stable,aiStack_128);
      if (-1 < iVar7) {
        piVar6 = (int *)(*(code *)PTR_sk_value_006a7f24)(stable,iVar7);
        if (piVar6 != (int *)0x0) goto LAB_0056c16c;
      }
    }
    piVar6 = (int *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x14,"a_strnid.c",0xe1);
    if (piVar6 == (int *)0x0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x81,0x41,"a_strnid.c",0xe4);
      iVar3 = 0;
      goto LAB_0056c1a8;
    }
    *piVar6 = iVar8;
    bVar1 = true;
    piVar6[4] = 0x56bcb9;
  }
  else {
LAB_0056c16c:
    bVar1 = false;
    piVar6[4] = piVar6[4] & 1U | 0x56bcb8;
  }
  if ((int *)puVar9 != (int *)0xffffffff) {
    piVar6[1] = (int)puVar9;
  }
  if (iVar3 != -1) {
    piVar6[2] = iVar3;
  }
  piVar6[3] = iVar5;
  if (bVar1) {
    (*(code *)PTR_sk_push_006a80a8)(stable,piVar6);
    iVar3 = 1;
  }
  else {
    iVar3 = 1;
  }
LAB_0056c1a8:
  if (iStack_114 == *(int *)puVar2) {
    return iVar3;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar3 = stable;
  if (stable != 0) {
    stable = 0;
                    /* WARNING: Could not recover jumptable at 0x0056c30c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar3 = (*(code *)PTR_sk_pop_free_006a8158)(iVar3,st_free);
    return iVar3;
  }
  return (int)&_ITM_registerTMCloneTable;
}

