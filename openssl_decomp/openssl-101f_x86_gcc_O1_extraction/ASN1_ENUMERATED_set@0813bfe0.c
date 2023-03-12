
int ASN1_ENUMERATED_set(ASN1_ENUMERATED *a,long v)

{
  uchar *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int in_GS_OFFSET;
  uchar auStack_17 [7];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  a->type = 10;
  if (a->length < 5) {
    if (a->data != (uchar *)0x0) {
      CRYPTO_free(a->data);
    }
    puVar2 = (undefined4 *)CRYPTO_malloc(5,"a_enum.c",0x51);
    a->data = (uchar *)puVar2;
    if (puVar2 != (undefined4 *)0x0) {
      *puVar2 = 0;
      *(undefined *)(puVar2 + 1) = 0;
      goto LAB_0813c041;
    }
  }
  else {
LAB_0813c041:
    puVar1 = a->data;
    if (puVar1 != (uchar *)0x0) {
      if (v < 0) {
        v = -v;
        a->type = 0x10a;
LAB_0813c05a:
        auStack_17[2] = (uchar)v;
        if (v >> 8 == 0) {
          iVar4 = 1;
LAB_0813c11d:
          iVar3 = iVar4 + -1;
          *puVar1 = auStack_17[iVar4 + 1];
          if (iVar4 != 1) {
            iVar5 = iVar4 + -3;
            a->data[1] = auStack_17[iVar4];
            if (iVar5 != -1) goto LAB_0813c0a1;
          }
        }
        else {
          auStack_17[3] = (char)((uint)v >> 8);
          if (v >> 0x10 == 0) {
            iVar4 = 2;
            goto LAB_0813c11d;
          }
          auStack_17[4] = (uchar)((uint)v >> 0x10);
          if (v >> 0x18 == 0) {
            iVar4 = 3;
            goto LAB_0813c11d;
          }
          auStack_17[5] = (uchar)((uint)v >> 0x18);
          *puVar1 = auStack_17[5];
          a->data[1] = auStack_17[4];
          iVar3 = 3;
          iVar5 = 1;
LAB_0813c0a1:
          a->data[2] = auStack_17[iVar5 + 2];
          if (iVar5 != 0) {
            a->data[3] = (uchar)v;
          }
        }
        iVar3 = iVar3 + 1;
      }
      else {
        if (v != 0) goto LAB_0813c05a;
        iVar3 = 0;
      }
      a->length = iVar3;
      iVar4 = 1;
      goto LAB_0813c0c5;
    }
  }
  ERR_put_error(0xd,0x70,0x41,"a_enum.c",0x56);
  iVar4 = 0;
LAB_0813c0c5:
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}

