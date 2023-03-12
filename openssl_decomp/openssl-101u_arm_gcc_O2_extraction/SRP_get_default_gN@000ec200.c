
undefined ** SRP_get_default_gN(char *param_1)

{
  int iVar1;
  
  if (param_1 == (char *)0x0) {
    return &knowngN;
  }
  iVar1 = strcmp(knowngN,param_1);
  if (iVar1 != 0) {
    iVar1 = strcmp(PTR_DAT_001912c0,param_1);
    if (iVar1 == 0) {
      iVar1 = 1;
    }
    else {
      iVar1 = strcmp(PTR_DAT_001912cc,param_1);
      if (iVar1 == 0) {
        iVar1 = 2;
      }
      else {
        iVar1 = strcmp(PTR_DAT_001912d8,param_1);
        if (iVar1 == 0) {
          iVar1 = 3;
        }
        else {
          iVar1 = strcmp(PTR_DAT_001912e4,param_1);
          if (iVar1 == 0) {
            iVar1 = 4;
          }
          else {
            iVar1 = strcmp(PTR_DAT_001912f0,param_1);
            if (iVar1 == 0) {
              iVar1 = 5;
            }
            else {
              iVar1 = strcmp(PTR_DAT_001912fc,param_1);
              if (iVar1 != 0) {
                return (undefined **)0x0;
              }
              iVar1 = 6;
            }
          }
        }
      }
    }
  }
  return &knowngN + iVar1 * 3;
}

