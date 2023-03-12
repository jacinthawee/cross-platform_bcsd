
int ENGINE_cmd_is_executable(ENGINE *e,int cmd)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  
  if (e == (ENGINE *)0x0) {
    ERR_put_error(0x26,0x8e,0x43,"eng_ctrl.c",0xb7);
    return 0;
  }
  (*(code *)PTR_CRYPTO_lock_006a8144)(9,0x1e,"eng_ctrl.c",0xba);
  iVar5 = *(int *)(e + 0x58);
  (*(code *)PTR_CRYPTO_lock_006a8144)(10,0x1e,"eng_ctrl.c",0xbc);
  if (iVar5 < 1) {
    ERR_put_error(0x26,0x8e,0x82,"eng_ctrl.c",0xbf);
    return 0;
  }
  if (*(code **)(e + 0x40) == (code *)0x0) {
    ERR_put_error(0x26,0x8e,0x78,"eng_ctrl.c",0xd4);
    goto LAB_00519d74;
  }
  if ((*(uint *)(e + 0x54) & 2) == 0) {
    puVar4 = *(uint **)(e + 0x50);
    if (puVar4 != (uint *)0x0) {
      uVar3 = *puVar4;
      iVar5 = 0;
      if ((uVar3 != 0) && (puVar2 = puVar4, puVar4[1] != 0)) {
        while (uVar3 < (uint)cmd) {
          uVar3 = puVar2[4];
          iVar5 = iVar5 + 1;
          if ((uVar3 == 0) || (puVar1 = puVar2 + 5, puVar2 = puVar2 + 4, *puVar1 == 0)) break;
        }
      }
      if (uVar3 == cmd) {
        uVar3 = puVar4[iVar5 * 4 + 3];
        goto LAB_00519cbc;
      }
    }
    ERR_put_error(0x26,0xac,0x8a,"eng_ctrl.c",0x8f);
  }
  else {
    uVar3 = (**(code **)(e + 0x40))(e,0x12,cmd,0,0);
LAB_00519cbc:
    if (-1 < (int)uVar3) {
      return (uint)((uVar3 & 7) != 0);
    }
  }
LAB_00519d74:
  ERR_put_error(0x26,0xaa,0x8a,"eng_ctrl.c",0xed);
  return 0;
}

