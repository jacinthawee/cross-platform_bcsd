
int OCSP_SINGLERESP_add_ext(OCSP_SINGLERESP *x,X509_EXTENSION *ex,int loc)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_X509v3_add_ext_006a8f64)(&x->singleExtensions);
  return (uint)(iVar1 != 0);
}

