
uint ocsp_match_issuerid(undefined4 param_1,undefined4 *param_2,undefined4 *param_3,char *param_4)

{
  undefined *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  OCSP_CERTID **ppOVar6;
  X509 *x;
  undefined4 uVar7;
  int iVar8;
  int *piVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  int iVar12;
  undefined4 *unaff_s4;
  undefined4 *unaff_s5;
  int iVar13;
  OCSP_CERTID *b;
  int unaff_s6;
  int *piVar14;
  OCSP_CERTID *pOStack_158;
  undefined auStack_150 [136];
  undefined auStack_c8 [20];
  int iStack_b4;
  undefined4 *puStack_b0;
  undefined4 *puStack_ac;
  undefined4 uStack_a8;
  undefined *puStack_a4;
  undefined4 *puStack_a0;
  undefined4 *puStack_9c;
  undefined4 auStack_64 [16];
  int *local_24;
  
  puStack_a4 = PTR___stack_chk_guard_006a9ae8;
  local_24 = *(int **)PTR___stack_chk_guard_006a9ae8;
  puVar10 = param_2;
  puVar11 = param_3;
  if (param_2 == (undefined4 *)0x0) {
    for (; iVar12 = (*(code *)PTR_sk_num_006a6e2c)(param_3), (int)param_2 < iVar12;
        param_2 = (undefined4 *)((int)param_2 + 1)) {
      puVar10 = (undefined4 *)(*(code *)PTR_sk_value_006a6e24)(param_3,param_2);
      puVar11 = (undefined4 *)0x0;
      puVar10 = (undefined4 *)*puVar10;
      uVar4 = ocsp_match_issuerid(param_1);
      if ((int)uVar4 < 1) goto LAB_005afafc;
    }
    uVar4 = 1;
  }
  else {
    uVar2 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*(undefined4 *)*param_2);
    uVar2 = (*(code *)PTR_OBJ_nid2sn_006a709c)(uVar2);
    puVar3 = (undefined4 *)(*(code *)PTR_EVP_get_digestbyname_006a6f2c)(uVar2);
    if (puVar3 == (undefined4 *)0x0) {
      puVar11 = (undefined4 *)&DAT_00000077;
      param_4 = "ocsp_vfy.c";
      puVar10 = (undefined4 *)&DAT_0000006d;
      (*(code *)PTR_ERR_put_error_006a7f34)(0x27);
      uVar4 = 0xffffffff;
      param_3 = puVar3;
    }
    else {
      unaff_s4 = (undefined4 *)(*(code *)PTR_EVP_MD_size_006a7e3c)(puVar3);
      puVar11 = param_3;
      if ((int)unaff_s4 < 0) {
LAB_005afc24:
        uVar4 = 0xffffffff;
        param_3 = puVar3;
      }
      else if (unaff_s4 == *(undefined4 **)param_2[1]) {
        uVar4 = 0;
        param_3 = puVar3;
        if (unaff_s4 == *(undefined4 **)param_2[2]) {
          unaff_s5 = auStack_64;
          uVar2 = (*(code *)PTR_X509_get_subject_name_006a6f00)(param_1);
          param_4 = (char *)0x0;
          puVar10 = puVar3;
          puVar11 = unaff_s5;
          iVar12 = (*(code *)PTR_X509_NAME_digest_006a926c)(uVar2);
          if (iVar12 == 0) goto LAB_005afc24;
          puVar10 = *(undefined4 **)(param_2[1] + 8);
          param_3 = unaff_s4;
          iVar12 = (*(code *)PTR_memcmp_006a9ad0)(unaff_s5);
          if (iVar12 != 0) goto LAB_005afaf8;
          param_4 = (char *)0x0;
          (*(code *)PTR_X509_pubkey_digest_006a92ac)(param_1,puVar3,unaff_s5);
          puVar10 = *(undefined4 **)(param_2[2] + 8);
          puVar11 = unaff_s4;
          iVar12 = (*(code *)PTR_memcmp_006a9ad0)(unaff_s5);
          uVar4 = (uint)(iVar12 == 0);
          param_3 = puVar3;
        }
      }
      else {
LAB_005afaf8:
        uVar4 = 0;
        puVar11 = param_3;
        param_3 = puVar3;
      }
    }
  }
