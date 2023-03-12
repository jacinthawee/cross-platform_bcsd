
RSA * pkey_rsa_verifyrecover(RSA *param_1,RSA *param_2,RSA *param_3,RSA *param_4,undefined4 param_5)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  RSA *pRVar4;
  RSA *pRVar5;
  int iVar6;
  RSA *pRVar7;
  code cVar10;
  int iVar8;
  undefined4 uVar9;
  char *sigret;
  char *pcVar11;
  char *pcVar12;
  RSA *pRVar13;
  RSA *pRVar14;
  char *pcVar15;
  int iVar16;
  RSA **ppRStack_c8;
  RSA **in_stack_ffffff70;
  RSA *pRStack_80;
  int iStack_7c;
  undefined *puStack_74;
  RSA *pRStack_70;
  RSA *pRStack_6c;
  RSA *pRStack_68;
  RSA *pRStack_64;
  BIGNUM *pBStack_60;
  RSA *local_40;
  RSA *local_28;
  int local_24;
  
  puStack_74 = PTR___stack_chk_guard_006aabf0;
  pBStack_60 = param_1->e;
  local_24 = *(int *)PTR___stack_chk_guard_006aabf0;
  pRStack_70 = param_1;
  if (pBStack_60[1].d == (ulong *)0x0) {
    local_40 = (RSA *)pBStack_60->flags;
    pcVar11 = (char *)param_1->meth->rsa_mod_exp;
    sigret = (char *)param_4;
    pRVar13 = param_2;
    local_28 = (RSA *)(*(code *)PTR_RSA_public_decrypt_006a8740)(param_5);
joined_r0x005fdaa0:
    pRVar4 = local_28;
    if (-1 < (int)local_28) {
LAB_005fd968:
      param_3->pad = (int)local_28;
      pRVar4 = (RSA *)0x1;
      pRStack_70 = param_1;
    }
  }
  else {
    pcVar11 = (char *)param_4;
    if (pBStack_60->flags == 5) {
      pRVar13 = (RSA *)pBStack_60[1].neg;
      if (pRVar13 == (RSA *)0x0) {
        uVar2 = (*(code *)PTR_EVP_PKEY_size_006a85f4)(param_1->meth);
        sigret = "rsa_pmeth.c";
        pRVar13 = (RSA *)(*(code *)PTR_CRYPTO_malloc_006a8108)(uVar2,"rsa_pmeth.c",0x8d);
        pBStack_60[1].neg = (int)pRVar13;
        if (pRVar13 == (RSA *)0x0) goto LAB_005fda74;
      }
      pcVar11 = (char *)param_1->meth->rsa_mod_exp;
      local_40 = (RSA *)&DAT_00000005;
      sigret = (char *)param_4;
      iVar3 = (*(code *)PTR_RSA_public_decrypt_006a8740)(param_5);
      if (iVar3 < 1) goto LAB_005fda38;
      local_28 = (RSA *)(iVar3 + -1);
      param_4 = (RSA *)(uint)*(byte *)((int)&local_28->pad + pBStack_60[1].neg);
      uVar2 = (*(code *)PTR_EVP_MD_type_006a84cc)(pBStack_60[1].d);
      pRVar4 = (RSA *)(*(code *)PTR_RSA_X931_hash_id_006aa840)(uVar2);
      if (param_4 == pRVar4) {
        pRVar4 = (RSA *)(*(code *)PTR_EVP_MD_size_006a8f2c)(pBStack_60[1].d);
        if (local_28 == pRVar4) {
          param_1 = local_28;
          if (param_2 != (RSA *)0x0) {
            sigret = (char *)pBStack_60[1].neg;
            pRVar13 = local_28;
            (*(code *)PTR_memcpy_006aabf4)(param_2);
          }
          goto LAB_005fd968;
        }
        pRVar13 = (RSA *)0x8f;
        local_40 = (RSA *)0x137;
      }
      else {
        pRVar13 = (RSA *)&DAT_00000064;
        local_40 = (RSA *)0x131;
      }
      pcVar11 = "rsa_pmeth.c";
      sigret = (char *)0x8d;
      (*(code *)PTR_ERR_put_error_006a9030)(4);
      pRVar4 = (RSA *)0x0;
      pRStack_70 = local_28;
    }
    else {
      sigret = (char *)param_2;
      pRVar13 = param_3;
      if (pBStack_60->flags == 1) {
        uVar2 = (*(code *)PTR_EVP_MD_type_006a84cc)();
        pRVar13 = (RSA *)0x0;
        sigret = (char *)0x0;
        local_40 = (RSA *)&local_28;
        pcVar11 = (char *)param_2;
        iVar3 = (*(code *)PTR_int_rsa_verify_006aa844)(uVar2);
        if (0 < iVar3) goto joined_r0x005fdaa0;
LAB_005fda38:
        pRVar4 = (RSA *)0x0;
      }
      else {
LAB_005fda74:
        pRVar4 = (RSA *)0xffffffff;
      }
    }
  }
  if (local_24 == *(int *)puStack_74) {
    return pRVar4;
  }
  iVar3 = local_24;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iVar16 = *(int *)(iVar3 + 0x14);
  iStack_7c = *(int *)PTR___stack_chk_guard_006aabf0;
  pRVar4 = *(RSA **)(*(int *)(iVar3 + 8) + 0x14);
  pRStack_6c = param_3;
  pRStack_68 = param_4;
  pRStack_64 = param_2;
  if (*(int *)(iVar16 + 0x14) == 0) {
    in_stack_ffffff70 = *(RSA ***)(iVar16 + 0x10);
    pRStack_80 = (RSA *)(*(code *)PTR_RSA_private_encrypt_006a873c)(local_40,pcVar11,sigret,pRVar4);
LAB_005fdc30:
    pRVar7 = pRStack_80;
    pcVar12 = pcVar11;
    pRVar14 = (RSA *)sigret;
    pcVar15 = (char *)pRVar4;
    if (-1 < (int)pRStack_80) {
      pRVar13->pad = (int)pRStack_80;
      pRVar7 = (RSA *)0x1;
    }
  }
  else {
    pcVar12 = sigret;
    pRVar14 = pRVar13;
    pcVar15 = pcVar11;
    pRVar5 = (RSA *)(*(code *)PTR_EVP_MD_size_006a8f2c)();
    if (pRVar5 == local_40) {
      iVar6 = (*(code *)PTR_EVP_MD_type_006a84cc)(*(undefined4 *)(iVar16 + 0x14));
      if (iVar6 == 0x5f) {
        if (*(int *)(iVar16 + 0x10) == 1) {
          in_stack_ffffff70 = &pRStack_80;
          pRVar7 = (RSA *)RSA_sign_ASN1_OCTET_STRING
                                    (0x5f,(uchar *)pcVar11,(uint)pRVar5,(uchar *)sigret,
                                     (uint *)in_stack_ffffff70,pRVar4);
          pRVar4 = (RSA *)sigret;
joined_r0x005fddc0:
          sigret = (char *)pRVar5;
          pcVar12 = pcVar11;
          pRVar14 = (RSA *)sigret;
          pcVar15 = (char *)pRVar4;
          if (0 < (int)pRVar7) goto LAB_005fdc30;
        }
        else {
LAB_005fdc88:
          pRVar7 = (RSA *)0xffffffff;
        }
      }
      else {
        iVar6 = *(int *)(iVar16 + 0x10);
        if (iVar6 == 5) {
          iVar6 = *(int *)(iVar16 + 0x20);
          if (iVar6 == 0) {
            uVar2 = (*(code *)PTR_EVP_PKEY_size_006a85f4)(*(undefined4 *)(iVar3 + 8));
            pRVar14 = (RSA *)0x8d;
            pcVar12 = "rsa_pmeth.c";
            iVar6 = (*(code *)PTR_CRYPTO_malloc_006a8108)(uVar2,"rsa_pmeth.c");
            *(int *)(iVar16 + 0x20) = iVar6;
            if (iVar6 == 0) {
              pRVar7 = (RSA *)0xffffffff;
              goto LAB_005fdc40;
            }
          }
          (*(code *)PTR_memcpy_006aabf4)(iVar6,pcVar11,pRVar5);
          iVar3 = *(int *)(iVar16 + 0x20);
          uVar2 = (*(code *)PTR_EVP_MD_type_006a84cc)(*(undefined4 *)(iVar16 + 0x14));
          cVar10 = (code)(*(code *)PTR_RSA_X931_hash_id_006aa840)(uVar2);
          *(code *)((int)&pRVar5->pad + iVar3) = cVar10;
          pcVar11 = *(char **)(iVar16 + 0x20);
          in_stack_ffffff70 = (RSA **)&DAT_00000005;
          pRStack_80 = (RSA *)(*(code *)PTR_RSA_private_encrypt_006a873c)
                                        ((code *)((int)&pRVar5->pad + 1),pcVar11,sigret,pRVar4);
          goto LAB_005fdc30;
        }
        if (iVar6 == 1) {
          uVar2 = (*(code *)PTR_EVP_MD_type_006a84cc)(*(undefined4 *)(iVar16 + 0x14));
          in_stack_ffffff70 = &pRStack_80;
          pRVar7 = (RSA *)(*(code *)PTR_RSA_sign_006a8b64)(uVar2,pcVar11,pRVar5,sigret);
          pRVar4 = (RSA *)sigret;
          goto joined_r0x005fddc0;
        }
        pRVar7 = (RSA *)0xffffffff;
        if (iVar6 == 6) {
          pRVar5 = *(RSA **)(iVar16 + 0x20);
          if (pRVar5 == (RSA *)0x0) {
            uVar2 = (*(code *)PTR_EVP_PKEY_size_006a85f4)(*(undefined4 *)(iVar3 + 8));
            pRVar14 = (RSA *)0x8d;
            pcVar12 = "rsa_pmeth.c";
            pRVar5 = (RSA *)(*(code *)PTR_CRYPTO_malloc_006a8108)(uVar2,"rsa_pmeth.c");
            *(RSA **)(iVar16 + 0x20) = pRVar5;
            if (pRVar5 == (RSA *)0x0) goto LAB_005fdc88;
          }
          pcVar15 = *(char **)(iVar16 + 0x14);
          in_stack_ffffff70 = *(RSA ***)(iVar16 + 0x18);
          iVar3 = (*(code *)PTR_RSA_padding_add_PKCS1_PSS_mgf1_006aa848)
                            (pRVar4,pRVar5,pcVar11,pcVar15);
          pcVar12 = (char *)pRVar5;
          pRVar14 = (RSA *)pcVar11;
          if (iVar3 != 0) {
            uVar2 = (*(code *)PTR_RSA_size_006a8730)(pRVar4);
            pcVar11 = *(char **)(iVar16 + 0x20);
            in_stack_ffffff70 = (RSA **)0x3;
            pRStack_80 = (RSA *)(*(code *)PTR_RSA_private_encrypt_006a873c)
                                          (uVar2,pcVar11,sigret,pRVar4);
            goto LAB_005fdc30;
          }
          goto LAB_005fdc88;
        }
      }
    }
    else {
      pRVar14 = (RSA *)0x8f;
      pcVar15 = "rsa_pmeth.c";
      in_stack_ffffff70 = (RSA **)0xce;
      pcVar12 = (char *)0x8e;
      (*(code *)PTR_ERR_put_error_006a9030)(4,0x8e,0x8f,"rsa_pmeth.c");
      pRVar7 = (RSA *)0xffffffff;
    }
  }
