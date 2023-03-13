
int parse_name(char *param_1,undefined4 param_2,int param_3)

{
  undefined *puVar1;
  int iVar2;
  char *pcVar3;
  char **ppcVar4;
  char **ppcVar5;
  undefined4 *puVar6;
  char *pcVar7;
  char *pcVar8;
  int iVar9;
  int iVar10;
  char cVar11;
  char *pcVar12;
  char *pcVar13;
  char **ppcVar14;
  char **ppcVar15;
  undefined4 *puVar16;
  int iVar17;
  undefined4 *local_38;
  
  iVar2 = (*(code *)PTR_strlen_006a9a24)();
  pcVar3 = (char *)(*(code *)PTR_CRYPTO_malloc_006a7008)(iVar2 + 1U,"apps.c",0x7ee);
  iVar2 = ((iVar2 + 1U >> 1) + 1) * 4;
  ppcVar4 = (char **)(*(code *)PTR_CRYPTO_malloc_006a7008)(iVar2,"apps.c",0x7f0);
  ppcVar5 = (char **)(*(code *)PTR_CRYPTO_malloc_006a7008)(iVar2,"apps.c",0x7f1);
  puVar6 = (undefined4 *)(*(code *)PTR_CRYPTO_malloc_006a7008)(iVar2,"apps.c",0x7f2);
  if (pcVar3 == (char *)0x0) {
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)PTR_bio_err_006a6e3c,"malloc error\n");
    (*(code *)PTR_X509_NAME_free_006a6ff8)(0);
    if (ppcVar5 != (char **)0x0) goto LAB_0045d820;
LAB_0045d82c:
    if (ppcVar4 == (char **)0x0) goto LAB_0045d844;
  }
  else {
    if (ppcVar4 == (char **)0x0) {
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)PTR_bio_err_006a6e3c,"malloc error\n");
      (*(code *)PTR_X509_NAME_free_006a6ff8)(0);
      if (ppcVar5 == (char **)0x0) goto LAB_0045d844;
LAB_0045d820:
      (*(code *)PTR_CRYPTO_free_006a6e88)(ppcVar5);
      goto LAB_0045d82c;
    }
    if (ppcVar5 != (char **)0x0) {
      if (puVar6 != (undefined4 *)0x0) {
        if (*param_1 == '/') {
          *puVar6 = 0;
          pcVar12 = param_1 + 1;
          if (param_1[1] != '\0') {
            iVar2 = 0;
            pcVar8 = pcVar3;
            ppcVar14 = ppcVar4;
            ppcVar15 = ppcVar5;
            puVar16 = puVar6;
LAB_0045d8dc:
            puVar16 = puVar16 + 1;
            *ppcVar14 = pcVar8;
            cVar11 = *pcVar12;
            if (cVar11 != '\0') {
              do {
                pcVar7 = pcVar8 + 1;
                if (cVar11 == '\\') {
                  cVar11 = pcVar12[1];
                  pcVar12 = pcVar12 + 2;
                  if (cVar11 == '\0') goto LAB_0045d94c;
                }
                else {
                  if (cVar11 == '=') goto LAB_0045d95c;
                  pcVar12 = pcVar12 + 1;
                }
                *pcVar8 = cVar11;
                cVar11 = *pcVar12;
                pcVar8 = pcVar7;
                if (cVar11 == '\0') break;
              } while( true );
            }
            goto LAB_0045d918;
          }
          iVar9 = (*(code *)PTR_X509_NAME_new_006a7138)();
          if (iVar9 != 0) goto LAB_0045dc54;
        }
        else {
          pcVar12 = "Subject does not start with \'/\'.\n";
LAB_0045d7f8:
          (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)PTR_bio_err_006a6e3c,pcVar12);
        }
        goto LAB_0045d80c;
      }
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)PTR_bio_err_006a6e3c,"malloc error\n");
      (*(code *)PTR_X509_NAME_free_006a6ff8)(0);
      goto LAB_0045d820;
    }
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)PTR_bio_err_006a6e3c,"malloc error\n");
    (*(code *)PTR_X509_NAME_free_006a6ff8)(0);
  }
  (*(code *)PTR_CRYPTO_free_006a6e88)(ppcVar4);
LAB_0045d844:
  if (puVar6 != (undefined4 *)0x0) {
    (*(code *)PTR_CRYPTO_free_006a6e88)(puVar6);
  }
  if (pcVar3 != (char *)0x0) {
    (*(code *)PTR_CRYPTO_free_006a6e88)(pcVar3);
    return 0;
  }
  return 0;
