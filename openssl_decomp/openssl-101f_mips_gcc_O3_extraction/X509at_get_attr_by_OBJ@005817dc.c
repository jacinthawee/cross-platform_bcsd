
int X509at_get_attr_by_OBJ(stack_st_X509_ATTRIBUTE *sk,ASN1_OBJECT *obj,int lastpos)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  
  if (sk == (stack_st_X509_ATTRIBUTE *)0x0) {
    return -1;
  }
  iVar4 = lastpos + 1;
  if (iVar4 < 0) {
    iVar4 = 0;
  }
  iVar1 = (*(code *)PTR_sk_num_006a7f2c)();
  if (iVar4 < iVar1) {
    do {
      puVar2 = (undefined4 *)(*(code *)PTR_sk_value_006a7f24)(sk,iVar4);
      iVar3 = (*(code *)PTR_OBJ_cmp_006a9de4)(*puVar2,obj);
      if (iVar3 == 0) {
        return iVar4;
      }
      iVar4 = iVar4 + 1;
    } while (iVar1 != iVar4);
  }
  return -1;
}
