
AUTHORITY_KEYID * v2i_AUTHORITY_KEYID(undefined4 param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  AUTHORITY_KEYID *pAVar3;
  X509_EXTENSION *ext;
  X509_NAME *pXVar4;
  GENERAL_NAME *pGVar5;
  undefined4 uVar6;
  int iVar7;
  X509 *x;
  GENERAL_NAMES *pGVar8;
  ASN1_OCTET_STRING *pAVar9;
  int iVar10;
  ASN1_INTEGER *pAVar11;
  int iVar12;
  char *pcVar13;
  undefined4 uVar14;
  
  iVar12 = 0;
  iVar10 = 0;
  iVar7 = 0;
  while (iVar1 = (*(code *)PTR_sk_num_006a6e2c)(param_3), iVar7 < iVar1) {
    iVar1 = (*(code *)PTR_sk_value_006a6e24)(param_3,iVar7);
    uVar14 = *(undefined4 *)(iVar1 + 4);
    iVar2 = (*(code *)PTR_strcmp_006a9b18)(uVar14,"keyid");
    if (iVar2 == 0) {
      if (*(int *)(iVar1 + 8) == 0) {
        iVar10 = 1;
        iVar7 = iVar7 + 1;
      }
      else {
        iVar10 = 1;
        iVar1 = (*(code *)PTR_strcmp_006a9b18)(*(int *)(iVar1 + 8),"always");
        iVar7 = iVar7 + 1;
        if (iVar1 == 0) {
          iVar10 = 2;
        }
      }
    }
    else {
      iVar12 = (*(code *)PTR_strcmp_006a9b18)(uVar14,"issuer");
      if (iVar12 != 0) {
        (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x77,0x78,"v3_akey.c",0x8f);
        (*(code *)PTR_ERR_add_error_data_006a813c)(2,"name=",*(undefined4 *)(iVar1 + 4));
        return (AUTHORITY_KEYID *)0x0;
      }
      if (*(int *)(iVar1 + 8) == 0) {
        iVar12 = 1;
        iVar7 = iVar7 + 1;
      }
      else {
        iVar12 = 1;
        iVar1 = (*(code *)PTR_strcmp_006a9b18)(*(int *)(iVar1 + 8),"always");
        iVar7 = iVar7 + 1;
        if (iVar1 == 0) {
          iVar12 = 2;
        }
      }
    }
  }
  if (param_2 != (int *)0x0) {
    x = (X509 *)param_2[1];
    if (x != (X509 *)0x0) {
      if (iVar10 == 0) {
LAB_0058fe9c:
        pAVar9 = (ASN1_OCTET_STRING *)0x0;
        if (iVar12 == 0) {
LAB_0058fea8:
          pAVar11 = (ASN1_INTEGER *)0x0;
          pAVar3 = AUTHORITY_KEYID_new();
          if (pAVar3 != (AUTHORITY_KEYID *)0x0) {
            pGVar8 = (GENERAL_NAMES *)0x0;
            goto LAB_0058fec0;
          }
          pcVar13 = (char *)0x0;
          goto LAB_0059016c;
        }
LAB_0059013c:
        pAVar9 = (ASN1_OCTET_STRING *)0x0;
      }
      else {
        iVar7 = X509_get_ext_by_NID(x,0x52,-1);
        if ((iVar7 < 0) || (ext = X509_get_ext(x,iVar7), ext == (X509_EXTENSION *)0x0)) {
          if (iVar10 == 2) {
LAB_005900ec:
            uVar6 = 0x7b;
            uVar14 = 0xa5;
            goto LAB_00590114;
          }
          goto LAB_0058fe9c;
        }
        pAVar9 = (ASN1_OCTET_STRING *)X509V3_EXT_d2i(ext);
        if (iVar10 != 2) {
          if (iVar12 == 0) goto LAB_0058fea8;
          if (pAVar9 != (ASN1_OCTET_STRING *)0x0) goto LAB_00590014;
          goto LAB_0059013c;
        }
        if (pAVar9 == (ASN1_OCTET_STRING *)0x0) goto LAB_005900ec;
        if (iVar12 == 0) goto LAB_0058fea8;
LAB_00590014:
        if (iVar12 != 2) goto LAB_0058fea8;
      }
      pXVar4 = X509_get_issuer_name(x);
      pcVar13 = (char *)(*(code *)PTR_X509_NAME_dup_006a713c)(pXVar4);
      pAVar11 = X509_get_serialNumber(x);
      pAVar11 = (ASN1_INTEGER *)(*(code *)PTR_ASN1_STRING_dup_006a8cbc)(pAVar11);
      if ((pcVar13 == (char *)0x0) || (pAVar11 == (ASN1_INTEGER *)0x0)) {
        uVar6 = 0x7a;
        uVar14 = 0xaf;
      }
      else {
        pAVar3 = AUTHORITY_KEYID_new();
        if (pAVar3 == (AUTHORITY_KEYID *)0x0) goto LAB_0059016c;
        pGVar8 = (GENERAL_NAMES *)(*(code *)PTR_sk_new_null_006a6fa4)();
        if (((pGVar8 != (GENERAL_NAMES *)0x0) &&
            (pGVar5 = GENERAL_NAME_new(), pGVar5 != (GENERAL_NAME *)0x0)) &&
           (iVar7 = (*(code *)PTR_sk_push_006a6fa8)(pGVar8,pGVar5), iVar7 != 0)) {
          (pGVar5->d).ptr = pcVar13;
          pGVar5->type = 4;
LAB_0058fec0:
          pAVar3->issuer = pGVar8;
          pAVar3->serial = pAVar11;
          pAVar3->keyid = pAVar9;
          return pAVar3;
        }
        uVar6 = 0x41;
        uVar14 = 0xbb;
      }
      (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x77,uVar6,"v3_akey.c",uVar14);
LAB_0059016c:
      (*(code *)PTR_X509_NAME_free_006a6ff8)(pcVar13);
      (*(code *)PTR_ASN1_STRING_free_006a879c)(pAVar11);
      (*(code *)PTR_ASN1_STRING_free_006a879c)(pAVar9);
      return (AUTHORITY_KEYID *)0x0;
    }
    if (*param_2 == 1) {
      pAVar3 = AUTHORITY_KEYID_new();
      return pAVar3;
    }
  }
  uVar6 = 0x79;
  uVar14 = 0x99;
LAB_00590114:
  (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x77,uVar6,"v3_akey.c",uVar14);
  return (AUTHORITY_KEYID *)0x0;
}

