
void lh_stats_bio(_LHASH *lh,BIO *out)

{
  undefined *puVar1;
  char **ppcVar2;
  undefined4 *puVar3;
  ulong auStackX_8 [2];
  int aiStack_8c [2];
  undefined4 uStack_84;
  int iStack_80;
  int iStack_7c;
  undefined *puStack_78;
  code *pcStack_74;
  undefined4 auStack_6c [3];
  int *piStack_60;
  ulong *puStack_5c;
  undefined *puStack_58;
  undefined *puStack_50;
  undefined *puStack_48;
  int iStack_44;
  char *pcStack_40;
  undefined4 uStack_3c;
  int iStack_38;
  int iStack_34;
  undefined *puStack_30;
  code *pcStack_2c;
  undefined auStack_1c [4];
  undefined *local_18;
  ulong *puStack_10;
  
  local_18 = &_gp;
  BIO_printf(out,"num_items             = %lu\n",lh->num_items);
  BIO_printf(out,"num_nodes             = %u\n",lh->num_nodes);
  BIO_printf(out,"num_alloc_nodes       = %u\n",lh->num_alloc_nodes);
  BIO_printf(out,"num_expands           = %lu\n",lh->num_expands);
  BIO_printf(out,"num_expand_reallocs   = %lu\n",lh->num_expand_reallocs);
  BIO_printf(out,"num_contracts         = %lu\n",lh->num_contracts);
  BIO_printf(out,"num_contract_reallocs = %lu\n",lh->num_contract_reallocs);
  BIO_printf(out,"num_hash_calls        = %lu\n",lh->num_hash_calls);
  BIO_printf(out,"num_comp_calls        = %lu\n",lh->num_comp_calls);
  BIO_printf(out,"num_insert            = %lu\n",lh->num_insert);
  BIO_printf(out,"num_replace           = %lu\n",lh->num_replace);
  BIO_printf(out,"num_delete            = %lu\n",lh->num_delete);
  BIO_printf(out,"num_no_delete         = %lu\n",lh->num_no_delete);
  BIO_printf(out,"num_retrieve          = %lu\n",lh->num_retrieve);
  BIO_printf(out,"num_retrieve_miss     = %lu\n",lh->num_retrieve_miss);
  puStack_30 = PTR___stack_chk_guard_006a9ae8;
  auStackX_8[0] = lh->num_hash_comps;
  pcStack_40 = "num_hash_comps        = %lu\n";
  puStack_5c = auStackX_8;
  local_18 = &_gp;
  iStack_44 = *(int *)PTR___stack_chk_guard_006a9ae8;
  puStack_10 = puStack_5c;
  BIO_vprintf(out,"num_hash_comps        = %lu\n",puStack_5c);
  if (iStack_44 == *(int *)puStack_30) {
    return;
  }
  pcStack_2c = BIO_snprintf;
  (**(code **)(local_18 + -0x5330))();
  puStack_78 = PTR___stack_chk_guard_006a9ae8;
  puStack_58 = auStack_1c;
  piStack_60 = &iStack_38;
  puVar3 = &uStack_3c;
  ppcVar2 = &pcStack_40;
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
  _dopr(aiStack_8c,0,auStack_6c,&uStack_84,&iStack_80,ppcVar2,puVar3);
  if (iStack_7c == *(int *)puVar1) {
    return;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
                    /* WARNING: Could not recover jumptable at 0x00526240. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_fwrite_006a9a74)();
  return;
}

