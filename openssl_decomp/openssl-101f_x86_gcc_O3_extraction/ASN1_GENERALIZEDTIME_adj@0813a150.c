
ASN1_GENERALIZEDTIME *
ASN1_GENERALIZEDTIME_adj(ASN1_GENERALIZEDTIME *s,time_t t,int offset_day,long offset_sec)

{
  long lVar1;
  undefined4 *puVar2;
  uchar *buf;
  size_t sVar3;
  int iVar4;
  int in_GS_OFFSET;
  undefined local_4c [44];
  int local_20;
  
  lVar1 = offset_sec;
  iVar4 = offset_day;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (s == (ASN1_GENERALIZEDTIME *)0x0) {
    s = ASN1_STRING_type_new(0x18);
    if (s == (ASN1_STRING *)0x0) {
      s = (ASN1_GENERALIZEDTIME *)0x0;
      goto LAB_0813a22b;
    }
  }
  puVar2 = (undefined4 *)OPENSSL_gmtime(&t,local_4c);
  if (puVar2 == (undefined4 *)0x0) {
LAB_0813a256:
    s = (ASN1_GENERALIZEDTIME *)0x0;
  }
  else {
    if ((iVar4 != 0) || (lVar1 != 0)) {
      iVar4 = OPENSSL_gmtime_adj(puVar2,iVar4,lVar1);
      if (iVar4 == 0) goto LAB_0813a256;
    }
    buf = s->data;
    if ((buf == (uchar *)0x0) || ((uint)s->length < 0x14)) {
      buf = (uchar *)CRYPTO_malloc(0x14,"a_gentm.c",0xf3);
      if (buf == (uchar *)0x0) {
        ERR_put_error(0xd,0xd8,0x41,"a_gentm.c",0xf7);
        s = (ASN1_GENERALIZEDTIME *)0x0;
        goto LAB_0813a22b;
      }
      if (s->data != (uchar *)0x0) {
        CRYPTO_free(s->data);
      }
      s->data = buf;
    }
    BIO_snprintf((char *)buf,0x14,"%04d%02d%02d%02d%02d%02dZ",puVar2[5] + 0x76c,puVar2[4] + 1,
                 puVar2[3],puVar2[2],puVar2[1],*puVar2);
    sVar3 = strlen((char *)buf);
    s->length = sVar3;
    s->type = 0x18;
  }
LAB_0813a22b:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return s;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

