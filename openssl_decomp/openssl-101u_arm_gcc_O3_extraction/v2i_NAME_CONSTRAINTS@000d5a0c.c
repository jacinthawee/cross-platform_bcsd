
_STACK ** v2i_NAME_CONSTRAINTS(X509V3_EXT_METHOD *param_1,X509V3_CTX *param_2,_STACK *param_3)

{
  _STACK **val;
  _STACK **val_00;
  GENERAL_NAME *pGVar1;
  _STACK *st;
  int iVar2;
  void *pvVar3;
  char *__s1;
  int iVar4;
  _STACK **pp_Var5;
  CONF_VALUE CStack_34;
  
  val = (_STACK **)ASN1_item_new((ASN1_ITEM *)&NAME_CONSTRAINTS_it);
  if (val == (_STACK **)0x0) {
    ERR_put_error(0x22,0x93,0x41,"v3_ncons.c",0x95);
  }
  else {
    for (iVar4 = 0; iVar2 = sk_num(param_3), iVar4 < iVar2; iVar4 = iVar4 + 1) {
      pvVar3 = sk_value(param_3,iVar4);
      __s1 = *(char **)((int)pvVar3 + 4);
      iVar2 = strncmp(__s1,"permitted",9);
      if ((iVar2 == 0) && (__s1[9] != '\0')) {
        CStack_34.name = __s1 + 10;
        pp_Var5 = val;
      }
      else {
        iVar2 = strncmp(__s1,"excluded",8);
        if ((iVar2 != 0) || (__s1[8] == '\0')) {
          val_00 = (_STACK **)0x0;
          ERR_put_error(0x22,0x93,0x8f,"v3_ncons.c",0x82);
          goto LAB_000d5ad4;
        }
        CStack_34.name = __s1 + 9;
        pp_Var5 = val + 1;
      }
      CStack_34.value = *(char **)((int)pvVar3 + 8);
      val_00 = (_STACK **)ASN1_item_new((ASN1_ITEM *)PTR_GENERAL_SUBTREE_it_000d5b38);
      if (val_00 == (_STACK **)0x0) {
LAB_000d5b00:
        ERR_put_error(0x22,0x93,0x41,"v3_ncons.c",0x95);
LAB_000d5ad4:
        ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)&NAME_CONSTRAINTS_it);
        if (val_00 != (_STACK **)0x0) {
          ASN1_item_free((ASN1_VALUE *)val_00,(ASN1_ITEM *)PTR_GENERAL_SUBTREE_it_000d5b38);
          val_00 = (_STACK **)0x0;
        }
        return val_00;
      }
      pGVar1 = v2i_GENERAL_NAME_ex((GENERAL_NAME *)*val_00,param_1,param_2,&CStack_34,1);
      if (pGVar1 == (GENERAL_NAME *)0x0) goto LAB_000d5ad4;
      st = *pp_Var5;
      if (st == (_STACK *)0x0) {
        st = sk_new_null();
        *pp_Var5 = st;
        if (st == (_STACK *)0x0) goto LAB_000d5b00;
      }
      iVar2 = sk_push(st,val_00);
      if (iVar2 == 0) goto LAB_000d5b00;
    }
  }
  return val;
}

