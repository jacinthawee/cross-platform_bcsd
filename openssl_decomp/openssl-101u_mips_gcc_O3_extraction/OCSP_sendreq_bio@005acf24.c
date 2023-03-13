
OCSP_RESPONSE * OCSP_sendreq_bio(BIO *b,char *path,OCSP_REQUEST *req)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  OCSP_CERTID *pOVar4;
  int iVar5;
  undefined4 uVar6;
  ASN1_OBJECT *pAVar7;
  ASN1_TYPE *pAVar8;
  ASN1_INTEGER *pAVar9;
  OCSP_RESPONSE *pOVar10;
  undefined4 *puVar11;
  ASN1_OBJECT *pAVar12;
  ASN1_OBJECT *pAVar13;
  ASN1_OBJECT *pAVar14;
  undefined4 uVar15;
  char *pcVar16;
  int unaff_s0;
  ASN1_OBJECT *unaff_s1;
  undefined4 unaff_s2;
  X509_ALGOR *pXVar17;
  OCSP_RESPONSE **unaff_s3;
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
  
  puStack_50 = PTR___stack_chk_guard_006a9ae8;
  pcVar16 = (char *)0xffffffff;
  local_28 = (OCSP_RESPONSE *)0x0;
  local_24 = *(int *)PTR___stack_chk_guard_006a9ae8;
  pAStack_60 = (ASN1_OBJECT *)OCSP_sendreq_new(b,path,req,-1);
  if (pAStack_60 == (ASN1_OBJECT *)0x0) {
LAB_005ad030:
    pOVar10 = (OCSP_RESPONSE *)0x0;
    pAStack_60 = unaff_s1;
  }
  else {
    unaff_s3 = &local_28;
    unaff_s2 = 0xffffffff;
    do {
      path = (char *)pAStack_60;
      unaff_s0 = OCSP_sendreq_nbio(unaff_s3,(OCSP_REQ_CTX *)pAStack_60);
      if (unaff_s0 != -1) break;
      path = &DAT_00000008;
      iVar3 = (*(code *)PTR_BIO_test_flags_006a7868)(b);
    } while (iVar3 != 0);
    if (pAStack_60->data != (uchar *)0x0) {
      (*(code *)PTR_BIO_free_006a6e70)();
    }
    if ((ASN1_TYPE *)pAStack_60->ln != (ASN1_TYPE *)0x0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
    (*(code *)PTR_CRYPTO_free_006a6e88)(pAStack_60);
    pOVar10 = local_28;
    unaff_s1 = pAStack_60;
    if (unaff_s0 == 0) goto LAB_005ad030;
  }
  if (local_24 == *(int *)puStack_50) {
    return pOVar10;
  }
  iStack_f0 = local_24;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_ec = PTR___stack_chk_guard_006a9ae8;
  puStack_b8 = &_gp;
  iStack_6c = *(int *)PTR___stack_chk_guard_006a9ae8;
  pAVar12 = (ASN1_OBJECT *)path;
  pAVar14 = (ASN1_OBJECT *)req;
  iStack_64 = unaff_s0;
  uStack_5c = unaff_s2;
  ppOStack_58 = unaff_s3;
  pBStack_54 = b;
  if (iStack_f0 == 0) {
    iStack_f0 = (*(code *)PTR_EVP_sha1_006a75d0)();
  }
  if ((ASN1_OBJECT *)path == (ASN1_OBJECT *)0x0) {
    iStack_e0 = 0;
    uStack_e4 = (**(code **)(puStack_b8 + -0x7ee0))(req);
  }
  else {
    uStack_e4 = (**(code **)(puStack_b8 + -0x76fc))(path);
    iStack_e0 = (**(code **)(puStack_b8 + -0x7e44))(path);
  }
  ppAStack_dc = (ASN1_OBJECT **)(**(code **)(puStack_b8 + -0x6fb8))(req);
  pOStack_f4 = OCSP_CERTID_new();
  if (pOStack_f4 == (OCSP_CERTID *)0x0) {
LAB_005ad160:
    pAStack_b0 = pAVar14;
    pOVar4 = (OCSP_CERTID *)0x0;
  }
  else {
    req = (OCSP_REQUEST *)pOStack_f4->hashAlgorithm;
    if ((ASN1_OBJECT *)((ASN1_OBJECT *)req)->sn != (ASN1_OBJECT *)0x0) {
      (**(code **)(puStack_b8 + -0x7ddc))();
    }
    iVar3 = (**(code **)(puStack_b8 + -0x7a14))(iStack_f0);
    if (iVar3 == 0) {
      pcVar18 = *(code **)(puStack_b8 + -0x6eac);
      pAVar14 = (ASN1_OBJECT *)&DAT_00000078;
      iStack_c0 = 0x75;
LAB_005ad13c:
      pcVar16 = "ocsp_lib.c";
      pAVar12 = (ASN1_OBJECT *)&DAT_00000065;
      (*pcVar18)(0x27);
LAB_005ad150:
      OCSP_CERTID_free(pOStack_f4);
      goto LAB_005ad160;
    }
    pAVar13 = (ASN1_OBJECT *)(**(code **)(puStack_b8 + -0x7ca0))(iVar3);
    ((ASN1_OBJECT *)req)->sn = (char *)pAVar13;
    if (pAVar13 == (ASN1_OBJECT *)0x0) goto LAB_005ad150;
    pAVar8 = (ASN1_TYPE *)(**(code **)(puStack_b8 + -0x6f14))();
    ((ASN1_OBJECT *)req)->ln = (char **)pAVar8;
    if (pAVar8 == (ASN1_TYPE *)0x0) goto LAB_005ad150;
    pcVar18 = *(code **)(puStack_b8 + -0x5b74);
    unaff_s7 = &pAStack_b0;
    req = (OCSP_REQUEST *)aAStack_ac;
    pAVar8->type = 5;
    pcVar16 = (char *)unaff_s7;
    iVar3 = (*pcVar18)(uStack_e4,iStack_f0,req);
    if (iVar3 == 0) {
      pcVar18 = *(code **)(puStack_b8 + -0x6eac);
      pAVar14 = (ASN1_OBJECT *)0x66;
      iStack_c0 = 0x91;
      goto LAB_005ad13c;
    }
    pAVar12 = (ASN1_OBJECT *)req;
    pAVar14 = pAStack_b0;
    iVar3 = (**(code **)(puStack_b8 + -0x6774))(pOStack_f4->issuerNameHash);
    if (iVar3 == 0) goto LAB_005ad150;
    pAVar12 = *ppAStack_dc;
    uStack_bc = 0;
    pAVar14 = (ASN1_OBJECT *)req;
    pcVar16 = (char *)unaff_s7;
    iStack_c0 = iStack_f0;
    iVar3 = (**(code **)(puStack_b8 + -0x73cc))(ppAStack_dc[2]);
    if ((iVar3 == 0) ||
       (pAVar12 = (ASN1_OBJECT *)req,
       iVar3 = (**(code **)(puStack_b8 + -0x6774))(pOStack_f4->issuerKeyHash), pAVar14 = pAStack_b0,
       iVar3 == 0)) goto LAB_005ad150;
    pOVar4 = pOStack_f4;
    if (iStack_e0 != 0) {
      (**(code **)(puStack_b8 + -0x7f4c))(pOStack_f4->serialNumber);
      pAVar9 = (ASN1_INTEGER *)(**(code **)(puStack_b8 + -0x5b70))(iStack_e0);
      pOStack_f4->serialNumber = pAVar9;
      pAVar14 = pAStack_b0;
      if (pAVar9 == (ASN1_INTEGER *)0x0) goto LAB_005ad150;
    }
  }
  if (iStack_6c == *(int *)puStack_ec) {
    return (OCSP_RESPONSE *)pOVar4;
  }
  pcStack_d4 = OCSP_cert_id_new;
  iVar3 = iStack_6c;
  (**(code **)(puStack_b8 + -0x5330))();
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  puStack_fc = *(undefined4 **)PTR___stack_chk_guard_006a9ae8;
  pAVar14 = pAVar12;
  pAStack_e8 = (ASN1_OBJECT *)req;
  ppAStack_d8 = unaff_s7;
  pOVar4 = OCSP_CERTID_new();
  if (pOVar4 != (OCSP_CERTID *)0x0) {
    pXVar17 = pOVar4->hashAlgorithm;
    if (pXVar17->algorithm != (ASN1_OBJECT *)0x0) {
      (*(code *)PTR_ASN1_OBJECT_free_006a7004)();
    }
    iVar5 = (*(code *)PTR_EVP_MD_type_006a73cc)(iVar3);
    if (iVar5 == 0) {
      uVar15 = 0x78;
      uVar6 = 0x75;
LAB_005ad390:
      pAVar13 = (ASN1_OBJECT *)&DAT_00000065;
      (*(code *)PTR_ERR_put_error_006a7f34)(0x27,0x65,uVar15,"ocsp_lib.c",uVar6);
    }
    else {
      pAVar7 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_nid2obj_006a7140)(iVar5);
      pXVar17->algorithm = pAVar7;
      pAVar13 = pAVar14;
      if (pAVar7 != (ASN1_OBJECT *)0x0) {
        pAVar8 = (ASN1_TYPE *)(*(code *)PTR_ASN1_TYPE_new_006a7ecc)();
        pXVar17->parameter = pAVar8;
        puVar1 = PTR_X509_NAME_digest_006a926c;
        pAVar13 = pAVar14;
        if (pAVar8 != (ASN1_TYPE *)0x0) {
          pAVar14 = aAStack_13c;
          pAVar8->type = 5;
          iVar5 = (*(code *)puVar1)(pAVar12,iVar3,pAVar14,&uStack_140);
          if (iVar5 == 0) {
            uVar15 = 0x66;
            uVar6 = 0x91;
            goto LAB_005ad390;
          }
          pAVar13 = pAVar14;
          iVar5 = (*(code *)PTR_ASN1_OCTET_STRING_set_006a866c)
                            (pOVar4->issuerNameHash,pAVar14,uStack_140);
          if (iVar5 != 0) {
            pAVar13 = (ASN1_OBJECT *)pAStack_b0->sn;
            iVar3 = (*(code *)PTR_EVP_Digest_006a7a14)
                              (pAStack_b0->nid,pAVar13,pAVar14,&uStack_140,iVar3,0);
            if ((iVar3 != 0) &&
               (iVar3 = (*(code *)PTR_ASN1_OCTET_STRING_set_006a866c)
                                  (pOVar4->issuerKeyHash,pAVar14,uStack_140), pAVar13 = pAVar14,
               iVar3 != 0)) {
              if ((ASN1_OBJECT **)pcVar16 == (ASN1_OBJECT **)0x0) goto LAB_005ad3b8;
              (*(code *)PTR_ASN1_INTEGER_free_006a6e94)(pOVar4->serialNumber);
              pAVar9 = (ASN1_INTEGER *)(*(code *)PTR_ASN1_INTEGER_dup_006a9270)(pcVar16);
              pOVar4->serialNumber = pAVar9;
              pAVar13 = pAVar14;
              if (pAVar9 != (ASN1_INTEGER *)0x0) goto LAB_005ad3b8;
            }
          }
        }
      }
    }
    OCSP_CERTID_free(pOVar4);
    pAVar14 = pAVar13;
  }
  pOVar4 = (OCSP_CERTID *)0x0;
LAB_005ad3b8:
  if (puStack_fc == *(undefined4 **)puVar2) {
    return (OCSP_RESPONSE *)pOVar4;
  }
  puVar11 = puStack_fc;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  pOVar10 = (OCSP_RESPONSE *)
            (*(code *)PTR_OBJ_cmp_006a8cc4)
                      (*(undefined4 *)*puVar11,((ASN1_OBJECT *)pAVar14->sn)->sn);
  if ((pOVar10 == (OCSP_RESPONSE *)0x0) &&
     (pOVar10 = (OCSP_RESPONSE *)
                (*(code *)PTR_ASN1_OCTET_STRING_cmp_006a8ee0)(puVar11[1],(ASN1_TYPE *)pAVar14->ln),
     pOVar10 == (OCSP_RESPONSE *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x005ad590. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pOVar10 = (OCSP_RESPONSE *)
              (*(code *)PTR_ASN1_OCTET_STRING_cmp_006a8ee0)(puVar11[2],pAVar14->nid);
    return pOVar10;
  }
  return pOVar10;
}

