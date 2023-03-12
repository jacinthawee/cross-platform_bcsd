
ASN1_OBJECT * OBJ_dup(ASN1_OBJECT *o)

{
  ASN1_OBJECT *ptr;
  uchar *__dest;
  char **__s;
  size_t sVar1;
  char *__dest_00;
  int iVar2;
  int iVar3;
  
  if ((o == (ASN1_OBJECT *)0x0) || (-1 < o->flags << 0x1f)) {
    return o;
  }
  ptr = ASN1_OBJECT_new();
  if (ptr == (ASN1_OBJECT *)0x0) {
    ERR_put_error(8,0x65,0xd,"obj_lib.c",0x50);
    return (ASN1_OBJECT *)0x0;
  }
  __dest = (uchar *)CRYPTO_malloc(o->length,"obj_lib.c",0x53);
  if (__dest == (uchar *)0x0) {
    ERR_put_error(8,0x65,0x41,"obj_lib.c",0x72);
    goto LAB_0006f746;
  }
  if (o->data != (uchar *)0x0) {
    memcpy(__dest,o->data,o->length);
  }
  iVar3 = o->length;
  iVar2 = o->nid;
  ptr->ln = (char **)0x0;
  __s = o->ln;
  ptr->data = __dest;
  ptr->length = iVar3;
  ptr->nid = iVar2;
  ptr->sn = (char *)0x0;
  if (__s == (char **)0x0) {
LAB_0006f6ee:
    if (o->sn == (char *)0x0) {
LAB_0006f71a:
      ptr->flags = o->flags | 0xd;
      return ptr;
    }
    sVar1 = strlen(o->sn);
    __dest_00 = (char *)CRYPTO_malloc(sVar1 + 1,"obj_lib.c",0x69);
    if (__dest_00 != (char *)0x0) {
      memcpy(__dest_00,o->sn,sVar1 + 1);
      ptr->sn = __dest_00;
      goto LAB_0006f71a;
    }
    ERR_put_error(8,0x65,0x41,"obj_lib.c",0x72);
    if (__s != (char **)0x0) {
      CRYPTO_free(__s);
    }
  }
  else {
    sVar1 = strlen((char *)__s);
    __s = (char **)CRYPTO_malloc(sVar1 + 1,"obj_lib.c",0x60);
    if (__s != (char **)0x0) {
      memcpy(__s,o->ln,sVar1 + 1);
      ptr->ln = __s;
      goto LAB_0006f6ee;
    }
    ERR_put_error(8,0x65,0x41,"obj_lib.c",0x72);
  }
  CRYPTO_free(__dest);
LAB_0006f746:
  CRYPTO_free(ptr);
  return (ASN1_OBJECT *)0x0;
}

