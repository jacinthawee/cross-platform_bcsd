
int X509_REVOKED_add_ext(X509_REVOKED *x,X509_EXTENSION *ex,int loc)

{
  stack_st_X509_EXTENSION *psVar1;
  
  psVar1 = X509v3_add_ext(&x->extensions,ex,loc);
  return (uint)(psVar1 != (stack_st_X509_EXTENSION *)0x0);
}
