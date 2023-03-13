
undefined4
ssl3_send_finished(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4,
                  undefined4 param_5)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  size_t __n;
  int iVar4;
  undefined uVar5;
  
  if (param_1[0xd] == param_2) {
    puVar1 = *(undefined **)(param_1[0xf] + 4);
    __n = (**(code **)(*(int *)(param_1[2] + 100) + 0x14))
                    (param_1,param_4,param_5,param_1[0x16] + 0x234);
    if ((int)__n < 1) {
      return 0;
    }
    iVar2 = param_1[0x16];
    *(size_t *)(iVar2 + 0x2b4) = __n;
    memcpy(puVar1 + 4,(void *)(iVar2 + 0x234),__n);
    uVar5 = (undefined)__n;
    if (param_1[1] == 0x1000) {
      if (0x40 < (int)__n) {
        OpenSSLDie("s3_both.c",0xb7,"i <= EVP_MAX_MD_SIZE");
      }
      memcpy((void *)(param_1[0x16] + 0x394),(void *)(param_1[0x16] + 0x234),__n);
      *(undefined *)(param_1[0x16] + 0x3d4) = uVar5;
    }
    else {
      if (0x40 < (int)__n) {
        OpenSSLDie("s3_both.c",0xbb,"i <= EVP_MAX_MD_SIZE");
      }
      memcpy((void *)(param_1[0x16] + 0x3d5),(void *)(param_1[0x16] + 0x234),__n);
      *(undefined *)(param_1[0x16] + 0x415) = uVar5;
    }
    *puVar1 = 0x14;
    puVar1[3] = uVar5;
    puVar1[1] = (char)(__n >> 0x10);
    iVar2 = __n + 4;
    puVar1[2] = (char)(__n >> 8);
    param_1[0x11] = iVar2;
    param_1[0x12] = 0;
    param_1[0xd] = param_3;
    iVar4 = 0;
  }
  else {
    iVar2 = param_1[0x11];
    iVar4 = param_1[0x12];
  }
  iVar2 = ssl3_write_bytes(param_1,0x16,iVar4 + *(int *)(param_1[0xf] + 4),iVar2);
  if (iVar2 < 0) {
    uVar3 = 0xffffffff;
  }
  else {
    ssl3_finish_mac(param_1,param_1[0x12] + *(int *)(param_1[0xf] + 4),iVar2);
    if (iVar2 == param_1[0x11]) {
      uVar3 = 1;
      if ((code *)param_1[0x19] != (code *)0x0) {
        (*(code *)param_1[0x19])
                  (1,*param_1,0x16,*(undefined4 *)(param_1[0xf] + 4),iVar2 + param_1[0x12],param_1,
                   param_1[0x1a]);
        return 1;
      }
    }
    else {
      param_1[0x12] = param_1[0x12] + iVar2;
      param_1[0x11] = param_1[0x11] - iVar2;
      uVar3 = 0;
    }
  }
  return uVar3;
}

