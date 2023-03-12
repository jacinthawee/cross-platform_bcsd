
undefined4
ssl_parse_clienthello_renegotiate_ext(int param_1,byte *param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  uint __n;
  int iVar2;
  
  if (param_3 < 1) {
    iVar2 = 0x9b;
  }
  else {
    __n = (uint)*param_2;
    if (param_3 == __n + 1) {
      iVar2 = *(int *)(param_1 + 0x58);
      if (__n == *(byte *)(iVar2 + 0x3d4)) {
        iVar1 = memcmp(param_2 + 1,(void *)(iVar2 + 0x394),__n);
        if (iVar1 == 0) {
          *(undefined4 *)(iVar2 + 0x418) = 1;
          return 1;
        }
        iVar2 = 0xb5;
      }
      else {
        iVar2 = 0xad;
      }
      ERR_put_error(0x14,300,0x151,"t1_reneg.c",iVar2);
      *param_4 = 0x28;
      return 0;
    }
    iVar2 = 0xa5;
  }
  ERR_put_error(0x14,300,0x150,"t1_reneg.c",iVar2);
  *param_4 = 0x2f;
  return 0;
}

