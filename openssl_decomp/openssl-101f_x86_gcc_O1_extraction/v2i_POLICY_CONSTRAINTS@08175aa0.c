
ASN1_INTEGER ** v2i_POLICY_CONSTRAINTS(undefined4 param_1,undefined4 param_2,_STACK *param_3)

{
  CONF_VALUE *pCVar1;
  int iVar2;
  int iVar3;
  CONF_VALUE *pCVar4;
  char *pcVar5;
  byte *pbVar6;
  undefined uVar7;
  undefined uVar8;
  bool bVar9;
  byte bVar10;
  undefined auStack_2c [4];
  CONF_VALUE *local_28;
  ASN1_INTEGER **local_24;
  ASN1_INTEGER **local_20;
  
  bVar10 = 0;
  local_20 = (ASN1_INTEGER **)ASN1_item_new((ASN1_ITEM *)POLICY_CONSTRAINTS_it);
  if (local_20 == (ASN1_INTEGER **)0x0) {
    ERR_put_error(0x22,0x92,0x41,"v3_pcons.c",0x71);
    local_20 = (ASN1_INTEGER **)0x0;
  }
  else {
    local_24 = local_20 + 1;
    for (iVar3 = 0; iVar2 = sk_num(param_3), iVar3 < iVar2; iVar3 = iVar3 + 1) {
      uVar7 = auStack_2c < &DAT_00000008;
      uVar8 = &stack0x00000000 == (undefined *)0x34;
      local_28 = (CONF_VALUE *)sk_value(param_3,iVar3);
      pCVar1 = (CONF_VALUE *)local_28->name;
      iVar2 = 0x16;
      pCVar4 = pCVar1;
      pbVar6 = (byte *)"requireExplicitPolicy";
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        uVar7 = *(byte *)&pCVar4->section < *pbVar6;
        uVar8 = *(byte *)&pCVar4->section == *pbVar6;
        pCVar4 = (CONF_VALUE *)((int)pCVar4 + (uint)bVar10 * -2 + 1);
        pbVar6 = pbVar6 + (uint)bVar10 * -2 + 1;
      } while ((bool)uVar8);
      bVar9 = (!(bool)uVar7 && !(bool)uVar8) == (bool)uVar7;
      if (bVar9) {
        pCVar4 = local_28;
        local_28 = pCVar1;
        iVar2 = X509V3_get_value_int(pCVar4,local_20);
      }
      else {
        iVar2 = 0x15;
        pCVar4 = pCVar1;
        pcVar5 = "inhibitPolicyMapping";
        do {
          if (iVar2 == 0) break;
          iVar2 = iVar2 + -1;
          bVar9 = *(char *)&pCVar4->section == *pcVar5;
          pCVar4 = (CONF_VALUE *)((int)pCVar4 + (uint)bVar10 * -2 + 1);
          pcVar5 = pcVar5 + (uint)bVar10 * -2 + 1;
        } while (bVar9);
        if (!bVar9) {
          ERR_put_error(0x22,0x92,0x6a,"v3_pcons.c",0x7d);
          ERR_add_error_data(6,"section:",local_28->section,",name:",local_28->name,",value:",
                             local_28->value);
          goto LAB_08175b58;
        }
        pCVar4 = local_28;
        local_28 = pCVar1;
        iVar2 = X509V3_get_value_int(pCVar4,local_24);
      }
      if (iVar2 == 0) goto LAB_08175b58;
    }
    if ((local_20[1] == (ASN1_INTEGER *)0x0) && (*local_20 == (ASN1_INTEGER *)0x0)) {
      ERR_put_error(0x22,0x92,0x97,"v3_pcons.c",0x83);
LAB_08175b58:
      ASN1_item_free((ASN1_VALUE *)local_20,(ASN1_ITEM *)POLICY_CONSTRAINTS_it);
      local_20 = (ASN1_INTEGER **)0x0;
    }
  }
  return local_20;
}

