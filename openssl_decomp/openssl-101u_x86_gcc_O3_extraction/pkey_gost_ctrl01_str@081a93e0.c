
int pkey_gost_ctrl01_str(EVP_PKEY_CTX *param_1,byte *param_2,byte *param_3)

{
  size_t sVar1;
  int iVar2;
  __int32_t **pp_Var3;
  int *piVar4;
  int iVar5;
  undefined1 *puVar6;
  int iVar7;
  byte *pbVar8;
  undefined in_CF;
  undefined in_ZF;
  
  iVar5 = 9;
  pbVar8 = (byte *)0x823c312;
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    in_CF = *param_2 < *pbVar8;
    in_ZF = *param_2 == *pbVar8;
    param_2 = param_2 + 1;
    pbVar8 = pbVar8 + 1;
  } while ((bool)in_ZF);
  iVar5 = (int)(char)((!(bool)in_CF && !(bool)in_ZF) - in_CF);
  if (iVar5 == 0) {
    if (param_3 != (byte *)0x0) {
      sVar1 = strlen((char *)param_3);
      if (sVar1 == 1) {
        pp_Var3 = __ctype_toupper_loc();
        iVar5 = (*pp_Var3)[*param_3];
        if (iVar5 == 0x41) {
          iVar7 = 0x348;
        }
        else if (iVar5 < 0x42) {
          iVar7 = 0x347;
          if (iVar5 != 0x30) {
            return 0;
          }
        }
        else if (iVar5 == 0x42) {
          iVar7 = 0x349;
        }
        else {
          iVar7 = 0x34a;
          if (iVar5 != 0x43) {
            return 0;
          }
        }
LAB_081a94aa:
        piVar4 = (int *)EVP_PKEY_CTX_get_data(param_1);
        *piVar4 = iVar7;
        return 1;
      }
      if (sVar1 == 2) {
        pp_Var3 = __ctype_toupper_loc();
        if ((*pp_Var3)[*param_3] == 0x58) {
          iVar5 = (*pp_Var3)[param_3[1]];
          if (iVar5 == 0x41) {
            iVar7 = 0x34b;
          }
          else {
            iVar7 = 0x34c;
            if (iVar5 != 0x42) {
              return 0;
            }
          }
          goto LAB_081a94aa;
        }
      }
      iVar2 = OBJ_txt2nid((char *)param_3);
      if (iVar2 != 0) {
        if (R3410_2001_paramset._0_4_ != 0) {
          iVar7 = R3410_2001_paramset._0_4_;
          if (R3410_2001_paramset._0_4_ != iVar2) {
            puVar6 = R3410_2001_paramset;
            do {
              puVar6 = (undefined1 *)((int)puVar6 + 0x1c);
              iVar7 = *(int *)puVar6;
              if (iVar7 == 0) goto LAB_081a945d;
            } while (iVar2 != iVar7);
          }
          goto LAB_081a94aa;
        }
LAB_081a945d:
        ERR_GOST_error(0x7e,0x70,"gost_pmeth.c",0xea);
      }
    }
  }
  else {
    iVar5 = -2;
  }
  return iVar5;
}

