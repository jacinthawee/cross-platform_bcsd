
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EVP_MD_CTX * EVP_MD_CTX_create(void)

{
  EVP_MD_CTX *pEVar1;
  uint uVar2;
  uint uVar3;
  
  pEVar1 = (EVP_MD_CTX *)CRYPTO_malloc(0x18,"digest.c",0x83);
  if (pEVar1 != (EVP_MD_CTX *)0x0) {
    pEVar1->digest = (EVP_MD *)0x0;
    pEVar1->update = (_func_1088 *)0x0;
    uVar2 = 0;
    uVar3 = (uint)&pEVar1->engine & 0xfffffffc;
    do {
      *(undefined4 *)(uVar3 + uVar2) = 0;
      uVar2 = uVar2 + 4;
    } while (uVar2 < ((int)pEVar1 + (0x18 - uVar3) & 0xfffffffc));
  }
  return pEVar1;
}

