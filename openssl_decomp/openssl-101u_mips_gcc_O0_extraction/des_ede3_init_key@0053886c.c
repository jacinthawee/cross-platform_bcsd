
undefined4 des_ede3_init_key(int param_1,int param_2)

{
  (*(code *)PTR_DES_set_key_unchecked_006a79e8)(param_2,*(undefined4 *)(param_1 + 0x60));
  (*(code *)PTR_DES_set_key_unchecked_006a79e8)(param_2 + 8,*(int *)(param_1 + 0x60) + 0x80);
  (*(code *)PTR_DES_set_key_unchecked_006a79e8)(param_2 + 0x10,*(int *)(param_1 + 0x60) + 0x100);
  return 1;
}

