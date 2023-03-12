
ASN1_OBJECT * OBJ_dup(ASN1_OBJECT *o)

{
  ASN1_OBJECT *ptr;
  uchar *ptr_00;
  int iVar1;
  char **ptr_01;
  void *pvVar2;
  char *pcVar3;
  int iVar4;
  
  if (o == (ASN1_OBJECT *)0x0) {
    return (ASN1_OBJECT *)0x0;
  }
  if ((o->flags & 1U) == 0) {
    return o;
  }
  ptr = (ASN1_OBJECT *)(*(code *)PTR_ASN1_OBJECT_new_006a84ac)();
  if (ptr == (ASN1_OBJECT *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(8,0x65,0xd,"obj_lib.c",0x50);
    return (ASN1_OBJECT *)0x0;
  }
  ptr_00 = (uchar *)CRYPTO_malloc(o->length,"obj_lib.c",0x53);
  if (ptr_00 == (uchar *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(8,0x65,0x41,"obj_lib.c",0x73);
    goto LAB_004c4494;
  }
  if (o->data != (uchar *)0x0) {
    (*(code *)PTR_memcpy_006a9aec)(ptr_00,o->data,o->length);
  }
  iVar4 = o->length;
  iVar1 = o->nid;
  ptr->ln = (char **)0x0;
  ptr->data = ptr_00;
  ptr->length = iVar4;
  ptr->nid = iVar1;
  ptr->sn = (char *)0x0;
  if (o->ln == (char **)0x0) {
    ptr_01 = (char **)0x0;
LAB_004c43d8:
    if (o->sn == (char *)0x0) {
LAB_004c4428:
      ptr->flags = o->flags | 0xd;
      return ptr;
    }
    iVar1 = (*(code *)PTR_strlen_006a9a24)();
    pvVar2 = CRYPTO_malloc(iVar1 + 1,"obj_lib.c",0x68);
    if (pvVar2 != (void *)0x0) {
      pcVar3 = (char *)(*(code *)PTR_memcpy_006a9aec)(pvVar2,o->sn,iVar1 + 1);
      ptr->sn = pcVar3;
      goto LAB_004c4428;
    }
    (*(code *)PTR_ERR_put_error_006a7f34)(8,0x65,0x41,"obj_lib.c",0x73);
    if (ptr_01 != (char **)0x0) {
      CRYPTO_free(ptr_01);
    }
  }
  else {
    iVar1 = (*(code *)PTR_strlen_006a9a24)();
    ptr_01 = (char **)CRYPTO_malloc(iVar1 + 1,"obj_lib.c",0x5f);
    if (ptr_01 != (char **)0x0) {
      (*(code *)PTR_memcpy_006a9aec)(ptr_01,o->ln,iVar1 + 1);
      ptr->ln = ptr_01;
      goto LAB_004c43d8;
    }
    (*(code *)PTR_ERR_put_error_006a7f34)(8,0x65,0x41,"obj_lib.c",0x73);
  }
  CRYPTO_free(ptr_00);
LAB_004c4494:
  CRYPTO_free(ptr);
  return (ASN1_OBJECT *)0x0;
}

