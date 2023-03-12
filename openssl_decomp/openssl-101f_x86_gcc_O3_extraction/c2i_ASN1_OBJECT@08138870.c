
ASN1_OBJECT * c2i_ASN1_OBJECT(ASN1_OBJECT **a,uchar **pp,long length)

{
  int iVar1;
  ASN1_OBJECT *ptr;
  uchar *puVar2;
  uint uVar3;
  uchar *puVar4;
  
  puVar4 = *pp;
  if (0 < length) {
    iVar1 = 0;
    do {
      if ((puVar4[iVar1] == 0x80) && ((iVar1 == 0 || (-1 < (char)puVar4[iVar1 + -1])))) {
        ERR_put_error(0xd,0xc4,0xd8,"a_object.c",300);
        return (ASN1_OBJECT *)0x0;
      }
      iVar1 = iVar1 + 1;
    } while (length != iVar1);
  }
  if (((a == (ASN1_OBJECT **)0x0) || (ptr = *a, ptr == (ASN1_OBJECT *)0x0)) ||
     ((*(byte *)&ptr->flags & 1) == 0)) {
    ptr = (ASN1_OBJECT *)CRYPTO_malloc(0x18,"a_object.c",0x15f);
    if (ptr == (ASN1_OBJECT *)0x0) {
      ERR_put_error(0xd,0x7b,0x41,"a_object.c",0x162);
      return (ASN1_OBJECT *)0x0;
    }
    ptr->data = (uchar *)0x0;
    ptr->sn = (char *)0x0;
    ptr->ln = (char **)0x0;
    puVar4 = *pp;
    ptr->length = 0;
    ptr->nid = 0;
    ptr->flags = 1;
LAB_08138900:
    ptr->length = 0;
LAB_08138907:
    iVar1 = 1;
    if (length != 0) {
      iVar1 = length;
    }
    puVar2 = (uchar *)CRYPTO_malloc(iVar1,"a_object.c",0x143);
    if (puVar2 == (uchar *)0x0) {
      ERR_put_error(0xd,0xc4,0x41,"a_object.c",0x155);
      if ((a == (ASN1_OBJECT **)0x0) || (ptr != *a)) {
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
          return (ASN1_OBJECT *)0x0;
        }
      }
      return (ASN1_OBJECT *)0x0;
    }
    ptr->flags = ptr->flags | 8;
    memcpy(puVar2,puVar4,length);
    ptr->length = length;
    puVar4 = puVar4 + length;
    ptr->sn = (char *)0x0;
    ptr->ln = (char **)0x0;
    ptr->data = puVar2;
    if (a == (ASN1_OBJECT **)0x0) goto LAB_0813896d;
  }
  else {
    puVar2 = ptr->data;
    ptr->data = (uchar *)0x0;
    if (puVar2 == (uchar *)0x0) goto LAB_08138900;
    if (ptr->length < length) {
      ptr->length = 0;
      CRYPTO_free(puVar2);
      goto LAB_08138907;
    }
    memcpy(puVar2,puVar4,length);
    ptr->length = length;
    ptr->sn = (char *)0x0;
    ptr->ln = (char **)0x0;
    puVar4 = puVar4 + length;
    ptr->data = puVar2;
  }
  *a = ptr;
LAB_0813896d:
  *pp = puVar4;
  return ptr;
}

