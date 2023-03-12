
int ENGINE_free(ENGINE *e)

{
  int iVar1;
  
  if (e == (ENGINE *)0x0) {
    ERR_put_error(0x26,0x6c,0x43,"eng_lib.c",0x70);
  }
  else {
    iVar1 = CRYPTO_add_lock((int *)(e + 0x58),-1,0x1e,"eng_lib.c",0x74);
    if (iVar1 < 1) {
      engine_pkey_meths_free(e);
      engine_pkey_asn1_meths_free(e);
      if (*(code **)(e + 0x34) != (code *)0x0) {
        (**(code **)(e + 0x34))(e);
      }
      CRYPTO_free_ex_data(9,e,(CRYPTO_EX_DATA *)(e + 0x60));
      CRYPTO_free(e);
      return 1;
    }
    e = (ENGINE *)0x1;
  }
  return (int)e;
}

