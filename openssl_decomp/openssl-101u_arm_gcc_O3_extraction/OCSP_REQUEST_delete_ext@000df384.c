
X509_EXTENSION * OCSP_REQUEST_delete_ext(OCSP_REQUEST *x,int loc)

{
  X509_EXTENSION *pXVar1;
  
  pXVar1 = X509v3_delete_ext(x->tbsRequest->requestExtensions,loc);
  return pXVar1;
}

