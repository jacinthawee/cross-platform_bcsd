
uint pkey_rsa_sign(int param_1,RSA *param_2,RSA *param_3,RSA *param_4,RSA *param_5)

{
  undefined *puVar1;
  RSA *pRVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uchar *puVar6;
  uchar uVar9;
  int iVar7;
  undefined4 uVar8;
  char *pcVar10;
  RSA *pRVar11;
  char *pcVar12;
  int iVar13;
  int iVar14;
  RSA *rsa;
  uchar *puVar15;
  uint *puStack_78;
  uint *in_stack_ffffffc0;
  uint local_30;
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iVar13 = *(int *)(param_1 + 0x14);
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  rsa = *(RSA **)(*(int *)(param_1 + 8) + 0x14);
  if (*(int *)(iVar13 + 0x14) == 0) {
    in_stack_ffffffc0 = *(uint **)(iVar13 + 0x10);
    local_30 = (*(code *)PTR_RSA_private_encrypt_006a764c)(param_5,param_4,param_2,rsa);
LAB_005fbd74:
    uVar5 = local_30;
    pcVar10 = (char *)param_4;
    pRVar11 = param_2;
    pcVar12 = (char *)rsa;
    if (-1 < (int)local_30) {
      param_3->pad = local_30;
      uVar5 = 1;
    }
  }
  else {
    pcVar10 = (char *)param_2;
    pRVar11 = param_3;
    pcVar12 = (char *)param_4;
    pRVar2 = (RSA *)(*(code *)PTR_EVP_MD_size_006a7e3c)();
    if (pRVar2 == param_5) {
      iVar3 = (*(code *)PTR_EVP_MD_type_006a73cc)(*(undefined4 *)(iVar13 + 0x14));
      if (iVar3 == 0x5f) {
        uVar5 = 0xffffffff;
        if (*(int *)(iVar13 + 0x10) == 1) {
          in_stack_ffffffc0 = &local_30;
          uVar5 = RSA_sign_ASN1_OCTET_STRING
                            (0x5f,(uchar *)param_4,(uint)pRVar2,(uchar *)param_2,in_stack_ffffffc0,
                             rsa);
          rsa = param_2;
joined_r0x005fbe20:
          param_2 = pRVar2;
          pcVar10 = (char *)param_4;
          pRVar11 = param_2;
          pcVar12 = (char *)rsa;
          if (0 < (int)uVar5) goto LAB_005fbd74;
        }
      }
      else {
        iVar3 = *(int *)(iVar13 + 0x10);
        if (iVar3 == 5) {
          puVar15 = (uchar *)((int)&pRVar2->pad + 1);
          puVar6 = (uchar *)(*(code *)PTR_EVP_PKEY_size_006a74f8)(*(undefined4 *)(param_1 + 8));
          if (puVar15 <= puVar6) {
            iVar3 = *(int *)(iVar13 + 0x20);
            if (iVar3 == 0) {
              uVar4 = (*(code *)PTR_EVP_PKEY_size_006a74f8)(*(undefined4 *)(param_1 + 8));
              iVar3 = (*(code *)PTR_CRYPTO_malloc_006a7008)(uVar4,"rsa_pmeth.c",0x8c);
              *(int *)(iVar13 + 0x20) = iVar3;
              if (iVar3 == 0) {
                pcVar12 = "rsa_pmeth.c";
                pRVar11 = (RSA *)&DAT_00000041;
                pcVar10 = (char *)0x8e;
                in_stack_ffffffc0 = (uint *)0xec;
                (*(code *)PTR_ERR_put_error_006a7f34)(4,0x8e,0x41,"rsa_pmeth.c");
                goto LAB_005fbde4;
              }
            }
            (*(code *)PTR_memcpy_006a9aec)(iVar3,param_4,pRVar2);
            iVar3 = *(int *)(iVar13 + 0x20);
            uVar4 = (*(code *)PTR_EVP_MD_type_006a73cc)(*(undefined4 *)(iVar13 + 0x14));
            uVar9 = (*(code *)PTR_RSA_X931_hash_id_006a9738)(uVar4);
            *(uchar *)((int)&pRVar2->pad + iVar3) = uVar9;
            param_4 = *(RSA **)(iVar13 + 0x20);
            in_stack_ffffffc0 = (uint *)&DAT_00000005;
            local_30 = (*(code *)PTR_RSA_private_encrypt_006a764c)(puVar15,param_4,param_2,rsa);
            goto LAB_005fbd74;
          }
          pRVar11 = (RSA *)&DAT_00000078;
          in_stack_ffffffc0 = (uint *)0xe8;
          goto LAB_005fbefc;
        }
        if (iVar3 == 1) {
          uVar4 = (*(code *)PTR_EVP_MD_type_006a73cc)(*(undefined4 *)(iVar13 + 0x14));
          in_stack_ffffffc0 = &local_30;
          uVar5 = (*(code *)PTR_RSA_sign_006a7a78)(uVar4,param_4,pRVar2,param_2);
          rsa = param_2;
          goto joined_r0x005fbe20;
        }
        uVar5 = 0xffffffff;
        if (iVar3 == 6) {
          pRVar2 = *(RSA **)(iVar13 + 0x20);
          if (pRVar2 == (RSA *)0x0) {
            uVar4 = (*(code *)PTR_EVP_PKEY_size_006a74f8)(*(undefined4 *)(param_1 + 8));
            pRVar11 = (RSA *)&DAT_0000008c;
            pcVar10 = "rsa_pmeth.c";
            pRVar2 = (RSA *)(*(code *)PTR_CRYPTO_malloc_006a7008)(uVar4,"rsa_pmeth.c");
            *(RSA **)(iVar13 + 0x20) = pRVar2;
            if (pRVar2 == (RSA *)0x0) goto LAB_005fbde4;
          }
          pcVar12 = *(char **)(iVar13 + 0x14);
          in_stack_ffffffc0 = *(uint **)(iVar13 + 0x18);
          iVar3 = (*(code *)PTR_RSA_padding_add_PKCS1_PSS_mgf1_006a9740)(rsa,pRVar2,param_4,pcVar12)
          ;
          pcVar10 = (char *)pRVar2;
          pRVar11 = param_4;
          if (iVar3 != 0) {
            uVar4 = (*(code *)PTR_RSA_size_006a7640)(rsa);
            param_4 = *(RSA **)(iVar13 + 0x20);
            in_stack_ffffffc0 = (uint *)0x3;
            local_30 = (*(code *)PTR_RSA_private_encrypt_006a764c)(uVar4,param_4,param_2,rsa);
            goto LAB_005fbd74;
          }
LAB_005fbde4:
          uVar5 = 0xffffffff;
        }
      }
    }
    else {
      pRVar11 = (RSA *)0x8f;
      in_stack_ffffffc0 = (uint *)&DAT_000000ca;
LAB_005fbefc:
      pcVar12 = "rsa_pmeth.c";
      pcVar10 = (char *)0x8e;
      (*(code *)PTR_ERR_put_error_006a7f34)(4,0x8e,pRVar11,"rsa_pmeth.c");
      uVar5 = 0xffffffff;
    }
  }
  if (local_2c == *(int *)puVar1) {
    return uVar5;
  }
  iVar13 = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iVar14 = *(int *)(iVar13 + 0x14);
  iVar3 = *(int *)(iVar13 + 8);
  iVar13 = *(int *)PTR___stack_chk_guard_006a9ae8;
  uVar4 = *(undefined4 *)(iVar3 + 0x14);
  if (*(int *)(iVar14 + 0x14) == 0) {
    iVar7 = *(int *)(iVar14 + 0x20);
    if (iVar7 == 0) {
      uVar8 = (*(code *)PTR_EVP_PKEY_size_006a74f8)(iVar3);
      iVar7 = (*(code *)PTR_CRYPTO_malloc_006a7008)(uVar8,"rsa_pmeth.c",0x8c);
      *(int *)(iVar14 + 0x20) = iVar7;
      if (iVar7 == 0) {
LAB_005fc1b8:
        uVar5 = 0xffffffff;
        goto LAB_005fc0cc;
      }
    }
    puStack_78 = (uint *)(*(code *)PTR_RSA_public_decrypt_006a7650)
                                   (pRVar11,pcVar10,iVar7,uVar4,*(undefined4 *)(iVar14 + 0x10));
    if (puStack_78 != (uint *)0x0) {
LAB_005fc138:
      if (in_stack_ffffffc0 == puStack_78) {
        iVar3 = (*(code *)PTR_memcmp_006a9ad0)
                          (pcVar12,*(undefined4 *)(iVar14 + 0x20),in_stack_ffffffc0);
        uVar5 = (uint)(iVar3 == 0);
        goto LAB_005fc0cc;
      }
    }
  }
  else {
    iVar7 = *(int *)(iVar14 + 0x10);
    if (iVar7 == 1) {
      uVar8 = (*(code *)PTR_EVP_MD_type_006a73cc)(*(int *)(iVar14 + 0x14));
      uVar5 = (*(code *)PTR_RSA_verify_006a7a7c)
                        (uVar8,pcVar12,in_stack_ffffffc0,pcVar10,pRVar11,uVar4);
      goto LAB_005fc0cc;
    }
    if (iVar7 == 5) {
      iVar3 = pkey_rsa_verifyrecover();
      if (0 < iVar3) goto LAB_005fc138;
    }
    else {
      uVar5 = 0xffffffff;
      if (iVar7 != 6) goto LAB_005fc0cc;
      iVar7 = *(int *)(iVar14 + 0x20);
      if (iVar7 == 0) {
        uVar8 = (*(code *)PTR_EVP_PKEY_size_006a74f8)(iVar3);
        iVar7 = (*(code *)PTR_CRYPTO_malloc_006a7008)(uVar8,"rsa_pmeth.c",0x8c);
        *(int *)(iVar14 + 0x20) = iVar7;
        if (iVar7 == 0) goto LAB_005fc1b8;
      }
      iVar3 = (*(code *)PTR_RSA_public_decrypt_006a7650)(pRVar11,pcVar10,iVar7,uVar4,3);
      if (0 < iVar3) {
        iVar3 = (*(code *)PTR_RSA_verify_PKCS1_PSS_mgf1_006a9748)
                          (uVar4,pcVar12,*(undefined4 *)(iVar14 + 0x14),
                           *(undefined4 *)(iVar14 + 0x18),*(undefined4 *)(iVar14 + 0x20),
                           *(undefined4 *)(iVar14 + 0x1c));
        uVar5 = (uint)(0 < iVar3);
        goto LAB_005fc0cc;
      }
    }
  }
  uVar5 = 0;
LAB_005fc0cc:
  if (iVar13 == *(int *)puVar1) {
    return uVar5;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  uVar5 = (*(code *)PTR_ERR_func_error_string_006a8440)(DSA_str_functs._0_4_);
  if (uVar5 != 0) {
    return uVar5;
  }
  (*(code *)PTR_ERR_load_strings_006a8444)(0,DSA_str_functs);
                    /* WARNING: Could not recover jumptable at 0x005fc2b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar5 = (*(code *)PTR_ERR_load_strings_006a8444)(0,DSA_str_reasons);
  return uVar5;
}

