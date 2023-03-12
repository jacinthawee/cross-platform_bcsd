
int X509_VERIFY_PARAM_add0_policy(X509_VERIFY_PARAM *param,ASN1_OBJECT *policy)

{
  stack_st_ASN1_OBJECT *psVar1;
  int iVar2;
  
  psVar1 = param->policies;
  if (psVar1 == (stack_st_ASN1_OBJECT *)0x0) {
    psVar1 = (stack_st_ASN1_OBJECT *)(*(code *)PTR_sk_new_null_006a80a4)();
    param->policies = psVar1;
    if (psVar1 == (stack_st_ASN1_OBJECT *)0x0) {
      return 0;
    }
  }
  iVar2 = (*(code *)PTR_sk_push_006a80a8)(psVar1,policy);
  return (uint)(iVar2 != 0);
}

