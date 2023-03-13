
/* WARNING: Restarted to delay deadcode elimination for space: ram */

int * hwcrhk_rsa_mod_exp(int *param_1,undefined4 *param_2,int param_3)

{
  code *pcVar1;
  undefined *puVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  uint uVar7;
  int iVar8;
  undefined *puVar9;
  int iVar10;
  char *pcVar11;
  int unaff_s1;
  int *unaff_s3;
  undefined4 *unaff_s4;
  undefined4 uStack_8fc;
  uint uStack_8f8;
  undefined4 uStack_8f4;
  uint uStack_8f0;
  undefined *puStack_8ec;
  undefined4 uStack_8e8;
  int iStack_8e4;
  int *piStack_8e0;
  undefined auStack_8dc [1024];
  int iStack_4dc;
  int *piStack_4d4;
  int iStack_4d0;
  undefined *puStack_4cc;
  int *piStack_4c8;
  undefined4 *puStack_4c4;
  undefined *puStack_4c0;
  int local_42c;
  uint local_428;
  undefined auStack_424 [1024];
  int local_24;
  
  puStack_4cc = PTR___stack_chk_guard_006a9ae8;
  puVar9 = auStack_424;
  local_24 = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (hwcrhk_context == 0) {
    param_1 = (int *)&_gp_1;
    if (HWCRHK_lib_error_code == 0) {
      HWCRHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    iVar10 = 0x6a;
    pcVar11 = "e_chil.c";
    puVar9 = &DAT_0000006d;
    (*(code *)PTR_ERR_put_error_006a7f34)(HWCRHK_lib_error_code,0x6d);
    piVar4 = (int *)0x0;
  }
  else {
    unaff_s3 = (int *)(*(code *)PTR_RSA_get_ex_data_006a9534)(param_3,hndidx_rsa);
    unaff_s1 = param_3;
    unaff_s4 = param_2;
    if (unaff_s3 == (int *)0x0) {
      if ((((*(int *)(param_3 + 0x1c) == 0) || (*(int *)(param_3 + 0x20) == 0)) ||
          (*(int *)(param_3 + 0x24) == 0)) ||
         ((*(int *)(param_3 + 0x28) == 0 || (*(int *)(param_3 + 0x2c) == 0)))) {
        param_1 = (int *)&_gp_1;
        if (HWCRHK_lib_error_code == 0) {
          HWCRHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
        }
        iVar10 = 0x69;
        pcVar11 = "e_chil.c";
        puVar9 = &DAT_0000006d;
        (*(code *)PTR_ERR_put_error_006a7f34)(HWCRHK_lib_error_code,0x6d);
        piVar4 = (int *)0x0;
      }
      else {
        (*(code *)PTR_bn_expand2_006a8524)(param_1,*(undefined4 *)(*(int *)(param_3 + 0x10) + 4));
        local_428 = param_1[2] << 2;
        pcVar11 = (char *)**(int ***)(param_3 + 0x1c);
        iVar10 = param_2[1] << 2;
        puVar2 = (undefined *)*param_2;
        local_42c = *param_1;
        iVar3 = (*p_hwcrhk_ModExpCRT)(hwcrhk_context,puVar2);
        uVar7 = local_428 >> 2;
        param_1[1] = uVar7;
        if (uVar7 != 0) {
          iVar8 = *param_1 + (local_428 & 0xfffffffc) + -8;
          do {
            puVar2 = *(undefined **)(iVar8 + 4);
            if (puVar2 != (undefined *)0x0) break;
            uVar7 = uVar7 - 1;
            iVar8 = iVar8 + -4;
          } while (uVar7 != 0);
          param_1[1] = uVar7;
        }
        if (-1 < iVar3) goto LAB_005d39fc;
        if (iVar3 == -2) {
          if (HWCRHK_lib_error_code == 0) {
            HWCRHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
          }
          iVar10 = 0x70;
          pcVar11 = "e_chil.c";
          (*(code *)PTR_ERR_put_error_006a7f34)(HWCRHK_lib_error_code,0x6d);
        }
        else {
          if (HWCRHK_lib_error_code == 0) {
            HWCRHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
          }
          iVar10 = 0x6f;
          pcVar11 = "e_chil.c";
          (*(code *)PTR_ERR_put_error_006a7f34)(HWCRHK_lib_error_code,0x6d);
        }
LAB_005d3a7c:
        param_1 = (int *)&_gp_1;
        (*(code *)PTR_ERR_add_error_data_006a813c)(1,puVar9);
        piVar4 = (int *)0x0;
      }
    }
    else if (*(int *)(param_3 + 0x10) == 0) {
      param_1 = (int *)&_gp_1;
      if (HWCRHK_lib_error_code == 0) {
        HWCRHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
      }
      iVar10 = 0x69;
      pcVar11 = "e_chil.c";
      puVar9 = &DAT_0000006d;
      (*(code *)PTR_ERR_put_error_006a7f34)(HWCRHK_lib_error_code,0x6d);
      piVar4 = (int *)0x0;
    }
    else {
      (*(code *)PTR_bn_expand2_006a8524)(param_1,*(undefined4 *)(*(int *)(param_3 + 0x10) + 4));
      pcVar11 = (char *)&local_42c;
      local_42c = *param_1;
      local_428 = param_1[2] << 2;
      puVar2 = (undefined *)(param_2[1] << 2);
      iVar10 = *unaff_s3;
      iVar3 = (*p_hwcrhk_RSA)(*param_2,puVar2);
      uVar7 = local_428 >> 2;
      param_1[1] = uVar7;
      if (uVar7 != 0) {
        iVar8 = *param_1 + (local_428 & 0xfffffffc) + -8;
        do {
          puVar2 = *(undefined **)(iVar8 + 4);
          if (puVar2 != (undefined *)0x0) break;
          uVar7 = uVar7 - 1;
          iVar8 = iVar8 + -4;
        } while (uVar7 != 0);
        param_1[1] = uVar7;
      }
      param_1 = (int *)&_gp_1;
      if (iVar3 < 0) {
        if (iVar3 == -2) {
          if (HWCRHK_lib_error_code == 0) {
            HWCRHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
          }
          iVar10 = 0x70;
          pcVar11 = "e_chil.c";
          (*(code *)PTR_ERR_put_error_006a7f34)(HWCRHK_lib_error_code,0x6d);
        }
        else {
          if (HWCRHK_lib_error_code == 0) {
            HWCRHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
          }
          iVar10 = 0x6f;
          pcVar11 = "e_chil.c";
          (*(code *)PTR_ERR_put_error_006a7f34)(HWCRHK_lib_error_code,0x6d);
        }
        goto LAB_005d3a7c;
      }
LAB_005d39fc:
      piVar4 = (int *)0x1;
      puVar9 = puVar2;
    }
  }
  if (local_24 == *(int *)puStack_4cc) {
    return piVar4;
  }
  iVar3 = local_24;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  puStack_4c0 = &_gp_1;
  puStack_8ec = auStack_8dc;
  uStack_8e8 = 0x400;
  iStack_4dc = *(int *)PTR___stack_chk_guard_006a9ae8;
  piStack_4d4 = param_1;
  iStack_4d0 = unaff_s1;
  piStack_4c8 = unaff_s3;
  puStack_4c4 = unaff_s4;
  if (hwcrhk_context == 0) {
    if (HWCRHK_lib_error_code == 0) {
      HWCRHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    (*(code *)PTR_ERR_put_error_006a7f34)(HWCRHK_lib_error_code,0x69,0x6a,"e_chil.c",0x316);
    piVar4 = (int *)0x0;
    goto LAB_005d3fe4;
  }
  piVar4 = (int *)(*(code *)PTR_CRYPTO_malloc_006a7008)(4,"e_chil.c",0x31a);
  if (piVar4 == (int *)0x0) {
    if (HWCRHK_lib_error_code == 0) {
      HWCRHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    (*(code *)PTR_ERR_put_error_006a7f34)(HWCRHK_lib_error_code,0x69,0x41,"e_chil.c",0x31c);
    piVar4 = (int *)0x0;
    goto LAB_005d3fe4;
  }
  iStack_8e4 = iVar10;
  piStack_8e0 = (int *)pcVar11;
  iVar10 = (*p_hwcrhk_RSALoadKey)(hwcrhk_context,puVar9,piVar4,&puStack_8ec,&iStack_8e4);
  if (iVar10 != 0) {
    if (HWCRHK_lib_error_code == 0) {
      HWCRHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    (*(code *)PTR_ERR_put_error_006a7f34)(HWCRHK_lib_error_code,0x69,0x66,"e_chil.c",0x322);
    (*(code *)PTR_ERR_add_error_data_006a813c)(1,puStack_8ec);
    piVar4 = (int *)0x0;
    goto LAB_005d3fe4;
  }
  if (*piVar4 == 0) {
    if (HWCRHK_lib_error_code == 0) {
      HWCRHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    (*(code *)PTR_ERR_put_error_006a7f34)(HWCRHK_lib_error_code,0x69,0x6d,"e_chil.c",0x327);
    piVar4 = (int *)0x0;
    goto LAB_005d3fe4;
  }
  iVar10 = (*(code *)PTR_RSA_new_method_006a772c)(iVar3);
  (*(code *)PTR_RSA_set_ex_data_006a953c)(iVar10,hndidx_rsa,piVar4);
  uVar5 = (*(code *)PTR_BN_new_006a71b4)();
  puVar9 = PTR_BN_new_006a71b4;
  *(undefined4 *)(iVar10 + 0x14) = uVar5;
  puVar6 = (undefined4 *)(*(code *)puVar9)();
  pcVar1 = p_hwcrhk_RSAGetPublicKey;
  uStack_8f4 = *puVar6;
  uStack_8fc = **(undefined4 **)(iVar10 + 0x14);
  iVar3 = (*(undefined4 **)(iVar10 + 0x14))[2];
  uStack_8f0 = puVar6[2] << 2;
  *(undefined4 **)(iVar10 + 0x10) = puVar6;
  uStack_8f8 = iVar3 << 2;
  *(uint *)(iVar10 + 0x3c) = *(uint *)(iVar10 + 0x3c) | 0x20;
  iVar3 = (*pcVar1)(*piVar4,&uStack_8f4,&uStack_8fc,&puStack_8ec);
  if (iVar3 == -3) {
    (*(code *)PTR_bn_expand2_006a8524)(*(undefined4 *)(iVar10 + 0x14),uStack_8f8 >> 2);
    (*(code *)PTR_bn_expand2_006a8524)(*(undefined4 *)(iVar10 + 0x10),uStack_8f0 >> 2);
    uStack_8fc = **(undefined4 **)(iVar10 + 0x14);
    uStack_8f4 = **(undefined4 **)(iVar10 + 0x10);
    uStack_8f8 = (*(undefined4 **)(iVar10 + 0x14))[2] << 2;
    uStack_8f0 = (*(undefined4 **)(iVar10 + 0x10))[2] << 2;
    iVar3 = (*p_hwcrhk_RSAGetPublicKey)(*piVar4,&uStack_8f4,&uStack_8fc,&puStack_8ec);
    if (iVar3 != 0) {
      if (HWCRHK_lib_error_code == 0) {
        HWCRHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
      }
      uVar5 = 0x340;
      goto LAB_005d3fb0;
    }
    piVar4 = *(int **)(iVar10 + 0x14);
    uVar7 = uStack_8f8 >> 2;
    piVar4[1] = uVar7;
    if (uVar7 != 0) {
      iVar3 = *piVar4 + (uStack_8f8 & 0xfffffffc) + -8;
      do {
        if (*(int *)(iVar3 + 4) != 0) break;
        uVar7 = uVar7 - 1;
        iVar3 = iVar3 + -4;
      } while (uVar7 != 0);
      piVar4[1] = uVar7;
    }
    piVar4 = *(int **)(iVar10 + 0x10);
    uVar7 = uStack_8f0 >> 2;
    piVar4[1] = uVar7;
    if (uVar7 != 0) {
      iVar3 = *piVar4 + (uStack_8f0 & 0xfffffffc) + -8;
      do {
        if (*(int *)(iVar3 + 4) != 0) break;
        uVar7 = uVar7 - 1;
        iVar3 = iVar3 + -4;
      } while (uVar7 != 0);
      piVar4[1] = uVar7;
    }
    piVar4 = (int *)(*(code *)PTR_EVP_PKEY_new_006a7620)();
    if (piVar4 != (int *)0x0) {
      (*(code *)PTR_EVP_PKEY_assign_006a83cc)(piVar4,6,iVar10);
      goto LAB_005d3fe4;
    }
    if (HWCRHK_lib_error_code == 0) {
      HWCRHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    (*(code *)PTR_ERR_put_error_006a7f34)(HWCRHK_lib_error_code,0x69,0x66,"e_chil.c",0x34b);
  }
  else {
    if (HWCRHK_lib_error_code == 0) {
      HWCRHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    uVar5 = 0x335;
LAB_005d3fb0:
    (*(code *)PTR_ERR_put_error_006a7f34)(HWCRHK_lib_error_code,0x69,0x66,"e_chil.c",uVar5);
    (*(code *)PTR_ERR_add_error_data_006a813c)(1,puStack_8ec);
  }
  (*(code *)PTR_RSA_free_006a7600)(iVar10);
  piVar4 = (int *)0x0;
LAB_005d3fe4:
  if (iStack_4dc == *(int *)puVar2) {
    return piVar4;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  piVar4 = (int *)hwcrhk_load_privkey();
  if (piVar4 == (int *)0x0) {
    return (int *)0x0;
  }
  if (*piVar4 == 6) {
    (*(code *)PTR_CRYPTO_lock_006a8144)(9,10,"e_chil.c",0x36e);
    iVar3 = piVar4[5];
    iVar10 = (*(code *)PTR_RSA_new_006a787c)();
    piVar4[5] = iVar10;
    puVar9 = PTR_CRYPTO_lock_006a8144;
    uVar5 = *(undefined4 *)(iVar3 + 0x14);
    *(undefined4 *)(iVar10 + 0x10) = *(undefined4 *)(iVar3 + 0x10);
    *(undefined4 *)(iVar10 + 0x14) = uVar5;
    *(undefined4 *)(iVar3 + 0x10) = 0;
    *(undefined4 *)(iVar3 + 0x14) = 0;
    (*(code *)puVar9)(10,10,"e_chil.c",0x375);
    (*(code *)PTR_RSA_free_006a7600)(iVar3);
    return piVar4;
  }
  if (HWCRHK_lib_error_code == 0) {
    HWCRHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(HWCRHK_lib_error_code,0x6a,0x67,"e_chil.c",0x37c);
  (*(code *)PTR_EVP_PKEY_free_006a6e78)(piVar4);
  return (int *)0x0;
}

