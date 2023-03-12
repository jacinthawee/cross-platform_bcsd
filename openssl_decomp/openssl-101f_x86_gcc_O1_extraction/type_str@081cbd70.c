
undefined4 type_str(uint param_1,uint *param_2)

{
  char *pcVar1;
  uint uVar2;
  
  uVar2 = *param_2;
  if ((uVar2 & 2) == 0) {
LAB_081cbdc3:
    if (((uVar2 & 0x10) != 0) && (0x7f < param_1)) {
      uVar2 = uVar2 & 0xffffffef;
    }
  }
  else if ((0x7f < param_1) ||
          ((((0x19 < (param_1 & 0xffffffdf) - 0x41 && (9 < param_1 - 0x30)) && (param_1 != 0x20)) &&
           (pcVar1 = strchr("\'()+,-./:=?",param_1), pcVar1 == (char *)0x0)))) {
    uVar2 = uVar2 & 0xfffffffd;
    goto LAB_081cbdc3;
  }
  if (((uVar2 & 4) != 0) && (0xff < param_1)) {
    uVar2 = uVar2 & 0xfffffffb;
  }
  if ((uVar2 & 0x800) != 0) {
    if (param_1 < 0x10000) goto LAB_081cbdfd;
    uVar2 = uVar2 & 0xfffff7ff;
  }
  if (uVar2 == 0) {
    return 0xffffffff;
  }
LAB_081cbdfd:
  *param_2 = uVar2;
  return 1;
}

