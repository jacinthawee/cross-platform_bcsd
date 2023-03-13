
undefined4 __regparm3
tls1_P_hash_constprop_2
          (EVP_MD *param_1_00,uchar *param_2_00,int param_3_00,void *param_1,size_t param_2,
          void *param_3,size_t param_4,void *param_5,size_t param_6,void *param_7,size_t param_8,
          uchar *param_9,size_t param_10)

{
  int iVar1;
  EVP_PKEY *pkey;
  int iVar2;
  int in_GS_OFFSET;
  undefined4 local_b8;
  size_t local_98;
  size_t local_94;
  EVP_MD_CTX local_90;
  EVP_MD_CTX local_78;
  uchar local_60 [64];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = EVP_MD_size(param_1_00);
  if (iVar1 < 0) {
    OpenSSLDie("t1_enc.c",0xaa,"chunk >= 0");
  }
  EVP_MD_CTX_init(&local_90);
  EVP_MD_CTX_init(&local_78);
  EVP_MD_CTX_set_flags(&local_90,8);
  EVP_MD_CTX_set_flags(&local_78,8);
  pkey = EVP_PKEY_new_mac_key(0x357,(ENGINE *)0x0,param_2_00,param_3_00);
  if ((((((pkey != (EVP_PKEY *)0x0) &&
         (iVar2 = EVP_DigestSignInit(&local_90,(EVP_PKEY_CTX **)0x0,param_1_00,(ENGINE *)0x0,pkey),
         iVar2 != 0)) &&
        (iVar2 = EVP_DigestSignInit(&local_78,(EVP_PKEY_CTX **)0x0,param_1_00,(ENGINE *)0x0,pkey),
        iVar2 != 0)) &&
       ((param_1 == (void *)0x0 || (iVar2 = EVP_DigestUpdate(&local_90,param_1,param_2), iVar2 != 0)
        ))) && (((param_3 == (void *)0x0 ||
                 (iVar2 = EVP_DigestUpdate(&local_90,param_3,param_4), iVar2 != 0)) &&
                ((param_5 == (void *)0x0 ||
                 (iVar2 = EVP_DigestUpdate(&local_90,param_5,param_6), iVar2 != 0)))))) &&
     ((param_7 == (void *)0x0 || (iVar2 = EVP_DigestUpdate(&local_90,param_7,param_8), iVar2 != 0)))
     ) {
    iVar2 = EVP_DigestSignFinal(&local_90,local_60,&local_94);
    while( true ) {
      if (((((iVar2 == 0) ||
            (iVar2 = EVP_DigestSignInit(&local_90,(EVP_PKEY_CTX **)0x0,param_1_00,(ENGINE *)0x0,pkey
                                       ), iVar2 == 0)) ||
           (iVar2 = EVP_DigestSignInit(&local_78,(EVP_PKEY_CTX **)0x0,param_1_00,(ENGINE *)0x0,pkey)
           , iVar2 == 0)) ||
          (((iVar2 = EVP_DigestUpdate(&local_90,local_60,local_94), iVar2 == 0 ||
            (iVar2 = EVP_DigestUpdate(&local_78,local_60,local_94), iVar2 == 0)) ||
           ((param_1 != (void *)0x0 &&
            (iVar2 = EVP_DigestUpdate(&local_90,param_1,param_2), iVar2 == 0)))))) ||
         ((((param_3 != (void *)0x0 &&
            (iVar2 = EVP_DigestUpdate(&local_90,param_3,param_4), iVar2 == 0)) ||
           ((param_5 != (void *)0x0 &&
            (iVar2 = EVP_DigestUpdate(&local_90,param_5,param_6), iVar2 == 0)))) ||
          ((param_7 != (void *)0x0 &&
           (iVar2 = EVP_DigestUpdate(&local_90,param_7,param_8), iVar2 == 0)))))) goto LAB_080adea2;
      if ((int)param_10 <= iVar1) break;
      iVar2 = EVP_DigestSignFinal(&local_90,param_9,&local_98);
      if (iVar2 == 0) goto LAB_080adea2;
      param_9 = param_9 + local_98;
      param_10 = param_10 - local_98;
      iVar2 = EVP_DigestSignFinal(&local_78,local_60,&local_94);
    }
    iVar1 = EVP_DigestSignFinal(&local_90,local_60,&local_94);
    if (iVar1 != 0) {
      memcpy(param_9,local_60,param_10);
      local_b8 = 1;
      goto LAB_080adeaa;
    }
  }
LAB_080adea2:
  local_b8 = 0;
LAB_080adeaa:
  EVP_PKEY_free(pkey);
  EVP_MD_CTX_cleanup(&local_90);
  EVP_MD_CTX_cleanup(&local_78);
  OPENSSL_cleanse(local_60,0x40);
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return local_b8;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