LAB_0045d95c:
  *pcVar8 = '\0';
  pcVar13 = pcVar12 + 1;
  pcVar12 = pcVar12 + 1;
  if (*pcVar13 == '\0') {
LAB_0045d918:
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)PTR_bio_err_006a6e3c,
               "end of string encountered while processing type of subject name element #%d\n",iVar2
              );
    goto LAB_0045d80c;
  }
  *ppcVar15 = pcVar7;
  pcVar8 = pcVar8 + 2;
  if (param_3 == 0) {
    cVar11 = *pcVar12;
    while (pcVar13 = pcVar8, cVar11 != '\0') {
      if (cVar11 != '\\') {
        if (cVar11 != '/') {
          pcVar13[-1] = cVar11;
          pcVar12 = pcVar12 + 1;
          goto LAB_0045d9a4;
        }
        pcVar13 = pcVar12 + 1;
LAB_0045db38:
        *puVar16 = 0;
        pcVar12 = pcVar13;
        break;
      }
      pcVar8 = pcVar12 + 1;
      pcVar12 = pcVar12 + 2;
      if (*pcVar8 == '\0') goto LAB_0045d94c;
      pcVar13[-1] = *pcVar8;
LAB_0045d9a4:
      pcVar8 = pcVar13 + 1;
      pcVar7 = pcVar13;
      cVar11 = *pcVar12;
    }
  }
  else {
    while( true ) {
      cVar11 = *pcVar12;
      pcVar7 = pcVar8 + -1;
      if (cVar11 == '\0') break;
      if (cVar11 == '\\') {
        pcVar7 = pcVar12 + 1;
        pcVar12 = pcVar12 + 2;
        if (*pcVar7 == '\0') goto LAB_0045d94c;
        pcVar8[-1] = *pcVar7;
        pcVar8 = pcVar8 + 1;
      }
      else {
        pcVar13 = pcVar12 + 1;
        if (cVar11 == '/') goto LAB_0045db38;
        pcVar12 = pcVar12 + 1;
        if (cVar11 == '+') {
          *puVar16 = 0xffffffff;
          pcVar12 = pcVar13;
          break;
        }
        pcVar8[-1] = cVar11;
        pcVar8 = pcVar8 + 1;
      }
    }
  }
  *pcVar7 = '\0';
  pcVar8 = pcVar7 + 1;
  iVar2 = iVar2 + 1;
  ppcVar14 = ppcVar14 + 1;
  ppcVar15 = ppcVar15 + 1;
  if (*pcVar12 == '\0') goto code_r0x0045d9d4;
  goto LAB_0045d8dc;
LAB_0045d94c:
  pcVar12 = "escape character at end of string\n";
  goto LAB_0045d7f8;
code_r0x0045d9d4:
  iVar9 = (*(code *)PTR_X509_NAME_new_006a7138)();
  puVar1 = PTR_bio_err_006a6e3c;
  if (iVar9 != 0) {
    iVar17 = 0;
    ppcVar14 = ppcVar5;
    ppcVar15 = ppcVar4;
    local_38 = puVar6;
    do {
      iVar10 = (*(code *)PTR_OBJ_txt2nid_006a6f5c)(*ppcVar15);
      if (iVar10 == 0) {
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar1,"Subject Attribute %s has no known NID, skipped\n",
                   *ppcVar15);
      }
      else {
        pcVar12 = *ppcVar14;
        if (*pcVar12 == '\0') {
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*(undefined4 *)puVar1,"No value provided for Subject Attribute %s, skipped\n",
                     *ppcVar15,pcVar12);
        }
        else {
          iVar10 = (*(code *)PTR_X509_NAME_add_entry_by_NID_006a6f78)
                             (iVar9,iVar10,param_2,pcVar12,0xffffffff,0xffffffff,*local_38);
          if (iVar10 == 0) goto LAB_0045d810;
        }
      }
      iVar17 = iVar17 + 1;
      ppcVar15 = ppcVar15 + 1;
      ppcVar14 = ppcVar14 + 1;
      local_38 = local_38 + 1;
    } while (iVar2 != iVar17);
LAB_0045dc54:
    (*(code *)PTR_CRYPTO_free_006a6e88)(ppcVar5);
    (*(code *)PTR_CRYPTO_free_006a6e88)(ppcVar4);
    (*(code *)PTR_CRYPTO_free_006a6e88)(pcVar3);
    (*(code *)PTR_CRYPTO_free_006a6e88)(puVar6);
    return iVar9;
  }
LAB_0045d80c:
  iVar9 = 0;
LAB_0045d810:
  (*(code *)PTR_X509_NAME_free_006a6ff8)(iVar9);
  goto LAB_0045d820;
}

