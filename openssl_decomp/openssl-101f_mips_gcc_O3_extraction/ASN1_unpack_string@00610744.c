
void * ASN1_unpack_string(ASN1_STRING *oct,undefined1 *d2i)

{
  undefined *puVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  uchar **ppuVar6;
  int *piVar7;
  int **ppiVar8;
  undefined4 uVar9;
  int *piVar10;
  int iStack_58;
  int iStack_54;
  undefined *puStack_50;
  uchar *local_10;
  int local_c;
  
  puStack_50 = PTR___stack_chk_guard_006aabf0;
  local_10 = oct->data;
  ppiVar8 = (int **)oct->length;
  ppuVar6 = &local_10;
  local_c = *(int *)PTR___stack_chk_guard_006aabf0;
  pvVar2 = (void *)(*(code *)d2i)(0);
  if (pvVar2 == (void *)0x0) {
    ppiVar8 = (int **)&DAT_0000006e;
    ppuVar6 = (uchar **)&DAT_00000088;
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x88,0x6e,"asn_pack.c");
  }
  if (local_c == *(int *)puStack_50) {
    return pvVar2;
  }
  iVar4 = local_c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iStack_54 = *(int *)PTR___stack_chk_guard_006aabf0;
  if (ppiVar8 == (int **)0x0) {
    piVar10 = (int *)(*(code *)PTR_ASN1_STRING_new_006a98b4)();
    if (piVar10 != (int *)0x0) goto LAB_0061083c;
LAB_00610928:
    ppiVar8 = (int **)&DAT_00000041;
    uVar5 = 0x81;
LAB_006108f8:
    piVar7 = (int *)&DAT_0000007c;
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x7c,ppiVar8,"asn_pack.c",uVar5);
    piVar10 = (int *)0x0;
  }
  else {
    piVar10 = *ppiVar8;
    if (piVar10 == (int *)0x0) {
      piVar10 = (int *)(*(code *)PTR_ASN1_STRING_new_006a98b4)();
      if (piVar10 == (int *)0x0) goto LAB_00610928;
      *ppiVar8 = piVar10;
    }
LAB_0061083c:
    iVar3 = (*(code *)ppuVar6)(iVar4,0);
    *piVar10 = iVar3;
    if (iVar3 == 0) {
      ppiVar8 = (int **)&DAT_00000070;
      uVar5 = 0x88;
      goto LAB_006108f8;
    }
    ppiVar8 = (int **)&DAT_0000008b;
    iStack_58 = (*(code *)PTR_CRYPTO_malloc_006a8108)(iVar3,"asn_pack.c");
    if (iStack_58 == 0) {
      ppiVar8 = (int **)&DAT_00000041;
      piVar7 = (int *)&DAT_0000007c;
      (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x7c,0x41,"asn_pack.c",0x8c);
      piVar10 = (int *)0x0;
    }
    else {
      piVar7 = &iStack_58;
      piVar10[2] = iStack_58;
      (*(code *)ppuVar6)(iVar4,piVar7);
    }
  }
  if (iStack_54 == *(int *)puVar1) {
    return piVar10;
  }
  iVar4 = iStack_54;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (ppiVar8 == (int **)0x0) {
    piVar10 = (int *)(*(code *)PTR_ASN1_STRING_new_006a98b4)();
    if (piVar10 == (int *)0x0) {
LAB_00610a48:
      uVar9 = 0x41;
      uVar5 = 0x9e;
      goto LAB_00610a5c;
    }
  }
  else {
    piVar10 = *ppiVar8;
    if (piVar10 == (int *)0x0) {
      piVar10 = (int *)(*(code *)PTR_ASN1_STRING_new_006a98b4)();
      if (piVar10 == (int *)0x0) goto LAB_00610a48;
      *ppiVar8 = piVar10;
    }
  }
  if (piVar10[2] != 0) {
    (*(code *)PTR_CRYPTO_free_006a7f88)();
    piVar10[2] = 0;
  }
  iVar4 = (*(code *)PTR_ASN1_item_i2d_006a979c)(iVar4,piVar10 + 2,piVar7);
  *piVar10 = iVar4;
  if (iVar4 == 0) {
    uVar9 = 0x70;
    uVar5 = 0xaa;
  }
  else {
    if (piVar10[2] != 0) {
      return piVar10;
    }
    uVar9 = 0x41;
    uVar5 = 0xae;
  }
LAB_00610a5c:
  (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xc6,uVar9,"asn_pack.c",uVar5);
  return (void *)0x0;
}

