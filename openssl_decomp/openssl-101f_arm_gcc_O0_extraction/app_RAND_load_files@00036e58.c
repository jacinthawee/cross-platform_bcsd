
int app_RAND_load_files(byte *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  byte *pbVar2;
  undefined4 *puVar3;
  byte bVar4;
  int iVar5;
  
  iVar5 = 0;
  do {
    bVar4 = *param_1;
    pbVar2 = param_1;
    if (bVar4 != 0x3a && bVar4 != 0) {
      do {
        pbVar2 = pbVar2 + 1;
        bVar4 = *pbVar2;
      } while (bVar4 != 0x3a && bVar4 != 0);
    }
    *pbVar2 = 0;
    puVar3 = (undefined4 *)(uint)*param_1;
    if (puVar3 == (undefined4 *)0x0) break;
    iVar1 = RAND_egd((char *)param_1);
    if (iVar1 < 1) {
      iVar1 = RAND_load_file((char *)param_1,-1);
    }
    iVar5 = iVar5 + iVar1;
    param_1 = pbVar2 + 1;
  } while (bVar4 != 0);
  if (0x200 < iVar5) {
    param_3 = 1;
    puVar3 = &egdsocket;
  }
  if (0x200 < iVar5) {
    puVar3[1] = param_3;
  }
  return iVar5;
}

