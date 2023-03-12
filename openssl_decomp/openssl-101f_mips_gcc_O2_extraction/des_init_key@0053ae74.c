
undefined4 des_init_key(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  (*(code *)PTR_DES_set_key_unchecked_006a8ad8)
            (param_2,*(undefined4 *)(param_1 + 0x60),param_3,param_4,&_gp);
  return 1;
}

