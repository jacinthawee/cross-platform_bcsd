
undefined4 policy_cache_set_mapping(int param_1,_STACK *param_2)

{
  uint **ppuVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  ASN1_OBJECT **ppAVar5;
  uint *data;
  undefined4 uVar6;
  
  ppuVar1 = *(uint ***)(param_1 + 0x40);
  iVar3 = sk_num(param_2);
  if (iVar3 == 0) {
LAB_08177720:
    uVar6 = 0xffffffff;
    *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x28) | 0x800;
  }
  else {
    iVar3 = 0;
    while( true ) {
      iVar4 = sk_num(param_2);
      if (iVar4 <= iVar3) break;
      ppAVar5 = (ASN1_OBJECT **)sk_value(param_2,iVar3);
      iVar4 = OBJ_obj2nid(ppAVar5[1]);
      if (iVar4 == 0x2ea) goto LAB_08177720;
      iVar4 = OBJ_obj2nid(*ppAVar5);
      if (iVar4 == 0x2ea) goto LAB_08177720;
      data = (uint *)policy_cache_find_data(ppuVar1,*ppAVar5);
      if (data == (uint *)0x0) {
        if (*ppuVar1 != (uint *)0x0) {
          data = (uint *)policy_data_new(0,*ppAVar5,**ppuVar1 & 0x10);
          if (data == (uint *)0x0) goto LAB_08177760;
          uVar2 = (*ppuVar1)[2];
          *data = *data | 6;
          data[2] = uVar2;
          iVar4 = sk_push((_STACK *)ppuVar1[1],data);
          if (iVar4 != 0) goto LAB_08177633;
          uVar6 = 0;
          policy_data_free(data);
          goto LAB_08177730;
        }
      }
      else {
        *data = *data | 1;
LAB_08177633:
        iVar4 = sk_push((_STACK *)data[3],ppAVar5[1]);
        if (iVar4 == 0) {
LAB_08177760:
          uVar6 = 0;
          goto LAB_08177730;
        }
        ppAVar5[1] = (ASN1_OBJECT *)0x0;
      }
      iVar3 = iVar3 + 1;
    }
    uVar6 = 1;
  }
LAB_08177730:
  sk_pop_free(param_2,POLICY_MAPPING_free);
  return uVar6;
}

