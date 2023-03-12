
ASN1_TIME * X509_time_adj_ex(ASN1_TIME *s,int offset_day,long offset_sec,time_t *t)

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
  time_t local_18;
  int local_14;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_14 = *(int *)PTR___stack_chk_guard_006aabf0;
  if (t == (time_t *)0x0) {
    (*(code *)PTR_time_006aabe4)(&local_18);
  }
  else {
    local_18 = *t;
  }
  pcVar12 = (code *)PTR_ASN1_TIME_adj_006aa00c;
  if ((((s == (ASN1_TIME *)0x0) || ((s->flags & 0x40U) != 0)) ||
      (pcVar12 = (code *)PTR_ASN1_UTCTIME_adj_006a9dc8, s->type == 0x17)) ||
     (pcVar12 = (code *)PTR_ASN1_TIME_adj_006aa00c,
     pcVar13 = (code *)PTR_ASN1_GENERALIZEDTIME_adj_006a9dcc, s->type != 0x18)) {
    pcVar13 = pcVar12;
  }
  tVar10 = local_18;
  pAVar2 = (ASN1_TIME *)(*pcVar13)(s,local_18,offset_day,offset_sec);
  if (local_14 == *(int *)puVar1) {
    return pAVar2;
  }
  iVar9 = local_14;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if ((iVar9 != 0) && (iVar3 = (*(code *)PTR_EVP_PKEY_missing_parameters_006a8270)(), iVar3 == 0)) {
    return (ASN1_TIME *)0x1;
  }
  iVar3 = 0;
  do {
    iVar6 = (*(code *)PTR_sk_num_006a7f2c)(tVar10);
    if (iVar6 <= iVar3) {
      uVar11 = 0x6b;
      uVar7 = 0x717;
LAB_0057cf34:
      (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x6e,uVar11,"x509_vfy.c",uVar7);
      return (ASN1_TIME *)0x0;
    }
    pXVar4 = (X509 *)(*(code *)PTR_sk_value_006a7f24)(tVar10,iVar3);
    pEVar5 = X509_get_pubkey(pXVar4);
    if (pEVar5 == (EVP_PKEY *)0x0) {
      uVar11 = 0x6c;
      uVar7 = 0x70a;
      goto LAB_0057cf34;
    }
    iVar6 = (*(code *)PTR_EVP_PKEY_missing_parameters_006a8270)(pEVar5);
    if (iVar6 == 0) {
      iVar6 = iVar3 + -1;
      if (-1 < iVar3 + -1) {
        do {
          iVar3 = iVar6 + -1;
          pXVar4 = (X509 *)(*(code *)PTR_sk_value_006a7f24)(tVar10,iVar6);
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

