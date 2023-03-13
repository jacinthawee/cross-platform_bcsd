
ASN1_UTCTIME * ASN1_UTCTIME_adj(ASN1_UTCTIME *s,time_t t,int offset_day,long offset_sec)

{
  bool bVar1;
  undefined *puVar2;
  undefined4 *puVar3;
  ASN1_UTCTIME *pAVar4;
  int iVar5;
  time_t local_res4 [3];
  undefined auStack_50 [44];
  int local_24;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  local_24 = *(int *)PTR___stack_chk_guard_006a9ae8;
  local_res4[0] = t;
  if (s == (ASN1_UTCTIME *)0x0) {
    s = ASN1_STRING_type_new(0x17);
    if (s != (ASN1_STRING *)0x0) goto LAB_00549ab0;
  }
  else {
    puVar3 = (undefined4 *)(*(code *)PTR_OPENSSL_gmtime_006a8ca0)(local_res4,auStack_50);
    if (puVar3 != (undefined4 *)0x0) {
      bVar1 = false;
      if (offset_day != 0) goto LAB_005499f8;
      goto LAB_005498d8;
    }
  }
  pAVar4 = (ASN1_UTCTIME *)0x0;
  do {
    if (local_24 == *(int *)puVar2) {
      return pAVar4;
    }
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_00549ab0:
    puVar3 = (undefined4 *)(*(code *)PTR_OPENSSL_gmtime_006a8ca0)(local_res4,auStack_50);
    if (puVar3 == (undefined4 *)0x0) goto LAB_00549a18;
    bVar1 = true;
    if ((uchar *)offset_day != (uchar *)0x0) {
LAB_005499f8:
      iVar5 = (*(code *)PTR_OPENSSL_gmtime_adj_006a8ca4)(puVar3,offset_day,offset_sec);
      pAVar4 = s;
      if (iVar5 != 0) goto LAB_005498e0;
      goto LAB_00549a10;
    }
LAB_005498d8:
    pAVar4 = s;
    if ((char *)offset_sec != (char *)0x0) goto LAB_005499f8;
LAB_005498e0:
    iVar5 = puVar3[5];
    s = pAVar4;
    if (iVar5 - 0x32U < 100) {
      offset_day = (int)pAVar4->data;
      if (((uchar *)offset_day == (uchar *)0x0) || ((uint)pAVar4->length < 0x14)) {
        offset_sec = 0x670000;
        offset_day = (*(code *)PTR_CRYPTO_malloc_006a7008)(0x14,"a_utctm.c",0xe1);
        if ((uchar *)offset_day == (uchar *)0x0) {
          ERR_put_error(0xd,0xda,0x41,"a_utctm.c",0xe3);
          goto LAB_00549a10;
        }
        if (pAVar4->data != (uchar *)0x0) {
          (*(code *)PTR_CRYPTO_free_006a6e88)();
        }
        iVar5 = puVar3[5];
        pAVar4->data = (uchar *)offset_day;
      }
      (*(code *)PTR_BIO_snprintf_006a6f60)
                (offset_day,0x14,"%02d%02d%02d%02d%02d%02dZ",iVar5 % 100,puVar3[4] + 1,puVar3[3],
                 puVar3[2],puVar3[1],*puVar3);
      iVar5 = (*(code *)PTR_strlen_006a9a24)(offset_day);
      pAVar4->length = iVar5;
      pAVar4->type = 0x17;
    }
    else {
LAB_00549a10:
      pAVar4 = (ASN1_UTCTIME *)0x0;
      if (bVar1) {
LAB_00549a18:
        ASN1_STRING_free(s);
        pAVar4 = (ASN1_UTCTIME *)0x0;
      }
    }
  } while( true );
}

