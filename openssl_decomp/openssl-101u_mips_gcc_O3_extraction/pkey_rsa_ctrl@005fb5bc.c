
RSA * pkey_rsa_ctrl(int param_1,RSA *param_2,RSA *param_3,RSA *param_4)

{
  undefined *puVar1;
  RSA *pRVar2;
  ulong *puVar3;
  undefined4 uVar4;
  int iVar5;
  RSA *pRVar6;
  int iVar7;
  RSA *pRVar8;
  code *pcVar9;
  code cVar12;
  int iVar10;
  undefined4 uVar11;
  uint uVar13;
  char *sigret;
  char *pcVar14;
  char *pcVar15;
  RSA *pRVar16;
  char *pcVar17;
  int iVar18;
  RSA *unaff_s2;
  RSA *pRVar19;
  code *pcVar20;
  RSA **ppRStack_110;
  RSA **in_stack_ffffff28;
  RSA *pRStack_c8;
  int iStack_c4;
  undefined *puStack_c0;
  RSA *pRStack_bc;
  RSA *pRStack_b8;
  char *pcStack_b4;
  RSA *pRStack_b0;
  BIGNUM *pBStack_ac;
  RSA *pRStack_88;
  RSA *pRStack_70;
  int iStack_6c;
  ENGINE *pEStack_64;
  BIGNUM *pBStack_60;
  RSA *pRStack_5c;
  int local_38;
  RSA *local_1c;
  int local_18;
  RSA *local_14;
  
  pEStack_64 = (ENGINE *)PTR___stack_chk_guard_006a9ae8;
  pBStack_60 = *(BIGNUM **)(param_1 + 0x14);
  local_14 = *(RSA **)PTR___stack_chk_guard_006a9ae8;
  pcStack_b4 = (char *)param_4;
  pRStack_5c = unaff_s2;
  if (param_2 == (RSA *)&DAT_0000000b) goto LAB_005fb704;
  pRStack_5c = param_4;
  if ((int)param_2 < 0xc) {
    if ((int)param_2 < 6) {
      if ((int)param_2 < 3) {
        if (param_2 != (RSA *)0x1) {
          if (param_2 != (RSA *)&SUB_00000002) goto LAB_005fb7d4;
          param_3 = (RSA *)&DAT_00000094;
          local_38 = 0x21c;
LAB_005fb6c8:
          pcStack_b4 = "rsa_pmeth.c";
          param_2 = (RSA *)0x8f;
          (*(code *)PTR_ERR_put_error_006a7f34)(4);
          pRVar2 = (RSA *)&SUB_fffffffe;
          goto LAB_005fb708;
        }
        if (param_4 != (RSA *)0x0) {
          if ((undefined *)pBStack_60->flags == (undefined *)0x3) {
LAB_005fb93c:
            param_3 = (RSA *)0x8d;
            local_38 = 0x1a3;
LAB_005fb8f4:
            pcStack_b4 = "rsa_pmeth.c";
            param_2 = (RSA *)&DAT_0000008c;
            (*(code *)PTR_ERR_put_error_006a7f34)(4);
            pRVar2 = (RSA *)0x0;
            goto LAB_005fb708;
          }
          if ((undefined *)pBStack_60->flags == &DAT_00000005) {
            uVar4 = (*(code *)PTR_EVP_MD_type_006a73cc)(param_4);
            iVar5 = (*(code *)PTR_RSA_X931_hash_id_006a9738)(uVar4);
            if (iVar5 == -1) {
LAB_005fb8e0:
              param_3 = (RSA *)0x8e;
              local_38 = 0x1a9;
              goto LAB_005fb8f4;
            }
          }
        }
        pBStack_60[1].d = (ulong *)param_4;
      }
    }
    else if (param_2 != (RSA *)&DAT_00000009) {
      if ((int)param_2 < 10) {
        if (param_2 != (RSA *)&DAT_00000007) goto LAB_005fb7d4;
      }
      else {
        local_1c = (RSA *)0x0;
        local_18 = 0;
        if (param_4 != (RSA *)0x0) {
          param_3 = (RSA *)0x0;
          param_2 = (RSA *)0x0;
          (*(code *)PTR_CMS_RecipientInfo_ktri_get0_algs_006a9720)(param_4,0,0,&local_1c);
          pcStack_b4 = (char *)local_1c;
          if (local_1c != (RSA *)0x0) {
            param_3 = (RSA *)0x0;
            param_2 = (RSA *)0x0;
            (*(code *)PTR_X509_ALGOR_get0_006a87a4)(&local_18);
          }
          if ((local_18 != 0) && (iVar5 = (*(code *)PTR_OBJ_obj2nid_006a712c)(), iVar5 == 0x397)) {
            pBStack_60->flags = (int)&SUB_00000004;
          }
        }
      }
    }
LAB_005fb704:
    pRVar2 = (RSA *)0x1;
  }
  else if (param_2 == (RSA *)0x1004) {
    if (param_4 == (RSA *)0x0) {
LAB_005fb7d4:
      pRVar2 = (RSA *)&SUB_fffffffe;
    }
    else {
      pBStack_60->top = (int)param_4;
      pRVar2 = (RSA *)0x1;
    }
  }
  else if ((int)param_2 < 0x1005) {
    if (param_2 == (RSA *)0x1002) {
LAB_005fb798:
      pcStack_b4 = "encrypt";
      if ((undefined *)pBStack_60->flags != &DAT_00000006) {
        param_3 = (RSA *)&DAT_00000092;
        local_38 = 0x1d6;
        goto LAB_005fb6c8;
      }
      pRVar2 = (RSA *)0x1;
      if (param_2 == (RSA *)0x1007) {
        param_4->pad = pBStack_60[1].dmax;
      }
      else {
        if ((int)param_3 < -2) goto LAB_005fb7d4;
        pBStack_60[1].dmax = (int)param_3;
        pRVar2 = (RSA *)0x1;
      }
    }
    else if ((int)param_2 < 0x1003) {
      pRVar2 = (RSA *)&SUB_fffffffe;
      if (param_2 == (RSA *)0x1001) {
        if (&DAT_00000005 < (undefined *)((int)&param_3[-1].mt_blinding + 3)) {
LAB_005fb8a4:
          param_3 = (RSA *)&DAT_00000090;
          local_38 = 0x1cc;
          goto LAB_005fb6c8;
        }
        puVar3 = pBStack_60[1].d;
        if (puVar3 != (ulong *)0x0) {
          if (param_3 == (RSA *)0x3) goto LAB_005fb93c;
          if (param_3 == (RSA *)&DAT_00000005) {
            uVar4 = (*(code *)PTR_EVP_MD_type_006a73cc)(puVar3);
            iVar5 = (*(code *)PTR_RSA_X931_hash_id_006a9738)(uVar4);
            if (iVar5 == -1) goto LAB_005fb8e0;
            pBStack_60->flags = (int)&DAT_00000005;
            pRVar2 = (RSA *)0x1;
            goto LAB_005fb708;
          }
        }
        if (param_3 == (RSA *)&DAT_00000006) {
          uVar13 = *(uint *)(param_1 + 0x10) & 0x18;
joined_r0x005fb89c:
          if (uVar13 == 0) goto LAB_005fb8a4;
          if (puVar3 == (ulong *)0x0) {
            puVar3 = (ulong *)(*(code *)PTR_EVP_sha1_006a75d0)();
            pBStack_60[1].d = puVar3;
            pRVar2 = (RSA *)0x1;
            pBStack_60->flags = (int)param_3;
            goto LAB_005fb708;
          }
        }
        else if (param_3 == (RSA *)&SUB_00000004) {
          uVar13 = *(uint *)(param_1 + 0x10) & 0x300;
          goto joined_r0x005fb89c;
        }
        pBStack_60->flags = (int)param_3;
        pRVar2 = (RSA *)0x1;
      }
    }
    else {
      if ((int)param_3 < 0x100) {
        param_3 = (RSA *)0x91;
        local_38 = 0x1e4;
        goto LAB_005fb6c8;
      }
      pBStack_60->d = (ulong *)param_3;
      pRVar2 = (RSA *)0x1;
    }
  }
  else {
    pRVar2 = (RSA *)0x1;
    if (param_2 == (RSA *)0x1006) {
      param_4->pad = pBStack_60->flags;
    }
    else {
      if (0x1005 < (int)param_2) {
        if (param_2 == (RSA *)0x1007) goto LAB_005fb798;
        pRVar2 = (RSA *)&SUB_fffffffe;
        if (param_2 != (RSA *)0x1008) goto LAB_005fb708;
      }
      if ((undefined *)pBStack_60->flags != &DAT_00000006) {
        param_3 = (RSA *)&DAT_0000009c;
        local_38 = 0x1f9;
        goto LAB_005fb6c8;
      }
      pRVar2 = (RSA *)0x1;
      if (param_2 == (RSA *)0x1008) {
        if (pBStack_60[1].top == 0) {
          pRVar2 = (RSA *)0x1;
          param_4->pad = (int)pBStack_60[1].d;
        }
        else {
          param_4->pad = pBStack_60[1].top;
          pRVar2 = (RSA *)0x1;
        }
      }
      else {
        pBStack_60[1].top = (int)param_4;
      }
    }
  }
LAB_005fb708:
  if (local_14 == *(RSA **)pEStack_64) {
    return pRVar2;
  }
  pRStack_bc = local_14;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_c0 = PTR___stack_chk_guard_006a9ae8;
  pBStack_ac = pRStack_bc->e;
  iStack_6c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (pBStack_ac[1].d == (ulong *)0x0) {
    pRStack_88 = (RSA *)pBStack_ac->flags;
    pcVar14 = (char *)pRStack_bc->meth->rsa_mod_exp;
    sigret = pcStack_b4;
    pRVar2 = param_2;
    pRStack_70 = (RSA *)(*(code *)PTR_RSA_public_decrypt_006a7650)(local_38);
joined_r0x005fbbe0:
    if (-1 < (int)pRStack_70) {
LAB_005fbaa8:
      param_3->pad = (int)pRStack_70;
      pRStack_70 = (RSA *)0x1;
    }
  }
  else {
    pcVar14 = pcStack_b4;
    if (pBStack_ac->flags == 5) {
      pRVar2 = (RSA *)pBStack_ac[1].neg;
      if (pRVar2 == (RSA *)0x0) {
        uVar4 = (*(code *)PTR_EVP_PKEY_size_006a74f8)(pRStack_bc->meth);
        sigret = "rsa_pmeth.c";
        pRVar2 = (RSA *)(*(code *)PTR_CRYPTO_malloc_006a7008)(uVar4,"rsa_pmeth.c",0x8c);
        pBStack_ac[1].neg = (int)pRVar2;
        if (pRVar2 == (RSA *)0x0) goto LAB_005fbbb4;
      }
      pcVar14 = (char *)pRStack_bc->meth->rsa_mod_exp;
      pRStack_88 = (RSA *)&DAT_00000005;
      sigret = pcStack_b4;
      iVar5 = (*(code *)PTR_RSA_public_decrypt_006a7650)(local_38);
      if (iVar5 < 1) goto LAB_005fbb78;
      pRStack_70 = (RSA *)(iVar5 + -1);
      pcStack_b4 = (char *)(uint)*(byte *)((int)&pRStack_70->pad + pBStack_ac[1].neg);
      uVar4 = (*(code *)PTR_EVP_MD_type_006a73cc)(pBStack_ac[1].d);
      pRVar19 = (RSA *)(*(code *)PTR_RSA_X931_hash_id_006a9738)(uVar4);
      pRStack_bc = pRStack_70;
      if ((RSA *)pcStack_b4 == pRVar19) {
        pRVar19 = (RSA *)(*(code *)PTR_EVP_MD_size_006a7e3c)(pBStack_ac[1].d);
        if (pRStack_70 == pRVar19) {
          if (param_2 != (RSA *)0x0) {
            sigret = (char *)pBStack_ac[1].neg;
            pRVar2 = pRStack_70;
            (*(code *)PTR_memcpy_006a9aec)(param_2);
          }
          goto LAB_005fbaa8;
        }
        pRVar2 = (RSA *)0x8f;
        pRStack_88 = (RSA *)0x127;
      }
      else {
        pRVar2 = (RSA *)&DAT_00000064;
        pRStack_88 = (RSA *)0x122;
      }
      pcVar14 = "rsa_pmeth.c";
      sigret = (char *)0x8d;
      (*(code *)PTR_ERR_put_error_006a7f34)(4);
      pRStack_70 = (RSA *)0x0;
    }
    else {
      sigret = (char *)param_2;
      pRVar2 = param_3;
      if (pBStack_ac->flags == 1) {
        uVar4 = (*(code *)PTR_EVP_MD_type_006a73cc)();
        pRVar2 = (RSA *)0x0;
        sigret = (char *)0x0;
        pRStack_88 = (RSA *)&pRStack_70;
        pcVar14 = (char *)param_2;
        iVar5 = (*(code *)PTR_int_rsa_verify_006a973c)(uVar4);
        if (0 < iVar5) goto joined_r0x005fbbe0;
LAB_005fbb78:
        pRStack_70 = (RSA *)0x0;
      }
      else {
LAB_005fbbb4:
        pRStack_70 = (RSA *)0xffffffff;
      }
    }
  }
  if (iStack_6c == *(int *)puStack_c0) {
    return pRStack_70;
  }
  iVar5 = iStack_6c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iVar18 = *(int *)(iVar5 + 0x14);
  iStack_c4 = *(int *)PTR___stack_chk_guard_006a9ae8;
  pRVar19 = *(RSA **)(*(int *)(iVar5 + 8) + 0x14);
  pRStack_b8 = param_3;
  pRStack_b0 = param_2;
  if (*(int *)(iVar18 + 0x14) == 0) {
    in_stack_ffffff28 = *(RSA ***)(iVar18 + 0x10);
    pRStack_c8 = (RSA *)(*(code *)PTR_RSA_private_encrypt_006a764c)
                                  (pRStack_88,pcVar14,sigret,pRVar19);
LAB_005fbd74:
    pRVar8 = pRStack_c8;
    pcVar15 = pcVar14;
    pRVar16 = (RSA *)sigret;
    pcVar17 = (char *)pRVar19;
    if (-1 < (int)pRStack_c8) {
      pRVar2->pad = (int)pRStack_c8;
      pRVar8 = (RSA *)0x1;
    }
  }
  else {
    pcVar15 = sigret;
    pRVar16 = pRVar2;
    pcVar17 = pcVar14;
    pRVar6 = (RSA *)(*(code *)PTR_EVP_MD_size_006a7e3c)();
    if (pRVar6 == pRStack_88) {
      iVar7 = (*(code *)PTR_EVP_MD_type_006a73cc)(*(undefined4 *)(iVar18 + 0x14));
      if (iVar7 == 0x5f) {
        pRVar8 = (RSA *)0xffffffff;
        if (*(int *)(iVar18 + 0x10) == 1) {
          in_stack_ffffff28 = &pRStack_c8;
          pRVar8 = (RSA *)RSA_sign_ASN1_OCTET_STRING
                                    (0x5f,(uchar *)pcVar14,(uint)pRVar6,(uchar *)sigret,
                                     (uint *)in_stack_ffffff28,pRVar19);
          pRVar19 = (RSA *)sigret;
joined_r0x005fbe20:
          sigret = (char *)pRVar6;
          pcVar15 = pcVar14;
          pRVar16 = (RSA *)sigret;
          pcVar17 = (char *)pRVar19;
          if (0 < (int)pRVar8) goto LAB_005fbd74;
        }
      }
      else {
        iVar7 = *(int *)(iVar18 + 0x10);
        if (iVar7 == 5) {
          pcVar20 = (code *)((int)&pRVar6->pad + 1);
          pcVar9 = (code *)(*(code *)PTR_EVP_PKEY_size_006a74f8)(*(undefined4 *)(iVar5 + 8));
          if (pcVar20 <= pcVar9) {
            iVar7 = *(int *)(iVar18 + 0x20);
            if (iVar7 == 0) {
              uVar4 = (*(code *)PTR_EVP_PKEY_size_006a74f8)(*(undefined4 *)(iVar5 + 8));
              iVar7 = (*(code *)PTR_CRYPTO_malloc_006a7008)(uVar4,"rsa_pmeth.c",0x8c);
              *(int *)(iVar18 + 0x20) = iVar7;
              if (iVar7 == 0) {
                pcVar17 = "rsa_pmeth.c";
                pRVar16 = (RSA *)&DAT_00000041;
                pcVar15 = (char *)0x8e;
                in_stack_ffffff28 = (RSA **)0xec;
                (*(code *)PTR_ERR_put_error_006a7f34)(4,0x8e,0x41,"rsa_pmeth.c");
                goto LAB_005fbde4;
              }
            }
            (*(code *)PTR_memcpy_006a9aec)(iVar7,pcVar14,pRVar6);
            iVar5 = *(int *)(iVar18 + 0x20);
            uVar4 = (*(code *)PTR_EVP_MD_type_006a73cc)(*(undefined4 *)(iVar18 + 0x14));
            cVar12 = (code)(*(code *)PTR_RSA_X931_hash_id_006a9738)(uVar4);
            *(code *)((int)&pRVar6->pad + iVar5) = cVar12;
            pcVar14 = *(char **)(iVar18 + 0x20);
            in_stack_ffffff28 = (RSA **)&DAT_00000005;
            pRStack_c8 = (RSA *)(*(code *)PTR_RSA_private_encrypt_006a764c)
                                          (pcVar20,pcVar14,sigret,pRVar19);
            goto LAB_005fbd74;
          }
          pRVar16 = (RSA *)&DAT_00000078;
          in_stack_ffffff28 = (RSA **)0xe8;
          goto LAB_005fbefc;
        }
        if (iVar7 == 1) {
          uVar4 = (*(code *)PTR_EVP_MD_type_006a73cc)(*(undefined4 *)(iVar18 + 0x14));
          in_stack_ffffff28 = &pRStack_c8;
          pRVar8 = (RSA *)(*(code *)PTR_RSA_sign_006a7a78)(uVar4,pcVar14,pRVar6,sigret);
          pRVar19 = (RSA *)sigret;
          goto joined_r0x005fbe20;
        }
        pRVar8 = (RSA *)0xffffffff;
        if (iVar7 == 6) {
          pRVar6 = *(RSA **)(iVar18 + 0x20);
          if (pRVar6 == (RSA *)0x0) {
            uVar4 = (*(code *)PTR_EVP_PKEY_size_006a74f8)(*(undefined4 *)(iVar5 + 8));
            pRVar16 = (RSA *)&DAT_0000008c;
            pcVar15 = "rsa_pmeth.c";
            pRVar6 = (RSA *)(*(code *)PTR_CRYPTO_malloc_006a7008)(uVar4,"rsa_pmeth.c");
            *(RSA **)(iVar18 + 0x20) = pRVar6;
            if (pRVar6 == (RSA *)0x0) goto LAB_005fbde4;
          }
          pcVar17 = *(char **)(iVar18 + 0x14);
          in_stack_ffffff28 = *(RSA ***)(iVar18 + 0x18);
          iVar5 = (*(code *)PTR_RSA_padding_add_PKCS1_PSS_mgf1_006a9740)
                            (pRVar19,pRVar6,pcVar14,pcVar17);
          pcVar15 = (char *)pRVar6;
          pRVar16 = (RSA *)pcVar14;
          if (iVar5 != 0) {
            uVar4 = (*(code *)PTR_RSA_size_006a7640)(pRVar19);
            pcVar14 = *(char **)(iVar18 + 0x20);
            in_stack_ffffff28 = (RSA **)0x3;
            pRStack_c8 = (RSA *)(*(code *)PTR_RSA_private_encrypt_006a764c)
                                          (uVar4,pcVar14,sigret,pRVar19);
            goto LAB_005fbd74;
          }
LAB_005fbde4:
          pRVar8 = (RSA *)0xffffffff;
        }
      }
    }
    else {
      pRVar16 = (RSA *)0x8f;
      in_stack_ffffff28 = (RSA **)&DAT_000000ca;
LAB_005fbefc:
      pcVar17 = "rsa_pmeth.c";
      pcVar15 = (char *)0x8e;
      (*(code *)PTR_ERR_put_error_006a7f34)(4,0x8e,pRVar16,"rsa_pmeth.c");
      pRVar8 = (RSA *)0xffffffff;
    }
  }
  if (iStack_c4 == *(int *)puVar1) {
    return pRVar8;
  }
  iVar5 = iStack_c4;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iVar7 = *(int *)(iVar5 + 0x14);
  iVar18 = *(int *)(iVar5 + 8);
  iVar5 = *(int *)PTR___stack_chk_guard_006a9ae8;
  uVar4 = *(undefined4 *)(iVar18 + 0x14);
  if (*(int *)(iVar7 + 0x14) == 0) {
    iVar10 = *(int *)(iVar7 + 0x20);
    if (iVar10 == 0) {
      uVar11 = (*(code *)PTR_EVP_PKEY_size_006a74f8)(iVar18);
      iVar10 = (*(code *)PTR_CRYPTO_malloc_006a7008)(uVar11,"rsa_pmeth.c",0x8c);
      *(int *)(iVar7 + 0x20) = iVar10;
      if (iVar10 == 0) {
LAB_005fc1b8:
        pRVar2 = (RSA *)0xffffffff;
        goto LAB_005fc0cc;
      }
    }
    ppRStack_110 = (RSA **)(*(code *)PTR_RSA_public_decrypt_006a7650)
                                     (pRVar16,pcVar15,iVar10,uVar4,*(undefined4 *)(iVar7 + 0x10));
    if (ppRStack_110 != (RSA **)0x0) {
LAB_005fc138:
      if (in_stack_ffffff28 == ppRStack_110) {
        iVar18 = (*(code *)PTR_memcmp_006a9ad0)
                           (pcVar17,*(undefined4 *)(iVar7 + 0x20),in_stack_ffffff28);
        pRVar2 = (RSA *)(uint)(iVar18 == 0);
        goto LAB_005fc0cc;
      }
    }
  }
  else {
    iVar10 = *(int *)(iVar7 + 0x10);
    if (iVar10 == 1) {
      uVar11 = (*(code *)PTR_EVP_MD_type_006a73cc)(*(int *)(iVar7 + 0x14));
      pRVar2 = (RSA *)(*(code *)PTR_RSA_verify_006a7a7c)
                                (uVar11,pcVar17,in_stack_ffffff28,pcVar15,pRVar16,uVar4);
      goto LAB_005fc0cc;
    }
    if (iVar10 == 5) {
      iVar18 = pkey_rsa_verifyrecover();
      if (0 < iVar18) goto LAB_005fc138;
    }
    else {
      pRVar2 = (RSA *)0xffffffff;
      if (iVar10 != 6) goto LAB_005fc0cc;
      iVar10 = *(int *)(iVar7 + 0x20);
      if (iVar10 == 0) {
        uVar11 = (*(code *)PTR_EVP_PKEY_size_006a74f8)(iVar18);
        iVar10 = (*(code *)PTR_CRYPTO_malloc_006a7008)(uVar11,"rsa_pmeth.c",0x8c);
        *(int *)(iVar7 + 0x20) = iVar10;
        if (iVar10 == 0) goto LAB_005fc1b8;
      }
      iVar18 = (*(code *)PTR_RSA_public_decrypt_006a7650)(pRVar16,pcVar15,iVar10,uVar4,3);
      if (0 < iVar18) {
        iVar18 = (*(code *)PTR_RSA_verify_PKCS1_PSS_mgf1_006a9748)
                           (uVar4,pcVar17,*(undefined4 *)(iVar7 + 0x14),
                            *(undefined4 *)(iVar7 + 0x18),*(undefined4 *)(iVar7 + 0x20),
                            *(undefined4 *)(iVar7 + 0x1c));
        pRVar2 = (RSA *)(uint)(0 < iVar18);
        goto LAB_005fc0cc;
      }
    }
  }
  pRVar2 = (RSA *)0x0;
LAB_005fc0cc:
  if (iVar5 == *(int *)puVar1) {
    return pRVar2;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  pRVar2 = (RSA *)(*(code *)PTR_ERR_func_error_string_006a8440)(DSA_str_functs._0_4_);
  if (pRVar2 != (RSA *)0x0) {
    return pRVar2;
  }
  (*(code *)PTR_ERR_load_strings_006a8444)(0,DSA_str_functs);
                    /* WARNING: Could not recover jumptable at 0x005fc2b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pRVar2 = (RSA *)(*(code *)PTR_ERR_load_strings_006a8444)(0,DSA_str_reasons);
  return pRVar2;
}

