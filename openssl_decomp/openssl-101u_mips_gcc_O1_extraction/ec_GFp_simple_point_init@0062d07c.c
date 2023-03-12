
undefined4 ec_GFp_simple_point_init(int param_1)

{
  (*(code *)PTR_BN_init_006a857c)(param_1 + 4);
  (*(code *)PTR_BN_init_006a857c)(param_1 + 0x18);
  (*(code *)PTR_BN_init_006a857c)(param_1 + 0x2c);
  *(undefined4 *)(param_1 + 0x40) = 0;
  return 1;
}

