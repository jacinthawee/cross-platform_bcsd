
void lh_stats_bio(_LHASH *lh,BIO *out)

{
  undefined *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  ulong auStackX_8 [2];
  int aiStack_84 [2];
  undefined4 uStack_7c;
  int iStack_78;
  int iStack_74;
  undefined *puStack_70;
  code *pcStack_6c;
  char **appcStack_64 [3];
  ulong *puStack_58;
  undefined *puStack_54;
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
  puStack_30 = PTR___stack_chk_guard_006aabf0;
  auStackX_8[0] = lh->num_hash_comps;
  pcStack_40 = "num_hash_comps        = %lu\n";
  puStack_58 = auStackX_8;
  local_18 = &_gp;
  iStack_44 = *(int *)PTR___stack_chk_guard_006aabf0;
  puStack_10 = puStack_58;
  BIO_vprintf(out,"num_hash_comps        = %lu\n",puStack_58);
  if (iStack_44 == *(int *)puStack_30) {
    return;
  }
  pcStack_2c = BIO_snprintf;
  (**(code **)(local_18 + -0x5328))();
  puStack_70 = PTR___stack_chk_guard_006aabf0;
  puStack_54 = auStack_1c;
  piVar3 = &iStack_38;
  puVar2 = &uStack_3c;
  appcStack_64[0] = &pcStack_40;
  puStack_50 = &_gp;
  iStack_34 = *(int *)PTR___stack_chk_guard_006aabf0;
  puStack_48 = puStack_54;
  _dopr_constprop_0(&iStack_44);
  if (iStack_34 != *(int *)puStack_70) {
    pcStack_6c = BIO_vsnprintf;
    aiStack_84[0] = iStack_34;
    (**(code **)(puStack_50 + -0x5328))();
    puVar1 = PTR___stack_chk_guard_006aabf0;
    iStack_74 = *(int *)PTR___stack_chk_guard_006aabf0;
    _dopr_constprop_0(aiStack_84,appcStack_64,&uStack_7c,&iStack_78,puVar2,piVar3);
    if (iStack_74 != *(int *)puVar1) {
      (*(code *)PTR___stack_chk_fail_006aabb8)();
                    /* WARNING: Could not recover jumptable at 0x00529660. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)PTR_fwrite_006aab7c)();
      return;
    }
    return;
  }
  return;
}

