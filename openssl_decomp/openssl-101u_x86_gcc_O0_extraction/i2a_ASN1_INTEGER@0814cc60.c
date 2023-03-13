
int i2a_ASN1_INTEGER(BIO *bp,ASN1_INTEGER *a)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_GS_OFFSET;
  char local_22;
  char local_21;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (a == (ASN1_INTEGER *)0x0) {
    iVar3 = 0;
    goto LAB_0814cd75;
  }
  iVar3 = 0;
  iVar2 = 2;
  if ((*(byte *)((int)&a->type + 1) & 1) == 0) {
LAB_0814cc94:
    if (a->length == 0) {
      iVar1 = BIO_write(bp,"00",2);
      iVar3 = iVar2;
      if (iVar1 == 2) goto LAB_0814cd75;
    }
    else {
      if (a->length < 1) goto LAB_0814cd75;
      iVar2 = 0;
      while( true ) {
        iVar1 = iVar3;
        local_22 = "0123456789ABCDEF"[a->data[iVar2] >> 4];
        local_21 = "0123456789ABCDEF"[a->data[iVar2] & 0xf];
        iVar3 = BIO_write(bp,&local_22,2);
        if (iVar3 != 2) break;
        iVar2 = iVar2 + 1;
        iVar3 = iVar1 + 2;
        if (a->length == iVar2 || a->length < iVar2) goto LAB_0814cd75;
        if ((iVar2 != 0) && (iVar2 == (iVar2 / 0x23) * 0x23)) {
          iVar3 = BIO_write(bp,&DAT_082289d0,2);
          if (iVar3 != 2) break;
          iVar3 = iVar1 + 4;
        }
      }
    }
  }
  else {
    iVar2 = 3;
    iVar3 = 1;
    iVar1 = BIO_write(bp,&DAT_0823b914,1);
    if (iVar1 == 1) goto LAB_0814cc94;
  }
  iVar3 = -1;
LAB_0814cd75:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}

