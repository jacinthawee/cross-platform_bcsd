
int NETSCAPE_SPKI_set_pubkey(NETSCAPE_SPKI *x,EVP_PKEY *pkey)

{
  int iVar1;
  
  if ((x != (NETSCAPE_SPKI *)0x0) && (x->spkac != (NETSCAPE_SPKAC *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0057aa1c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*(code *)PTR_X509_PUBKEY_set_006a9fe4)();
    return iVar1;
  }
  return 0;
}

