
int CMAC_Update(CMAC_CTX *ctx,void *data,size_t dlen)

{
  uint inl;
  int iVar1;
  uint uVar2;
  
  if (*(int *)(ctx + 0x10c) == -1) {
    return 0;
  }
  if (dlen != 0) {
    inl = EVP_CIPHER_CTX_block_size((EVP_CIPHER_CTX *)ctx);
    iVar1 = *(int *)(ctx + 0x10c);
    if (0 < iVar1) {
      uVar2 = inl - iVar1;
      if (dlen <= inl - iVar1) {
        uVar2 = dlen;
      }
      memcpy(ctx + 0xec + iVar1,data,uVar2);
      *(uint *)(ctx + 0x10c) = *(int *)(ctx + 0x10c) + uVar2;
      dlen = dlen - uVar2;
      if (dlen == 0) {
        return 1;
      }
      iVar1 = EVP_Cipher((EVP_CIPHER_CTX *)ctx,(uchar *)(ctx + 0xcc),(uchar *)(ctx + 0xec),inl);
      if (iVar1 == 0) {
        return 0;
      }
      data = (void *)((int)data + uVar2);
    }
    if (inl < dlen) {
      uVar2 = dlen - inl;
      do {
        dlen = uVar2;
        iVar1 = EVP_Cipher((EVP_CIPHER_CTX *)ctx,(uchar *)(ctx + 0xcc),(uchar *)data,inl);
        if (iVar1 == 0) {
          return 0;
        }
        data = (void *)((int)data + inl);
        uVar2 = dlen - inl;
      } while (inl < dlen);
    }
    memcpy(ctx + 0xec,data,dlen);
    *(size_t *)(ctx + 0x10c) = dlen;
  }
  return 1;
}

