
undefined4 cswift_init(void)

{
  undefined4 uVar1;
  char *filename;
  DSO_FUNC_TYPE pDVar2;
  DSO_FUNC_TYPE pDVar3;
  DSO_FUNC_TYPE pDVar4;
  DSO_FUNC_TYPE pDVar5;
  int iVar6;
  int in_GS_OFFSET;
  undefined4 local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (cswift_dso == (DSO *)0x0) {
    filename = CSWIFT_LIBNAME;
    if (CSWIFT_LIBNAME == (char *)0x0) {
      filename = "swift";
    }
    cswift_dso = DSO_load((DSO *)0x0,filename,(DSO_METHOD *)0x0,0);
    if (cswift_dso == (DSO *)0x0) {
      if (CSWIFT_lib_error_code == 0) {
        CSWIFT_lib_error_code = ERR_get_next_error_library();
      }
      iVar6 = 0x18d;
    }
    else {
      pDVar2 = DSO_bind_func(cswift_dso,"swAcquireAccContext");
      if (pDVar2 != (DSO_FUNC_TYPE)0x0) {
        pDVar3 = DSO_bind_func(cswift_dso,"swAttachKeyParam");
        if (pDVar3 != (DSO_FUNC_TYPE)0x0) {
          pDVar4 = DSO_bind_func(cswift_dso,"swSimpleRequest");
          if (pDVar4 != (DSO_FUNC_TYPE)0x0) {
            pDVar5 = DSO_bind_func(cswift_dso,"swReleaseAccContext");
            if (pDVar5 != (DSO_FUNC_TYPE)0x0) {
              p_CSwift_ReleaseAccContext = pDVar5;
              p_CSwift_SimpleRequest = pDVar4;
              p_CSwift_AttachKeyParam = pDVar3;
              p_CSwift_AcquireAccContext = pDVar2;
              iVar6 = (*pDVar2)(&local_14);
              if (iVar6 == 0) {
                (*p_CSwift_ReleaseAccContext)(local_14);
                uVar1 = 1;
                goto LAB_081a05ef;
              }
              if (CSWIFT_lib_error_code == 0) {
                CSWIFT_lib_error_code = ERR_get_next_error_library();
              }
              ERR_put_error(CSWIFT_lib_error_code,0x68,0x6c,"e_cswift.c",0x1a5);
              goto LAB_081a05a6;
            }
          }
        }
      }
      if (CSWIFT_lib_error_code == 0) {
        CSWIFT_lib_error_code = ERR_get_next_error_library();
      }
      iVar6 = 0x199;
    }
    ERR_put_error(CSWIFT_lib_error_code,0x68,0x6a,"e_cswift.c",iVar6);
  }
  else {
    if (CSWIFT_lib_error_code == 0) {
      CSWIFT_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(CSWIFT_lib_error_code,0x68,100,"e_cswift.c",0x186);
  }
LAB_081a05a6:
  if (cswift_dso != (DSO *)0x0) {
    DSO_free(cswift_dso);
    cswift_dso = (DSO *)0x0;
  }
  p_CSwift_AcquireAccContext = (DSO_FUNC_TYPE)0x0;
  p_CSwift_AttachKeyParam = (DSO_FUNC_TYPE)0x0;
  uVar1 = 0;
  p_CSwift_SimpleRequest = (DSO_FUNC_TYPE)0x0;
  p_CSwift_ReleaseAccContext = (DSO_FUNC_TYPE)0x0;
LAB_081a05ef:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

