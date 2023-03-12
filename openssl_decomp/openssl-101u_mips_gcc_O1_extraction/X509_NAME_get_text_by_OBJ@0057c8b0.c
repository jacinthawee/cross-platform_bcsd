
int X509_NAME_get_text_by_OBJ(X509_NAME *name,ASN1_OBJECT *obj,char *buf,int len)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  stack_st_X509_NAME_ENTRY *psVar5;
  
  if (name == (X509_NAME *)0x0) {
    return -1;
  }
  psVar5 = name->entries;
  iVar1 = (*(code *)PTR_sk_num_006a6e2c)(psVar5);
  if (0 < iVar1) {
    iVar4 = 0;
    do {
      puVar2 = (undefined4 *)(*(code *)PTR_sk_value_006a6e24)(psVar5,iVar4);
      iVar3 = (*(code *)PTR_OBJ_cmp_006a8cc4)(*puVar2,obj);
      if (iVar3 == 0) {
        if (iVar4 < 0) {
          return -1;
        }
        iVar1 = (*(code *)PTR_sk_num_006a6e2c)(name->entries);
        if ((iVar4 < iVar1) &&
           (iVar1 = (*(code *)PTR_sk_value_006a6e24)(name->entries,iVar4), iVar1 != 0)) {
          iVar3 = **(int **)(iVar1 + 4);
          iVar4 = iVar3;
          if (len <= iVar3) {
            iVar4 = len + -1;
          }
          if (buf == (char *)0x0) {
            return iVar3;
          }
          (*(code *)PTR_memcpy_006a9aec)(buf,(*(int **)(iVar1 + 4))[2],iVar4);
          buf[iVar4] = '\0';
          return iVar4;
        }
        trap(0);
        return -1;
      }
      iVar4 = iVar4 + 1;
    } while (iVar1 != iVar4);
  }
  return -1;
}

