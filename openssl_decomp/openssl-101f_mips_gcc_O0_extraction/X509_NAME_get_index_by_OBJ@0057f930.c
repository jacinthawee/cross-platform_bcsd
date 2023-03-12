
int X509_NAME_get_index_by_OBJ(X509_NAME *name,ASN1_OBJECT *obj,int lastpos)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  stack_st_X509_NAME_ENTRY *psVar5;
  
  if (name == (X509_NAME *)0x0) {
    return -1;
  }
  if (lastpos < 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = lastpos + 1;
  }
  psVar5 = name->entries;
  iVar1 = (*(code *)PTR_sk_num_006a7f2c)(psVar5);
  if (iVar4 < iVar1) {
    do {
      puVar2 = (undefined4 *)(*(code *)PTR_sk_value_006a7f24)(psVar5,iVar4);
      iVar3 = (*(code *)PTR_OBJ_cmp_006a9de4)(*puVar2,obj);
      if (iVar3 == 0) {
        return iVar4;
      }
      iVar4 = iVar4 + 1;
    } while (iVar1 != iVar4);
  }
  return -1;
}

