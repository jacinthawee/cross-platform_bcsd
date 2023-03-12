
ASN1_TIME * X509_gmtime_adj(ASN1_TIME *s,long adj)

{
  undefined *puVar1;
  ASN1_TIME *pAVar2;
  int iVar3;
  X509 *pXVar4;
  EVP_PKEY *pEVar5;
  int iVar6;
  undefined4 uVar7;
  EVP_PKEY *pEVar8;
  int iVar9;
  undefined4 uVar10;
  undefined4 *puVar11;
  undefined4 uVar12;
  code *pcVar13;
  code *pcVar14;
  undefined4 uStack_80;
  int iStack_7c;
  int iStack_74;
  undefined *puStack_70;
  code *pcStack_6c;
  undefined *puStack_58;
  undefined4 *puStack_4c;
  undefined4 uStack_48;
  int iStack_44;
  ASN1_TIME *pAStack_3c;
  undefined *puStack_38;
  code *pcStack_34;
  undefined *local_20;
  undefined4 *local_18;
  int local_14;
  
  puStack_38 = PTR___stack_chk_guard_006aabf0;
  local_20 = &_gp;
  local_14 = *(int *)PTR___stack_chk_guard_006aabf0;
  (*(code *)PTR_time_006aabe4)(&local_18);
  if ((s == (ASN1_TIME *)0x0) || ((s->flags & 0x40U) != 0)) {
LAB_0057cc28:
    pcVar13 = *(code **)(local_20 + -0x5ed4);
  }
  else if (s->type == 0x17) {
    pcVar13 = *(code **)(local_20 + -0x6118);
  }
  else {
    pcVar13 = *(code **)(local_20 + -0x6114);
    if (s->type != 0x18) goto LAB_0057cc28;
  }
  puVar11 = (undefined4 *)0x0;
  pAVar2 = (ASN1_TIME *)(*pcVar13)(s,local_18,0,adj);
  if (local_14 == *(int *)puStack_38) {
    return pAVar2;
  }
  pcStack_34 = X509_time_adj;
  iStack_74 = local_14;
  (**(code **)(local_20 + -0x5328))();
  puStack_70 = PTR___stack_chk_guard_006aabf0;
  puStack_58 = &_gp;
  iStack_44 = *(int *)PTR___stack_chk_guard_006aabf0;
  pAStack_3c = s;
  if (puVar11 == (undefined4 *)0x0) {
    puStack_4c = local_18;
    (*(code *)PTR_time_006aabe4)(&uStack_48);
    local_18 = puStack_4c;
  }
  else {
    uStack_48 = *puVar11;
  }
  pcVar13 = *(code **)(puStack_58 + -0x5ed4);
  if (iStack_74 == 0) goto LAB_0057ccf4;
  if ((*(uint *)(iStack_74 + 0xc) & 0x40) == 0) {
    if (*(int *)(iStack_74 + 4) == 0x17) {
      pcVar13 = *(code **)(puStack_58 + -0x6118);
      goto LAB_0057ccf4;
    }
    pcVar13 = *(code **)(puStack_58 + -0x6114);
    if (*(int *)(iStack_74 + 4) == 0x18) goto LAB_0057ccf4;
  }
  pcVar13 = *(code **)(puStack_58 + -0x5ed4);
LAB_0057ccf4:
  uVar12 = 0;
  uVar7 = uStack_48;
  pAVar2 = (ASN1_TIME *)(*pcVar13)(iStack_74);
  if (iStack_44 == *(int *)puStack_70) {
    return pAVar2;
  }
  pcStack_6c = X509_time_adj_ex;
  iVar9 = iStack_44;
  (**(code **)(puStack_58 + -0x5328))();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iStack_7c = *(int *)PTR___stack_chk_guard_006aabf0;
  if (local_18 == (undefined4 *)0x0) {
    (*(code *)PTR_time_006aabe4)(&uStack_80);
  }
  else {
    uStack_80 = *local_18;
  }
  pcVar13 = (code *)PTR_ASN1_TIME_adj_006aa00c;
  if ((((iVar9 == 0) || ((*(uint *)(iVar9 + 0xc) & 0x40) != 0)) ||
      (pcVar13 = (code *)PTR_ASN1_UTCTIME_adj_006a9dc8, *(int *)(iVar9 + 4) == 0x17)) ||
     (pcVar13 = (code *)PTR_ASN1_TIME_adj_006aa00c,
     pcVar14 = (code *)PTR_ASN1_GENERALIZEDTIME_adj_006a9dcc, *(int *)(iVar9 + 4) != 0x18)) {
    pcVar14 = pcVar13;
  }
  uVar10 = uStack_80;
  pAVar2 = (ASN1_TIME *)(*pcVar14)(iVar9,uStack_80,uVar7,uVar12);
  if (iStack_7c == *(int *)puVar1) {
    return pAVar2;
  }
  iVar9 = iStack_7c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if ((iVar9 != 0) && (iVar3 = (*(code *)PTR_EVP_PKEY_missing_parameters_006a8270)(), iVar3 == 0)) {
    return (ASN1_TIME *)0x1;
  }
  iVar3 = 0;
  do {
    iVar6 = (*(code *)PTR_sk_num_006a7f2c)(uVar10);
    if (iVar6 <= iVar3) {
      uVar12 = 0x6b;
      uVar7 = 0x717;
LAB_0057cf34:
      (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x6e,uVar12,"x509_vfy.c",uVar7);
      return (ASN1_TIME *)0x0;
    }
    pXVar4 = (X509 *)(*(code *)PTR_sk_value_006a7f24)(uVar10,iVar3);
    pEVar5 = X509_get_pubkey(pXVar4);
    if (pEVar5 == (EVP_PKEY *)0x0) {
      uVar12 = 0x6c;
      uVar7 = 0x70a;
      goto LAB_0057cf34;
    }
    iVar6 = (*(code *)PTR_EVP_PKEY_missing_parameters_006a8270)(pEVar5);
    if (iVar6 == 0) {
      iVar6 = iVar3 + -1;
      if (-1 < iVar3 + -1) {
        do {
          iVar3 = iVar6 + -1;
          pXVar4 = (X509 *)(*(code *)PTR_sk_value_006a7f24)(uVar10,iVar6);
          pEVar8 = X509_get_pubkey(pXVar4);
          (*(code *)PTR_EVP_PKEY_copy_parameters_006a8274)(pEVar8,pEVar5);
          (*(code *)PTR_EVP_PKEY_free_006a7f78)(pEVar8);
          iVar6 = iVar3;
        } while (iVar3 != -1);
      }
      if (iVar9 != 0) {
        (*(code *)PTR_EVP_PKEY_copy_parameters_006a8274)(iVar9,pEVar5);
      }
      (*(code *)PTR_EVP_PKEY_free_006a7f78)(pEVar5);
      return (ASN1_TIME *)0x1;
    }
    iVar3 = iVar3 + 1;
    (*(code *)PTR_EVP_PKEY_free_006a7f78)(pEVar5);
  } while( true );
}

