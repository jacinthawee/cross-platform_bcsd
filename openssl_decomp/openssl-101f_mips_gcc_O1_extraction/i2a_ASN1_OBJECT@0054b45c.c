
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
  char *apcStack_74 [20];
  int **local_24;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_24 = *(int ***)PTR___stack_chk_guard_006aabf0;
  if ((a == (ASN1_OBJECT *)0x0) || (a->data == (uchar *)0x0)) {
    iVar9 = 4;
    pcVar7 = "NULL";
    iVar2 = (*(code *)PTR_BIO_write_006a7f14)(bp);
  }
  else {
    ppcVar8 = apcStack_74;
    iVar2 = (*(code *)PTR_OBJ_obj2txt_006a9dbc)(ppcVar8,0x50,a,0);
    if (iVar2 < 0x50) {
      if (iVar2 < 1) {
        iVar9 = 9;
        pcVar7 = s__INVALID__00669f10;
        iVar2 = (*(code *)PTR_BIO_write_006a7f14)(bp);
      }
      else {
        iVar9 = iVar2;
        (*(code *)PTR_BIO_write_006a7f14)(bp);
        pcVar7 = (char *)ppcVar8;
      }
    }
    else {
      iVar9 = 0xf5;
      pcVar7 = "a_object.c";
      ppcVar3 = (char **)(*(code *)PTR_CRYPTO_malloc_006a8108)(iVar2 + 1);
      if (ppcVar3 == (char **)0x0) {
        iVar2 = -1;
      }
      else {
        (*(code *)PTR_OBJ_obj2txt_006a9dbc)(ppcVar3,iVar2 + 1,a,0);
        pcVar7 = (char *)ppcVar3;
        iVar9 = iVar2;
        (*(code *)PTR_BIO_write_006a7f14)(bp);
        if (ppcVar3 != ppcVar8) {
          (*(code *)PTR_CRYPTO_free_006a7f88)(ppcVar3);
        }
      }
    }
  }
  if (local_24 == *(int ***)puVar1) {
    return iVar2;
  }
  ppiVar6 = local_24;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  pcVar10 = *(char **)pcVar7;
  if (0 < iVar9) {
    pcVar4 = pcVar10;
    do {
      if ((*pcVar4 == -0x80) && ((pcVar4 == pcVar10 || (-1 < pcVar4[-1])))) {
        ERR_put_error(0xd,0xc4,0xd8,"a_object.c",300);
        return 0;
      }
      pcVar4 = pcVar4 + 1;
    } while (pcVar4 != pcVar10 + iVar9);
  }
  if (((ppiVar6 == (int **)0x0) || (piVar11 = *ppiVar6, piVar11 == (int *)0x0)) ||
     ((piVar11[5] & 1U) == 0)) {
    piVar11 = (int *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x18,"a_object.c",0x15f);
    if (piVar11 == (int *)0x0) {
      ERR_put_error(0xd,0x7b,0x41,"a_object.c",0x162);
      return 0;
    }
    piVar11[4] = 0;
    *piVar11 = 0;
    piVar11[1] = 0;
    piVar11[3] = 0;
    piVar11[2] = 0;
    pcVar10 = *(char **)pcVar7;
    piVar11[5] = 1;
LAB_0054b750:
    piVar11[3] = 0;
  }
  else {
    iVar2 = piVar11[4];
    piVar11[4] = 0;
    puVar1 = PTR_CRYPTO_free_006a7f88;
    if (iVar2 == 0) goto LAB_0054b750;
    if (iVar9 <= piVar11[3]) {
      iVar2 = (*(code *)PTR_memcpy_006aabf4)(iVar2,pcVar10,iVar9);
      pcVar4 = pcVar10 + iVar9;
      piVar11[4] = iVar2;
      piVar11[3] = iVar9;
      *piVar11 = 0;
      piVar11[1] = 0;
      *ppiVar6 = piVar11;
      goto LAB_0054b7b4;
    }
    piVar11[3] = 0;
    (*(code *)puVar1)(iVar2);
  }
  iVar2 = 1;
  if (iVar9 != 0) {
    iVar2 = iVar9;
  }
  iVar2 = (*(code *)PTR_CRYPTO_malloc_006a8108)(iVar2,"a_object.c",0x143);
  puVar1 = PTR_memcpy_006aabf4;
  if (iVar2 == 0) {
    ERR_put_error(0xd,0xc4,0x41,"a_object.c",0x155);
    if ((ppiVar6 != (int **)0x0) && (piVar11 == *ppiVar6)) {
      return 0;
    }
    uVar5 = piVar11[5];
    if ((uVar5 & 4) != 0) {
      if (*piVar11 != 0) {
        (*(code *)PTR_CRYPTO_free_006a7f88)();
      }
      if (piVar11[1] != 0) {
        (*(code *)PTR_CRYPTO_free_006a7f88)();
      }
      uVar5 = piVar11[5];
      piVar11[1] = 0;
      *piVar11 = 0;
    }
    if ((uVar5 & 8) != 0) {
      if (piVar11[4] != 0) {
        (*(code *)PTR_CRYPTO_free_006a7f88)();
        uVar5 = piVar11[5];
      }
      piVar11[4] = 0;
      piVar11[3] = 0;
    }
    if ((uVar5 & 1) == 0) {
      return 0;
    }
    (*(code *)PTR_CRYPTO_free_006a7f88)(piVar11);
    return 0;
  }
  pcVar4 = pcVar10 + iVar9;
  piVar11[5] = piVar11[5] | 8;
  iVar2 = (*(code *)puVar1)(iVar2,pcVar10,iVar9);
  piVar11[4] = iVar2;
  piVar11[3] = iVar9;
  *piVar11 = 0;
  piVar11[1] = 0;
  if (ppiVar6 != (int **)0x0) {
    *ppiVar6 = piVar11;
  }
LAB_0054b7b4:
  *(char **)pcVar7 = pcVar4;
  return (int)piVar11;
}

