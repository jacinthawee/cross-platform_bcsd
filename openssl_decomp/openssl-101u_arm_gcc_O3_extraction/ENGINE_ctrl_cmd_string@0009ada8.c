
int ENGINE_ctrl_cmd_string(ENGINE *e,char *cmd_name,char *arg,int cmd_optional)

{
  uint uVar1;
  long i;
  uint uVar2;
  int iVar3;
  char *local_24 [2];
  
  if (cmd_name == (char *)0x0 || e == (ENGINE *)0x0) {
    ERR_put_error(0x26,0xab,0x43,"eng_ctrl.c",0x124);
    return 0;
  }
  if (*(int *)(e + 0x40) != 0) {
    CRYPTO_lock(9,0x1e,"eng_ctrl.c",0xba);
    iVar3 = *(int *)(e + 0x58);
    CRYPTO_lock(10,0x1e,"eng_ctrl.c",0xbc);
    if (iVar3 < 1) {
      ERR_put_error(0x26,0x8e,0x82,"eng_ctrl.c",0xbf);
    }
    else if (*(code **)(e + 0x40) == (code *)0x0) {
      ERR_put_error(0x26,0x8e,0x78,"eng_ctrl.c",0xd4);
    }
    else {
      if ((*(uint *)(e + 0x54) & 2) == 0) {
        iVar3 = int_ctrl_helper_isra_1(e + 0x50,0xd,0,cmd_name);
      }
      else {
        iVar3 = (**(code **)(e + 0x40))(e,0xd,0,cmd_name,0);
      }
      if (0 < iVar3) {
        uVar2 = 0;
        uVar1 = ENGINE_ctrl(e,0x12,iVar3,(void *)0x0,(f *)0x0);
        if ((int)uVar1 < 0) {
          ERR_put_error(0x26,0xaa,0x8a,"eng_ctrl.c",0xed);
        }
        else if ((uVar1 & 7) != 0) {
          uVar1 = ENGINE_ctrl(e,0x12,iVar3,(void *)0x0,(f *)0x0);
          if ((int)uVar1 < 0) {
            iVar3 = 0x146;
          }
          else {
            if ((uVar1 & 4) != 0) {
              if (arg != (char *)0x0) {
                ERR_put_error(0x26,0xab,0x88,"eng_ctrl.c",0x14f);
                return 0;
              }
              iVar3 = ENGINE_ctrl(e,iVar3,0,(void *)0x0,(f *)0x0);
              return (uint)(0 < iVar3);
            }
            if (arg == (char *)0x0) {
              ERR_put_error(0x26,0xab,0x87,"eng_ctrl.c",0x15f);
              return 0;
            }
            if ((int)(uVar1 << 0x1e) < 0) {
              iVar3 = ENGINE_ctrl(e,iVar3,0,arg,(f *)0x0);
              return (uint)(0 < iVar3);
            }
            uVar2 = uVar1 & 1;
            if (uVar2 != 0) {
              i = strtol(arg,local_24,10);
              if ((arg != local_24[0]) && (*local_24[0] == '\0')) {
                iVar3 = ENGINE_ctrl(e,iVar3,i,(void *)0x0,(f *)0x0);
                return (uint)(0 < iVar3);
              }
              ERR_put_error(0x26,0xab,0x85,"eng_ctrl.c",0x177);
              return 0;
            }
            iVar3 = 0x171;
          }
          ERR_put_error(0x26,0xab,0x6e,"eng_ctrl.c",iVar3);
          return uVar2;
        }
        ERR_put_error(0x26,0xab,0x86,"eng_ctrl.c",0x13c);
        return 0;
      }
    }
  }
  if (cmd_optional == 0) {
    ERR_put_error(0x26,0xab,0x89,"eng_ctrl.c",0x137);
    return 0;
  }
  ERR_clear_error();
  return 1;
}

