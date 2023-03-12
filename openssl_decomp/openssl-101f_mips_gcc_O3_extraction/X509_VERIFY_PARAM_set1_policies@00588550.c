
int X509_VERIFY_PARAM_set1_policies(X509_VERIFY_PARAM *param,stack_st_ASN1_OBJECT *policies)

{
  stack_st_ASN1_OBJECT *psVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if (param == (X509_VERIFY_PARAM *)0x0) {
    return 0;
  }
  if (param->policies != (stack_st_ASN1_OBJECT *)0x0) {
    (*(code *)PTR_sk_pop_free_006a8158)(param->policies,PTR_ASN1_OBJECT_free_006a8104);
  }
  if (policies != (stack_st_ASN1_OBJECT *)0x0) {
    psVar1 = (stack_st_ASN1_OBJECT *)(*(code *)PTR_sk_new_null_006a80a4)();
    param->policies = psVar1;
    if (psVar1 != (stack_st_ASN1_OBJECT *)0x0) {
      iVar5 = 0;
      while( true ) {
        iVar4 = (*(code *)PTR_sk_num_006a7f2c)(policies);
        if (iVar4 <= iVar5) {
          param->flags = param->flags | 0x80;
          return 1;
        }
        uVar2 = (*(code *)PTR_sk_value_006a7f24)(policies,iVar5);
        iVar4 = (*(code *)PTR_OBJ_dup_006a95b4)(uVar2);
        if (iVar4 == 0) break;
        iVar3 = (*(code *)PTR_sk_push_006a80a8)(param->policies,iVar4);
        iVar5 = iVar5 + 1;
        if (iVar3 == 0) {
          (*(code *)PTR_ASN1_OBJECT_free_006a8104)(iVar4);
          return 0;
        }
      }
    }
    return 0;
  }
  param->policies = (stack_st_ASN1_OBJECT *)0x0;
  return 1;
}

