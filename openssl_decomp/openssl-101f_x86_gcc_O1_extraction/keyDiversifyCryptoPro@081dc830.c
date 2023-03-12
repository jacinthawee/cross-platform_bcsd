
void keyDiversifyCryptoPro(undefined4 param_1,int *param_2,byte *param_3,int *param_4)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int in_GS_OFFSET;
  undefined local_28;
  undefined local_27;
  undefined local_26;
  undefined local_25;
  undefined local_24;
  undefined local_23;
  undefined local_22;
  undefined local_21;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  *param_4 = *param_2;
  param_4[1] = param_2[1];
  param_4[2] = param_2[2];
  param_4[3] = param_2[3];
  param_4[4] = param_2[4];
  param_4[5] = param_2[5];
  param_4[6] = param_2[6];
  param_4[7] = param_2[7];
  pbVar1 = param_3 + 8;
  do {
    bVar2 = *param_3;
    iVar3 = *param_4;
    iVar4 = 0;
    if ((bVar2 & 1) == 0) {
      iVar3 = 0;
      iVar4 = *param_4;
    }
    if ((bVar2 & 2) == 0) {
      iVar4 = iVar4 + param_4[1];
      iVar5 = param_4[2];
      if ((bVar2 & 4) == 0) goto LAB_081dc89e;
LAB_081dc973:
      iVar3 = iVar3 + iVar5;
      iVar5 = param_4[3];
      if ((bVar2 & 8) != 0) goto LAB_081dc981;
LAB_081dc8ac:
      iVar4 = iVar4 + iVar5;
      iVar5 = param_4[4];
      if ((bVar2 & 0x10) == 0) goto LAB_081dc8ba;
LAB_081dc98f:
      iVar3 = iVar3 + iVar5;
      iVar5 = param_4[5];
      if ((bVar2 & 0x20) != 0) goto LAB_081dc99d;
LAB_081dc8c8:
      iVar4 = iVar4 + iVar5;
      iVar5 = param_4[6];
      if ((bVar2 & 0x40) == 0) goto LAB_081dc8d6;
LAB_081dc9ab:
      iVar3 = iVar3 + iVar5;
      iVar5 = param_4[7];
      if ((char)bVar2 < '\0') goto LAB_081dc9b8;
LAB_081dc8e3:
      iVar4 = iVar4 + iVar5;
    }
    else {
      iVar3 = iVar3 + param_4[1];
      iVar5 = param_4[2];
      if ((bVar2 & 4) != 0) goto LAB_081dc973;
LAB_081dc89e:
      iVar4 = iVar4 + iVar5;
      iVar5 = param_4[3];
      if ((bVar2 & 8) == 0) goto LAB_081dc8ac;
LAB_081dc981:
      iVar3 = iVar3 + iVar5;
      iVar5 = param_4[4];
      if ((bVar2 & 0x10) != 0) goto LAB_081dc98f;
LAB_081dc8ba:
      iVar4 = iVar4 + iVar5;
      iVar5 = param_4[5];
      if ((bVar2 & 0x20) == 0) goto LAB_081dc8c8;
LAB_081dc99d:
      iVar3 = iVar3 + iVar5;
      iVar5 = param_4[6];
      if ((bVar2 & 0x40) != 0) goto LAB_081dc9ab;
LAB_081dc8d6:
      iVar4 = iVar4 + iVar5;
      iVar5 = param_4[7];
      if (-1 < (char)bVar2) goto LAB_081dc8e3;
LAB_081dc9b8:
      iVar3 = iVar3 + iVar5;
    }
    local_28 = (undefined)iVar3;
    local_24 = (undefined)iVar4;
    param_3 = param_3 + 1;
    local_27 = (undefined)((uint)iVar3 >> 8);
    local_25 = (undefined)((uint)iVar3 >> 0x18);
    local_26 = (undefined)((uint)iVar3 >> 0x10);
    local_23 = (undefined)((uint)iVar4 >> 8);
    local_21 = (undefined)((uint)iVar4 >> 0x18);
    local_22 = (undefined)((uint)iVar4 >> 0x10);
    gost_key(param_1,param_4);
    gost_enc_cfb(param_1,&local_28,param_4,param_4,4);
    if (param_3 == pbVar1) {
      if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
        return;
      }
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
  } while( true );
}

