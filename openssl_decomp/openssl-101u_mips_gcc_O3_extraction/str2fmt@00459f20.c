
undefined4 str2fmt(char *param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  
  if (param_1 == (char *)0x0) {
    return 0;
  }
  uVar4 = (uint)*param_1;
  uVar3 = uVar4 & 0xffffffdf;
  if (uVar3 != 0x44) {
    if (uVar3 == 0x54) {
      uVar2 = 2;
    }
    else if (uVar3 == 0x4e) {
      uVar2 = 4;
    }
    else if (uVar3 == 0x53) {
      uVar2 = 6;
    }
    else if (uVar3 == 0x4d) {
      uVar2 = 0xb;
    }
    else if ((uVar4 == 0x31) ||
            (iVar1 = (*(code *)PTR_strcmp_006a9b18)(param_1,"PKCS12"), iVar1 == 0)) {
      uVar2 = 5;
    }
    else {
      iVar1 = (*(code *)PTR_strcmp_006a9b18)(param_1,"pkcs12");
      uVar2 = 5;
      if (((iVar1 != 0) &&
          (((((uVar4 & 0xff) != 0x50 && ((uVar4 & 0xff) != 0x70)) || (param_1[1] != '1')) ||
           ((param_1[2] != '2' || (uVar2 = 5, param_1[3] != '\0')))))) && (uVar2 = 7, uVar3 != 0x45)
         ) {
        if (uVar3 == 0x50) {
          uVar2 = 0xc;
          if ((param_1[1] & 0xdfU) != 0x56) {
            uVar2 = 3;
          }
        }
        else {
          uVar2 = 0;
        }
      }
    }
    return uVar2;
  }
  return 1;
}

