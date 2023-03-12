
void ec_GFp_simple_group_clear_finish(int param_1)

{
  (*(code *)PTR_BN_clear_free_006a9130)(param_1 + 0x48);
  (*(code *)PTR_BN_clear_free_006a9130)(param_1 + 0x74);
                    /* WARNING: Could not recover jumptable at 0x0062db50. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_BN_clear_free_006a9130)(param_1 + 0x88);
  return;
}

