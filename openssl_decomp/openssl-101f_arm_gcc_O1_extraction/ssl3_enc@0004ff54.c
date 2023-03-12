
undefined4 ssl3_enc(int param_1,int param_2)

{
  EVP_CIPHER_CTX *pEVar1;
  int iVar2;
  EVP_MD *pEVar3;
  undefined4 uVar4;
  int extraout_r1;
  int extraout_r1_00;
  size_t __n;
  int iVar5;
  EVP_CIPHER_CTX *ctx;
  uint inl;
  uint uVar6;
  
  if (param_2 == 0) {
    ctx = *(EVP_CIPHER_CTX **)(param_1 + 0x80);
    iVar5 = *(int *)(param_1 + 0x58) + 0x10c;
  }
  else {
    ctx = *(EVP_CIPHER_CTX **)(param_1 + 0x8c);
    iVar5 = *(int *)(param_1 + 0x58) + 0x130;
  }
  pEVar1 = ctx;
  if (ctx != (EVP_CIPHER_CTX *)0x0) {
    pEVar1 = (EVP_CIPHER_CTX *)EVP_CIPHER_CTX_cipher(ctx);
  }
  if ((*(int *)(param_1 + 0xc0) == 0) ||
     (pEVar1 == (EVP_CIPHER_CTX *)0x0 || ctx == (EVP_CIPHER_CTX *)0x0)) {
    memmove(*(void **)(iVar5 + 0xc),*(void **)(iVar5 + 0x10),*(size_t *)(iVar5 + 4));
    *(undefined4 *)(iVar5 + 0x10) = *(undefined4 *)(iVar5 + 0xc);
  }
  else {
    inl = *(uint *)(iVar5 + 4);
    iVar2 = EVP_CIPHER_block_size(ctx->cipher);
    uVar6 = iVar2 - 1;
    if (uVar6 != 0) {
      uVar6 = 1;
    }
    if (param_2 == 0 || iVar2 == 1) {
      if ((param_2 == 0) && ((inl == 0 || (__aeabi_uidivmod(inl,iVar2), extraout_r1 != 0)))) {
        return 0;
      }
    }
    else {
      __aeabi_idivmod(inl,iVar2);
      __n = iVar2 - extraout_r1_00;
      inl = inl + __n;
      memset((void *)(*(int *)(iVar5 + 4) + *(int *)(iVar5 + 0x10)),
             (uint)(pEVar1 == (EVP_CIPHER_CTX *)0x0 || ctx == (EVP_CIPHER_CTX *)0x0),__n);
      *(size_t *)(iVar5 + 4) = __n + *(int *)(iVar5 + 4);
      *(char *)(*(int *)(iVar5 + 0x10) + inl + -1) = (char)__n + -1;
    }
    EVP_Cipher(ctx,*(uchar **)(iVar5 + 0xc),*(uchar **)(iVar5 + 0x10),inl);
    pEVar3 = EVP_MD_CTX_md(*(EVP_MD_CTX **)(param_1 + 0x84));
    if (pEVar3 != (EVP_MD *)0x0) {
      pEVar3 = EVP_MD_CTX_md(*(EVP_MD_CTX **)(param_1 + 0x84));
      pEVar3 = (EVP_MD *)EVP_MD_size(pEVar3);
    }
    if (param_2 == 0) {
      uVar6 = uVar6 & 1;
    }
    else {
      uVar6 = 0;
    }
    if (uVar6 != 0) {
      uVar4 = ssl3_cbc_remove_padding(param_1,iVar5,iVar2,pEVar3);
      return uVar4;
    }
  }
  return 1;
}

