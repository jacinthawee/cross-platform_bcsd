
int UI_set_result(UI *ui,UI_STRING *uis,char *result)

{
  char cVar1;
  uint uVar2;
  char *__s;
  size_t sVar3;
  char *pcVar4;
  char *pcVar5;
  int iVar6;
  int in_GS_OFFSET;
  int line;
  char local_3a [13];
  char local_2d [13];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  sVar3 = strlen(result);
  *(uint *)(ui + 0x14) = *(uint *)(ui + 0x14) & 0xfffffffe;
  if (uis == (UI_STRING *)0x0) {
LAB_0818afd0:
    iVar6 = -1;
  }
  else {
    uVar2 = *(uint *)uis;
    if (uVar2 != 0) {
      if (uVar2 < 3) {
        BIO_snprintf(local_3a,0xd,"%d",*(undefined4 *)(uis + 0x10));
        BIO_snprintf(local_2d,0xd,"%d",*(undefined4 *)(uis + 0x14));
        if ((int)sVar3 < *(int *)(uis + 0x10)) {
          *(uint *)(ui + 0x14) = *(uint *)(ui + 0x14) | 1;
          line = 0x365;
          iVar6 = 0x65;
        }
        else {
          if ((int)sVar3 <= *(int *)(uis + 0x14)) {
            if (*(char **)(uis + 0xc) != (char *)0x0) {
              BUF_strlcpy(*(char **)(uis + 0xc),result,*(int *)(uis + 0x14) + 1);
              iVar6 = 0;
              goto LAB_0818af7d;
            }
            iVar6 = 0x376;
            goto LAB_0818afbd;
          }
          *(uint *)(ui + 0x14) = *(uint *)(ui + 0x14) | 1;
          line = 0x36d;
          iVar6 = 100;
        }
        ERR_put_error(0x28,0x69,iVar6,"ui_lib.c",line);
        ERR_add_error_data(5,"You must type in ",local_3a,&DAT_08230dd9,local_2d," characters");
        goto LAB_0818afd0;
      }
      if (uVar2 == 3) {
        if (*(undefined **)(uis + 0xc) == (undefined *)0x0) {
          iVar6 = 899;
LAB_0818afbd:
          ERR_put_error(0x28,0x69,0x69,"ui_lib.c",iVar6);
          goto LAB_0818afd0;
        }
        **(undefined **)(uis + 0xc) = 0;
        cVar1 = *result;
        if (cVar1 != '\0') {
          __s = *(char **)(uis + 0x14);
          do {
            pcVar5 = strchr(__s,(int)cVar1);
            if (pcVar5 != (char *)0x0) {
              **(char **)(uis + 0xc) = *__s;
              iVar6 = 0;
              goto LAB_0818af7d;
            }
            pcVar5 = *(char **)(uis + 0x18);
            pcVar4 = strchr(pcVar5,(int)*result);
            if (pcVar4 != (char *)0x0) {
              **(char **)(uis + 0xc) = *pcVar5;
              iVar6 = 0;
              goto LAB_0818af7d;
            }
            result = result + 1;
            cVar1 = *result;
          } while (cVar1 != '\0');
        }
      }
    }
    iVar6 = 0;
  }
LAB_0818af7d:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar6;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

