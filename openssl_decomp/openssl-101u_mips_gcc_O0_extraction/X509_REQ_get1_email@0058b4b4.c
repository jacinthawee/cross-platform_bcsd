
stack_st_OPENSSL_STRING * X509_REQ_get1_email(X509_REQ *x)

{
  stack_st_X509_EXTENSION *x_00;
  void *pvVar1;
  stack_st_OPENSSL_STRING *psVar2;
  
  x_00 = X509_REQ_get_extensions(x);
  pvVar1 = X509V3_get_d2i(x_00,0x55,(int *)0x0,(int *)0x0);
  psVar2 = (stack_st_OPENSSL_STRING *)get_email(x->req_info->subject,pvVar1);
  (*(code *)PTR_sk_pop_free_006a7058)(pvVar1,PTR_GENERAL_NAME_free_006a73a4);
  (*(code *)PTR_sk_pop_free_006a7058)(x_00,PTR_X509_EXTENSION_free_006a7168);
  return psVar2;
}

