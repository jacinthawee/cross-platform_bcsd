
long TXT_DB_write(BIO *out,TXT_DB *db)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  char **ppcVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  char cVar8;
  char *pcVar9;
  int iVar10;
  char **ppcVar11;
  char **ppcVar12;
  int iVar13;
  long local_38;
  
  iVar2 = (*(code *)PTR_BUF_MEM_new_006a859c)();
  if (iVar2 == 0) {
    local_38 = -1;
  }
  else {
    iVar3 = (*(code *)PTR_sk_num_006a7f2c)(db->data);
    iVar7 = db->num_fields;
    if (iVar3 < 1) {
      local_38 = 0;
    }
    else {
      local_38 = 0;
      iVar10 = 0;
      do {
        ppcVar4 = (char **)(*(code *)PTR_sk_value_006a7f24)(db->data,iVar10);
        if (iVar7 < 1) {
          iVar13 = (*(code *)PTR_BUF_MEM_grow_clean_006a8c2c)(iVar2,iVar7);
          if (iVar13 != 0) {
            pcVar5 = *(char **)(iVar2 + 4);
            goto LAB_005a1a1c;
          }
LAB_005a1ac0:
          local_38 = -1;
          break;
        }
        iVar13 = 0;
        ppcVar12 = ppcVar4 + iVar7;
        ppcVar11 = ppcVar4;
        do {
          pcVar5 = *ppcVar11;
          ppcVar11 = ppcVar11 + 1;
          if (pcVar5 != (char *)0x0) {
            iVar6 = (*(code *)PTR_strlen_006aab30)(pcVar5);
            iVar13 = iVar13 + iVar6;
          }
        } while (ppcVar12 != ppcVar11);
        iVar13 = (*(code *)PTR_BUF_MEM_grow_clean_006a8c2c)(iVar2,iVar13 * 2 + iVar7);
        if (iVar13 == 0) goto LAB_005a1ac0;
        pcVar5 = *(char **)(iVar2 + 4);
        do {
          pcVar9 = *ppcVar4;
          if (pcVar9 != (char *)0x0) {
            for (; cVar8 = *pcVar9, cVar8 != '\0'; pcVar9 = pcVar9 + 1) {
              if (cVar8 == '\t') {
                *pcVar5 = '\\';
                pcVar5 = pcVar5 + 1;
                cVar8 = *pcVar9;
              }
              *pcVar5 = cVar8;
              pcVar5 = pcVar5 + 1;
            }
          }
          ppcVar4 = ppcVar4 + 1;
          *pcVar5 = '\t';
          pcVar5 = pcVar5 + 1;
        } while (ppcVar12 != ppcVar4);
LAB_005a1a1c:
        puVar1 = PTR_BIO_write_006a7f14;
        pcVar5[-1] = '\n';
        iVar6 = (int)pcVar5 - *(int *)(iVar2 + 4);
        iVar13 = (*(code *)puVar1)(out,*(int *)(iVar2 + 4),iVar6);
        if (iVar6 != iVar13) goto LAB_005a1ac0;
        iVar10 = iVar10 + 1;
        local_38 = local_38 + iVar6;
      } while (iVar3 != iVar10);
    }
    (*(code *)PTR_BUF_MEM_free_006a8594)(iVar2);
  }
  return local_38;
}

