
int __regparm3
do_pk8pkey(BIO *param_1_00,EVP_PKEY *param_2_00,int param_3_00,int param_1,EVP_CIPHER *param_2,
          char *param_3,int param_4,code *param_5,void *param_6)

{
  PKCS8_PRIV_KEY_INFO *a;
  int iVar1;
  X509_SIG *p8;
  size_t len;
  int in_GS_OFFSET;
  char local_420 [1024];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  a = EVP_PKEY2PKCS8(param_2_00);
  if (a == (PKCS8_PRIV_KEY_INFO *)0x0) {
    ERR_put_error(9,0x7e,0x73,"pem_pk8.c",0x7a);
    iVar1 = 0;
  }
  else if ((param_2 == (EVP_CIPHER *)0x0) && (param_1 == -1)) {
    if (param_3_00 == 0) {
      iVar1 = PEM_ASN1_write_bio(i2d_PKCS8_PRIV_KEY_INFO,"PRIVATE KEY",param_1_00,a,
                                 (EVP_CIPHER *)0x0,(uchar *)0x0,0,(undefined1 *)0x0,(void *)0x0);
    }
    else {
      iVar1 = i2d_PKCS8_PRIV_KEY_INFO_bio(param_1_00,a);
    }
    PKCS8_PRIV_KEY_INFO_free(a);
  }
  else {
    if (param_3 == (char *)0x0) {
      if (param_5 == (code *)0x0) {
        len = PEM_def_callback(local_420,0x400,1,param_6);
      }
      else {
        len = (*param_5)(local_420,0x400,1,param_6);
      }
      if ((int)len < 1) {
        ERR_put_error(9,0x7e,0x6f,"pem_pk8.c",0x82);
        PKCS8_PRIV_KEY_INFO_free(a);
        iVar1 = 0;
        goto LAB_081588cb;
      }
      p8 = PKCS8_encrypt(param_1,param_2,local_420,len,(uchar *)0x0,0,0,a);
      OPENSSL_cleanse(local_420,len);
    }
    else {
      p8 = PKCS8_encrypt(param_1,param_2,param_3,param_4,(uchar *)0x0,0,0,a);
    }
    PKCS8_PRIV_KEY_INFO_free(a);
    if (param_3_00 == 0) {
      iVar1 = PEM_ASN1_write_bio(i2d_X509_SIG,"ENCRYPTED PRIVATE KEY",param_1_00,p8,
                                 (EVP_CIPHER *)0x0,(uchar *)0x0,0,(undefined1 *)0x0,(void *)0x0);
    }
    else {
      iVar1 = i2d_PKCS8_bio(param_1_00,p8);
    }
    X509_SIG_free(p8);
  }
LAB_081588cb:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

