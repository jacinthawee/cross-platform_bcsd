
int dsa_priv_decode(undefined4 param_1,undefined4 *param_2)

{
  undefined *puVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  char **ppcVar8;
  undefined4 uVar9;
  int unaff_s4;
  undefined4 uVar10;
  undefined4 *puVar11;
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
  undefined *puStack_78;
  char **ppcStack_74;
  undefined4 *puStack_70;
  undefined4 uStack_6c;
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
  
  puStack_78 = PTR___stack_chk_guard_006aabf0;
  ppcStack_74 = &local_3c;
  local_48 = &_gp;
  local_24 = *(int *)PTR___stack_chk_guard_006aabf0;
  ppcVar8 = ppcStack_74;
  local_50 = param_2;
  iVar2 = (*(code *)PTR_PKCS8_pkey_get0_006a98c0)(0,ppcStack_74,&local_38,&local_2c);
  if (iVar2 != 0) {
    (**(code **)(local_48 + -0x661c))(0,&local_34,&local_30,local_2c);
    if (*local_3c == '0') {
      unaff_s4 = (**(code **)(local_48 + -0x607c))(0,ppcStack_74,local_38);
      if ((unaff_s4 != 0) && (iVar2 = (**(code **)(local_48 + -0x7fb4))(unaff_s4), iVar2 == 2)) {
        piVar3 = (int *)(**(code **)(local_48 + -0x7fbc))(unaff_s4,0);
        piVar4 = (int *)(**(code **)(local_48 + -0x7fbc))(unaff_s4,1);
        if (*piVar3 == 0x10) {
          *param_2 = 2;
          local_30 = (undefined4 *)piVar3[1];
        }
        else {
          if (local_34 != 0x10) goto LAB_005fee78;
          *param_2 = 3;
        }
        if (*piVar4 == 2) {
          ppcStack_74 = (char **)piVar4[1];
          goto LAB_005fed74;
        }
      }
LAB_005fee78:
      ppcStack_74 = (char **)0x0;
LAB_005fecf4:
      local_50 = (undefined4 *)0x125;
      param_2 = (undefined4 *)0x0;
      (**(code **)(local_48 + -0x6eb0))(10,0x73,0x72,"dsa_ameth.c");
      puVar11 = (undefined4 *)0x0;
    }
    else {
      local_28 = local_3c;
      ppcStack_74 = (char **)(**(code **)(local_48 + -0x69d4))(0,ppcStack_74,local_38);
      if (ppcStack_74 == (char **)0x0) {
LAB_005fef14:
        ppcStack_74 = (char **)0x0;
LAB_005fecf0:
        unaff_s4 = 0;
        goto LAB_005fecf4;
      }
      if (ppcStack_74[1] == (char *)0x102) {
        pcVar12 = *(code **)(local_48 + -0x7f4c);
        *param_2 = 4;
        (*pcVar12)(ppcStack_74);
        ppcStack_74 = (char **)(**(code **)(local_48 + -0x5684))(0,&local_28,local_38);
        if (ppcStack_74 == (char **)0x0) goto LAB_005fef14;
      }
      unaff_s4 = 0;
      if (local_34 != 0x10) goto LAB_005fecf0;
LAB_005fed74:
      local_28 = (char *)local_30[2];
      param_2 = (undefined4 *)(**(code **)(local_48 + -0x78a4))(0,&local_28,*local_30);
      if (param_2 == (undefined4 *)0x0) goto LAB_005fecf4;
      iVar2 = (**(code **)(local_48 + -0x7dcc))(ppcStack_74,0);
      param_2[7] = iVar2;
      if (iVar2 == 0) {
        pcVar12 = *(code **)(local_48 + -0x6eb0);
        uVar10 = 0x6d;
        local_50 = (undefined4 *)0x106;
LAB_005fef78:
        puVar11 = (undefined4 *)0x0;
        (*pcVar12)(10,0x73,uVar10,"dsa_ameth.c");
      }
      else {
        iVar2 = (**(code **)(local_48 + -0x7c2c))();
        param_2[6] = iVar2;
        if (iVar2 == 0) {
          pcVar12 = *(code **)(local_48 + -0x6eb0);
          uVar10 = 0x41;
          local_50 = (undefined4 *)0x10c;
          goto LAB_005fef78;
        }
        puVar11 = (undefined4 *)(**(code **)(local_48 + -0x74a8))();
        if (puVar11 == (undefined4 *)0x0) {
          pcVar12 = *(code **)(local_48 + -0x6eb0);
          uVar10 = 0x41;
          local_50 = (undefined4 *)0x111;
        }
        else {
          local_50 = puVar11;
          iVar2 = (**(code **)(local_48 + -0x7498))(param_2[6],param_2[5],param_2[7],param_2[3]);
          if (iVar2 != 0) {
            ppcVar8 = (char **)&DAT_00000074;
            (**(code **)(local_48 + -0x69fc))(param_1,0x74,param_2);
            (**(code **)(local_48 + -0x74a0))(puVar11);
            if (unaff_s4 == 0) {
              (**(code **)(local_48 + -0x7f4c))(ppcStack_74);
              iVar2 = 1;
            }
            else {
              ppcVar8 = *(char ***)(local_48 + -0x7948);
              (**(code **)(local_48 + -0x7d88))(unaff_s4);
              iVar2 = 1;
            }
            goto LAB_005fec50;
          }
          pcVar12 = *(code **)(local_48 + -0x6eb0);
          uVar10 = 0x6d;
          local_50 = (undefined4 *)0x117;
        }
        (*pcVar12)(10,0x73,uVar10,"dsa_ameth.c");
      }
    }
    (**(code **)(local_48 + -0x74a0))(puVar11);
    if (ppcStack_74 != (char **)0x0) {
      (**(code **)(local_48 + -0x7f4c))(ppcStack_74);
    }
    ppcVar8 = *(char ***)(local_48 + -0x7948);
    (**(code **)(local_48 + -0x7d88))(unaff_s4);
    (**(code **)(local_48 + -0x78b4))(param_2);
    iVar2 = 0;
  }
LAB_005fec50:
  if (local_24 == *(int *)puStack_78) {
    return iVar2;
  }
  pcStack_64 = dsa_pub_encode;
  iStack_a8 = local_24;
  (**(code **)(local_48 + -0x5328))();
  puStack_ac = PTR___stack_chk_guard_006aabf0;
  puVar1 = PTR_i2d_DSAPublicKey_006aa860;
  puStack_88 = &_gp;
  iStack_80 = 0;
  iStack_7c = *(int *)PTR___stack_chk_guard_006aabf0;
  pcStack_b4 = ppcVar8[5];
  puStack_70 = param_2;
  uStack_6c = param_1;
  iStack_68 = unaff_s4;
  if ((((ppcVar8[6] == (char *)0x0) || (*(int *)(pcStack_b4 + 0xc) == 0)) ||
      (*(int *)(pcStack_b4 + 0x10) == 0)) || (*(int *)(pcStack_b4 + 0x14) == 0)) {
    *(undefined4 *)(pcStack_b4 + 8) = 0;
    uVar10 = 0xffffffff;
    pcStack_b4 = (char *)(*(code *)puVar1)(pcStack_b4,&iStack_80);
    piStack_b0 = (int *)0x0;
    if ((int)pcStack_b4 < 1) goto LAB_005ff0b8;
LAB_005ff168:
    uVar9 = (**(code **)(puStack_88 + -0x7ca0))(0x74);
    iStack_90 = iStack_80;
    pcStack_8c = pcStack_b4;
    iVar2 = (**(code **)(puStack_88 + -0x6618))(iStack_a8,uVar9,uVar10,piStack_b0);
    if (iVar2 == 0) goto LAB_005ff0e0;
    iVar2 = 1;
  }
  else {
    piStack_b0 = (int *)(*(code *)PTR_ASN1_STRING_new_006a98b4)();
    iVar2 = (**(code **)(puStack_88 + -0x776c))(pcStack_b4,piStack_b0 + 2);
    *piStack_b0 = iVar2;
    if (iVar2 < 1) {
      iStack_90 = 0x9a;
      uVar9 = 0x76;
      (**(code **)(puStack_88 + -0x6eb0))(10,0x76,0x41,"dsa_ameth.c");
      if (iStack_80 != 0) {
        piStack_b0 = (int *)0x0;
LAB_005ff0ec:
        (**(code **)(puStack_88 + -0x7f58))();
        goto LAB_005ff0fc;
      }
    }
    else {
      pcVar12 = *(code **)(puStack_88 + -0x5680);
      *(undefined4 *)(pcStack_b4 + 8) = 0;
      uVar10 = 0x10;
      pcStack_b4 = (char *)(*pcVar12)(pcStack_b4,&iStack_80);
      if (0 < (int)pcStack_b4) goto LAB_005ff168;
LAB_005ff0b8:
      iStack_90 = 0xa9;
      uVar9 = 0x76;
      (**(code **)(puStack_88 + -0x6eb0))(10,0x76,0x41,"dsa_ameth.c");
LAB_005ff0e0:
      if (iStack_80 != 0) goto LAB_005ff0ec;
LAB_005ff0fc:
      if (piStack_b0 != (int *)0x0) {
        (**(code **)(puStack_88 + -0x6624))(piStack_b0);
      }
    }
    iVar2 = 0;
  }
  if (iStack_7c == *(int *)puStack_ac) {
    return iVar2;
  }
  pcStack_a4 = dsa_pub_decode;
  iVar2 = iStack_7c;
  (**(code **)(puStack_88 + -0x5328))();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iStack_bc = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar5 = (*(code *)PTR_X509_PUBKEY_get0_param_006a98cc)(0,auStack_d4,&uStack_cc,&uStack_c0,uVar9);
  if (iVar5 != 0) {
    (*(code *)PTR_X509_ALGOR_get0_006a98c4)(0,&iStack_c8,&puStack_c4,uStack_c0);
    if (iStack_c8 == 0x10) {
      uStack_d0 = puStack_c4[2];
      iVar5 = (*(code *)PTR_d2i_DSAparams_006a863c)(0,&uStack_d0,*puStack_c4);
      if (iVar5 != 0) {
LAB_005ff2f8:
        iVar6 = (*(code *)PTR_d2i_ASN1_INTEGER_006a950c)(0,auStack_d4,uStack_cc);
        if (iVar6 == 0) {
          (*(code *)PTR_ERR_put_error_006a9030)(10,0x75,0x68,"dsa_ameth.c",0x73);
        }
        else {
          iVar7 = (*(code *)PTR_ASN1_INTEGER_to_BN_006a8114)(iVar6,0);
          *(int *)(iVar5 + 0x18) = iVar7;
          if (iVar7 != 0) {
            (*(code *)PTR_ASN1_INTEGER_free_006a7f94)(iVar6);
            (*(code *)PTR_EVP_PKEY_assign_006a94e4)(iVar2,0x74,iVar5);
            iVar2 = 1;
            goto LAB_005ff254;
          }
          (*(code *)PTR_ERR_put_error_006a9030)(10,0x75,0x6c,"dsa_ameth.c",0x79);
          (*(code *)PTR_ASN1_INTEGER_free_006a7f94)(iVar6);
        }
        (*(code *)PTR_DSA_free_006a862c)(iVar5);
        iVar2 = 0;
        goto LAB_005ff254;
      }
      uVar9 = 0x68;
      uVar10 = 0x5e;
    }
    else if ((iStack_c8 == 5) || (iStack_c8 == -1)) {
      iVar5 = (*(code *)PTR_DSA_new_006a8624)();
      if (iVar5 != 0) goto LAB_005ff2f8;
      uVar9 = 0x41;
      uVar10 = 0x67;
    }
    else {
      uVar9 = 0x69;
      uVar10 = 0x6d;
    }
    (*(code *)PTR_ERR_put_error_006a9030)(10,0x75,uVar9,"dsa_ameth.c",uVar10);
  }
  iVar2 = 0;
LAB_005ff254:
  if (iStack_bc == *(int *)puVar1) {
    return iVar2;
  }
  iVar2 = iStack_bc;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar5 = (*(code *)PTR_d2i_DSAPrivateKey_006a9f3c)(0);
  if (iVar5 == 0) {
    (*(code *)PTR_ERR_put_error_006a9030)(10,0x7a,10,"dsa_ameth.c",0x215);
    return 0;
  }
  (*(code *)PTR_EVP_PKEY_assign_006a94e4)(iVar2,0x74,iVar5);
  return 1;
}

