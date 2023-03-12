
code * ssl_check_serverhello_tlsext(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  code *pcVar6;
  code *pcVar7;
  undefined4 local_14;
  
  iVar5 = *(int *)(*(int *)(param_1 + 0x58) + 0x344);
  local_14 = 0x70;
  if ((*(int *)(param_1 + 0x148) != 0) && (*(int *)(param_1 + 0x144) != 0)) {
    pcVar4 = *(char **)(*(int *)(param_1 + 0xc0) + 0xd8);
    if (((pcVar4 != (char *)0x0) && (iVar2 = *(int *)(*(int *)(param_1 + 0xc0) + 0xd4), iVar2 != 0))
       && ((((*(uint *)(iVar5 + 0xc) & 0xe0) != 0 || (*(int *)(iVar5 + 0x10) << 0x19 < 0)) &&
           (*pcVar4 != '\0')))) {
      pcVar3 = pcVar4 + iVar2;
      do {
        pcVar4 = pcVar4 + 1;
        if (pcVar4 == pcVar3) {
          ERR_put_error(0x14,0x118,0x9d,"t1_lib.c",0x7ff);
          return (code *)0xffffffff;
        }
      } while (*pcVar4 != '\0');
    }
  }
  pcVar6 = *(code **)(param_1 + 0xe4);
  if (((pcVar6 != (code *)0x0) && (pcVar7 = *(code **)(pcVar6 + 0x100), pcVar7 != (code *)0x0)) ||
     ((pcVar6 = *(code **)(param_1 + 0x170), pcVar7 = pcVar6, pcVar6 != (code *)0x0 &&
      (pcVar7 = *(code **)(pcVar6 + 0x100), pcVar7 != (code *)0x0)))) {
    pcVar7 = (code *)(*pcVar7)(param_1,&local_14,*(undefined4 *)(pcVar6 + 0x104));
  }
  if (((*(int *)(param_1 + 0x128) != -1) && (*(int *)(param_1 + 300) == 0)) &&
     ((iVar5 = *(int *)(param_1 + 0xe4), iVar5 != 0 &&
      (pcVar6 = *(code **)(iVar5 + 0x13c), pcVar6 != (code *)0x0)))) {
    if (*(void **)(param_1 + 0x138) != (void *)0x0) {
      CRYPTO_free(*(void **)(param_1 + 0x138));
      iVar5 = *(int *)(param_1 + 0xe4);
      *(undefined4 *)(param_1 + 0x138) = 0;
      pcVar6 = *(code **)(iVar5 + 0x13c);
    }
    uVar1 = *(undefined4 *)(iVar5 + 0x140);
    *(undefined4 *)(param_1 + 0x13c) = 0xffffffff;
    iVar5 = (*pcVar6)(param_1,uVar1);
    if (iVar5 == 0) {
      local_14 = 0x71;
      goto LAB_000565c8;
    }
    if (iVar5 < 0) {
      local_14 = 0x50;
      goto LAB_000565c8;
    }
  }
  if (pcVar7 != (code *)0x2) {
    if (pcVar7 != (code *)0x3) {
      if (pcVar7 == (code *)0x1) {
        ssl3_send_alert(param_1,1,local_14);
      }
      else {
        pcVar7 = (code *)0x1;
      }
      return pcVar7;
    }
    *(undefined4 *)(param_1 + 0x124) = 0;
    return (code *)0x1;
  }
LAB_000565c8:
  ssl3_send_alert(param_1,2);
  return (code *)0xffffffff;
}

