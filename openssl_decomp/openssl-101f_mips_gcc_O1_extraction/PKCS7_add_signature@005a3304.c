
PKCS7_SIGNER_INFO * PKCS7_add_signature(PKCS7 *p7,X509 *x509,EVP_PKEY *pkey,EVP_MD *dgst)

{
  undefined *puVar1;
  undefined *puVar2;
  X509 *p7i;
  int iVar3;
  ASN1_INTEGER *pAVar4;
  undefined4 uVar5;
  char *pcVar6;
  PKCS7_SIGNER_INFO *pPVar7;
  X509 *pXVar8;
  ASN1_OBJECT *pAVar9;
  ASN1_BIT_STRING *pAVar10;
  ASN1_STRING *pAVar11;
  X509_ALGOR *pXVar12;
  code *pcVar13;
  X509_CINF *local_28;
  X509_ALGOR *local_24;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  local_24 = *(X509_ALGOR **)PTR___stack_chk_guard_006aabf0;
  pXVar8 = x509;
  if (dgst == (EVP_MD *)0x0) {
    pXVar8 = (X509 *)&local_28;
    iVar3 = (*(code *)PTR_EVP_PKEY_get_default_digest_nid_006a8198)(pkey,pXVar8);
    if (0 < iVar3) {
      uVar5 = (*(code *)PTR_OBJ_nid2sn_006a819c)(local_28);
      dgst = (EVP_MD *)(*(code *)PTR_EVP_get_digestbyname_006a802c)(uVar5);
      if (dgst != (EVP_MD *)0x0) goto LAB_005a3354;
      pXVar8 = (X509 *)0x83;
      (*(code *)PTR_ERR_put_error_006a9030)(0x21,0x83,0x97,"pk7_lib.c",0x1ab);
    }
  }
  else {
LAB_005a3354:
    p7i = (X509 *)PKCS7_SIGNER_INFO_new();
    if (p7i != (X509 *)0x0) {
      pXVar8 = (X509 *)0x1;
      iVar3 = (*(code *)PTR_ASN1_INTEGER_set_006a8264)(p7i->cert_info,1);
      if (iVar3 != 0) {
        pXVar12 = p7i->sig_alg;
        pXVar8 = (X509 *)(*(code *)PTR_X509_get_issuer_name_006a87d0)(x509);
        iVar3 = (*(code *)PTR_X509_NAME_set_006aa048)(pXVar12,pXVar8);
        if (iVar3 != 0) {
          (*(code *)PTR_ASN1_STRING_free_006a98bc)((ASN1_INTEGER *)p7i->sig_alg->parameter);
          pXVar12 = p7i->sig_alg;
          uVar5 = (*(code *)PTR_X509_get_serialNumber_006a809c)(x509);
          pAVar4 = (ASN1_INTEGER *)(*(code *)PTR_ASN1_STRING_dup_006a9ddc)(uVar5);
          pXVar12->parameter = (ASN1_TYPE *)pAVar4;
          if (pAVar4 != (ASN1_INTEGER *)0x0) {
            (*(code *)PTR_CRYPTO_add_lock_006a9080)(&pkey->references,1,10,"pk7_lib.c",0x182);
            puVar1 = PTR_EVP_MD_type_006a84cc;
            pAVar10 = p7i->signature;
            (p7i->ex_data).dummy = (int)pkey;
            uVar5 = (*(code *)puVar1)(dgst);
            uVar5 = (*(code *)PTR_OBJ_nid2obj_006a8240)(uVar5);
            (*(code *)PTR_X509_ALGOR_set0_006a9e04)(pAVar10,uVar5,5,0);
            if ((pkey->ameth == (EVP_PKEY_ASN1_METHOD *)0x0) ||
               (pcVar13 = *(code **)(pkey->ameth + 0x58), pcVar13 == (code *)0x0)) {
LAB_005a3564:
              pXVar8 = (X509 *)0x81;
              (*(code *)PTR_ERR_put_error_006a9030)(0x21,0x81,0x94,"pk7_lib.c",0x198);
            }
            else {
              iVar3 = (*pcVar13)(pkey,1,0,p7i);
              if (iVar3 < 1) {
                if (iVar3 == -2) goto LAB_005a3564;
                pXVar8 = (X509 *)0x81;
                (*(code *)PTR_ERR_put_error_006a9030)(0x21,0x81,0x93,"pk7_lib.c",0x193);
              }
              else {
                pXVar8 = p7i;
                iVar3 = PKCS7_add_signer(p7,(PKCS7_SIGNER_INFO *)p7i);
                if (iVar3 != 0) goto LAB_005a3398;
              }
            }
          }
        }
      }
      PKCS7_SIGNER_INFO_free((PKCS7_SIGNER_INFO *)p7i);
    }
  }
  p7i = (X509 *)0x0;
LAB_005a3398:
  if (local_24 == *(X509_ALGOR **)puVar2) {
    return (PKCS7_SIGNER_INFO *)p7i;
  }
  pXVar12 = local_24;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar3 = (*(code *)PTR_OBJ_obj2nid_006a822c)(pXVar12[2].algorithm);
  if (iVar3 == 0x19) {
    pAVar11 = ((pXVar12[2].parameter)->value).asn1_string;
    iVar3 = (*(code *)PTR_ASN1_TYPE_new_006a8fbc)();
    pAVar11->type = iVar3;
    puVar2 = PTR_EVP_MD_type_006a84cc;
    if (iVar3 != 0) {
      pAVar9 = ((pXVar12[2].parameter)->value).object;
      *pAVar9->ln = &DAT_00000005;
      uVar5 = (*(code *)puVar2)(pXVar8);
      pcVar6 = (char *)(*(code *)PTR_OBJ_nid2obj_006a8240)(uVar5);
      pAVar9->sn = pcVar6;
      return (PKCS7_SIGNER_INFO *)0x1;
    }
    (*(code *)PTR_ERR_put_error_006a9030)(0x21,0x7e,0x41,"pk7_lib.c",0x1c0);
    pPVar7 = (PKCS7_SIGNER_INFO *)0x0;
  }
  else {
    (*(code *)PTR_ERR_put_error_006a9030)(0x21,0x7e,0x71,"pk7_lib.c",0x1c8);
    pPVar7 = (PKCS7_SIGNER_INFO *)0x1;
  }
  return pPVar7;
}

