
int ENGINE_cmd_is_executable(ENGINE *e,int cmd)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  int iVar7;
  
  if (e == (ENGINE *)0x0) {
    ERR_put_error(0x26,0x8e,0x43,"eng_ctrl.c",0xb7);
    return 0;
  }
  CRYPTO_lock(9,0x1e,"eng_ctrl.c",0xba);
  iVar7 = *(int *)(e + 0x58);
  CRYPTO_lock(10,0x1e,"eng_ctrl.c",0xbc);
  if (iVar7 < 1) {
    ERR_put_error(0x26,0x8e,0x82,"eng_ctrl.c",0xbf);
    return 0;
  }
  if (*(code **)(e + 0x40) == (code *)0x0) {
    ERR_put_error(0x26,0x8e,0x78,"eng_ctrl.c",0xd4);
    goto LAB_0009ac1e;
  }
  uVar4 = *(uint *)(e + 0x54) & 2;
  if (uVar4 == 0) {
    puVar6 = *(uint **)(e + 0x50);
    if (puVar6 != (uint *)0x0) {
      uVar2 = *puVar6;
      uVar3 = uVar2;
      if (uVar2 != 0) {
        uVar1 = puVar6[1];
        puVar5 = puVar6;
        uVar2 = uVar1;
        while ((uVar1 != 0 && (uVar2 = uVar4, uVar3 < (uint)cmd))) {
          uVar3 = puVar5[4];
          uVar4 = uVar4 + 1;
          if (uVar3 == 0) goto LAB_0009ac08;
          uVar1 = puVar5[5];
          puVar5 = puVar5 + 4;
          uVar2 = uVar4;
        }
      }
      if (cmd == uVar3) {
        uVar4 = puVar6[uVar2 * 4 + 3];
        goto LAB_0009abc6;
      }
    }
LAB_0009ac08:
    ERR_put_error(0x26,0xac,0x8a,"eng_ctrl.c",0x8f);
  }
  else {
    uVar4 = (**(code **)(e + 0x40))(e,0x12,cmd,0,0);
LAB_0009abc6:
    if (-1 < (int)uVar4) {
      if ((uVar4 & 7) == 0) {
        return 0;
      }
      return 1;
    }
  }
LAB_0009ac1e:
  ERR_put_error(0x26,0xaa,0x8a,"eng_ctrl.c",0xed);
  return 0;
}

