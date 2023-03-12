
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

BN_CTX * BN_CTX_new(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x2c,"bn_ctx.c",0xd8);
  if (puVar1 == (undefined4 *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(3,0x6a,0x41,"bn_ctx.c",0xdb);
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1[2] = 0;
    puVar1[1] = 0;
    *puVar1 = 0;
    puVar1[4] = 0;
    puVar1[3] = 0;
    puVar1[5] = 0;
    puVar1[7] = 0;
    puVar1[6] = 0;
    puVar1[8] = 0;
    puVar1[9] = 0;
    puVar1[10] = 0;
  }
  return (BN_CTX *)puVar1;
}

