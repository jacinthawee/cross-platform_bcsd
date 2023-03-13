
int __regparm1 ENGINE_cmd_is_executable(ENGINE *e,int cmd)

{
  uint *puVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  uint in_stack_00000008;
  
  if (cmd == 0) {
    ERR_put_error(0x26,0x8e,0x43,"eng_ctrl.c",0xb7);
    return 0;
  }
  CRYPTO_lock((int)e,9,(char *)0x1e,(int)"eng_ctrl.c");
  iVar4 = *(int *)(cmd + 0x58);
  CRYPTO_lock((int)e,10,(char *)0x1e,(int)"eng_ctrl.c");
  if (iVar4 < 1) {
    ERR_put_error(0x26,0x8e,0x82,"eng_ctrl.c",0xbf);
    return 0;
  }
  if (*(code **)(cmd + 0x40) == (code *)0x0) {
    ERR_put_error(0x26,0x8e,0x78,"eng_ctrl.c",0xd4);
    goto LAB_081123d0;
  }
  if ((*(byte *)(cmd + 0x54) & 2) == 0) {
    puVar1 = *(uint **)(cmd + 0x50);
    if (puVar1 != (uint *)0x0) {
      uVar2 = *puVar1;
      if (((uVar2 == 0) || (puVar1[1] == 0)) || (in_stack_00000008 <= uVar2)) {
        iVar4 = 0;
      }
      else {
        iVar4 = 0;
        puVar3 = puVar1;
        do {
          uVar2 = puVar3[4];
          iVar4 = iVar4 + 1;
          if (uVar2 == 0) goto LAB_081123af;
        } while ((puVar3[5] != 0) && (puVar3 = puVar3 + 4, uVar2 < in_stack_00000008));
      }
      if (in_stack_00000008 == uVar2) {
        uVar2 = puVar1[iVar4 * 4 + 3];
        goto LAB_08112348;
      }
    }
LAB_081123af:
    ERR_put_error(0x26,0xac,0x8a,"eng_ctrl.c",0x8f);
  }
  else {
    uVar2 = (**(code **)(cmd + 0x40))(cmd,0x12);
LAB_08112348:
    if (-1 < (int)uVar2) {
      return (uint)((uVar2 & 7) != 0);
    }
  }
LAB_081123d0:
  ERR_put_error(0x26,0xaa,0x8a,"eng_ctrl.c",0xed);
  return 0;
}

