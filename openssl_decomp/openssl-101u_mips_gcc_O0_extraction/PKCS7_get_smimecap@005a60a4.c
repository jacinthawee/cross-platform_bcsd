
stack_st_X509_ALGOR * PKCS7_get_smimecap(PKCS7_SIGNER_INFO *si)

{
  undefined *puVar1;
  ASN1_TYPE *pAVar2;
  stack_st_X509_ALGOR *psVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  int iVar9;
  uchar **ppuVar10;
  int in_a2;
  uchar *local_10;
  int local_c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  ppuVar10 = (uchar **)0xa7;
  local_c = *(int *)PTR___stack_chk_guard_006a9ae8;
  pAVar2 = PKCS7_get_signed_attribute(si,0xa7);
  if ((pAVar2 == (ASN1_TYPE *)0x0) || (ppuVar10 = &local_10, pAVar2->type != 0x10)) {
    psVar3 = (stack_st_X509_ALGOR *)0x0;
  }
  else {
    local_10 = ((pAVar2->value).asn1_string)->data;
    in_a2 = ((pAVar2->value).asn1_string)->length;
    psVar3 = (stack_st_X509_ALGOR *)
             (*(code *)PTR_ASN1_item_d2i_006a8674)(0,ppuVar10,in_a2,PTR_X509_ALGORS_it_006a91ac);
  }
  if (local_c == *(int *)puVar1) {
    return psVar3;
  }
  iVar9 = local_c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar4 = (undefined4 *)(*(code *)PTR_X509_ALGOR_new_006a7ec8)();
  if (puVar4 == (undefined4 *)0x0) {
    uVar5 = 0x68;
  }
  else {
    (*(code *)PTR_ASN1_OBJECT_free_006a7004)(*puVar4);
    uVar5 = (*(code *)PTR_OBJ_nid2obj_006a7140)(ppuVar10);
    *puVar4 = uVar5;
    if (in_a2 < 1) {
LAB_005a6208:
      (*(code *)PTR_sk_push_006a6fa8)(iVar9,puVar4);
      return (stack_st_X509_ALGOR *)0x1;
    }
    iVar6 = (*(code *)PTR_ASN1_TYPE_new_006a7ecc)();
    puVar4[1] = iVar6;
    if (iVar6 == 0) {
      uVar5 = 0x70;
    }
    else {
      iVar6 = (*(code *)PTR_ASN1_INTEGER_new_006a7160)();
      if (iVar6 != 0) {
        iVar7 = (*(code *)PTR_ASN1_INTEGER_set_006a7164)(iVar6,in_a2);
        if (iVar7 == 0) {
          (*(code *)PTR_ERR_put_error_006a7f34)(0x21,0x77,0x41,"pk7_attr.c",0x78);
          return (stack_st_X509_ALGOR *)0x0;
        }
        puVar8 = (undefined4 *)puVar4[1];
        puVar8[1] = iVar6;
        *puVar8 = 2;
        goto LAB_005a6208;
      }
      uVar5 = 0x74;
    }
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x21,0x77,0x41,"pk7_attr.c",uVar5);
  return (stack_st_X509_ALGOR *)0x0;
}

