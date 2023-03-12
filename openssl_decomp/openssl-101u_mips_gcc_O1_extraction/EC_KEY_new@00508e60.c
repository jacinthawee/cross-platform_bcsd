
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EC_KEY * EC_KEY_new(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x24,"ec_key.c",0x4b);
  if (puVar1 == (undefined4 *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xb6,0x41,"ec_key.c",0x4d);
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1[7] = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
    *puVar1 = 1;
    puVar1[3] = 0;
    puVar1[4] = 0;
    puVar1[5] = 4;
    puVar1[6] = 1;
    puVar1[8] = 0;
  }
  return (EC_KEY *)puVar1;
}

