
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
  code cVar11;
  int iVar9;
  undefined4 uVar10;
  uint uVar12;
  char *sigret;
  char *pcVar13;
  char *pcVar14;
  RSA *pRVar15;
  char *pcVar16;
  int iVar17;
  RSA *unaff_s2;
  RSA *pRVar18;
  RSA **ppRStack_110;
  RSA **in_stack_ffffff28;
  RSA *pRStack_c8;
  int iStack_c4;
  undefined *puStack_bc;
  RSA *pRStack_b8;
  RSA *pRStack_b4;
  char *pcStack_b0;
  RSA *pRStack_ac;
  BIGNUM *pBStack_a8;
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
  
  pEStack_64 = (ENGINE *)PTR___stack_chk_guard_006aabf0;
  pBStack_60 = *(BIGNUM **)(param_1 + 0x14);
  local_14 = *(RSA **)PTR___stack_chk_guard_006aabf0;
  pcStack_b0 = (char *)param_4;
  pRStack_5c = unaff_s2;
  if (param_2 == (RSA *)&DAT_0000000b) goto LAB_005fd5c4;
  pRStack_5c = param_4;
  if ((int)param_2 < 0xc) {
    if ((int)param_2 < 6) {
      if ((int)param_2 < 3) {
        if (param_2 != (RSA *)0x1) {
          if (param_2 != (RSA *)&SUB_00000002) goto LAB_005fd694;
          param_3 = (RSA *)&DAT_00000094;
          local_38 = 0x24a;
LAB_005fd588:
          pcStack_b0 = "rsa_pmeth.c";
          param_2 = (RSA *)0x8f;
          (*(code *)PTR_ERR_put_error_006a9030)(4);
          pRVar2 = (RSA *)&SUB_fffffffe;
          goto LAB_005fd5c8;
        }
        if (param_4 != (RSA *)0x0) {
          if ((undefined *)pBStack_60->flags == (undefined *)0x3) {
LAB_005fd7fc:
            param_3 = (RSA *)0x8d;
            local_38 = 0x1c3;
LAB_005fd7b4:
            pcStack_b0 = "rsa_pmeth.c";
            param_2 = (RSA *)&DAT_0000008c;
            (*(code *)PTR_ERR_put_error_006a9030)(4);
            pRVar2 = (RSA *)0x0;
            goto LAB_005fd5c8;
          }
          if ((undefined *)pBStack_60->flags == &DAT_00000005) {
            uVar4 = (*(code *)PTR_EVP_MD_type_006a84cc)(param_4);
            iVar5 = (*(code *)PTR_RSA_X931_hash_id_006aa840)(uVar4);
            if (iVar5 == -1) {
LAB_005fd7a0:
              param_3 = (RSA *)0x8e;
              local_38 = 0x1cc;
              goto LAB_005fd7b4;
            }
          }
        }
        pBStack_60[1].d = (ulong *)param_4;
      }
    }
    else if (param_2 != (RSA *)&DAT_00000009) {
      if ((int)param_2 < 10) {
        if (param_2 != (RSA *)&DAT_00000007) goto LAB_005fd694;
      }
      else {
        local_1c = (RSA *)0x0;
        local_18 = 0;
        if (param_4 != (RSA *)0x0) {
          param_3 = (RSA *)0x0;
          param_2 = (RSA *)0x0;
          (*(code *)PTR_CMS_RecipientInfo_ktri_get0_algs_006aa828)(param_4,0,0,&local_1c);
          pcStack_b0 = (char *)local_1c;
          if (local_1c != (RSA *)0x0) {
            param_3 = (RSA *)0x0;
            param_2 = (RSA *)0x0;
            (*(code *)PTR_X509_ALGOR_get0_006a98c4)(&local_18);
          }
          if ((local_18 != 0) && (iVar5 = (*(code *)PTR_OBJ_obj2nid_006a822c)(), iVar5 == 0x397)) {
            pBStack_60->flags = (int)&SUB_00000004;
          }
        }
      }
    }
LAB_005fd5c4:
    pRVar2 = (RSA *)0x1;
  }
  else if (param_2 == (RSA *)0x1004) {
    if (param_4 == (RSA *)0x0) {
LAB_005fd694:
      pRVar2 = (RSA *)&SUB_fffffffe;
    }
    else {
      pBStack_60->top = (int)param_4;
      pRVar2 = (RSA *)0x1;
    }
  }
  else if ((int)param_2 < 0x1005) {
    if (param_2 == (RSA *)0x1002) {
LAB_005fd658:
      pcStack_b0 = (char *)0x680000;
      if ((undefined *)pBStack_60->flags != &DAT_00000006) {
        param_3 = (RSA *)0x92;
        local_38 = 0x1ff;
        goto LAB_005fd588;
      }
      pRVar2 = (RSA *)0x1;
      if (param_2 == (RSA *)0x1007) {
        param_4->pad = pBStack_60[1].dmax;
      }
      else {
        if ((int)param_3 < -2) goto LAB_005fd694;
        pBStack_60[1].dmax = (int)param_3;
        pRVar2 = (RSA *)0x1;
      }
    }
    else if ((int)param_2 < 0x1003) {
      pRVar2 = (RSA *)&SUB_fffffffe;
      if (param_2 == (RSA *)0x1001) {
        if (&DAT_00000005 < (undefined *)((int)&param_3[-1].mt_blinding + 3)) {
LAB_005fd764:
          param_3 = (RSA *)&DAT_00000090;
          local_38 = 500;
          goto LAB_005fd588;
        }
        puVar3 = pBStack_60[1].d;
        if (puVar3 != (ulong *)0x0) {
          if (param_3 == (RSA *)0x3) goto LAB_005fd7fc;
          if (param_3 == (RSA *)&DAT_00000005) {
            uVar4 = (*(code *)PTR_EVP_MD_type_006a84cc)(puVar3);
            iVar5 = (*(code *)PTR_RSA_X931_hash_id_006aa840)(uVar4);
            if (iVar5 == -1) goto LAB_005fd7a0;
            pBStack_60->flags = (int)&DAT_00000005;
            pRVar2 = (RSA *)0x1;
            goto LAB_005fd5c8;
          }
        }
        if (param_3 == (RSA *)&DAT_00000006) {
          uVar12 = *(uint *)(param_1 + 0x10) & 0x18;
joined_r0x005fd75c:
          if (uVar12 == 0) goto LAB_005fd764;
          if (puVar3 == (ulong *)0x0) {
            puVar3 = (ulong *)(*(code *)PTR_EVP_sha1_006a86c4)();
            pBStack_60[1].d = puVar3;
            pRVar2 = (RSA *)0x1;
            pBStack_60->flags = (int)param_3;
            goto LAB_005fd5c8;
          }
        }
        else if (param_3 == (RSA *)&SUB_00000004) {
          uVar12 = *(uint *)(param_1 + 0x10) & 0x300;
          goto joined_r0x005fd75c;
        }
        pBStack_60->flags = (int)param_3;
        pRVar2 = (RSA *)0x1;
      }
    }
    else {
      if ((int)param_3 < 0x100) {
        param_3 = (RSA *)0x91;
        local_38 = 0x20f;
        goto LAB_005fd588;
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
        if (param_2 == (RSA *)0x1007) goto LAB_005fd658;
        pRVar2 = (RSA *)&SUB_fffffffe;
        if (param_2 != (RSA *)0x1008) goto LAB_005fd5c8;
      }
      if ((undefined *)pBStack_60->flags != &DAT_00000006) {
        param_3 = (RSA *)&DAT_0000009c;
        local_38 = 0x225;
        goto LAB_005fd588;
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
LAB_005fd5c8:
  if (local_14 == *(RSA **)pEStack_64) {
    return pRVar2;
  }
  pRStack_b8 = local_14;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_bc = PTR___stack_chk_guard_006aabf0;
  pBStack_a8 = pRStack_b8->e;
  iStack_6c = *(int *)PTR___stack_chk_guard_006aabf0;
  if (pBStack_a8[1].d == (ulong *)0x0) {
    pRStack_88 = (RSA *)pBStack_a8->flags;
    pcVar13 = (char *)pRStack_b8->meth->rsa_mod_exp;
    sigret = pcStack_b0;
    pRVar2 = param_2;
    pRStack_70 = (RSA *)(*(code *)PTR_RSA_public_decrypt_006a8740)(local_38);
joined_r0x005fdaa0:
    if (-1 < (int)pRStack_70) {
LAB_005fd968:
      param_3->pad = (int)pRStack_70;
      pRStack_70 = (RSA *)0x1;
    }
  }
  else {
    pcVar13 = pcStack_b0;
    if (pBStack_a8->flags == 5) {
      pRVar2 = (RSA *)pBStack_a8[1].neg;
      if (pRVar2 == (RSA *)0x0) {
        uVar4 = (*(code *)PTR_EVP_PKEY_size_006a85f4)(pRStack_b8->meth);
        sigret = "rsa_pmeth.c";
        pRVar2 = (RSA *)(*(code *)PTR_CRYPTO_malloc_006a8108)(uVar4,"rsa_pmeth.c",0x8d);
        pBStack_a8[1].neg = (int)pRVar2;
        if (pRVar2 == (RSA *)0x0) goto LAB_005fda74;
      }
      pcVar13 = (char *)pRStack_b8->meth->rsa_mod_exp;
      pRStack_88 = (RSA *)&DAT_00000005;
      sigret = pcStack_b0;
      iVar5 = (*(code *)PTR_RSA_public_decrypt_006a8740)(local_38);
      if (iVar5 < 1) goto LAB_005fda38;
      pRStack_70 = (RSA *)(iVar5 + -1);
      pcStack_b0 = (char *)(uint)*(byte *)((int)&pRStack_70->pad + pBStack_a8[1].neg);
      uVar4 = (*(code *)PTR_EVP_MD_type_006a84cc)(pBStack_a8[1].d);
      pRVar18 = (RSA *)(*(code *)PTR_RSA_X931_hash_id_006aa840)(uVar4);
      pRStack_b8 = pRStack_70;
      if ((RSA *)pcStack_b0 == pRVar18) {
        pRVar18 = (RSA *)(*(code *)PTR_EVP_MD_size_006a8f2c)(pBStack_a8[1].d);
        if (pRStack_70 == pRVar18) {
          if (param_2 != (RSA *)0x0) {
            sigret = (char *)pBStack_a8[1].neg;
            pRVar2 = pRStack_70;
            (*(code *)PTR_memcpy_006aabf4)(param_2);
          }
          goto LAB_005fd968;
        }
        pRVar2 = (RSA *)0x8f;
        pRStack_88 = (RSA *)0x137;
      }
      else {
        pRVar2 = (RSA *)&DAT_00000064;
        pRStack_88 = (RSA *)0x131;
      }
      pcVar13 = "rsa_pmeth.c";
      sigret = (char *)0x8d;
      (*(code *)PTR_ERR_put_error_006a9030)(4);
      pRStack_70 = (RSA *)0x0;
    }
    else {
      sigret = (char *)param_2;
      pRVar2 = param_3;
      if (pBStack_a8->flags == 1) {
        uVar4 = (*(code *)PTR_EVP_MD_type_006a84cc)();
        pRVar2 = (RSA *)0x0;
        sigret = (char *)0x0;
        pRStack_88 = (RSA *)&pRStack_70;
        pcVar13 = (char *)param_2;
        iVar5 = (*(code *)PTR_int_rsa_verify_006aa844)(uVar4);
        if (0 < iVar5) goto joined_r0x005fdaa0;
LAB_005fda38:
        pRStack_70 = (RSA *)0x0;
      }
      else {
LAB_005fda74:
        pRStack_70 = (RSA *)0xffffffff;
      }
    }
  }
  if (iStack_6c == *(int *)puStack_bc) {
    return pRStack_70;
  }
  iVar5 = iStack_6c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iVar17 = *(int *)(iVar5 + 0x14);
  iStack_c4 = *(int *)PTR___stack_chk_guard_006aabf0;
  pRVar18 = *(RSA **)(*(int *)(iVar5 + 8) + 0x14);
  pRStack_b4 = param_3;
  pRStack_ac = param_2;
  if (*(int *)(iVar17 + 0x14) == 0) {
    in_stack_ffffff28 = *(RSA ***)(iVar17 + 0x10);
    pRStack_c8 = (RSA *)(*(code *)PTR_RSA_private_encrypt_006a873c)
                                  (pRStack_88,pcVar13,sigret,pRVar18);
LAB_005fdc30:
    pRVar8 = pRStack_c8;
    pcVar14 = pcVar13;
    pRVar15 = (RSA *)sigret;
    pcVar16 = (char *)pRVar18;
    if (-1 < (int)pRStack_c8) {
      pRVar2->pad = (int)pRStack_c8;
      pRVar8 = (RSA *)0x1;
    }
  }
  else {
    pcVar14 = sigret;
    pRVar15 = pRVar2;
    pcVar16 = pcVar13;
    pRVar6 = (RSA *)(*(code *)PTR_EVP_MD_size_006a8f2c)();
    if (pRVar6 == pRStack_88) {
      iVar7 = (*(code *)PTR_EVP_MD_type_006a84cc)(*(undefined4 *)(iVar17 + 0x14));
      if (iVar7 == 0x5f) {
        if (*(int *)(iVar17 + 0x10) == 1) {
          in_stack_ffffff28 = &pRStack_c8;
          pRVar8 = (RSA *)RSA_sign_ASN1_OCTET_STRING
                                    (0x5f,(uchar *)pcVar13,(uint)pRVar6,(uchar *)sigret,
                                     (uint *)in_stack_ffffff28,pRVar18);
          pRVar18 = (RSA *)sigret;
joined_r0x005fddc0:
          sigret = (char *)pRVar6;
          pcVar14 = pcVar13;
          pRVar15 = (RSA *)sigret;
          pcVar16 = (char *)pRVar18;
          if (0 < (int)pRVar8) goto LAB_005fdc30;
        }
        else {
LAB_005fdc88:
          pRVar8 = (RSA *)0xffffffff;
        }
      }
      else {
        iVar7 = *(int *)(iVar17 + 0x10);
        if (iVar7 == 5) {
          iVar7 = *(int *)(iVar17 + 0x20);
          if (iVar7 == 0) {
            uVar4 = (*(code *)PTR_EVP_PKEY_size_006a85f4)(*(undefined4 *)(iVar5 + 8));
            pRVar15 = (RSA *)0x8d;
            pcVar14 = "rsa_pmeth.c";
            iVar7 = (*(code *)PTR_CRYPTO_malloc_006a8108)(uVar4,"rsa_pmeth.c");
            *(int *)(iVar17 + 0x20) = iVar7;
            if (iVar7 == 0) {
              pRVar8 = (RSA *)0xffffffff;
              goto LAB_005fdc40;
            }
          }
          (*(code *)PTR_memcpy_006aabf4)(iVar7,pcVar13,pRVar6);
          iVar5 = *(int *)(iVar17 + 0x20);
          uVar4 = (*(code *)PTR_EVP_MD_type_006a84cc)(*(undefined4 *)(iVar17 + 0x14));
          cVar11 = (code)(*(code *)PTR_RSA_X931_hash_id_006aa840)(uVar4);
          *(code *)((int)&pRVar6->pad + iVar5) = cVar11;
          pcVar13 = *(char **)(iVar17 + 0x20);
          in_stack_ffffff28 = (RSA **)&DAT_00000005;
          pRStack_c8 = (RSA *)(*(code *)PTR_RSA_private_encrypt_006a873c)
                                        ((code *)((int)&pRVar6->pad + 1),pcVar13,sigret,pRVar18);
          goto LAB_005fdc30;
        }
        if (iVar7 == 1) {
          uVar4 = (*(code *)PTR_EVP_MD_type_006a84cc)(*(undefined4 *)(iVar17 + 0x14));
          in_stack_ffffff28 = &pRStack_c8;
          pRVar8 = (RSA *)(*(code *)PTR_RSA_sign_006a8b64)(uVar4,pcVar13,pRVar6,sigret);
          pRVar18 = (RSA *)sigret;
          goto joined_r0x005fddc0;
        }
        pRVar8 = (RSA *)0xffffffff;
        if (iVar7 == 6) {
          pRVar6 = *(RSA **)(iVar17 + 0x20);
          if (pRVar6 == (RSA *)0x0) {
            uVar4 = (*(code *)PTR_EVP_PKEY_size_006a85f4)(*(undefined4 *)(iVar5 + 8));
            pRVar15 = (RSA *)0x8d;
            pcVar14 = "rsa_pmeth.c";
            pRVar6 = (RSA *)(*(code *)PTR_CRYPTO_malloc_006a8108)(uVar4,"rsa_pmeth.c");
            *(RSA **)(iVar17 + 0x20) = pRVar6;
            if (pRVar6 == (RSA *)0x0) goto LAB_005fdc88;
          }
          pcVar16 = *(char **)(iVar17 + 0x14);
          in_stack_ffffff28 = *(RSA ***)(iVar17 + 0x18);
          iVar5 = (*(code *)PTR_RSA_padding_add_PKCS1_PSS_mgf1_006aa848)
                            (pRVar18,pRVar6,pcVar13,pcVar16);
          pcVar14 = (char *)pRVar6;
          pRVar15 = (RSA *)pcVar13;
          if (iVar5 != 0) {
            uVar4 = (*(code *)PTR_RSA_size_006a8730)(pRVar18);
            pcVar13 = *(char **)(iVar17 + 0x20);
            in_stack_ffffff28 = (RSA **)0x3;
            pRStack_c8 = (RSA *)(*(code *)PTR_RSA_private_encrypt_006a873c)
                                          (uVar4,pcVar13,sigret,pRVar18);
            goto LAB_005fdc30;
          }
          goto LAB_005fdc88;
        }
      }
    }
    else {
      pRVar15 = (RSA *)0x8f;
      pcVar16 = "rsa_pmeth.c";
      in_stack_ffffff28 = (RSA **)0xce;
      pcVar14 = (char *)0x8e;
      (*(code *)PTR_ERR_put_error_006a9030)(4,0x8e,0x8f,"rsa_pmeth.c");
      pRVar8 = (RSA *)0xffffffff;
    }
  }
LAB_005fdc40:
  if (iStack_c4 == *(int *)puVar1) {
    return pRVar8;
  }
  iVar5 = iStack_c4;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iVar7 = *(int *)(iVar5 + 0x14);
  iVar17 = *(int *)(iVar5 + 8);
  iVar5 = *(int *)PTR___stack_chk_guard_006aabf0;
  uVar4 = *(undefined4 *)(iVar17 + 0x14);
  if (*(int *)(iVar7 + 0x14) == 0) {
    iVar9 = *(int *)(iVar7 + 0x20);
    if (iVar9 == 0) {
      uVar10 = (*(code *)PTR_EVP_PKEY_size_006a85f4)(iVar17);
      iVar9 = (*(code *)PTR_CRYPTO_malloc_006a8108)(uVar10,"rsa_pmeth.c",0x8d);
      *(int *)(iVar7 + 0x20) = iVar9;
      if (iVar9 == 0) {
LAB_005fe018:
        pRVar2 = (RSA *)0xffffffff;
        goto LAB_005fdf2c;
      }
    }
    ppRStack_110 = (RSA **)(*(code *)PTR_RSA_public_decrypt_006a8740)
                                     (pRVar15,pcVar14,iVar9,uVar4,*(undefined4 *)(iVar7 + 0x10));
    if (ppRStack_110 != (RSA **)0x0) {
LAB_005fdf98:
      if (in_stack_ffffff28 == ppRStack_110) {
        iVar17 = (*(code *)PTR_memcmp_006aabd8)
                           (pcVar16,*(undefined4 *)(iVar7 + 0x20),in_stack_ffffff28);
        pRVar2 = (RSA *)(uint)(iVar17 == 0);
        goto LAB_005fdf2c;
      }
    }
  }
  else {
    iVar9 = *(int *)(iVar7 + 0x10);
    if (iVar9 == 1) {
      uVar10 = (*(code *)PTR_EVP_MD_type_006a84cc)(*(int *)(iVar7 + 0x14));
      pRVar2 = (RSA *)(*(code *)PTR_RSA_verify_006a8b68)
                                (uVar10,pcVar16,in_stack_ffffff28,pcVar14,pRVar15,uVar4);
      goto LAB_005fdf2c;
    }
    if (iVar9 == 5) {
      iVar17 = pkey_rsa_verifyrecover();
      if (0 < iVar17) goto LAB_005fdf98;
    }
    else {
      pRVar2 = (RSA *)0xffffffff;
      if (iVar9 != 6) goto LAB_005fdf2c;
      iVar9 = *(int *)(iVar7 + 0x20);
      if (iVar9 == 0) {
        uVar10 = (*(code *)PTR_EVP_PKEY_size_006a85f4)(iVar17);
        iVar9 = (*(code *)PTR_CRYPTO_malloc_006a8108)(uVar10,"rsa_pmeth.c",0x8d);
        *(int *)(iVar7 + 0x20) = iVar9;
        if (iVar9 == 0) goto LAB_005fe018;
      }
      iVar17 = (*(code *)PTR_RSA_public_decrypt_006a8740)(pRVar15,pcVar14,iVar9,uVar4,3);
      if (0 < iVar17) {
        iVar17 = (*(code *)PTR_RSA_verify_PKCS1_PSS_mgf1_006aa850)
                           (uVar4,pcVar16,*(undefined4 *)(iVar7 + 0x14),
                            *(undefined4 *)(iVar7 + 0x18),*(undefined4 *)(iVar7 + 0x20),
                            *(undefined4 *)(iVar7 + 0x1c));
        pRVar2 = (RSA *)(uint)(0 < iVar17);
        goto LAB_005fdf2c;
      }
    }
  }
  pRVar2 = (RSA *)0x0;
LAB_005fdf2c:
  if (iVar5 == *(int *)puVar1) {
    return pRVar2;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  pRVar2 = (RSA *)(*(code *)PTR_ERR_func_error_string_006a9560)(DSA_str_functs._0_4_);
  if (pRVar2 != (RSA *)0x0) {
    return pRVar2;
  }
  (*(code *)PTR_ERR_load_strings_006a9564)(0,DSA_str_functs);
                    /* WARNING: Could not recover jumptable at 0x005fe110. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pRVar2 = (RSA *)(*(code *)PTR_ERR_load_strings_006a9564)(0,DSA_str_reasons);
  return pRVar2;
}

