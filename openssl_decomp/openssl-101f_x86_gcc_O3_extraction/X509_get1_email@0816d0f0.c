
stack_st_OPENSSL_STRING * X509_get1_email(X509 *x)

{
  _STACK *st;
  stack_st_OPENSSL_STRING *psVar1;
  
  st = (_STACK *)X509_get_ext_d2i(x,0x55,(int *)0x0,(int *)0x0);
  X509_get_subject_name(x);
  psVar1 = (stack_st_OPENSSL_STRING *)get_email();
  sk_pop_free(st,GENERAL_NAME_free);
  return psVar1;
}

