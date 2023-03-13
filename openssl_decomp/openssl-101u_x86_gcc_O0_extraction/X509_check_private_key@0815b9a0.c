
int X509_check_private_key(X509 *x509,EVP_PKEY *pkey)

{
  EVP_PKEY *a;
  int iVar1;
  uint uVar2;
  
  if ((x509 == (X509 *)0x0) || (x509->cert_info == (X509_CINF *)0x0)) {
LAB_0815ba38:
    a = (EVP_PKEY *)0x0;
  }
  else {
    a = X509_PUBKEY_get(x509->cert_info->key);
    if (a == (EVP_PKEY *)0x0) goto LAB_0815ba38;
    iVar1 = EVP_PKEY_cmp(a,pkey);
    if (iVar1 == -1) {
      uVar2 = 0;
      ERR_put_error(0xb,0x80,0x73,"x509_cmp.c",0x158);
      goto LAB_0815b9fb;
    }
    if (iVar1 == 0) {
      uVar2 = 0;
      ERR_put_error(0xb,0x80,0x74,"x509_cmp.c",0x155);
      goto LAB_0815b9fb;
    }
    if (iVar1 != -2) {
      uVar2 = (uint)(0 < iVar1);
      goto LAB_0815b9fb;
    }
  }
  uVar2 = 0;
  ERR_put_error(0xb,0x80,0x75,"x509_cmp.c",0x15b);
  if (a == (EVP_PKEY *)0x0) {
    return 0;
  }
LAB_0815b9fb:
  EVP_PKEY_free(a);
  return uVar2;
}

