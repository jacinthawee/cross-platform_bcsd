
void lh_node_usage_stats_bio(_LHASH *lh,BIO *out)

{
  undefined *puVar1;
  LHASH_NODE *pLVar2;
  int iVar3;
  LHASH_NODE **ppLVar4;
  LHASH_NODE **ppLVar5;
  char **ppcVar6;
  undefined4 *puVar7;
  uint uVar8;
  uint uVar9;
  undefined4 uStackX_8;
  undefined4 uStackX_c;
  int aiStack_8c [2];
  undefined4 uStack_84;
  int iStack_80;
  int iStack_7c;
  undefined *puStack_78;
  code *pcStack_74;
  undefined4 auStack_6c [3];
  int *piStack_60;
  undefined4 *puStack_5c;
  undefined4 *puStack_58;
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
  
  piStack_60 = &iStack_38;
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
  puStack_30 = PTR___stack_chk_guard_006a9ae8;
  pcStack_40 = "%lu items\n";
  puStack_5c = &uStackX_8;
  uStackX_8 = 0;
  puStack_18 = &_gp;
  iStack_44 = *(int *)PTR___stack_chk_guard_006a9ae8;
  uStackX_c = uStack_1c;
  BIO_vprintf(out,"%lu items\n",puStack_5c);
  if (iStack_44 == *(int *)puStack_30) {
    return;
  }
  pcStack_2c = BIO_snprintf;
  (**(code **)(puStack_18 + -0x5330))();
  puStack_78 = PTR___stack_chk_guard_006a9ae8;
  puStack_58 = &uStack_1c;
  puVar7 = &uStack_3c;
  ppcVar6 = &pcStack_40;
  auStack_6c[0] = 0;
  puStack_50 = &_gp;
  iStack_34 = *(int *)PTR___stack_chk_guard_006a9ae8;
  puStack_48 = puStack_58;
  _dopr(&iStack_44);
  if (iStack_34 == *(int *)puStack_78) {
    return;
  }
  pcStack_74 = BIO_vsnprintf;
  aiStack_8c[0] = iStack_34;
  (**(code **)(puStack_50 + -0x5330))();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iStack_7c = *(int *)PTR___stack_chk_guard_006a9ae8;
  _dopr(aiStack_8c,0,auStack_6c,&uStack_84,&iStack_80,ppcVar6,puVar7);
  if (iStack_7c == *(int *)puVar1) {
    return;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
                    /* WARNING: Could not recover jumptable at 0x00526240. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_fwrite_006a9a74)();
  return;
}

