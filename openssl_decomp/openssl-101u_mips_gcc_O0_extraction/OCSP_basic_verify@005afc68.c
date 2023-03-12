
int OCSP_basic_verify(OCSP_BASICRESP *bs,stack_st_X509 *certs,X509_STORE *st,ulong flags)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  OCSP_CERTID **ppOVar4;
  X509 *x;
  undefined4 uVar5;
  int iVar6;
  stack_st_X509 *psVar7;
  BUF_MEM *pBVar8;
  OCSP_CERTID *b;
  int unaff_s6;
  OCSP_RESPID *pOVar9;
  stack_st_OCSP_SINGLERESP *psVar10;
  OCSP_CERTID *local_d0;
  undefined auStack_c8 [136];
  undefined auStack_40 [20];
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  pOVar9 = bs->tbsResponseData->responderId;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (pOVar9->type != 0) {
    if (((pOVar9->value).byName)->entries == (stack_st_X509_NAME_ENTRY *)0x14) {
      pBVar8 = ((pOVar9->value).byName)->bytes;
      for (iVar6 = 0; iVar2 = (*(code *)PTR_sk_num_006a6e2c)(certs), iVar6 < iVar2;
          iVar6 = iVar6 + 1) {
        unaff_s6 = (*(code *)PTR_sk_value_006a6e24)(certs,iVar6);
        uVar5 = (*(code *)PTR_EVP_sha1_006a75d0)();
        (*(code *)PTR_X509_pubkey_digest_006a92ac)(unaff_s6,uVar5,auStack_40,0);
        iVar2 = (*(code *)PTR_memcmp_006a9ad0)(pBVar8,auStack_40,0x14);
        if (iVar2 == 0) goto LAB_005afdc0;
      }
    }
LAB_005afd68:
    if ((flags & 2) == 0) {
      psVar7 = bs->certs;
      if (pOVar9->type == 0) {
        unaff_s6 = (*(code *)PTR_X509_find_by_subject_006a92b4)(psVar7,(pOVar9->value).byName);
LAB_005b0288:
        iVar6 = 1;
        if (unaff_s6 != 0) goto LAB_005afdd0;
      }
      else if (((pOVar9->value).byName)->entries == (stack_st_X509_NAME_ENTRY *)0x14) {
        pBVar8 = ((pOVar9->value).byName)->bytes;
        for (iVar6 = 0; iVar2 = (*(code *)PTR_sk_num_006a6e2c)(psVar7), iVar6 < iVar2;
            iVar6 = iVar6 + 1) {
          unaff_s6 = (*(code *)PTR_sk_value_006a6e24)(psVar7,iVar6);
          uVar5 = (*(code *)PTR_EVP_sha1_006a75d0)();
          (*(code *)PTR_X509_pubkey_digest_006a92ac)(unaff_s6,uVar5,auStack_40,0);
          iVar2 = (*(code *)PTR_memcmp_006a9ad0)(pBVar8,auStack_40,0x14);
          if (iVar2 == 0) goto LAB_005b0288;
        }
      }
    }
    iVar6 = 0;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x27,0x69,0x76,"ocsp_vfy.c",0x5c);
    psVar7 = (stack_st_X509 *)0x0;
    goto LAB_005afdec;
  }
  unaff_s6 = (*(code *)PTR_X509_find_by_subject_006a92b4)(certs,(pOVar9->value).byName);
LAB_005afdc0:
  if (unaff_s6 == 0) goto LAB_005afd68;
  iVar6 = 2;
  if ((flags & 0x200) != 0) {
    flags = flags | 0x10;
  }
LAB_005afdd0:
  if ((flags & 4) == 0) {
    iVar2 = (*(code *)PTR_X509_get_pubkey_006a6f08)(unaff_s6);
    if (iVar2 != 0) {
      iVar6 = (*(code *)PTR_ASN1_item_verify_006a8d20)
                        (PTR_OCSP_RESPDATA_it_006a92b0,bs->signatureAlgorithm,bs->signature,
                         bs->tbsResponseData,iVar2);
      (*(code *)PTR_EVP_PKEY_free_006a6e78)(iVar2);
      if (0 < iVar6) goto LAB_005afddc;
    }
    psVar7 = (stack_st_X509 *)0x0;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x27,0x69,0x75,"ocsp_vfy.c",0x69);
LAB_005afdec:
    while( true ) {
      if ((bs->certs != (stack_st_X509 *)0x0) && (certs != (stack_st_X509 *)0x0)) {
        (*(code *)PTR_sk_free_006a6e80)(psVar7);
      }
      if (local_2c == *(int *)puVar1) break;
      (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_005b03c0:
      iVar6 = -1;
      (*(code *)PTR_ERR_put_error_006a7f34)(0x27,0x6b,0x6f,"ocsp_vfy.c",0x11a);
LAB_005aff4c:
      if (unaff_s6 != 0) {
        (*(code *)PTR_sk_pop_free_006a7058)(unaff_s6,PTR_X509_free_006a6e90);
      }
    }
    return iVar6;
  }
