
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ASN1_PCTX * ASN1_PCTX_new(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x14,"tasn_prn.c",0x57);
  if (puVar1 == (undefined4 *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xcd,0x41,"tasn_prn.c",0x59);
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar1[4] = 0;
  }
  return (ASN1_PCTX *)puVar1;
}

