
int X509_NAME_get_index_by_NID(X509_NAME *name,int nid,int lastpos)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  stack_st_X509_NAME_ENTRY *psVar6;
  
  iVar1 = (*(code *)PTR_OBJ_nid2obj_006a7140)(nid);
  if (iVar1 == 0) {
    iVar3 = -2;
  }
  else if (name == (X509_NAME *)0x0) {
    iVar3 = -1;
  }
  else {
    if (lastpos < 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = lastpos + 1;
    }
    psVar6 = name->entries;
    iVar2 = (*(code *)PTR_sk_num_006a6e2c)(psVar6);
    if (iVar5 < iVar2) {
      do {
        puVar4 = (undefined4 *)(*(code *)PTR_sk_value_006a6e24)(psVar6,iVar5);
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
  return iVar3;
}

