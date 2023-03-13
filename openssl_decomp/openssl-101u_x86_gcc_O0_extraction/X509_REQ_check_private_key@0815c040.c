
int X509_REQ_check_private_key(X509_REQ *x509,EVP_PKEY *pkey)

{
  int iVar1;
  EVP_PKEY *a;
  int iVar2;
  int line;
  
  if (x509 == (X509_REQ *)0x0) {
    a = (EVP_PKEY *)0x0;
  }
  else {
    a = (EVP_PKEY *)0x0;
    if (x509->req_info != (X509_REQ_INFO *)0x0) {
      a = X509_PUBKEY_get(x509->req_info->pubkey);
    }
  }
  iVar1 = EVP_PKEY_cmp(a,pkey);
  if (iVar1 == -1) {
    line = 0x86;
    iVar1 = 0x73;
LAB_0815c0af:
    iVar2 = 0;
    ERR_put_error(0xb,0x90,iVar1,"x509_req.c",line);
  }
  else {
    if (iVar1 < 0) {
      if (iVar1 == -2) {
        if (pkey->type == 0x198) {
          line = 0x8b;
          iVar1 = 0x10;
        }
        else if (pkey->type == 0x1c) {
          line = 0x93;
          iVar1 = 0x72;
        }
        else {
          line = 0x97;
          iVar1 = 0x75;
        }
        goto LAB_0815c0af;
      }
    }
    else {
      if (iVar1 == 0) {
        line = 0x83;
        iVar1 = 0x74;
        goto LAB_0815c0af;
      }
      iVar2 = 1;
      if (iVar1 == 1) goto LAB_0815c08f;
    }
    iVar2 = 0;
  }
LAB_0815c08f:
  EVP_PKEY_free(a);
  return iVar2;
}

