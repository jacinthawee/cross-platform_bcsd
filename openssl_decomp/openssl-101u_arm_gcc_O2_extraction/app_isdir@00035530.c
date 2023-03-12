
uint app_isdir(char *param_1)

{
  int iVar1;
  uint uVar2;
  stat sStack_60;
  
  iVar1 = __xstat(3,param_1,&sStack_60);
  if (iVar1 == 0) {
    uVar2 = count_leading_zeroes((sStack_60.st_mode & 0xf000) - 0x4000);
    uVar2 = uVar2 >> 5;
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

