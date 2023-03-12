
int pkey_gost_mac_ctrl(EVP_PKEY_CTX *param_1,undefined4 param_2,int param_3,EVP_MD *param_4)

{
  int *piVar1;
  EVP_PKEY *pkey;
  int iVar2;
  _func_1079 *p_Var3;
  int iVar4;
  _func_1080 *p_Var5;
  ulong uVar6;
  _func_1081 *p_Var7;
  int iVar8;
  
  piVar1 = (int *)EVP_PKEY_CTX_get_data(param_1);
  switch(param_2) {
  case 1:
    iVar8 = EVP_MD_type(param_4);
    if (iVar8 != 0x32f) {
      ERR_GOST_error(0x80,0x6c,"gost_pmeth.c",0x1ba);
      return 0;
    }
    piVar1[1] = (int)param_4;
  case 3:
  case 4:
  case 5:
    iVar8 = 1;
    break;
  default:
    return -2;
  case 6:
    if (param_3 != 0x20) {
      ERR_GOST_error(0x80,0x6f,"gost_pmeth.c",0x1c8);
      return 0;
    }
    iVar8 = 1;
    iVar2 = param_4->pkey_type;
    iVar4 = param_4->md_size;
    uVar6 = param_4->flags;
    piVar1[2] = param_4->type;
    piVar1[3] = iVar2;
    piVar1[4] = iVar4;
    piVar1[5] = uVar6;
    p_Var3 = param_4->update;
    p_Var5 = param_4->final;
    p_Var7 = param_4->copy;
    piVar1[6] = (int)param_4->init;
    piVar1[7] = (int)p_Var3;
    piVar1[8] = (int)p_Var5;
    piVar1[9] = (int)p_Var7;
    *piVar1 = 1;
    break;
  case 7:
    iVar8 = *piVar1;
    piVar1 = piVar1 + 2;
    if (iVar8 != 0) {
LAB_000f64ac:
                    /* WARNING: Could not recover jumptable at 0x000f64be. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar8 = (**(code **)(param_4->type + 0x48))(param_4,0x1004,0x20,piVar1);
      return iVar8;
    }
    pkey = EVP_PKEY_CTX_get0_pkey(param_1);
    if (pkey == (EVP_PKEY *)0x0) {
      ERR_GOST_error(0x80,0x74,"gost_pmeth.c",0x1d7);
    }
    else {
      piVar1 = (int *)EVP_PKEY_get0(pkey);
      if (piVar1 != (int *)0x0) goto LAB_000f64ac;
      ERR_GOST_error(0x80,0x74,"gost_pmeth.c",0x1dd);
    }
  }
  return iVar8;
}

