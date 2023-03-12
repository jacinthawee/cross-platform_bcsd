
int X509_set_issuer_name(X509 *x,X509_NAME *name)

{
  int iVar1;
  
  if ((x != (X509 *)0x0) && (x->cert_info != (X509_CINF *)0x0)) {
    iVar1 = X509_NAME_set(&x->cert_info->issuer,name);
    return iVar1;
  }
  return 0;
}

