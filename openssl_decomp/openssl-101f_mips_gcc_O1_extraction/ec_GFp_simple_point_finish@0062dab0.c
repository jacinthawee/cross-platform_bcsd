
void ec_GFp_simple_point_finish(int param_1)

{
  (*(code *)PTR_BN_free_006a811c)(param_1 + 4);
  (*(code *)PTR_BN_free_006a811c)(param_1 + 0x18);
                    /* WARNING: Could not recover jumptable at 0x0062dafc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_BN_free_006a811c)(param_1 + 0x2c);
  return;
}

