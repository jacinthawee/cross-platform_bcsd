
int X509_NAME_get_text_by_NID(X509_NAME *name,int nid,char *buf,int len)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  int iVar8;
  stack_st_X509_NAME_ENTRY *psVar9;
  
  pcVar6 = buf;
  iVar8 = len;
  iVar1 = (*(code *)PTR_OBJ_nid2obj_006a8240)(nid);
  if ((iVar1 != 0) && (name != (X509_NAME *)0x0)) {
    psVar9 = name->entries;
    iVar2 = (*(code *)PTR_sk_num_006a7f2c)(psVar9);
    if (0 < iVar2) {
      iVar7 = 0;
      while( true ) {
        puVar3 = (undefined4 *)(*(code *)PTR_sk_value_006a7f24)(psVar9,iVar7);
        iVar5 = iVar1;
        iVar4 = (*(code *)PTR_OBJ_cmp_006a9de4)(*puVar3,iVar1);
        if (iVar4 == 0) break;
        iVar7 = iVar7 + 1;
        if (iVar2 == iVar7) {
          return -1;
        }
      }
      if (-1 < iVar7) {
        psVar9 = name->entries;
        iVar1 = (*(code *)PTR_sk_num_006a7f2c)();
        if (iVar7 < iVar1) {
          psVar9 = name->entries;
          iVar1 = (*(code *)PTR_sk_value_006a7f24)(psVar9,iVar7);
          iVar5 = iVar7;
          if (iVar1 != 0) {
            iVar2 = **(int **)(iVar1 + 4);
            iVar8 = iVar2;
            if (len <= iVar2) {
              iVar8 = len + -1;
            }
            if (buf == (char *)0x0) {
              return iVar2;
            }
            (*(code *)PTR_memcpy_006aabf4)(buf,(*(int **)(iVar1 + 4))[2],iVar8);
            buf[iVar8] = '\0';
            return iVar8;
          }
        }
        trap(0);
        if (psVar9 == (stack_st_X509_NAME_ENTRY *)0x0) {
          return -1;
        }
        iVar2 = (psVar9->stack).num;
        iVar1 = (*(code *)PTR_sk_num_006a7f2c)(iVar2);
        if (0 < iVar1) {
          iVar7 = 0;
          while( true ) {
            puVar3 = (undefined4 *)(*(code *)PTR_sk_value_006a7f24)(iVar2,iVar7);
            iVar4 = (*(code *)PTR_OBJ_cmp_006a9de4)(*puVar3,iVar5);
            if (iVar4 == 0) break;
            iVar7 = iVar7 + 1;
            if (iVar1 == iVar7) {
              return -1;
            }
          }
          if (-1 < iVar7) {
            iVar1 = (*(code *)PTR_sk_num_006a7f2c)((psVar9->stack).num);
            if ((iVar1 <= iVar7) ||
               (iVar1 = (*(code *)PTR_sk_value_006a7f24)((psVar9->stack).num,iVar7), iVar1 == 0)) {
              trap(0);
              return -1;
            }
            iVar7 = **(int **)(iVar1 + 4);
            iVar2 = iVar7;
            if (iVar8 <= iVar7) {
              iVar2 = iVar8 + -1;
            }
            if (pcVar6 == (char *)0x0) {
              return iVar7;
            }
            (*(code *)PTR_memcpy_006aabf4)(pcVar6,(*(int **)(iVar1 + 4))[2],iVar2);
            pcVar6[iVar2] = '\0';
            return iVar2;
          }
        }
        return -1;
      }
    }
  }
  return -1;
}

