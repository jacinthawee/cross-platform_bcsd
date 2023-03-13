
OCSP_CERTID * OCSP_cert_to_id(EVP_MD *dgst,X509 *subject,X509 *issuer)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  X509_CINF *pXVar4;
  OCSP_CERTID *pOVar5;
  int iVar6;
  undefined4 uVar7;
  ASN1_OBJECT *pAVar8;
  ASN1_TYPE *pAVar9;
  ASN1_INTEGER *pAVar10;
  undefined4 *puVar11;
  X509 *pXVar12;
  X509 *pXVar13;
  X509 *pXVar14;
  undefined4 uVar15;
  char *in_a3;
  X509_ALGOR *pXVar16;
  X509 **unaff_s7;
  code *pcVar17;
  undefined4 uStack_100;
  undefined auStack_fc [100];
  X509 **ppXStack_98;
  code *pcStack_94;
  EVP_MD *local_80;
  undefined4 local_7c;
  undefined *local_78;
  X509 *local_70 [17];
  int local_2c;
  
  auStack_fc._80_4_ = (stack_st_IPAddressFamily *)PTR___stack_chk_guard_006a9ae8;
  local_78 = &_gp;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  pXVar12 = subject;
  pXVar14 = issuer;
  if (dgst == (EVP_MD *)0x0) {
    dgst = (EVP_MD *)(*(code *)PTR_EVP_sha1_006a75d0)();
  }
  if (subject == (X509 *)0x0) {
    auStack_fc._92_4_ = 0;
    auStack_fc._88_4_ = (**(code **)(local_78 + -0x7ee0))(issuer);
  }
  else {
    auStack_fc._88_4_ = (**(code **)(local_78 + -0x76fc))(subject);
    auStack_fc._92_4_ = (**(code **)(local_78 + -0x7e44))(subject);
  }
  auStack_fc._96_4_ = (X509 **)(**(code **)(local_78 + -0x6fb8))(issuer);
  auStack_fc._72_4_ = OCSP_CERTID_new();
  if (auStack_fc._72_4_ == (OCSP_CERTID *)0x0) {
LAB_005ad160:
    local_70[0] = pXVar14;
    pOVar5 = (OCSP_CERTID *)0x0;
  }
  else {
    issuer = (X509 *)(auStack_fc._72_4_)->hashAlgorithm;
    if (issuer->cert_info != (X509_CINF *)0x0) {
      (**(code **)(local_78 + -0x7ddc))();
    }
    iVar3 = (**(code **)(local_78 + -0x7a14))(dgst);
    if (iVar3 == 0) {
      pcVar17 = *(code **)(local_78 + -0x6eac);
      pXVar14 = (X509 *)&DAT_00000078;
      local_80 = (EVP_MD *)0x75;
LAB_005ad13c:
      in_a3 = "ocsp_lib.c";
      pXVar12 = (X509 *)&DAT_00000065;
      (*pcVar17)(0x27);
LAB_005ad150:
      OCSP_CERTID_free(auStack_fc._72_4_);
      goto LAB_005ad160;
    }
    pXVar4 = (X509_CINF *)(**(code **)(local_78 + -0x7ca0))(iVar3);
    issuer->cert_info = pXVar4;
    if (pXVar4 == (X509_CINF *)0x0) goto LAB_005ad150;
    pXVar16 = (X509_ALGOR *)(**(code **)(local_78 + -0x6f14))();
    issuer->sig_alg = pXVar16;
    if (pXVar16 == (X509_ALGOR *)0x0) goto LAB_005ad150;
    pcVar17 = *(code **)(local_78 + -0x5b74);
    unaff_s7 = local_70;
    issuer = (X509 *)(local_70 + 1);
    pXVar16->algorithm = (ASN1_OBJECT *)0x5;
    in_a3 = (char *)unaff_s7;
    iVar3 = (*pcVar17)(auStack_fc._88_4_,dgst,issuer);
    if (iVar3 == 0) {
      pcVar17 = *(code **)(local_78 + -0x6eac);
      pXVar14 = (X509 *)0x66;
      local_80 = (EVP_MD *)0x91;
      goto LAB_005ad13c;
    }
    pXVar12 = issuer;
    pXVar14 = local_70[0];
    iVar3 = (**(code **)(local_78 + -0x6774))((auStack_fc._72_4_)->issuerNameHash);
    if (iVar3 == 0) goto LAB_005ad150;
    pXVar12 = *auStack_fc._96_4_;
    local_7c = 0;
    pXVar14 = issuer;
    in_a3 = (char *)unaff_s7;
    local_80 = dgst;
    iVar3 = (**(code **)(local_78 + -0x73cc))(auStack_fc._96_4_[2]);
    if ((iVar3 == 0) ||
       (pXVar12 = issuer,
       iVar3 = (**(code **)(local_78 + -0x6774))((auStack_fc._72_4_)->issuerKeyHash),
       pXVar14 = local_70[0], iVar3 == 0)) goto LAB_005ad150;
    pOVar5 = auStack_fc._72_4_;
    if (auStack_fc._92_4_ != 0) {
      (**(code **)(local_78 + -0x7f4c))((auStack_fc._72_4_)->serialNumber);
      pAVar10 = (ASN1_INTEGER *)(**(code **)(local_78 + -0x5b70))(auStack_fc._92_4_);
      (auStack_fc._72_4_)->serialNumber = pAVar10;
      pXVar14 = local_70[0];
      if (pAVar10 == (ASN1_INTEGER *)0x0) goto LAB_005ad150;
    }
  }
  if (local_2c == *(int *)auStack_fc._80_4_) {
    return pOVar5;
  }
  pcStack_94 = OCSP_cert_id_new;
  iVar3 = local_2c;
  (**(code **)(local_78 + -0x5330))();
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  auStack_fc._64_4_ = *(undefined4 **)PTR___stack_chk_guard_006a9ae8;
  pXVar14 = pXVar12;
  auStack_fc._76_4_ = dgst;
  auStack_fc._84_4_ = issuer;
  ppXStack_98 = unaff_s7;
  pOVar5 = OCSP_CERTID_new();
  if (pOVar5 != (OCSP_CERTID *)0x0) {
    pXVar16 = pOVar5->hashAlgorithm;
    if (pXVar16->algorithm != (ASN1_OBJECT *)0x0) {
      (*(code *)PTR_ASN1_OBJECT_free_006a7004)();
    }
    iVar6 = (*(code *)PTR_EVP_MD_type_006a73cc)(iVar3);
    if (iVar6 == 0) {
      uVar15 = 0x78;
      uVar7 = 0x75;
LAB_005ad390:
      pXVar13 = (X509 *)&DAT_00000065;
      (*(code *)PTR_ERR_put_error_006a7f34)(0x27,0x65,uVar15,"ocsp_lib.c",uVar7);
    }
    else {
      pAVar8 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_nid2obj_006a7140)(iVar6);
      pXVar16->algorithm = pAVar8;
      pXVar13 = pXVar14;
      if (pAVar8 != (ASN1_OBJECT *)0x0) {
        pAVar9 = (ASN1_TYPE *)(*(code *)PTR_ASN1_TYPE_new_006a7ecc)();
        pXVar16->parameter = pAVar9;
        puVar1 = PTR_X509_NAME_digest_006a926c;
        pXVar13 = pXVar14;
        if (pAVar9 != (ASN1_TYPE *)0x0) {
          pXVar14 = (X509 *)auStack_fc;
          pAVar9->type = 5;
          iVar6 = (*(code *)puVar1)(pXVar12,iVar3,pXVar14,&uStack_100);
          if (iVar6 == 0) {
            uVar15 = 0x66;
            uVar7 = 0x91;
            goto LAB_005ad390;
          }
          pXVar13 = pXVar14;
          iVar6 = (*(code *)PTR_ASN1_OCTET_STRING_set_006a866c)
                            (pOVar5->issuerNameHash,pXVar14,uStack_100);
          if (iVar6 != 0) {
            pXVar13 = (X509 *)local_70[0]->cert_info;
            iVar3 = (*(code *)PTR_EVP_Digest_006a7a14)
                              (local_70[0]->signature,pXVar13,pXVar14,&uStack_100,iVar3,0);
            if ((iVar3 != 0) &&
               (iVar3 = (*(code *)PTR_ASN1_OCTET_STRING_set_006a866c)
                                  (pOVar5->issuerKeyHash,pXVar14,uStack_100), pXVar13 = pXVar14,
               iVar3 != 0)) {
              if ((X509 **)in_a3 == (X509 **)0x0) goto LAB_005ad3b8;
              (*(code *)PTR_ASN1_INTEGER_free_006a6e94)(pOVar5->serialNumber);
              pAVar10 = (ASN1_INTEGER *)(*(code *)PTR_ASN1_INTEGER_dup_006a9270)(in_a3);
              pOVar5->serialNumber = pAVar10;
              pXVar13 = pXVar14;
              if (pAVar10 != (ASN1_INTEGER *)0x0) goto LAB_005ad3b8;
            }
          }
        }
      }
    }
    OCSP_CERTID_free(pOVar5);
    pXVar14 = pXVar13;
  }
  pOVar5 = (OCSP_CERTID *)0x0;
LAB_005ad3b8:
  if (auStack_fc._64_4_ == *(undefined4 **)puVar2) {
    return pOVar5;
  }
  puVar11 = auStack_fc._64_4_;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  pOVar5 = (OCSP_CERTID *)
           (*(code *)PTR_OBJ_cmp_006a8cc4)(*(undefined4 *)*puVar11,pXVar14->cert_info->version);
  if ((pOVar5 == (OCSP_CERTID *)0x0) &&
     (pOVar5 = (OCSP_CERTID *)
               (*(code *)PTR_ASN1_OCTET_STRING_cmp_006a8ee0)(puVar11[1],pXVar14->sig_alg),
     pOVar5 == (OCSP_CERTID *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x005ad590. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pOVar5 = (OCSP_CERTID *)
             (*(code *)PTR_ASN1_OCTET_STRING_cmp_006a8ee0)(puVar11[2],pXVar14->signature);
    return pOVar5;
  }
  return pOVar5;
}

