
EVP_PKEY * NETSCAPE_SPKI_get_pubkey(NETSCAPE_SPKI *x)

{
  EVP_PKEY *pEVar1;
  
  if ((x != (NETSCAPE_SPKI *)0x0) && (x->spkac != (NETSCAPE_SPKAC *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x005772c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pEVar1 = (EVP_PKEY *)(*(code *)PTR_X509_PUBKEY_get_006a8d64)(x->spkac->pubkey);
    return pEVar1;
  }
  return (EVP_PKEY *)0x0;
}

