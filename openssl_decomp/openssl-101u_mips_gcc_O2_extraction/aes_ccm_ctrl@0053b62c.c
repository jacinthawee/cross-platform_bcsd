
undefined4 aes_ccm_ctrl(int param_1,undefined4 param_2,uint param_3,int param_4)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  
  puVar1 = PTR_memcpy_006a9aec;
  iVar3 = *(int *)(param_1 + 0x60);
  switch(param_2) {
  case 0:
    *(undefined4 *)(iVar3 + 0xf4) = 0;
    *(undefined4 *)(iVar3 + 0x104) = 8;
    *(undefined4 *)(iVar3 + 0xf8) = 0;
    *(undefined4 *)(iVar3 + 0xfc) = 0;
    *(undefined4 *)(iVar3 + 0x108) = 0xc;
    *(undefined4 *)(iVar3 + 0x100) = 0;
    return 1;
  default:
    return 0xffffffff;
  case 8:
    if (*(int *)(iVar3 + 0x13c) == 0) {
      return 1;
    }
    if (*(int *)(iVar3 + 0x13c) == iVar3) {
      *(int *)(*(int *)(param_4 + 0x60) + 0x13c) = *(int *)(param_4 + 0x60);
      return 1;
    }
    break;
  case 9:
    param_3 = 0xf - param_3;
  case 0x14:
    if (param_3 - 2 < 7) {
      *(uint *)(iVar3 + 0x104) = param_3;
      return 1;
    }
    break;
  case 0x10:
    if (*(int *)(param_1 + 8) == 0) {
      return 0;
    }
    if (*(int *)(iVar3 + 0xfc) == 0) {
      return 0;
    }
    iVar2 = (*(code *)PTR_CRYPTO_ccm128_tag_006a8a40)(iVar3 + 0x110,param_4);
    if (iVar2 != 0) {
      *(undefined4 *)(iVar3 + 0xfc) = 0;
      *(undefined4 *)(iVar3 + 0xf8) = 0;
      *(undefined4 *)(iVar3 + 0x100) = 0;
      return 1;
    }
    break;
  case 0x11:
    if ((param_3 & 1) == 0) {
      if (0xc < param_3 - 4) {
        return 0;
      }
      if (*(int *)(param_1 + 8) == 0) {
        if (param_4 != 0) {
          *(undefined4 *)(iVar3 + 0xfc) = 1;
          (*(code *)puVar1)(param_1 + 0x30,param_4,param_3,param_4,&_gp);
        }
        *(uint *)(iVar3 + 0x108) = param_3;
        return 1;
      }
      if (param_4 == 0) {
        *(uint *)(iVar3 + 0x108) = param_3;
        return 1;
      }
    }
  }
  return 0;
}

