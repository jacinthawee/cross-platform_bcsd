
ASN1_TIME * X509_time_adj(ASN1_TIME *s,long adj,time_t *t)

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
  time_t tVar10;
  undefined4 uVar11;
  code *pcVar12;
  code *pcVar13;
  undefined4 uStack_50;
  int iStack_4c;
  ASN1_TIME *pAStack_44;
  undefined *puStack_40;
  code *pcStack_3c;
  undefined *local_28;
  undefined4 *local_1c;
  time_t local_18;
  int local_14;
  
  puStack_40 = PTR___stack_chk_guard_006a9ae8;
  local_28 = &_gp;
  local_14 = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (t == (time_t *)0x0) {
    local_1c = (undefined4 *)adj;
    (*(code *)PTR_time_006a9adc)(&local_18);
    adj = (long)local_1c;
  }
  else {
    local_18 = *t;
  }
  pcVar12 = *(code **)(local_28 + -0x5ef0);
  if (s == (ASN1_TIME *)0x0) goto LAB_00579b20;
  if ((s->flags & 0x40U) == 0) {
    if (s->type == 0x17) {
      pcVar12 = *(code **)(local_28 + -0x6138);
      goto LAB_00579b20;
    }
    pcVar12 = *(code **)(local_28 + -0x6134);
    if (s->type == 0x18) goto LAB_00579b20;
  }
  pcVar12 = *(code **)(local_28 + -0x5ef0);
LAB_00579b20:
  uVar7 = 0;
  tVar10 = local_18;
  pAVar2 = (ASN1_TIME *)(*pcVar12)(s);
  if (local_14 == *(int *)puStack_40) {
    return pAVar2;
  }
  pcStack_3c = X509_time_adj_ex;
  iVar9 = local_14;
  (**(code **)(local_28 + -0x5330))();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iStack_4c = *(int *)PTR___stack_chk_guard_006a9ae8;
  pAStack_44 = s;
  if ((undefined4 *)adj == (undefined4 *)0x0) {
    (*(code *)PTR_time_006a9adc)(&uStack_50);
  }
  else {
    uStack_50 = *(undefined4 *)adj;
  }
  pcVar12 = (code *)PTR_ASN1_TIME_adj_006a8ef0;
  if ((((iVar9 == 0) || ((*(uint *)(iVar9 + 0xc) & 0x40) != 0)) ||
      (pcVar12 = (code *)PTR_ASN1_UTCTIME_adj_006a8ca8, *(int *)(iVar9 + 4) == 0x17)) ||
     (pcVar12 = (code *)PTR_ASN1_TIME_adj_006a8ef0,
     pcVar13 = (code *)PTR_ASN1_GENERALIZEDTIME_adj_006a8cac, *(int *)(iVar9 + 4) != 0x18)) {
    pcVar13 = pcVar12;
  }
  uVar11 = uStack_50;
  pAVar2 = (ASN1_TIME *)(*pcVar13)(iVar9,uStack_50,tVar10,uVar7);
  if (iStack_4c == *(int *)puVar1) {
    return pAVar2;
  }
  iVar9 = iStack_4c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if ((iVar9 != 0) && (iVar3 = (*(code *)PTR_EVP_PKEY_missing_parameters_006a7170)(), iVar3 == 0)) {
    return (ASN1_TIME *)0x1;
  }
  iVar3 = 0;
  do {
    iVar6 = (*(code *)PTR_sk_num_006a6e2c)(uVar11);
    if (iVar6 <= iVar3) {
      uVar11 = 0x6b;
      uVar7 = 0x78a;
LAB_00579d60:
      (*(code *)PTR_ERR_put_error_006a7f34)(0xb,0x6e,uVar11,"x509_vfy.c",uVar7);
      return (ASN1_TIME *)0x0;
    }
    pXVar4 = (X509 *)(*(code *)PTR_sk_value_006a6e24)(uVar11,iVar3);
    pEVar5 = X509_get_pubkey(pXVar4);
    if (pEVar5 == (EVP_PKEY *)0x0) {
      uVar11 = 0x6c;
      uVar7 = 0x77e;
      goto LAB_00579d60;
    }
    iVar6 = (*(code *)PTR_EVP_PKEY_missing_parameters_006a7170)(pEVar5);
    if (iVar6 == 0) {
      iVar6 = iVar3 + -1;
      if (-1 < iVar3 + -1) {
        do {
          iVar3 = iVar6 + -1;
          pXVar4 = (X509 *)(*(code *)PTR_sk_value_006a6e24)(uVar11,iVar6);
          pEVar8 = X509_get_pubkey(pXVar4);
          (*(code *)PTR_EVP_PKEY_copy_parameters_006a7174)(pEVar8,pEVar5);
          (*(code *)PTR_EVP_PKEY_free_006a6e78)(pEVar8);
          iVar6 = iVar3;
        } while (iVar3 != -1);
      }
      if (iVar9 != 0) {
        (*(code *)PTR_EVP_PKEY_copy_parameters_006a7174)(iVar9,pEVar5);
      }
      (*(code *)PTR_EVP_PKEY_free_006a6e78)(pEVar5);
      return (ASN1_TIME *)0x1;
    }
    iVar3 = iVar3 + 1;
    (*(code *)PTR_EVP_PKEY_free_006a6e78)(pEVar5);
  } while( true );
}

