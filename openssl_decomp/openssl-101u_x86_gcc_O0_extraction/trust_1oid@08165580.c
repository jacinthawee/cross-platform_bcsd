
undefined4 trust_1oid(int param_1,int param_2)

{
  _STACK **pp_Var1;
  int iVar2;
  int iVar3;
  ASN1_OBJECT *pAVar4;
  _STACK *p_Var5;
  int iVar6;
  
  pp_Var1 = *(_STACK ***)(param_2 + 100);
  if (pp_Var1 != (_STACK **)0x0) {
    iVar2 = *(int *)(param_1 + 0x10);
    p_Var5 = pp_Var1[1];
    if (p_Var5 != (_STACK *)0x0) {
      for (iVar6 = 0; iVar3 = sk_num(p_Var5), iVar6 < iVar3; iVar6 = iVar6 + 1) {
        pAVar4 = (ASN1_OBJECT *)sk_value(pp_Var1[1],iVar6);
        iVar3 = OBJ_obj2nid(pAVar4);
        if (iVar2 == iVar3) {
          return 2;
        }
        p_Var5 = pp_Var1[1];
      }
    }
    p_Var5 = *pp_Var1;
    iVar6 = 0;
    if (p_Var5 != (_STACK *)0x0) {
      for (; iVar3 = sk_num(p_Var5), iVar6 < iVar3; iVar6 = iVar6 + 1) {
        pAVar4 = (ASN1_OBJECT *)sk_value(*pp_Var1,iVar6);
        iVar3 = OBJ_obj2nid(pAVar4);
        if (iVar2 == iVar3) {
          return 1;
        }
        p_Var5 = *pp_Var1;
      }
    }
  }
  return 3;
}

