
int i2a_ASN1_STRING(BIO *bp,ASN1_STRING *a,int type)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_GS_OFFSET;
  char local_22;
  char local_21;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (a == (ASN1_STRING *)0x0) {
LAB_081ce198:
    iVar1 = 0;
  }
  else {
    if (a->length == 0) {
      iVar1 = BIO_write(bp,"0",1);
      if (iVar1 == 1) goto LAB_081ce175;
    }
    else {
      if (a->length < 1) goto LAB_081ce198;
      iVar2 = 0;
      iVar1 = 0;
      while( true ) {
        iVar3 = iVar1;
        local_22 = "0123456789ABCDEF"[a->data[iVar2] >> 4];
        local_21 = "0123456789ABCDEF"[a->data[iVar2] & 0xf];
        iVar1 = BIO_write(bp,&local_22,2);
        if (iVar1 != 2) break;
        iVar2 = iVar2 + 1;
        iVar1 = iVar3 + 2;
        if (a->length == iVar2 || a->length < iVar2) goto LAB_081ce175;
        if ((iVar2 != 0) && (iVar2 == (iVar2 / 0x23) * 0x23)) {
          iVar1 = BIO_write(bp,&DAT_08228630,2);
          if (iVar1 != 2) break;
          iVar1 = iVar3 + 4;
        }
      }
    }
    iVar1 = -1;
  }
LAB_081ce175:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}

