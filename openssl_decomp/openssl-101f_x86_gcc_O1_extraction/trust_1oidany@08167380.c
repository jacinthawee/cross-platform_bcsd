
undefined4 trust_1oidany(int param_1,X509 *param_2)

{
  _STACK **pp_Var1;
  _STACK *p_Var2;
  int iVar3;
  ASN1_OBJECT *pAVar4;
  _STACK *p_Var5;
  int iVar6;
  int iVar7;
  
  pp_Var1 = *(_STACK ***)(param_2->sha1_hash + 0xc);
  if (pp_Var1 == (_STACK **)0x0) {
LAB_08167458:
    X509_check_purpose(param_2,-1,0);
    if ((*(byte *)&param_2->ex_flags & 0x20) == 0) {
      return 3;
    }
    return 1;
  }
  p_Var5 = *pp_Var1;
  if (p_Var5 == (_STACK *)0x0) {
    p_Var2 = pp_Var1[1];
    if (p_Var2 == (_STACK *)0x0) goto LAB_08167458;
    iVar7 = *(int *)(param_1 + 0x10);
  }
  else {
    iVar7 = *(int *)(param_1 + 0x10);
    p_Var2 = pp_Var1[1];
    if (p_Var2 == (_STACK *)0x0) goto LAB_081673e7;
  }
  for (iVar6 = 0; iVar3 = sk_num(p_Var2), iVar6 < iVar3; iVar6 = iVar6 + 1) {
    pAVar4 = (ASN1_OBJECT *)sk_value(pp_Var1[1],iVar6);
    iVar3 = OBJ_obj2nid(pAVar4);
    if (iVar7 == iVar3) {
      return 2;
    }
    p_Var2 = pp_Var1[1];
  }
  p_Var5 = *pp_Var1;
  if (p_Var5 == (_STACK *)0x0) {
    return 3;
  }
LAB_081673e7:
  iVar6 = 0;
  while( true ) {
    iVar3 = sk_num(p_Var5);
    if (iVar3 <= iVar6) {
      return 3;
    }
    pAVar4 = (ASN1_OBJECT *)sk_value(*pp_Var1,iVar6);
    iVar3 = OBJ_obj2nid(pAVar4);
    if (iVar3 == iVar7) break;
    p_Var5 = *pp_Var1;
    iVar6 = iVar6 + 1;
  }
  return 1;
}

