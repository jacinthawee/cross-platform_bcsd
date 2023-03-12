
EVP_PKEY * NETSCAPE_SPKI_get_pubkey(NETSCAPE_SPKI *x)

{
  EVP_PKEY *pEVar1;
  
  if ((x != (NETSCAPE_SPKI *)0x0) && (x->spkac != (NETSCAPE_SPKAC *)0x0)) {
    pEVar1 = X509_PUBKEY_get(x->spkac->pubkey);
    return pEVar1;
  }
  return (EVP_PKEY *)0x0;
}

