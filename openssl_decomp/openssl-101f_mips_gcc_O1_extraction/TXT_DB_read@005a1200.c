
/* WARNING: Removing unreachable block (ram,0x005a1418) */

TXT_DB * TXT_DB_read(BIO *in,int num)

{
  char cVar1;
  bool bVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  stack_st_OPENSSL_PSTRING *psVar6;
  lhash_st_OPENSSL_STRING **pplVar7;
  _func_4743 *p_Var8;
  int iVar9;
  int iVar10;
  undefined4 *puVar11;
  char *pcVar12;
  undefined4 *puVar13;
  TXT_DB *pTVar14;
  char *pcVar15;
  int iVar16;
  
  iVar4 = (*(code *)PTR_BUF_MEM_new_006a859c)();
  if (((iVar4 == 0) || (iVar5 = (*(code *)PTR_BUF_MEM_grow_006a85a0)(iVar4,0x200), iVar5 == 0)) ||
     (pTVar14 = (TXT_DB *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x20,"txt_db.c",0x57),
     puVar3 = PTR_sk_new_null_006a80a4, pTVar14 == (TXT_DB *)0x0)) {
    pTVar14 = (TXT_DB *)0x0;
  }
  else {
    pTVar14->num_fields = num;
    pTVar14->index = (lhash_st_OPENSSL_STRING **)0x0;
    pTVar14->qual = (_func_4743 *)0x0;
    psVar6 = (stack_st_OPENSSL_PSTRING *)(*(code *)puVar3)();
    pTVar14->data = psVar6;
    if (psVar6 != (stack_st_OPENSSL_PSTRING *)0x0) {
      pplVar7 = (lhash_st_OPENSSL_STRING **)
                (*(code *)PTR_CRYPTO_malloc_006a8108)(num << 2,"txt_db.c",0x5e);
      pTVar14->index = pplVar7;
      if (pplVar7 != (lhash_st_OPENSSL_STRING **)0x0) {
        p_Var8 = (_func_4743 *)(*(code *)PTR_CRYPTO_malloc_006a8108)(num << 2,"txt_db.c",0x60);
        pTVar14->qual = p_Var8;
        if (p_Var8 != (_func_4743 *)0x0) {
          iVar5 = 0;
          if (0 < num) {
            do {
              iVar9 = iVar5 + 1;
              pTVar14->index[iVar5] = (lhash_st_OPENSSL_STRING *)0x0;
              *(undefined4 *)(pTVar14->qual + iVar5 * 4) = 0;
              iVar5 = iVar9;
            } while (num != iVar9);
          }
          iVar16 = 0;
          iVar9 = 1;
          *(undefined *)(*(int *)(iVar4 + 4) + 0x1ff) = 0;
          iVar5 = 0x200;
LAB_005a14a0:
          puVar3 = PTR_BIO_gets_006a85d0;
          **(undefined **)(iVar4 + 4) = 0;
          (*(code *)puVar3)(in,*(undefined4 *)(iVar4 + 4),iVar5);
          pcVar12 = *(char **)(iVar4 + 4);
          if (*pcVar12 == '\0') {
LAB_005a15d0:
            (*(code *)PTR_BUF_MEM_free_006a8594)(iVar4);
            return pTVar14;
          }
          pcVar15 = pcVar12;
          if (*pcVar12 == '#') goto LAB_005a1498;
          do {
            iVar10 = (*(code *)PTR_strlen_006aab30)(pcVar12);
            puVar3 = PTR_CRYPTO_malloc_006a8108;
            iVar16 = iVar16 + iVar10;
            if (pcVar15[iVar16 + -1] == '\n') {
              pcVar15[iVar16 + -1] = '\0';
              puVar11 = (undefined4 *)(*(code *)puVar3)((num + 1) * 4 + iVar16,"txt_db.c",0x7e);
              if (puVar11 == (undefined4 *)0x0) break;
              puVar13 = puVar11 + num + 1;
              iVar16 = 1;
              bVar2 = false;
              *puVar11 = puVar13;
              pcVar12 = (char *)(*(int *)(iVar4 + 4) + 1);
              while( true ) {
                cVar1 = pcVar12[-1];
                pcVar15 = pcVar12 + -1;
                if (cVar1 == '\0') break;
                if (cVar1 == '\t') {
                  if (bVar2) {
                    puVar13 = (undefined4 *)((int)puVar13 + -1);
                    goto LAB_005a1534;
                  }
                  *(undefined *)puVar13 = 0;
                  puVar13 = (undefined4 *)((int)puVar13 + 1);
                  pcVar15 = pcVar12;
                  if (num <= iVar16) break;
                  puVar11[iVar16] = puVar13;
                  iVar16 = iVar16 + 1;
                  pcVar12 = pcVar12 + 1;
                }
                else {
LAB_005a1534:
                  *(char *)puVar13 = cVar1;
                  bVar2 = cVar1 == '\\';
                  puVar13 = (undefined4 *)((int)puVar13 + 1);
                  pcVar12 = pcVar12 + 1;
                }
              }
              *(undefined *)puVar13 = 0;
              puVar3 = PTR_sk_push_006a80a8;
              if ((iVar16 == num) && (*pcVar15 == '\0')) {
                puVar11[iVar16] = (undefined *)((int)puVar13 + 1);
                iVar16 = (*(code *)puVar3)(pTVar14->data,puVar11);
                if (iVar16 != 0) {
                  iVar16 = 0;
                  goto LAB_005a1498;
                }
                (*(code *)PTR_fwrite_006aab7c)
                          ("failure in sk_push\n",1,0x13,*(undefined4 *)PTR_stderr_006aac00);
              }
              else {
                (*(code *)PTR___fprintf_chk_006aaa8c)
                          (*(undefined4 *)PTR_stderr_006aac00,1,
                           "wrong number of fields on line %ld (looking for field %d, got %d, \'%s\' left)\n"
                           ,iVar9,num,iVar16,pcVar15);
              }
              (*(code *)PTR_BUF_MEM_free_006a8594)(iVar4);
              goto LAB_005a12ac;
            }
LAB_005a1498:
            iVar9 = iVar9 + 1;
            if (iVar16 == 0) goto LAB_005a14a0;
            iVar5 = iVar5 + 0x200;
            iVar10 = (*(code *)PTR_BUF_MEM_grow_clean_006a8c2c)(iVar4,iVar5);
            puVar3 = PTR_BIO_gets_006a85d0;
            if (iVar10 == 0) break;
            *(undefined *)(*(int *)(iVar4 + 4) + iVar16) = 0;
            (*(code *)puVar3)(in,*(int *)(iVar4 + 4) + iVar16,iVar5 - iVar16);
            pcVar15 = *(char **)(iVar4 + 4);
            pcVar12 = pcVar15 + iVar16;
            if (*pcVar12 == '\0') goto LAB_005a15d0;
          } while( true );
        }
      }
    }
  }
  (*(code *)PTR_BUF_MEM_free_006a8594)(iVar4);
  (*(code *)PTR_fwrite_006aab7c)
            ("OPENSSL_malloc failure\n",1,0x17,*(undefined4 *)PTR_stderr_006aac00);
  if (pTVar14 != (TXT_DB *)0x0) {
LAB_005a12ac:
    if (pTVar14->data != (stack_st_OPENSSL_PSTRING *)0x0) {
      (*(code *)PTR_sk_free_006a7f80)();
    }
    if (pTVar14->index != (lhash_st_OPENSSL_STRING **)0x0) {
      (*(code *)PTR_CRYPTO_free_006a7f88)();
    }
    if (pTVar14->qual != (_func_4743 *)0x0) {
      (*(code *)PTR_CRYPTO_free_006a7f88)();
    }
    (*(code *)PTR_CRYPTO_free_006a7f88)(pTVar14);
  }
  return (TXT_DB *)0x0;
}

