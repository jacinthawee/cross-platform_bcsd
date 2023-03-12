
int ASN1_STRING_print(BIO *bp,ASN1_STRING *v)

{
  int iVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  uint uVar5;
  int iVar6;
  uchar *puVar7;
  byte abStack_74 [80];
  int local_24;
  
  local_24 = __TMC_END__;
  if (v == (ASN1_STRING *)0x0) {
LAB_000b9bd8:
    iVar6 = 0;
  }
  else {
    iVar6 = v->length;
    puVar7 = v->data;
    if (0 < iVar6) {
      iVar2 = 0;
      iVar3 = iVar2;
      do {
        while( true ) {
          bVar4 = puVar7[iVar2];
          uVar5 = (uint)bVar4;
          if (uVar5 < 0x7f) {
            iVar1 = uVar5 - 10;
            if (iVar1 != 0) {
              iVar1 = 1;
            }
            if (0x1f < uVar5) {
              iVar1 = 0;
            }
            if ((iVar1 != 0) && (uVar5 != 0xd)) {
              bVar4 = 0x2e;
            }
          }
          else {
            bVar4 = 0x2e;
          }
          iVar1 = iVar3 + 1;
          abStack_74[iVar3] = bVar4;
          if (iVar1 < 0x50) break;
          iVar6 = BIO_write(bp,abStack_74,iVar1);
          if (iVar6 < 1) goto LAB_000b9bd8;
          iVar6 = v->length;
          iVar2 = iVar2 + 1;
          iVar1 = 0;
          iVar3 = iVar1;
          if (iVar6 <= iVar2) goto LAB_000b9bb2;
        }
        iVar2 = iVar2 + 1;
        iVar3 = iVar1;
      } while (iVar2 < iVar6);
LAB_000b9bb2:
      if (iVar1 != 0) {
        iVar6 = BIO_write(bp,abStack_74,iVar1);
        if (iVar6 < 1) {
          iVar6 = 0;
        }
        else {
          iVar6 = 1;
        }
        goto LAB_000b9bc4;
      }
    }
    iVar6 = 1;
  }
LAB_000b9bc4:
  if (local_24 == __TMC_END__) {
    return iVar6;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

