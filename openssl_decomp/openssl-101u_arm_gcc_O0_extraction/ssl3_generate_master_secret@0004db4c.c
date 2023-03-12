
void ssl3_generate_master_secret(int param_1,uchar *param_2,void *param_3,size_t param_4)

{
  int iVar1;
  size_t cnt;
  char **ppcVar2;
  int iVar3;
  char *__s;
  size_t local_88;
  EVP_MD_CTX EStack_84;
  uchar auStack_6c [64];
  int local_2c;
  
  local_2c = __stack_chk_guard;
  EVP_MD_CTX_init(&EStack_84);
  iVar3 = 0;
  ppcVar2 = (char **)PTR_s_84_0004dc68;
  do {
    iVar1 = EVP_DigestInit_ex(&EStack_84,*(EVP_MD **)(*(int *)(param_1 + 0xe4) + 0x90),(ENGINE *)0x0
                             );
    if (iVar1 < 1) {
LAB_0004dc44:
      iVar3 = 0;
      ERR_put_error(0x14,0x184,0x44,"s3_enc.c",0x356);
      break;
    }
    ppcVar2 = ppcVar2 + 1;
    __s = *ppcVar2;
    cnt = strlen(__s);
    iVar1 = EVP_DigestUpdate(&EStack_84,__s,cnt);
    if ((((((iVar1 < 1) || (iVar1 = EVP_DigestUpdate(&EStack_84,param_3,param_4), iVar1 < 1)) ||
          (iVar1 = EVP_DigestUpdate(&EStack_84,(void *)(*(int *)(param_1 + 0x58) + 0xc0),0x20),
          iVar1 < 1)) ||
         ((iVar1 = EVP_DigestUpdate(&EStack_84,(void *)(*(int *)(param_1 + 0x58) + 0xa0),0x20),
          iVar1 < 1 || (iVar1 = EVP_DigestFinal_ex(&EStack_84,auStack_6c,&local_88), iVar1 < 1))))
        || ((iVar1 = EVP_DigestInit_ex(&EStack_84,*(EVP_MD **)(*(int *)(param_1 + 0xe4) + 0x8c),
                                       (ENGINE *)0x0), iVar1 < 1 ||
            ((iVar1 = EVP_DigestUpdate(&EStack_84,param_3,param_4), iVar1 < 1 ||
             (iVar1 = EVP_DigestUpdate(&EStack_84,auStack_6c,local_88), iVar1 < 1)))))) ||
       (iVar1 = EVP_DigestFinal_ex(&EStack_84,param_2,&local_88), iVar1 < 1)) goto LAB_0004dc44;
    param_2 = param_2 + local_88;
    iVar3 = iVar3 + local_88;
  } while (ppcVar2 != (char **)PTR_PTR_DAT_0004dc6c);
  EVP_MD_CTX_cleanup(&EStack_84);
  OPENSSL_cleanse(auStack_6c,0x40);
  if (local_2c == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(iVar3);
}

