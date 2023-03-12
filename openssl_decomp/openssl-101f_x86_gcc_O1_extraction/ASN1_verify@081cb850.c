
int ASN1_verify(undefined1 *i2d,X509_ALGOR *algor1,ASN1_BIT_STRING *signature,char *data,
               EVP_PKEY *pkey)

{
  int iVar1;
  char *name;
  EVP_MD *type;
  size_t cnt;
  void *d;
  int iVar2;
  int in_GS_OFFSET;
  int line;
  void *local_3c;
  EVP_MD_CTX local_38;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  EVP_MD_CTX_init(&local_38);
  iVar1 = OBJ_obj2nid(algor1->algorithm);
  name = OBJ_nid2sn(iVar1);
  type = EVP_get_digestbyname(name);
  if (type == (EVP_MD *)0x0) {
    line = 0x5a;
    iVar1 = 0xa1;
  }
  else {
    cnt = (*(code *)i2d)(data,0);
    d = CRYPTO_malloc(cnt,"a_verify.c",0x5f);
    if (d != (void *)0x0) {
      local_3c = d;
      (*(code *)i2d)(data,&local_3c);
      iVar1 = EVP_DigestInit_ex(&local_38,type,(ENGINE *)0x0);
      if (iVar1 == 0) {
LAB_081cb91a:
        iVar1 = 0x6b;
      }
      else {
        iVar1 = EVP_DigestUpdate(&local_38,d,cnt);
        if (iVar1 == 0) goto LAB_081cb91a;
        iVar2 = 1;
        OPENSSL_cleanse(d,cnt);
        CRYPTO_free(d);
        iVar1 = EVP_VerifyFinal(&local_38,signature->data,signature->length,pkey);
        if (0 < iVar1) goto LAB_081cb937;
        iVar1 = 0x76;
      }
      iVar2 = 0;
      ERR_put_error(0xd,0x89,6,"a_verify.c",iVar1);
      goto LAB_081cb937;
    }
    line = 0x62;
    iVar1 = 0x41;
  }
  iVar2 = -1;
  ERR_put_error(0xd,0x89,iVar1,"a_verify.c",line);
LAB_081cb937:
  EVP_MD_CTX_cleanup(&local_38);
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

