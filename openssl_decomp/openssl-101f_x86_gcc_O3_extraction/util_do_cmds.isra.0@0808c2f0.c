
void __regparm3 util_do_cmds_isra_0(ENGINE *param_1,_STACK *param_2,BIO *param_3)

{
  int iVar1;
  char *__s;
  char *pcVar2;
  int iVar3;
  int iVar4;
  int in_GS_OFFSET;
  char local_120 [256];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = sk_num(param_2);
  if (iVar1 < 0) {
    BIO_printf(param_3,"[Error]: internal stack error\n");
  }
  else {
    iVar4 = 0;
    if (iVar1 != 0) {
      do {
        while( true ) {
          __s = (char *)sk_value(param_2,iVar4);
          pcVar2 = strchr(__s,0x3a);
          if (pcVar2 == (char *)0x0) break;
          iVar3 = (int)pcVar2 - (int)__s;
          if (0xfe < iVar3) {
            BIO_printf(param_3,"[Error]: command name too long\n");
            goto LAB_0808c3f8;
          }
          __memcpy_chk(local_120,__s,iVar3,0x100);
          local_120[iVar3] = '\0';
          iVar3 = ENGINE_ctrl_cmd_string(param_1,local_120,pcVar2 + 1,0);
          if (iVar3 == 0) goto LAB_0808c340;
LAB_0808c3d6:
          iVar4 = iVar4 + 1;
          BIO_printf(param_3,"[Success]: %s\n",__s);
          if (iVar1 == iVar4) goto LAB_0808c3f8;
        }
        iVar3 = ENGINE_ctrl_cmd_string(param_1,__s,(char *)0x0,0);
        if (iVar3 != 0) goto LAB_0808c3d6;
LAB_0808c340:
        iVar4 = iVar4 + 1;
        BIO_printf(param_3,"[Failure]: %s\n",__s);
        ERR_print_errors(param_3);
      } while (iVar1 != iVar4);
    }
  }
LAB_0808c3f8:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