LAB_005afafc:
  if (local_24 == *(int **)puStack_a4) {
    return uVar4;
  }
  piVar9 = local_24;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  piVar14 = *(int **)(*piVar9 + 4);
  iStack_b4 = *(int *)PTR___stack_chk_guard_006a9ae8;
  puStack_b0 = param_2;
  puStack_ac = param_3;
  uStack_a8 = param_1;
  puStack_a0 = unaff_s4;
  puStack_9c = unaff_s5;
  if (*piVar14 != 0) {
    if (*(int *)piVar14[1] == 0x14) {
      iVar13 = ((int *)piVar14[1])[2];
      for (iVar12 = 0; iVar5 = (*(code *)PTR_sk_num_006a6e2c)(puVar10), iVar12 < iVar5;
          iVar12 = iVar12 + 1) {
        unaff_s6 = (*(code *)PTR_sk_value_006a6e24)(puVar10,iVar12);
        uVar2 = (*(code *)PTR_EVP_sha1_006a75d0)();
        (*(code *)PTR_X509_pubkey_digest_006a92ac)(unaff_s6,uVar2,auStack_c8,0);
        iVar5 = (*(code *)PTR_memcmp_006a9ad0)(iVar13,auStack_c8,0x14);
        if (iVar5 == 0) goto LAB_005afdc0;
      }
    }
LAB_005afd68:
    if (((uint)param_4 & 2) == 0) {
      iVar12 = piVar9[3];
      if (*piVar14 == 0) {
        unaff_s6 = (*(code *)PTR_X509_find_by_subject_006a92b4)(iVar12,piVar14[1]);
LAB_005b0288:
        uVar4 = 1;
        if (unaff_s6 != 0) goto LAB_005afdd0;
      }
      else if (*(int *)piVar14[1] == 0x14) {
        iVar5 = ((int *)piVar14[1])[2];
        for (iVar13 = 0; iVar8 = (*(code *)PTR_sk_num_006a6e2c)(iVar12), iVar13 < iVar8;
            iVar13 = iVar13 + 1) {
          unaff_s6 = (*(code *)PTR_sk_value_006a6e24)(iVar12,iVar13);
          uVar2 = (*(code *)PTR_EVP_sha1_006a75d0)();
          (*(code *)PTR_X509_pubkey_digest_006a92ac)(unaff_s6,uVar2,auStack_c8,0);
          iVar8 = (*(code *)PTR_memcmp_006a9ad0)(iVar5,auStack_c8,0x14);
          if (iVar8 == 0) goto LAB_005b0288;
        }
      }
    }
    uVar4 = 0;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x27,0x69,0x76,"ocsp_vfy.c",0x5c);
    iVar12 = 0;
    goto LAB_005afdec;
  }
  unaff_s6 = (*(code *)PTR_X509_find_by_subject_006a92b4)(puVar10,piVar14[1]);
LAB_005afdc0:
  if (unaff_s6 == 0) goto LAB_005afd68;
  uVar4 = 2;
  if (((uint)param_4 & 0x200) != 0) {
    param_4 = (char *)((uint)param_4 | 0x10);
  }
LAB_005afdd0:
  if (((uint)param_4 & 4) == 0) {
    iVar12 = (*(code *)PTR_X509_get_pubkey_006a6f08)(unaff_s6);
    if (iVar12 != 0) {
      uVar4 = (*(code *)PTR_ASN1_item_verify_006a8d20)
                        (PTR_OCSP_RESPDATA_it_006a92b0,piVar9[1],piVar9[2],*piVar9,iVar12);
      (*(code *)PTR_EVP_PKEY_free_006a6e78)(iVar12);
      if (0 < (int)uVar4) goto LAB_005afddc;
    }
    iVar12 = 0;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x27,0x69,0x75,"ocsp_vfy.c",0x69);
LAB_005afdec:
    while( true ) {
      if ((piVar9[3] != 0) && (puVar10 != (undefined4 *)0x0)) {
        (*(code *)PTR_sk_free_006a6e80)(iVar12);
      }
      if (iStack_b4 == *(int *)puVar1) break;
      (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_005b03c0:
      uVar4 = 0xffffffff;
      (*(code *)PTR_ERR_put_error_006a7f34)(0x27,0x6b,0x6f,"ocsp_vfy.c",0x11a);
LAB_005aff4c:
      if (unaff_s6 != 0) {
        (*(code *)PTR_sk_pop_free_006a7058)(unaff_s6,PTR_X509_free_006a6e90);
      }
    }
    return uVar4;
  }
