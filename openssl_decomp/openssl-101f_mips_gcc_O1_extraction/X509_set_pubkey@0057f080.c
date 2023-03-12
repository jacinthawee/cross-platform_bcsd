
int X509_set_pubkey(X509 *x,EVP_PKEY *pkey)

{
  int iVar1;
  
  if ((x != (X509 *)0x0) && (x->cert_info != (X509_CINF *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0057f09c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*(code *)PTR_X509_PUBKEY_set_006a9fe4)(&x->cert_info->key);
    return iVar1;
  }
  return 0;
}

