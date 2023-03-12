
int ASN1_STRING_print(BIO *bp,ASN1_STRING *v)

{
  uchar *puVar1;
  uchar uVar2;
  int iVar3;
  uint uVar4;
  int len;
  int iVar5;
  int in_GS_OFFSET;
  uchar local_70 [80];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (v == (ASN1_STRING *)0x0) {
LAB_08144c50:
    uVar4 = 0;
  }
  else {
    iVar3 = v->length;
    len = 0;
    iVar5 = 0;
    puVar1 = v->data;
    if (0 < iVar3) {
      do {
        while( true ) {
          uVar2 = puVar1[iVar5];
          if (uVar2 == '\x7f') {
            uVar2 = '.';
          }
          else if (((char)uVar2 < ' ' && uVar2 != '\n') && (uVar2 != '\r')) {
            uVar2 = '.';
          }
          local_70[len] = uVar2;
          len = len + 1;
          if (len < 0x50) break;
          iVar3 = BIO_write(bp,local_70,len);
          if (iVar3 < 1) goto LAB_08144c50;
          iVar5 = iVar5 + 1;
          len = 0;
          iVar3 = v->length;
          if (iVar3 <= iVar5) goto LAB_08144bfe;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar3);
LAB_08144bfe:
      if (len != 0) {
        iVar3 = BIO_write(bp,local_70,len);
        uVar4 = (uint)(0 < iVar3);
        goto LAB_08144c1f;
      }
    }
    uVar4 = 1;
  }
LAB_08144c1f:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar4;
}

