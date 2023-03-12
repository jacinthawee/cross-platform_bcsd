
OCSP_RESPONSE * OCSP_sendreq_bio(BIO *b,char *path,OCSP_REQUEST *req)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  ASN1_OBJECT *pAVar4;
  OCSP_CERTID *pOVar5;
  int iVar6;
  undefined4 uVar7;
  ASN1_OBJECT *pAVar8;
  ASN1_TYPE *pAVar9;
  ASN1_INTEGER *pAVar10;
  OCSP_RESPONSE *pOVar11;
  undefined4 *puVar12;
  ASN1_OBJECT *pAVar13;
  ASN1_OBJECT *pAVar14;
  undefined4 uVar15;
  char *pcVar16;
  X509_ALGOR *pXVar17;
  ASN1_OBJECT **unaff_s7;
  code *pcVar18;
  undefined4 uStack_140;
  ASN1_OBJECT aAStack_13c [2];
  undefined4 *puStack_fc;
  OCSP_CERTID *pOStack_f4;
  int iStack_f0;
  undefined *puStack_ec;
  ASN1_OBJECT *pAStack_e8;
  undefined4 uStack_e4;
  int iStack_e0;
  ASN1_OBJECT **ppAStack_dc;
  ASN1_OBJECT **ppAStack_d8;
  code *pcStack_d4;
  int iStack_c0;
  undefined4 uStack_bc;
  undefined *puStack_b8;
  ASN1_OBJECT *pAStack_b0;
  ASN1_OBJECT aAStack_ac [2];
  int iStack_6c;
  int iStack_64;
  ASN1_OBJECT *pAStack_60;
  undefined4 uStack_5c;
  OCSP_RESPONSE **ppOStack_58;
  BIO *pBStack_54;
  undefined *puStack_50;
  OCSP_RESPONSE *local_28;
  int local_24;
  
  puStack_50 = PTR___stack_chk_guard_006aabf0;
  pcVar16 = (char *)0xffffffff;
  ppOStack_58 = &local_28;
  local_28 = (OCSP_RESPONSE *)0x0;
  local_24 = *(int *)PTR___stack_chk_guard_006aabf0;
  pAStack_60 = (ASN1_OBJECT *)OCSP_sendreq_new(b,path,req,-1);
  do {
    pAVar4 = pAStack_60;
    iStack_64 = OCSP_sendreq_nbio(ppOStack_58,(OCSP_REQ_CTX *)pAStack_60);
    if (iStack_64 != -1) break;
    pAVar4 = (ASN1_OBJECT *)&DAT_00000008;
    iVar3 = (*(code *)PTR_BIO_test_flags_006a8954)(b);
  } while (iVar3 != 0);
  if (pAStack_60->data != (uchar *)0x0) {
    (*(code *)PTR_BIO_free_006a7f70)();
  }
  if ((ASN1_TYPE *)pAStack_60->ln != (ASN1_TYPE *)0x0) {
    (*(code *)PTR_CRYPTO_free_006a7f88)();
  }
  (*(code *)PTR_CRYPTO_free_006a7f88)(pAStack_60);
  pOVar11 = local_28;
  if (iStack_64 == 0) {
    pOVar11 = (OCSP_RESPONSE *)0x0;
  }
  if (local_24 == *(int *)puStack_50) {
    return pOVar11;
  }
  iStack_f0 = local_24;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_ec = PTR___stack_chk_guard_006aabf0;
  uStack_5c = 0xffffffff;
  puStack_b8 = &_gp;
  iStack_6c = *(int *)PTR___stack_chk_guard_006aabf0;
  pAVar13 = pAVar4;
  pAVar14 = (ASN1_OBJECT *)req;
  pBStack_54 = b;
  if (iStack_f0 == 0) {
    iStack_f0 = (*(code *)PTR_EVP_sha1_006a86c4)();
  }
  if (pAVar4 == (ASN1_OBJECT *)0x0) {
    iStack_e0 = 0;
    uStack_e4 = (**(code **)(puStack_b8 + -0x7ee0))(req);
  }
  else {
    uStack_e4 = (**(code **)(puStack_b8 + -0x7710))(pAVar4);
    iStack_e0 = (**(code **)(puStack_b8 + -0x7e44))(pAVar4);
  }
  ppAStack_dc = (ASN1_OBJECT **)(**(code **)(puStack_b8 + -0x6fc8))(req);
  pOStack_f4 = OCSP_CERTID_new();
  if (pOStack_f4 == (OCSP_CERTID *)0x0) {
LAB_005afbd0:
    pAStack_b0 = pAVar14;
    pOVar5 = (OCSP_CERTID *)0x0;
  }
  else {
    req = (OCSP_REQUEST *)pOStack_f4->hashAlgorithm;
    if ((ASN1_OBJECT *)((ASN1_OBJECT *)req)->sn != (ASN1_OBJECT *)0x0) {
      (**(code **)(puStack_b8 + -0x7ddc))();
    }
    iVar3 = (**(code **)(puStack_b8 + -0x7a14))(iStack_f0);
    if (iVar3 == 0) {
      pcVar18 = *(code **)(puStack_b8 + -0x6eb0);
      pAVar14 = (ASN1_OBJECT *)&DAT_00000078;
      iStack_c0 = 0x74;
LAB_005afbac:
      pcVar16 = "ocsp_lib.c";
      pAVar13 = (ASN1_OBJECT *)&DAT_00000065;
      (*pcVar18)(0x27);
LAB_005afbc0:
      OCSP_CERTID_free(pOStack_f4);
      goto LAB_005afbd0;
    }
    pAVar4 = (ASN1_OBJECT *)(**(code **)(puStack_b8 + -0x7ca0))(iVar3);
    ((ASN1_OBJECT *)req)->sn = (char *)pAVar4;
    if (pAVar4 == (ASN1_OBJECT *)0x0) goto LAB_005afbc0;
    pAVar9 = (ASN1_TYPE *)(**(code **)(puStack_b8 + -0x6f24))();
    ((ASN1_OBJECT *)req)->ln = (char **)pAVar9;
    if (pAVar9 == (ASN1_TYPE *)0x0) goto LAB_005afbc0;
    pcVar18 = *(code **)(puStack_b8 + -0x5b68);
    unaff_s7 = &pAStack_b0;
    req = (OCSP_REQUEST *)aAStack_ac;
    pAVar9->type = 5;
    pcVar16 = (char *)unaff_s7;
    iVar3 = (*pcVar18)(uStack_e4,iStack_f0,req);
    if (iVar3 == 0) {
      pcVar18 = *(code **)(puStack_b8 + -0x6eb0);
      pAVar14 = (ASN1_OBJECT *)0x66;
      iStack_c0 = 0x8b;
      goto LAB_005afbac;
    }
    pAVar13 = (ASN1_OBJECT *)req;
    pAVar14 = pAStack_b0;
    iVar3 = (**(code **)(puStack_b8 + -0x6750))(pOStack_f4->issuerNameHash);
    if (iVar3 == 0) goto LAB_005afbc0;
    pAVar13 = *ppAStack_dc;
    uStack_bc = 0;
    pAVar14 = (ASN1_OBJECT *)req;
    pcVar16 = (char *)unaff_s7;
    iStack_c0 = iStack_f0;
    iVar3 = (**(code **)(puStack_b8 + -0x73dc))(ppAStack_dc[2]);
    if ((iVar3 == 0) ||
       (pAVar13 = (ASN1_OBJECT *)req,
       iVar3 = (**(code **)(puStack_b8 + -0x6750))(pOStack_f4->issuerKeyHash), pAVar14 = pAStack_b0,
       iVar3 == 0)) goto LAB_005afbc0;
    pOVar5 = pOStack_f4;
    if (iStack_e0 != 0) {
      (**(code **)(puStack_b8 + -0x7f4c))(pOStack_f4->serialNumber);
      pAVar10 = (ASN1_INTEGER *)(**(code **)(puStack_b8 + -0x5b64))(iStack_e0);
      pOStack_f4->serialNumber = pAVar10;
      pAVar14 = pAStack_b0;
      if (pAVar10 == (ASN1_INTEGER *)0x0) goto LAB_005afbc0;
    }
  }
  if (iStack_6c == *(int *)puStack_ec) {
    return (OCSP_RESPONSE *)pOVar5;
  }
  pcStack_d4 = OCSP_cert_id_new;
  iVar3 = iStack_6c;
  (**(code **)(puStack_b8 + -0x5328))();
  puVar2 = PTR___stack_chk_guard_006aabf0;
  puStack_fc = *(undefined4 **)PTR___stack_chk_guard_006aabf0;
  pAVar4 = pAVar13;
  pAStack_e8 = (ASN1_OBJECT *)req;
  ppAStack_d8 = unaff_s7;
  pOVar5 = OCSP_CERTID_new();
  if (pOVar5 != (OCSP_CERTID *)0x0) {
    pXVar17 = pOVar5->hashAlgorithm;
    if (pXVar17->algorithm != (ASN1_OBJECT *)0x0) {
      (*(code *)PTR_ASN1_OBJECT_free_006a8104)();
    }
    iVar6 = (*(code *)PTR_EVP_MD_type_006a84cc)(iVar3);
    if (iVar6 == 0) {
      uVar15 = 0x78;
      uVar7 = 0x74;
LAB_005afe00:
      pAVar14 = (ASN1_OBJECT *)&DAT_00000065;
      (*(code *)PTR_ERR_put_error_006a9030)(0x27,0x65,uVar15,"ocsp_lib.c",uVar7);
    }
    else {
      pAVar8 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_nid2obj_006a8240)(iVar6);
      pXVar17->algorithm = pAVar8;
      pAVar14 = pAVar4;
      if (pAVar8 != (ASN1_OBJECT *)0x0) {
        pAVar9 = (ASN1_TYPE *)(*(code *)PTR_ASN1_TYPE_new_006a8fbc)();
        pXVar17->parameter = pAVar9;
        puVar1 = PTR_X509_NAME_digest_006aa378;
        pAVar14 = pAVar4;
        if (pAVar9 != (ASN1_TYPE *)0x0) {
          pAVar4 = aAStack_13c;
          pAVar9->type = 5;
          iVar6 = (*(code *)puVar1)(pAVar13,iVar3,pAVar4,&uStack_140);
          if (iVar6 == 0) {
            uVar15 = 0x66;
            uVar7 = 0x8b;
            goto LAB_005afe00;
          }
          pAVar14 = pAVar4;
          iVar6 = (*(code *)PTR_ASN1_OCTET_STRING_set_006a9790)
                            (pOVar5->issuerNameHash,pAVar4,uStack_140);
          if (iVar6 != 0) {
            pAVar14 = (ASN1_OBJECT *)pAStack_b0->sn;
            iVar3 = (*(code *)PTR_EVP_Digest_006a8b04)
                              (pAStack_b0->nid,pAVar14,pAVar4,&uStack_140,iVar3,0);
            if ((iVar3 != 0) &&
               (iVar3 = (*(code *)PTR_ASN1_OCTET_STRING_set_006a9790)
                                  (pOVar5->issuerKeyHash,pAVar4,uStack_140), pAVar14 = pAVar4,
               iVar3 != 0)) {
              if ((ASN1_OBJECT **)pcVar16 == (ASN1_OBJECT **)0x0) goto LAB_005afe28;
              (*(code *)PTR_ASN1_INTEGER_free_006a7f94)(pOVar5->serialNumber);
              pAVar10 = (ASN1_INTEGER *)(*(code *)PTR_ASN1_INTEGER_dup_006aa37c)(pcVar16);
              pOVar5->serialNumber = pAVar10;
              pAVar14 = pAVar4;
              if (pAVar10 != (ASN1_INTEGER *)0x0) goto LAB_005afe28;
            }
          }
        }
      }
    }
    OCSP_CERTID_free(pOVar5);
    pAVar4 = pAVar14;
  }
  pOVar5 = (OCSP_CERTID *)0x0;
LAB_005afe28:
  if (puStack_fc == *(undefined4 **)puVar2) {
    return (OCSP_RESPONSE *)pOVar5;
  }
  puVar12 = puStack_fc;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  pOVar11 = (OCSP_RESPONSE *)
            (*(code *)PTR_OBJ_cmp_006a9de4)(*(undefined4 *)*puVar12,((ASN1_OBJECT *)pAVar4->sn)->sn)
  ;
  if ((pOVar11 == (OCSP_RESPONSE *)0x0) &&
     (pOVar11 = (OCSP_RESPONSE *)
                (*(code *)PTR_ASN1_OCTET_STRING_cmp_006a9ffc)(puVar12[1],(ASN1_TYPE *)pAVar4->ln),
     pOVar11 == (OCSP_RESPONSE *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x005b0000. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pOVar11 = (OCSP_RESPONSE *)(*(code *)PTR_ASN1_OCTET_STRING_cmp_006a9ffc)(puVar12[2],pAVar4->nid)
    ;
    return pOVar11;
  }
  return pOVar11;
}

