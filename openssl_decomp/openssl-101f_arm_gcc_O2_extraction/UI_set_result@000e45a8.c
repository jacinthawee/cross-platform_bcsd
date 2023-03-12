
int UI_set_result(UI *ui,UI_STRING *uis,char *result)

{
  size_t sVar1;
  char *pcVar2;
  char *__c;
  int reason;
  uint uVar3;
  byte *pbVar4;
  char *__s;
  char *__s_00;
  int line;
  char acStack_44 [16];
  char acStack_34 [16];
  int local_24;
  
  local_24 = __TMC_END__;
  sVar1 = strlen(result);
  *(uint *)(ui + 0x14) = *(uint *)(ui + 0x14) & 0xfffffffe;
  if (uis == (UI_STRING *)0x0) {
LAB_000e46d8:
    __c = (char *)0xffffffff;
  }
  else {
    uVar3 = *(uint *)uis;
    if (uVar3 != 0) {
      if (uVar3 < 3) {
        BIO_snprintf(acStack_44,0xd,"%d",*(undefined4 *)(uis + 0x10));
        BIO_snprintf(acStack_34,0xd,"%d",*(undefined4 *)(uis + 0x14));
        if ((int)sVar1 < *(int *)(uis + 0x10)) {
          *(uint *)(ui + 0x14) = *(uint *)(ui + 0x14) | 1;
          reason = 0x65;
          line = 0x365;
        }
        else {
          if ((int)sVar1 <= *(int *)(uis + 0x14)) {
            if (*(char **)(uis + 0xc) == (char *)0x0) {
              ERR_put_error(0x28,0x69,0x69,"ui_lib.c",0x376);
              __c = (char *)0xffffffff;
            }
            else {
              BUF_strlcpy(*(char **)(uis + 0xc),result,*(int *)(uis + 0x14) + 1);
              __c = (char *)0x0;
            }
            goto LAB_000e4670;
          }
          *(uint *)(ui + 0x14) = *(uint *)(ui + 0x14) | 1;
          line = 0x36d;
          reason = 100;
        }
        ERR_put_error(0x28,0x69,reason,"ui_lib.c",line);
        ERR_add_error_data(5,"You must type in ",acStack_44,&DAT_0016bfcc,acStack_34," characters");
        goto LAB_000e46d8;
      }
      if (uVar3 == 3) {
        if (*(undefined **)(uis + 0xc) == (undefined *)0x0) {
          ERR_put_error(0x28,0x69,0x69,"ui_lib.c",899);
          __c = (char *)0xffffffff;
          goto LAB_000e4670;
        }
        **(undefined **)(uis + 0xc) = 0;
        __c = (char *)(uint)(byte)*result;
        if (__c != (char *)0x0) {
          __s_00 = *(char **)(uis + 0x14);
          pbVar4 = (byte *)(result + 1);
          do {
            __c = strchr(__s_00,(int)__c);
            if (__c != (char *)0x0) {
              __c = (char *)0x0;
              **(char **)(uis + 0xc) = *__s_00;
              break;
            }
            __s = *(char **)(uis + 0x18);
            pcVar2 = strchr(__s,(uint)pbVar4[-1]);
            if (pcVar2 != (char *)0x0) {
              **(char **)(uis + 0xc) = *__s;
              break;
            }
            __c = (char *)(uint)*pbVar4;
            pbVar4 = pbVar4 + 1;
          } while (__c != (char *)0x0);
          goto LAB_000e4670;
        }
      }
    }
    __c = (char *)0x0;
  }
LAB_000e4670:
  if (local_24 != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (int)__c;
}

