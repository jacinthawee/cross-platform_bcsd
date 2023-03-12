
undefined4 aep_finish(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  DSO *pDVar5;
  
  if (aep_dso == (DSO *)0x0) {
    if (AEPHK_lib_error_code == 0) {
      AEPHK_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(AEPHK_lib_error_code,0x65,0x6f,"e_aep.c",0x211);
    return 0;
  }
  pDVar5 = (DSO *)0x0;
  iVar3 = 0;
  do {
    while (piVar1 = (int *)(aep_app_conn_table + iVar3), *piVar1 == 1) {
      iVar2 = (*(code *)p_AEP_CloseConnection)(*(undefined4 *)(aep_app_conn_table + iVar3 + 4));
      if (iVar2 != 0) {
        if (AEPHK_lib_error_code == 0) {
          AEPHK_lib_error_code = ERR_get_next_error_library();
        }
        ERR_put_error(AEPHK_lib_error_code,0x65,0x65,"e_aep.c",0x218);
        return 0;
      }
      *(undefined4 *)(aep_app_conn_table + iVar3) = 0;
      iVar2 = iVar3 + 8;
      *(undefined4 *)(aep_app_conn_table + iVar3 + 4) = 0;
      iVar3 = iVar2;
      if (iVar2 == 0x800) goto LAB_000f0d66;
    }
    iVar3 = iVar3 + 8;
    if (*piVar1 == 2) {
      pDVar5 = (DSO *)((int)&pDVar5->meth + 1);
    }
  } while (iVar3 != 0x800);
LAB_000f0d66:
  if (pDVar5 != (DSO *)0x0) {
    if (AEPHK_lib_error_code == 0) {
      AEPHK_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(AEPHK_lib_error_code,0x65,0x66,"e_aep.c",0x21d);
    return 0;
  }
  iVar3 = (*(code *)p_AEP_Finalize)();
  if (iVar3 == 0) {
    iVar3 = DSO_free(aep_dso);
    if (iVar3 == 0) {
      if (AEPHK_lib_error_code == 0) {
        AEPHK_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(AEPHK_lib_error_code,0x65,0x73,"e_aep.c",0x22a);
      uVar4 = 0;
    }
    else {
      uVar4 = 1;
      aep_dso = pDVar5;
      p_AEP_ModExp = pDVar5;
      p_AEP_ModExpCrt = pDVar5;
      p_AEP_Finalize = pDVar5;
      p_AEP_Initialize = pDVar5;
      p_AEP_OpenConnection = pDVar5;
      p_AEP_SetBNCallBacks = pDVar5;
      p_AEP_CloseConnection = pDVar5;
    }
    return uVar4;
  }
  if (AEPHK_lib_error_code == 0) {
    AEPHK_lib_error_code = ERR_get_next_error_library();
  }
  ERR_put_error(AEPHK_lib_error_code,0x65,0x68,"e_aep.c",0x224);
  return 0;
}

