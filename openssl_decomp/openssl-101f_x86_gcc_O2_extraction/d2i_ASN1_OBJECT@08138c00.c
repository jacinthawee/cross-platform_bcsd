
ASN1_OBJECT * d2i_ASN1_OBJECT(ASN1_OBJECT **a,uchar **pp,long length)

{
  uint uVar1;
  size_t sVar2;
  uchar *puVar3;
  ASN1_OBJECT *a_00;
  int reason;
  uchar *puVar4;
  int in_GS_OFFSET;
  uchar *local_30;
  size_t local_2c;
  int local_28;
  int local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_30 = *pp;
  uVar1 = ASN1_get_object(&local_30,(long *)&local_2c,&local_28,&local_24,length);
  puVar4 = local_30;
  if ((uVar1 & 0x80) == 0) {
    if (local_28 != 6) {
      reason = 0x74;
      goto LAB_08138d8d;
    }
    if (0 < (int)local_2c) {
      sVar2 = 0;
      do {
        if ((local_30[sVar2] == 0x80) && ((sVar2 == 0 || (-1 < (char)local_30[sVar2 - 1])))) {
          ERR_put_error(0xd,0xc4,0xd8,"a_object.c",300);
          goto LAB_08138d69;
        }
        sVar2 = sVar2 + 1;
      } while (local_2c != sVar2);
    }
    if (((a != (ASN1_OBJECT **)0x0) && (a_00 = *a, a_00 != (ASN1_OBJECT *)0x0)) &&
       ((*(byte *)&a_00->flags & 1) != 0)) {
      puVar3 = a_00->data;
      a_00->data = (uchar *)0x0;
      if (puVar3 == (uchar *)0x0) goto LAB_08138dfe;
      if (a_00->length < (int)local_2c) {
        a_00->length = 0;
        CRYPTO_free(puVar3);
        goto LAB_08138cc6;
      }
      memcpy(puVar3,local_30,local_2c);
      a_00->length = local_2c;
      a_00->sn = (char *)0x0;
      a_00->ln = (char **)0x0;
      a_00->data = puVar3;
      puVar4 = puVar4 + local_2c;
LAB_08138d31:
      *a = a_00;
LAB_08138d33:
      *pp = puVar4;
      goto LAB_08138d6b;
    }
    a_00 = (ASN1_OBJECT *)CRYPTO_malloc(0x18,"a_object.c",0x15f);
    if (a_00 == (ASN1_OBJECT *)0x0) {
      ERR_put_error(0xd,0x7b,0x41,"a_object.c",0x162);
      a_00 = (ASN1_OBJECT *)0x0;
      goto LAB_08138d6b;
    }
    a_00->length = 0;
    a_00->data = (uchar *)0x0;
    a_00->nid = 0;
    a_00->sn = (char *)0x0;
    a_00->ln = (char **)0x0;
    a_00->flags = 1;
LAB_08138dfe:
    a_00->length = 0;
    puVar4 = local_30;
LAB_08138cc6:
    sVar2 = 1;
    if (local_2c != 0) {
      sVar2 = local_2c;
    }
    puVar3 = (uchar *)CRYPTO_malloc(sVar2,"a_object.c",0x143);
    if (puVar3 != (uchar *)0x0) {
      a_00->flags = a_00->flags | 8;
      memcpy(puVar3,puVar4,local_2c);
      a_00->length = local_2c;
      a_00->sn = (char *)0x0;
      a_00->ln = (char **)0x0;
      puVar4 = puVar4 + local_2c;
      a_00->data = puVar3;
      if (a != (ASN1_OBJECT **)0x0) goto LAB_08138d31;
      goto LAB_08138d33;
    }
    ERR_put_error(0xd,0xc4,0x41,"a_object.c",0x155);
    if ((a == (ASN1_OBJECT **)0x0) || (*a != a_00)) {
      ASN1_OBJECT_free(a_00);
    }
  }
  else {
    reason = 0x66;
LAB_08138d8d:
    ERR_put_error(0xd,0x93,reason,"a_object.c",0x11b);
  }
LAB_08138d69:
  a_00 = (ASN1_OBJECT *)0x0;
LAB_08138d6b:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return a_00;
}

