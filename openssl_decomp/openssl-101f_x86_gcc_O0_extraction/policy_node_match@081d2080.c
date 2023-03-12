
bool policy_node_match(int param_1,byte **param_2,ASN1_OBJECT *param_3)

{
  byte *pbVar1;
  ASN1_OBJECT *a;
  int iVar2;
  int iVar3;
  
  pbVar1 = *param_2;
  if (((*(byte *)(param_1 + 0xd) & 4) == 0) && (iVar3 = 0, (*pbVar1 & 3) != 0)) {
    while( true ) {
      iVar2 = sk_num(*(_STACK **)(pbVar1 + 0xc));
      if (iVar2 <= iVar3) {
        return false;
      }
      a = (ASN1_OBJECT *)sk_value(*(_STACK **)(pbVar1 + 0xc),iVar3);
      iVar2 = OBJ_cmp(a,param_3);
      if (iVar2 == 0) break;
      iVar3 = iVar3 + 1;
    }
    return true;
  }
  iVar3 = OBJ_cmp(*(ASN1_OBJECT **)(pbVar1 + 4),param_3);
  return iVar3 == 0;
}

