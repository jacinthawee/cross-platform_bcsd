
int OCSP_BASICRESP_add_ext(OCSP_BASICRESP *x,X509_EXTENSION *ex,int loc)

{
  stack_st_X509_EXTENSION *psVar1;
  
  psVar1 = X509v3_add_ext(&x->tbsResponseData->responseExtensions,ex,loc);
  if (psVar1 != (stack_st_X509_EXTENSION *)0x0) {
    psVar1 = (stack_st_X509_EXTENSION *)0x1;
  }
  return (int)psVar1;
}
