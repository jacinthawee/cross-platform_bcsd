
int X509at_get_attr_by_NID(stack_st_X509_ATTRIBUTE *x,int nid,int lastpos)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  
  iVar1 = (*(code *)PTR_OBJ_nid2obj_006a7140)(nid);
  if (iVar1 == 0) {
    iVar3 = -2;
  }
  else {
    iVar5 = lastpos + 1;
    if (x == (stack_st_X509_ATTRIBUTE *)0x0) {
      iVar3 = -1;
    }
    else {
      if (iVar5 < 0) {
        iVar5 = 0;
      }
      iVar2 = (*(code *)PTR_sk_num_006a6e2c)(x);
      if (iVar5 < iVar2) {
        do {
          puVar4 = (undefined4 *)(*(code *)PTR_sk_value_006a6e24)(x,iVar5);
          iVar3 = (*(code *)PTR_OBJ_cmp_006a8cc4)(*puVar4,iVar1);
          if (iVar3 == 0) {
            return iVar5;
          }
          iVar5 = iVar5 + 1;
          iVar3 = -1;
        } while (iVar2 != iVar5);
      }
      else {
        iVar3 = -1;
      }
    }
  }
  return iVar3;
}
