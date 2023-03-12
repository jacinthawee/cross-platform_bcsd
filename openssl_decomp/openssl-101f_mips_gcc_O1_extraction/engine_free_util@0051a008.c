
undefined4 engine_free_util(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    ERR_put_error(0x26,0x6c,0x43,"eng_lib.c",0x70);
    uVar2 = 0;
  }
  else {
    if (param_2 == 0) {
      iVar1 = *(int *)(param_1 + 0x58) + -1;
      *(int *)(param_1 + 0x58) = iVar1;
    }
    else {
      iVar1 = (*(code *)PTR_CRYPTO_add_lock_006a9080)
                        (param_1 + 0x58,0xffffffff,0x1e,"eng_lib.c",0x74);
    }
    if (iVar1 < 1) {
      engine_pkey_meths_free(param_1);
      engine_pkey_asn1_meths_free(param_1);
      if (*(code **)(param_1 + 0x34) != (code *)0x0) {
        (**(code **)(param_1 + 0x34))(param_1);
      }
      (*(code *)PTR_CRYPTO_free_ex_data_006a9414)(9,param_1,param_1 + 0x60);
      (*(code *)PTR_CRYPTO_free_006a7f88)(param_1);
      return 1;
    }
    uVar2 = 1;
  }
  return uVar2;
}

