
undefined4
ssl3_send_finished(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4,
                  undefined4 param_5)

{
  undefined uVar1;
  undefined4 uVar2;
  size_t __n;
  int iVar3;
  int iVar4;
  undefined *puVar5;
  
  if (param_1[0xd] == param_2) {
    puVar5 = *(undefined **)(param_1[0xf] + 4);
    __n = (**(code **)(*(int *)(param_1[2] + 100) + 0x14))
                    (param_1,param_4,param_5,param_1[0x16] + 0x234);
    if (__n == 0) {
      return 0;
    }
    iVar4 = param_1[0x16];
    *(size_t *)(iVar4 + 0x2b4) = __n;
    memcpy(puVar5 + 4,(void *)(iVar4 + 0x234),__n);
    uVar1 = (undefined)__n;
    if (param_1[1] == 0x1000) {
      if (0x40 < (int)__n) {
        OpenSSLDie("s3_both.c",0xaf,"i <= EVP_MAX_MD_SIZE");
      }
      memcpy((void *)(param_1[0x16] + 0x394),(void *)(param_1[0x16] + 0x234),__n);
      *(undefined *)(param_1[0x16] + 0x3d4) = uVar1;
    }
    else {
      if (0x40 < (int)__n) {
        OpenSSLDie("s3_both.c",0xb6,"i <= EVP_MAX_MD_SIZE");
      }
      memcpy((void *)(param_1[0x16] + 0x3d5),(void *)(param_1[0x16] + 0x234),__n);
      *(undefined *)(param_1[0x16] + 0x415) = uVar1;
    }
    iVar4 = 0;
    puVar5[3] = uVar1;
    *puVar5 = 0x14;
    puVar5[1] = (char)(__n >> 0x10);
    iVar3 = __n + 4;
    puVar5[2] = (char)(__n >> 8);
    param_1[0x11] = iVar3;
    param_1[0xd] = param_3;
    param_1[0x12] = 0;
  }
  else {
    iVar4 = param_1[0x12];
    iVar3 = param_1[0x11];
  }
  iVar4 = ssl3_write_bytes(param_1,0x16,*(int *)(param_1[0xf] + 4) + iVar4,iVar3);
  if (iVar4 < 0) {
    uVar2 = 0xffffffff;
  }
  else {
    ssl3_finish_mac(param_1,*(int *)(param_1[0xf] + 4) + param_1[0x12],iVar4);
    if (iVar4 == param_1[0x11]) {
      uVar2 = 1;
      if ((code *)param_1[0x19] != (code *)0x0) {
        (*(code *)param_1[0x19])
                  (1,*param_1,0x16,*(undefined4 *)(param_1[0xf] + 4),iVar4 + param_1[0x12],param_1,
                   param_1[0x1a]);
        return 1;
      }
    }
    else {
      uVar2 = 0;
      param_1[0x11] = param_1[0x11] - iVar4;
      param_1[0x12] = iVar4 + param_1[0x12];
    }
  }
  return uVar2;
}

