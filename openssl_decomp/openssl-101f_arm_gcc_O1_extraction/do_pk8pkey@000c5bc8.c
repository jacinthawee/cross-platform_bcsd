
void do_pk8pkey(BIO *param_1,EVP_PKEY *param_2,int param_3,int param_4,EVP_CIPHER *param_5,
               char *param_6,int param_7,code *param_8,void *param_9)

{
  PKCS8_PRIV_KEY_INFO *p8inf;
  X509_SIG *p8;
  PKCS8_PRIV_KEY_INFO *pPVar1;
  size_t len;
  char acStack_42c [1024];
  int local_2c;
  
  local_2c = __TMC_END__;
  p8inf = EVP_PKEY2PKCS8(param_2);
  if (p8inf == (PKCS8_PRIV_KEY_INFO *)0x0) {
    ERR_put_error(9,0x7e,0x73,"pem_pk8.c",0x7a);
  }
  else if (param_4 == -1 && param_5 == (EVP_CIPHER *)0x0) {
    if (param_3 == 0) {
      pPVar1 = (PKCS8_PRIV_KEY_INFO *)
               PEM_ASN1_write_bio(i2d_PKCS8_PRIV_KEY_INFO + 1,"PRIVATE KEY",param_1,p8inf,
                                  (EVP_CIPHER *)0x0,(uchar *)0x0,0,(undefined1 *)0x0,(void *)0x0);
    }
    else {
      pPVar1 = (PKCS8_PRIV_KEY_INFO *)i2d_PKCS8_PRIV_KEY_INFO_bio(param_1,p8inf);
    }
    PKCS8_PRIV_KEY_INFO_free(p8inf);
    p8inf = pPVar1;
  }
  else {
    if (param_6 == (char *)0x0) {
      if (param_8 == (code *)0x0) {
        len = PEM_def_callback(acStack_42c,0x400,1,param_9);
      }
      else {
        len = (*param_8)();
      }
      if ((int)len < 1) {
        ERR_put_error(9,0x7e,0x6f,"pem_pk8.c",0x82);
        PKCS8_PRIV_KEY_INFO_free(p8inf);
        p8inf = (PKCS8_PRIV_KEY_INFO *)0x0;
        goto LAB_000c5c5c;
      }
      p8 = PKCS8_encrypt(param_4,param_5,acStack_42c,len,(uchar *)0x0,0,0,p8inf);
      OPENSSL_cleanse(acStack_42c,len);
    }
    else {
      p8 = PKCS8_encrypt(param_4,param_5,param_6,param_7,(uchar *)0x0,0,0,p8inf);
    }
    PKCS8_PRIV_KEY_INFO_free(p8inf);
    if (param_3 == 0) {
      p8inf = (PKCS8_PRIV_KEY_INFO *)
              PEM_ASN1_write_bio(i2d_X509_SIG + 1,"ENCRYPTED PRIVATE KEY",param_1,p8,
                                 (EVP_CIPHER *)0x0,(uchar *)0x0,0,(undefined1 *)0x0,(void *)0x0);
    }
    else {
      p8inf = (PKCS8_PRIV_KEY_INFO *)i2d_PKCS8_bio(param_1,p8);
    }
    X509_SIG_free(p8);
  }
LAB_000c5c5c:
  if (local_2c == __TMC_END__) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(p8inf);
}

