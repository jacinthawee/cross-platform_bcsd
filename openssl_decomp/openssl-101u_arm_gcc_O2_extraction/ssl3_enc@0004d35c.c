
undefined4 ssl3_enc(int param_1,int param_2)

{
  EVP_CIPHER_CTX *pEVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  EVP_MD *pEVar5;
  int extraout_r1;
  int extraout_r1_00;
  size_t __n;
  int iVar6;
  EVP_CIPHER_CTX *ctx;
  uint inl;
  uint uVar7;
  
  if (param_2 == 0) {
    ctx = *(EVP_CIPHER_CTX **)(param_1 + 0x80);
    iVar6 = *(int *)(param_1 + 0x58) + 0x10c;
  }
  else {
    ctx = *(EVP_CIPHER_CTX **)(param_1 + 0x8c);
    iVar6 = *(int *)(param_1 + 0x58) + 0x130;
  }
  pEVar1 = ctx;
  if (ctx != (EVP_CIPHER_CTX *)0x0) {
    pEVar1 = (EVP_CIPHER_CTX *)EVP_CIPHER_CTX_cipher(ctx);
  }
  if ((*(int *)(param_1 + 0xc0) == 0) ||
     (pEVar1 == (EVP_CIPHER_CTX *)0x0 || ctx == (EVP_CIPHER_CTX *)0x0)) {
    memmove(*(void **)(iVar6 + 0xc),*(void **)(iVar6 + 0x10),*(size_t *)(iVar6 + 4));
    uVar2 = 1;
    *(undefined4 *)(iVar6 + 0x10) = *(undefined4 *)(iVar6 + 0xc);
  }
  else {
    inl = *(uint *)(iVar6 + 4);
    iVar3 = EVP_CIPHER_block_size(ctx->cipher);
    uVar7 = iVar3 - 1;
    if (uVar7 != 0) {
      uVar7 = 1;
    }
    if (param_2 == 0 || iVar3 == 1) {
      if ((param_2 == 0) && ((inl == 0 || (__aeabi_uidivmod(inl,iVar3), extraout_r1 != 0)))) {
        return 0;
      }
    }
    else {
      __aeabi_idivmod(inl,iVar3);
      __n = iVar3 - extraout_r1_00;
      inl = inl + __n;
      memset((void *)(*(int *)(iVar6 + 4) + *(int *)(iVar6 + 0x10)),
             (uint)(pEVar1 == (EVP_CIPHER_CTX *)0x0 || ctx == (EVP_CIPHER_CTX *)0x0),__n);
      *(size_t *)(iVar6 + 4) = __n + *(int *)(iVar6 + 4);
      *(char *)(*(int *)(iVar6 + 0x10) + inl + -1) = (char)__n + -1;
    }
    iVar4 = EVP_Cipher(ctx,*(uchar **)(iVar6 + 0xc),*(uchar **)(iVar6 + 0x10),inl);
    if (iVar4 < 1) {
      uVar2 = 0xffffffff;
    }
    else {
      pEVar5 = EVP_MD_CTX_md(*(EVP_MD_CTX **)(param_1 + 0x84));
      if (pEVar5 != (EVP_MD *)0x0) {
        pEVar5 = EVP_MD_CTX_md(*(EVP_MD_CTX **)(param_1 + 0x84));
        pEVar5 = (EVP_MD *)EVP_MD_size(pEVar5);
      }
      if (param_2 == 0) {
        uVar7 = uVar7 & 1;
      }
      else {
        uVar7 = 0;
      }
      uVar2 = 1;
      if (uVar7 != 0) {
        uVar2 = ssl3_cbc_remove_padding(param_1,iVar6,iVar3,pEVar5);
        return uVar2;
      }
    }
  }
  return uVar2;
}

