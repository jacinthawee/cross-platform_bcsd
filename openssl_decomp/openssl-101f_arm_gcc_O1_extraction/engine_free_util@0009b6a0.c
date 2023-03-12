
undefined4 engine_free_util(void *param_1,int param_2)

{
  int iVar1;
  
  if (param_1 == (void *)0x0) {
    ERR_put_error(0x26,0x6c,0x43,"eng_lib.c",0x70);
    return 0;
  }
  if (param_2 == 0) {
    iVar1 = *(int *)((int)param_1 + 0x58) + -1;
    *(int *)((int)param_1 + 0x58) = iVar1;
    if (0 < iVar1) {
      return 1;
    }
  }
  else {
    iVar1 = CRYPTO_add_lock((int *)((int)param_1 + 0x58),-1,0x1e,"eng_lib.c",0x74);
    if (0 < iVar1) {
      return 1;
    }
  }
  engine_pkey_meths_free(param_1);
  engine_pkey_asn1_meths_free(param_1);
  if (*(code **)((int)param_1 + 0x34) != (code *)0x0) {
    (**(code **)((int)param_1 + 0x34))(param_1);
  }
  CRYPTO_free_ex_data(9,param_1,(CRYPTO_EX_DATA *)((int)param_1 + 0x60));
  CRYPTO_free(param_1);
  return 1;
}

