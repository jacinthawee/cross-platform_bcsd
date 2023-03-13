
undefined4 aep_finish(void)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  puVar1 = aep_app_conn_table;
  if (aep_dso == (DSO *)0x0) {
    if (AEPHK_lib_error_code == 0) {
      AEPHK_lib_error_code = ERR_get_next_error_library();
    }
    iVar3 = 0x219;
    iVar2 = 0x6f;
  }
  else {
    do {
      while (iVar3 = *(int *)puVar1, iVar3 == 1) {
        iVar3 = (*p_AEP_CloseConnection)(*(int *)((int)puVar1 + 4));
        if (iVar3 != 0) {
          if (AEPHK_lib_error_code == 0) {
            AEPHK_lib_error_code = ERR_get_next_error_library();
          }
          iVar3 = 0x21f;
          iVar2 = 0x65;
          goto LAB_0819c9c2;
        }
        *(int *)puVar1 = 0;
        *(int *)((int)puVar1 + 4) = 0;
        puVar1 = (undefined1 *)((int)puVar1 + 8);
        if ((int *)puVar1 == &AEPHK_lib_error_code) goto LAB_0819c904;
      }
      puVar1 = (undefined1 *)((int)puVar1 + 8);
      iVar2 = iVar2 + (uint)(iVar3 == 2);
    } while ((int *)puVar1 != &AEPHK_lib_error_code);
LAB_0819c904:
    if (iVar2 == 0) {
      iVar2 = (*p_AEP_Finalize)();
      if (iVar2 == 0) {
        iVar2 = DSO_free(aep_dso);
        if (iVar2 != 0) {
          aep_dso = (DSO *)0x0;
          p_AEP_CloseConnection = (code *)0x0;
          p_AEP_OpenConnection = 0;
          p_AEP_ModExp = 0;
          p_AEP_ModExpCrt = 0;
          p_AEP_Initialize = 0;
          p_AEP_Finalize = (code *)0x0;
          p_AEP_SetBNCallBacks = 0;
          return 1;
        }
        if (AEPHK_lib_error_code == 0) {
          AEPHK_lib_error_code = ERR_get_next_error_library();
        }
        iVar3 = 0x22e;
        iVar2 = 0x73;
      }
      else {
        if (AEPHK_lib_error_code == 0) {
          AEPHK_lib_error_code = ERR_get_next_error_library();
        }
        iVar3 = 0x229;
        iVar2 = 0x68;
      }
    }
    else {
      if (AEPHK_lib_error_code == 0) {
        AEPHK_lib_error_code = ERR_get_next_error_library();
      }
      iVar3 = 0x223;
      iVar2 = 0x66;
    }
  }
LAB_0819c9c2:
  ERR_put_error(AEPHK_lib_error_code,0x65,iVar2,"e_aep.c",iVar3);
  return 0;
}

