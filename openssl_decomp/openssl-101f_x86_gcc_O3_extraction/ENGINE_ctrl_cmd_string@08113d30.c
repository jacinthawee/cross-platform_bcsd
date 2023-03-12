
int ENGINE_ctrl_cmd_string(ENGINE *e,char *cmd_name,char *arg,int cmd_optional)

{
  int iVar1;
  uint uVar2;
  int in_GS_OFFSET;
  long i;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  undefined4 uVar6;
  char *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = 0;
  if ((e == (ENGINE *)0x0) || (cmd_name == (char *)0x0)) {
    iVar3 = 0x129;
    iVar1 = 0x43;
    goto LAB_08113e72;
  }
  if (*(int *)(e + 0x40) == 0) {
LAB_08113e58:
    if (cmd_optional != 0) {
      ERR_clear_error();
      uVar2 = 1;
      goto LAB_08113e83;
    }
    iVar3 = 0x13c;
    iVar1 = 0x89;
  }
  else {
    uVar6 = 0xbe;
    pcVar5 = "eng_ctrl.c";
    uVar4 = 0x1e;
    CRYPTO_lock(0,9,(char *)0x1e,(int)"eng_ctrl.c");
    iVar3 = *(int *)(e + 0x58);
    CRYPTO_lock(iVar1,10,(char *)0x1e,(int)"eng_ctrl.c");
    if (iVar3 < 1) {
      ERR_put_error(0x26,0x8e,0x82,"eng_ctrl.c",0xc4);
      goto LAB_08113e58;
    }
    if (*(code **)(e + 0x40) == (code *)0x0) {
      ERR_put_error(0x26,0x8e,0x78,"eng_ctrl.c",0xd9);
      goto LAB_08113e58;
    }
    if (((byte)e[0x54] & 2) == 0) {
      iVar1 = int_ctrl_helper_isra_1(cmd_name,uVar4,pcVar5,uVar6);
    }
    else {
      iVar1 = (**(code **)(e + 0x40))(e,0xd,0,cmd_name,0);
    }
    if (iVar1 < 1) goto LAB_08113e58;
    uVar2 = ENGINE_ctrl(e,0x12,iVar1,(void *)0x0,(f *)0x0);
    if ((int)uVar2 < 0) {
      ERR_put_error(0x26,0xaa,0x8a,"eng_ctrl.c",0xf1);
LAB_08113ef0:
      iVar3 = 0x142;
      iVar1 = 0x86;
    }
    else {
      if ((uVar2 & 7) == 0) goto LAB_08113ef0;
      uVar2 = ENGINE_ctrl(e,0x12,iVar1,(void *)0x0,(f *)0x0);
      if ((int)uVar2 < 0) {
        iVar3 = 0x14a;
        iVar1 = 0x6e;
      }
      else if ((uVar2 & 4) == 0) {
        if (arg == (char *)0x0) {
          iVar3 = 0x164;
          iVar1 = 0x87;
        }
        else {
          if ((uVar2 & 2) != 0) {
            i = 0;
LAB_08113fa0:
            iVar1 = ENGINE_ctrl(e,iVar1,i,arg,(f *)0x0);
            uVar2 = (uint)(0 < iVar1);
            goto LAB_08113e83;
          }
          if ((uVar2 & 1) == 0) {
            iVar3 = 0x176;
            iVar1 = 0x6e;
          }
          else {
            i = strtol(arg,&local_24,10);
            if ((arg != local_24) && (*local_24 == '\0')) {
              arg = (char *)0x0;
              goto LAB_08113fa0;
            }
            iVar3 = 0x17d;
            iVar1 = 0x85;
          }
        }
      }
      else {
        if (arg == (char *)0x0) {
          arg = (char *)0x0;
          i = 0;
          goto LAB_08113fa0;
        }
        iVar3 = 0x154;
        iVar1 = 0x88;
      }
    }
  }
LAB_08113e72:
  ERR_put_error(0x26,0xab,iVar1,"eng_ctrl.c",iVar3);
  uVar2 = 0;
LAB_08113e83:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

