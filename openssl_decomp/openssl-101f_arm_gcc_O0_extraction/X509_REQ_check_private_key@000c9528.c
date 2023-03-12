
int X509_REQ_check_private_key(X509_REQ *x509,EVP_PKEY *pkey)

{
  int iVar1;
  
  if ((x509 != (X509_REQ *)0x0) &&
     (x509 = (X509_REQ *)x509->req_info, (EVP_PKEY *)x509 != (EVP_PKEY *)0x0)) {
    x509 = (X509_REQ *)X509_PUBKEY_get((X509_PUBKEY *)((_union_271 *)((int)x509 + 0x14))->rsa);
  }
  iVar1 = EVP_PKEY_cmp((EVP_PKEY *)x509,pkey);
  switch(iVar1) {
  case 0:
    ERR_put_error(0xb,0x90,0x74,"x509_req.c",0x81);
    EVP_PKEY_free((EVP_PKEY *)x509);
    return 0;
  case 1:
    iVar1 = 1;
    break;
  default:
    EVP_PKEY_free((EVP_PKEY *)x509);
    return 0;
  case -2:
    if (pkey->type == 0x198) {
      iVar1 = 0;
      ERR_put_error(0xb,0x90,0x10,"x509_req.c",0x8a);
    }
    else {
      if (pkey->type != 0x1c) {
        ERR_put_error(0xb,0x90,0x75,"x509_req.c",0x96);
        EVP_PKEY_free((EVP_PKEY *)x509);
        return 0;
      }
      iVar1 = 0;
      ERR_put_error(0xb,0x90,0x72,"x509_req.c",0x92);
    }
    break;
  case -1:
    ERR_put_error(0xb,0x90,0x73,"x509_req.c",0x84);
    EVP_PKEY_free((EVP_PKEY *)x509);
    return 0;
  }
  EVP_PKEY_free((EVP_PKEY *)x509);
  return iVar1;
}

