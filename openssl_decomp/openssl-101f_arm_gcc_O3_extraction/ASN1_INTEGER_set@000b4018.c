
int ASN1_INTEGER_set(ASN1_INTEGER *a,long v)

{
  uchar *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  bool bVar5;
  bool bVar6;
  uchar auStack_22 [14];
  int local_14;
  
  iVar2 = __TMC_END__;
  local_14 = __TMC_END__;
  a->type = 2;
  if (a->length < 5) {
    if (a->data != (uchar *)0x0) {
      CRYPTO_free(a->data);
    }
    puVar1 = (uchar *)CRYPTO_malloc(5,"a_int.c",0x15b);
    a->data = puVar1;
    if (puVar1 != (uchar *)0x0) {
      iVar2 = 0;
      *puVar1 = '\0';
      puVar1[1] = '\0';
      puVar1[2] = '\0';
      puVar1[3] = '\0';
      puVar1[4] = '\0';
      goto LAB_000b406e;
    }
  }
  else {
LAB_000b406e:
    puVar1 = a->data;
    if (puVar1 != (uchar *)0x0) {
      bVar5 = v < 0;
      bVar6 = v != 0;
      if (bVar5) {
        v = -v;
        iVar2 = 0x102;
      }
      if (bVar5) {
        a->type = iVar2;
LAB_000b4084:
        auStack_22[2] = (uchar)v;
        if (v >> 8 == 0) {
          iVar2 = 1;
LAB_000b40fa:
          uVar3 = iVar2 - 1;
          *puVar1 = auStack_22[iVar2 + 1];
          if (uVar3 != 0) {
            iVar4 = iVar2 + -3;
            a->data[1] = auStack_22[iVar2];
            if (iVar4 != -1) goto LAB_000b40ae;
          }
        }
        else {
          auStack_22[3] = (char)((uint)v >> 8);
          if (v >> 0x10 == 0) {
            iVar2 = 2;
            goto LAB_000b40fa;
          }
          auStack_22[4] = (uchar)((uint)v >> 0x10);
          if (v >> 0x18 == 0) {
            iVar2 = 3;
            goto LAB_000b40fa;
          }
          auStack_22[5] = (uchar)((uint)v >> 0x18);
          *puVar1 = auStack_22[5];
          uVar3 = 3;
          iVar4 = 1;
          a->data[1] = auStack_22[4];
LAB_000b40ae:
          a->data[2] = auStack_22[iVar4 + 2];
          if (iVar4 == 1) {
            a->data[3] = (uchar)v;
          }
        }
        v = (uVar3 & ~((int)uVar3 >> 0x1f)) + 1;
      }
      else if (bVar6) goto LAB_000b4084;
      iVar2 = 1;
      a->length = v;
      goto LAB_000b40d0;
    }
  }
  ERR_put_error(0xd,0x76,0x41,"a_int.c",0x160);
  iVar2 = 0;
LAB_000b40d0:
  if (local_14 == __TMC_END__) {
    return iVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

