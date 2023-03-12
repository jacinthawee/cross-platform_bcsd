
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
  
  iVar2 = __stack_chk_guard;
  local_14 = __stack_chk_guard;
  a->type = 2;
  if (a->length < 5) {
    if (a->data != (uchar *)0x0) {
      CRYPTO_free(a->data);
    }
    puVar1 = (uchar *)CRYPTO_malloc(5,"a_int.c",0x164);
    a->data = puVar1;
    if (puVar1 != (uchar *)0x0) {
      iVar2 = 0;
      *puVar1 = '\0';
      puVar1[1] = '\0';
      puVar1[2] = '\0';
      puVar1[3] = '\0';
      puVar1[4] = '\0';
      goto LAB_000b14a6;
    }
  }
  else {
LAB_000b14a6:
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
LAB_000b14bc:
        auStack_22[2] = (uchar)v;
        if (v >> 8 == 0) {
          iVar2 = 1;
LAB_000b1532:
          uVar3 = iVar2 - 1;
          *puVar1 = auStack_22[iVar2 + 1];
          if (uVar3 != 0) {
            iVar4 = iVar2 + -3;
            a->data[1] = auStack_22[iVar2];
            if (iVar4 != -1) goto LAB_000b14e6;
          }
        }
        else {
          auStack_22[3] = (char)((uint)v >> 8);
          if (v >> 0x10 == 0) {
            iVar2 = 2;
            goto LAB_000b1532;
          }
          auStack_22[4] = (uchar)((uint)v >> 0x10);
          if (v >> 0x18 == 0) {
            iVar2 = 3;
            goto LAB_000b1532;
          }
          auStack_22[5] = (uchar)((uint)v >> 0x18);
          *puVar1 = auStack_22[5];
          uVar3 = 3;
          iVar4 = 1;
          a->data[1] = auStack_22[4];
LAB_000b14e6:
          a->data[2] = auStack_22[iVar4 + 2];
          if (iVar4 == 1) {
            a->data[3] = (uchar)v;
          }
        }
        v = (uVar3 & ~((int)uVar3 >> 0x1f)) + 1;
      }
      else if (bVar6) goto LAB_000b14bc;
      iVar2 = 1;
      a->length = v;
      goto LAB_000b1508;
    }
  }
  ERR_put_error(0xd,0x76,0x41,"a_int.c",0x168);
  iVar2 = 0;
LAB_000b1508:
  if (local_14 == __stack_chk_guard) {
    return iVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

