
undefined4 type_str(uint param_1,uint *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = *param_2;
  if ((uVar2 & 2) == 0) {
LAB_00609c74:
    uVar3 = uVar2;
    if (((uVar2 & 0x10) != 0) && (0x7f < param_1)) {
      uVar2 = uVar2 & 0xffffffef;
    }
joined_r0x00609c94:
    if (((uVar3 & 4) != 0) && (0xff < param_1)) {
      uVar2 = uVar2 & 0xfffffffb;
    }
  }
  else {
    if (0x7f < param_1) {
LAB_00609c70:
      uVar2 = uVar2 & 0xfffffffd;
      goto LAB_00609c74;
    }
    uVar3 = uVar2;
    if (((param_1 & 0xffffffdf) - 0x41 < 0x1a) || (param_1 - 0x30 < 10)) goto joined_r0x00609c94;
    if (param_1 != 0x20) {
      iVar1 = (*(code *)PTR_strchr_006aab34)("\'()+,-./:=?",param_1,param_3,param_4,&_gp);
      if (iVar1 == 0) goto LAB_00609c70;
      goto joined_r0x00609c94;
    }
  }
  if ((uVar2 & 0x800) != 0) {
    if (param_1 < 0x10000) goto LAB_00609c4c;
    uVar2 = uVar2 & 0xfffff7ff;
  }
  if (uVar2 == 0) {
    return 0xffffffff;
  }
LAB_00609c4c:
  *param_2 = uVar2;
  return 1;
}