LAB_005fdc40:
  if (iStack_7c == *(int *)puVar1) {
    return pRVar7;
  }
  iVar3 = iStack_7c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iVar6 = *(int *)(iVar3 + 0x14);
  iVar16 = *(int *)(iVar3 + 8);
  iVar3 = *(int *)PTR___stack_chk_guard_006aabf0;
  uVar2 = *(undefined4 *)(iVar16 + 0x14);
  if (*(int *)(iVar6 + 0x14) == 0) {
    iVar8 = *(int *)(iVar6 + 0x20);
    if (iVar8 == 0) {
      uVar9 = (*(code *)PTR_EVP_PKEY_size_006a85f4)(iVar16);
      iVar8 = (*(code *)PTR_CRYPTO_malloc_006a8108)(uVar9,"rsa_pmeth.c",0x8d);
      *(int *)(iVar6 + 0x20) = iVar8;
      if (iVar8 == 0) {
LAB_005fe018:
        pRVar13 = (RSA *)0xffffffff;
        goto LAB_005fdf2c;
      }
    }
    ppRStack_c8 = (RSA **)(*(code *)PTR_RSA_public_decrypt_006a8740)
                                    (pRVar14,pcVar12,iVar8,uVar2,*(undefined4 *)(iVar6 + 0x10));
    if (ppRStack_c8 != (RSA **)0x0) {
LAB_005fdf98:
      if (in_stack_ffffff70 == ppRStack_c8) {
        iVar16 = (*(code *)PTR_memcmp_006aabd8)
                           (pcVar15,*(undefined4 *)(iVar6 + 0x20),in_stack_ffffff70);
        pRVar13 = (RSA *)(uint)(iVar16 == 0);
        goto LAB_005fdf2c;
      }
    }
  }
  else {
    iVar8 = *(int *)(iVar6 + 0x10);
    if (iVar8 == 1) {
      uVar9 = (*(code *)PTR_EVP_MD_type_006a84cc)(*(int *)(iVar6 + 0x14));
      pRVar13 = (RSA *)(*(code *)PTR_RSA_verify_006a8b68)
                                 (uVar9,pcVar15,in_stack_ffffff70,pcVar12,pRVar14,uVar2);
      goto LAB_005fdf2c;
    }
    if (iVar8 == 5) {
      iVar16 = pkey_rsa_verifyrecover();
      if (0 < iVar16) goto LAB_005fdf98;
    }
    else {
      pRVar13 = (RSA *)0xffffffff;
      if (iVar8 != 6) goto LAB_005fdf2c;
      iVar8 = *(int *)(iVar6 + 0x20);
      if (iVar8 == 0) {
        uVar9 = (*(code *)PTR_EVP_PKEY_size_006a85f4)(iVar16);
        iVar8 = (*(code *)PTR_CRYPTO_malloc_006a8108)(uVar9,"rsa_pmeth.c",0x8d);
        *(int *)(iVar6 + 0x20) = iVar8;
        if (iVar8 == 0) goto LAB_005fe018;
      }
      iVar16 = (*(code *)PTR_RSA_public_decrypt_006a8740)(pRVar14,pcVar12,iVar8,uVar2,3);
      if (0 < iVar16) {
        iVar16 = (*(code *)PTR_RSA_verify_PKCS1_PSS_mgf1_006aa850)
                           (uVar2,pcVar15,*(undefined4 *)(iVar6 + 0x14),
                            *(undefined4 *)(iVar6 + 0x18),*(undefined4 *)(iVar6 + 0x20),
                            *(undefined4 *)(iVar6 + 0x1c));
        pRVar13 = (RSA *)(uint)(0 < iVar16);
        goto LAB_005fdf2c;
      }
    }
  }
  pRVar13 = (RSA *)0x0;
LAB_005fdf2c:
  if (iVar3 == *(int *)puVar1) {
    return pRVar13;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  pRVar13 = (RSA *)(*(code *)PTR_ERR_func_error_string_006a9560)(DSA_str_functs._0_4_);
  if (pRVar13 == (RSA *)0x0) {
    (*(code *)PTR_ERR_load_strings_006a9564)(0,DSA_str_functs);
                    /* WARNING: Could not recover jumptable at 0x005fe110. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pRVar13 = (RSA *)(*(code *)PTR_ERR_load_strings_006a9564)(0,DSA_str_reasons);
    return pRVar13;
  }
  return pRVar13;
}

