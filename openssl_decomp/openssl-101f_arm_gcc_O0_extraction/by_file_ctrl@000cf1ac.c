
int by_file_ctrl(int param_1,int param_2,void *param_3,int param_4)

{
  BIO_METHOD *type;
  BIO *bp;
  long lVar1;
  char *pcVar2;
  X509 *x;
  int iVar3;
  
  if (param_2 != 1) {
    return 0;
  }
  if (param_4 == 3) {
    pcVar2 = X509_get_default_cert_file_env();
    pcVar2 = getenv(pcVar2);
    if (pcVar2 == (char *)0x0) {
      pcVar2 = X509_get_default_cert_file();
    }
    iVar3 = X509_load_cert_crl_file_part_0(param_1,pcVar2);
    if (iVar3 != 0) {
      iVar3 = 1;
    }
    if (iVar3 != 0) {
      return iVar3;
    }
    ERR_put_error(0xb,0x65,0x68,"by_file.c",0x72);
    return 0;
  }
  if (param_4 == 1) {
    iVar3 = X509_load_cert_crl_file_part_0(param_1,param_3);
    if (iVar3 != 0) {
      iVar3 = 1;
    }
    return iVar3;
  }
  if (param_3 == (void *)0x0) {
    return 1;
  }
  type = BIO_s_file();
  bp = BIO_new(type);
  if ((bp == (BIO *)0x0) || (lVar1 = BIO_ctrl(bp,0x6c,3,param_3), lVar1 < 1)) {
    ERR_put_error(0xb,0x6f,2,"by_file.c",0x8e);
    if (bp == (BIO *)0x0) {
      return 0;
    }
  }
  else if (param_4 == 2) {
    x = d2i_X509_bio(bp,(X509 **)0x0);
    if (x != (X509 *)0x0) {
      iVar3 = X509_STORE_add_cert(*(X509_STORE **)(param_1 + 0x10),x);
      if (iVar3 != 0) {
        iVar3 = 1;
      }
      X509_free(x);
      goto LAB_000cf202;
    }
    ERR_put_error(0xb,0x6f,0xd,"by_file.c",0xb3);
  }
  else {
    ERR_put_error(0xb,0x6f,100,"by_file.c",0xbc);
  }
  iVar3 = 0;
LAB_000cf202:
  BIO_free(bp);
  return iVar3;
}

