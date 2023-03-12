
int ENGINE_ctrl_cmd(ENGINE *e,char *cmd_name,long i,void *p,f *f,int cmd_optional)

{
  int iVar1;
  
  if (cmd_name == (char *)0x0 || e == (ENGINE *)0x0) {
    ERR_put_error(0x26,0xb2,0x43,"eng_ctrl.c",0xfd);
    return 0;
  }
  if (*(int *)(e + 0x40) != 0) {
    CRYPTO_lock(9,0x1e,"eng_ctrl.c",0xba);
    iVar1 = *(int *)(e + 0x58);
    CRYPTO_lock(10,0x1e,"eng_ctrl.c",0xbc);
    if (iVar1 < 1) {
      ERR_put_error(0x26,0x8e,0x82,"eng_ctrl.c",0xbf);
    }
    else if (*(code **)(e + 0x40) == (code *)0x0) {
      ERR_put_error(0x26,0x8e,0x78,"eng_ctrl.c",0xd4);
    }
    else {
      if ((*(uint *)(e + 0x54) & 2) == 0) {
        iVar1 = int_ctrl_helper_isra_1(e + 0x50,0xd,0,cmd_name);
      }
      else {
        iVar1 = (**(code **)(e + 0x40))(e,0xd,0,cmd_name,0);
      }
      if (0 < iVar1) {
        iVar1 = ENGINE_ctrl(e,iVar1,i,p,f);
        return (uint)(0 < iVar1);
      }
    }
  }
  if (cmd_optional != 0) {
    ERR_clear_error();
    return 1;
  }
  ERR_put_error(0x26,0xb2,0x89,"eng_ctrl.c",0x110);
  return 0;
}

