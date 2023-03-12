
undefined4 ssl_check_clienthello_tlsext_late(int param_1)

{
  int iVar1;
  
  if (((*(int *)(param_1 + 0x128) != -1) && (*(int *)(param_1 + 0xe4) != 0)) &&
     (*(int *)(*(int *)(param_1 + 0xe4) + 0x13c) != 0)) {
    iVar1 = ssl_get_server_send_pkey(param_1);
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 300) = 0;
      return 1;
    }
    **(int **)(param_1 + 0x98) = iVar1;
    iVar1 = (**(code **)(*(int *)(param_1 + 0xe4) + 0x13c))
                      (param_1,*(undefined4 *)(*(int *)(param_1 + 0xe4) + 0x140));
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

