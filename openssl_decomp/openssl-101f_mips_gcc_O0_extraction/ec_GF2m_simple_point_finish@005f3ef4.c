
void ec_GF2m_simple_point_finish(int param_1)

{
  (*(code *)PTR_BN_free_006a811c)(param_1 + 4);
  (*(code *)PTR_BN_free_006a811c)(param_1 + 0x18);
                    /* WARNING: Could not recover jumptable at 0x005f3f40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_BN_free_006a811c)(param_1 + 0x2c);
  return;
}

