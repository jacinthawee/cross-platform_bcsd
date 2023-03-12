
void ec_GF2m_simple_group_finish(int param_1)

{
  (*(code *)PTR_BN_free_006a811c)(param_1 + 0x48);
  (*(code *)PTR_BN_free_006a811c)(param_1 + 0x74);
                    /* WARNING: Could not recover jumptable at 0x005f3eec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_BN_free_006a811c)(param_1 + 0x88);
  return;
}

