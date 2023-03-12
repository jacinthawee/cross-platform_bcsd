
void ec_GFp_simple_point_clear_finish(int param_1)

{
  (*(code *)PTR_BN_clear_free_006a9130)(param_1 + 4);
  (*(code *)PTR_BN_clear_free_006a9130)(param_1 + 0x18);
  (*(code *)PTR_BN_clear_free_006a9130)(param_1 + 0x2c);
  *(undefined4 *)(param_1 + 0x40) = 0;
  return;
}

