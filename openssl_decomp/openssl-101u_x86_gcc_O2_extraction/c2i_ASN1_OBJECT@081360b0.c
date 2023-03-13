
ASN1_OBJECT * c2i_ASN1_OBJECT(ASN1_OBJECT **a,uchar **pp,long length)

{
  int iVar1;
  uchar *puVar2;
  ASN1_OBJECT *ptr;
  uint uVar3;
  uchar *puVar4;
  uchar *__src;
  
  if ((((length < 1) || (pp == (uchar **)0x0)) || (__src = *pp, __src == (uchar *)0x0)) ||
     (iVar1 = 0, (char)__src[length + -1] < '\0')) {
    iVar1 = 0x11f;
LAB_08136110:
    ERR_put_error(0xd,0xc4,0xd8,"a_object.c",iVar1);
    return (ASN1_OBJECT *)0x0;
  }
  do {
    if ((__src[iVar1] == 0x80) && ((iVar1 == 0 || (-1 < (char)__src[iVar1 + -1])))) {
      iVar1 = 0x126;
      goto LAB_08136110;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < length);
  if (((a == (ASN1_OBJECT **)0x0) || (ptr = *a, ptr == (ASN1_OBJECT *)0x0)) ||
     ((*(byte *)&ptr->flags & 1) == 0)) {
    ptr = (ASN1_OBJECT *)CRYPTO_malloc(0x18,"a_object.c",0x15e);
    if (ptr == (ASN1_OBJECT *)0x0) {
      ERR_put_error(0xd,0x7b,0x41,"a_object.c",0x160);
      return (ASN1_OBJECT *)0x0;
    }
    ptr->data = (uchar *)0x0;
    ptr->sn = (char *)0x0;
    ptr->ln = (char **)0x0;
    __src = *pp;
    ptr->length = 0;
    ptr->nid = 0;
    ptr->flags = 1;
LAB_0813623c:
    ptr->length = 0;
    puVar2 = (uchar *)CRYPTO_malloc(length,"a_object.c",0x13f);
    if (puVar2 == (uchar *)0x0) {
      ERR_put_error(0xd,0xc4,0x41,"a_object.c",0x154);
      if (a == (ASN1_OBJECT **)0x0) goto LAB_08136295;
LAB_08136289:
      if (*a == ptr) {
        return (ASN1_OBJECT *)0x0;
      }
LAB_08136295:
      uVar3 = ptr->flags;
      if ((uVar3 & 4) != 0) {
        if (ptr->sn != (char *)0x0) {
          CRYPTO_free(ptr->sn);
        }
        if (ptr->ln != (char **)0x0) {
          CRYPTO_free(ptr->ln);
        }
        uVar3 = ptr->flags;
        ptr->ln = (char **)0x0;
        ptr->sn = (char *)0x0;
      }
      if ((uVar3 & 8) != 0) {
        if (ptr->data != (uchar *)0x0) {
          CRYPTO_free(ptr->data);
          uVar3 = ptr->flags;
        }
        ptr->data = (uchar *)0x0;
        ptr->length = 0;
      }
      if ((uVar3 & 1) != 0) {
        CRYPTO_free(ptr);
      }
      return (ASN1_OBJECT *)0x0;
    }
LAB_081361a7:
    ptr->flags = ptr->flags | 8;
    puVar4 = __src + length;
    memcpy(puVar2,__src,length);
    ptr->length = length;
    ptr->sn = (char *)0x0;
    ptr->ln = (char **)0x0;
    ptr->data = puVar2;
    if (a == (ASN1_OBJECT **)0x0) goto LAB_081361e4;
  }
  else {
    puVar2 = ptr->data;
    ptr->data = (uchar *)0x0;
    if (puVar2 == (uchar *)0x0) goto LAB_0813623c;
    if (ptr->length < length) {
      ptr->length = 0;
      CRYPTO_free(puVar2);
      puVar2 = (uchar *)CRYPTO_malloc(length,"a_object.c",0x13f);
      if (puVar2 == (uchar *)0x0) {
        ERR_put_error(0xd,0xc4,0x41,"a_object.c",0x154);
        goto LAB_08136289;
      }
      goto LAB_081361a7;
    }
    puVar4 = __src + length;
    memcpy(puVar2,__src,length);
    ptr->length = length;
    ptr->sn = (char *)0x0;
    ptr->ln = (char **)0x0;
    ptr->data = puVar2;
  }
  *a = ptr;
LAB_081361e4:
  *pp = puVar4;
  return ptr;
}

