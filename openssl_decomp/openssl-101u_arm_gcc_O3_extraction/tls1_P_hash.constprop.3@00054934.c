
void tls1_P_hash_constprop_3
               (EVP_MD *param_1,uchar *param_2,int param_3,void *param_4,size_t param_5,
               void *param_6,size_t param_7,void *param_8,size_t param_9,void *param_10,
               size_t param_11,uchar *param_12,size_t param_13)

{
  int iVar1;
  EVP_PKEY *pkey;
  int iVar2;
  undefined4 uVar3;
  size_t local_a4;
  size_t local_a0;
  EVP_MD_CTX EStack_9c;
  EVP_MD_CTX EStack_84;
  uchar auStack_6c [64];
  int local_2c;
  
  local_2c = __stack_chk_guard;
  iVar1 = EVP_MD_size(param_1);
  if (iVar1 < 0) {
    OpenSSLDie("t1_enc.c",0xaa,"chunk >= 0");
  }
  EVP_MD_CTX_init(&EStack_9c);
  EVP_MD_CTX_init(&EStack_84);
  EVP_MD_CTX_set_flags(&EStack_9c,8);
  EVP_MD_CTX_set_flags(&EStack_84,8);
  pkey = EVP_PKEY_new_mac_key(0x357,(ENGINE *)0x0,param_2,param_3);
  if ((((((pkey != (EVP_PKEY *)0x0) &&
         (iVar2 = EVP_DigestSignInit(&EStack_9c,(EVP_PKEY_CTX **)0x0,param_1,(ENGINE *)0x0,pkey),
         iVar2 != 0)) &&
        (iVar2 = EVP_DigestSignInit(&EStack_84,(EVP_PKEY_CTX **)0x0,param_1,(ENGINE *)0x0,pkey),
        iVar2 != 0)) &&
       ((param_4 == (void *)0x0 ||
        (iVar2 = EVP_DigestUpdate(&EStack_9c,param_4,param_5), iVar2 != 0)))) &&
      (((param_6 == (void *)0x0 ||
        (iVar2 = EVP_DigestUpdate(&EStack_9c,param_6,param_7), iVar2 != 0)) &&
       ((param_8 == (void *)0x0 ||
        (iVar2 = EVP_DigestUpdate(&EStack_9c,param_8,param_9), iVar2 != 0)))))) &&
     ((param_10 == (void *)0x0 ||
      (iVar2 = EVP_DigestUpdate(&EStack_9c,param_10,param_11), iVar2 != 0)))) {
    iVar2 = EVP_DigestSignFinal(&EStack_9c,auStack_6c,&local_a0);
    while( true ) {
      if (((((iVar2 == 0) ||
            (iVar2 = EVP_DigestSignInit(&EStack_9c,(EVP_PKEY_CTX **)0x0,param_1,(ENGINE *)0x0,pkey),
            iVar2 == 0)) ||
           (iVar2 = EVP_DigestSignInit(&EStack_84,(EVP_PKEY_CTX **)0x0,param_1,(ENGINE *)0x0,pkey),
           iVar2 == 0)) ||
          (((iVar2 = EVP_DigestUpdate(&EStack_9c,auStack_6c,local_a0), iVar2 == 0 ||
            (iVar2 = EVP_DigestUpdate(&EStack_84,auStack_6c,local_a0), iVar2 == 0)) ||
           ((param_4 != (void *)0x0 &&
            (iVar2 = EVP_DigestUpdate(&EStack_9c,param_4,param_5), iVar2 == 0)))))) ||
         ((((param_6 != (void *)0x0 &&
            (iVar2 = EVP_DigestUpdate(&EStack_9c,param_6,param_7), iVar2 == 0)) ||
           ((param_8 != (void *)0x0 &&
            (iVar2 = EVP_DigestUpdate(&EStack_9c,param_8,param_9), iVar2 == 0)))) ||
          ((param_10 != (void *)0x0 &&
           (iVar2 = EVP_DigestUpdate(&EStack_9c,param_10,param_11), iVar2 == 0))))))
      goto LAB_000549aa;
      if ((int)param_13 <= iVar1) break;
      iVar2 = EVP_DigestSignFinal(&EStack_9c,param_12,&local_a4);
      if (iVar2 == 0) goto LAB_000549aa;
      param_12 = param_12 + local_a4;
      param_13 = param_13 - local_a4;
      iVar2 = EVP_DigestSignFinal(&EStack_84,auStack_6c,&local_a0);
    }
    iVar1 = EVP_DigestSignFinal(&EStack_9c,auStack_6c,&local_a0);
    if (iVar1 != 0) {
      uVar3 = 1;
      memcpy(param_12,auStack_6c,param_13);
      goto LAB_000549ac;
    }
  }
LAB_000549aa:
  uVar3 = 0;
LAB_000549ac:
  EVP_PKEY_free(pkey);
  EVP_MD_CTX_cleanup(&EStack_9c);
  EVP_MD_CTX_cleanup(&EStack_84);
  OPENSSL_cleanse(auStack_6c,0x40);
  if (local_2c == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar3);
}

