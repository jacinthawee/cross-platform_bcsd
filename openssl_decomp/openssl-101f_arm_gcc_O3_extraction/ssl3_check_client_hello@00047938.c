
undefined4 ssl3_check_client_hello(int param_1)

{
  undefined4 uVar1;
  uint *puVar2;
  int local_14;
  
  uVar1 = (**(code **)(*(int *)(param_1 + 8) + 0x30))
                    (param_1,0x2180,0x2181,0xffffffff,*(undefined4 *)(param_1 + 0x108),&local_14);
  if (local_14 != 0) {
    puVar2 = *(uint **)(param_1 + 0x58);
    uVar1 = 1;
    puVar2[0xd5] = 1;
    if (puVar2[0xd0] == 1) {
      if ((*puVar2 & 0x40) == 0) {
        if ((DH *)puVar2[0xd2] != (DH *)0x0) {
          DH_free((DH *)puVar2[0xd2]);
          puVar2 = *(uint **)(param_1 + 0x58);
          puVar2[0xd2] = 0;
        }
        if ((EC_KEY *)puVar2[0xd3] != (EC_KEY *)0x0) {
          EC_KEY_free((EC_KEY *)puVar2[0xd3]);
          puVar2 = *(uint **)(param_1 + 0x58);
          puVar2[0xd3] = 0;
        }
        *puVar2 = *puVar2 | 0x40;
        return 2;
      }
      ERR_put_error(0x14,0x130,0x15a,"s3_srvr.c",0x37b);
      uVar1 = 0xffffffff;
    }
  }
  return uVar1;
}
