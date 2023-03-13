
undefined4 aes_ccm_ctrl(int param_1,undefined4 param_2,uint param_3,void *param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x60);
  switch(param_2) {
  case 0:
    *(undefined4 *)(iVar1 + 0xf4) = 0;
    *(undefined4 *)(iVar1 + 0xf8) = 0;
    *(undefined4 *)(iVar1 + 0x104) = 8;
    *(undefined4 *)(iVar1 + 0x108) = 0xc;
    *(undefined4 *)(iVar1 + 0xfc) = 0;
    *(undefined4 *)(iVar1 + 0x100) = 0;
    return 1;
  default:
    return 0xffffffff;
  case 8:
    if (*(int *)(iVar1 + 0x138) == 0) {
      return 1;
    }
    if (*(int *)(iVar1 + 0x138) == iVar1) {
      *(int *)(*(int *)((int)param_4 + 0x60) + 0x138) = *(int *)((int)param_4 + 0x60);
      return 1;
    }
    break;
  case 9:
    param_3 = 0xf - param_3;
  case 0x14:
    if (param_3 - 2 < 7) {
      *(uint *)(iVar1 + 0x104) = param_3;
      return 1;
    }
    break;
  case 0x10:
    if (((*(int *)(param_1 + 8) != 0) && (*(int *)(iVar1 + 0xfc) != 0)) &&
       (iVar2 = CRYPTO_ccm128_tag(iVar1 + 0x10c,param_4,param_3), iVar2 != 0)) {
      *(undefined4 *)(iVar1 + 0xfc) = 0;
      *(undefined4 *)(iVar1 + 0xf8) = 0;
      *(undefined4 *)(iVar1 + 0x100) = 0;
      return 1;
    }
    break;
  case 0x11:
    if (((param_3 & 1) == 0) && (param_3 - 4 < 0xd)) {
      if (*(int *)(param_1 + 8) == 0) {
        if (param_4 != (void *)0x0) {
          *(undefined4 *)(iVar1 + 0xfc) = 1;
          memcpy((void *)(param_1 + 0x30),param_4,param_3);
        }
      }
      else if (param_4 != (void *)0x0) {
        return 0;
      }
      *(uint *)(iVar1 + 0x108) = param_3;
      return 1;
    }
  }
  return 0;
}

