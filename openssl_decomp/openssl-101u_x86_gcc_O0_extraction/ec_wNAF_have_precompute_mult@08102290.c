
bool ec_wNAF_have_precompute_mult(int param_1)

{
  int iVar1;
  
  iVar1 = EC_EX_DATA_get_data(*(undefined4 *)(param_1 + 0x44),ec_pre_comp_dup,ec_pre_comp_free,
                              ec_pre_comp_clear_free);
  return iVar1 != 0;
}

