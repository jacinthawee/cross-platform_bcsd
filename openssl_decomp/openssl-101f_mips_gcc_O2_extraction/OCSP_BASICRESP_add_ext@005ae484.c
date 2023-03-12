
int OCSP_BASICRESP_add_ext(OCSP_BASICRESP *x,X509_EXTENSION *ex,int loc)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_X509v3_add_ext_006aa080)(&x->tbsResponseData->responseExtensions);
  return (uint)(iVar1 != 0);
}

