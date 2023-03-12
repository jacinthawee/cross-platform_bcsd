
void TXT_DB_free(TXT_DB *db)

{
  lhash_st_OPENSSL_STRING **pplVar1;
  int **ppiVar2;
  undefined4 uVar3;
  lhash_st_OPENSSL_STRING **pplVar4;
  int *piVar5;
  int iVar6;
  int **ppiVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  
  if (db != (TXT_DB *)0x0) {
    pplVar4 = db->index;
    if (pplVar4 != (lhash_st_OPENSSL_STRING **)0x0) {
      iVar6 = db->num_fields + -1;
      if (-1 < iVar6) {
        iVar8 = iVar6 * 4;
        pplVar1 = pplVar4 + iVar6;
        do {
          iVar6 = iVar6 + -1;
          iVar8 = iVar8 + -4;
          if (*pplVar1 != (lhash_st_OPENSSL_STRING *)0x0) {
            (*(code *)PTR_lh_free_006a8518)(*pplVar1);
            pplVar4 = db->index;
          }
          pplVar1 = (lhash_st_OPENSSL_STRING **)((int)pplVar4 + iVar8);
        } while (iVar6 != -1);
      }
      (*(code *)PTR_CRYPTO_free_006a7f88)(pplVar4);
    }
    if (db->qual != (_func_4743 *)0x0) {
      (*(code *)PTR_CRYPTO_free_006a7f88)();
    }
    if (db->data != (stack_st_OPENSSL_PSTRING *)0x0) {
      iVar8 = (*(code *)PTR_sk_num_006a7f2c)();
      iVar6 = iVar8 + -1;
      if (-1 < iVar8 + -1) {
        do {
          ppiVar2 = (int **)(*(code *)PTR_sk_value_006a7f24)(db->data,iVar6);
          iVar8 = db->num_fields;
          piVar10 = ppiVar2[iVar8];
          if (piVar10 == (int *)0x0) {
            if (0 < iVar8) {
              iVar9 = 0;
              do {
                piVar10 = *ppiVar2;
                iVar9 = iVar9 + 1;
                ppiVar2 = ppiVar2 + 1;
                if (piVar10 != (int *)0x0) {
                  (*(code *)PTR_CRYPTO_free_006a7f88)(piVar10);
                  iVar8 = db->num_fields;
                }
              } while (iVar9 < iVar8);
            }
          }
          else if (0 < iVar8) {
            iVar9 = 0;
            ppiVar7 = ppiVar2;
            do {
              piVar5 = *ppiVar7;
              iVar9 = iVar9 + 1;
              ppiVar7 = ppiVar7 + 1;
              if (((piVar5 < ppiVar2) || (piVar10 < piVar5)) && (piVar5 != (int *)0x0)) {
                (*(code *)PTR_CRYPTO_free_006a7f88)(piVar5);
                iVar8 = db->num_fields;
              }
            } while (iVar9 < iVar8);
          }
          iVar8 = iVar6 + -1;
          uVar3 = (*(code *)PTR_sk_value_006a7f24)(db->data,iVar6);
          (*(code *)PTR_CRYPTO_free_006a7f88)(uVar3);
          iVar6 = iVar8;
        } while (iVar8 != -1);
      }
      (*(code *)PTR_sk_free_006a7f80)(db->data);
    }
                    /* WARNING: Could not recover jumptable at 0x005a1e54. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_CRYPTO_free_006a7f88)(db);
    return;
  }
  return;
}

