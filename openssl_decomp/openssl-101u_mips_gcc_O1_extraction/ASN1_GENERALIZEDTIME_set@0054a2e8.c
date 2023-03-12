
ASN1_GENERALIZEDTIME * ASN1_GENERALIZEDTIME_set(ASN1_GENERALIZEDTIME *s,time_t t)

{
  undefined *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  uint uVar5;
  ASN1_GENERALIZEDTIME *pAVar6;
  char *in_a2;
  char *in_a3;
  int unaff_s1;
  uchar *unaff_s2;
  uchar *puVar7;
  char *unaff_s4;
  char acStack_c8 [44];
  int iStack_9c;
  ASN1_GENERALIZEDTIME *pAStack_98;
  int iStack_94;
  uchar *puStack_90;
  undefined *puStack_8c;
  char *pcStack_88;
  code *pcStack_84;
  char *apcStack_7c [3];
  time_t local_4c;
  char acStack_48 [44];
  ASN1_GENERALIZEDTIME *local_1c;
  
  puStack_8c = PTR___stack_chk_guard_006a9ae8;
  local_1c = *(ASN1_GENERALIZEDTIME **)PTR___stack_chk_guard_006a9ae8;
  local_4c = t;
  if ((s == (ASN1_GENERALIZEDTIME *)0x0) &&
     (s = ASN1_STRING_type_new(0x18), s == (ASN1_STRING *)0x0)) {
    pAVar6 = (ASN1_GENERALIZEDTIME *)0x0;
  }
  else {
    t = (time_t)acStack_48;
    unaff_s1 = (*(code *)PTR_OPENSSL_gmtime_006a8ca0)(&local_4c);
    if (unaff_s1 == 0) {
LAB_0054a460:
      pAVar6 = (ASN1_GENERALIZEDTIME *)0x0;
    }
    else {
      unaff_s2 = s->data;
      unaff_s4 = "encrypt";
      if ((unaff_s2 == (uchar *)0x0) || ((uint)s->length < 0x14)) {
        unaff_s2 = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x14,"a_gentm.c",0xfb);
        if (unaff_s2 == (uchar *)0x0) {
          in_a3 = "a_gentm.c";
          in_a2 = &DAT_00000041;
          t = (time_t)&DAT_000000d8;
          ERR_put_error(0xd,0xd8,0x41,"a_gentm.c",0xfd);
          goto LAB_0054a460;
        }
        if (s->data != (uchar *)0x0) {
          (*(code *)PTR_CRYPTO_free_006a6e88)();
        }
        s->data = unaff_s2;
      }
      t = (time_t)&DAT_00000014;
      in_a2 = "%04d%02d%02d%02d%02d%02dZ";
      in_a3 = (char *)(*(int *)(unaff_s1 + 0x14) + 0x76c);
      (*(code *)PTR_BIO_snprintf_006a6f60)(unaff_s2);
      iVar2 = (*(code *)PTR_strlen_006a9a24)(unaff_s2);
      s->length = iVar2;
      s->type = 0x18;
      pAVar6 = s;
    }
  }
  if (local_1c == *(ASN1_GENERALIZEDTIME **)puStack_8c) {
    return pAVar6;
  }
  pcStack_84 = ASN1_GENERALIZEDTIME_adj;
  pAVar6 = local_1c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iStack_9c = *(int *)PTR___stack_chk_guard_006a9ae8;
  pAStack_98 = s;
  iStack_94 = unaff_s1;
  puStack_90 = unaff_s2;
  pcStack_88 = unaff_s4;
  apcStack_7c[0] = (char *)t;
  if ((pAVar6 == (ASN1_GENERALIZEDTIME *)0x0) &&
     (pAVar6 = ASN1_STRING_type_new(0x18), pAVar6 == (ASN1_STRING *)0x0)) {
    pAVar6 = (ASN1_GENERALIZEDTIME *)0x0;
  }
  else {
    t = (time_t)acStack_c8;
    puVar3 = (undefined4 *)(*(code *)PTR_OPENSSL_gmtime_006a8ca0)(apcStack_7c);
    if ((puVar3 == (undefined4 *)0x0) ||
       (((in_a2 != (char *)0x0 || (in_a3 != (char *)0x0)) &&
        (iVar2 = (*(code *)PTR_OPENSSL_gmtime_adj_006a8ca4)(puVar3), t = (time_t)in_a2, iVar2 == 0))
       )) {
      pAVar6 = (ASN1_GENERALIZEDTIME *)0x0;
    }
    else {
      puVar7 = pAVar6->data;
      if ((puVar7 == (uchar *)0x0) || ((uint)pAVar6->length < 0x14)) {
        puVar7 = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x14,"a_gentm.c",0xfb);
        if (puVar7 == (uchar *)0x0) {
          t = (time_t)&DAT_000000d8;
          ERR_put_error(0xd,0xd8,0x41,"a_gentm.c",0xfd);
          pAVar6 = (ASN1_GENERALIZEDTIME *)0x0;
          goto LAB_0054a5d4;
        }
        if (pAVar6->data != (uchar *)0x0) {
          (*(code *)PTR_CRYPTO_free_006a6e88)();
        }
        pAVar6->data = puVar7;
      }
      t = (time_t)&DAT_00000014;
      (*(code *)PTR_BIO_snprintf_006a6f60)
                (puVar7,0x14,"%04d%02d%02d%02d%02d%02dZ",puVar3[5] + 0x76c,puVar3[4] + 1,puVar3[3],
                 puVar3[2],puVar3[1],*puVar3);
      iVar2 = (*(code *)PTR_strlen_006a9a24)(puVar7);
      pAVar6->length = iVar2;
      pAVar6->type = 0x18;
    }
  }
LAB_0054a5d4:
  if (iStack_9c == *(int *)puVar1) {
    return pAVar6;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  piVar4 = *(int **)PTR___stack_chk_guard_006a9ae8;
  uVar5 = (uint)ASN1_TIME_it[0];
  if (ASN1_TIME_it._16_4_ == 0) {
    if (uVar5 < 7) {
                    /* WARNING: Could not recover jumptable at 0x005619f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      pAVar6 = (ASN1_GENERALIZEDTIME *)(*(code *)(&switchD_005619f8::switchdataD_0066a17c)[uVar5])()
      ;
      return pAVar6;
    }
  }
  else if (uVar5 < 7) {
                    /* WARNING: Could not recover jumptable at 0x00561550. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pAVar6 = (ASN1_GENERALIZEDTIME *)(*(code *)(&switchD_00561550::switchdataD_0066a160)[uVar5])();
    return pAVar6;
  }
  if (piVar4 == *(int **)PTR___stack_chk_guard_006a9ae8) {
    return (ASN1_GENERALIZEDTIME *)0x0;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  return *(ASN1_GENERALIZEDTIME **)(*piVar4 + *(int *)(t + 4));
}

