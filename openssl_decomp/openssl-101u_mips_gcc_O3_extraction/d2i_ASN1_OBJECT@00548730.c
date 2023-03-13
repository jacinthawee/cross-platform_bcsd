
ASN1_OBJECT * d2i_ASN1_OBJECT(ASN1_OBJECT **a,uchar **pp,long length)

{
  undefined *puVar1;
  uint uVar2;
  ASN1_OBJECT *pAVar3;
  int reason;
  uchar *local_2c;
  long local_28;
  int local_24;
  int iStack_20;
  int local_1c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *pp;
  local_1c = *(int *)PTR___stack_chk_guard_006a9ae8;
  uVar2 = ASN1_get_object(&local_2c,&local_28,&local_24,&iStack_20,length);
  if ((uVar2 & 0x80) == 0) {
    if (local_24 == 6) {
      pAVar3 = c2i_ASN1_OBJECT(a,&local_2c,local_28);
      if (pAVar3 == (ASN1_OBJECT *)0x0) {
        pAVar3 = (ASN1_OBJECT *)0x0;
      }
      else {
        *pp = local_2c;
      }
      goto LAB_005487cc;
    }
    reason = 0x74;
  }
  else {
    reason = 0x66;
  }
  ERR_put_error(0xd,0x93,reason,"a_object.c",0x10c);
  pAVar3 = (ASN1_OBJECT *)0x0;
LAB_005487cc:
  if (local_1c == *(int *)puVar1) {
    return pAVar3;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  pAVar3 = (ASN1_OBJECT *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x18,"a_object.c",0x15e);
  if (pAVar3 == (ASN1_OBJECT *)0x0) {
    ERR_put_error(0xd,0x7b,0x41,"a_object.c",0x160);
    pAVar3 = (ASN1_OBJECT *)0x0;
  }
  else {
    pAVar3->length = 0;
    pAVar3->data = (uchar *)0x0;
    pAVar3->nid = 0;
    pAVar3->sn = (char *)0x0;
    pAVar3->ln = (char **)0x0;
    pAVar3->flags = 1;
  }
  return pAVar3;
}

