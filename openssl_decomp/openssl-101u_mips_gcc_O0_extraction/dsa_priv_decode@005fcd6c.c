
char ** dsa_priv_decode(undefined4 param_1,undefined4 *param_2)

{
  undefined *puVar1;
  char **ppcVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  char **ppcVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  int unaff_s3;
  int unaff_s4;
  undefined4 uVar11;
  code *pcVar12;
  undefined auStack_d4 [4];
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  int iStack_c8;
  undefined4 *puStack_c4;
  undefined4 uStack_c0;
  int iStack_bc;
  char *pcStack_b4;
  int *piStack_b0;
  undefined *puStack_ac;
  int iStack_a8;
  code *pcStack_a4;
  int iStack_90;
  char *pcStack_8c;
  undefined *puStack_88;
  int iStack_80;
  int iStack_7c;
  char **ppcStack_78;
  undefined *puStack_74;
  undefined4 *puStack_70;
  int iStack_6c;
  int iStack_68;
  code *pcStack_64;
  undefined4 *local_50;
  undefined *local_48;
  char *local_3c;
  undefined4 local_38;
  int local_34;
  undefined4 *local_30;
  undefined4 local_2c;
  char *local_28;
  int local_24;
  
  puStack_74 = PTR___stack_chk_guard_006a9ae8;
  local_48 = &_gp;
  local_24 = *(int *)PTR___stack_chk_guard_006a9ae8;
  ppcVar6 = &local_3c;
  local_50 = param_2;
  ppcVar2 = (char **)(*(code *)PTR_PKCS8_pkey_get0_006a87a0)(0,&local_3c,&local_38,&local_2c);
  ppcStack_78 = &local_3c;
  if (ppcVar2 != (char **)0x0) {
    (**(code **)(local_48 + -0x663c))(0,&local_34,&local_30,local_2c);
    if (*local_3c == '0') {
      unaff_s3 = (**(code **)(local_48 + -0x609c))(0,&local_3c,local_38);
      if ((unaff_s3 != 0) && (iVar5 = (**(code **)(local_48 + -0x7fb4))(unaff_s3), iVar5 == 2)) {
        piVar3 = (int *)(**(code **)(local_48 + -0x7fbc))(unaff_s3,0);
        piVar4 = (int *)(**(code **)(local_48 + -0x7fbc))(unaff_s3,1);
        if (*piVar3 == 0x10) {
          *param_2 = 2;
          local_30 = (undefined4 *)piVar3[1];
        }
        else {
          if (local_34 != 0x10) goto LAB_005fcff4;
          *param_2 = 3;
        }
        if (*piVar4 == 2) {
          unaff_s4 = piVar4[1];
          goto LAB_005fcef0;
        }
      }
LAB_005fcff4:
      unaff_s4 = 0;
LAB_005fce7c:
      local_50 = (undefined4 *)0x110;
      ppcVar6 = (char **)&DAT_00000073;
      iVar5 = 0;
      (**(code **)(local_48 + -0x6eac))(10,0x73,0x72,"dsa_ameth.c");
      param_2 = (undefined4 *)0x0;
LAB_005fceac:
      ppcVar2 = (char **)0x0;
      (**(code **)(local_48 + -0x78b0))(iVar5);
    }
    else {
      local_28 = local_3c;
      unaff_s4 = (**(code **)(local_48 + -0x69ec))(0,&local_3c,local_38);
      if (unaff_s4 == 0) {
LAB_005fd0a8:
        unaff_s4 = 0;
LAB_005fce78:
        unaff_s3 = 0;
        goto LAB_005fce7c;
      }
      if (*(int *)(unaff_s4 + 4) == 0x102) {
        pcVar12 = *(code **)(local_48 + -0x664c);
        *param_2 = 4;
        (*pcVar12)(unaff_s4);
        unaff_s4 = (**(code **)(local_48 + -0x568c))(0,&local_28,local_38);
        if (unaff_s4 == 0) goto LAB_005fd0a8;
      }
      unaff_s3 = 0;
      if (local_34 != 0x10) goto LAB_005fce78;
LAB_005fcef0:
      local_28 = (char *)local_30[2];
      iVar5 = (**(code **)(local_48 + -0x78a0))(0,&local_28,*local_30);
      if (iVar5 == 0) goto LAB_005fce7c;
      iVar7 = (**(code **)(local_48 + -0x7dcc))(unaff_s4,0);
      *(int *)(iVar5 + 0x1c) = iVar7;
      if (iVar7 == 0) {
        pcVar12 = *(code **)(local_48 + -0x6eac);
        uVar11 = 0x6d;
        local_50 = (undefined4 *)0xf8;
LAB_005fd0e4:
        ppcVar6 = (char **)&DAT_00000073;
        param_2 = (undefined4 *)0x0;
        (*pcVar12)(10,0x73,uVar11,"dsa_ameth.c");
        goto LAB_005fceac;
      }
      iVar7 = (**(code **)(local_48 + -0x7c2c))();
      *(int *)(iVar5 + 0x18) = iVar7;
      if (iVar7 == 0) {
        pcVar12 = *(code **)(local_48 + -0x6eac);
        uVar11 = 0x41;
        local_50 = (undefined4 *)0xfd;
        goto LAB_005fd0e4;
      }
      param_2 = (undefined4 *)(**(code **)(local_48 + -0x7494))();
      if (param_2 == (undefined4 *)0x0) {
        pcVar12 = *(code **)(local_48 + -0x6eac);
        uVar11 = 0x41;
        local_50 = (undefined4 *)0x101;
LAB_005fcfa0:
        ppcVar6 = (char **)&DAT_00000073;
        (*pcVar12)(10,0x73,uVar11,"dsa_ameth.c");
        goto LAB_005fceac;
      }
      local_50 = param_2;
      iVar7 = (**(code **)(local_48 + -0x7484))
                        (*(undefined4 *)(iVar5 + 0x18),*(undefined4 *)(iVar5 + 0x14),
                         *(undefined4 *)(iVar5 + 0x1c),*(undefined4 *)(iVar5 + 0xc));
      if (iVar7 == 0) {
        pcVar12 = *(code **)(local_48 + -0x6eac);
        uVar11 = 0x6d;
        local_50 = (undefined4 *)0x106;
        goto LAB_005fcfa0;
      }
      ppcVar6 = (char **)&DAT_00000074;
      (**(code **)(local_48 + -0x6a14))(param_1,0x74,iVar5);
      ppcVar2 = (char **)0x1;
    }
    (**(code **)(local_48 + -0x748c))(param_2);
    ppcStack_78 = ppcVar2;
    if (unaff_s3 == 0) {
      (**(code **)(local_48 + -0x664c))(unaff_s4);
    }
    else {
      ppcVar6 = *(char ***)(local_48 + -0x7948);
      (**(code **)(local_48 + -0x7d88))(unaff_s3);
    }
  }
  if (local_24 == *(int *)puStack_74) {
    return ppcVar2;
  }
  pcStack_64 = dsa_pub_encode;
  iStack_a8 = local_24;
  (**(code **)(local_48 + -0x5330))();
  puStack_ac = PTR___stack_chk_guard_006a9ae8;
  puVar1 = PTR_i2d_DSAPublicKey_006a9758;
  puStack_88 = &_gp;
  iStack_80 = 0;
  iStack_7c = *(int *)PTR___stack_chk_guard_006a9ae8;
  pcStack_b4 = ppcVar6[5];
  puStack_70 = param_2;
  iStack_6c = unaff_s3;
  iStack_68 = unaff_s4;
  if ((((ppcVar6[6] == (char *)0x0) || (*(int *)(pcStack_b4 + 0xc) == 0)) ||
      (*(int *)(pcStack_b4 + 0x10) == 0)) || (*(int *)(pcStack_b4 + 0x14) == 0)) {
    *(undefined4 *)(pcStack_b4 + 8) = 0;
    piStack_b0 = (int *)0x0;
    pcStack_b4 = (char *)(*(code *)puVar1)(pcStack_b4,&iStack_80);
    uVar11 = 0xffffffff;
    if ((int)pcStack_b4 < 1) {
LAB_005fd210:
      iStack_90 = 0x9e;
      uVar10 = 0x76;
      (**(code **)(puStack_88 + -0x6eac))(10,0x76,0x41,"dsa_ameth.c");
LAB_005fd238:
      if (iStack_80 != 0) goto LAB_005fd244;
      goto LAB_005fd254;
    }
LAB_005fd2c0:
    uVar10 = (**(code **)(puStack_88 + -0x7ca0))(0x74);
    iStack_90 = iStack_80;
    pcStack_8c = pcStack_b4;
    iVar5 = (**(code **)(puStack_88 + -0x6638))(iStack_a8,uVar10,uVar11,piStack_b0);
    if (iVar5 == 0) goto LAB_005fd238;
    ppcVar6 = (char **)0x1;
  }
  else {
    piStack_b0 = (int *)(*(code *)PTR_ASN1_STRING_new_006a8790)();
    if (piStack_b0 == (int *)0x0) {
      iStack_90 = 0x8d;
      uVar10 = 0x76;
      (**(code **)(puStack_88 + -0x6eac))(10,0x76,0x41,"dsa_ameth.c");
      if (iStack_80 == 0) {
        ppcVar6 = (char **)0x0;
        goto LAB_005fd26c;
      }
LAB_005fd244:
      (**(code **)(puStack_88 + -0x7f58))();
LAB_005fd254:
      pcVar12 = *(code **)(puStack_88 + -0x6644);
      if (piStack_b0 != (int *)0x0) goto LAB_005fd25c;
    }
    else {
      iVar5 = (**(code **)(puStack_88 + -0x775c))(pcStack_b4,piStack_b0 + 2);
      *piStack_b0 = iVar5;
      if (0 < iVar5) {
        pcVar12 = *(code **)(puStack_88 + -0x5688);
        *(undefined4 *)(pcStack_b4 + 8) = 0;
        uVar11 = 0x10;
        pcStack_b4 = (char *)(*pcVar12)(pcStack_b4,&iStack_80);
        if (0 < (int)pcStack_b4) goto LAB_005fd2c0;
        goto LAB_005fd210;
      }
      iStack_90 = 0x92;
      uVar10 = 0x76;
      (**(code **)(puStack_88 + -0x6eac))(10,0x76,0x41,"dsa_ameth.c");
      if (iStack_80 != 0) goto LAB_005fd244;
      pcVar12 = *(code **)(puStack_88 + -0x6644);
LAB_005fd25c:
      (*pcVar12)(piStack_b0);
    }
    ppcVar6 = (char **)0x0;
  }
LAB_005fd26c:
  if (iStack_7c == *(int *)puStack_ac) {
    return ppcVar6;
  }
  pcStack_a4 = dsa_pub_decode;
  iVar5 = iStack_7c;
  (**(code **)(puStack_88 + -0x5330))();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iStack_bc = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar7 = (*(code *)PTR_X509_PUBKEY_get0_param_006a87ac)(0,auStack_d4,&uStack_cc,&uStack_c0,uVar10);
  if (iVar7 != 0) {
    (*(code *)PTR_X509_ALGOR_get0_006a87a4)(0,&iStack_c8,&puStack_c4,uStack_c0);
    if (iStack_c8 == 0x10) {
      uStack_d0 = puStack_c4[2];
      iVar7 = (*(code *)PTR_d2i_DSAparams_006a7540)(0,&uStack_d0,*puStack_c4);
      if (iVar7 != 0) {
LAB_005fd488:
        iVar8 = (*(code *)PTR_d2i_ASN1_INTEGER_006a83f4)(0,auStack_d4,uStack_cc);
        if (iVar8 == 0) {
          (*(code *)PTR_ERR_put_error_006a7f34)(10,0x75,0x68,"dsa_ameth.c",0x6b);
        }
        else {
          iVar9 = (*(code *)PTR_ASN1_INTEGER_to_BN_006a7014)(iVar8,0);
          *(int *)(iVar7 + 0x18) = iVar9;
          if (iVar9 != 0) {
            (*(code *)PTR_ASN1_INTEGER_free_006a6e94)(iVar8);
            (*(code *)PTR_EVP_PKEY_assign_006a83cc)(iVar5,0x74,iVar7);
            ppcVar6 = (char **)0x1;
            goto LAB_005fd3e4;
          }
          (*(code *)PTR_ERR_put_error_006a7f34)(10,0x75,0x6c,"dsa_ameth.c",0x70);
          (*(code *)PTR_ASN1_INTEGER_free_006a6e94)(iVar8);
        }
        (*(code *)PTR_DSA_free_006a7530)(iVar7);
        ppcVar6 = (char **)0x0;
        goto LAB_005fd3e4;
      }
      uVar10 = 0x68;
      uVar11 = 0x5c;
    }
    else if ((iStack_c8 == 5) || (iStack_c8 == -1)) {
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
  ppcVar6 = (char **)0x0;
LAB_005fd3e4:
  if (iStack_bc == *(int *)puVar1) {
    return ppcVar6;
  }
  iVar5 = iStack_bc;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar7 = (*(code *)PTR_d2i_DSAPrivateKey_006a8e20)(0);
  if (iVar7 == 0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(10,0x7a,10,"dsa_ameth.c",0x205);
    return (char **)0x0;
  }
  (*(code *)PTR_EVP_PKEY_assign_006a83cc)(iVar5,0x74,iVar7);
  return (char **)0x1;
}

