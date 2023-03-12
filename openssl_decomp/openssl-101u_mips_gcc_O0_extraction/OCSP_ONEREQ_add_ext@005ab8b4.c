
int OCSP_ONEREQ_add_ext(OCSP_ONEREQ *x,X509_EXTENSION *ex,int loc)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_X509v3_add_ext_006a8f64)(&x->singleRequestExtensions);
  return (uint)(iVar1 != 0);
}

