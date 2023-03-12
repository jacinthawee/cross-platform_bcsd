
RSA * pkey_rsa_verifyrecover(RSA *param_1,RSA *param_2,RSA *param_3,RSA *param_4,undefined4 param_5)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  RSA *pRVar4;
  RSA *pRVar5;
  int iVar6;
  RSA *pRVar7;
  code *pcVar8;
  code cVar11;
  int iVar9;
  undefined4 uVar10;
  char *sigret;
  char *pcVar12;
  char *pcVar13;
  RSA *pRVar14;
  RSA *pRVar15;
  char *pcVar16;
  int iVar17;
  code *pcVar18;
  RSA **ppRStack_c8;
  RSA **in_stack_ffffff70;
  RSA *pRStack_80;
  int iStack_7c;
  undefined *puStack_78;
  RSA *pRStack_74;
  RSA *pRStack_70;
  RSA *pRStack_6c;
  RSA *pRStack_68;
  BIGNUM *pBStack_64;
  RSA *local_40;
  RSA *local_28;
  int local_24;
  
  puStack_78 = PTR___stack_chk_guard_006a9ae8;
  pBStack_64 = param_1->e;
  local_24 = *(int *)PTR___stack_chk_guard_006a9ae8;
  pRStack_74 = param_1;
  if (pBStack_64[1].d == (ulong *)0x0) {
    local_40 = (RSA *)pBStack_64->flags;
    pcVar12 = (char *)param_1->meth->rsa_mod_exp;
    sigret = (char *)param_4;
    pRVar14 = param_2;
    local_28 = (RSA *)(*(code *)PTR_RSA_public_decrypt_006a7650)(param_5);
joined_r0x005fbbe0:
    pRVar4 = local_28;
    if (-1 < (int)local_28) {
LAB_005fbaa8:
      param_3->pad = (int)local_28;
      pRVar4 = (RSA *)0x1;
      pRStack_74 = param_1;
    }
  }
  else {
    pcVar12 = (char *)param_4;
    if (pBStack_64->flags == 5) {
      pRVar14 = (RSA *)pBStack_64[1].neg;
      if (pRVar14 == (RSA *)0x0) {
        uVar2 = (*(code *)PTR_EVP_PKEY_size_006a74f8)(param_1->meth);
        sigret = "rsa_pmeth.c";
        pRVar14 = (RSA *)(*(code *)PTR_CRYPTO_malloc_006a7008)(uVar2,"rsa_pmeth.c",0x8c);
        pBStack_64[1].neg = (int)pRVar14;
        if (pRVar14 == (RSA *)0x0) goto LAB_005fbbb4;
      }
      pcVar12 = (char *)param_1->meth->rsa_mod_exp;
      local_40 = (RSA *)&DAT_00000005;
      sigret = (char *)param_4;
      iVar3 = (*(code *)PTR_RSA_public_decrypt_006a7650)(param_5);
      if (iVar3 < 1) goto LAB_005fbb78;
      local_28 = (RSA *)(iVar3 + -1);
      param_4 = (RSA *)(uint)*(byte *)((int)&local_28->pad + pBStack_64[1].neg);
      uVar2 = (*(code *)PTR_EVP_MD_type_006a73cc)(pBStack_64[1].d);
      pRVar4 = (RSA *)(*(code *)PTR_RSA_X931_hash_id_006a9738)(uVar2);
      if (param_4 == pRVar4) {
        pRVar4 = (RSA *)(*(code *)PTR_EVP_MD_size_006a7e3c)(pBStack_64[1].d);
        if (local_28 == pRVar4) {
          param_1 = local_28;
          if (param_2 != (RSA *)0x0) {
            sigret = (char *)pBStack_64[1].neg;
            pRVar14 = local_28;
            (*(code *)PTR_memcpy_006a9aec)(param_2);
          }
          goto LAB_005fbaa8;
        }
        pRVar14 = (RSA *)0x8f;
        local_40 = (RSA *)0x127;
      }
      else {
        pRVar14 = (RSA *)&DAT_00000064;
        local_40 = (RSA *)0x122;
      }
      pcVar12 = "rsa_pmeth.c";
      sigret = (char *)0x8d;
      (*(code *)PTR_ERR_put_error_006a7f34)(4);
      pRVar4 = (RSA *)0x0;
      pRStack_74 = local_28;
    }
    else {
      sigret = (char *)param_2;
      pRVar14 = param_3;
      if (pBStack_64->flags == 1) {
        uVar2 = (*(code *)PTR_EVP_MD_type_006a73cc)();
        pRVar14 = (RSA *)0x0;
        sigret = (char *)0x0;
        local_40 = (RSA *)&local_28;
        pcVar12 = (char *)param_2;
        iVar3 = (*(code *)PTR_int_rsa_verify_006a973c)(uVar2);
        if (0 < iVar3) goto joined_r0x005fbbe0;
LAB_005fbb78:
        pRVar4 = (RSA *)0x0;
      }
      else {
LAB_005fbbb4:
        pRVar4 = (RSA *)0xffffffff;
      }
    }
  }
  if (local_24 == *(int *)puStack_78) {
    return pRVar4;
  }
  iVar3 = local_24;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iVar17 = *(int *)(iVar3 + 0x14);
  iStack_7c = *(int *)PTR___stack_chk_guard_006a9ae8;
  pRVar4 = *(RSA **)(*(int *)(iVar3 + 8) + 0x14);
  pRStack_70 = param_3;
  pRStack_6c = param_4;
  pRStack_68 = param_2;
  if (*(int *)(iVar17 + 0x14) == 0) {
    in_stack_ffffff70 = *(RSA ***)(iVar17 + 0x10);
    pRStack_80 = (RSA *)(*(code *)PTR_RSA_private_encrypt_006a764c)(local_40,pcVar12,sigret,pRVar4);
LAB_005fbd74:
    pRVar7 = pRStack_80;
    pcVar13 = pcVar12;
    pRVar15 = (RSA *)sigret;
    pcVar16 = (char *)pRVar4;
    if (-1 < (int)pRStack_80) {
      pRVar14->pad = (int)pRStack_80;
      pRVar7 = (RSA *)0x1;
    }
  }
  else {
    pcVar13 = sigret;
    pRVar15 = pRVar14;
    pcVar16 = pcVar12;
    pRVar5 = (RSA *)(*(code *)PTR_EVP_MD_size_006a7e3c)();
    if (pRVar5 == local_40) {
      iVar6 = (*(code *)PTR_EVP_MD_type_006a73cc)(*(undefined4 *)(iVar17 + 0x14));
      if (iVar6 == 0x5f) {
        pRVar7 = (RSA *)0xffffffff;
        if (*(int *)(iVar17 + 0x10) == 1) {
          in_stack_ffffff70 = &pRStack_80;
          pRVar7 = (RSA *)RSA_sign_ASN1_OCTET_STRING
                                    (0x5f,(uchar *)pcVar12,(uint)pRVar5,(uchar *)sigret,
                                     (uint *)in_stack_ffffff70,pRVar4);
          pRVar4 = (RSA *)sigret;
joined_r0x005fbe20:
          sigret = (char *)pRVar5;
          pcVar13 = pcVar12;
          pRVar15 = (RSA *)sigret;
          pcVar16 = (char *)pRVar4;
          if (0 < (int)pRVar7) goto LAB_005fbd74;
        }
      }
      else {
        iVar6 = *(int *)(iVar17 + 0x10);
        if (iVar6 == 5) {
          pcVar18 = (code *)((int)&pRVar5->pad + 1);
          pcVar8 = (code *)(*(code *)PTR_EVP_PKEY_size_006a74f8)(*(undefined4 *)(iVar3 + 8));
          if (pcVar18 <= pcVar8) {
            iVar6 = *(int *)(iVar17 + 0x20);
            if (iVar6 == 0) {
              uVar2 = (*(code *)PTR_EVP_PKEY_size_006a74f8)(*(undefined4 *)(iVar3 + 8));
              iVar6 = (*(code *)PTR_CRYPTO_malloc_006a7008)(uVar2,"rsa_pmeth.c",0x8c);
              *(int *)(iVar17 + 0x20) = iVar6;
              if (iVar6 == 0) {
                pcVar16 = "rsa_pmeth.c";
                pRVar15 = (RSA *)&DAT_00000041;
                pcVar13 = (char *)0x8e;
                in_stack_ffffff70 = (RSA **)0xec;
                (*(code *)PTR_ERR_put_error_006a7f34)(4,0x8e,0x41,"rsa_pmeth.c");
                goto LAB_005fbde4;
              }
            }
            (*(code *)PTR_memcpy_006a9aec)(iVar6,pcVar12,pRVar5);
            iVar3 = *(int *)(iVar17 + 0x20);
            uVar2 = (*(code *)PTR_EVP_MD_type_006a73cc)(*(undefined4 *)(iVar17 + 0x14));
            cVar11 = (code)(*(code *)PTR_RSA_X931_hash_id_006a9738)(uVar2);
            *(code *)((int)&pRVar5->pad + iVar3) = cVar11;
            pcVar12 = *(char **)(iVar17 + 0x20);
            in_stack_ffffff70 = (RSA **)&DAT_00000005;
            pRStack_80 = (RSA *)(*(code *)PTR_RSA_private_encrypt_006a764c)
                                          (pcVar18,pcVar12,sigret,pRVar4);
            goto LAB_005fbd74;
          }
          pRVar15 = (RSA *)&DAT_00000078;
          in_stack_ffffff70 = (RSA **)0xe8;
          goto LAB_005fbefc;
        }
        if (iVar6 == 1) {
          uVar2 = (*(code *)PTR_EVP_MD_type_006a73cc)(*(undefined4 *)(iVar17 + 0x14));
          in_stack_ffffff70 = &pRStack_80;
          pRVar7 = (RSA *)(*(code *)PTR_RSA_sign_006a7a78)(uVar2,pcVar12,pRVar5,sigret);
          pRVar4 = (RSA *)sigret;
          goto joined_r0x005fbe20;
        }
        pRVar7 = (RSA *)0xffffffff;
        if (iVar6 == 6) {
          pRVar5 = *(RSA **)(iVar17 + 0x20);
          if (pRVar5 == (RSA *)0x0) {
            uVar2 = (*(code *)PTR_EVP_PKEY_size_006a74f8)(*(undefined4 *)(iVar3 + 8));
            pRVar15 = (RSA *)&DAT_0000008c;
            pcVar13 = "rsa_pmeth.c";
            pRVar5 = (RSA *)(*(code *)PTR_CRYPTO_malloc_006a7008)(uVar2,"rsa_pmeth.c");
            *(RSA **)(iVar17 + 0x20) = pRVar5;
            if (pRVar5 == (RSA *)0x0) goto LAB_005fbde4;
          }
          pcVar16 = *(char **)(iVar17 + 0x14);
          in_stack_ffffff70 = *(RSA ***)(iVar17 + 0x18);
          iVar3 = (*(code *)PTR_RSA_padding_add_PKCS1_PSS_mgf1_006a9740)
                            (pRVar4,pRVar5,pcVar12,pcVar16);
          pcVar13 = (char *)pRVar5;
          pRVar15 = (RSA *)pcVar12;
          if (iVar3 != 0) {
            uVar2 = (*(code *)PTR_RSA_size_006a7640)(pRVar4);
            pcVar12 = *(char **)(iVar17 + 0x20);
            in_stack_ffffff70 = (RSA **)0x3;
            pRStack_80 = (RSA *)(*(code *)PTR_RSA_private_encrypt_006a764c)
                                          (uVar2,pcVar12,sigret,pRVar4);
            goto LAB_005fbd74;
          }
LAB_005fbde4:
          pRVar7 = (RSA *)0xffffffff;
        }
      }
    }
    else {
      pRVar15 = (RSA *)0x8f;
      in_stack_ffffff70 = (RSA **)&DAT_000000ca;
LAB_005fbefc:
      pcVar16 = "rsa_pmeth.c";
      pcVar13 = (char *)0x8e;
      (*(code *)PTR_ERR_put_error_006a7f34)(4,0x8e,pRVar15,"rsa_pmeth.c");
      pRVar7 = (RSA *)0xffffffff;
    }
  }
  if (iStack_7c == *(int *)puVar1) {
    return pRVar7;
  }
  iVar3 = iStack_7c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iVar6 = *(int *)(iVar3 + 0x14);
  iVar17 = *(int *)(iVar3 + 8);
  iVar3 = *(int *)PTR___stack_chk_guard_006a9ae8;
  uVar2 = *(undefined4 *)(iVar17 + 0x14);
  if (*(int *)(iVar6 + 0x14) == 0) {
    iVar9 = *(int *)(iVar6 + 0x20);
    if (iVar9 == 0) {
      uVar10 = (*(code *)PTR_EVP_PKEY_size_006a74f8)(iVar17);
      iVar9 = (*(code *)PTR_CRYPTO_malloc_006a7008)(uVar10,"rsa_pmeth.c",0x8c);
      *(int *)(iVar6 + 0x20) = iVar9;
      if (iVar9 == 0) {
LAB_005fc1b8:
        pRVar14 = (RSA *)0xffffffff;
        goto LAB_005fc0cc;
      }
    }
    ppRStack_c8 = (RSA **)(*(code *)PTR_RSA_public_decrypt_006a7650)
                                    (pRVar15,pcVar13,iVar9,uVar2,*(undefined4 *)(iVar6 + 0x10));
    if (ppRStack_c8 != (RSA **)0x0) {
LAB_005fc138:
      if (in_stack_ffffff70 == ppRStack_c8) {
        iVar17 = (*(code *)PTR_memcmp_006a9ad0)
                           (pcVar16,*(undefined4 *)(iVar6 + 0x20),in_stack_ffffff70);
        pRVar14 = (RSA *)(uint)(iVar17 == 0);
        goto LAB_005fc0cc;
      }
    }
  }
  else {
    iVar9 = *(int *)(iVar6 + 0x10);
    if (iVar9 == 1) {
      uVar10 = (*(code *)PTR_EVP_MD_type_006a73cc)(*(int *)(iVar6 + 0x14));
      pRVar14 = (RSA *)(*(code *)PTR_RSA_verify_006a7a7c)
                                 (uVar10,pcVar16,in_stack_ffffff70,pcVar13,pRVar15,uVar2);
      goto LAB_005fc0cc;
    }
    if (iVar9 == 5) {
      iVar17 = pkey_rsa_verifyrecover();
      if (0 < iVar17) goto LAB_005fc138;
    }
    else {
      pRVar14 = (RSA *)0xffffffff;
      if (iVar9 != 6) goto LAB_005fc0cc;
      iVar9 = *(int *)(iVar6 + 0x20);
      if (iVar9 == 0) {
        uVar10 = (*(code *)PTR_EVP_PKEY_size_006a74f8)(iVar17);
        iVar9 = (*(code *)PTR_CRYPTO_malloc_006a7008)(uVar10,"rsa_pmeth.c",0x8c);
        *(int *)(iVar6 + 0x20) = iVar9;
        if (iVar9 == 0) goto LAB_005fc1b8;
      }
      iVar17 = (*(code *)PTR_RSA_public_decrypt_006a7650)(pRVar15,pcVar13,iVar9,uVar2,3);
      if (0 < iVar17) {
        iVar17 = (*(code *)PTR_RSA_verify_PKCS1_PSS_mgf1_006a9748)
                           (uVar2,pcVar16,*(undefined4 *)(iVar6 + 0x14),
                            *(undefined4 *)(iVar6 + 0x18),*(undefined4 *)(iVar6 + 0x20),
                            *(undefined4 *)(iVar6 + 0x1c));
        pRVar14 = (RSA *)(uint)(0 < iVar17);
        goto LAB_005fc0cc;
      }
    }
  }
  pRVar14 = (RSA *)0x0;
LAB_005fc0cc:
  if (iVar3 == *(int *)puVar1) {
    return pRVar14;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  pRVar14 = (RSA *)(*(code *)PTR_ERR_func_error_string_006a8440)(DSA_str_functs._0_4_);
  if (pRVar14 == (RSA *)0x0) {
    (*(code *)PTR_ERR_load_strings_006a8444)(0,DSA_str_functs);
                    /* WARNING: Could not recover jumptable at 0x005fc2b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pRVar14 = (RSA *)(*(code *)PTR_ERR_load_strings_006a8444)(0,DSA_str_reasons);
    return pRVar14;
  }
  return pRVar14;
}

