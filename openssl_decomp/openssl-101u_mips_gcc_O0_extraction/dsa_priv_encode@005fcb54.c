
char ** dsa_priv_encode(int param_1,int param_2)

{
  undefined *puVar1;
  int iVar2;
  char **ppcVar3;
  char **ppcVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  int *unaff_s0;
  int unaff_s2;
  int unaff_s3;
  int unaff_s4;
  undefined4 uVar11;
  code *pcVar12;
  undefined auStack_11c [4];
  undefined4 uStack_118;
  undefined4 uStack_114;
  int iStack_110;
  undefined4 *puStack_10c;
  undefined4 uStack_108;
  int iStack_104;
  char *pcStack_fc;
  int *piStack_f8;
  undefined *puStack_f4;
  int iStack_f0;
  code *pcStack_ec;
  int iStack_d8;
  char *pcStack_d4;
  undefined *puStack_d0;
  int iStack_c8;
  int iStack_c4;
  char **ppcStack_c0;
  undefined *puStack_bc;
  undefined4 *puStack_b8;
  int iStack_b4;
  int iStack_b0;
  code *pcStack_ac;
  undefined4 *puStack_98;
  undefined *puStack_90;
  char *pcStack_84;
  undefined4 uStack_80;
  int iStack_7c;
  undefined4 *puStack_78;
  undefined4 uStack_74;
  char *pcStack_70;
  int iStack_6c;
  int *piStack_64;
  undefined *puStack_60;
  int iStack_5c;
  int iStack_58;
  int local_20;
  int local_1c;
  
  puStack_60 = PTR___stack_chk_guard_006a9ae8;
  local_20 = 0;
  local_1c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if ((*(int *)(param_2 + 0x14) == 0) || (*(int *)(*(int *)(param_2 + 0x14) + 0x1c) == 0)) {
    uVar11 = 0x65;
    param_2 = unaff_s2;
LAB_005fccc8:
    puStack_b8 = (undefined4 *)&DAT_00000074;
    (*(code *)PTR_ERR_put_error_006a7f34)(10,0x74,uVar11,"dsa_ameth.c");
    if (local_20 != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
    ppcVar3 = (char **)0x0;
  }
  else {
    unaff_s0 = (int *)(*(code *)PTR_ASN1_STRING_new_006a8790)();
    unaff_s3 = param_1;
    if (unaff_s0 == (int *)0x0) {
      uVar11 = 0x41;
      goto LAB_005fccc8;
    }
    iVar2 = (*(code *)PTR_i2d_DSAparams_006a7684)(*(undefined4 *)(param_2 + 0x14),unaff_s0 + 2);
    *unaff_s0 = iVar2;
    puVar1 = PTR_BN_to_ASN1_INTEGER_006a70f4;
    if (iVar2 < 1) {
      uVar11 = 0x41;
LAB_005fcd10:
      puStack_b8 = (undefined4 *)&DAT_00000074;
      (*(code *)PTR_ERR_put_error_006a7f34)(10,0x74,uVar11,"dsa_ameth.c");
LAB_005fcc64:
      if (local_20 != 0) {
        (*(code *)PTR_CRYPTO_free_006a6e88)();
      }
      (*(code *)PTR_ASN1_STRING_free_006a879c)(unaff_s0);
      ppcVar3 = (char **)0x0;
    }
    else {
      unaff_s0[1] = 0x10;
      iVar2 = (*(code *)puVar1)(*(undefined4 *)(*(int *)(param_2 + 0x14) + 0x1c),0);
      if (iVar2 == 0) {
        uVar11 = 0x6d;
        param_2 = iVar2;
        goto LAB_005fcd10;
      }
      param_2 = (*(code *)PTR_i2d_ASN1_INTEGER_006a83dc)(iVar2,&local_20);
      (*(code *)PTR_ASN1_STRING_clear_free_006a8794)(iVar2);
      puStack_b8 = (undefined4 *)(*(code *)PTR_OBJ_nid2obj_006a7140)(0x74);
      iVar2 = (*(code *)PTR_PKCS8_pkey_set0_006a8798)(param_1,puStack_b8,0,0x10);
      if (iVar2 == 0) goto LAB_005fcc64;
      ppcVar3 = (char **)0x1;
    }
  }
  if (local_1c == *(int *)puStack_60) {
    return ppcVar3;
  }
  iVar2 = local_1c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_bc = PTR___stack_chk_guard_006a9ae8;
  puStack_90 = &_gp;
  iStack_6c = *(int *)PTR___stack_chk_guard_006a9ae8;
  ppcVar3 = &pcStack_84;
  puStack_98 = puStack_b8;
  piStack_64 = unaff_s0;
  iStack_5c = param_2;
  iStack_58 = unaff_s3;
  ppcVar4 = (char **)(*(code *)PTR_PKCS8_pkey_get0_006a87a0)(0,&pcStack_84,&uStack_80,&uStack_74);
  ppcStack_c0 = &pcStack_84;
  if (ppcVar4 != (char **)0x0) {
    (**(code **)(puStack_90 + -0x663c))(0,&iStack_7c,&puStack_78,uStack_74);
    if (*pcStack_84 == '0') {
      unaff_s3 = (**(code **)(puStack_90 + -0x609c))(0,&pcStack_84,uStack_80);
      if ((unaff_s3 != 0) && (iVar7 = (**(code **)(puStack_90 + -0x7fb4))(unaff_s3), iVar7 == 2)) {
        piVar5 = (int *)(**(code **)(puStack_90 + -0x7fbc))(unaff_s3,0);
        piVar6 = (int *)(**(code **)(puStack_90 + -0x7fbc))(unaff_s3,1);
        if (*piVar5 == 0x10) {
          *puStack_b8 = 2;
          puStack_78 = (undefined4 *)piVar5[1];
        }
        else {
          if (iStack_7c != 0x10) goto LAB_005fcff4;
          *puStack_b8 = 3;
        }
        if (*piVar6 == 2) {
          unaff_s4 = piVar6[1];
          goto LAB_005fcef0;
        }
      }
LAB_005fcff4:
      unaff_s4 = 0;
LAB_005fce7c:
      puStack_98 = (undefined4 *)0x110;
      ppcVar3 = (char **)&DAT_00000073;
      iVar7 = 0;
      (**(code **)(puStack_90 + -0x6eac))(10,0x73,0x72,"dsa_ameth.c");
      puStack_b8 = (undefined4 *)0x0;
LAB_005fceac:
      ppcVar4 = (char **)0x0;
      (**(code **)(puStack_90 + -0x78b0))(iVar7);
    }
    else {
      pcStack_70 = pcStack_84;
      unaff_s4 = (**(code **)(puStack_90 + -0x69ec))(0,&pcStack_84,uStack_80);
      if (unaff_s4 == 0) {
LAB_005fd0a8:
        unaff_s4 = 0;
LAB_005fce78:
        unaff_s3 = 0;
        goto LAB_005fce7c;
      }
      if (*(int *)(unaff_s4 + 4) == 0x102) {
        pcVar12 = *(code **)(puStack_90 + -0x664c);
        *puStack_b8 = 4;
        (*pcVar12)(unaff_s4);
        unaff_s4 = (**(code **)(puStack_90 + -0x568c))(0,&pcStack_70,uStack_80);
        if (unaff_s4 == 0) goto LAB_005fd0a8;
      }
      unaff_s3 = 0;
      if (iStack_7c != 0x10) goto LAB_005fce78;
LAB_005fcef0:
      pcStack_70 = (char *)puStack_78[2];
      iVar7 = (**(code **)(puStack_90 + -0x78a0))(0,&pcStack_70,*puStack_78);
      if (iVar7 == 0) goto LAB_005fce7c;
      iVar8 = (**(code **)(puStack_90 + -0x7dcc))(unaff_s4,0);
      *(int *)(iVar7 + 0x1c) = iVar8;
      if (iVar8 == 0) {
        pcVar12 = *(code **)(puStack_90 + -0x6eac);
        uVar11 = 0x6d;
        puStack_98 = (undefined4 *)0xf8;
LAB_005fd0e4:
        ppcVar3 = (char **)&DAT_00000073;
        puStack_b8 = (undefined4 *)0x0;
        (*pcVar12)(10,0x73,uVar11,"dsa_ameth.c");
        goto LAB_005fceac;
      }
      iVar8 = (**(code **)(puStack_90 + -0x7c2c))();
      *(int *)(iVar7 + 0x18) = iVar8;
      if (iVar8 == 0) {
        pcVar12 = *(code **)(puStack_90 + -0x6eac);
        uVar11 = 0x41;
        puStack_98 = (undefined4 *)0xfd;
        goto LAB_005fd0e4;
      }
      puStack_b8 = (undefined4 *)(**(code **)(puStack_90 + -0x7494))();
      if (puStack_b8 == (undefined4 *)0x0) {
        pcVar12 = *(code **)(puStack_90 + -0x6eac);
        uVar11 = 0x41;
        puStack_98 = (undefined4 *)0x101;
LAB_005fcfa0:
        ppcVar3 = (char **)&DAT_00000073;
        (*pcVar12)(10,0x73,uVar11,"dsa_ameth.c");
        goto LAB_005fceac;
      }
      puStack_98 = puStack_b8;
      iVar8 = (**(code **)(puStack_90 + -0x7484))
                        (*(undefined4 *)(iVar7 + 0x18),*(undefined4 *)(iVar7 + 0x14),
                         *(undefined4 *)(iVar7 + 0x1c),*(undefined4 *)(iVar7 + 0xc));
      if (iVar8 == 0) {
        pcVar12 = *(code **)(puStack_90 + -0x6eac);
        uVar11 = 0x6d;
        puStack_98 = (undefined4 *)0x106;
        goto LAB_005fcfa0;
      }
      ppcVar3 = (char **)&DAT_00000074;
      (**(code **)(puStack_90 + -0x6a14))(iVar2,0x74,iVar7);
      ppcVar4 = (char **)0x1;
    }
    (**(code **)(puStack_90 + -0x748c))(puStack_b8);
    ppcStack_c0 = ppcVar4;
    if (unaff_s3 == 0) {
      (**(code **)(puStack_90 + -0x664c))(unaff_s4);
    }
    else {
      ppcVar3 = *(char ***)(puStack_90 + -0x7948);
      (**(code **)(puStack_90 + -0x7d88))(unaff_s3);
    }
  }
  if (iStack_6c == *(int *)puStack_bc) {
    return ppcVar4;
  }
  pcStack_ac = dsa_pub_encode;
  iStack_f0 = iStack_6c;
  (**(code **)(puStack_90 + -0x5330))();
  puStack_f4 = PTR___stack_chk_guard_006a9ae8;
  puVar1 = PTR_i2d_DSAPublicKey_006a9758;
  puStack_d0 = &_gp;
  iStack_c8 = 0;
  iStack_c4 = *(int *)PTR___stack_chk_guard_006a9ae8;
  pcStack_fc = ppcVar3[5];
  iStack_b4 = unaff_s3;
  iStack_b0 = unaff_s4;
  if ((((ppcVar3[6] == (char *)0x0) || (*(int *)(pcStack_fc + 0xc) == 0)) ||
      (*(int *)(pcStack_fc + 0x10) == 0)) || (*(int *)(pcStack_fc + 0x14) == 0)) {
    *(undefined4 *)(pcStack_fc + 8) = 0;
    piStack_f8 = (int *)0x0;
    pcStack_fc = (char *)(*(code *)puVar1)(pcStack_fc,&iStack_c8);
    uVar11 = 0xffffffff;
    if ((int)pcStack_fc < 1) {
LAB_005fd210:
      iStack_d8 = 0x9e;
      uVar10 = 0x76;
      (**(code **)(puStack_d0 + -0x6eac))(10,0x76,0x41,"dsa_ameth.c");
LAB_005fd238:
      if (iStack_c8 != 0) goto LAB_005fd244;
      goto LAB_005fd254;
    }
LAB_005fd2c0:
    uVar10 = (**(code **)(puStack_d0 + -0x7ca0))(0x74);
    iStack_d8 = iStack_c8;
    pcStack_d4 = pcStack_fc;
    iVar2 = (**(code **)(puStack_d0 + -0x6638))(iStack_f0,uVar10,uVar11,piStack_f8);
    if (iVar2 == 0) goto LAB_005fd238;
    ppcVar3 = (char **)0x1;
  }
  else {
    piStack_f8 = (int *)(*(code *)PTR_ASN1_STRING_new_006a8790)();
    if (piStack_f8 == (int *)0x0) {
      iStack_d8 = 0x8d;
      uVar10 = 0x76;
      (**(code **)(puStack_d0 + -0x6eac))(10,0x76,0x41,"dsa_ameth.c");
      if (iStack_c8 == 0) {
        ppcVar3 = (char **)0x0;
        goto LAB_005fd26c;
      }
LAB_005fd244:
      (**(code **)(puStack_d0 + -0x7f58))();
LAB_005fd254:
      pcVar12 = *(code **)(puStack_d0 + -0x6644);
      if (piStack_f8 != (int *)0x0) goto LAB_005fd25c;
    }
    else {
      iVar2 = (**(code **)(puStack_d0 + -0x775c))(pcStack_fc,piStack_f8 + 2);
      *piStack_f8 = iVar2;
      if (0 < iVar2) {
        pcVar12 = *(code **)(puStack_d0 + -0x5688);
        *(undefined4 *)(pcStack_fc + 8) = 0;
        uVar11 = 0x10;
        pcStack_fc = (char *)(*pcVar12)(pcStack_fc,&iStack_c8);
        if (0 < (int)pcStack_fc) goto LAB_005fd2c0;
        goto LAB_005fd210;
      }
      iStack_d8 = 0x92;
      uVar10 = 0x76;
      (**(code **)(puStack_d0 + -0x6eac))(10,0x76,0x41,"dsa_ameth.c");
      if (iStack_c8 != 0) goto LAB_005fd244;
      pcVar12 = *(code **)(puStack_d0 + -0x6644);
LAB_005fd25c:
      (*pcVar12)(piStack_f8);
    }
    ppcVar3 = (char **)0x0;
  }
LAB_005fd26c:
  if (iStack_c4 == *(int *)puStack_f4) {
    return ppcVar3;
  }
  pcStack_ec = dsa_pub_decode;
  iVar2 = iStack_c4;
  (**(code **)(puStack_d0 + -0x5330))();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iStack_104 = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar7 = (*(code *)PTR_X509_PUBKEY_get0_param_006a87ac)
                    (0,auStack_11c,&uStack_114,&uStack_108,uVar10);
  if (iVar7 != 0) {
    (*(code *)PTR_X509_ALGOR_get0_006a87a4)(0,&iStack_110,&puStack_10c,uStack_108);
    if (iStack_110 == 0x10) {
      uStack_118 = puStack_10c[2];
      iVar7 = (*(code *)PTR_d2i_DSAparams_006a7540)(0,&uStack_118,*puStack_10c);
      if (iVar7 != 0) {
LAB_005fd488:
        iVar8 = (*(code *)PTR_d2i_ASN1_INTEGER_006a83f4)(0,auStack_11c,uStack_114);
        if (iVar8 == 0) {
          (*(code *)PTR_ERR_put_error_006a7f34)(10,0x75,0x68,"dsa_ameth.c",0x6b);
        }
        else {
          iVar9 = (*(code *)PTR_ASN1_INTEGER_to_BN_006a7014)(iVar8,0);
          *(int *)(iVar7 + 0x18) = iVar9;
          if (iVar9 != 0) {
            (*(code *)PTR_ASN1_INTEGER_free_006a6e94)(iVar8);
            (*(code *)PTR_EVP_PKEY_assign_006a83cc)(iVar2,0x74,iVar7);
            ppcVar3 = (char **)0x1;
            goto LAB_005fd3e4;
          }
          (*(code *)PTR_ERR_put_error_006a7f34)(10,0x75,0x6c,"dsa_ameth.c",0x70);
          (*(code *)PTR_ASN1_INTEGER_free_006a6e94)(iVar8);
        }
        (*(code *)PTR_DSA_free_006a7530)(iVar7);
        ppcVar3 = (char **)0x0;
        goto LAB_005fd3e4;
      }
      uVar10 = 0x68;
      uVar11 = 0x5c;
    }
    else if ((iStack_110 == 5) || (iStack_110 == -1)) {
      iVar7 = (*(code *)PTR_DSA_new_006a7528)();
      if (iVar7 != 0) goto LAB_005fd488;
      uVar10 = 0x41;
      uVar11 = 0x62;
    }
    else {
      uVar10 = 0x69;
      uVar11 = 0x66;
    }
    (*(code *)PTR_ERR_put_error_006a7f34)(10,0x75,uVar10,"dsa_ameth.c",uVar11);
  }
  ppcVar3 = (char **)0x0;
LAB_005fd3e4:
  if (iStack_104 == *(int *)puVar1) {
    return ppcVar3;
  }
  iVar2 = iStack_104;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar7 = (*(code *)PTR_d2i_DSAPrivateKey_006a8e20)(0);
  if (iVar7 == 0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(10,0x7a,10,"dsa_ameth.c",0x205);
    return (char **)0x0;
  }
  (*(code *)PTR_EVP_PKEY_assign_006a83cc)(iVar2,0x74,iVar7);
  return (char **)0x1;
}

