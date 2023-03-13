
/* WARNING: Removing unreachable block (ram,0x0815635e) */
/* WARNING: Removing unreachable block (ram,0x081563e8) */

int PEM_write_bio_PKCS8PrivateKey_nid
              (BIO *bp,EVP_PKEY *x,int nid,char *kstr,int klen,undefined1 *cb,void *u)

{
  PKCS8_PRIV_KEY_INFO *a;
  X509_SIG *a_00;
  int iVar1;
  size_t len;
  int in_GS_OFFSET;
  char acStack_420 [1024];
  int iStack_20;
  
  iStack_20 = *(int *)(in_GS_OFFSET + 0x14);
  a = EVP_PKEY2PKCS8(x);
  if (a == (PKCS8_PRIV_KEY_INFO *)0x0) {
    ERR_put_error(9,0x7e,0x73,"pem_pk8.c",0x78);
    iVar1 = 0;
  }
  else if (nid == -1) {
    iVar1 = PEM_ASN1_write_bio(i2d_PKCS8_PRIV_KEY_INFO,"PRIVATE KEY",bp,a,(EVP_CIPHER *)0x0,
                               (uchar *)0x0,0,(undefined1 *)0x0,(void *)0x0);
    PKCS8_PRIV_KEY_INFO_free(a);
  }
  else {
    if (kstr == (char *)0x0) {
      if (cb == (undefined1 *)0x0) {
        len = PEM_def_callback(acStack_420,0x400,1,u);
      }
      else {
        len = (*(code *)cb)(acStack_420,0x400,1,u);
      }
      if ((int)len < 1) {
        ERR_put_error(9,0x7e,0x6f,"pem_pk8.c",0x82);
        PKCS8_PRIV_KEY_INFO_free(a);
        iVar1 = 0;
        goto LAB_0815637b;
      }
      a_00 = PKCS8_encrypt(nid,(EVP_CIPHER *)0x0,acStack_420,len,(uchar *)0x0,0,0,a);
      OPENSSL_cleanse(acStack_420,len);
    }
    else {
      a_00 = PKCS8_encrypt(nid,(EVP_CIPHER *)0x0,kstr,klen,(uchar *)0x0,0,0,a);
    }
    PKCS8_PRIV_KEY_INFO_free(a);
    if (a_00 == (X509_SIG *)0x0) {
      iVar1 = 0;
    }
    else {
      iVar1 = PEM_ASN1_write_bio(i2d_X509_SIG,"ENCRYPTED PRIVATE KEY",bp,a_00,(EVP_CIPHER *)0x0,
                                 (uchar *)0x0,0,(undefined1 *)0x0,(void *)0x0);
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

