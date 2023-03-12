
ASN1_GENERALIZEDTIME *
ASN1_GENERALIZEDTIME_adj(ASN1_GENERALIZEDTIME *s,time_t t,int offset_day,long offset_sec)

{
  undefined *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  ASN1_GENERALIZEDTIME *pAVar6;
  uchar *puVar7;
  time_t local_res4 [3];
  undefined auStack_48 [44];
  int local_1c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_1c = *(int *)PTR___stack_chk_guard_006aabf0;
  local_res4[0] = t;
  if ((s == (ASN1_GENERALIZEDTIME *)0x0) &&
     (s = ASN1_STRING_type_new(0x18), s == (ASN1_STRING *)0x0)) {
    s = (ASN1_GENERALIZEDTIME *)0x0;
  }
  else {
    t = (time_t)auStack_48;
    puVar2 = (undefined4 *)(*(code *)PTR_OPENSSL_gmtime_006a9dc0)(local_res4);
    if ((puVar2 == (undefined4 *)0x0) ||
       (((offset_day != 0 || (offset_sec != 0)) &&
        (iVar3 = (*(code *)PTR_OPENSSL_gmtime_adj_006a9dc4)(puVar2), t = offset_day, iVar3 == 0))))
    {
      s = (ASN1_GENERALIZEDTIME *)0x0;
    }
    else {
      puVar7 = s->data;
      if ((puVar7 == (uchar *)0x0) || ((uint)s->length < 0x14)) {
        puVar7 = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x14,"a_gentm.c",0xf3);
        if (puVar7 == (uchar *)0x0) {
          t = (time_t)&DAT_000000d8;
          ERR_put_error(0xd,0xd8,0x41,"a_gentm.c",0xf7);
          s = (ASN1_GENERALIZEDTIME *)0x0;
          goto LAB_0054d8e4;
        }
        if (s->data != (uchar *)0x0) {
          (*(code *)PTR_CRYPTO_free_006a7f88)();
        }
        s->data = puVar7;
      }
      t = (time_t)&DAT_00000014;
      (*(code *)PTR_BIO_snprintf_006a8060)
                (puVar7,0x14,"%04d%02d%02d%02d%02d%02dZ",puVar2[5] + 0x76c,puVar2[4] + 1,puVar2[3],
                 puVar2[2],puVar2[1],*puVar2);
      iVar3 = (*(code *)PTR_strlen_006aab30)(puVar7);
      s->length = iVar3;
      s->type = 0x18;
    }
  }
LAB_0054d8e4:
  if (local_1c == *(int *)puVar1) {
    return s;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  piVar4 = *(int **)PTR___stack_chk_guard_006aabf0;
  uVar5 = (uint)ASN1_TIME_it[0];
  if (ASN1_TIME_it._16_4_ == 0) {
    if (uVar5 < 7) {
                    /* WARNING: Could not recover jumptable at 0x00565630. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      pAVar6 = (ASN1_GENERALIZEDTIME *)(*(code *)(&switchD_00565630::switchdataD_0066abc0)[uVar5])()
      ;
      return pAVar6;
    }
  }
  else if (uVar5 < 7) {
                    /* WARNING: Could not recover jumptable at 0x005651a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pAVar6 = (ASN1_GENERALIZEDTIME *)(*(code *)(&switchD_005651a0::switchdataD_0066aba4)[uVar5])();
    return pAVar6;
  }
  if (piVar4 == *(int **)PTR___stack_chk_guard_006aabf0) {
    return (ASN1_GENERALIZEDTIME *)0x0;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  return *(ASN1_GENERALIZEDTIME **)(*piVar4 + *(int *)(t + 4));
}