LAB_005afddc:
  if (((uint)param_4 & 0x10) != 0) {
    iVar12 = 0;
    goto LAB_005afdec;
  }
  iVar12 = 0;
  if (((((uint)param_4 & 8) == 0) && (iVar12 = piVar9[3], iVar12 != 0)) &&
     (puVar10 != (undefined4 *)0x0)) {
    iVar12 = (*(code *)PTR_sk_dup_006a7f54)(iVar12);
    for (iVar13 = 0; iVar5 = (*(code *)PTR_sk_num_006a6e2c)(puVar10), iVar13 < iVar5;
        iVar13 = iVar13 + 1) {
      uVar2 = (*(code *)PTR_sk_value_006a6e24)(puVar10,iVar13);
      iVar5 = (*(code *)PTR_sk_push_006a6fa8)(iVar12,uVar2);
      if (iVar5 == 0) {
        (*(code *)PTR_ERR_put_error_006a7f34)(0x27,0x69,0x41,"ocsp_vfy.c",0x75);
        goto LAB_005afdec;
      }
    }
  }
  iVar13 = (*(code *)PTR_X509_STORE_CTX_init_006a7270)(auStack_150,puVar11,unaff_s6,iVar12);
  if (iVar13 == 0) {
    uVar4 = 0xffffffff;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x27,0x69,0xb,"ocsp_vfy.c",0x7f);
    goto LAB_005afdec;
  }
  (*(code *)PTR_X509_STORE_CTX_set_purpose_006a9168)(auStack_150,8);
  uVar4 = (*(code *)PTR_X509_verify_cert_006a728c)(auStack_150);
  unaff_s6 = (*(code *)PTR_X509_STORE_CTX_get1_chain_006a7290)(auStack_150);
  (*(code *)PTR_X509_STORE_CTX_cleanup_006a7294)(auStack_150);
  if ((int)uVar4 < 1) {
    uVar2 = (*(code *)PTR_X509_STORE_CTX_get_error_006a729c)(auStack_150);
    (*(code *)PTR_ERR_put_error_006a7f34)(0x27,0x69,0x65,"ocsp_vfy.c",0x8a);
    uVar2 = (*(code *)PTR_X509_verify_cert_error_string_006a72a0)(uVar2);
    (*(code *)PTR_ERR_add_error_data_006a813c)(2,"Verify error:",uVar2);
    goto LAB_005aff4c;
  }
  if (((uint)param_4 & 0x100) != 0) goto LAB_005aff48;
  uVar2 = *(undefined4 *)(*piVar9 + 0xc);
  iVar13 = (*(code *)PTR_sk_num_006a6e2c)(unaff_s6);
  if (iVar13 < 1) {
    uVar4 = 0xffffffff;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x27,0x6c,0x69,"ocsp_vfy.c",0xed);
    goto LAB_005aff4c;
  }
  iVar13 = (*(code *)PTR_sk_num_006a6e2c)(uVar2);
  if (iVar13 < 1) goto LAB_005b03c0;
  ppOVar6 = (OCSP_CERTID **)(*(code *)PTR_sk_value_006a6e24)(uVar2,0);
  pOStack_158 = *ppOVar6;
  if (iVar13 != 1) {
    iVar5 = 1;
    do {
      ppOVar6 = (OCSP_CERTID **)(*(code *)PTR_sk_value_006a6e24)(uVar2,iVar5);
      b = *ppOVar6;
      iVar8 = OCSP_id_issuer_cmp(pOStack_158,b);
      if (iVar8 != 0) {
        iVar13 = (*(code *)PTR_OBJ_cmp_006a8cc4)
                           (b->hashAlgorithm->algorithm,pOStack_158->hashAlgorithm->algorithm);
        if (iVar13 == 0) goto LAB_005b0134;
        pOStack_158 = (OCSP_CERTID *)0x0;
        break;
      }
      iVar5 = iVar5 + 1;
    } while (iVar13 != iVar5);
  }
  x = (X509 *)(*(code *)PTR_sk_value_006a6e24)(unaff_s6,0);
  iVar13 = (*(code *)PTR_sk_num_006a6e2c)(unaff_s6);
  if (iVar13 < 2) {
LAB_005b0118:
    uVar4 = ocsp_match_issuerid(x,pOStack_158,uVar2);
    if (uVar4 != 0) goto LAB_005aff4c;
  }
  else {
    uVar7 = (*(code *)PTR_sk_value_006a6e24)(unaff_s6,1);
    uVar4 = ocsp_match_issuerid(uVar7,pOStack_158,uVar2);
    if ((int)uVar4 < 0) goto LAB_005aff4c;
    if (uVar4 == 0) goto LAB_005b0118;
    X509_check_purpose(x,-1,0);
    if (((x->ex_flags & 4) != 0) && ((x->ex_xkusage & 0x20) != 0)) goto LAB_005aff48;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x27,0x6a,0x67,"ocsp_vfy.c",0x168);
  }
LAB_005b0134:
  uVar4 = 0;
  if (((uint)param_4 & 0x20) != 0) goto LAB_005aff4c;
  iVar13 = (*(code *)PTR_sk_num_006a6e2c)(unaff_s6);
  uVar2 = (*(code *)PTR_sk_value_006a6e24)(unaff_s6,iVar13 + -1);
  iVar13 = (*(code *)PTR_X509_check_trust_006a8f0c)(uVar2,0xb4,0);
  if (iVar13 != 1) {
    uVar4 = 0;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x27,0x69,0x70,"ocsp_vfy.c",0xa6);
    goto LAB_005aff4c;
  }
LAB_005aff48:
  uVar4 = 1;
  goto LAB_005aff4c;
}

