
int X509_CRL_set_issuer_name(X509_CRL *x,X509_NAME *name)

{
  int iVar1;
  
  if ((x != (X509_CRL *)0x0) && (x->crl != (X509_CRL_INFO *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0057f174. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*(code *)PTR_X509_NAME_set_006aa048)(&x->crl->issuer);
    return iVar1;
  }
  return 0;
}

