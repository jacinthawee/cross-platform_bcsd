
undefined4 ssl_check_serverhello_tlsext(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  code *pcVar6;
  char *pcVar7;
  int in_GS_OFFSET;
  undefined4 local_14;
  int local_10;
  
  local_14 = 0x70;
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if ((*(int *)(param_1 + 0x148) != 0) && (*(int *)(param_1 + 0x144) != 0)) {
    pcVar5 = *(char **)(*(int *)(param_1 + 0xc0) + 0xd8);
    if (((pcVar5 != (char *)0x0) && (iVar3 = *(int *)(*(int *)(param_1 + 0xc0) + 0xd4), iVar3 != 0))
       && ((iVar2 = *(int *)(*(int *)(param_1 + 0x58) + 0x344), (*(byte *)(iVar2 + 0xc) & 0xe0) != 0
           || ((*(uint *)(iVar2 + 0x10) & 0x40) != 0)))) {
      pcVar7 = pcVar5 + iVar3;
      cVar1 = *pcVar5;
      while (cVar1 != '\0') {
        pcVar5 = pcVar5 + 1;
        if (pcVar7 == pcVar5) {
          ERR_put_error(0x14,0x118,0x9d,"t1_lib.c",0x7ff);
          uVar4 = 0xffffffff;
          goto LAB_080afd63;
        }
        cVar1 = *pcVar5;
      }
    }
  }
  iVar3 = *(int *)(param_1 + 0xe4);
  if ((iVar3 == 0) || (*(code **)(iVar3 + 0x100) == (code *)0x0)) {
    iVar2 = *(int *)(param_1 + 0x170);
    if ((iVar2 != 0) && (*(code **)(iVar2 + 0x100) != (code *)0x0)) {
      iVar2 = (**(code **)(iVar2 + 0x100))(param_1,&local_14,*(undefined4 *)(iVar2 + 0x104));
      goto LAB_080afc87;
    }
    uVar4 = 1;
    if (((*(int *)(param_1 + 0x128) == -1) || (*(int *)(param_1 + 300) != 0)) || (iVar3 == 0))
    goto LAB_080afd63;
    pcVar6 = *(code **)(iVar3 + 0x13c);
    iVar2 = 0;
    if (pcVar6 == (code *)0x0) goto LAB_080afd63;
LAB_080afcba:
    if (*(void **)(param_1 + 0x138) != (void *)0x0) {
      CRYPTO_free(*(void **)(param_1 + 0x138));
      iVar3 = *(int *)(param_1 + 0xe4);
      *(undefined4 *)(param_1 + 0x138) = 0;
      pcVar6 = *(code **)(iVar3 + 0x13c);
    }
    *(undefined4 *)(param_1 + 0x13c) = 0xffffffff;
    iVar3 = (*pcVar6)(param_1,*(undefined4 *)(iVar3 + 0x140));
    if (iVar3 == 0) {
      local_14 = 0x71;
    }
    else {
      if (-1 < iVar3) goto LAB_080afd30;
      local_14 = 0x50;
    }
  }
  else {
    iVar2 = (**(code **)(iVar3 + 0x100))(param_1,&local_14,*(undefined4 *)(iVar3 + 0x104));
LAB_080afc87:
    if (((*(int *)(param_1 + 0x128) != -1) && (*(int *)(param_1 + 300) == 0)) &&
       ((iVar3 = *(int *)(param_1 + 0xe4), iVar3 != 0 &&
        (pcVar6 = *(code **)(iVar3 + 0x13c), pcVar6 != (code *)0x0)))) goto LAB_080afcba;
LAB_080afd30:
    if (iVar2 != 2) {
      if (iVar2 == 3) {
        *(undefined4 *)(param_1 + 0x124) = 0;
        uVar4 = 1;
      }
      else {
        uVar4 = 1;
        if (iVar2 == 1) {
          ssl3_send_alert(param_1,1,local_14);
          uVar4 = 1;
        }
      }
      goto LAB_080afd63;
    }
  }
  ssl3_send_alert(param_1,2,local_14);
  uVar4 = 0xffffffff;
LAB_080afd63:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

