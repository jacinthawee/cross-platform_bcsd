
int __regparm1 ENGINE_ctrl_cmd(ENGINE *e,char *cmd_name,long i,void *p,f *f,int cmd_optional)

{
  int iVar1;
  int in_stack_00000018;
  int line;
  undefined4 uVar2;
  char *pcVar3;
  undefined4 uVar4;
  
  if ((cmd_name == (char *)0x0) || (i == 0)) {
    line = 0xfd;
    iVar1 = 0x43;
  }
  else {
    if (*(int *)(cmd_name + 0x40) != 0) {
      uVar4 = 0xba;
      pcVar3 = "eng_ctrl.c";
      uVar2 = 0x1e;
      CRYPTO_lock((int)e,9,(char *)0x1e,(int)"eng_ctrl.c");
      iVar1 = *(int *)(cmd_name + 0x58);
      CRYPTO_lock((int)e,10,(char *)0x1e,(int)"eng_ctrl.c");
      if (iVar1 < 1) {
        ERR_put_error(0x26,0x8e,0x82,"eng_ctrl.c",0xbf);
      }
      else if (*(code **)(cmd_name + 0x40) == (code *)0x0) {
        ERR_put_error(0x26,0x8e,0x78,"eng_ctrl.c",0xd4);
      }
      else {
        if ((cmd_name[0x54] & 2U) == 0) {
          iVar1 = int_ctrl_helper_isra_1(i,uVar2,pcVar3,uVar4);
        }
        else {
          iVar1 = (**(code **)(cmd_name + 0x40))(cmd_name,0xd,0,i,0);
        }
        if (0 < iVar1) {
          iVar1 = ENGINE_ctrl((ENGINE *)cmd_name,iVar1,(long)p,f,(f *)cmd_optional);
          return (uint)(0 < iVar1);
        }
      }
    }
    if (in_stack_00000018 != 0) {
      ERR_clear_error();
      return 1;
    }
    line = 0x110;
    iVar1 = 0x89;
  }
  ERR_put_error(0x26,0xb2,iVar1,"eng_ctrl.c",line);
  return 0;
}

