
int X509_set_pubkey(X509 *x,EVP_PKEY *pkey)

{
  int iVar1;
  
  if ((x != (X509 *)0x0) && (x->cert_info != (X509_CINF *)0x0)) {
    iVar1 = X509_PUBKEY_set(&x->cert_info->key,pkey);
    return iVar1;
  }
  return 0;
}

