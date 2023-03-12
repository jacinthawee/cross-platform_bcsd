
void * ASN1_unpack_string(ASN1_STRING *oct,undefined1 *d2i)

{
  undefined *puVar1;
  void *pvVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  uchar **ppuVar7;
  int *piVar8;
  int **ppiVar9;
  int **ppiVar10;
  undefined4 uVar11;
  int *piVar12;
  int iStack_60;
  int iStack_5c;
  undefined *puStack_54;
  uchar *local_10;
  int local_c;
  
  puStack_54 = PTR___stack_chk_guard_006a9ae8;
  local_10 = oct->data;
  ppiVar9 = (int **)oct->length;
  ppuVar7 = &local_10;
  local_c = *(int *)PTR___stack_chk_guard_006a9ae8;
  pvVar2 = (void *)(*(code *)d2i)(0);
  if (pvVar2 == (void *)0x0) {
    ppiVar9 = (int **)&DAT_0000006e;
    ppuVar7 = (uchar **)&DAT_00000088;
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x88,0x6e,"asn_pack.c");
  }
  if (local_c == *(int *)puStack_54) {
    return pvVar2;
  }
  iVar5 = local_c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iStack_5c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (ppiVar9 == (int **)0x0) {
    piVar12 = (int *)(*(code *)PTR_ASN1_STRING_new_006a8790)();
    if (piVar12 != (int *)0x0) goto LAB_0060f614;
LAB_0060f754:
    ppiVar10 = (int **)&DAT_00000041;
    piVar8 = (int *)&DAT_0000007c;
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x7c,0x41,"asn_pack.c",0x86);
    piVar4 = (int *)0x0;
  }
  else {
    piVar12 = *ppiVar9;
    if (piVar12 == (int *)0x0) {
      piVar12 = (int *)(*(code *)PTR_ASN1_STRING_new_006a8790)();
      if (piVar12 == (int *)0x0) goto LAB_0060f754;
      *ppiVar9 = piVar12;
    }
LAB_0060f614:
    iVar3 = (*(code *)ppuVar7)(iVar5,0);
    *piVar12 = iVar3;
    if (iVar3 == 0) {
      ppiVar10 = (int **)&DAT_00000070;
      piVar8 = (int *)&DAT_0000007c;
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x7c,0x70,"asn_pack.c",0x8f);
    }
    else {
      ppiVar10 = (int **)&DAT_00000092;
      iStack_60 = (*(code *)PTR_CRYPTO_malloc_006a7008)(iVar3,"asn_pack.c");
      if (iStack_60 != 0) {
        piVar8 = &iStack_60;
        piVar12[2] = iStack_60;
        (*(code *)ppuVar7)(iVar5,piVar8);
        piVar4 = piVar12;
        goto LAB_0060f670;
      }
      ppiVar10 = (int **)&DAT_00000041;
      piVar8 = (int *)&DAT_0000007c;
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x7c,0x41,"asn_pack.c",0x93);
    }
    if (ppiVar9 == (int **)0x0) {
      (*(code *)PTR_ASN1_STRING_free_006a879c)(piVar12);
      piVar4 = (int *)0x0;
    }
    else {
      piVar4 = *ppiVar9;
      if (piVar4 == (int *)0x0) {
        (*(code *)PTR_ASN1_STRING_free_006a879c)(piVar12);
        *ppiVar9 = (int *)0x0;
      }
      else {
        piVar4 = (int *)0x0;
      }
    }
  }
LAB_0060f670:
  if (iStack_5c == *(int *)puVar1) {
    return piVar4;
  }
  iVar5 = iStack_5c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (ppiVar10 == (int **)0x0) {
    piVar12 = (int *)(*(code *)PTR_ASN1_STRING_new_006a8790)();
    if (piVar12 == (int *)0x0) {
LAB_0060f874:
      uVar11 = 0x41;
      uVar6 = 0xac;
      goto LAB_0060f888;
    }
  }
  else {
    piVar12 = *ppiVar10;
    if (piVar12 == (int *)0x0) {
      piVar12 = (int *)(*(code *)PTR_ASN1_STRING_new_006a8790)();
      if (piVar12 == (int *)0x0) goto LAB_0060f874;
      *ppiVar10 = piVar12;
    }
  }
  if (piVar12[2] != 0) {
    (*(code *)PTR_CRYPTO_free_006a6e88)();
    piVar12[2] = 0;
  }
  iVar5 = (*(code *)PTR_ASN1_item_i2d_006a8678)(iVar5,piVar12 + 2,piVar8);
  *piVar12 = iVar5;
  if (iVar5 == 0) {
    uVar11 = 0x70;
    uVar6 = 0xba;
  }
  else {
    if (piVar12[2] != 0) {
      return piVar12;
    }
    uVar11 = 0x41;
    uVar6 = 0xbe;
  }
LAB_0060f888:
  (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xc6,uVar11,"asn_pack.c",uVar6);
  return (void *)0x0;
}

