
int OCSP_basic_verify(OCSP_BASICRESP *bs,stack_st_X509 *certs,X509_STORE *st,ulong flags)

{
  undefined *puVar1;
  int iVar2;
  ASN1_OBJECT **ppAVar3;
  X509 **ppXVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  int *piVar8;
  char *pcVar9;
  undefined4 uVar10;
  OCSP_RESPDATA *pOVar11;
  int iVar12;
  X509 *unaff_s1;
  ASN1_OBJECT *unaff_s3;
  code *pcVar13;
  undefined auStack_19c [136];
  int iStack_114;
  int iStack_10c;
  X509 *pXStack_108;
  X509 *pXStack_104;
  ASN1_OBJECT *pAStack_100;
  ulong uStack_fc;
  ASN1_OBJECT *pAStack_f8;
  code *pcStack_f4;
  X509 *local_e0;
  undefined *local_d8;
  X509_STORE *local_cc;
  X509 XStack_c8;
  ASN1_OBJECT AStack_40;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  pAStack_f8 = (ASN1_OBJECT *)bs->tbsResponseData->responderId;
  AStack_40.flags = *(int *)PTR___stack_chk_guard_006aabf0;
  local_d8 = &_gp;
  pOVar11 = (OCSP_RESPDATA *)flags;
  local_cc = st;
  if ((X509_ALGOR *)pAStack_f8->sn == (X509_ALGOR *)0x0) {
    pcVar9 = (char *)pAStack_f8->ln;
    unaff_s1 = (X509 *)(*(code *)PTR_X509_find_by_subject_006aa3c0)(certs,pcVar9);
LAB_005b2848:
    if (unaff_s1 == (X509 *)0x0) goto LAB_005b27b8;
    iStack_10c = 2;
    if ((flags & 0x200) != 0) {
      flags = flags | 0x10;
    }
LAB_005b2858:
    if ((flags & 4) == 0) {
      certs = (stack_st_X509 *)(**(code **)(local_d8 + -0x7ed8))(unaff_s1);
      if ((X509 *)certs != (X509 *)0x0) {
        pcVar9 = (char *)bs->signatureAlgorithm;
        pOVar11 = bs->tbsResponseData;
        st = (X509_STORE *)bs->signature;
        local_e0 = (X509 *)certs;
        iStack_10c = (**(code **)(local_d8 + -0x60a0))
                               (*(undefined4 *)(local_d8 + -0x5b24),pcVar9,st);
        (**(code **)(local_d8 + -0x7f68))(certs);
        if (0 < iStack_10c) goto LAB_005b2864;
      }
      st = (X509_STORE *)0x75;
      pOVar11 = (OCSP_RESPDATA *)0x0;
      local_e0 = (X509 *)&DAT_00000065;
      pcVar9 = &DAT_00000069;
      (**(code **)(local_d8 + -0x6eb0))(0x27,0x69,0x75);
    }
    else {
LAB_005b2864:
      if ((flags & 0x10) == 0) {
        certs = (stack_st_X509 *)&XStack_c8;
        if ((flags & 8) == 0) {
          pOVar11 = (OCSP_RESPDATA *)bs->certs;
        }
        else {
          pOVar11 = (OCSP_RESPDATA *)0x0;
        }
        st = (X509_STORE *)unaff_s1;
        iVar12 = (**(code **)(local_d8 + -0x7bdc))(certs,local_cc,unaff_s1);
        if (iVar12 == 0) {
          st = (X509_STORE *)&DAT_0000000b;
          pOVar11 = (OCSP_RESPDATA *)0x0;
          local_e0 = (X509 *)&DAT_00000073;
          pcVar9 = &DAT_00000069;
          iStack_10c = -1;
          (**(code **)(local_d8 + -0x6eb0))(0x27,0x69,0xb);
        }
        else {
          pcVar9 = &DAT_00000008;
          (**(code **)(local_d8 + -0x5c5c))(certs,8);
          iStack_10c = (**(code **)(local_d8 + -0x7bd8))(certs);
          unaff_s3 = (ASN1_OBJECT *)(**(code **)(local_d8 + -0x7bd4))(certs);
          (**(code **)(local_d8 + -0x7bd0))(certs);
          if (iStack_10c < 1) {
            unaff_s1 = (X509 *)(**(code **)(local_d8 + -0x7bcc))(certs);
            pOVar11 = (OCSP_RESPDATA *)0x0;
            local_e0 = (X509 *)0x7e;
            (**(code **)(local_d8 + -0x6eb0))(0x27,0x69,0x65);
            st = (X509_STORE *)(**(code **)(local_d8 + -0x7b44))(unaff_s1);
            pcVar9 = "Verify error:";
            (**(code **)(local_d8 + -0x6c7c))(2,"Verify error:",st);
          }
          else if ((flags & 0x100) == 0) {
            certs = (stack_st_X509 *)bs->tbsResponseData->responses;
            iVar12 = (**(code **)(local_d8 + -0x7fb4))(unaff_s3);
            if (iVar12 < 1) {
              st = (X509_STORE *)&DAT_00000069;
              pOVar11 = (OCSP_RESPDATA *)0x0;
              local_e0 = (X509 *)0xe2;
              pcVar9 = &DAT_0000006c;
              iStack_10c = -1;
              (**(code **)(local_d8 + -0x6eb0))(0x27,0x6c,0x69);
            }
            else {
              iVar12 = (**(code **)(local_d8 + -0x7fb4))(certs);
              if (iVar12 < 1) {
                st = (X509_STORE *)&DAT_0000006f;
                pOVar11 = (OCSP_RESPDATA *)0x0;
                local_e0 = (X509 *)0x10d;
                pcVar9 = &DAT_0000006b;
                iStack_10c = -1;
                (**(code **)(local_d8 + -0x6eb0))(0x27,0x6b,0x6f);
              }
              else {
                ppAVar3 = (ASN1_OBJECT **)(**(code **)(local_d8 + -0x7fbc))(certs,0);
                pAStack_f8 = *ppAVar3;
                if (iVar12 == 1) {
LAB_005b2a54:
                  pcVar13 = *(code **)(local_d8 + -0x7fbc);
                }
                else {
                  iVar2 = 1;
                  do {
                    ppXVar4 = (X509 **)(**(code **)(local_d8 + -0x7fbc))(certs,iVar2);
                    unaff_s1 = *ppXVar4;
                    iVar5 = OCSP_id_issuer_cmp((OCSP_CERTID *)pAStack_f8,(OCSP_CERTID *)unaff_s1);
                    if (iVar5 != 0) {
                      pcVar9 = (char *)((X509_ALGOR *)pAStack_f8->sn)->algorithm;
                      iVar12 = (**(code **)(local_d8 + -0x60fc))
                                         (unaff_s1->cert_info->version,pcVar9);
                      if (iVar12 == 0) goto LAB_005b2ad4;
                      pAStack_f8 = (ASN1_OBJECT *)0x0;
                      goto LAB_005b2a54;
                    }
                    iVar2 = iVar2 + 1;
                    pcVar13 = *(code **)(local_d8 + -0x7fbc);
                  } while (iVar12 != iVar2);
                }
                unaff_s1 = (X509 *)(*pcVar13)(unaff_s3,0);
                iVar12 = (**(code **)(local_d8 + -0x7fb4))(unaff_s3);
                if (iVar12 < 2) {
LAB_005b2ab8:
                  pcVar9 = (char *)pAStack_f8;
                  st = (X509_STORE *)certs;
                  iStack_10c = ocsp_match_issuerid(unaff_s1,pAStack_f8,certs);
                  if (iStack_10c == 0) {
LAB_005b2ad4:
                    flags = flags & 0x20;
                    iStack_10c = 0;
                    if (flags == 0) {
                      iVar12 = (**(code **)(local_d8 + -0x7fb4))(unaff_s3);
                      uVar7 = (**(code **)(local_d8 + -0x7fbc))(unaff_s3,iVar12 + -1);
                      st = (X509_STORE *)0x0;
                      pcVar9 = &DAT_000000b4;
                      iVar12 = (**(code **)(local_d8 + -0x5ebc))(uVar7,0xb4,0);
                      if (iVar12 == 1) goto LAB_005b28f4;
                      st = (X509_STORE *)&DAT_00000070;
                      pOVar11 = (OCSP_RESPDATA *)0x0;
                      local_e0 = (X509 *)&DAT_00000098;
                      pcVar9 = &DAT_00000069;
                      iStack_10c = 0;
                      (**(code **)(local_d8 + -0x6eb0))(0x27,0x69,0x70);
                    }
                  }
                }
                else {
                  uVar7 = (**(code **)(local_d8 + -0x7fbc))(unaff_s3,1);
                  pcVar9 = (char *)pAStack_f8;
                  st = (X509_STORE *)certs;
                  iStack_10c = ocsp_match_issuerid(uVar7,pAStack_f8,certs);
                  if (-1 < iStack_10c) {
                    if (iStack_10c == 0) goto LAB_005b2ab8;
                    st = (X509_STORE *)0x0;
                    pcVar9 = (char *)0xffffffff;
                    X509_check_purpose(unaff_s1,-1,0);
                    if (((unaff_s1->ex_flags & 4) != 0) && ((unaff_s1->ex_xkusage & 0x20) != 0))
                    goto LAB_005b28f4;
                    st = (X509_STORE *)0x67;
                    pOVar11 = (OCSP_RESPDATA *)0x0;
                    local_e0 = (X509 *)0x162;
                    pcVar9 = &DAT_0000006a;
                    (**(code **)(local_d8 + -0x6eb0))(0x27,0x6a,0x67);
                    goto LAB_005b2ad4;
                  }
                }
              }
            }
          }
          else {
LAB_005b28f4:
            iStack_10c = 1;
          }
          if (unaff_s3 != (ASN1_OBJECT *)0x0) {
            pcVar9 = *(char **)(local_d8 + -0x7f50);
            (**(code **)(local_d8 + -0x7d88))(unaff_s3,pcVar9);
          }
        }
      }
    }
  }
  else {
    if (((_union_958 *)&pAStack_f8->ln)->byName->entries == (stack_st_X509_NAME_ENTRY *)0x14) {
      unaff_s3 = (ASN1_OBJECT *)((_union_958 *)&pAStack_f8->ln)->byName->bytes;
      for (iVar12 = 0; iVar2 = (**(code **)(local_d8 + -0x7fb4))(certs), iVar12 < iVar2;
          iVar12 = iVar12 + 1) {
        unaff_s1 = (X509 *)(**(code **)(local_d8 + -0x7fbc))(certs,iVar12);
        uVar7 = (**(code **)(local_d8 + -0x781c))();
        pOVar11 = (OCSP_RESPDATA *)0x0;
        (**(code **)(local_d8 + -0x5b28))(unaff_s1,uVar7,&AStack_40);
        st = (X509_STORE *)&DAT_00000014;
        pcVar9 = (char *)&AStack_40;
        iVar2 = (**(code **)(local_d8 + -0x5308))(unaff_s3,&AStack_40,0x14);
        if (iVar2 == 0) goto LAB_005b2848;
      }
    }
LAB_005b27b8:
    if ((flags & 2) == 0) {
      certs = bs->certs;
      if ((X509_ALGOR *)pAStack_f8->sn == (X509_ALGOR *)0x0) {
        pcVar9 = (char *)pAStack_f8->ln;
        unaff_s1 = (X509 *)(**(code **)(local_d8 + -0x5b20))(certs,pcVar9);
LAB_005b2bfc:
        iStack_10c = 1;
        if (unaff_s1 != (X509 *)0x0) goto LAB_005b2858;
      }
      else if (((ASN1_OCTET_STRING *)pAStack_f8->ln)->length == 0x14) {
        pAStack_f8 = (ASN1_OBJECT *)((ASN1_OCTET_STRING *)pAStack_f8->ln)->data;
        unaff_s3 = &AStack_40;
        for (iVar12 = 0; iVar2 = (**(code **)(local_d8 + -0x7fb4))(certs), iVar12 < iVar2;
            iVar12 = iVar12 + 1) {
          unaff_s1 = (X509 *)(**(code **)(local_d8 + -0x7fbc))(certs,iVar12);
          uVar7 = (**(code **)(local_d8 + -0x781c))();
          pOVar11 = (OCSP_RESPDATA *)0x0;
          (**(code **)(local_d8 + -0x5b28))(unaff_s1,uVar7,unaff_s3);
          st = (X509_STORE *)&DAT_00000014;
          pcVar9 = (char *)unaff_s3;
          iVar2 = (**(code **)(local_d8 + -0x5308))(pAStack_f8,unaff_s3,0x14);
          if (iVar2 == 0) goto LAB_005b2bfc;
        }
      }
    }
    st = (X509_STORE *)&DAT_00000076;
    pOVar11 = (OCSP_RESPDATA *)0x0;
    local_e0 = (X509 *)&DAT_00000055;
    pcVar9 = &DAT_00000069;
    iStack_10c = 0;
    (**(code **)(local_d8 + -0x6eb0))(0x27,0x69,0x76);
  }
  if ((int *)AStack_40.flags == *(int **)puVar1) {
    return iStack_10c;
  }
  pcStack_f4 = OCSP_request_verify;
  piVar8 = (int *)AStack_40.flags;
  (**(code **)(local_d8 + -0x5328))();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iStack_114 = *(int *)PTR___stack_chk_guard_006aabf0;
  pXStack_108 = unaff_s1;
  pXStack_104 = (X509 *)certs;
  pAStack_100 = unaff_s3;
  uStack_fc = flags;
  if (piVar8[1] == 0) {
    uVar10 = 0x80;
    uVar7 = 0x174;
  }
  else {
    piVar6 = *(int **)(*piVar8 + 4);
    if ((piVar6 != (int *)0x0) && (*piVar6 == 4)) {
      if (((uint)pOVar11 & 2) == 0) {
        iVar12 = (*(code *)PTR_X509_find_by_subject_006aa3c0)
                           (*(undefined4 *)(piVar8[1] + 8),piVar6[1]);
      }
      else {
        iVar12 = (*(code *)PTR_X509_find_by_subject_006aa3c0)(pcVar9);
        if (iVar12 == 0) {
          uVar10 = 0x76;
          uVar7 = 0x181;
          goto LAB_005b2e14;
        }
        if (((uint)pOVar11 & 0x200) != 0) {
          pOVar11 = (OCSP_RESPDATA *)((uint)pOVar11 | 0x10);
        }
      }
      if (((uint)pOVar11 & 4) == 0) {
        uVar7 = (*(code *)PTR_X509_get_pubkey_006a8008)(iVar12);
        iVar2 = (*(code *)PTR_ASN1_item_verify_006a9e40)
                          (PTR_OCSP_REQINFO_it_006aa390,*(undefined4 *)piVar8[1],
                           ((undefined4 *)piVar8[1])[1],*piVar8,uVar7);
        (*(code *)PTR_EVP_PKEY_free_006a7f78)(uVar7);
        if (iVar2 < 1) {
          uVar10 = 0x75;
          uVar7 = 0x18e;
          goto LAB_005b2e14;
        }
      }
      if (((uint)pOVar11 & 0x10) == 0) {
        if (((uint)pOVar11 & 8) == 0) {
          iVar12 = (*(code *)PTR_X509_STORE_CTX_init_006a8304)
                             (auStack_19c,st,iVar12,*(undefined4 *)(piVar8[1] + 8));
        }
        else {
          iVar12 = (*(code *)PTR_X509_STORE_CTX_init_006a8304)(auStack_19c,st,iVar12,0);
        }
        if (iVar12 == 0) {
          uVar10 = 0xb;
          uVar7 = 0x19c;
          goto LAB_005b2e14;
        }
        (*(code *)PTR_X509_STORE_CTX_set_purpose_006aa284)(auStack_19c,8);
        (*(code *)PTR_X509_STORE_CTX_set_trust_006aa3c4)(auStack_19c,7);
        iVar12 = (*(code *)PTR_X509_verify_cert_006a8308)(auStack_19c);
        (*(code *)PTR_X509_STORE_CTX_cleanup_006a8310)(auStack_19c);
        if (iVar12 < 1) {
          uVar7 = (*(code *)PTR_X509_STORE_CTX_get_error_006a8314)(auStack_19c);
          (*(code *)PTR_ERR_put_error_006a9030)(0x27,0x74,0x65,"ocsp_vfy.c",0x1a7);
          uVar7 = (*(code *)PTR_X509_verify_cert_error_string_006a839c)(uVar7);
          (*(code *)PTR_ERR_add_error_data_006a9264)(2,"Verify error:",uVar7);
          iVar12 = 0;
          goto LAB_005b2e2c;
        }
      }
      iVar12 = 1;
      goto LAB_005b2e2c;
    }
    uVar10 = 0x81;
    uVar7 = 0x17a;
  }
LAB_005b2e14:
  (*(code *)PTR_ERR_put_error_006a9030)(0x27,0x74,uVar10,"ocsp_vfy.c",uVar7);
  iVar12 = 0;
LAB_005b2e2c:
  if (iStack_114 == *(int *)puVar1) {
    return iVar12;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar12 = (*(code *)PTR_ERR_func_error_string_006a9560)(OCSP_str_functs._0_4_);
  if (iVar12 == 0) {
    (*(code *)PTR_ERR_load_strings_006a9564)(0,OCSP_str_functs);
                    /* WARNING: Could not recover jumptable at 0x005b30f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar12 = (*(code *)PTR_ERR_load_strings_006a9564)(0,OCSP_str_reasons);
    return iVar12;
  }
  return iVar12;
}

