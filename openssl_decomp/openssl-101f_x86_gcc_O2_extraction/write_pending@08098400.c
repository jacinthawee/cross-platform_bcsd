
int __regparm3 write_pending(int param_1,int param_2,int param_3)

{
  BIO *b;
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x54);
  if ((*(int *)(iVar3 + 0x14) == param_3 || *(int *)(iVar3 + 0x14) < param_3) &&
     ((*(int *)(iVar3 + 0x18) == param_2 || ((*(byte *)(param_1 + 0x104) & 2) != 0)))) {
    piVar1 = __errno_location();
    while( true ) {
      b = *(BIO **)(param_1 + 0x10);
      *piVar1 = 0;
      if (b == (BIO *)0x0) break;
      *(undefined4 *)(param_1 + 0x18) = 2;
      iVar2 = BIO_write(b,(void *)(*(int *)(iVar3 + 0x1c) + *(int *)(iVar3 + 0x38)),
                        *(int *)(iVar3 + 0x20));
      iVar3 = *(int *)(param_1 + 0x54);
      if (iVar2 == *(int *)(iVar3 + 0x20)) goto LAB_0809849f;
      if (iVar2 < 1) {
        return iVar2;
      }
      *(int *)(iVar3 + 0x1c) = *(int *)(iVar3 + 0x1c) + iVar2;
      *(int *)(iVar3 + 0x20) = *(int *)(iVar3 + 0x20) - iVar2;
    }
    ERR_put_error(0x14,0xd4,0x104,"s2_pkt.c",0x1f0);
    iVar3 = *(int *)(param_1 + 0x54);
    iVar2 = -1;
    if (*(int *)(iVar3 + 0x20) == -1) {
LAB_0809849f:
      iVar2 = *(int *)(iVar3 + 0x24);
      *(undefined4 *)(iVar3 + 0x20) = 0;
      *(undefined4 *)(param_1 + 0x18) = 1;
    }
  }
  else {
    ERR_put_error(0x14,0xd4,0x7f,"s2_pkt.c",0x1e0);
    iVar2 = -1;
  }
  return iVar2;
}

