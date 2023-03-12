
undefined4 * sig_cb(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)0x1;
  if (param_1 == 0) {
    puVar1 = (undefined4 *)CRYPTO_malloc(8,"dsa_asn1.c",0x48);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = 0;
      puVar1[1] = 0;
      *param_2 = puVar1;
      return (undefined4 *)0x2;
    }
    ERR_put_error(10,0x72,0x41,"dsa_asn1.c",0x4b);
  }
  return puVar1;
}

