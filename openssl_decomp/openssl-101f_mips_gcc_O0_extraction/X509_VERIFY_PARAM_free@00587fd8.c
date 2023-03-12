
void X509_VERIFY_PARAM_free(X509_VERIFY_PARAM *param)

{
  if (param != (X509_VERIFY_PARAM *)0x0) {
    param->name = (char *)0x0;
    param->purpose = 0;
    param->trust = 0;
    param->inh_flags = 0;
    param->flags = 0;
    param->depth = -1;
    if (param->policies != (stack_st_ASN1_OBJECT *)0x0) {
      (*(code *)PTR_sk_pop_free_006a8158)(param->policies,PTR_ASN1_OBJECT_free_006a8104);
      param->policies = (stack_st_ASN1_OBJECT *)0x0;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x00588044. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_CRYPTO_free_006a7f88)(param);
  return;
}

