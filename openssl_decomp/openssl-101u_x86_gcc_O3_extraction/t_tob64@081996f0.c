
char * __regparm3 t_tob64(char *param_1,byte *param_2,int param_3)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  byte bVar4;
  char *pcVar5;
  char *pcVar6;
  uint local_2c;
  int local_1c;
  
  local_1c = param_3 % 3;
  if (local_1c == 1) {
    bVar4 = *param_2;
    uVar3 = 0;
  }
  else if (local_1c == 2) {
    uVar3 = (uint)*param_2;
    bVar4 = param_2[1];
  }
  else {
    bVar4 = 0;
    uVar3 = 0;
  }
  param_2 = param_2 + local_1c;
  bVar1 = false;
  uVar2 = 0;
  pcVar5 = param_1;
  do {
    local_2c = (uint)bVar4;
    if ((uVar2 >> 2 != 0) || (bVar1)) {
      *pcVar5 = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz./"[uVar2 >> 2];
      uVar2 = (uVar2 & 3) << 4 | uVar3 >> 4;
      pcVar5 = pcVar5 + 1;
LAB_081997e0:
      *pcVar5 = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz./"[uVar2];
      uVar3 = (uVar3 & 0xf) << 2 | (uint)(bVar4 >> 6);
      pcVar6 = pcVar5 + 1;
LAB_081997ff:
      pcVar5 = pcVar6 + 1;
      *pcVar6 = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz./"[uVar3];
      local_2c = local_2c & 0x3f;
LAB_08199811:
      bVar1 = true;
      *pcVar5 = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz./"[local_2c];
      pcVar5 = pcVar5 + 1;
    }
    else {
      uVar2 = (uVar2 & 3) << 4 | uVar3 >> 4;
      if (uVar2 != 0) goto LAB_081997e0;
      uVar3 = (uVar3 & 0xf) << 2 | (uint)(bVar4 >> 6);
      pcVar6 = pcVar5;
      if (uVar3 != 0) goto LAB_081997ff;
      local_2c = (uint)(bVar4 & 0x3f);
      if ((bVar4 & 0x3f) != 0) goto LAB_08199811;
      bVar1 = false;
    }
    if (param_3 <= local_1c) {
      *pcVar5 = '\0';
      return param_1;
    }
    bVar4 = param_2[2];
    local_1c = local_1c + 3;
    uVar2 = (uint)*param_2;
    uVar3 = (uint)param_2[1];
    param_2 = param_2 + 3;
  } while( true );
}

