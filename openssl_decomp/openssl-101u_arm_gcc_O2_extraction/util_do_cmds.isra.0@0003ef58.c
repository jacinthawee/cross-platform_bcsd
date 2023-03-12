
void util_do_cmds_isra_0(ENGINE *param_1,_STACK *param_2,BIO *param_3)

{
  int iVar1;
  char *__s;
  char *pcVar2;
  int unaff_r4;
  int iVar3;
  char acStack_12c [256];
  int local_2c;
  
  local_2c = __stack_chk_guard;
  iVar1 = sk_num(param_2);
  if (iVar1 < 0) {
    BIO_printf(param_3,"[Error]: internal stack error\n");
  }
  else {
    if (iVar1 != 0) {
      unaff_r4 = 0;
    }
    if (iVar1 != 0) {
      do {
        while( true ) {
          __s = (char *)sk_value(param_2,unaff_r4);
          pcVar2 = strchr(__s,0x3a);
          if (pcVar2 == (char *)0x0) break;
          iVar3 = (int)pcVar2 - (int)__s;
          if (0xfe < iVar3) {
            BIO_printf(param_3,"[Error]: command name too long\n");
            goto LAB_0003f002;
          }
          __memcpy_chk(acStack_12c,__s,iVar3,0x100);
          acStack_12c[iVar3] = '\0';
          iVar3 = ENGINE_ctrl_cmd_string(param_1,acStack_12c,pcVar2 + 1,0);
          if (iVar3 == 0) goto LAB_0003ef88;
          BIO_printf(param_3,"[Success]: %s\n",__s);
LAB_0003effa:
          unaff_r4 = unaff_r4 + 1;
          if (unaff_r4 == iVar1) goto LAB_0003f002;
        }
        iVar3 = ENGINE_ctrl_cmd_string(param_1,__s,(char *)0x0,0);
        if (iVar3 != 0) {
          BIO_printf(param_3,"[Success]: %s\n",__s);
          goto LAB_0003effa;
        }
LAB_0003ef88:
        BIO_printf(param_3,"[Failure]: %s\n",__s);
        ERR_print_errors(param_3);
        unaff_r4 = unaff_r4 + 1;
      } while (unaff_r4 != iVar1);
    }
  }
LAB_0003f002:
  if (local_2c == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

