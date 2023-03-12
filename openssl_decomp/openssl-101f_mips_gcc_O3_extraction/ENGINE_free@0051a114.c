
int ENGINE_free(ENGINE *e)

{
  int iVar1;
  
  if (e == (ENGINE *)0x0) {
    ERR_put_error(0x26,0x6c,0x43,"eng_lib.c",0x70);
    iVar1 = 0;
  }
  else {
    iVar1 = (*(code *)PTR_CRYPTO_add_lock_006a9080)(e + 0x58,0xffffffff,0x1e,"eng_lib.c",0x74);
    if (iVar1 < 1) {
      engine_pkey_meths_free(e);
      engine_pkey_asn1_meths_free(e);
      if (*(code **)(e + 0x34) != (code *)0x0) {
        (**(code **)(e + 0x34))(e);
      }
      (*(code *)PTR_CRYPTO_free_ex_data_006a9414)(9,e,e + 0x60);
      (*(code *)PTR_CRYPTO_free_006a7f88)(e);
      return 1;
    }
    iVar1 = 1;
  }
  return iVar1;
}

