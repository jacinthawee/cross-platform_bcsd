
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined4 aep_init(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined *puVar8;
  
  if (aep_dso == 0) {
    puVar8 = AEP_LIBNAME;
    if (AEP_LIBNAME == (undefined *)0x0) {
      puVar8 = &DAT_00673488;
    }
    aep_dso = (*(code *)PTR_DSO_load_006a8884)(0,puVar8,0,0);
    if (aep_dso == 0) {
      if (AEPHK_lib_error_code == 0) {
        AEPHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
      }
      (*(code *)PTR_ERR_put_error_006a7f34)(AEPHK_lib_error_code,0x67,0x6f,"e_aep.c",0x1d4);
    }
    else {
      iVar1 = (*(code *)PTR_DSO_bind_func_006a888c)(aep_dso,"AEP_ModExp");
      if ((((iVar1 != 0) &&
           (iVar2 = (*(code *)PTR_DSO_bind_func_006a888c)(aep_dso,"AEP_ModExpCrt"), iVar2 != 0)) &&
          (iVar3 = (*(code *)PTR_DSO_bind_func_006a888c)(aep_dso,"AEP_Finalize"), iVar3 != 0)) &&
         (((iVar4 = (*(code *)PTR_DSO_bind_func_006a888c)(aep_dso,"AEP_Initialize"), iVar4 != 0 &&
           (iVar5 = (*(code *)PTR_DSO_bind_func_006a888c)(aep_dso,"AEP_OpenConnection"), iVar5 != 0)
           ) && ((iVar6 = (*(code *)PTR_DSO_bind_func_006a888c)(aep_dso,"AEP_SetBNCallBacks"),
                 iVar6 != 0 &&
                 (iVar7 = (*(code *)PTR_DSO_bind_func_006a888c)(aep_dso,"AEP_CloseConnection"),
                 iVar7 != 0)))))) {
        p_AEP_SetBNCallBacks = iVar6;
        p_AEP_Finalize = iVar3;
        p_AEP_Initialize = iVar4;
        p_AEP_ModExpCrt = iVar2;
        p_AEP_ModExp = iVar1;
        p_AEP_CloseConnection = iVar7;
        p_AEP_OpenConnection = iVar5;
        return 1;
      }
      if (AEPHK_lib_error_code == 0) {
        AEPHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
      }
      (*(code *)PTR_ERR_put_error_006a7f34)(AEPHK_lib_error_code,0x67,0x6f,"e_aep.c",0x1e2);
    }
  }
  else {
    if (AEPHK_lib_error_code == 0) {
      AEPHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    (*(code *)PTR_ERR_put_error_006a7f34)(AEPHK_lib_error_code,0x67,100,"e_aep.c",0x1cc);
  }
  if (aep_dso != 0) {
    (*(code *)PTR_DSO_free_006a8874)();
  }
  aep_dso = 0;
  p_AEP_OpenConnection = 0;
  p_AEP_CloseConnection = 0;
  p_AEP_ModExp = 0;
  p_AEP_ModExpCrt = 0;
  p_AEP_Initialize = 0;
  p_AEP_Finalize = 0;
  p_AEP_SetBNCallBacks = 0;
  return 0;
}

