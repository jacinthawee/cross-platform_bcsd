
bool ssl_parse_clienthello_renegotiate_ext
               (int param_1,byte *param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  int iVar2;
  
  if (param_3 < 1) {
    iVar2 = 0x9b;
  }
  else {
    if (*param_2 + 1 == param_3) {
      iVar2 = *(int *)(param_1 + 0x58);
      if ((uint)*(byte *)(iVar2 + 0x3d4) != (uint)*param_2) {
        ERR_put_error(0x14,300,0x151,"t1_reneg.c",0xad);
        *param_4 = 0x28;
        return false;
      }
      iVar1 = memcmp(param_2 + 1,(void *)(iVar2 + 0x394),(uint)*(byte *)(iVar2 + 0x3d4));
      if (iVar1 != 0) {
        ERR_put_error(0x14,300,0x151,"t1_reneg.c",0xb5);
        *param_4 = 0x28;
      }
      else {
        *(undefined4 *)(iVar2 + 0x418) = 1;
      }
      return iVar1 == 0;
    }
    iVar2 = 0xa5;
  }
  ERR_put_error(0x14,300,0x150,"t1_reneg.c",iVar2);
  *param_4 = 0x2f;
  return false;
}

