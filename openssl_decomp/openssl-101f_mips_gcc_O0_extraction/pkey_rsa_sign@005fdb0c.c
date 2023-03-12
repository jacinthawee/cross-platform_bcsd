
uint pkey_rsa_sign(int param_1,RSA *param_2,RSA *param_3,RSA *param_4,RSA *param_5)

{
  undefined *puVar1;
  RSA *pRVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uchar uVar8;
  int iVar6;
  undefined4 uVar7;
  char *pcVar9;
  RSA *pRVar10;
  char *pcVar11;
  int iVar12;
  int iVar13;
  RSA *rsa;
  uint *puStack_78;
  uint *in_stack_ffffffc0;
  uint local_30;
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iVar12 = *(int *)(param_1 + 0x14);
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  rsa = *(RSA **)(*(int *)(param_1 + 8) + 0x14);
  if (*(int *)(iVar12 + 0x14) == 0) {
    in_stack_ffffffc0 = *(uint **)(iVar12 + 0x10);
    local_30 = (*(code *)PTR_RSA_private_encrypt_006a873c)(param_5,param_4,param_2,rsa);
LAB_005fdc30:
    uVar5 = local_30;
    pcVar9 = (char *)param_4;
    pRVar10 = param_2;
    pcVar11 = (char *)rsa;
    if (-1 < (int)local_30) {
      param_3->pad = local_30;
      uVar5 = 1;
    }
  }
  else {
    pcVar9 = (char *)param_2;
    pRVar10 = param_3;
    pcVar11 = (char *)param_4;
    pRVar2 = (RSA *)(*(code *)PTR_EVP_MD_size_006a8f2c)();
    if (pRVar2 == param_5) {
      iVar3 = (*(code *)PTR_EVP_MD_type_006a84cc)(*(undefined4 *)(iVar12 + 0x14));
      if (iVar3 == 0x5f) {
        if (*(int *)(iVar12 + 0x10) == 1) {
          in_stack_ffffffc0 = &local_30;
          uVar5 = RSA_sign_ASN1_OCTET_STRING
                            (0x5f,(uchar *)param_4,(uint)pRVar2,(uchar *)param_2,in_stack_ffffffc0,
                             rsa);
          rsa = param_2;
joined_r0x005fddc0:
          param_2 = pRVar2;
          pcVar9 = (char *)param_4;
          pRVar10 = param_2;
          pcVar11 = (char *)rsa;
          if (0 < (int)uVar5) goto LAB_005fdc30;
        }
        else {
LAB_005fdc88:
          uVar5 = 0xffffffff;
        }
      }
      else {
        iVar3 = *(int *)(iVar12 + 0x10);
        if (iVar3 == 5) {
          iVar3 = *(int *)(iVar12 + 0x20);
          if (iVar3 == 0) {
            uVar4 = (*(code *)PTR_EVP_PKEY_size_006a85f4)(*(undefined4 *)(param_1 + 8));
            pRVar10 = (RSA *)0x8d;
            pcVar9 = "rsa_pmeth.c";
            iVar3 = (*(code *)PTR_CRYPTO_malloc_006a8108)(uVar4,"rsa_pmeth.c");
            *(int *)(iVar12 + 0x20) = iVar3;
            if (iVar3 == 0) {
              uVar5 = 0xffffffff;
              goto LAB_005fdc40;
            }
          }
          (*(code *)PTR_memcpy_006aabf4)(iVar3,param_4,pRVar2);
          iVar3 = *(int *)(iVar12 + 0x20);
          uVar4 = (*(code *)PTR_EVP_MD_type_006a84cc)(*(undefined4 *)(iVar12 + 0x14));
          uVar8 = (*(code *)PTR_RSA_X931_hash_id_006aa840)(uVar4);
          *(uchar *)((int)&pRVar2->pad + iVar3) = uVar8;
          param_4 = *(RSA **)(iVar12 + 0x20);
          in_stack_ffffffc0 = (uint *)&DAT_00000005;
          local_30 = (*(code *)PTR_RSA_private_encrypt_006a873c)
                               ((uchar *)((int)&pRVar2->pad + 1),param_4,param_2,rsa);
          goto LAB_005fdc30;
        }
        if (iVar3 == 1) {
          uVar4 = (*(code *)PTR_EVP_MD_type_006a84cc)(*(undefined4 *)(iVar12 + 0x14));
          in_stack_ffffffc0 = &local_30;
          uVar5 = (*(code *)PTR_RSA_sign_006a8b64)(uVar4,param_4,pRVar2,param_2);
          rsa = param_2;
          goto joined_r0x005fddc0;
        }
        uVar5 = 0xffffffff;
        if (iVar3 == 6) {
          pRVar2 = *(RSA **)(iVar12 + 0x20);
          if (pRVar2 == (RSA *)0x0) {
            uVar4 = (*(code *)PTR_EVP_PKEY_size_006a85f4)(*(undefined4 *)(param_1 + 8));
            pRVar10 = (RSA *)0x8d;
            pcVar9 = "rsa_pmeth.c";
            pRVar2 = (RSA *)(*(code *)PTR_CRYPTO_malloc_006a8108)(uVar4,"rsa_pmeth.c");
            *(RSA **)(iVar12 + 0x20) = pRVar2;
            if (pRVar2 == (RSA *)0x0) goto LAB_005fdc88;
          }
          pcVar11 = *(char **)(iVar12 + 0x14);
          in_stack_ffffffc0 = *(uint **)(iVar12 + 0x18);
          iVar3 = (*(code *)PTR_RSA_padding_add_PKCS1_PSS_mgf1_006aa848)(rsa,pRVar2,param_4,pcVar11)
          ;
          pcVar9 = (char *)pRVar2;
          pRVar10 = param_4;
          if (iVar3 != 0) {
            uVar4 = (*(code *)PTR_RSA_size_006a8730)(rsa);
            param_4 = *(RSA **)(iVar12 + 0x20);
            in_stack_ffffffc0 = (uint *)0x3;
            local_30 = (*(code *)PTR_RSA_private_encrypt_006a873c)(uVar4,param_4,param_2,rsa);
            goto LAB_005fdc30;
          }
          goto LAB_005fdc88;
        }
      }
    }
    else {
      pRVar10 = (RSA *)0x8f;
      pcVar11 = "rsa_pmeth.c";
      in_stack_ffffffc0 = (uint *)0xce;
      pcVar9 = (char *)0x8e;
      (*(code *)PTR_ERR_put_error_006a9030)(4,0x8e,0x8f,"rsa_pmeth.c");
      uVar5 = 0xffffffff;
    }
  }
LAB_005fdc40:
  if (local_2c == *(int *)puVar1) {
    return uVar5;
  }
  iVar12 = local_2c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iVar13 = *(int *)(iVar12 + 0x14);
  iVar3 = *(int *)(iVar12 + 8);
  iVar12 = *(int *)PTR___stack_chk_guard_006aabf0;
  uVar4 = *(undefined4 *)(iVar3 + 0x14);
  if (*(int *)(iVar13 + 0x14) == 0) {
    iVar6 = *(int *)(iVar13 + 0x20);
    if (iVar6 == 0) {
      uVar7 = (*(code *)PTR_EVP_PKEY_size_006a85f4)(iVar3);
      iVar6 = (*(code *)PTR_CRYPTO_malloc_006a8108)(uVar7,"rsa_pmeth.c",0x8d);
      *(int *)(iVar13 + 0x20) = iVar6;
      if (iVar6 == 0) {
LAB_005fe018:
        uVar5 = 0xffffffff;
        goto LAB_005fdf2c;
      }
    }
    puStack_78 = (uint *)(*(code *)PTR_RSA_public_decrypt_006a8740)
                                   (pRVar10,pcVar9,iVar6,uVar4,*(undefined4 *)(iVar13 + 0x10));
    if (puStack_78 != (uint *)0x0) {
LAB_005fdf98:
      if (in_stack_ffffffc0 == puStack_78) {
        iVar3 = (*(code *)PTR_memcmp_006aabd8)
                          (pcVar11,*(undefined4 *)(iVar13 + 0x20),in_stack_ffffffc0);
        uVar5 = (uint)(iVar3 == 0);
        goto LAB_005fdf2c;
      }
    }
  }
  else {
    iVar6 = *(int *)(iVar13 + 0x10);
    if (iVar6 == 1) {
      uVar7 = (*(code *)PTR_EVP_MD_type_006a84cc)(*(int *)(iVar13 + 0x14));
      uVar5 = (*(code *)PTR_RSA_verify_006a8b68)
                        (uVar7,pcVar11,in_stack_ffffffc0,pcVar9,pRVar10,uVar4);
      goto LAB_005fdf2c;
    }
    if (iVar6 == 5) {
      iVar3 = pkey_rsa_verifyrecover();
      if (0 < iVar3) goto LAB_005fdf98;
    }
    else {
      uVar5 = 0xffffffff;
      if (iVar6 != 6) goto LAB_005fdf2c;
      iVar6 = *(int *)(iVar13 + 0x20);
      if (iVar6 == 0) {
        uVar7 = (*(code *)PTR_EVP_PKEY_size_006a85f4)(iVar3);
        iVar6 = (*(code *)PTR_CRYPTO_malloc_006a8108)(uVar7,"rsa_pmeth.c",0x8d);
        *(int *)(iVar13 + 0x20) = iVar6;
        if (iVar6 == 0) goto LAB_005fe018;
      }
      iVar3 = (*(code *)PTR_RSA_public_decrypt_006a8740)(pRVar10,pcVar9,iVar6,uVar4,3);
      if (0 < iVar3) {
        iVar3 = (*(code *)PTR_RSA_verify_PKCS1_PSS_mgf1_006aa850)
                          (uVar4,pcVar11,*(undefined4 *)(iVar13 + 0x14),
                           *(undefined4 *)(iVar13 + 0x18),*(undefined4 *)(iVar13 + 0x20),
                           *(undefined4 *)(iVar13 + 0x1c));
        uVar5 = (uint)(0 < iVar3);
        goto LAB_005fdf2c;
      }
    }
  }
  uVar5 = 0;
LAB_005fdf2c:
  if (iVar12 == *(int *)puVar1) {
    return uVar5;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  uVar5 = (*(code *)PTR_ERR_func_error_string_006a9560)(DSA_str_functs._0_4_);
  if (uVar5 != 0) {
    return uVar5;
  }
  (*(code *)PTR_ERR_load_strings_006a9564)(0,DSA_str_functs);
                    /* WARNING: Could not recover jumptable at 0x005fe110. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar5 = (*(code *)PTR_ERR_load_strings_006a9564)(0,DSA_str_reasons);
  return uVar5;
}

