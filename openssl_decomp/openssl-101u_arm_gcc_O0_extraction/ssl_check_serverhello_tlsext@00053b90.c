
code * ssl_check_serverhello_tlsext(int param_1)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  code *pcVar5;
  code *pcVar6;
  undefined4 local_14 [2];
  
  iVar4 = *(int *)(*(int *)(param_1 + 0x58) + 0x344);
  local_14[0] = 0x70;
  if ((*(int *)(param_1 + 0x148) != 0) && (*(int *)(param_1 + 0x144) != 0)) {
    pcVar3 = *(char **)(*(int *)(param_1 + 0xc0) + 0xd8);
    if (((pcVar3 != (char *)0x0) && (iVar1 = *(int *)(*(int *)(param_1 + 0xc0) + 0xd4), iVar1 != 0))
       && ((((*(uint *)(iVar4 + 0xc) & 0xe0) != 0 || (*(int *)(iVar4 + 0x10) << 0x19 < 0)) &&
           (*pcVar3 != '\0')))) {
      pcVar2 = pcVar3 + iVar1;
      do {
        pcVar3 = pcVar3 + 1;
        if (pcVar3 == pcVar2) {
          ERR_put_error(0x14,0x118,0x9d,"t1_lib.c",0x802);
          return (code *)0xffffffff;
        }
      } while (*pcVar3 != '\0');
    }
  }
  pcVar5 = *(code **)(param_1 + 0xe4);
  if (((pcVar5 != (code *)0x0) && (pcVar6 = *(code **)(pcVar5 + 0x100), pcVar6 != (code *)0x0)) ||
     ((pcVar5 = *(code **)(param_1 + 0x170), pcVar6 = pcVar5, pcVar5 != (code *)0x0 &&
      (pcVar6 = *(code **)(pcVar5 + 0x100), pcVar6 != (code *)0x0)))) {
    pcVar6 = (code *)(*pcVar6)(param_1,local_14,*(undefined4 *)(pcVar5 + 0x104));
  }
  CRYPTO_free(*(void **)(param_1 + 0x138));
  *(undefined4 *)(param_1 + 0x138) = 0;
  *(undefined4 *)(param_1 + 0x13c) = 0xffffffff;
  if (((*(int *)(param_1 + 0x128) == -1) || (*(int *)(param_1 + 300) != 0)) ||
     ((*(int *)(param_1 + 0x6c) != 0 ||
      ((iVar4 = *(int *)(param_1 + 0xe4), iVar4 == 0 || (*(code **)(iVar4 + 0x13c) == (code *)0x0)))
      ))) {
LAB_00053bf2:
    if (pcVar6 != (code *)0x2) {
      if (pcVar6 != (code *)0x3) {
        if (pcVar6 == (code *)0x1) {
          ssl3_send_alert(param_1,1,local_14[0]);
        }
        else {
          pcVar6 = (code *)0x1;
        }
        return pcVar6;
      }
      *(undefined4 *)(param_1 + 0x124) = 0;
      return (code *)0x1;
    }
    ssl3_send_alert(param_1,2,local_14[0]);
  }
  else {
    iVar4 = (**(code **)(iVar4 + 0x13c))(param_1,*(undefined4 *)(iVar4 + 0x140));
    if (iVar4 == 0) {
      local_14[0] = 0x71;
    }
    else {
      if (-1 < iVar4) goto LAB_00053bf2;
      local_14[0] = 0x50;
    }
    ssl3_send_alert(param_1,2);
  }
  return (code *)0xffffffff;
}

