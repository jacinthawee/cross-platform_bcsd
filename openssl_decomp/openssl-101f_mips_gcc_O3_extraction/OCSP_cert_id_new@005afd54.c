
OCSP_CERTID *
OCSP_cert_id_new(EVP_MD *dgst,X509_NAME *issuerName,ASN1_BIT_STRING *issuerKey,
                ASN1_INTEGER *serialNumber)

{
  undefined *puVar1;
  undefined *puVar2;
  OCSP_CERTID *pOVar3;
  int iVar4;
  undefined4 uVar5;
  ASN1_OBJECT *pAVar6;
  ASN1_TYPE *pAVar7;
  ASN1_INTEGER *pAVar8;
  undefined4 *puVar9;
  X509_NAME *pXVar10;
  X509_NAME *pXVar11;
  undefined4 uVar12;
  X509_ALGOR *pXVar13;
  undefined4 local_70;
  X509_NAME aXStack_6c [3];
  undefined4 *local_2c;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(undefined4 **)PTR___stack_chk_guard_006aabf0;
  pXVar10 = issuerName;
  pOVar3 = OCSP_CERTID_new();
  if (pOVar3 != (OCSP_CERTID *)0x0) {
    pXVar13 = pOVar3->hashAlgorithm;
    if (pXVar13->algorithm != (ASN1_OBJECT *)0x0) {
      (*(code *)PTR_ASN1_OBJECT_free_006a8104)();
    }
    iVar4 = (*(code *)PTR_EVP_MD_type_006a84cc)(dgst);
    if (iVar4 == 0) {
      uVar12 = 0x78;
      uVar5 = 0x74;
LAB_005afe00:
      pXVar11 = (X509_NAME *)&DAT_00000065;
      (*(code *)PTR_ERR_put_error_006a9030)(0x27,0x65,uVar12,"ocsp_lib.c",uVar5);
    }
    else {
      pAVar6 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_nid2obj_006a8240)(iVar4);
      pXVar13->algorithm = pAVar6;
      pXVar11 = pXVar10;
      if (pAVar6 != (ASN1_OBJECT *)0x0) {
        pAVar7 = (ASN1_TYPE *)(*(code *)PTR_ASN1_TYPE_new_006a8fbc)();
        pXVar13->parameter = pAVar7;
        puVar1 = PTR_X509_NAME_digest_006aa378;
        pXVar11 = pXVar10;
        if (pAVar7 != (ASN1_TYPE *)0x0) {
          pXVar10 = aXStack_6c;
          pAVar7->type = 5;
          iVar4 = (*(code *)puVar1)(issuerName,dgst,pXVar10,&local_70);
          if (iVar4 == 0) {
            uVar12 = 0x66;
            uVar5 = 0x8b;
            goto LAB_005afe00;
          }
          pXVar11 = pXVar10;
          iVar4 = (*(code *)PTR_ASN1_OCTET_STRING_set_006a9790)
                            (pOVar3->issuerNameHash,pXVar10,local_70);
          if (iVar4 != 0) {
            pXVar11 = (X509_NAME *)issuerKey->length;
            iVar4 = (*(code *)PTR_EVP_Digest_006a8b04)
                              (issuerKey->data,pXVar11,pXVar10,&local_70,dgst,0);
            if ((iVar4 != 0) &&
               (iVar4 = (*(code *)PTR_ASN1_OCTET_STRING_set_006a9790)
                                  (pOVar3->issuerKeyHash,pXVar10,local_70), pXVar11 = pXVar10,
               iVar4 != 0)) {
              if (serialNumber == (ASN1_INTEGER *)0x0) goto LAB_005afe28;
              (*(code *)PTR_ASN1_INTEGER_free_006a7f94)(pOVar3->serialNumber);
              pAVar8 = (ASN1_INTEGER *)(*(code *)PTR_ASN1_INTEGER_dup_006aa37c)(serialNumber);
              pOVar3->serialNumber = pAVar8;
              pXVar11 = pXVar10;
              if (pAVar8 != (ASN1_INTEGER *)0x0) goto LAB_005afe28;
            }
          }
        }
      }
    }
    OCSP_CERTID_free(pOVar3);
    pXVar10 = pXVar11;
  }
  pOVar3 = (OCSP_CERTID *)0x0;
LAB_005afe28:
  if (local_2c == *(undefined4 **)puVar2) {
    return pOVar3;
  }
  puVar9 = local_2c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  pOVar3 = (OCSP_CERTID *)
           (*(code *)PTR_OBJ_cmp_006a9de4)(*(undefined4 *)*puVar9,(pXVar10->entries->stack).num);
  if ((pOVar3 == (OCSP_CERTID *)0x0) &&
     (pOVar3 = (OCSP_CERTID *)
               (*(code *)PTR_ASN1_OCTET_STRING_cmp_006a9ffc)(puVar9[1],pXVar10->modified),
     pOVar3 == (OCSP_CERTID *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x005b0000. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pOVar3 = (OCSP_CERTID *)(*(code *)PTR_ASN1_OCTET_STRING_cmp_006a9ffc)(puVar9[2],pXVar10->bytes);
    return pOVar3;
  }
  return pOVar3;
}

