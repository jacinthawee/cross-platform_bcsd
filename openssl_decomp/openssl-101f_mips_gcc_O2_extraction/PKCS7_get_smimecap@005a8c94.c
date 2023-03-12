
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
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  ppuVar10 = (uchar **)0xa7;
  local_c = *(int *)PTR___stack_chk_guard_006aabf0;
  pAVar2 = PKCS7_get_signed_attribute(si,0xa7);
  if ((pAVar2 == (ASN1_TYPE *)0x0) || (ppuVar10 = &local_10, pAVar2->type != 0x10)) {
    psVar3 = (stack_st_X509_ALGOR *)0x0;
  }
  else {
    local_10 = ((pAVar2->value).asn1_string)->data;
    in_a2 = ((pAVar2->value).asn1_string)->length;
    psVar3 = (stack_st_X509_ALGOR *)
             (*(code *)PTR_ASN1_item_d2i_006a9798)(0,ppuVar10,in_a2,PTR_X509_ALGORS_it_006aa2c8);
  }
  if (local_c == *(int *)puVar1) {
    return psVar3;
  }
  iVar9 = local_c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar4 = (undefined4 *)(*(code *)PTR_X509_ALGOR_new_006a8fb8)();
  if (puVar4 == (undefined4 *)0x0) {
    uVar5 = 0x66;
  }
  else {
    (*(code *)PTR_ASN1_OBJECT_free_006a8104)(*puVar4);
    uVar5 = (*(code *)PTR_OBJ_nid2obj_006a8240)(ppuVar10);
    *puVar4 = uVar5;
    if (in_a2 < 1) {
LAB_005a8df8:
      (*(code *)PTR_sk_push_006a80a8)(iVar9,puVar4);
      return (stack_st_X509_ALGOR *)0x1;
    }
    iVar6 = (*(code *)PTR_ASN1_TYPE_new_006a8fbc)();
    puVar4[1] = iVar6;
    if (iVar6 == 0) {
      uVar5 = 0x6e;
    }
    else {
      iVar6 = (*(code *)PTR_ASN1_INTEGER_new_006a8260)();
      if (iVar6 != 0) {
        iVar7 = (*(code *)PTR_ASN1_INTEGER_set_006a8264)(iVar6,in_a2);
        if (iVar7 == 0) {
          (*(code *)PTR_ERR_put_error_006a9030)(0x21,0x77,0x41,"pk7_attr.c",0x76);
          return (stack_st_X509_ALGOR *)0x0;
        }
        puVar8 = (undefined4 *)puVar4[1];
        puVar8[1] = iVar6;
        *puVar8 = 2;
        goto LAB_005a8df8;
      }
      uVar5 = 0x72;
    }
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x21,0x77,0x41,"pk7_attr.c",uVar5);
  return (stack_st_X509_ALGOR *)0x0;
}

