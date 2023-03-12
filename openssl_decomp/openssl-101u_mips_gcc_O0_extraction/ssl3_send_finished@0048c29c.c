
undefined4
ssl3_send_finished(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4,
                  undefined4 param_5)

{
  undefined uVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined *puVar7;
  
  if (param_1[0xd] == param_2) {
    puVar7 = *(undefined **)(param_1[0xf] + 4);
    iVar4 = (**(code **)(*(int *)(param_1[2] + 100) + 0x14))
                      (param_1,param_4,param_5,param_1[0x16] + 0x234);
    puVar2 = PTR_memcpy_006a9aec;
    if (iVar4 < 1) {
      return 0;
    }
    iVar3 = param_1[0x16];
    *(int *)(iVar3 + 0x2b4) = iVar4;
    (*(code *)puVar2)(puVar7 + 4,iVar3 + 0x234,iVar4);
    uVar1 = (undefined)iVar4;
    if (param_1[1] == 0x1000) {
      if (0x40 < iVar4) {
        (*(code *)PTR_OpenSSLDie_006a7c5c)("s3_both.c",0xb7,"i <= EVP_MAX_MD_SIZE");
      }
      (*(code *)PTR_memcpy_006a9aec)(param_1[0x16] + 0x394,param_1[0x16] + 0x234,iVar4);
      *(undefined *)(param_1[0x16] + 0x3d4) = uVar1;
    }
    else {
      if (0x40 < iVar4) {
        (*(code *)PTR_OpenSSLDie_006a7c5c)("s3_both.c",0xbb,"i <= EVP_MAX_MD_SIZE");
      }
      (*(code *)PTR_memcpy_006a9aec)(param_1[0x16] + 0x3d5,param_1[0x16] + 0x234,iVar4);
      *(undefined *)(param_1[0x16] + 0x415) = uVar1;
    }
    puVar7[3] = uVar1;
    iVar6 = iVar4 + 4;
    puVar7[1] = (char)((uint)iVar4 >> 0x10);
    *puVar7 = 0x14;
    iVar3 = 0;
    puVar7[2] = (char)((uint)iVar4 >> 8);
    param_1[0x11] = iVar6;
    param_1[0x12] = 0;
    param_1[0xd] = param_3;
  }
  else {
    iVar3 = param_1[0x12];
    iVar6 = param_1[0x11];
  }
  iVar4 = ssl3_write_bytes(param_1,0x16,*(int *)(param_1[0xf] + 4) + iVar3,iVar6);
  if (iVar4 < 0) {
    uVar5 = 0xffffffff;
  }
  else {
    ssl3_finish_mac(param_1,*(int *)(param_1[0xf] + 4) + param_1[0x12],iVar4);
    if (iVar4 == param_1[0x11]) {
      if ((code *)param_1[0x19] != (code *)0x0) {
        (*(code *)param_1[0x19])
                  (1,*param_1,0x16,*(undefined4 *)(param_1[0xf] + 4),iVar4 + param_1[0x12],param_1,
                   param_1[0x1a]);
        return 1;
      }
      uVar5 = 1;
    }
    else {
      uVar5 = 0;
      param_1[0x11] = param_1[0x11] - iVar4;
      param_1[0x12] = param_1[0x12] + iVar4;
    }
  }
  return uVar5;
}

