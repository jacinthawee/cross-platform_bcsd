
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined4 aep_finish(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  
  if (aep_dso == 0) {
    if (AEPHK_lib_error_code == 0) {
      AEPHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    uVar3 = 0x6f;
    uVar2 = 0x219;
  }
  else {
    iVar6 = 0;
    piVar4 = (int *)aep_app_conn_table;
    do {
      while( true ) {
        iVar1 = *piVar4;
        if (iVar1 != 1) break;
        iVar1 = (*p_AEP_CloseConnection)(piVar4[1]);
        if (iVar1 != 0) {
          if (AEPHK_lib_error_code == 0) {
            AEPHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
          }
          uVar3 = 0x65;
          uVar2 = 0x21f;
          goto LAB_005cc770;
        }
        *piVar4 = 0;
        piVar5 = piVar4 + 2;
        piVar4[1] = 0;
        piVar4 = piVar5;
        if (piVar5 == &AEPHK_lib_error_code) goto LAB_005cc690;
      }
      piVar4 = piVar4 + 2;
      if (iVar1 == 2) {
        iVar6 = iVar6 + 1;
      }
    } while (piVar4 != &AEPHK_lib_error_code);
LAB_005cc690:
    if (iVar6 == 0) {
      iVar6 = (*p_AEP_Finalize)();
      if (iVar6 == 0) {
        iVar6 = (*(code *)PTR_DSO_free_006a8874)(aep_dso);
        if (iVar6 == 0) {
          if (AEPHK_lib_error_code == 0) {
            AEPHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
          }
          (*(code *)PTR_ERR_put_error_006a7f34)(AEPHK_lib_error_code,0x65,0x73,"e_aep.c",0x22e);
          uVar2 = 0;
        }
        else {
          p_AEP_Finalize = (code *)0x0;
          aep_dso = 0;
          p_AEP_SetBNCallBacks = 0;
          p_AEP_CloseConnection = (code *)0x0;
          p_AEP_OpenConnection = 0;
          p_AEP_ModExp = 0;
          p_AEP_ModExpCrt = 0;
          p_AEP_Initialize = 0;
          uVar2 = 1;
        }
        return uVar2;
      }
      if (AEPHK_lib_error_code == 0) {
        AEPHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
      }
      uVar3 = 0x68;
      uVar2 = 0x229;
    }
    else {
      if (AEPHK_lib_error_code == 0) {
        AEPHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
      }
      uVar3 = 0x66;
      uVar2 = 0x223;
    }
  }
LAB_005cc770:
  (*(code *)PTR_ERR_put_error_006a7f34)(AEPHK_lib_error_code,0x65,uVar3,"e_aep.c",uVar2);
  return 0;
}

