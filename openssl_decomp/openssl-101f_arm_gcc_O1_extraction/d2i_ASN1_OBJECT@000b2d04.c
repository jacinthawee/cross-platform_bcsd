
ASN1_OBJECT * d2i_ASN1_OBJECT(ASN1_OBJECT **a,uchar **pp,long length)

{
  uint uVar1;
  size_t num;
  int reason;
  uchar *puVar2;
  ASN1_OBJECT *a_00;
  uchar *puVar3;
  uchar *local_30;
  size_t local_2c;
  int local_28;
  int aiStack_24 [2];
  
  local_30 = *pp;
  uVar1 = ASN1_get_object(&local_30,(long *)&local_2c,&local_28,aiStack_24,length);
  puVar3 = local_30;
  uVar1 = uVar1 & 0x80;
  if (uVar1 != 0) {
    reason = 0x66;
LAB_000b2df2:
    ERR_put_error(0xd,0x93,reason,"a_object.c",0x11b);
    return (ASN1_OBJECT *)0x0;
  }
  if (local_28 != 6) {
    reason = 0x74;
    goto LAB_000b2df2;
  }
  if (0 < (int)local_2c) {
    puVar2 = local_30 + -1;
    do {
      if ((puVar2[1] == 0x80) && ((uVar1 == 0 || (-1 < (char)*puVar2)))) {
        ERR_put_error(0xd,0xc4,0xd8,"a_object.c",300);
        goto LAB_000b2de8;
      }
      uVar1 = uVar1 + 1;
      puVar2 = puVar2 + 1;
    } while (uVar1 != local_2c);
  }
  if (((a == (ASN1_OBJECT **)0x0) || (a_00 = *a, a_00 == (ASN1_OBJECT *)0x0)) ||
     (-1 < a_00->flags << 0x1f)) {
    a_00 = (ASN1_OBJECT *)CRYPTO_malloc(0x18,"a_object.c",0x15f);
    if (a_00 != (ASN1_OBJECT *)0x0) {
      a_00->length = 0;
      a_00->nid = 0;
      a_00->sn = (char *)0x0;
      a_00->ln = (char **)0x0;
      a_00->data = (uchar *)0x0;
      a_00->flags = 1;
      goto LAB_000b2e38;
    }
    ERR_put_error(0xd,0x7b,0x41,"a_object.c",0x162);
LAB_000b2de8:
    a_00 = (ASN1_OBJECT *)0x0;
  }
  else {
    puVar2 = a_00->data;
    a_00->data = (uchar *)0x0;
    if (puVar2 == (uchar *)0x0) {
LAB_000b2e38:
      a_00->length = 0;
      puVar3 = local_30;
LAB_000b2d80:
      num = local_2c;
      if (local_2c == 0) {
        num = 1;
      }
      puVar2 = (uchar *)CRYPTO_malloc(num,"a_object.c",0x143);
      if (puVar2 == (uchar *)0x0) {
        ERR_put_error(0xd,0xc4,0x41,"a_object.c",0x155);
        if ((a == (ASN1_OBJECT **)0x0) || (a_00 != *a)) {
          ASN1_OBJECT_free(a_00);
        }
        goto LAB_000b2de8;
      }
      a_00->flags = a_00->flags | 8;
      memcpy(puVar2,puVar3,local_2c);
      a_00->length = local_2c;
      puVar3 = puVar3 + local_2c;
      a_00->data = puVar2;
      a_00->sn = (char *)0x0;
      a_00->ln = (char **)0x0;
      if (a != (ASN1_OBJECT **)0x0) goto LAB_000b2dc2;
    }
    else {
      if (a_00->length < (int)local_2c) {
        a_00->length = 0;
        CRYPTO_free(puVar2);
        goto LAB_000b2d80;
      }
      puVar2 = (uchar *)memcpy(puVar2,local_30,local_2c);
      a_00->length = local_2c;
      a_00->sn = (char *)0x0;
      puVar3 = puVar3 + local_2c;
      a_00->ln = (char **)0x0;
      a_00->data = puVar2;
LAB_000b2dc2:
      *a = a_00;
    }
    *pp = puVar3;
  }
  return a_00;
}

