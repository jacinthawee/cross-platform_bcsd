
void ssl3_generate_master_secret(int param_1,uchar *param_2,void *param_3,size_t param_4)

{
  size_t cnt;
  char **ppcVar1;
  char *__s;
  int iVar2;
  size_t local_88;
  EVP_MD_CTX EStack_84;
  uchar auStack_6c [64];
  int local_2c;
  
  local_2c = __TMC_END__;
  EVP_MD_CTX_init(&EStack_84);
  iVar2 = 0;
  ppcVar1 = (char **)PTR_s_84_00050754;
  do {
    EVP_DigestInit_ex(&EStack_84,*(EVP_MD **)(*(int *)(param_1 + 0xe4) + 0x90),(ENGINE *)0x0);
    ppcVar1 = ppcVar1 + 1;
    __s = *ppcVar1;
    cnt = strlen(__s);
    EVP_DigestUpdate(&EStack_84,__s,cnt);
    EVP_DigestUpdate(&EStack_84,param_3,param_4);
    EVP_DigestUpdate(&EStack_84,(void *)(*(int *)(param_1 + 0x58) + 0xc0),0x20);
    EVP_DigestUpdate(&EStack_84,(void *)(*(int *)(param_1 + 0x58) + 0xa0),0x20);
    EVP_DigestFinal_ex(&EStack_84,auStack_6c,&local_88);
    EVP_DigestInit_ex(&EStack_84,*(EVP_MD **)(*(int *)(param_1 + 0xe4) + 0x8c),(ENGINE *)0x0);
    EVP_DigestUpdate(&EStack_84,param_3,param_4);
    EVP_DigestUpdate(&EStack_84,auStack_6c,local_88);
    EVP_DigestFinal_ex(&EStack_84,param_2,&local_88);
    param_2 = param_2 + local_88;
    iVar2 = iVar2 + local_88;
  } while (ppcVar1 != (char **)PTR_PTR_DAT_00050758);
  EVP_MD_CTX_cleanup(&EStack_84);
  if (local_2c == __TMC_END__) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(iVar2);
}

