
stack_st_OPENSSL_STRING * X509_get1_email(X509 *x)

{
  void *pvVar1;
  X509_NAME *pXVar2;
  stack_st_OPENSSL_STRING *psVar3;
  
  pvVar1 = X509_get_ext_d2i(x,0x55,(int *)0x0,(int *)0x0);
  pXVar2 = X509_get_subject_name(x);
  psVar3 = (stack_st_OPENSSL_STRING *)get_email(pXVar2,pvVar1);
  (*(code *)PTR_sk_pop_free_006a7058)(pvVar1,PTR_GENERAL_NAME_free_006a73a4);
  return psVar3;
}

