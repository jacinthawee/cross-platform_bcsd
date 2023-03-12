
int X509_check_private_key(X509 *x509,EVP_PKEY *pkey)

{
  EVP_PKEY *a;
  int iVar1;
  
  if (((x509 == (X509 *)0x0) || (x509->cert_info == (X509_CINF *)0x0)) ||
     (a = X509_PUBKEY_get(x509->cert_info->key), a == (EVP_PKEY *)0x0)) {
    a = (EVP_PKEY *)0x0;
LAB_000c6bfc:
    ERR_put_error(0xb,0x80,0x75,"x509_cmp.c",0x15b);
    if (a == (EVP_PKEY *)0x0) {
      return 0;
    }
  }
  else {
    iVar1 = EVP_PKEY_cmp(a,pkey);
    if (iVar1 == -1) {
      ERR_put_error(0xb,0x80,0x73,"x509_cmp.c",0x158);
    }
    else {
      if (iVar1 != 0) {
        if (iVar1 != -2) {
          if (iVar1 < 1) {
            iVar1 = 0;
          }
          else {
            iVar1 = 1;
          }
          goto LAB_000c6bd2;
        }
        goto LAB_000c6bfc;
      }
      ERR_put_error(0xb,0x80,0x74,"x509_cmp.c",0x155);
    }
  }
  iVar1 = 0;
LAB_000c6bd2:
  EVP_PKEY_free(a);
  return iVar1;
}

