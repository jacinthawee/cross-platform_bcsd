
void lh_node_usage_stats_bio(_LHASH *lh,BIO *out)

{
  undefined *puVar1;
  LHASH_NODE *pLVar2;
  int iVar3;
  LHASH_NODE **ppLVar4;
  LHASH_NODE **ppLVar5;
  undefined4 *puVar6;
  int *piVar7;
  uint uVar8;
  uint uVar9;
  undefined4 uStackX_8;
  undefined4 uStackX_c;
  int aiStack_84 [2];
  undefined4 uStack_7c;
  int iStack_78;
  int iStack_74;
  undefined *puStack_70;
  code *pcStack_6c;
  char **appcStack_64 [3];
  undefined4 *puStack_58;
  undefined4 *puStack_54;
  undefined *puStack_50;
  undefined4 *puStack_48;
  int iStack_44;
  char *pcStack_40;
  undefined4 uStack_3c;
  int iStack_38;
  int iStack_34;
  undefined *puStack_30;
  code *pcStack_2c;
  uint local_28;
  uint local_24;
  undefined *local_20;
  undefined4 uStack_1c;
  undefined *puStack_18;
  
  piVar7 = &iStack_38;
  local_20 = &_gp;
  if (lh->num_nodes != 0) {
    ppLVar4 = lh->b;
    local_24 = 0;
    uVar9 = 0;
    ppLVar5 = ppLVar4 + lh->num_nodes;
    do {
      pLVar2 = *ppLVar4;
      iVar3 = 0;
      if (pLVar2 != (LHASH_NODE *)0x0) {
        do {
          pLVar2 = pLVar2->next;
          iVar3 = iVar3 + 1;
        } while (pLVar2 != (lhash_node_st *)0x0);
        if (iVar3 != 0) {
          local_24 = local_24 + 1;
          uVar9 = uVar9 + iVar3;
        }
      }
      ppLVar4 = ppLVar4 + 1;
    } while (ppLVar5 != ppLVar4);
    BIO_printf(out,"%lu nodes used out of %u\n",local_24);
    BIO_printf(out,"%lu items\n",uVar9);
    if (local_24 != 0) {
      if (local_24 == 0) {
        trap(7);
      }
      local_28 = uVar9 / local_24;
      uVar8 = lh->num_nodes;
      if (uVar8 == 0) {
        trap(7);
      }
      if (local_24 == 0) {
        trap(7);
      }
      local_24 = ((uVar9 % local_24) * 100) / local_24;
      if (uVar8 == 0) {
        trap(7);
      }
      BIO_printf(out,"load %d.%02d  actual load %d.%02d\n",uVar9 / uVar8,
                 ((uVar9 % uVar8) * 100) / uVar8);
    }
    return;
  }
  uStack_1c = 0;
  BIO_printf(out,"%lu nodes used out of %u\n",0);
  puStack_30 = PTR___stack_chk_guard_006aabf0;
  pcStack_40 = "%lu items\n";
  puStack_58 = &uStackX_8;
  uStackX_8 = 0;
  puStack_18 = &_gp;
  iStack_44 = *(int *)PTR___stack_chk_guard_006aabf0;
  uStackX_c = uStack_1c;
  BIO_vprintf(out,"%lu items\n",puStack_58);
  if (iStack_44 == *(int *)puStack_30) {
    return;
  }
  pcStack_2c = BIO_snprintf;
  (**(code **)(puStack_18 + -0x5328))();
  puStack_70 = PTR___stack_chk_guard_006aabf0;
  puStack_54 = &uStack_1c;
  puVar6 = &uStack_3c;
  appcStack_64[0] = &pcStack_40;
  puStack_50 = &_gp;
  iStack_34 = *(int *)PTR___stack_chk_guard_006aabf0;
  puStack_48 = puStack_54;
  _dopr_constprop_0(&iStack_44);
  if (iStack_34 == *(int *)puStack_70) {
    return;
  }
  pcStack_6c = BIO_vsnprintf;
  aiStack_84[0] = iStack_34;
  (**(code **)(puStack_50 + -0x5328))();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iStack_74 = *(int *)PTR___stack_chk_guard_006aabf0;
  _dopr_constprop_0(aiStack_84,appcStack_64,&uStack_7c,&iStack_78,puVar6,piVar7);
  if (iStack_74 != *(int *)puVar1) {
    (*(code *)PTR___stack_chk_fail_006aabb8)();
                    /* WARNING: Could not recover jumptable at 0x00529660. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_fwrite_006aab7c)();
    return;
  }
  return;
}

