
void ssleay_rand_cleanup(void)

{
  (*(code *)PTR_OPENSSL_cleanse_006a7074)(state,0x413);
  state_num = 0;
  state_index = 0;
  (*(code *)PTR_OPENSSL_cleanse_006a7074)(md,0x14);
  md_count._0_4_ = 0;
  md_count._4_4_ = 0;
  entropy._4_4_ = 0;
  entropy._0_4_ = 0;
  initialized = 0;
  return;
}
