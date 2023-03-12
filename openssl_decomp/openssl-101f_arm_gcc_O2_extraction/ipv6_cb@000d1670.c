
undefined4 ipv6_cb(byte *param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  
  iVar5 = *(int *)(param_3 + 0x10);
  if (iVar5 != 0x10) {
    if (param_2 == 0) {
      if (*(int *)(param_3 + 0x14) == -1) {
        *(int *)(param_3 + 0x14) = iVar5;
      }
      else if (iVar5 != *(int *)(param_3 + 0x14)) {
        return 0;
      }
      *(int *)(param_3 + 0x18) = *(int *)(param_3 + 0x18) + 1;
      return 1;
    }
    if (param_2 < 5) {
      uVar4 = 0;
      do {
        uVar3 = (uint)*param_1;
        uVar2 = uVar4 << 4;
        uVar4 = uVar3 - 0x30 | uVar2;
        if (9 < (uVar3 - 0x30 & 0xff)) {
          iVar1 = -0x57;
          if (uVar3 - 0x41 < 6) {
            iVar1 = -0x37;
          }
          uVar4 = uVar3 + iVar1 | uVar2;
          if ((5 < uVar3 - 0x41) && (5 < uVar3 - 0x61)) {
            return 0;
          }
        }
        param_2 = param_2 + -1;
        param_1 = param_1 + 1;
        if (param_2 == 0) {
          *(char *)(param_3 + iVar5) = (char)(uVar4 >> 8);
          *(char *)(param_3 + iVar5 + 1) = (char)uVar4;
          *(int *)(param_3 + 0x10) = *(int *)(param_3 + 0x10) + 2;
          return 1;
        }
      } while( true );
    }
    if ((((iVar5 < 0xd) && (param_1[param_2] == 0)) &&
        (iVar1 = __isoc99_sscanf(param_1,"%d.%d.%d.%d",&local_28,&local_24,&local_20,&local_1c),
        iVar1 == 4)) &&
       (((local_28 < 0x100 && (local_24 < 0x100)) && ((local_20 < 0x100 && (local_1c < 0x100)))))) {
      iVar1 = param_3 + iVar5;
      *(char *)(param_3 + iVar5) = (char)local_28;
      *(char *)(iVar1 + 1) = (char)local_24;
      *(char *)(iVar1 + 2) = (char)local_20;
      *(char *)(iVar1 + 3) = (char)local_1c;
      *(int *)(param_3 + 0x10) = *(int *)(param_3 + 0x10) + 4;
      return 1;
    }
  }
  return 0;
}

