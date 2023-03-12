
EVP_PKEY * X509_get_pubkey(X509 *x)

{
  EVP_PKEY *pEVar1;
  
  if ((x != (X509 *)0x0) && (x->cert_info != (X509_CINF *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00579a20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pEVar1 = (EVP_PKEY *)(*(code *)PTR_X509_PUBKEY_get_006a9e84)(x->cert_info->key);
    return pEVar1;
  }
  return (EVP_PKEY *)0x0;
}

