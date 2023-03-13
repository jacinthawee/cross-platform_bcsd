
/* WARNING: Removing unreachable block (ram,0x0815635e) */
/* WARNING: Removing unreachable block (ram,0x081563e8) */

int PEM_write_bio_PKCS8PrivateKey
              (BIO *param_1,EVP_PKEY *param_2,EVP_CIPHER *param_3,char *param_4,int param_5,
              undefined1 *param_6,void *param_7)

{
  PKCS8_PRIV_KEY_INFO *a;
  X509_SIG *a_00;
  int iVar1;
  size_t len;
  int in_GS_OFFSET;
  char acStack_420 [1024];
  int iStack_20;
  
  iStack_20 = *(int *)(in_GS_OFFSET + 0x14);
  a = EVP_PKEY2PKCS8(param_2);
  if (a == (PKCS8_PRIV_KEY_INFO *)0x0) {
    ERR_put_error(9,0x7e,0x73,"pem_pk8.c",0x78);
    iVar1 = 0;
  }
  else if (param_3 == (EVP_CIPHER *)0x0) {
    iVar1 = PEM_ASN1_write_bio(i2d_PKCS8_PRIV_KEY_INFO,"PRIVATE KEY",param_1,a,(EVP_CIPHER *)0x0,
                               (uchar *)0x0,0,(undefined1 *)0x0,(void *)0x0);
    PKCS8_PRIV_KEY_INFO_free(a);
  }
  else {
    if (param_4 == (char *)0x0) {
      if (param_6 == (undefined1 *)0x0) {
        len = PEM_def_callback(acStack_420,0x400,1,param_7);
      }
      else {
        len = (*(code *)param_6)(acStack_420,0x400,1,param_7);
      }
      if ((int)len < 1) {
        ERR_put_error(9,0x7e,0x6f,"pem_pk8.c",0x82);
        PKCS8_PRIV_KEY_INFO_free(a);
        iVar1 = 0;
        goto LAB_0815637b;
      }
      a_00 = PKCS8_encrypt(-1,param_3,acStack_420,len,(uchar *)0x0,0,0,a);
      OPENSSL_cleanse(acStack_420,len);
    }
    else {
      a_00 = PKCS8_encrypt(-1,param_3,param_4,param_5,(uchar *)0x0,0,0,a);
    }
    PKCS8_PRIV_KEY_INFO_free(a);
    if (a_00 == (X509_SIG *)0x0) {
      iVar1 = 0;
    }
    else {
      iVar1 = PEM_ASN1_write_bio(i2d_X509_SIG,"ENCRYPTED PRIVATE KEY",param_1,a_00,(EVP_CIPHER *)0x0
                                 ,(uchar *)0x0,0,(undefined1 *)0x0,(void *)0x0);
      X509_SIG_free(a_00);
    }
  }
LAB_0815637b:
  if (iStack_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

