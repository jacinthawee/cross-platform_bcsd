
int ssl_fill_hello_random(int param_1,int param_2,uchar *param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  time_t tVar3;
  
  if (param_4 < 4) {
    return 0;
  }
  if (param_2 == 0) {
    uVar1 = *(uint *)(param_1 + 0x104) >> 5;
  }
  else {
    uVar1 = *(uint *)(param_1 + 0x104) >> 6;
  }
  if ((uVar1 & 1) == 0) {
    iVar2 = RAND_bytes(param_3,param_4);
    return iVar2;
  }
  tVar3 = time((time_t *)0x0);
  param_3[3] = (uchar)tVar3;
  *param_3 = (uchar)((uint)tVar3 >> 0x18);
  param_3[1] = (uchar)((uint)tVar3 >> 0x10);
  param_3[2] = (uchar)((uint)tVar3 >> 8);
  iVar2 = RAND_bytes(param_3 + 4,param_4 + -4);
  return iVar2;
}

