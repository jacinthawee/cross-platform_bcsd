
undefined4 des_ede_init_key(int param_1,const_DES_cblock *param_2)

{
  DES_set_key_unchecked(param_2,*(DES_key_schedule **)(param_1 + 0x60));
  DES_set_key_unchecked(param_2[1],(DES_key_schedule *)(*(int *)(param_1 + 0x60) + 0x80));
  memcpy((void *)((int)*(void **)(param_1 + 0x60) + 0x100),*(void **)(param_1 + 0x60),0x80);
  return 1;
}
