
ASN1_STRING * ASN1_pack_string(void *obj,undefined1 *i2d,ASN1_OCTET_STRING **oct)

{
  undefined *puVar1;
  int iVar2;
  ASN1_STRING *pAVar3;
  undefined4 uVar4;
  uchar **ppuVar5;
  ASN1_STRING **ppAVar6;
  undefined4 uVar7;
  ASN1_STRING *pAVar8;
  uchar *local_28;
  int local_24;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_24 = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (oct == (ASN1_OCTET_STRING **)0x0) {
    pAVar8 = (ASN1_STRING *)(*(code *)PTR_ASN1_STRING_new_006a8790)();
    if (pAVar8 != (ASN1_STRING *)0x0) goto LAB_0060f614;
LAB_0060f754:
    ppAVar6 = (ASN1_STRING **)&DAT_00000041;
    ppuVar5 = (uchar **)&DAT_0000007c;
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x7c,0x41,"asn_pack.c",0x86);
    pAVar3 = (ASN1_STRING *)0x0;
  }
  else {
    pAVar8 = *oct;
    if (pAVar8 == (ASN1_STRING *)0x0) {
      pAVar8 = (ASN1_STRING *)(*(code *)PTR_ASN1_STRING_new_006a8790)();
      if (pAVar8 == (ASN1_STRING *)0x0) goto LAB_0060f754;
      *oct = pAVar8;
    }
LAB_0060f614:
    iVar2 = (*(code *)i2d)(obj,0);
    pAVar8->length = iVar2;
    if (iVar2 == 0) {
      ppAVar6 = (ASN1_STRING **)&DAT_00000070;
      ppuVar5 = (uchar **)&DAT_0000007c;
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x7c,0x70,"asn_pack.c",0x8f);
    }
    else {
      ppAVar6 = (ASN1_STRING **)&DAT_00000092;
      local_28 = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a7008)(iVar2,"asn_pack.c");
      if (local_28 != (uchar *)0x0) {
        ppuVar5 = &local_28;
        pAVar8->data = local_28;
        (*(code *)i2d)(obj,ppuVar5);
        pAVar3 = pAVar8;
        goto LAB_0060f670;
      }
      ppAVar6 = (ASN1_STRING **)&DAT_00000041;
      ppuVar5 = (uchar **)&DAT_0000007c;
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x7c,0x41,"asn_pack.c",0x93);
    }
    if (oct == (ASN1_OCTET_STRING **)0x0) {
      (*(code *)PTR_ASN1_STRING_free_006a879c)(pAVar8);
      pAVar3 = (ASN1_STRING *)0x0;
    }
    else {
      pAVar3 = *oct;
      if (pAVar3 == (ASN1_STRING *)0x0) {
        (*(code *)PTR_ASN1_STRING_free_006a879c)(pAVar8);
        *oct = (ASN1_OCTET_STRING *)0x0;
      }
      else {
        pAVar3 = (ASN1_STRING *)0x0;
      }
    }
  }
LAB_0060f670:
  if (local_24 == *(int *)puVar1) {
    return pAVar3;
  }
  iVar2 = local_24;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (ppAVar6 == (ASN1_STRING **)0x0) {
    pAVar8 = (ASN1_STRING *)(*(code *)PTR_ASN1_STRING_new_006a8790)();
    if (pAVar8 == (ASN1_STRING *)0x0) {
LAB_0060f874:
      uVar7 = 0x41;
      uVar4 = 0xac;
      goto LAB_0060f888;
    }
  }
  else {
    pAVar8 = *ppAVar6;
    if (pAVar8 == (ASN1_STRING *)0x0) {
      pAVar8 = (ASN1_STRING *)(*(code *)PTR_ASN1_STRING_new_006a8790)();
      if (pAVar8 == (ASN1_STRING *)0x0) goto LAB_0060f874;
      *ppAVar6 = pAVar8;
    }
  }
  if (pAVar8->data != (uchar *)0x0) {
    (*(code *)PTR_CRYPTO_free_006a6e88)();
    pAVar8->data = (uchar *)0x0;
  }
  iVar2 = (*(code *)PTR_ASN1_item_i2d_006a8678)(iVar2,&pAVar8->data,ppuVar5);
  pAVar8->length = iVar2;
  if (iVar2 == 0) {
    uVar7 = 0x70;
    uVar4 = 0xba;
  }
  else {
    if (pAVar8->data != (uchar *)0x0) {
      return pAVar8;
    }
    uVar7 = 0x41;
    uVar4 = 0xbe;
  }
LAB_0060f888:
  (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xc6,uVar7,"asn_pack.c",uVar4);
  return (ASN1_STRING *)0x0;
}

