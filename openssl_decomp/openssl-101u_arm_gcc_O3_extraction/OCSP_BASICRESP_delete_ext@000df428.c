
X509_EXTENSION * OCSP_BASICRESP_delete_ext(OCSP_BASICRESP *x,int loc)

{
  X509_EXTENSION *pXVar1;
  
  pXVar1 = X509v3_delete_ext(x->tbsResponseData->responseExtensions,loc);
  return pXVar1;
}