LAB_005afddc:
  if ((flags & 0x10) != 0) {
    psVar7 = (stack_st_X509 *)0x0;
    goto LAB_005afdec;
  }
  psVar7 = (stack_st_X509 *)0x0;
  if ((((flags & 8) == 0) && (psVar7 = bs->certs, psVar7 != (stack_st_X509 *)0x0)) &&
     (certs != (stack_st_X509 *)0x0)) {
    psVar7 = (stack_st_X509 *)(*(code *)PTR_sk_dup_006a7f54)(psVar7);
    for (iVar2 = 0; iVar3 = (*(code *)PTR_sk_num_006a6e2c)(certs), iVar2 < iVar3; iVar2 = iVar2 + 1)
    {
      uVar5 = (*(code *)PTR_sk_value_006a6e24)(certs,iVar2);
      iVar3 = (*(code *)PTR_sk_push_006a6fa8)(psVar7,uVar5);
      if (iVar3 == 0) {
        (*(code *)PTR_ERR_put_error_006a7f34)(0x27,0x69,0x41,"ocsp_vfy.c",0x75);
        goto LAB_005afdec;
      }
    }
  }
  iVar6 = (*(code *)PTR_X509_STORE_CTX_init_006a7270)(auStack_c8,st,unaff_s6,psVar7);
  if (iVar6 == 0) {
    iVar6 = -1;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x27,0x69,0xb,"ocsp_vfy.c",0x7f);
    goto LAB_005afdec;
  }
  (*(code *)PTR_X509_STORE_CTX_set_purpose_006a9168)(auStack_c8,8);
  iVar6 = (*(code *)PTR_X509_verify_cert_006a728c)(auStack_c8);
  unaff_s6 = (*(code *)PTR_X509_STORE_CTX_get1_chain_006a7290)(auStack_c8);
  (*(code *)PTR_X509_STORE_CTX_cleanup_006a7294)(auStack_c8);
  if (iVar6 < 1) {
    uVar5 = (*(code *)PTR_X509_STORE_CTX_get_error_006a729c)(auStack_c8);
    (*(code *)PTR_ERR_put_error_006a7f34)(0x27,0x69,0x65,"ocsp_vfy.c",0x8a);
    uVar5 = (*(code *)PTR_X509_verify_cert_error_string_006a72a0)(uVar5);
    (*(code *)PTR_ERR_add_error_data_006a813c)(2,"Verify error:",uVar5);
    goto LAB_005aff4c;
  }
  if ((flags & 0x100) != 0) goto LAB_005aff48;
  psVar10 = bs->tbsResponseData->responses;
  iVar6 = (*(code *)PTR_sk_num_006a6e2c)(unaff_s6);
  if (iVar6 < 1) {
    iVar6 = -1;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x27,0x6c,0x69,"ocsp_vfy.c",0xed);
    goto LAB_005aff4c;
  }
  iVar6 = (*(code *)PTR_sk_num_006a6e2c)(psVar10);
  if (iVar6 < 1) goto LAB_005b03c0;
  ppOVar4 = (OCSP_CERTID **)(*(code *)PTR_sk_value_006a6e24)(psVar10,0);
  local_d0 = *ppOVar4;
  if (iVar6 != 1) {
    iVar2 = 1;
    do {
      ppOVar4 = (OCSP_CERTID **)(*(code *)PTR_sk_value_006a6e24)(psVar10,iVar2);
      b = *ppOVar4;
      iVar3 = OCSP_id_issuer_cmp(local_d0,b);
      if (iVar3 != 0) {
        iVar6 = (*(code *)PTR_OBJ_cmp_006a8cc4)
                          (b->hashAlgorithm->algorithm,local_d0->hashAlgorithm->algorithm);
        if (iVar6 == 0) goto LAB_005b0134;
        local_d0 = (OCSP_CERTID *)0x0;
        break;
      }
      iVar2 = iVar2 + 1;
    } while (iVar6 != iVar2);
  }
  x = (X509 *)(*(code *)PTR_sk_value_006a6e24)(unaff_s6,0);
  iVar6 = (*(code *)PTR_sk_num_006a6e2c)(unaff_s6);
  if (iVar6 < 2) {
LAB_005b0118:
    iVar6 = ocsp_match_issuerid(x,local_d0,psVar10);
    if (iVar6 != 0) goto LAB_005aff4c;
  }
  else {
    uVar5 = (*(code *)PTR_sk_value_006a6e24)(unaff_s6,1);
    iVar6 = ocsp_match_issuerid(uVar5,local_d0,psVar10);
    if (iVar6 < 0) goto LAB_005aff4c;
    if (iVar6 == 0) goto LAB_005b0118;
    X509_check_purpose(x,-1,0);
    if (((x->ex_flags & 4) != 0) && ((x->ex_xkusage & 0x20) != 0)) goto LAB_005aff48;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x27,0x6a,0x67,"ocsp_vfy.c",0x168);
  }
LAB_005b0134:
  iVar6 = 0;
  if ((flags & 0x20) != 0) goto LAB_005aff4c;
  iVar6 = (*(code *)PTR_sk_num_006a6e2c)(unaff_s6);
  uVar5 = (*(code *)PTR_sk_value_006a6e24)(unaff_s6,iVar6 + -1);
  iVar6 = (*(code *)PTR_X509_check_trust_006a8f0c)(uVar5,0xb4,0);
  if (iVar6 != 1) {
    iVar6 = 0;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x27,0x69,0x70,"ocsp_vfy.c",0xa6);
    goto LAB_005aff4c;
  }
LAB_005aff48:
  iVar6 = 1;
  goto LAB_005aff4c;
}

