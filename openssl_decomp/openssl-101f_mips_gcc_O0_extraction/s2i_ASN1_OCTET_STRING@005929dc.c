
ASN1_OCTET_STRING * s2i_ASN1_OCTET_STRING(X509V3_EXT_METHOD *method,X509V3_CTX *ctx,char *str)

{
  undefined *puVar1;
  ASN1_OCTET_STRING *pAVar2;
  uchar *puVar3;
  int iVar4;
  int iVar5;
  ASN1_OCTET_STRING *pAVar6;
  X509_EXTENSION *ext;
  X509_NAME *pXVar7;
  GENERAL_NAME *pGVar8;
  int *len;
  undefined4 uVar9;
  int iVar10;
  X509 *x;
  GENERAL_NAMES *pGVar11;
  int iVar12;
  ASN1_INTEGER *pAVar13;
  int iVar14;
  char *pcVar15;
  undefined4 uVar16;
  int local_18;
  int local_14;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_14 = *(int *)PTR___stack_chk_guard_006aabf0;
  pcVar15 = str;
  pAVar2 = (ASN1_OCTET_STRING *)(*(code *)PTR_ASN1_STRING_type_new_006a97a4)(4);
  if (pAVar2 == (ASN1_OCTET_STRING *)0x0) {
    pcVar15 = &DAT_00000041;
    len = (int *)&DAT_00000070;
    (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x70,0x41,"v3_skey.c",0x56);
    pAVar2 = (ASN1_OCTET_STRING *)0x0;
  }
  else {
    len = &local_18;
    puVar3 = string_to_hex(str,len);
    pAVar2->data = puVar3;
    if (puVar3 == (uchar *)0x0) {
      (*(code *)PTR_ASN1_STRING_free_006a98bc)(pAVar2);
      pAVar2 = (ASN1_OCTET_STRING *)0x0;
    }
    else {
      pAVar2->length = local_18;
    }
  }
  if (local_14 == *(int *)puVar1) {
    return pAVar2;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar14 = 0;
  iVar12 = 0;
  iVar10 = 0;
  while (iVar4 = (*(code *)PTR_sk_num_006a7f2c)(pcVar15), iVar10 < iVar4) {
    iVar4 = (*(code *)PTR_sk_value_006a7f24)(pcVar15,iVar10);
    uVar16 = *(undefined4 *)(iVar4 + 4);
    iVar5 = (*(code *)PTR_strcmp_006aac20)(uVar16,"keyid");
    if (iVar5 == 0) {
      if (*(int *)(iVar4 + 8) == 0) {
        iVar12 = 1;
        iVar10 = iVar10 + 1;
      }
      else {
        iVar12 = 1;
        iVar4 = (*(code *)PTR_strcmp_006aac20)(*(int *)(iVar4 + 8),"always");
        iVar10 = iVar10 + 1;
        if (iVar4 == 0) {
          iVar12 = 2;
        }
      }
    }
    else {
      iVar14 = (*(code *)PTR_strcmp_006aac20)(uVar16,"issuer");
      if (iVar14 != 0) {
        (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x77,0x78,"v3_akey.c",0x8f);
        (*(code *)PTR_ERR_add_error_data_006a9264)(2,"name=",*(undefined4 *)(iVar4 + 4));
        return (ASN1_OCTET_STRING *)0x0;
      }
      if (*(int *)(iVar4 + 8) == 0) {
        iVar14 = 1;
        iVar10 = iVar10 + 1;
      }
      else {
        iVar14 = 1;
        iVar4 = (*(code *)PTR_strcmp_006aac20)(*(int *)(iVar4 + 8),"always");
        iVar10 = iVar10 + 1;
        if (iVar4 == 0) {
          iVar14 = 2;
        }
      }
    }
  }
  if (len != (int *)0x0) {
    x = (X509 *)len[1];
    if (x != (X509 *)0x0) {
      if (iVar12 == 0) {
LAB_00592c2c:
        pAVar2 = (ASN1_OCTET_STRING *)0x0;
        if (iVar14 == 0) {
LAB_00592c38:
          pAVar13 = (ASN1_INTEGER *)0x0;
          pAVar6 = (ASN1_OCTET_STRING *)AUTHORITY_KEYID_new();
          if (pAVar6 != (ASN1_OCTET_STRING *)0x0) {
            pGVar11 = (GENERAL_NAMES *)0x0;
            goto LAB_00592c50;
          }
          pcVar15 = (char *)0x0;
          goto LAB_00592efc;
        }
LAB_00592ecc:
        pAVar2 = (ASN1_OCTET_STRING *)0x0;
      }
      else {
        iVar10 = X509_get_ext_by_NID(x,0x52,-1);
        if ((iVar10 < 0) || (ext = X509_get_ext(x,iVar10), ext == (X509_EXTENSION *)0x0)) {
          if (iVar12 == 2) {
LAB_00592e7c:
            uVar9 = 0x7b;
            uVar16 = 0xa6;
            goto LAB_00592ea4;
          }
          goto LAB_00592c2c;
        }
        pAVar2 = (ASN1_OCTET_STRING *)X509V3_EXT_d2i(ext);
        if (iVar12 != 2) {
          if (iVar14 == 0) goto LAB_00592c38;
          if (pAVar2 != (ASN1_OCTET_STRING *)0x0) goto LAB_00592da4;
          goto LAB_00592ecc;
        }
        if (pAVar2 == (ASN1_OCTET_STRING *)0x0) goto LAB_00592e7c;
        if (iVar14 == 0) goto LAB_00592c38;
LAB_00592da4:
        if (iVar14 != 2) goto LAB_00592c38;
      }
      pXVar7 = X509_get_issuer_name(x);
      pcVar15 = (char *)(*(code *)PTR_X509_NAME_dup_006a823c)(pXVar7);
      pAVar13 = X509_get_serialNumber(x);
      pAVar13 = (ASN1_INTEGER *)(*(code *)PTR_ASN1_STRING_dup_006a9ddc)(pAVar13);
      if ((pcVar15 == (char *)0x0) || (pAVar13 == (ASN1_INTEGER *)0x0)) {
        uVar9 = 0x7a;
        uVar16 = 0xb1;
      }
      else {
        pAVar6 = (ASN1_OCTET_STRING *)AUTHORITY_KEYID_new();
        if (pAVar6 == (ASN1_OCTET_STRING *)0x0) goto LAB_00592efc;
        pGVar11 = (GENERAL_NAMES *)(*(code *)PTR_sk_new_null_006a80a4)();
        if (((pGVar11 != (GENERAL_NAMES *)0x0) &&
            (pGVar8 = GENERAL_NAME_new(), pGVar8 != (GENERAL_NAME *)0x0)) &&
           (iVar10 = (*(code *)PTR_sk_push_006a80a8)(pGVar11,pGVar8), iVar10 != 0)) {
          (pGVar8->d).ptr = pcVar15;
          pGVar8->type = 4;
LAB_00592c50:
          pAVar6->type = (int)pGVar11;
          pAVar6->data = (uchar *)pAVar13;
          pAVar6->length = (int)pAVar2;
          return pAVar6;
        }
        uVar9 = 0x41;
        uVar16 = 0xbe;
      }
      (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x77,uVar9,"v3_akey.c",uVar16);
LAB_00592efc:
      (*(code *)PTR_X509_NAME_free_006a80f8)(pcVar15);
      (*(code *)PTR_ASN1_STRING_free_006a98bc)(pAVar13);
      (*(code *)PTR_ASN1_STRING_free_006a98bc)(pAVar2);
      return (ASN1_OCTET_STRING *)0x0;
    }
    if (*len == 1) {
      pAVar2 = (ASN1_OCTET_STRING *)AUTHORITY_KEYID_new();
      return pAVar2;
    }
  }
  uVar9 = 0x79;
  uVar16 = 0x99;
LAB_00592ea4:
  (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x77,uVar9,"v3_akey.c",uVar16);
  return (ASN1_OCTET_STRING *)0x0;
}

