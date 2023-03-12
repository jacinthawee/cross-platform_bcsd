
undefined1 * SRP_get_default_gN(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    return knowngN;
  }
  iVar1 = (*(code *)PTR_strcmp_006a9b18)(knowngN._0_4_,param_1);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = (*(code *)PTR_strcmp_006a9b18)(knowngN._12_4_,param_1);
    if (iVar1 == 0) {
      iVar1 = 1;
    }
    else {
      iVar1 = (*(code *)PTR_strcmp_006a9b18)(knowngN._24_4_,param_1);
      if (iVar1 == 0) {
        iVar1 = 2;
      }
      else {
        iVar1 = (*(code *)PTR_strcmp_006a9b18)(knowngN._36_4_,param_1);
        if (iVar1 == 0) {
          iVar1 = 3;
        }
        else {
          iVar1 = (*(code *)PTR_strcmp_006a9b18)(knowngN._48_4_,param_1);
          if (iVar1 == 0) {
            iVar1 = 4;
          }
          else {
            iVar1 = (*(code *)PTR_strcmp_006a9b18)(knowngN._60_4_,param_1);
            if (iVar1 == 0) {
              iVar1 = 5;
            }
            else {
              iVar1 = (*(code *)PTR_strcmp_006a9b18)(knowngN._72_4_,param_1);
              if (iVar1 != 0) {
                return (undefined1 *)0x0;
              }
              iVar1 = 6;
            }
          }
        }
      }
    }
  }
  return knowngN + iVar1 * 0xc;
}

