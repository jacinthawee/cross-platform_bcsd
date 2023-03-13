
int pkey_gost_mac_ctrl(EVP_PKEY_CTX *param_1,undefined4 param_2,int param_3,EVP_MD *param_4)

{
  _func_1081 *p_Var1;
  int *piVar2;
  int iVar3;
  EVP_PKEY *pkey;
  void *pvVar4;
  undefined4 uVar5;
  
  piVar2 = (int *)EVP_PKEY_CTX_get_data(param_1);
  switch(param_2) {
  default:
    return -2;
  case 1:
    iVar3 = EVP_MD_type(param_4);
    if (iVar3 != 0x32f) {
      ERR_GOST_error(0x80,0x6c,"gost_pmeth.c",0x1ba);
      return 0;
    }
    piVar2[1] = (int)param_4;
    iVar3 = 1;
    break;
  case 3:
  case 4:
  case 5:
    iVar3 = 1;
    break;
  case 6:
    if (param_3 != 0x20) {
      ERR_GOST_error(0x80,0x6f,"gost_pmeth.c",0x1c8);
      return 0;
    }
    iVar3 = 1;
    piVar2[2] = param_4->type;
    piVar2[3] = param_4->pkey_type;
    piVar2[4] = param_4->md_size;
    piVar2[5] = param_4->flags;
    piVar2[6] = (int)param_4->init;
    piVar2[7] = (int)param_4->update;
    piVar2[8] = (int)param_4->final;
    p_Var1 = param_4->copy;
    *piVar2 = 1;
    piVar2[9] = (int)p_Var1;
    break;
  case 7:
    iVar3 = *piVar2;
    if (iVar3 != 0) {
LAB_081a9089:
                    /* WARNING: Could not recover jumptable at 0x081a90ad. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar3 = (**(code **)(param_4->type + 0x48))();
      return iVar3;
    }
    pkey = EVP_PKEY_CTX_get0_pkey(param_1);
    if (pkey == (EVP_PKEY *)0x0) {
      uVar5 = 0x1d7;
    }
    else {
      pvVar4 = EVP_PKEY_get0(pkey);
      if (pvVar4 != (void *)0x0) goto LAB_081a9089;
      uVar5 = 0x1dd;
    }
    ERR_GOST_error(0x80,0x74,"gost_pmeth.c",uVar5);
  }
  return iVar3;
}

