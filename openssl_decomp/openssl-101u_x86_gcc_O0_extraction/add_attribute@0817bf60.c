
undefined4 __regparm3 add_attribute(_STACK **param_1_00,int param_2,int param_3,void *param_1)

{
  int iVar1;
  X509_ATTRIBUTE *pXVar2;
  _STACK *p_Var3;
  void *pvVar4;
  int iVar5;
  
  p_Var3 = *param_1_00;
  if (p_Var3 == (_STACK *)0x0) {
    p_Var3 = sk_new_null();
    *param_1_00 = p_Var3;
    if (p_Var3 == (_STACK *)0x0) {
      return 0;
    }
  }
  else {
    for (iVar5 = 0; iVar1 = sk_num(p_Var3), iVar5 < iVar1; iVar5 = iVar5 + 1) {
      pXVar2 = (X509_ATTRIBUTE *)sk_value(*param_1_00,iVar5);
      iVar1 = OBJ_obj2nid(pXVar2->object);
      if (iVar1 == param_2) {
        X509_ATTRIBUTE_free(pXVar2);
        pXVar2 = X509_ATTRIBUTE_create(param_2,param_3,param_1);
        if (pXVar2 == (X509_ATTRIBUTE *)0x0) {
          return 0;
        }
        pvVar4 = sk_set(*param_1_00,iVar5,pXVar2);
        if (pvVar4 != (void *)0x0) {
          return 1;
        }
        X509_ATTRIBUTE_free(pXVar2);
        return 0;
      }
      p_Var3 = *param_1_00;
    }
  }
  pXVar2 = X509_ATTRIBUTE_create(param_2,param_3,param_1);
  if (pXVar2 == (X509_ATTRIBUTE *)0x0) {
    return 0;
  }
  iVar5 = sk_push(*param_1_00,pXVar2);
  if (iVar5 != 0) {
    return 1;
  }
  X509_ATTRIBUTE_free(pXVar2);
  return 0;
}

