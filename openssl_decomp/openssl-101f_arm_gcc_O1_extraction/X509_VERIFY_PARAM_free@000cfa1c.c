
void X509_VERIFY_PARAM_free(X509_VERIFY_PARAM *param)

{
  if (param != (X509_VERIFY_PARAM *)0x0) {
    param->name = (char *)0x0;
    param->purpose = 0;
    param->trust = 0;
    param->inh_flags = 0;
    param->flags = 0;
    param->depth = -1;
    if ((_STACK *)param->policies != (_STACK *)0x0) {
      sk_pop_free((_STACK *)param->policies,ASN1_OBJECT_free + 1);
      param->policies = (stack_st_ASN1_OBJECT *)0x0;
    }
  }
  CRYPTO_free(param);
  return;
}

