
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
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_24 = *(int *)PTR___stack_chk_guard_006aabf0;
  if ((e == (ENGINE *)0x0) || (cmd_name == (char *)0x0)) {
    iVar4 = 0x43;
    iVar5 = 0x129;
  }
  else {
    if (*(int *)(e + 0x40) != 0) {
      (*(code *)PTR_CRYPTO_lock_006a926c)(9,0x1e,"eng_ctrl.c",0xbe);
      iVar5 = *(int *)(e + 0x58);
      (*(code *)PTR_CRYPTO_lock_006a926c)(10,0x1e,"eng_ctrl.c",0xc0);
      if (iVar5 < 1) {
        cmd_name = (char *)0x8e;
        ERR_put_error(0x26,0x8e,0x82,"eng_ctrl.c",0xc4);
      }
      else if (*(code **)(e + 0x40) == (code *)0x0) {
        cmd_name = (char *)0x8e;
        ERR_put_error(0x26,0x8e,0x78,"eng_ctrl.c",0xd9);
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
            ERR_put_error(0x26,0xaa,0x8a,"eng_ctrl.c",0xf1);
LAB_0051c16c:
            iVar4 = 0x86;
            iVar5 = 0x142;
          }
          else {
            if ((uVar2 & 7) == 0) goto LAB_0051c16c;
            uVar2 = ENGINE_ctrl(e,0x12,(long)i,(void *)0x0,(f *)0x0);
            if ((int)uVar2 < 0) {
              iVar4 = 0x6e;
              iVar5 = 0x14a;
            }
            else if ((uVar2 & 4) == 0) {
              if (arg == (char *)0x0) {
                iVar4 = 0x87;
                iVar5 = 0x164;
              }
              else {
                i_00 = 0;
                if ((uVar2 & 2) != 0) {
LAB_0051c230:
                  iVar5 = ENGINE_ctrl(e,(int)i,i_00,arg,(f *)0x0);
                  uVar2 = (uint)(0 < iVar5);
                  goto LAB_0051c0f8;
                }
                if ((uVar2 & 1) == 0) {
                  iVar4 = 0x6e;
                  iVar5 = 0x176;
                }
                else {
                  i_00 = (*(code *)PTR_strtol_006aaa68)(arg,&local_28,10);
                  if ((arg != local_28) && (*local_28 == '\0')) {
                    arg = (char *)0x0;
                    goto LAB_0051c230;
                  }
                  iVar4 = 0x85;
                  iVar5 = 0x17d;
                }
              }
            }
            else {
              if (arg == (char *)0x0) {
                arg = (char *)0x0;
                i_00 = 0;
                goto LAB_0051c230;
              }
              iVar4 = 0x88;
              iVar5 = 0x154;
            }
          }
          i = (char *)0xab;
          ERR_put_error(0x26,0xab,iVar4,"eng_ctrl.c",iVar5);
          uVar2 = 0;
          goto LAB_0051c0f8;
        }
      }
    }
    i = cmd_name;
    if (cmd_optional != 0) {
      ERR_clear_error();
      uVar2 = 1;
      goto LAB_0051c0f8;
    }
    iVar4 = 0x89;
    iVar5 = 0x13c;
  }
  i = (char *)0xab;
  ERR_put_error(0x26,0xab,iVar4,"eng_ctrl.c",iVar5);
  uVar2 = 0;
LAB_0051c0f8:
  if (local_24 != *(int *)puVar1) {
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    *(char **)(local_24 + 0x44) = i;
    return 1;
  }
  return uVar2;
}

