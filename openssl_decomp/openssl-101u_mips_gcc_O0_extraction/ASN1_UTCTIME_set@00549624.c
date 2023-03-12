
ASN1_UTCTIME * ASN1_UTCTIME_set(ASN1_UTCTIME *s,time_t t)

{
  bool bVar1;
  undefined *puVar2;
  undefined4 *puVar3;
  ASN1_UTCTIME *pAVar4;
  int iVar5;
  uchar *puVar6;
  time_t local_54;
  undefined auStack_50 [44];
  int local_24;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  local_24 = *(int *)PTR___stack_chk_guard_006a9ae8;
  local_54 = t;
  if (s == (ASN1_UTCTIME *)0x0) {
    s = ASN1_STRING_type_new(0x17);
    if (s != (ASN1_STRING *)0x0) goto LAB_00549830;
    goto LAB_005497dc;
  }
  puVar3 = (undefined4 *)(*(code *)PTR_OPENSSL_gmtime_006a8ca0)(&local_54,auStack_50);
  if (puVar3 == (undefined4 *)0x0) goto LAB_005497dc;
  iVar5 = puVar3[5];
  pAVar4 = (ASN1_UTCTIME *)0x0;
  if (99 < iVar5 - 0x32U) goto LAB_00549794;
  bVar1 = false;
  pAVar4 = s;
  do {
    puVar6 = pAVar4->data;
    s = pAVar4;
    if ((puVar6 == (uchar *)0x0) || ((uint)pAVar4->length < 0x14)) {
      puVar6 = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x14,"a_utctm.c",0xe1);
      if (puVar6 != (uchar *)0x0) {
        if (pAVar4->data != (uchar *)0x0) {
          (*(code *)PTR_CRYPTO_free_006a6e88)();
        }
        iVar5 = puVar3[5];
        pAVar4->data = puVar6;
        goto LAB_005496fc;
      }
      ERR_put_error(0xd,0xda,0x41,"a_utctm.c",0xe3);
      if (bVar1) goto LAB_00549810;
LAB_005497dc:
      pAVar4 = (ASN1_UTCTIME *)0x0;
    }
    else {
LAB_005496fc:
      (*(code *)PTR_BIO_snprintf_006a6f60)
                (puVar6,0x14,"%02d%02d%02d%02d%02d%02dZ",iVar5 % 100,puVar3[4] + 1,puVar3[3],
                 puVar3[2],puVar3[1],*puVar3);
      iVar5 = (*(code *)PTR_strlen_006a9a24)(puVar6);
      pAVar4->length = iVar5;
      pAVar4->type = 0x17;
    }
LAB_00549794:
    while( true ) {
      if (local_24 == *(int *)puVar2) {
        return pAVar4;
      }
      (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_00549830:
      puVar3 = (undefined4 *)(*(code *)PTR_OPENSSL_gmtime_006a8ca0)(&local_54,auStack_50);
      if ((puVar3 != (undefined4 *)0x0) && (iVar5 = puVar3[5], iVar5 - 0x32U < 100)) break;
LAB_00549810:
      ASN1_STRING_free(s);
      pAVar4 = (ASN1_UTCTIME *)0x0;
    }
    bVar1 = true;
    pAVar4 = s;
  } while( true );
}

