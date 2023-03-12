
uint ocsp_match_issuerid(undefined4 param_1,X509 *param_2,X509 *param_3,char *param_4)

{
  undefined *puVar1;
  undefined4 uVar2;
  X509 *pXVar3;
  uint uVar4;
  int iVar5;
  ASN1_OBJECT **ppAVar6;
  X509 **ppXVar7;
  int iVar8;
  int *piVar9;
  char **ppcVar10;
  int *piVar11;
  char *pcVar12;
  X509 *pXVar13;
  undefined4 uVar14;
  char *pcVar15;
  int iVar16;
  X509 *unaff_s4;
  X509 *unaff_s5;
  code *pcVar17;
  undefined auStack_224 [136];
  int iStack_19c;
  uint uStack_194;
  X509 *pXStack_190;
  X509 *pXStack_18c;
  ASN1_OBJECT *pAStack_188;
  char *pcStack_184;
  ASN1_OBJECT *pAStack_180;
  code *pcStack_17c;
  X509 *pXStack_168;
  undefined *puStack_160;
  X509 *pXStack_154;
  X509 XStack_150;
  ASN1_OBJECT AStack_c8;
  X509 *pXStack_b0;
  X509 *pXStack_ac;
  undefined4 uStack_a8;
  undefined *puStack_a4;
  X509 *pXStack_a0;
  X509 *pXStack_9c;
  char **local_24;
  
  pAStack_188 = (ASN1_OBJECT *)PTR___stack_chk_guard_006aabf0;
  local_24 = *(char ***)PTR___stack_chk_guard_006aabf0;
  pXStack_18c = param_2;
  pXVar13 = param_3;
  if (param_2 == (X509 *)0x0) {
    for (; iVar16 = (*(code *)PTR_sk_num_006a7f2c)(param_3), (int)param_2 < iVar16;
        param_2 = (X509 *)((int)&param_2->cert_info + 1)) {
      ppXVar7 = (X509 **)(*(code *)PTR_sk_value_006a7f24)(param_3,param_2);
      pXVar13 = (X509 *)0x0;
      pXStack_18c = *ppXVar7;
      uVar4 = ocsp_match_issuerid(param_1);
      if ((int)uVar4 < 1) goto LAB_005b254c;
    }
    uVar4 = 1;
  }
  else {
    uVar2 = (*(code *)PTR_OBJ_obj2nid_006a822c)(param_2->cert_info->version);
    uVar2 = (*(code *)PTR_OBJ_nid2sn_006a819c)(uVar2);
    pXVar3 = (X509 *)(*(code *)PTR_EVP_get_digestbyname_006a802c)(uVar2);
    if (pXVar3 == (X509 *)0x0) {
      pXVar13 = (X509 *)&DAT_00000077;
      param_4 = "ocsp_vfy.c";
      pXStack_18c = (X509 *)&DAT_0000006d;
      (*(code *)PTR_ERR_put_error_006a9030)(0x27);
      uVar4 = 0xffffffff;
      param_3 = pXVar3;
    }
    else {
      unaff_s4 = (X509 *)(*(code *)PTR_EVP_MD_size_006a8f2c)(pXVar3);
      pXVar13 = param_3;
      if ((int)unaff_s4 < 0) {
LAB_005b2674:
        uVar4 = 0xffffffff;
        param_3 = pXVar3;
      }
      else if (unaff_s4 == (X509 *)param_2->sig_alg->algorithm) {
        uVar4 = 0;
        param_3 = pXVar3;
        if (unaff_s4 == (X509 *)param_2->signature->length) {
          unaff_s5 = (X509 *)&stack0xffffff9c;
          uVar2 = (*(code *)PTR_X509_get_subject_name_006a8000)(param_1);
          param_4 = (char *)0x0;
          pXStack_18c = pXVar3;
          pXVar13 = unaff_s5;
          iVar16 = (*(code *)PTR_X509_NAME_digest_006aa378)(uVar2);
          if (iVar16 == 0) goto LAB_005b2674;
          pXStack_18c = (X509 *)param_2->sig_alg[1].algorithm;
          param_3 = unaff_s4;
          iVar16 = (*(code *)PTR_memcmp_006aabd8)(unaff_s5);
          if (iVar16 != 0) goto LAB_005b2548;
          param_4 = (char *)0x0;
          (*(code *)PTR_X509_pubkey_digest_006aa3b8)(param_1,pXVar3,unaff_s5);
          pXStack_18c = (X509 *)param_2->signature->data;
          pXVar13 = unaff_s4;
          iVar16 = (*(code *)PTR_memcmp_006aabd8)(unaff_s5);
          uVar4 = (uint)(iVar16 == 0);
          param_3 = pXVar3;
        }
      }
      else {
LAB_005b2548:
        uVar4 = 0;
        pXVar13 = param_3;
        param_3 = pXVar3;
      }
    }
  }
LAB_005b254c:
  if (local_24 == *(char ***)pAStack_188) {
    return uVar4;
  }
  ppcVar10 = local_24;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  pAStack_180 = *(ASN1_OBJECT **)(*ppcVar10 + 4);
  AStack_c8.flags = *(int *)PTR___stack_chk_guard_006aabf0;
  puStack_a4 = (undefined *)pAStack_188;
  puStack_160 = &_gp;
  pcVar15 = param_4;
  pXStack_154 = pXVar13;
  pXStack_b0 = param_2;
  pXStack_ac = param_3;
  uStack_a8 = param_1;
  pXStack_a0 = unaff_s4;
  pXStack_9c = unaff_s5;
  if ((X509_ALGOR *)pAStack_180->sn == (X509_ALGOR *)0x0) {
    pcVar12 = (char *)pAStack_180->ln;
    param_3 = (X509 *)(*(code *)PTR_X509_find_by_subject_006aa3c0)(pXStack_18c,pcVar12);
LAB_005b2848:
    if (param_3 == (X509 *)0x0) goto LAB_005b27b8;
    uStack_194 = 2;
    if (((uint)param_4 & 0x200) != 0) {
      param_4 = (char *)((uint)param_4 | 0x10);
    }
LAB_005b2858:
    if (((uint)param_4 & 4) == 0) {
      pXStack_18c = (X509 *)(**(code **)(puStack_160 + -0x7ed8))(param_3);
      if (pXStack_18c != (X509 *)0x0) {
        pcVar12 = ppcVar10[1];
        pcVar15 = *ppcVar10;
        pXVar13 = (X509 *)ppcVar10[2];
        pXStack_168 = pXStack_18c;
        uStack_194 = (**(code **)(puStack_160 + -0x60a0))
                               (*(undefined4 *)(puStack_160 + -0x5b24),pcVar12,pXVar13);
        (**(code **)(puStack_160 + -0x7f68))(pXStack_18c);
        if (0 < (int)uStack_194) goto LAB_005b2864;
      }
      pXVar13 = (X509 *)0x75;
      pcVar15 = (char *)0x0;
      pXStack_168 = (X509 *)&DAT_00000065;
      pcVar12 = &DAT_00000069;
      (**(code **)(puStack_160 + -0x6eb0))(0x27,0x69,0x75);
    }
    else {
LAB_005b2864:
      if (((uint)param_4 & 0x10) == 0) {
        pXStack_18c = &XStack_150;
        if (((uint)param_4 & 8) == 0) {
          pcVar15 = ppcVar10[3];
        }
        else {
          pcVar15 = (char *)0x0;
        }
        pXVar13 = param_3;
        iVar16 = (**(code **)(puStack_160 + -0x7bdc))(pXStack_18c,pXStack_154,param_3);
        if (iVar16 == 0) {
          pXVar13 = (X509 *)&DAT_0000000b;
          pcVar15 = (char *)0x0;
          pXStack_168 = (X509 *)&DAT_00000073;
          pcVar12 = &DAT_00000069;
          uStack_194 = 0xffffffff;
          (**(code **)(puStack_160 + -0x6eb0))(0x27,0x69,0xb);
        }
        else {
          pcVar12 = &DAT_00000008;
          (**(code **)(puStack_160 + -0x5c5c))(pXStack_18c,8);
          uStack_194 = (**(code **)(puStack_160 + -0x7bd8))(pXStack_18c);
          pAStack_188 = (ASN1_OBJECT *)(**(code **)(puStack_160 + -0x7bd4))(pXStack_18c);
          (**(code **)(puStack_160 + -0x7bd0))(pXStack_18c);
          if ((int)uStack_194 < 1) {
            param_3 = (X509 *)(**(code **)(puStack_160 + -0x7bcc))(pXStack_18c);
            pcVar15 = (char *)0x0;
            pXStack_168 = (X509 *)0x7e;
            (**(code **)(puStack_160 + -0x6eb0))(0x27,0x69,0x65);
            pXVar13 = (X509 *)(**(code **)(puStack_160 + -0x7b44))(param_3);
            pcVar12 = "Verify error:";
            (**(code **)(puStack_160 + -0x6c7c))(2,"Verify error:",pXVar13);
          }
          else if (((uint)param_4 & 0x100) == 0) {
            pXStack_18c = *(X509 **)(*ppcVar10 + 0xc);
            iVar16 = (**(code **)(puStack_160 + -0x7fb4))(pAStack_188);
            if (iVar16 < 1) {
              pXVar13 = (X509 *)&DAT_00000069;
              pcVar15 = (char *)0x0;
              pXStack_168 = (X509 *)0xe2;
              pcVar12 = &DAT_0000006c;
              uStack_194 = 0xffffffff;
              (**(code **)(puStack_160 + -0x6eb0))(0x27,0x6c,0x69);
            }
            else {
              iVar16 = (**(code **)(puStack_160 + -0x7fb4))(pXStack_18c);
              if (iVar16 < 1) {
                pXVar13 = (X509 *)&DAT_0000006f;
                pcVar15 = (char *)0x0;
                pXStack_168 = (X509 *)0x10d;
                pcVar12 = &DAT_0000006b;
                uStack_194 = 0xffffffff;
                (**(code **)(puStack_160 + -0x6eb0))(0x27,0x6b,0x6f);
              }
              else {
                ppAVar6 = (ASN1_OBJECT **)(**(code **)(puStack_160 + -0x7fbc))(pXStack_18c,0);
                pAStack_180 = *ppAVar6;
                if (iVar16 == 1) {
LAB_005b2a54:
                  pcVar17 = *(code **)(puStack_160 + -0x7fbc);
                }
                else {
                  iVar5 = 1;
                  do {
                    ppXVar7 = (X509 **)(**(code **)(puStack_160 + -0x7fbc))(pXStack_18c,iVar5);
                    param_3 = *ppXVar7;
                    iVar8 = OCSP_id_issuer_cmp((OCSP_CERTID *)pAStack_180,(OCSP_CERTID *)param_3);
                    if (iVar8 != 0) {
                      pcVar12 = (char *)((X509_ALGOR *)pAStack_180->sn)->algorithm;
                      iVar16 = (**(code **)(puStack_160 + -0x60fc))
                                         (param_3->cert_info->version,pcVar12);
                      if (iVar16 == 0) goto LAB_005b2ad4;
                      pAStack_180 = (ASN1_OBJECT *)0x0;
                      goto LAB_005b2a54;
                    }
                    iVar5 = iVar5 + 1;
                    pcVar17 = *(code **)(puStack_160 + -0x7fbc);
                  } while (iVar16 != iVar5);
                }
                param_3 = (X509 *)(*pcVar17)(pAStack_188,0);
                iVar16 = (**(code **)(puStack_160 + -0x7fb4))(pAStack_188);
                if (iVar16 < 2) {
LAB_005b2ab8:
                  pcVar12 = (char *)pAStack_180;
                  pXVar13 = pXStack_18c;
                  uStack_194 = ocsp_match_issuerid(param_3,pAStack_180,pXStack_18c);
                  if (uStack_194 == 0) {
LAB_005b2ad4:
                    param_4 = (char *)((uint)param_4 & 0x20);
                    uStack_194 = 0;
                    if (param_4 == (char *)0x0) {
                      iVar16 = (**(code **)(puStack_160 + -0x7fb4))(pAStack_188);
                      uVar2 = (**(code **)(puStack_160 + -0x7fbc))(pAStack_188,iVar16 + -1);
                      pXVar13 = (X509 *)0x0;
                      pcVar12 = &DAT_000000b4;
                      iVar16 = (**(code **)(puStack_160 + -0x5ebc))(uVar2,0xb4,0);
                      if (iVar16 == 1) goto LAB_005b28f4;
                      pXVar13 = (X509 *)&DAT_00000070;
                      pcVar15 = (char *)0x0;
                      pXStack_168 = (X509 *)&DAT_00000098;
                      pcVar12 = &DAT_00000069;
                      uStack_194 = 0;
                      (**(code **)(puStack_160 + -0x6eb0))(0x27,0x69,0x70);
                    }
                  }
                }
                else {
                  uVar2 = (**(code **)(puStack_160 + -0x7fbc))(pAStack_188,1);
                  pcVar12 = (char *)pAStack_180;
                  pXVar13 = pXStack_18c;
                  uStack_194 = ocsp_match_issuerid(uVar2,pAStack_180,pXStack_18c);
                  if (-1 < (int)uStack_194) {
                    if (uStack_194 == 0) goto LAB_005b2ab8;
                    pXVar13 = (X509 *)0x0;
                    pcVar12 = (char *)0xffffffff;
                    X509_check_purpose(param_3,-1,0);
                    if (((param_3->ex_flags & 4) != 0) && ((param_3->ex_xkusage & 0x20) != 0))
                    goto LAB_005b28f4;
                    pXVar13 = (X509 *)0x67;
                    pcVar15 = (char *)0x0;
                    pXStack_168 = (X509 *)0x162;
                    pcVar12 = &DAT_0000006a;
                    (**(code **)(puStack_160 + -0x6eb0))(0x27,0x6a,0x67);
                    goto LAB_005b2ad4;
                  }
                }
              }
            }
          }
          else {
LAB_005b28f4:
            uStack_194 = 1;
          }
          if (pAStack_188 != (ASN1_OBJECT *)0x0) {
            pcVar12 = *(char **)(puStack_160 + -0x7f50);
            (**(code **)(puStack_160 + -0x7d88))(pAStack_188,pcVar12);
          }
        }
      }
    }
  }
  else {
    if (((ASN1_OCTET_STRING *)pAStack_180->ln)->length == 0x14) {
      pAStack_188 = (ASN1_OBJECT *)((ASN1_OCTET_STRING *)pAStack_180->ln)->data;
      for (iVar16 = 0; iVar5 = (**(code **)(puStack_160 + -0x7fb4))(pXStack_18c), iVar16 < iVar5;
          iVar16 = iVar16 + 1) {
        param_3 = (X509 *)(**(code **)(puStack_160 + -0x7fbc))(pXStack_18c,iVar16);
        uVar2 = (**(code **)(puStack_160 + -0x781c))();
        pcVar15 = (char *)0x0;
        (**(code **)(puStack_160 + -0x5b28))(param_3,uVar2,&AStack_c8);
        pXVar13 = (X509 *)&DAT_00000014;
        pcVar12 = (char *)&AStack_c8;
        iVar5 = (**(code **)(puStack_160 + -0x5308))(pAStack_188,&AStack_c8,0x14);
        if (iVar5 == 0) goto LAB_005b2848;
      }
    }
LAB_005b27b8:
    if (((uint)param_4 & 2) == 0) {
      pXStack_18c = (X509 *)ppcVar10[3];
      if ((X509_ALGOR *)pAStack_180->sn == (X509_ALGOR *)0x0) {
        pcVar12 = (char *)pAStack_180->ln;
        param_3 = (X509 *)(**(code **)(puStack_160 + -0x5b20))(pXStack_18c,pcVar12);
LAB_005b2bfc:
        uStack_194 = 1;
        if (param_3 != (X509 *)0x0) goto LAB_005b2858;
      }
      else if (((ASN1_OCTET_STRING *)pAStack_180->ln)->length == 0x14) {
        pAStack_180 = (ASN1_OBJECT *)((ASN1_OCTET_STRING *)pAStack_180->ln)->data;
        pAStack_188 = &AStack_c8;
        for (iVar16 = 0; iVar5 = (**(code **)(puStack_160 + -0x7fb4))(pXStack_18c), iVar16 < iVar5;
            iVar16 = iVar16 + 1) {
          param_3 = (X509 *)(**(code **)(puStack_160 + -0x7fbc))(pXStack_18c,iVar16);
          uVar2 = (**(code **)(puStack_160 + -0x781c))();
          pcVar15 = (char *)0x0;
          (**(code **)(puStack_160 + -0x5b28))(param_3,uVar2,pAStack_188);
          pXVar13 = (X509 *)&DAT_00000014;
          pcVar12 = (char *)pAStack_188;
          iVar5 = (**(code **)(puStack_160 + -0x5308))(pAStack_180,pAStack_188,0x14);
          if (iVar5 == 0) goto LAB_005b2bfc;
        }
      }
    }
    pXVar13 = (X509 *)&DAT_00000076;
    pcVar15 = (char *)0x0;
    pXStack_168 = (X509 *)&DAT_00000055;
    pcVar12 = &DAT_00000069;
    uStack_194 = 0;
    (**(code **)(puStack_160 + -0x6eb0))(0x27,0x69,0x76);
  }
  if ((int *)AStack_c8.flags == *(int **)puVar1) {
    return uStack_194;
  }
  pcStack_17c = OCSP_request_verify;
  piVar11 = (int *)AStack_c8.flags;
  (**(code **)(puStack_160 + -0x5328))();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iStack_19c = *(int *)PTR___stack_chk_guard_006aabf0;
  pXStack_190 = param_3;
  pcStack_184 = param_4;
  if (piVar11[1] == 0) {
    uVar14 = 0x80;
    uVar2 = 0x174;
  }
  else {
    piVar9 = *(int **)(*piVar11 + 4);
    if ((piVar9 != (int *)0x0) && (*piVar9 == 4)) {
      if (((uint)pcVar15 & 2) == 0) {
        iVar16 = (*(code *)PTR_X509_find_by_subject_006aa3c0)
                           (*(undefined4 *)(piVar11[1] + 8),piVar9[1]);
      }
      else {
        iVar16 = (*(code *)PTR_X509_find_by_subject_006aa3c0)(pcVar12);
        if (iVar16 == 0) {
          uVar14 = 0x76;
          uVar2 = 0x181;
          goto LAB_005b2e14;
        }
        if (((uint)pcVar15 & 0x200) != 0) {
          pcVar15 = (char *)((uint)pcVar15 | 0x10);
        }
      }
      if (((uint)pcVar15 & 4) == 0) {
        uVar2 = (*(code *)PTR_X509_get_pubkey_006a8008)(iVar16);
        iVar5 = (*(code *)PTR_ASN1_item_verify_006a9e40)
                          (PTR_OCSP_REQINFO_it_006aa390,*(undefined4 *)piVar11[1],
                           ((undefined4 *)piVar11[1])[1],*piVar11,uVar2);
        (*(code *)PTR_EVP_PKEY_free_006a7f78)(uVar2);
        if (iVar5 < 1) {
          uVar14 = 0x75;
          uVar2 = 0x18e;
          goto LAB_005b2e14;
        }
      }
      if (((uint)pcVar15 & 0x10) == 0) {
        if (((uint)pcVar15 & 8) == 0) {
          iVar16 = (*(code *)PTR_X509_STORE_CTX_init_006a8304)
                             (auStack_224,pXVar13,iVar16,*(undefined4 *)(piVar11[1] + 8));
        }
        else {
          iVar16 = (*(code *)PTR_X509_STORE_CTX_init_006a8304)(auStack_224,pXVar13,iVar16,0);
        }
        if (iVar16 == 0) {
          uVar14 = 0xb;
          uVar2 = 0x19c;
          goto LAB_005b2e14;
        }
        (*(code *)PTR_X509_STORE_CTX_set_purpose_006aa284)(auStack_224,8);
        (*(code *)PTR_X509_STORE_CTX_set_trust_006aa3c4)(auStack_224,7);
        iVar16 = (*(code *)PTR_X509_verify_cert_006a8308)(auStack_224);
        (*(code *)PTR_X509_STORE_CTX_cleanup_006a8310)(auStack_224);
        if (iVar16 < 1) {
          uVar2 = (*(code *)PTR_X509_STORE_CTX_get_error_006a8314)(auStack_224);
          (*(code *)PTR_ERR_put_error_006a9030)(0x27,0x74,0x65,"ocsp_vfy.c",0x1a7);
          uVar2 = (*(code *)PTR_X509_verify_cert_error_string_006a839c)(uVar2);
          (*(code *)PTR_ERR_add_error_data_006a9264)(2,"Verify error:",uVar2);
          uVar4 = 0;
          goto LAB_005b2e2c;
        }
      }
      uVar4 = 1;
      goto LAB_005b2e2c;
    }
    uVar14 = 0x81;
    uVar2 = 0x17a;
  }
LAB_005b2e14:
  (*(code *)PTR_ERR_put_error_006a9030)(0x27,0x74,uVar14,"ocsp_vfy.c",uVar2);
  uVar4 = 0;
LAB_005b2e2c:
  if (iStack_19c == *(int *)puVar1) {
    return uVar4;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  uVar4 = (*(code *)PTR_ERR_func_error_string_006a9560)(OCSP_str_functs._0_4_);
  if (uVar4 == 0) {
    (*(code *)PTR_ERR_load_strings_006a9564)(0,OCSP_str_functs);
                    /* WARNING: Could not recover jumptable at 0x005b30f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar4 = (*(code *)PTR_ERR_load_strings_006a9564)(0,OCSP_str_reasons);
    return uVar4;
  }
  return uVar4;
}

