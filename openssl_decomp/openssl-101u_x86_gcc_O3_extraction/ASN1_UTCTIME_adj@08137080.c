
ASN1_UTCTIME * ASN1_UTCTIME_adj(ASN1_UTCTIME *s,time_t t,int offset_day,long offset_sec)

{
  bool bVar1;
  undefined4 *puVar2;
  uchar *buf;
  size_t sVar3;
  int iVar4;
  int in_GS_OFFSET;
  undefined local_4c [44];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (s == (ASN1_UTCTIME *)0x0) {
    s = ASN1_STRING_type_new(0x17);
    if (s != (ASN1_STRING *)0x0) {
      puVar2 = (undefined4 *)OPENSSL_gmtime(&t,local_4c,s,s);
      if (puVar2 != (undefined4 *)0x0) {
        bVar1 = true;
        goto LAB_081370c0;
      }
LAB_081371c0:
      ASN1_STRING_free(s);
    }
  }
  else {
    puVar2 = (undefined4 *)OPENSSL_gmtime(&t,local_4c);
    if (puVar2 != (undefined4 *)0x0) {
      bVar1 = false;
LAB_081370c0:
      if ((((offset_day == 0) && (offset_sec == 0)) ||
          (iVar4 = OPENSSL_gmtime_adj(puVar2,offset_day,offset_sec), iVar4 != 0)) &&
         (iVar4 = puVar2[5], iVar4 - 0x32U < 100)) {
        buf = s->data;
        if ((buf == (uchar *)0x0) || ((uint)s->length < 0x14)) {
          buf = (uchar *)CRYPTO_malloc(0x14,"a_utctm.c",0xe1);
          if (buf == (uchar *)0x0) {
            ERR_put_error(0xd,0xda,0x41,"a_utctm.c",0xe3);
            goto LAB_081371a0;
          }
          if (s->data != (uchar *)0x0) {
            CRYPTO_free(s->data);
          }
          iVar4 = puVar2[5];
          s->data = buf;
        }
        BIO_snprintf((char *)buf,0x14,"%02d%02d%02d%02d%02d%02dZ",iVar4 % 100,puVar2[4] + 1,
                     puVar2[3],puVar2[2],puVar2[1],*puVar2);
        sVar3 = strlen((char *)buf);
        s->length = sVar3;
        s->type = 0x17;
        goto LAB_081371a8;
      }
LAB_081371a0:
      if (bVar1) goto LAB_081371c0;
    }
  }
  s = (ASN1_UTCTIME *)0x0;
LAB_081371a8:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return s;
}
