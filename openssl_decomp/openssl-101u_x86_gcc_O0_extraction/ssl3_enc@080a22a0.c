
undefined4 ssl3_enc(int param_1,int param_2)

{
  int iVar1;
  EVP_CIPHER_CTX *ctx;
  EVP_CIPHER *pEVar2;
  uint uVar3;
  int iVar4;
  EVP_MD *pEVar5;
  undefined4 uVar6;
  size_t __n;
  uint inl;
  
  if (param_2 == 0) {
    ctx = *(EVP_CIPHER_CTX **)(param_1 + 0x80);
    iVar1 = *(int *)(param_1 + 0x58) + 0x10c;
  }
  else {
    ctx = *(EVP_CIPHER_CTX **)(param_1 + 0x8c);
    iVar1 = *(int *)(param_1 + 0x58) + 0x130;
  }
  if (((ctx == (EVP_CIPHER_CTX *)0x0) ||
      (pEVar2 = EVP_CIPHER_CTX_cipher(ctx), *(int *)(param_1 + 0xc0) == 0)) ||
     (pEVar2 == (EVP_CIPHER *)0x0)) {
    memmove(*(void **)(iVar1 + 0xc),*(void **)(iVar1 + 0x10),*(size_t *)(iVar1 + 4));
    *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)(iVar1 + 0xc);
    uVar6 = 1;
  }
  else {
    inl = *(uint *)(iVar1 + 4);
    uVar3 = EVP_CIPHER_block_size(ctx->cipher);
    if ((param_2 == 0) || (uVar3 == 1)) {
      if (param_2 == 0) {
        if (inl == 0) {
          return 0;
        }
        if (inl % uVar3 != 0) {
          return 0;
        }
      }
    }
    else {
      __n = uVar3 - (int)inl % (int)uVar3;
      inl = inl + __n;
      memset((void *)(*(int *)(iVar1 + 4) + *(int *)(iVar1 + 0x10)),0,__n);
      *(int *)(iVar1 + 4) = *(int *)(iVar1 + 4) + __n;
      *(char *)(*(int *)(iVar1 + 0x10) + -1 + inl) = (char)__n + -1;
    }
    iVar4 = EVP_Cipher(ctx,*(uchar **)(iVar1 + 0xc),*(uchar **)(iVar1 + 0x10),inl);
    if (iVar4 < 1) {
      uVar6 = 0xffffffff;
    }
    else {
      pEVar5 = EVP_MD_CTX_md(*(EVP_MD_CTX **)(param_1 + 0x84));
      iVar4 = 0;
      if (pEVar5 != (EVP_MD *)0x0) {
        pEVar5 = EVP_MD_CTX_md(*(EVP_MD_CTX **)(param_1 + 0x84));
        iVar4 = EVP_MD_size(pEVar5);
      }
      if ((param_2 != 0) || (uVar3 == 1)) {
        return 1;
      }
      uVar6 = ssl3_cbc_remove_padding(param_1,iVar1,uVar3,iVar4);
    }
  }
  return uVar6;
}

