
int ENGINE_ctrl_cmd(ENGINE *e,char *cmd_name,long i,void *p,f *f,int cmd_optional)

{
  int reason;
  int iVar1;
  
  if ((e == (ENGINE *)0x0) || (cmd_name == (char *)0x0)) {
    reason = 0x43;
    iVar1 = 0xfd;
  }
  else {
    if (*(int *)(e + 0x40) != 0) {
      (*(code *)PTR_CRYPTO_lock_006a8144)(9,0x1e,"eng_ctrl.c",0xba);
      iVar1 = *(int *)(e + 0x58);
      (*(code *)PTR_CRYPTO_lock_006a8144)(10,0x1e,"eng_ctrl.c",0xbc);
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
    reason = 0x89;
    iVar1 = 0x110;
  }
  ERR_put_error(0x26,0xb2,reason,"eng_ctrl.c",iVar1);
  return 0;
}

