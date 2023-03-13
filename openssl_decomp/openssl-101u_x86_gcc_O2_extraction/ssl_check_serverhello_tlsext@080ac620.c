
undefined4 ssl_check_serverhello_tlsext(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  int iVar5;
  code *pcVar6;
  char *pcVar7;
  int in_GS_OFFSET;
  undefined4 local_14;
  int local_10;
  
  local_14 = 0x70;
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if ((*(int *)(param_1 + 0x148) != 0) && (*(int *)(param_1 + 0x144) != 0)) {
    pcVar4 = *(char **)(*(int *)(param_1 + 0xc0) + 0xd8);
    if (((pcVar4 != (char *)0x0) && (iVar2 = *(int *)(*(int *)(param_1 + 0xc0) + 0xd4), iVar2 != 0))
       && ((iVar5 = *(int *)(*(int *)(param_1 + 0x58) + 0x344), (*(byte *)(iVar5 + 0xc) & 0xe0) != 0
           || ((*(uint *)(iVar5 + 0x10) & 0x40) != 0)))) {
      pcVar7 = pcVar4 + iVar2;
      cVar1 = *pcVar4;
      while (cVar1 != '\0') {
        pcVar4 = pcVar4 + 1;
        if (pcVar4 == pcVar7) {
          ERR_put_error(0x14,0x118,0x9d,"t1_lib.c",0x802);
          uVar3 = 0xffffffff;
          goto LAB_080ac6f6;
        }
        cVar1 = *pcVar4;
      }
    }
  }
  iVar2 = *(int *)(param_1 + 0xe4);
  if (((iVar2 == 0) || (pcVar6 = *(code **)(iVar2 + 0x100), pcVar6 == (code *)0x0)) &&
     ((iVar2 = *(int *)(param_1 + 0x170), iVar2 == 0 ||
      (pcVar6 = *(code **)(iVar2 + 0x100), pcVar6 == (code *)0x0)))) {
    CRYPTO_free(*(void **)(param_1 + 0x138));
    *(undefined4 *)(param_1 + 0x138) = 0;
    *(undefined4 *)(param_1 + 0x13c) = 0xffffffff;
    uVar3 = 1;
    if (((*(int *)(param_1 + 0x128) == -1) || (*(int *)(param_1 + 300) != 0)) ||
       (*(int *)(param_1 + 0x6c) != 0)) goto LAB_080ac6f6;
    iVar5 = *(int *)(param_1 + 0xe4);
    iVar2 = 0;
    if (iVar5 == 0) goto LAB_080ac6f6;
LAB_080ac7b9:
    if (*(code **)(iVar5 + 0x13c) == (code *)0x0) goto LAB_080ac6c3;
    iVar5 = (**(code **)(iVar5 + 0x13c))(param_1,*(undefined4 *)(iVar5 + 0x140));
    if (iVar5 == 0) {
      local_14 = 0x71;
    }
    else {
      if (-1 < iVar5) goto LAB_080ac6c3;
      local_14 = 0x50;
    }
  }
  else {
    iVar2 = (*pcVar6)(param_1,&local_14,*(undefined4 *)(iVar2 + 0x104));
    CRYPTO_free(*(void **)(param_1 + 0x138));
    *(undefined4 *)(param_1 + 0x138) = 0;
    *(undefined4 *)(param_1 + 0x13c) = 0xffffffff;
    if ((((*(int *)(param_1 + 0x128) != -1) && (*(int *)(param_1 + 300) == 0)) &&
        (*(int *)(param_1 + 0x6c) == 0)) && (iVar5 = *(int *)(param_1 + 0xe4), iVar5 != 0))
    goto LAB_080ac7b9;
LAB_080ac6c3:
    if (iVar2 != 2) {
      if (iVar2 == 3) {
        *(undefined4 *)(param_1 + 0x124) = 0;
        uVar3 = 1;
      }
      else {
        uVar3 = 1;
        if (iVar2 == 1) {
          ssl3_send_alert(param_1,1,local_14);
          uVar3 = 1;
        }
      }
      goto LAB_080ac6f6;
    }
  }
  ssl3_send_alert(param_1,2,local_14);
  uVar3 = 0xffffffff;
LAB_080ac6f6:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

