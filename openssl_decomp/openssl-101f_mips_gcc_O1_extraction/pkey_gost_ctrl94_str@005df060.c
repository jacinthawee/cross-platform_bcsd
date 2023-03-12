
int pkey_gost_ctrl94_str(undefined4 param_1,undefined4 param_2,byte *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  iVar1 = (*(code *)PTR_strcmp_006aac20)(param_2,"paramset");
  if (iVar1 == 0) {
    if (param_3 != (byte *)0x0) {
      iVar2 = (*(code *)PTR_strlen_006aab30)(param_3);
      if (iVar2 == 1) {
        piVar4 = (int *)(*(code *)PTR___ctype_toupper_loc_006aac30)();
        iVar1 = *(int *)(*piVar4 + (uint)*param_3 * 4);
        if (iVar1 == 0x42) {
          iVar2 = 0x341;
        }
        else if (iVar1 < 0x43) {
          iVar2 = 0x340;
          if (iVar1 != 0x41) {
            return 0;
          }
        }
        else if (iVar1 == 0x43) {
          iVar2 = 0x342;
        }
        else {
          iVar2 = 0x343;
          if (iVar1 != 0x44) {
            return 0;
          }
        }
LAB_005df19c:
        piVar4 = (int *)(*(code *)PTR_EVP_PKEY_CTX_get_data_006aa6dc)(param_1);
        *piVar4 = iVar2;
        return 1;
      }
      if (iVar2 == 2) {
        piVar4 = (int *)(*(code *)PTR___ctype_toupper_loc_006aac30)();
        if (*(int *)(*piVar4 + (uint)*param_3 * 4) == 0x58) {
          iVar1 = *(int *)(*piVar4 + (uint)param_3[1] * 4);
          if (iVar1 == 0x42) {
            iVar2 = 0x345;
          }
          else if (iVar1 == 0x43) {
            iVar2 = 0x346;
          }
          else {
            if (iVar1 != 0x41) {
              return 0;
            }
            iVar2 = 0x344;
          }
          goto LAB_005df19c;
        }
      }
      iVar3 = (*(code *)PTR_OBJ_txt2nid_006a805c)(param_3);
      if (iVar3 != 0) {
        iVar2 = *(int *)PTR_R3410_paramset_006aa708;
        piVar4 = (int *)PTR_R3410_paramset_006aa708;
        while (iVar2 != 0) {
          piVar4 = piVar4 + 4;
          if (iVar3 == iVar2) goto LAB_005df19c;
          iVar2 = *piVar4;
        }
        (*(code *)PTR_ERR_GOST_error_006aa6f0)(0x7f,0x70,"gost_pmeth.c",0xb8);
      }
    }
  }
  else {
    iVar1 = -2;
  }
  return iVar1;
}

