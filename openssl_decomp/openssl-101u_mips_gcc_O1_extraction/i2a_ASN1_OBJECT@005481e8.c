
int i2a_ASN1_OBJECT(BIO *bp,ASN1_OBJECT *a)

{
  undefined *puVar1;
  int iVar2;
  char **ppcVar3;
  char *pcVar4;
  uint uVar5;
  int **ppiVar6;
  char *pcVar7;
  char **ppcVar8;
  int iVar9;
  char *pcVar10;
  int *piVar11;
  char *pcVar12;
  char *apcStack_74 [20];
  int **local_24;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_24 = *(int ***)PTR___stack_chk_guard_006a9ae8;
  if ((a == (ASN1_OBJECT *)0x0) || (a->data == (uchar *)0x0)) {
    iVar9 = 4;
    pcVar7 = "NULL";
    iVar2 = (*(code *)PTR_BIO_write_006a6e14)(bp);
  }
  else {
    ppcVar8 = apcStack_74;
    iVar2 = (*(code *)PTR_OBJ_obj2txt_006a8c9c)(ppcVar8,0x50,a,0);
    if (iVar2 < 0x50) {
      if (iVar2 < 1) {
        iVar9 = 9;
        pcVar7 = s__INVALID__00669434;
        iVar2 = (*(code *)PTR_BIO_write_006a6e14)(bp);
      }
      else {
        iVar9 = iVar2;
        (*(code *)PTR_BIO_write_006a6e14)(bp);
        pcVar7 = (char *)ppcVar8;
      }
    }
    else {
      iVar9 = 0xe7;
      pcVar7 = "a_object.c";
      ppcVar3 = (char **)(*(code *)PTR_CRYPTO_malloc_006a7008)(iVar2 + 1);
      if (ppcVar3 == (char **)0x0) {
        iVar2 = -1;
      }
      else {
        (*(code *)PTR_OBJ_obj2txt_006a8c9c)(ppcVar3,iVar2 + 1,a,0);
        pcVar7 = (char *)ppcVar3;
        iVar9 = iVar2;
        (*(code *)PTR_BIO_write_006a6e14)(bp);
        if (ppcVar3 != ppcVar8) {
          (*(code *)PTR_CRYPTO_free_006a6e88)(ppcVar3);
        }
      }
    }
  }
  if (local_24 == *(int ***)puVar1) {
    return iVar2;
  }
  ppiVar6 = local_24;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if ((iVar9 < 1) || ((char **)pcVar7 == (char **)0x0)) {
LAB_005486b0:
    iVar9 = 0x11f;
LAB_00548434:
    ERR_put_error(0xd,0xc4,0xd8,"a_object.c",iVar9);
    return 0;
  }
  pcVar12 = *(char **)pcVar7;
  pcVar10 = pcVar12 + iVar9;
  if ((pcVar12 == (char *)0x0) || (pcVar4 = pcVar12, pcVar10[-1] < '\0')) goto LAB_005486b0;
  do {
    if ((*pcVar4 == -0x80) && ((pcVar4 == pcVar12 || (-1 < pcVar4[-1])))) {
      iVar9 = 0x126;
      goto LAB_00548434;
    }
    pcVar4 = pcVar4 + 1;
  } while (pcVar10 != pcVar4);
  if (((ppiVar6 == (int **)0x0) || (piVar11 = *ppiVar6, piVar11 == (int *)0x0)) ||
     ((piVar11[5] & 1U) == 0)) {
    piVar11 = (int *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x18,"a_object.c",0x15e);
    if (piVar11 == (int *)0x0) {
      ERR_put_error(0xd,0x7b,0x41,"a_object.c",0x160);
      return 0;
    }
    piVar11[4] = 0;
    *piVar11 = 0;
    piVar11[1] = 0;
    piVar11[3] = 0;
    piVar11[2] = 0;
    pcVar12 = *(char **)pcVar7;
    piVar11[5] = 1;
LAB_0054858c:
    puVar1 = PTR_CRYPTO_malloc_006a7008;
    piVar11[3] = 0;
    iVar2 = (*(code *)puVar1)(iVar9,"a_object.c",0x13f);
    pcVar10 = pcVar12 + iVar9;
    if (iVar2 == 0) {
      ERR_put_error(0xd,0xc4,0x41,"a_object.c",0x154);
      if (ppiVar6 == (int **)0x0) goto LAB_005485e8;
LAB_005485dc:
      if (*ppiVar6 == piVar11) {
        return 0;
      }
LAB_005485e8:
      uVar5 = piVar11[5];
      if ((uVar5 & 4) != 0) {
        if (*piVar11 != 0) {
          (*(code *)PTR_CRYPTO_free_006a6e88)();
        }
        if (piVar11[1] != 0) {
          (*(code *)PTR_CRYPTO_free_006a6e88)();
        }
        uVar5 = piVar11[5];
        piVar11[1] = 0;
        *piVar11 = 0;
      }
      if ((uVar5 & 8) != 0) {
        if (piVar11[4] != 0) {
          (*(code *)PTR_CRYPTO_free_006a6e88)();
          uVar5 = piVar11[5];
        }
        piVar11[4] = 0;
        piVar11[3] = 0;
      }
      if ((uVar5 & 1) == 0) {
        return 0;
      }
      (*(code *)PTR_CRYPTO_free_006a6e88)(piVar11);
      return 0;
    }
  }
  else {
    iVar2 = piVar11[4];
    piVar11[4] = 0;
    puVar1 = PTR_CRYPTO_free_006a6e88;
    if (iVar2 == 0) goto LAB_0054858c;
    if (iVar9 <= piVar11[3]) {
      iVar2 = (*(code *)PTR_memcpy_006a9aec)(iVar2,pcVar12,iVar9);
      piVar11[4] = iVar2;
      piVar11[3] = iVar9;
      *piVar11 = 0;
      piVar11[1] = 0;
      *ppiVar6 = piVar11;
      goto LAB_0054851c;
    }
    piVar11[3] = 0;
    (*(code *)puVar1)(iVar2);
    iVar2 = (*(code *)PTR_CRYPTO_malloc_006a7008)(iVar9,"a_object.c",0x13f);
    if (iVar2 == 0) {
      ERR_put_error(0xd,0xc4,0x41,"a_object.c",0x154);
      goto LAB_005485dc;
    }
  }
  puVar1 = PTR_memcpy_006a9aec;
  piVar11[5] = piVar11[5] | 8;
  iVar2 = (*(code *)puVar1)(iVar2,pcVar12,iVar9);
  piVar11[4] = iVar2;
  piVar11[3] = iVar9;
  *piVar11 = 0;
  piVar11[1] = 0;
  if (ppiVar6 != (int **)0x0) {
    *ppiVar6 = piVar11;
  }
LAB_0054851c:
  *(char **)pcVar7 = pcVar10;
  return (int)piVar11;
}

