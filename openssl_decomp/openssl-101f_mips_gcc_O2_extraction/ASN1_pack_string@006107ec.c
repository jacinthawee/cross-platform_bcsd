
ASN1_STRING * ASN1_pack_string(void *obj,undefined1 *i2d,ASN1_OCTET_STRING **oct)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  uchar **ppuVar4;
  ASN1_STRING **ppAVar5;
  undefined4 uVar6;
  ASN1_STRING *pAVar7;
  uchar *local_20;
  int local_1c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_1c = *(int *)PTR___stack_chk_guard_006aabf0;
  if (oct == (ASN1_OCTET_STRING **)0x0) {
    pAVar7 = (ASN1_STRING *)(*(code *)PTR_ASN1_STRING_new_006a98b4)();
    if (pAVar7 != (ASN1_STRING *)0x0) goto LAB_0061083c;
LAB_00610928:
    ppAVar5 = (ASN1_STRING **)&DAT_00000041;
    uVar3 = 0x81;
LAB_006108f8:
    ppuVar4 = (uchar **)&DAT_0000007c;
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x7c,ppAVar5,"asn_pack.c",uVar3);
    pAVar7 = (ASN1_STRING *)0x0;
  }
  else {
    pAVar7 = *oct;
    if (pAVar7 == (ASN1_STRING *)0x0) {
      pAVar7 = (ASN1_STRING *)(*(code *)PTR_ASN1_STRING_new_006a98b4)();
      if (pAVar7 == (ASN1_STRING *)0x0) goto LAB_00610928;
      *oct = pAVar7;
    }
LAB_0061083c:
    iVar2 = (*(code *)i2d)(obj,0);
    pAVar7->length = iVar2;
    if (iVar2 == 0) {
      ppAVar5 = (ASN1_STRING **)&DAT_00000070;
      uVar3 = 0x88;
      goto LAB_006108f8;
    }
    ppAVar5 = (ASN1_STRING **)&DAT_0000008b;
    local_20 = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a8108)(iVar2,"asn_pack.c");
    if (local_20 == (uchar *)0x0) {
      ppAVar5 = (ASN1_STRING **)&DAT_00000041;
      ppuVar4 = (uchar **)&DAT_0000007c;
      (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x7c,0x41,"asn_pack.c",0x8c);
      pAVar7 = (ASN1_STRING *)0x0;
    }
    else {
      ppuVar4 = &local_20;
      pAVar7->data = local_20;
      (*(code *)i2d)(obj,ppuVar4);
    }
  }
  if (local_1c == *(int *)puVar1) {
    return pAVar7;
  }
  iVar2 = local_1c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (ppAVar5 == (ASN1_STRING **)0x0) {
    pAVar7 = (ASN1_STRING *)(*(code *)PTR_ASN1_STRING_new_006a98b4)();
    if (pAVar7 == (ASN1_STRING *)0x0) {
LAB_00610a48:
      uVar6 = 0x41;
      uVar3 = 0x9e;
      goto LAB_00610a5c;
    }
  }
  else {
    pAVar7 = *ppAVar5;
    if (pAVar7 == (ASN1_STRING *)0x0) {
      pAVar7 = (ASN1_STRING *)(*(code *)PTR_ASN1_STRING_new_006a98b4)();
      if (pAVar7 == (ASN1_STRING *)0x0) goto LAB_00610a48;
      *ppAVar5 = pAVar7;
    }
  }
  if (pAVar7->data != (uchar *)0x0) {
    (*(code *)PTR_CRYPTO_free_006a7f88)();
    pAVar7->data = (uchar *)0x0;
  }
  iVar2 = (*(code *)PTR_ASN1_item_i2d_006a979c)(iVar2,&pAVar7->data,ppuVar4);
  pAVar7->length = iVar2;
  if (iVar2 == 0) {
    uVar6 = 0x70;
    uVar3 = 0xaa;
  }
  else {
    if (pAVar7->data != (uchar *)0x0) {
      return pAVar7;
    }
    uVar6 = 0x41;
    uVar3 = 0xae;
  }
LAB_00610a5c:
  (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xc6,uVar6,"asn_pack.c",uVar3);
  return (ASN1_STRING *)0x0;
}

