
int X509_CRL_get_ext_by_critical(X509_CRL *x,int crit,int lastpos)

{
  int iVar1;
  
  iVar1 = X509v3_get_ext_by_critical(x->crl->extensions,crit,lastpos);
  return iVar1;
}
