
undefined4 obj_trust(int param_1,int param_2)

{
  _STACK **pp_Var1;
  int iVar2;
  ASN1_OBJECT *pAVar3;
  _STACK *p_Var4;
  int iVar5;
  
  pp_Var1 = *(_STACK ***)(param_2 + 100);
  if (pp_Var1 != (_STACK **)0x0) {
    p_Var4 = pp_Var1[1];
    if (p_Var4 != (_STACK *)0x0) {
      for (iVar5 = 0; iVar2 = sk_num(p_Var4), iVar5 < iVar2; iVar5 = iVar5 + 1) {
        pAVar3 = (ASN1_OBJECT *)sk_value(pp_Var1[1],iVar5);
        iVar2 = OBJ_obj2nid(pAVar3);
        if (iVar2 == param_1) {
          return 2;
        }
        p_Var4 = pp_Var1[1];
      }
    }
    p_Var4 = *pp_Var1;
    iVar5 = 0;
    if (p_Var4 != (_STACK *)0x0) {
      for (; iVar2 = sk_num(p_Var4), iVar5 < iVar2; iVar5 = iVar5 + 1) {
        pAVar3 = (ASN1_OBJECT *)sk_value(*pp_Var1,iVar5);
        iVar2 = OBJ_obj2nid(pAVar3);
        if (param_1 == iVar2) {
          return 1;
        }
        p_Var4 = *pp_Var1;
      }
    }
  }
  return 3;
}

