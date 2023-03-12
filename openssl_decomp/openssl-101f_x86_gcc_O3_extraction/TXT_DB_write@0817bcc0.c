
long TXT_DB_write(BIO *out,TXT_DB *db)

{
  char **ppcVar1;
  size_t len;
  char cVar2;
  BUF_MEM *str;
  int iVar3;
  char **ppcVar4;
  size_t sVar5;
  char *pcVar6;
  char *pcVar7;
  char **ppcVar8;
  char *pcVar9;
  int iVar10;
  int len_00;
  int local_34;
  int local_28;
  
  str = BUF_MEM_new();
  if (str == (BUF_MEM *)0x0) {
    local_28 = -1;
  }
  else {
    iVar3 = sk_num((_STACK *)db->data);
    len = db->num_fields;
    if (iVar3 < 1) {
      local_28 = 0;
    }
    else {
      local_28 = 0;
      local_34 = 0;
      do {
        ppcVar4 = (char **)sk_value((_STACK *)db->data,local_34);
        if ((int)len < 1) {
          iVar10 = BUF_MEM_grow_clean(str,len);
          if (iVar10 != 0) {
            pcVar7 = str->data;
            goto LAB_0817bdea;
          }
LAB_0817be78:
          local_28 = -1;
          break;
        }
        iVar10 = 0;
        ppcVar1 = ppcVar4 + len;
        ppcVar8 = ppcVar4;
        do {
          if (*ppcVar8 != (char *)0x0) {
            sVar5 = strlen(*ppcVar8);
            iVar10 = iVar10 + sVar5;
          }
          ppcVar8 = ppcVar8 + 1;
        } while (ppcVar1 != ppcVar8);
        iVar10 = BUF_MEM_grow_clean(str,len + iVar10 * 2);
        if (iVar10 == 0) goto LAB_0817be78;
        pcVar9 = str->data;
        do {
          while (pcVar7 = *ppcVar4, pcVar7 != (char *)0x0) {
            cVar2 = *pcVar7;
            while (cVar2 != '\0') {
              while (cVar2 != '\t') {
                pcVar7 = pcVar7 + 1;
                *pcVar9 = cVar2;
                pcVar9 = pcVar9 + 1;
                cVar2 = *pcVar7;
                if (cVar2 == '\0') goto LAB_0817bddd;
              }
              *pcVar9 = '\\';
              cVar2 = *pcVar7;
              pcVar6 = pcVar9 + 1;
              pcVar7 = pcVar7 + 1;
              pcVar9 = pcVar9 + 2;
              *pcVar6 = cVar2;
              cVar2 = *pcVar7;
            }
LAB_0817bddd:
            ppcVar4 = ppcVar4 + 1;
            pcVar7 = pcVar9 + 1;
            *pcVar9 = '\t';
            pcVar9 = pcVar7;
            if (ppcVar1 == ppcVar4) goto LAB_0817bdea;
          }
          ppcVar4 = ppcVar4 + 1;
          pcVar7 = pcVar9 + 1;
          *pcVar9 = '\t';
          pcVar9 = pcVar7;
        } while (ppcVar1 != ppcVar4);
LAB_0817bdea:
        pcVar7[-1] = '\n';
        len_00 = (int)pcVar7 - (int)str->data;
        iVar10 = BIO_write(out,str->data,len_00);
        if (len_00 != iVar10) goto LAB_0817be78;
        local_34 = local_34 + 1;
        local_28 = local_28 + len_00;
      } while (iVar3 != local_34);
    }
    BUF_MEM_free(str);
  }
  return local_28;
}

