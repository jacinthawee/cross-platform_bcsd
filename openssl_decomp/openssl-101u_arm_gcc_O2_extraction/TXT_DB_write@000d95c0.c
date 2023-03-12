
long TXT_DB_write(BIO *out,TXT_DB *db)

{
  BUF_MEM *str;
  int iVar1;
  char **ppcVar2;
  size_t sVar3;
  char *pcVar4;
  char cVar5;
  size_t len;
  char *pcVar6;
  char *pcVar7;
  int iVar8;
  char *pcVar9;
  int len_00;
  char **ppcVar10;
  char **ppcVar11;
  int iVar12;
  long local_3c;
  
  str = BUF_MEM_new();
  if (str == (BUF_MEM *)0x0) {
    local_3c = -1;
  }
  else {
    iVar1 = sk_num((_STACK *)db->data);
    len = db->num_fields;
    local_3c = 0;
    if (0 < iVar1) {
      iVar8 = 0;
      do {
        ppcVar2 = (char **)sk_value((_STACK *)db->data,iVar8);
        if ((int)len < 1) {
          iVar12 = BUF_MEM_grow_clean(str,len);
          if (iVar12 != 0) goto LAB_000d963c;
LAB_000d96d0:
          local_3c = -1;
          break;
        }
        iVar12 = 0;
        ppcVar10 = ppcVar2;
        do {
          ppcVar11 = ppcVar10 + 1;
          if (*ppcVar10 != (char *)0x0) {
            sVar3 = strlen(*ppcVar10);
            iVar12 = iVar12 + sVar3;
          }
          ppcVar10 = ppcVar11;
        } while (ppcVar11 != ppcVar2 + len);
        iVar12 = BUF_MEM_grow_clean(str,iVar12 * 2 + len);
        if (iVar12 == 0) goto LAB_000d96d0;
LAB_000d963c:
        pcVar6 = str->data;
        if (0 < (int)len) {
          ppcVar10 = ppcVar2;
          do {
            while( true ) {
              ppcVar11 = ppcVar10 + 1;
              pcVar4 = *ppcVar10;
              ppcVar10 = ppcVar11;
              if ((pcVar4 == (char *)0x0) || (cVar5 = *pcVar4, pcVar9 = pcVar4, cVar5 == '\0'))
              break;
              do {
                if (cVar5 == '\t') {
                  *pcVar6 = '\\';
                }
                pcVar7 = pcVar6;
                if (cVar5 == '\t') {
                  pcVar7 = pcVar6 + 1;
                }
                pcVar6 = pcVar7 + 1;
                *pcVar7 = *pcVar4;
                cVar5 = pcVar9[1];
                pcVar4 = pcVar4 + 1;
                pcVar9 = pcVar9 + 1;
              } while (cVar5 != '\0');
              *pcVar6 = '\t';
              pcVar6 = pcVar7 + 2;
              if (ppcVar11 == ppcVar2 + len) goto LAB_000d967e;
            }
            *pcVar6 = '\t';
            pcVar6 = pcVar6 + 1;
          } while (ppcVar11 != ppcVar2 + len);
        }
LAB_000d967e:
        pcVar6[-1] = '\n';
        len_00 = (int)pcVar6 - (int)str->data;
        iVar12 = BIO_write(out,str->data,len_00);
        if (iVar12 != len_00) goto LAB_000d96d0;
        iVar8 = iVar8 + 1;
        local_3c = local_3c + iVar12;
      } while (iVar8 != iVar1);
    }
    BUF_MEM_free(str);
  }
  return local_3c;
}

