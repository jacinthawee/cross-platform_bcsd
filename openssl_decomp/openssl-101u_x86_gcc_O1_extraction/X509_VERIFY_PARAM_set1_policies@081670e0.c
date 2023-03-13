
int X509_VERIFY_PARAM_set1_policies(X509_VERIFY_PARAM *param,stack_st_ASN1_OBJECT *policies)

{
  _STACK *p_Var1;
  ASN1_OBJECT *pAVar2;
  int iVar3;
  int iVar4;
  
  if (param != (X509_VERIFY_PARAM *)0x0) {
    if ((_STACK *)param->policies != (_STACK *)0x0) {
      sk_pop_free((_STACK *)param->policies,ASN1_OBJECT_free);
    }
    if (policies == (stack_st_ASN1_OBJECT *)0x0) {
      param->policies = (stack_st_ASN1_OBJECT *)0x0;
      return 1;
    }
    p_Var1 = sk_new_null();
    param->policies = (stack_st_ASN1_OBJECT *)p_Var1;
    if (p_Var1 != (_STACK *)0x0) {
      iVar4 = 0;
      while( true ) {
        iVar3 = sk_num(&policies->stack);
        if (iVar3 <= iVar4) {
          param->flags = param->flags | 0x80;
          return 1;
        }
        pAVar2 = (ASN1_OBJECT *)sk_value(&policies->stack,iVar4);
        pAVar2 = OBJ_dup(pAVar2);
        if (pAVar2 == (ASN1_OBJECT *)0x0) break;
        iVar3 = sk_push((_STACK *)param->policies,pAVar2);
        if (iVar3 == 0) {
          ASN1_OBJECT_free(pAVar2);
          return 0;
        }
        iVar4 = iVar4 + 1;
      }
    }
  }
  return 0;
}

