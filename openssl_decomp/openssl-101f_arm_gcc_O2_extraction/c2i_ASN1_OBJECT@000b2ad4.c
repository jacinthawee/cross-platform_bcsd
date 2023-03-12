
ASN1_OBJECT * c2i_ASN1_OBJECT(ASN1_OBJECT **a,uchar **pp,long length)

{
  uchar *puVar1;
  int iVar2;
  ASN1_OBJECT *ptr;
  uchar *puVar3;
  
  puVar3 = *pp;
  if (0 < length) {
    iVar2 = 0;
    puVar1 = puVar3 + -1;
    do {
      if ((puVar1[1] == 0x80) && ((iVar2 == 0 || (-1 < (char)*puVar1)))) {
        ERR_put_error(0xd,0xc4,0xd8,"a_object.c",300);
        return (ASN1_OBJECT *)0x0;
      }
      iVar2 = iVar2 + 1;
      puVar1 = puVar1 + 1;
    } while (iVar2 != length);
  }
  if (((a == (ASN1_OBJECT **)0x0) || (ptr = *a, ptr == (ASN1_OBJECT *)0x0)) ||
     (-1 < ptr->flags << 0x1f)) {
    ptr = (ASN1_OBJECT *)CRYPTO_malloc(0x18,"a_object.c",0x15f);
    if (ptr == (ASN1_OBJECT *)0x0) {
      ERR_put_error(0xd,0x7b,0x41,"a_object.c",0x162);
      return (ASN1_OBJECT *)0x0;
    }
    ptr->data = (uchar *)0x0;
    ptr->sn = (char *)0x0;
    ptr->ln = (char **)0x0;
    puVar3 = *pp;
    ptr->length = 0;
    ptr->nid = 0;
    ptr->flags = 1;
LAB_000b2b38:
    ptr->length = 0;
LAB_000b2b3c:
    iVar2 = length;
    if (length == 0) {
      iVar2 = 1;
    }
    puVar1 = (uchar *)CRYPTO_malloc(iVar2,"a_object.c",0x143);
    if (puVar1 == (uchar *)0x0) {
      ERR_put_error(0xd,0xc4,0x41,"a_object.c",0x155);
      if ((a == (ASN1_OBJECT **)0x0) || (*a != ptr)) {
        iVar2 = ptr->flags;
        if (iVar2 << 0x1d < 0) {
          if (ptr->sn != (char *)0x0) {
            CRYPTO_free(ptr->sn);
          }
          if (ptr->ln != (char **)0x0) {
            CRYPTO_free(ptr->ln);
          }
          iVar2 = ptr->flags;
          ptr->ln = (char **)0x0;
          ptr->sn = (char *)0x0;
        }
        if (iVar2 << 0x1c < 0) {
          if (ptr->data != (uchar *)0x0) {
            CRYPTO_free(ptr->data);
            iVar2 = ptr->flags;
          }
          ptr->data = (uchar *)0x0;
          ptr->length = 0;
        }
        if (iVar2 << 0x1f < 0) {
          CRYPTO_free(ptr);
        }
      }
      return (ASN1_OBJECT *)0x0;
    }
    ptr->flags = ptr->flags | 8;
    memcpy(puVar1,puVar3,length);
    ptr->length = length;
    puVar3 = puVar3 + length;
    ptr->data = puVar1;
    ptr->sn = (char *)0x0;
    ptr->ln = (char **)0x0;
    if (a == (ASN1_OBJECT **)0x0) goto LAB_000b2b82;
  }
  else {
    puVar1 = ptr->data;
    ptr->data = (uchar *)0x0;
    if (puVar1 == (uchar *)0x0) goto LAB_000b2b38;
    if (ptr->length < length) {
      ptr->length = 0;
      CRYPTO_free(puVar1);
      goto LAB_000b2b3c;
    }
    puVar1 = (uchar *)memcpy(puVar1,puVar3,length);
    ptr->length = length;
    ptr->sn = (char *)0x0;
    puVar3 = puVar3 + length;
    ptr->ln = (char **)0x0;
    ptr->data = puVar1;
  }
  *a = ptr;
LAB_000b2b82:
  *pp = puVar3;
  return ptr;
}

