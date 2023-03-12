
undefined4 sig_cb(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (param_1 != 0) {
    return 1;
  }
  puVar1 = (undefined4 *)(*(code *)PTR_CRYPTO_malloc_006a8108)(8,"dsa_asn1.c",0x48);
  if (puVar1 == (undefined4 *)0x0) {
    ERR_put_error(10,0x72,0x41,"dsa_asn1.c",0x4b);
    uVar2 = 0;
  }
  else {
    *puVar1 = 0;
    uVar2 = 2;
    puVar1[1] = 0;
    *param_2 = puVar1;
  }
  return uVar2;
}

