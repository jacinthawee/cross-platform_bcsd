
undefined4 md_gets(int param_1,uchar *param_2,int param_3)

{
  int iVar1;
  uint local_c [3];
  
  if ((*(EVP_MD_CTX **)(param_1 + 0x20))->digest->md_size <= param_3) {
    iVar1 = EVP_DigestFinal_ex(*(EVP_MD_CTX **)(param_1 + 0x20),param_2,local_c);
    if (iVar1 < 1) {
      local_c[0] = 0xffffffff;
    }
    return local_c[0];
  }
  return 0;
}

