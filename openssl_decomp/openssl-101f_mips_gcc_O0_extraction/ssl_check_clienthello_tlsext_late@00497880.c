
undefined4
ssl_check_clienthello_tlsext_late
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  code *pcVar4;
  undefined *puVar5;
  
  puVar5 = &_gp;
  if (((*(int *)(param_1 + 0x128) != -1) && (*(int *)(param_1 + 0xe4) != 0)) &&
     (*(int *)(*(int *)(param_1 + 0xe4) + 0x13c) != 0)) {
    iVar1 = ssl_get_server_send_pkey();
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 300) = 0;
      return 1;
    }
    piVar3 = *(int **)(param_1 + 0x98);
    pcVar4 = *(code **)(*(int *)(param_1 + 0xe4) + 0x13c);
    uVar2 = *(undefined4 *)(*(int *)(param_1 + 0xe4) + 0x140);
    *piVar3 = iVar1;
    iVar1 = (*pcVar4)(param_1,uVar2,piVar3,param_4,puVar5);
    if (iVar1 == 2) {
      ssl3_send_alert(param_1,2,0x50);
      return 0xffffffff;
    }
    if (iVar1 != 3) {
      if (iVar1 != 0) {
        return 1;
      }
      if (*(int *)(param_1 + 0x138) != 0) {
        *(undefined4 *)(param_1 + 300) = 1;
        return 1;
      }
    }
  }
  *(undefined4 *)(param_1 + 300) = 0;
  return 1;
}

