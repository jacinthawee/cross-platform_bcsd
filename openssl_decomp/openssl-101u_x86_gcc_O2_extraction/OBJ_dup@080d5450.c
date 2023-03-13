
ASN1_OBJECT * OBJ_dup(ASN1_OBJECT *o)

{
  int iVar1;
  ASN1_OBJECT *ptr;
  uchar *__dest;
  size_t sVar2;
  char **__dest_00;
  char *__dest_01;
  
  if (o == (ASN1_OBJECT *)0x0) {
    return (ASN1_OBJECT *)0x0;
  }
  if ((*(byte *)&o->flags & 1) == 0) {
    return o;
  }
  ptr = ASN1_OBJECT_new();
  if (ptr == (ASN1_OBJECT *)0x0) {
    ERR_put_error(8,0x65,0xd,"obj_lib.c",0x50);
    return (ASN1_OBJECT *)0x0;
  }
  __dest = (uchar *)CRYPTO_malloc(o->length,"obj_lib.c",0x53);
  if (__dest == (uchar *)0x0) {
    ERR_put_error(8,0x65,0x41,"obj_lib.c",0x73);
    goto LAB_080d55a4;
  }
  if (o->data != (uchar *)0x0) {
    memcpy(__dest,o->data,o->length);
  }
  iVar1 = o->length;
  ptr->data = __dest;
  ptr->length = iVar1;
  iVar1 = o->nid;
  ptr->ln = (char **)0x0;
  ptr->sn = (char *)0x0;
  ptr->nid = iVar1;
  if (o->ln == (char **)0x0) {
    __dest_00 = (char **)0x0;
LAB_080d5522:
    if (o->sn == (char *)0x0) {
LAB_080d556c:
      ptr->flags = o->flags | 0xd;
      return ptr;
    }
    sVar2 = strlen(o->sn);
    __dest_01 = (char *)CRYPTO_malloc(sVar2 + 1,"obj_lib.c",0x68);
    if (__dest_01 != (char *)0x0) {
      memcpy(__dest_01,o->sn,sVar2 + 1);
      ptr->sn = __dest_01;
      goto LAB_080d556c;
    }
    ERR_put_error(8,0x65,0x41,"obj_lib.c",0x73);
    if (__dest_00 != (char **)0x0) {
      CRYPTO_free(__dest_00);
    }
  }
  else {
    sVar2 = strlen((char *)o->ln);
    __dest_00 = (char **)CRYPTO_malloc(sVar2 + 1,"obj_lib.c",0x5f);
    if (__dest_00 != (char **)0x0) {
      memcpy(__dest_00,o->ln,sVar2 + 1);
      ptr->ln = __dest_00;
      goto LAB_080d5522;
    }
    ERR_put_error(8,0x65,0x41,"obj_lib.c",0x73);
  }
  CRYPTO_free(__dest);
LAB_080d55a4:
  CRYPTO_free(ptr);
  return (ASN1_OBJECT *)0x0;
}

