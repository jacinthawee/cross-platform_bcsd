
int policy_cache_set_mapping(int param_1,_STACK *param_2)

{
  int iVar1;
  int iVar2;
  ASN1_OBJECT **ppAVar3;
  uint *data;
  _STACK *st;
  uint uVar4;
  uint **ppuVar5;
  
  ppuVar5 = *(uint ***)(param_1 + 0x40);
  iVar1 = sk_num(param_2);
  if (iVar1 == 0) {
LAB_000d6a74:
    iVar2 = -1;
    *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x28) | 0x800;
  }
  else {
    for (iVar1 = 0; iVar2 = sk_num(param_2), iVar1 < iVar2; iVar1 = iVar1 + 1) {
      ppAVar3 = (ASN1_OBJECT **)sk_value(param_2,iVar1);
      iVar2 = OBJ_obj2nid(ppAVar3[1]);
      if ((iVar2 == 0x2ea) || (iVar2 = OBJ_obj2nid(*ppAVar3), iVar2 == 0x2ea)) goto LAB_000d6a74;
      data = (uint *)policy_cache_find_data(ppuVar5,*ppAVar3);
      if (data == (uint *)0x0) {
        if (*ppuVar5 != (uint *)0x0) {
          data = (uint *)policy_data_new(0,*ppAVar3,**ppuVar5 & 0x10);
          if (data == (uint *)0x0) goto LAB_000d6a9c;
          st = (_STACK *)ppuVar5[1];
          uVar4 = (*ppuVar5)[2];
          *data = *data | 6;
          data[2] = uVar4;
          iVar2 = sk_push(st,data);
          if (iVar2 != 0) goto LAB_000d69e4;
          policy_data_free(data);
          goto LAB_000d6a84;
        }
      }
      else {
        *data = *data | 1;
LAB_000d69e4:
        iVar2 = sk_push((_STACK *)data[3],ppAVar3[1]);
        if (iVar2 == 0) {
LAB_000d6a9c:
          iVar2 = 0;
          goto LAB_000d6a84;
        }
        ppAVar3[1] = (ASN1_OBJECT *)0x0;
      }
    }
    iVar2 = 1;
  }
LAB_000d6a84:
  sk_pop_free(param_2,POLICY_MAPPING_free + 1);
  return iVar2;
}

