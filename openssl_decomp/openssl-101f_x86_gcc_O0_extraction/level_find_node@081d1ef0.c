
int * level_find_node(int param_1,int param_2,ASN1_OBJECT *param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = 0;
  while( true ) {
    iVar1 = sk_num(*(_STACK **)(param_1 + 4));
    if (iVar1 <= iVar3) {
      return (int *)0x0;
    }
    piVar2 = (int *)sk_value(*(_STACK **)(param_1 + 4),iVar3);
    if ((piVar2[1] == param_2) &&
       (iVar1 = OBJ_cmp(*(ASN1_OBJECT **)(*piVar2 + 4),param_3), iVar1 == 0)) break;
    iVar3 = iVar3 + 1;
  }
  return piVar2;
}
