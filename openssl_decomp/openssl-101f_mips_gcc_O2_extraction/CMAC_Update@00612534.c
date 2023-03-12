
int CMAC_Update(CMAC_CTX *ctx,void *data,size_t dlen)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  if (*(int *)(ctx + 0x10c) == -1) {
    return 0;
  }
  if (dlen != 0) {
    uVar1 = (*(code *)PTR_EVP_CIPHER_CTX_block_size_006a90c4)();
    iVar2 = *(int *)(ctx + 0x10c);
    if (0 < iVar2) {
      uVar3 = uVar1 - iVar2;
      if (dlen <= uVar1 - iVar2) {
        uVar3 = dlen;
      }
      (*(code *)PTR_memcpy_006aabf4)(ctx + 0xec + iVar2,data,uVar3);
      dlen = dlen - uVar3;
      *(uint *)(ctx + 0x10c) = *(int *)(ctx + 0x10c) + uVar3;
      if (dlen == 0) {
        return 1;
      }
      iVar2 = (*(code *)PTR_EVP_Cipher_006a90b0)(ctx,ctx + 0xcc,ctx + 0xec,uVar1);
      if (iVar2 == 0) {
        return 0;
      }
      data = (void *)((int)data + uVar3);
    }
    while (uVar1 < dlen) {
      dlen = dlen - uVar1;
      iVar2 = (*(code *)PTR_EVP_Cipher_006a90b0)(ctx,ctx + 0xcc,data,uVar1);
      if (iVar2 == 0) {
        return 0;
      }
      data = (void *)((int)data + uVar1);
    }
    (*(code *)PTR_memcpy_006aabf4)(ctx + 0xec,data,dlen);
    *(size_t *)(ctx + 0x10c) = dlen;
  }
  return 1;
}

