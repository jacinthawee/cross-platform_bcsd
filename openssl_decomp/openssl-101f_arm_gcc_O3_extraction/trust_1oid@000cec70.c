
undefined4 trust_1oid(int param_1,int param_2)

{
  _STACK *p_Var1;
  ASN1_OBJECT *pAVar2;
  int iVar3;
  int iVar4;
  _STACK **pp_Var5;
  int iVar6;
  
  pp_Var5 = *(_STACK ***)(param_2 + 100);
  if (pp_Var5 != (_STACK **)0x0) {
    p_Var1 = pp_Var5[1];
    iVar6 = *(int *)(param_1 + 0x10);
    iVar4 = 0;
    if (p_Var1 != (_STACK *)0x0) {
      while( true ) {
        iVar3 = sk_num(p_Var1);
        if (iVar3 <= iVar4) break;
        pAVar2 = (ASN1_OBJECT *)sk_value(pp_Var5[1],iVar4);
        iVar3 = OBJ_obj2nid(pAVar2);
        if (iVar6 == iVar3) {
          return 2;
        }
        p_Var1 = pp_Var5[1];
        iVar4 = iVar4 + 1;
      }
    }
    p_Var1 = *pp_Var5;
    iVar4 = 0;
    if (p_Var1 != (_STACK *)0x0) {
      while( true ) {
        iVar3 = sk_num(p_Var1);
        if (iVar3 <= iVar4) break;
        pAVar2 = (ASN1_OBJECT *)sk_value(*pp_Var5,iVar4);
        iVar3 = OBJ_obj2nid(pAVar2);
        if (iVar6 == iVar3) {
          return 1;
        }
        p_Var1 = *pp_Var5;
        iVar4 = iVar4 + 1;
      }
    }
  }
  return 3;
}

