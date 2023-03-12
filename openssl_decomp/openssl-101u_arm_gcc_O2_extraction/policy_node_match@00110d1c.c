
uint policy_node_match(int param_1,uint **param_2,ASN1_OBJECT *param_3)

{
  int iVar1;
  ASN1_OBJECT *a;
  uint uVar2;
  uint *puVar3;
  
  puVar3 = *param_2;
  uVar2 = *(uint *)(param_1 + 0xc) & 0x400;
  if ((uVar2 == 0) && ((*puVar3 & 3) != 0)) {
    do {
      iVar1 = sk_num((_STACK *)puVar3[3]);
      if (iVar1 <= (int)uVar2) {
        return 0;
      }
      a = (ASN1_OBJECT *)sk_value((_STACK *)puVar3[3],uVar2);
      iVar1 = OBJ_cmp(a,param_3);
      uVar2 = uVar2 + 1;
    } while (iVar1 != 0);
    return 1;
  }
  iVar1 = OBJ_cmp((ASN1_OBJECT *)puVar3[1],param_3);
  uVar2 = count_leading_zeroes(iVar1);
  return uVar2 >> 5;
}

