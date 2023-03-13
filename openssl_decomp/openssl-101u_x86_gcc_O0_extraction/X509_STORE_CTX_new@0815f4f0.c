
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

X509_STORE_CTX * X509_STORE_CTX_new(void)

{
  X509_STORE_CTX *pXVar1;
  uint uVar2;
  undefined4 *puVar3;
  byte bVar4;
  
  bVar4 = 0;
  pXVar1 = (X509_STORE_CTX *)CRYPTO_malloc(0x88,"x509_vfy.c",0x83d);
  if (pXVar1 == (X509_STORE_CTX *)0x0) {
    ERR_put_error(0xb,0x8e,0x41,"x509_vfy.c",0x83f);
    pXVar1 = (X509_STORE_CTX *)0x0;
  }
  else {
    pXVar1->ctx = (X509_STORE *)0x0;
    (pXVar1->ex_data).dummy = 0;
    puVar3 = (undefined4 *)((uint)&pXVar1->current_method & 0xfffffffc);
    uVar2 = (uint)((int)pXVar1 + (0x88 - (int)puVar3)) >> 2;
    for (; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar3 = 0;
      puVar3 = puVar3 + (uint)bVar4 * -2 + 1;
    }
  }
  return pXVar1;
}

