
undefined4 des_init_key(int param_1,const_DES_cblock *param_2)

{
  DES_set_key_unchecked(param_2,*(DES_key_schedule **)(param_1 + 0x60));
  return 1;
}

