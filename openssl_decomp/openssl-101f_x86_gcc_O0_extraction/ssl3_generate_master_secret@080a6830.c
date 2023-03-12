
int ssl3_generate_master_secret(int param_1,uchar *param_2,void *param_3,size_t param_4)

{
  char *__s;
  size_t cnt;
  char **ppcVar1;
  int in_GS_OFFSET;
  uchar *local_88;
  int local_80;
  size_t local_7c;
  EVP_MD_CTX local_78;
  uchar local_60 [64];
  int local_20;
  
  local_88 = param_2;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  EVP_MD_CTX_init(&local_78);
  local_80 = 0;
  ppcVar1 = (char **)salt_15921;
  while( true ) {
    EVP_DigestInit_ex(&local_78,*(EVP_MD **)(*(int *)(param_1 + 0xe4) + 0x90),(ENGINE *)0x0);
    __s = *ppcVar1;
    cnt = strlen(__s);
    EVP_DigestUpdate(&local_78,__s,cnt);
    EVP_DigestUpdate(&local_78,param_3,param_4);
    EVP_DigestUpdate(&local_78,(void *)(*(int *)(param_1 + 0x58) + 0xc0),0x20);
    EVP_DigestUpdate(&local_78,(void *)(*(int *)(param_1 + 0x58) + 0xa0),0x20);
    EVP_DigestFinal_ex(&local_78,local_60,&local_7c);
    EVP_DigestInit_ex(&local_78,*(EVP_MD **)(*(int *)(param_1 + 0xe4) + 0x8c),(ENGINE *)0x0);
    EVP_DigestUpdate(&local_78,param_3,param_4);
    EVP_DigestUpdate(&local_78,local_60,local_7c);
    EVP_DigestFinal_ex(&local_78,local_88,&local_7c);
    local_80 = local_80 + local_7c;
    if (ppcVar1 + 1 == (char **)"s3_pkt.c") break;
    local_88 = local_88 + local_7c;
    ppcVar1 = ppcVar1 + 1;
  }
  EVP_MD_CTX_cleanup(&local_78);
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return local_80;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

