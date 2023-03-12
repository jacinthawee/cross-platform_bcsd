
int CMAC_CTX_copy(CMAC_CTX *out,CMAC_CTX *in)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(in + 0x10c) == -1) {
    return 0;
  }
  iVar1 = (*(code *)PTR_EVP_CIPHER_CTX_copy_006a8b0c)();
  if (iVar1 == 0) {
    return 0;
  }
  uVar2 = (*(code *)PTR_EVP_CIPHER_CTX_block_size_006a922c)(in);
  (*(code *)PTR_memcpy_006a9aec)(out + 0x8c,in + 0x8c,uVar2);
  (*(code *)PTR_memcpy_006a9aec)(out + 0xac,in + 0xac,uVar2);
  (*(code *)PTR_memcpy_006a9aec)(out + 0xcc,in + 0xcc,uVar2);
  (*(code *)PTR_memcpy_006a9aec)(out + 0xec,in + 0xec,uVar2);
  *(undefined4 *)(out + 0x10c) = *(undefined4 *)(in + 0x10c);
  return 1;
}

