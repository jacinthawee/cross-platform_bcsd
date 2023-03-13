
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EVP_CIPHER_CTX * EVP_CIPHER_CTX_new(void)

{
  EVP_CIPHER_CTX *pEVar1;
  uint uVar2;
  undefined4 *puVar3;
  byte bVar4;
  
  bVar4 = 0;
  pEVar1 = (EVP_CIPHER_CTX *)CRYPTO_malloc(0x8c,"evp_enc.c",0x58);
  if (pEVar1 != (EVP_CIPHER_CTX *)0x0) {
    pEVar1->cipher = (EVP_CIPHER *)0x0;
    *(undefined4 *)(pEVar1->final + 0x1c) = 0;
    puVar3 = (undefined4 *)((uint)&pEVar1->engine & 0xfffffffc);
    uVar2 = (uint)((int)pEVar1 + (0x8c - (int)puVar3)) >> 2;
    for (; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar3 = 0;
      puVar3 = puVar3 + (uint)bVar4 * -2 + 1;
    }
  }
  return pEVar1;
}

