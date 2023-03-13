
undefined4 atalla_init(void)

{
  undefined4 uVar1;
  char *filename;
  DSO_FUNC_TYPE pDVar2;
  DSO_FUNC_TYPE pDVar3;
  DSO_FUNC_TYPE pDVar4;
  int iVar5;
  int in_GS_OFFSET;
  undefined local_1010 [4096];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (atalla_dso == (DSO *)0x0) {
    filename = ATALLA_LIBNAME;
    if (ATALLA_LIBNAME == (char *)0x0) {
      filename = "atasi";
    }
    atalla_dso = DSO_load((DSO *)0x0,filename,(DSO_METHOD *)0x0,0);
    if (atalla_dso == (DSO *)0x0) {
      if (ATALLA_lib_error_code == 0) {
        ATALLA_lib_error_code = ERR_get_next_error_library();
      }
      iVar5 = 0x17f;
    }
    else {
      pDVar2 = DSO_bind_func(atalla_dso,"ASI_GetHardwareConfig");
      if (pDVar2 != (DSO_FUNC_TYPE)0x0) {
        pDVar3 = DSO_bind_func(atalla_dso,"ASI_RSAPrivateKeyOpFn");
        if (pDVar3 != (DSO_FUNC_TYPE)0x0) {
          pDVar4 = DSO_bind_func(atalla_dso,"ASI_GetPerformanceStatistics");
          if (pDVar4 != (DSO_FUNC_TYPE)0x0) {
            p_Atalla_RSAPrivateKeyOpFn = pDVar3;
            iVar5 = (*pDVar2)(0,local_1010);
            uVar1 = 1;
            if (iVar5 == 0) goto LAB_0819e792;
            if (ATALLA_lib_error_code == 0) {
              ATALLA_lib_error_code = ERR_get_next_error_library();
            }
            ERR_put_error(ATALLA_lib_error_code,0x66,0x6b,"e_atalla.c",0x194);
            goto LAB_0819e767;
          }
        }
      }
      if (ATALLA_lib_error_code == 0) {
        ATALLA_lib_error_code = ERR_get_next_error_library();
      }
      iVar5 = 0x189;
    }
    ERR_put_error(ATALLA_lib_error_code,0x66,0x69,"e_atalla.c",iVar5);
  }
  else {
    if (ATALLA_lib_error_code == 0) {
      ATALLA_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(ATALLA_lib_error_code,0x66,100,"e_atalla.c",0x170);
  }
LAB_0819e767:
  if (atalla_dso != (DSO *)0x0) {
    DSO_free(atalla_dso);
  }
  atalla_dso = (DSO *)0x0;
  p_Atalla_RSAPrivateKeyOpFn = (DSO_FUNC_TYPE)0x0;
  uVar1 = 0;
LAB_0819e792:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

