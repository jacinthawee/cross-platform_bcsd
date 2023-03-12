
int ENGINE_ctrl_cmd_string(ENGINE *e,char *cmd_name,char *arg,int cmd_optional)

{
  undefined *puVar1;
  char *i;
  uint uVar2;
  char *pcVar3;
  int iVar4;
  long i_00;
  int iVar5;
  char *local_28;
  int local_24;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_24 = *(int *)PTR___stack_chk_guard_006a9ae8;
  if ((e == (ENGINE *)0x0) || (cmd_name == (char *)0x0)) {
    iVar4 = 0x43;
    iVar5 = 0x124;
  }
  else {
    if (*(int *)(e + 0x40) != 0) {
      (*(code *)PTR_CRYPTO_lock_006a8144)(9,0x1e,"eng_ctrl.c",0xba);
      iVar5 = *(int *)(e + 0x58);
      (*(code *)PTR_CRYPTO_lock_006a8144)(10,0x1e,"eng_ctrl.c",0xbc);
      if (iVar5 < 1) {
        cmd_name = (char *)0x8e;
        ERR_put_error(0x26,0x8e,0x82,"eng_ctrl.c",0xbf);
      }
      else if (*(code **)(e + 0x40) == (code *)0x0) {
        cmd_name = (char *)0x8e;
        ERR_put_error(0x26,0x8e,0x78,"eng_ctrl.c",0xd4);
      }
      else {
        if ((*(uint *)(e + 0x54) & 2) == 0) {
          pcVar3 = &DAT_0000000d;
          i = (char *)int_ctrl_helper_isra_1(e + 0x50,0xd,0,cmd_name);
        }
        else {
          pcVar3 = &DAT_0000000d;
          i = (char *)(**(code **)(e + 0x40))(e,0xd,0,cmd_name,0);
        }
        cmd_name = pcVar3;
        if (0 < (int)i) {
          uVar2 = ENGINE_ctrl(e,0x12,(long)i,(void *)0x0,(f *)0x0);
          if ((int)uVar2 < 0) {
            ERR_put_error(0x26,0xaa,0x8a,"eng_ctrl.c",0xed);
LAB_0051a27c:
            iVar4 = 0x86;
            iVar5 = 0x13c;
          }
          else {
            if ((uVar2 & 7) == 0) goto LAB_0051a27c;
            uVar2 = ENGINE_ctrl(e,0x12,(long)i,(void *)0x0,(f *)0x0);
            if ((int)uVar2 < 0) {
              iVar4 = 0x6e;
              iVar5 = 0x146;
            }
            else if ((uVar2 & 4) == 0) {
              if (arg == (char *)0x0) {
                iVar4 = 0x87;
                iVar5 = 0x15f;
              }
              else {
                i_00 = 0;
                if ((uVar2 & 2) != 0) {
LAB_0051a340:
                  iVar5 = ENGINE_ctrl(e,(int)i,i_00,arg,(f *)0x0);
                  uVar2 = (uint)(0 < iVar5);
                  goto LAB_0051a208;
                }
                if ((uVar2 & 1) == 0) {
                  iVar4 = 0x6e;
                  iVar5 = 0x171;
                }
                else {
                  i_00 = (*(code *)PTR_strtol_006a9958)(arg,&local_28,10);
                  if ((arg != local_28) && (*local_28 == '\0')) {
                    arg = (char *)0x0;
                    goto LAB_0051a340;
                  }
                  iVar4 = 0x85;
                  iVar5 = 0x177;
                }
              }
            }
            else {
              if (arg == (char *)0x0) {
                arg = (char *)0x0;
                i_00 = 0;
                goto LAB_0051a340;
              }
              iVar4 = 0x88;
              iVar5 = 0x14f;
            }
          }
          i = (char *)0xab;
          ERR_put_error(0x26,0xab,iVar4,"eng_ctrl.c",iVar5);
          uVar2 = 0;
          goto LAB_0051a208;
        }
      }
    }
    i = cmd_name;
    if (cmd_optional != 0) {
      ERR_clear_error();
      uVar2 = 1;
      goto LAB_0051a208;
    }
    iVar4 = 0x89;
    iVar5 = 0x137;
  }
  i = (char *)0xab;
  ERR_put_error(0x26,0xab,iVar4,"eng_ctrl.c",iVar5);
  uVar2 = 0;
LAB_0051a208:
  if (local_24 != *(int *)puVar1) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    *(char **)(local_24 + 0x44) = i;
    return 1;
  }
  return uVar2;
}

