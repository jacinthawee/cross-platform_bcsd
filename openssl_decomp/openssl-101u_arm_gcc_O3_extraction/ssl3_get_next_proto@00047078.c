
int ssl3_get_next_proto(int param_1)

{
  byte bVar1;
  int iVar2;
  void *__dest;
  uint __n;
  byte *pbVar3;
  int local_1c [2];
  
  if (*(int *)(*(int *)(param_1 + 0x58) + 0x41c) == 0) {
    ERR_put_error(0x14,0x132,0x164,"s3_srvr.c",0xe06);
    iVar2 = -1;
    *(undefined4 *)(param_1 + 0x34) = 5;
  }
  else {
    iVar2 = (**(code **)(*(int *)(param_1 + 8) + 0x30))(param_1,0x2210,0x2211,0x43,0x202,local_1c);
    if (local_1c[0] != 0) {
      if (*(int *)(*(int *)(param_1 + 0x58) + 0x180) == 0) {
        ERR_put_error(0x14,0x132,0x163,"s3_srvr.c",0xe1a);
        iVar2 = -1;
        *(undefined4 *)(param_1 + 0x34) = 5;
      }
      else {
        if (1 < iVar2) {
          pbVar3 = *(byte **)(param_1 + 0x40);
          bVar1 = *pbVar3;
          __n = (uint)bVar1;
          if (((int)(__n + 1) < *(int *)(param_1 + 0x44)) &&
             (*(int *)(param_1 + 0x44) == pbVar3[__n + 1] + __n + 2)) {
            __dest = CRYPTO_malloc(__n,"s3_srvr.c",0xe38);
            *(void **)(param_1 + 0x174) = __dest;
            if (__dest != (void *)0x0) {
              memcpy(__dest,pbVar3 + 1,__n);
              *(byte *)(param_1 + 0x178) = bVar1;
              return 1;
            }
            ERR_put_error(0x14,0x132,0x41,"s3_srvr.c",0xe3a);
            *(undefined4 *)(param_1 + 0x34) = 5;
            return 0;
          }
        }
        iVar2 = 0;
        *(undefined4 *)(param_1 + 0x34) = 5;
      }
    }
  }
  return iVar2;
}

