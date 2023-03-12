
undefined4 dtls1_enc(int param_1,int param_2)

{
  EVP_MD *pEVar1;
  EVP_CIPHER *pEVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  uint inl;
  char cVar7;
  int iVar8;
  uint uVar9;
  EVP_CIPHER_CTX *ctx;
  int local_2c;
  
  if (param_2 == 0) {
    pEVar1 = EVP_MD_CTX_md(*(EVP_MD_CTX **)(param_1 + 0x84));
    local_2c = 0;
    if (pEVar1 != (EVP_MD *)0x0) {
      pEVar1 = EVP_MD_CTX_md(*(EVP_MD_CTX **)(param_1 + 0x84));
      local_2c = EVP_MD_size(pEVar1);
      if (local_2c < 0) {
        OpenSSLDie("d1_enc.c",0xb0,"mac_size >= 0");
      }
    }
    ctx = *(EVP_CIPHER_CTX **)(param_1 + 0x80);
    pEVar2 = (EVP_CIPHER *)0x0;
    iVar8 = *(int *)(param_1 + 0x58) + 0x10c;
    if (ctx != (EVP_CIPHER_CTX *)0x0) {
      pEVar2 = EVP_CIPHER_CTX_cipher(ctx);
    }
  }
  else {
    pEVar1 = EVP_MD_CTX_md(*(EVP_MD_CTX **)(param_1 + 0x90));
    if (pEVar1 == (EVP_MD *)0x0) {
      local_2c = 0;
    }
    else {
      pEVar1 = EVP_MD_CTX_md(*(EVP_MD_CTX **)(param_1 + 0x90));
      local_2c = EVP_MD_size(pEVar1);
      if (local_2c < 0) {
        return 0xffffffff;
      }
    }
    ctx = *(EVP_CIPHER_CTX **)(param_1 + 0x8c);
    iVar4 = *(int *)(param_1 + 0x58);
    iVar8 = iVar4 + 0x130;
    if (ctx == (EVP_CIPHER_CTX *)0x0) {
      pEVar2 = (EVP_CIPHER *)0x0;
    }
    else {
      pEVar2 = EVP_CIPHER_CTX_cipher(ctx);
      if (*(int *)(iVar4 + 0x13c) == *(int *)(iVar4 + 0x140)) {
        iVar6 = EVP_CIPHER_block_size(ctx->cipher);
        if (1 < iVar6) {
          iVar6 = EVP_CIPHER_block_size(ctx->cipher);
          iVar4 = RAND_bytes(*(uchar **)(iVar4 + 0x140),iVar6);
          if (iVar4 < 1) {
            return 0xffffffff;
          }
        }
      }
      else {
        __fprintf_chk(stderr,1,"%s:%d: rec->data != rec->input\n",&DAT_081ffa8c,0xa3);
      }
    }
  }
  if (((*(int *)(param_1 + 0xc0) == 0) || (ctx == (EVP_CIPHER_CTX *)0x0)) ||
     (pEVar2 == (EVP_CIPHER *)0x0)) {
    memmove(*(void **)(iVar8 + 0xc),*(void **)(iVar8 + 0x10),*(size_t *)(iVar8 + 4));
    *(undefined4 *)(iVar8 + 0x10) = *(undefined4 *)(iVar8 + 0xc);
    uVar5 = 1;
  }
  else {
    inl = *(uint *)(iVar8 + 4);
    uVar3 = EVP_CIPHER_block_size(ctx->cipher);
    if ((param_2 == 0) || (uVar3 == 1)) {
      if (param_2 != 0) {
        EVP_Cipher(ctx,*(uchar **)(iVar8 + 0xc),*(uchar **)(iVar8 + 0x10),inl);
        return 1;
      }
      if (inl == 0) {
        return 0;
      }
      if (inl % uVar3 != 0) {
        return 0;
      }
    }
    else {
      iVar4 = uVar3 - (int)inl % (int)uVar3;
      cVar7 = (char)iVar4 + -1;
      if (((*(byte *)(param_1 + 0x101) & 2) != 0) && ((**(byte **)(param_1 + 0x58) & 8) != 0)) {
        cVar7 = (char)iVar4;
      }
      uVar9 = inl + iVar4;
      if ((int)inl < (int)uVar9) {
        do {
          *(char *)(*(int *)(iVar8 + 0x10) + inl) = cVar7;
          inl = inl + 1;
        } while (inl != uVar9);
      }
      *(int *)(iVar8 + 4) = *(int *)(iVar8 + 4) + iVar4;
      inl = uVar9;
    }
    EVP_Cipher(ctx,*(uchar **)(iVar8 + 0xc),*(uchar **)(iVar8 + 0x10),inl);
    if ((param_2 != 0) || (uVar3 == 1)) {
      return 1;
    }
    uVar5 = tls1_cbc_remove_padding(param_1,iVar8,uVar3,local_2c);
  }
  return uVar5;
}

