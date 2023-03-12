
int NETSCAPE_SPKI_set_pubkey(NETSCAPE_SPKI *x,EVP_PKEY *pkey)

{
  int iVar1;
  
  if ((x != (NETSCAPE_SPKI *)0x0) && (x->spkac != (NETSCAPE_SPKAC *)0x0)) {
    iVar1 = X509_PUBKEY_set(&x->spkac->pubkey,pkey);
    return iVar1;
  }
  return 0;
}

