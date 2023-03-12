
undefined4 dtls1_enc(int param_1,EVP_MD *param_2)

{
  EVP_MD *pEVar1;
  EVP_CIPHER_CTX *pEVar2;
  EVP_MD *pEVar3;
  undefined4 uVar4;
  int iVar5;
  int extraout_r1;
  int extraout_r1_00;
  int iVar6;
  uint uVar7;
  int iVar8;
  EVP_CIPHER_CTX *ctx;
  int iVar9;
  uint inl;
  uint inl_00;
  uchar *buf;
  
  if (param_2 == (EVP_MD *)0x0) {
    pEVar3 = EVP_MD_CTX_md(*(EVP_MD_CTX **)(param_1 + 0x84));
    pEVar1 = param_2;
    if (pEVar3 != (EVP_MD *)0x0) {
      pEVar1 = EVP_MD_CTX_md(*(EVP_MD_CTX **)(param_1 + 0x84));
      pEVar1 = (EVP_MD *)EVP_MD_size(pEVar1);
      if ((int)pEVar1 < 0) {
        OpenSSLDie("d1_enc.c",0xb0,"mac_size >= 0");
      }
    }
    ctx = *(EVP_CIPHER_CTX **)(param_1 + 0x80);
    iVar8 = *(int *)(param_1 + 0x58) + 0x10c;
    pEVar2 = ctx;
    if (ctx != (EVP_CIPHER_CTX *)0x0) {
      pEVar2 = (EVP_CIPHER_CTX *)EVP_CIPHER_CTX_cipher(ctx);
    }
  }
  else {
    pEVar1 = EVP_MD_CTX_md(*(EVP_MD_CTX **)(param_1 + 0x90));
    if (pEVar1 != (EVP_MD *)0x0) {
      pEVar1 = EVP_MD_CTX_md(*(EVP_MD_CTX **)(param_1 + 0x90));
      pEVar1 = (EVP_MD *)EVP_MD_size(pEVar1);
      if ((int)pEVar1 < 0) {
        return 0xffffffff;
      }
    }
    ctx = *(EVP_CIPHER_CTX **)(param_1 + 0x8c);
    iVar9 = *(int *)(param_1 + 0x58);
    iVar8 = iVar9 + 0x130;
    pEVar2 = ctx;
    if (ctx != (EVP_CIPHER_CTX *)0x0) {
      pEVar2 = (EVP_CIPHER_CTX *)EVP_CIPHER_CTX_cipher(ctx);
      if (*(int *)(iVar9 + 0x13c) == *(int *)(iVar9 + 0x140)) {
        iVar5 = EVP_CIPHER_block_size(ctx->cipher);
        if (1 < iVar5) {
          buf = *(uchar **)(iVar9 + 0x140);
          iVar9 = EVP_CIPHER_block_size(ctx->cipher);
          iVar9 = RAND_bytes(buf,iVar9);
          if (iVar9 < 1) {
            return 0xffffffff;
          }
        }
      }
      else {
        __fprintf_chk(stderr,1,"%s:%d: rec->data != rec->input\n","d1_enc.c",0xa3);
      }
    }
  }
  if ((*(int *)(param_1 + 0xc0) == 0) ||
     (pEVar2 == (EVP_CIPHER_CTX *)0x0 || ctx == (EVP_CIPHER_CTX *)0x0)) {
    memmove(*(void **)(iVar8 + 0xc),*(void **)(iVar8 + 0x10),*(size_t *)(iVar8 + 4));
    *(undefined4 *)(iVar8 + 0x10) = *(undefined4 *)(iVar8 + 0xc);
    return 1;
  }
  inl = *(uint *)(iVar8 + 4);
  iVar9 = EVP_CIPHER_block_size(ctx->cipher);
  uVar7 = iVar9 - 1;
  if (uVar7 != 0) {
    uVar7 = 1;
  }
  if (param_2 == (EVP_MD *)0x0 || iVar9 == 1) {
    if (param_2 != (EVP_MD *)0x0) {
      EVP_Cipher(ctx,*(uchar **)(iVar8 + 0xc),*(uchar **)(iVar8 + 0x10),inl);
      return 1;
    }
    if ((inl == 0) || (__aeabi_uidivmod(inl,iVar9), inl_00 = inl, extraout_r1 != 0)) {
      return 0;
    }
  }
  else {
    __aeabi_idivmod(inl,iVar9);
    iVar6 = iVar9 - extraout_r1_00;
    iVar5 = iVar6 + -1;
    if ((*(int *)(param_1 + 0x100) << 0x16 < 0) && ((**(uint **)(param_1 + 0x58) & 8) != 0)) {
      iVar5 = iVar6;
    }
    inl_00 = inl + iVar6;
    if ((int)inl < (int)inl_00) {
      do {
        *(char *)(*(int *)(iVar8 + 0x10) + inl) = (char)iVar5;
        inl = inl + 1;
      } while (inl != inl_00);
    }
    *(int *)(iVar8 + 4) = iVar6 + *(int *)(iVar8 + 4);
  }
  EVP_Cipher(ctx,*(uchar **)(iVar8 + 0xc),*(uchar **)(iVar8 + 0x10),inl_00);
  if (param_2 == (EVP_MD *)0x0) {
    uVar7 = uVar7 & 1;
  }
  else {
    uVar7 = 0;
  }
  if (uVar7 != 0) {
    uVar4 = tls1_cbc_remove_padding(param_1,iVar8,iVar9,pEVar1);
    return uVar4;
  }
  return 1;
}

