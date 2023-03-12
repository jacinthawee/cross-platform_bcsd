
ASN1_OBJECT * c2i_ASN1_OBJECT(ASN1_OBJECT **a,uchar **pp,long length)

{
  bool bVar1;
  uchar *puVar2;
  int iVar3;
  int in_r3;
  uchar *puVar4;
  ASN1_OBJECT *ptr;
  uchar *puVar5;
  bool bVar6;
  bool bVar7;
  
  bVar6 = (int)pp < 0;
  bVar7 = pp == (uchar **)0x0;
  if (!bVar7) {
    bVar6 = length < 0;
  }
  bVar1 = length == 0;
  if ((bVar7 || bVar1) || bVar6) {
    in_r3 = 1;
  }
  if ((!bVar7 && !bVar1) && !bVar6) {
    in_r3 = 0;
  }
  if ((((bVar7 || bVar1) || bVar6) || (puVar2 = *pp, puVar2 == (uchar *)0x0)) ||
     (puVar5 = puVar2 + length, (char)puVar5[-1] < '\0')) {
    iVar3 = 0x11f;
LAB_000b001a:
    ERR_put_error(0xd,0xc4,0xd8,"a_object.c",iVar3);
    return (ASN1_OBJECT *)0x0;
  }
  puVar4 = puVar2 + -1;
  do {
    if ((puVar4[1] == 0x80) && ((in_r3 == 0 || (-1 < (char)*puVar4)))) {
      iVar3 = 0x126;
      goto LAB_000b001a;
    }
    in_r3 = in_r3 + 1;
    puVar4 = puVar4 + 1;
  } while (in_r3 < length);
  if (((a == (ASN1_OBJECT **)0x0) || (ptr = *a, ptr == (ASN1_OBJECT *)0x0)) ||
     (-1 < ptr->flags << 0x1f)) {
    ptr = (ASN1_OBJECT *)CRYPTO_malloc(0x18,"a_object.c",0x15e);
    if (ptr == (ASN1_OBJECT *)0x0) {
      ERR_put_error(0xd,0x7b,0x41,"a_object.c",0x160);
      return (ASN1_OBJECT *)0x0;
    }
    ptr->data = (uchar *)0x0;
    ptr->sn = (char *)0x0;
    ptr->ln = (char **)0x0;
    puVar2 = *pp;
    ptr->length = 0;
    ptr->nid = 0;
    ptr->flags = 1;
LAB_000b00da:
    ptr->length = 0;
LAB_000b0066:
    puVar4 = (uchar *)CRYPTO_malloc(length,"a_object.c",0x13f);
    if (puVar4 == (uchar *)0x0) {
      ERR_put_error(0xd,0xc4,0x41,"a_object.c",0x154);
      if ((a == (ASN1_OBJECT **)0x0) || (*a != ptr)) {
        iVar3 = ptr->flags;
        if (iVar3 << 0x1d < 0) {
          if (ptr->sn != (char *)0x0) {
            CRYPTO_free(ptr->sn);
          }
          if (ptr->ln != (char **)0x0) {
            CRYPTO_free(ptr->ln);
          }
          iVar3 = ptr->flags;
          ptr->ln = (char **)0x0;
          ptr->sn = (char *)0x0;
        }
        if (iVar3 << 0x1c < 0) {
          if (ptr->data != (uchar *)0x0) {
            CRYPTO_free(ptr->data);
            iVar3 = ptr->flags;
          }
          ptr->data = (uchar *)0x0;
          ptr->length = 0;
        }
        if (iVar3 << 0x1f < 0) {
          CRYPTO_free(ptr);
        }
      }
      return (ASN1_OBJECT *)0x0;
    }
    ptr->flags = ptr->flags | 8;
    memcpy(puVar4,puVar2,length);
    ptr->length = length;
    puVar5 = puVar2 + length;
    ptr->data = puVar4;
    ptr->sn = (char *)0x0;
    ptr->ln = (char **)0x0;
    if (a == (ASN1_OBJECT **)0x0) goto LAB_000b00a6;
  }
  else {
    puVar4 = ptr->data;
    ptr->data = (uchar *)0x0;
    if (puVar4 == (uchar *)0x0) goto LAB_000b00da;
    if (ptr->length < length) {
      ptr->length = 0;
      CRYPTO_free(puVar4);
      goto LAB_000b0066;
    }
    puVar2 = (uchar *)memcpy(puVar4,puVar2,length);
    ptr->length = length;
    ptr->sn = (char *)0x0;
    ptr->ln = (char **)0x0;
    ptr->data = puVar2;
  }
  *a = ptr;
LAB_000b00a6:
  *pp = puVar5;
  return ptr;
}

