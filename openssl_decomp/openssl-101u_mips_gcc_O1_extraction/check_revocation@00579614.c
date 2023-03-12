
undefined4 check_revocation(int param_1,int param_2)

{
  undefined *puVar1;
  uint uVar2;
  undefined4 uVar3;
  X509_NAME *pXVar4;
  undefined4 uVar5;
  int iVar6;
  X509 *pXVar7;
  EVP_PKEY *pEVar8;
  int iVar9;
  EVP_PKEY *pEVar10;
  undefined4 *puVar11;
  undefined4 uVar12;
  int unaff_s0;
  int unaff_s1;
  X509 *unaff_s2;
  int iVar13;
  code *pcVar14;
  code *pcVar15;
  undefined4 uStack_100;
  int iStack_fc;
  int iStack_f4;
  undefined *puStack_f0;
  code *pcStack_ec;
  undefined *puStack_d8;
  undefined4 *puStack_cc;
  undefined4 uStack_c8;
  int iStack_c4;
  int iStack_bc;
  undefined *puStack_b8;
  code *pcStack_b4;
  undefined *puStack_a0;
  undefined4 *puStack_98;
  int iStack_94;
  int iStack_90;
  int iStack_8c;
  X509 *pXStack_88;
  code *pcStack_84;
  undefined4 *local_70;
  undefined4 *local_6c;
  int local_68;
  undefined *local_60;
  undefined4 *local_54;
  int local_50;
  int *local_4c;
  int local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  int local_34;
  int local_30;
  int local_2c;
  
  local_4c = (int *)PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  local_60 = &_gp;
  uVar2 = *(uint *)(*(int *)(param_1 + 0x14) + 0xc);
  if ((uVar2 & 4) == 0) {
LAB_00579688:
    uVar3 = 1;
    param_1 = unaff_s0;
  }
  else {
    unaff_s0 = param_1;
    if ((uVar2 & 8) != 0) {
      local_50 = (*(code *)PTR_sk_num_006a6e2c)(*(undefined4 *)(param_1 + 0x54));
      local_50 = local_50 + -1;
      if (-1 < local_50) goto LAB_005796e8;
      goto LAB_00579688;
    }
    if (*(int *)(param_1 + 0x7c) != 0) goto LAB_00579688;
    local_50 = 0;
LAB_005796e8:
    local_54 = &local_3c;
    iVar13 = 0;
    pcVar14 = *(code **)(local_60 + -0x7fbc);
    do {
      *(int *)(param_1 + 0x60) = iVar13;
      local_44 = 0;
      unaff_s2 = (X509 *)(*pcVar14)(*(undefined4 *)(param_1 + 0x54),iVar13);
      *(undefined4 *)(param_1 + 0x6c) = 0;
      *(undefined4 *)(param_1 + 0x74) = 0;
      *(X509 **)(param_1 + 0x68) = unaff_s2;
      *(undefined4 *)(param_1 + 0x78) = 0;
      iVar6 = 0;
      do {
        if (*(code **)(param_1 + 0x30) != (code *)0x0) {
          iVar9 = (**(code **)(param_1 + 0x30))(param_1,&local_44,unaff_s2);
          unaff_s1 = 0;
          if (iVar9 != 0) {
            *(int *)(param_1 + 0x70) = local_44;
            param_2 = local_44;
            iVar9 = (**(code **)(param_1 + 0x34))(param_1);
            if (iVar9 != 0) goto LAB_00579770;
LAB_005798b8:
            (**(code **)(local_60 + -0x7d80))(local_44);
            (**(code **)(local_60 + -0x7d80))(unaff_s1);
            uVar3 = 0;
            *(undefined4 *)(param_1 + 0x70) = 0;
            goto LAB_0057968c;
          }
LAB_00579948:
          *(undefined4 *)(param_1 + 100) = 3;
          param_2 = param_1;
          unaff_s1 = (**(code **)(param_1 + 0x20))(0);
          (**(code **)(local_60 + -0x7d80))(local_44);
          (**(code **)(local_60 + -0x7d80))(0);
          *(undefined4 *)(param_1 + 0x70) = 0;
          if (unaff_s1 != 0) goto LAB_00579990;
          uVar3 = 0;
          goto LAB_0057968c;
        }
        local_40 = 0;
        local_3c = 0;
        local_34 = 0;
        local_30 = 0;
        pXVar4 = X509_get_issuer_name(unaff_s2);
        local_68 = *(int *)(param_1 + 0x10);
        local_38 = *(undefined4 *)(param_1 + 0x78);
        local_70 = local_54;
        local_6c = &local_38;
        iVar9 = get_crl_sk(param_1,&local_34,&local_30,&local_40);
        if (iVar9 == 0) {
          iVar9 = (**(code **)(param_1 + 0x44))(param_1,pXVar4);
          if ((iVar9 != 0) || (local_34 == 0)) {
            local_70 = local_54;
            local_6c = &local_38;
            local_68 = iVar9;
            get_crl_sk(param_1,&local_34,&local_30,&local_40);
            (**(code **)(local_60 + -0x7d88))(iVar9,*(undefined4 *)(local_60 + -0x7d80));
            goto joined_r0x00579940;
          }
        }
        else {
joined_r0x00579940:
          if (local_34 == 0) goto LAB_00579948;
        }
        unaff_s1 = local_30;
        *(undefined4 *)(param_1 + 0x6c) = local_40;
        *(int *)(param_1 + 0x70) = local_34;
        *(undefined4 *)(param_1 + 0x74) = local_3c;
        *(undefined4 *)(param_1 + 0x78) = local_38;
        param_2 = local_34;
        local_44 = local_34;
        iVar9 = (**(code **)(param_1 + 0x34))(param_1);
        if (iVar9 == 0) goto LAB_005798b8;
LAB_00579770:
        if (unaff_s1 == 0) {
LAB_005797b4:
          param_2 = local_44;
          iVar9 = (**(code **)(param_1 + 0x38))(param_1,local_44,unaff_s2);
          if (iVar9 == 0) goto LAB_005798b8;
          pcVar14 = *(code **)(local_60 + -0x7d80);
        }
        else {
          param_2 = unaff_s1;
          iVar9 = (**(code **)(param_1 + 0x34))(param_1);
          if ((iVar9 == 0) ||
             (param_2 = unaff_s1, iVar9 = (**(code **)(param_1 + 0x38))(param_1,unaff_s1,unaff_s2),
             iVar9 == 0)) goto LAB_005798b8;
          pcVar14 = *(code **)(local_60 + -0x7d80);
          if (iVar9 != 2) goto LAB_005797b4;
        }
        (*pcVar14)(local_44);
        (**(code **)(local_60 + -0x7d80))(unaff_s1);
        iVar9 = *(int *)(param_1 + 0x78);
        local_44 = 0;
        if (iVar9 == iVar6) goto LAB_00579948;
        iVar6 = iVar9;
      } while (iVar9 != 0x807f);
      (**(code **)(local_60 + -0x7d80))(0);
      (**(code **)(local_60 + -0x7d80))(0);
      *(undefined4 *)(param_1 + 0x70) = 0;
LAB_00579990:
      iVar13 = iVar13 + 1;
      pcVar14 = *(code **)(local_60 + -0x7fbc);
    } while (iVar13 <= local_50);
    uVar3 = 1;
  }
LAB_0057968c:
  if (local_2c == *local_4c) {
    return uVar3;
  }
  pcStack_84 = X509_gmtime_adj;
  iStack_bc = local_2c;
  (**(code **)(local_60 + -0x5330))();
  puStack_b8 = PTR___stack_chk_guard_006a9ae8;
  puStack_a0 = &_gp;
  iStack_94 = *(int *)PTR___stack_chk_guard_006a9ae8;
  iStack_90 = param_1;
  iStack_8c = unaff_s1;
  pXStack_88 = unaff_s2;
  (*(code *)PTR_time_006a9adc)(&puStack_98);
  if ((iStack_bc == 0) || ((*(uint *)(iStack_bc + 0xc) & 0x40) != 0)) {
LAB_00579a54:
    pcVar14 = *(code **)(puStack_a0 + -0x5ef0);
  }
  else if (*(int *)(iStack_bc + 4) == 0x17) {
    pcVar14 = *(code **)(puStack_a0 + -0x6138);
  }
  else {
    pcVar14 = *(code **)(puStack_a0 + -0x6134);
    if (*(int *)(iStack_bc + 4) != 0x18) goto LAB_00579a54;
  }
  puVar11 = (undefined4 *)0x0;
  uVar3 = (*pcVar14)(iStack_bc,puStack_98,0,param_2);
  if (iStack_94 == *(int *)puStack_b8) {
    return uVar3;
  }
  pcStack_b4 = X509_time_adj;
  iStack_f4 = iStack_94;
  (**(code **)(puStack_a0 + -0x5330))();
  puStack_f0 = PTR___stack_chk_guard_006a9ae8;
  puStack_d8 = &_gp;
  iStack_c4 = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (puVar11 == (undefined4 *)0x0) {
    puStack_cc = puStack_98;
    (*(code *)PTR_time_006a9adc)(&uStack_c8);
    puStack_98 = puStack_cc;
  }
  else {
    uStack_c8 = *puVar11;
  }
  pcVar14 = *(code **)(puStack_d8 + -0x5ef0);
  if (iStack_f4 == 0) goto LAB_00579b20;
  if ((*(uint *)(iStack_f4 + 0xc) & 0x40) == 0) {
    if (*(int *)(iStack_f4 + 4) == 0x17) {
      pcVar14 = *(code **)(puStack_d8 + -0x6138);
      goto LAB_00579b20;
    }
    pcVar14 = *(code **)(puStack_d8 + -0x6134);
    if (*(int *)(iStack_f4 + 4) == 0x18) goto LAB_00579b20;
  }
  pcVar14 = *(code **)(puStack_d8 + -0x5ef0);
LAB_00579b20:
  uVar12 = 0;
  uVar3 = uStack_c8;
  uVar5 = (*pcVar14)(iStack_f4);
  if (iStack_c4 == *(int *)puStack_f0) {
    return uVar5;
  }
  pcStack_ec = X509_time_adj_ex;
  iVar13 = iStack_c4;
  (**(code **)(puStack_d8 + -0x5330))();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iStack_fc = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (puStack_98 == (undefined4 *)0x0) {
    (*(code *)PTR_time_006a9adc)(&uStack_100);
  }
  else {
    uStack_100 = *puStack_98;
  }
  pcVar14 = (code *)PTR_ASN1_TIME_adj_006a8ef0;
  if ((((iVar13 == 0) || ((*(uint *)(iVar13 + 0xc) & 0x40) != 0)) ||
      (pcVar14 = (code *)PTR_ASN1_UTCTIME_adj_006a8ca8, *(int *)(iVar13 + 4) == 0x17)) ||
     (pcVar14 = (code *)PTR_ASN1_TIME_adj_006a8ef0,
     pcVar15 = (code *)PTR_ASN1_GENERALIZEDTIME_adj_006a8cac, *(int *)(iVar13 + 4) != 0x18)) {
    pcVar15 = pcVar14;
  }
  uVar5 = uStack_100;
  uVar3 = (*pcVar15)(iVar13,uStack_100,uVar3,uVar12);
  if (iStack_fc == *(int *)puVar1) {
    return uVar3;
  }
  iVar13 = iStack_fc;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if ((iVar13 != 0) && (iVar6 = (*(code *)PTR_EVP_PKEY_missing_parameters_006a7170)(), iVar6 == 0))
  {
    return 1;
  }
  iVar6 = 0;
  do {
    iVar9 = (*(code *)PTR_sk_num_006a6e2c)(uVar5);
    if (iVar9 <= iVar6) {
      uVar5 = 0x6b;
      uVar3 = 0x78a;
LAB_00579d60:
      (*(code *)PTR_ERR_put_error_006a7f34)(0xb,0x6e,uVar5,"x509_vfy.c",uVar3);
      return 0;
    }
    pXVar7 = (X509 *)(*(code *)PTR_sk_value_006a6e24)(uVar5,iVar6);
    pEVar8 = X509_get_pubkey(pXVar7);
    if (pEVar8 == (EVP_PKEY *)0x0) {
      uVar5 = 0x6c;
      uVar3 = 0x77e;
      goto LAB_00579d60;
    }
    iVar9 = (*(code *)PTR_EVP_PKEY_missing_parameters_006a7170)(pEVar8);
    if (iVar9 == 0) {
      iVar9 = iVar6 + -1;
      if (-1 < iVar6 + -1) {
        do {
          iVar6 = iVar9 + -1;
          pXVar7 = (X509 *)(*(code *)PTR_sk_value_006a6e24)(uVar5,iVar9);
          pEVar10 = X509_get_pubkey(pXVar7);
          (*(code *)PTR_EVP_PKEY_copy_parameters_006a7174)(pEVar10,pEVar8);
          (*(code *)PTR_EVP_PKEY_free_006a6e78)(pEVar10);
          iVar9 = iVar6;
        } while (iVar6 != -1);
      }
      if (iVar13 != 0) {
        (*(code *)PTR_EVP_PKEY_copy_parameters_006a7174)(iVar13,pEVar8);
      }
      (*(code *)PTR_EVP_PKEY_free_006a6e78)(pEVar8);
      return 1;
    }
    iVar6 = iVar6 + 1;
    (*(code *)PTR_EVP_PKEY_free_006a6e78)(pEVar8);
  } while( true );
}

