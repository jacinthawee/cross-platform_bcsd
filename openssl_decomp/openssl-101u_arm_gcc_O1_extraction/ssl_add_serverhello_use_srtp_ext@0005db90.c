
bool ssl_add_serverhello_use_srtp_ext
               (int param_1,undefined *param_2,undefined4 *param_3,int param_4)

{
  bool bVar1;
  undefined4 uVar2;
  
  if (param_2 == (undefined *)0x0) {
    *param_3 = 5;
    return false;
  }
  if (4 < param_4) {
    bVar1 = *(int *)(param_1 + 0x180) == 0;
    if (bVar1) {
      ERR_put_error(0x14,0x134,0x171,"d1_srtp.c",0x176);
    }
    else {
      *param_2 = 0;
      param_2[1] = 2;
      param_2[2] = (char)((uint)*(undefined4 *)(*(int *)(param_1 + 0x180) + 4) >> 8);
      uVar2 = *(undefined4 *)(*(int *)(param_1 + 0x180) + 4);
      param_2[4] = 0;
      param_2[3] = (char)uVar2;
      *param_3 = 5;
    }
    return bVar1;
  }
  ERR_put_error(0x14,0x134,0x16b,"d1_srtp.c",0x170);
  return true;
}

