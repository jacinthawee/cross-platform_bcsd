
_STACK ** v2i_NAME_CONSTRAINTS(X509V3_EXT_METHOD *param_1,X509V3_CTX *param_2,_STACK *param_3)

{
  byte *pbVar1;
  GENERAL_NAME **val;
  GENERAL_NAME *pGVar2;
  int iVar3;
  _STACK *st;
  int iVar4;
  _STACK **pp_Var5;
  byte *pbVar6;
  byte *pbVar7;
  int in_GS_OFFSET;
  undefined uVar8;
  undefined uVar9;
  bool bVar10;
  byte bVar11;
  void *local_3c;
  _STACK **local_38;
  X509V3_EXT_METHOD *local_34;
  X509V3_CTX *local_30;
  CONF_VALUE local_2c;
  int local_20;
  
  bVar11 = 0;
  local_34 = param_1;
  local_30 = param_2;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_38 = (_STACK **)ASN1_item_new((ASN1_ITEM *)NAME_CONSTRAINTS_it);
  if (local_38 == (_STACK **)0x0) {
    ERR_put_error(0x22,0x93,0x41,"v3_ncons.c",0x95);
    pp_Var5 = (_STACK **)0x0;
  }
  else {
    for (iVar4 = 0; iVar3 = sk_num(param_3), pp_Var5 = local_38, iVar4 < iVar3; iVar4 = iVar4 + 1) {
      uVar8 = &local_3c < &DAT_00000008;
      uVar9 = &stack0x00000000 == (undefined *)0x44;
      local_3c = sk_value(param_3,iVar4);
      pbVar1 = *(byte **)((int)local_3c + 4);
      iVar3 = 9;
      pbVar6 = pbVar1;
      pbVar7 = (byte *)"permitted";
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        uVar8 = *pbVar6 < *pbVar7;
        uVar9 = *pbVar6 == *pbVar7;
        pbVar6 = pbVar6 + (uint)bVar11 * -2 + 1;
        pbVar7 = pbVar7 + (uint)bVar11 * -2 + 1;
      } while ((bool)uVar9);
      bVar10 = (!(bool)uVar8 && !(bool)uVar9) == (bool)uVar8;
      if ((!bVar10) || (bVar10 = pbVar1[9] == 0, bVar10)) {
        iVar3 = 8;
        pbVar6 = pbVar1;
        pbVar7 = (byte *)"excluded";
        do {
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          bVar10 = *pbVar6 == *pbVar7;
          pbVar6 = pbVar6 + (uint)bVar11 * -2 + 1;
          pbVar7 = pbVar7 + (uint)bVar11 * -2 + 1;
        } while (bVar10);
        if ((bVar10) && (pbVar1[8] != 0)) {
          local_2c.name = (char *)(pbVar1 + 9);
          pp_Var5 = local_38 + 1;
          goto LAB_08173e75;
        }
        val = (GENERAL_NAME **)0x0;
        ERR_put_error(0x22,0x93,0x8f,"v3_ncons.c",0x82);
LAB_08173f73:
        ASN1_item_free((ASN1_VALUE *)local_38,(ASN1_ITEM *)NAME_CONSTRAINTS_it);
        pp_Var5 = (_STACK **)0x0;
        if (val != (GENERAL_NAME **)0x0) {
          ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)GENERAL_SUBTREE_it);
        }
        break;
      }
      local_2c.name = (char *)(pbVar1 + 10);
      pp_Var5 = local_38;
LAB_08173e75:
      local_2c.value = *(char **)((int)local_3c + 8);
      val = (GENERAL_NAME **)ASN1_item_new((ASN1_ITEM *)GENERAL_SUBTREE_it);
      if (val == (GENERAL_NAME **)0x0) {
LAB_08173fc7:
        ERR_put_error(0x22,0x93,0x41,"v3_ncons.c",0x95);
        goto LAB_08173f73;
      }
      pGVar2 = v2i_GENERAL_NAME_ex(*val,local_34,local_30,&local_2c,1);
      if (pGVar2 == (GENERAL_NAME *)0x0) goto LAB_08173f73;
      st = *pp_Var5;
      if (st == (_STACK *)0x0) {
        st = sk_new_null();
        *pp_Var5 = st;
        if (st == (_STACK *)0x0) goto LAB_08173fc7;
      }
      iVar3 = sk_push(st,val);
      if (iVar3 == 0) goto LAB_08173fc7;
    }
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return pp_Var5;
}

