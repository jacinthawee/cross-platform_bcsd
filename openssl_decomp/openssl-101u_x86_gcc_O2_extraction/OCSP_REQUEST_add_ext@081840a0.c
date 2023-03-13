
int OCSP_REQUEST_add_ext(OCSP_REQUEST *x,X509_EXTENSION *ex,int loc)

{
  stack_st_X509_EXTENSION *psVar1;
  
  psVar1 = X509v3_add_ext(&x->tbsRequest->requestExtensions,ex,loc);
  return (uint)(psVar1 != (stack_st_X509_EXTENSION *)0x0);
}

