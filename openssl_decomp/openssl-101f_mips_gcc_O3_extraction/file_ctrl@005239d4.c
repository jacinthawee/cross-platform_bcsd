
BIO * file_ctrl(BIO *param_1,uint param_2,uint param_3,void **param_4)

{
  undefined *puVar1;
  BIO *pBVar2;
  int *piVar3;
  int iVar4;
  void *pvVar5;
  int reason;
  char acStack_20 [4];
  int local_1c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  pvVar5 = param_1->ptr;
  local_1c = *(int *)PTR___stack_chk_guard_006aabf0;
  if (param_2 == 0xb) {
    (*(code *)PTR_fflush_006aac0c)();
    pBVar2 = (BIO *)0x1;
    goto LAB_00523aac;
  }
  if ((int)param_2 < 0xc) {
    if (param_2 != 3) {
      if (3 < (int)param_2) {
        if (param_2 == 8) {
          pBVar2 = (BIO *)param_1->shutdown;
        }
        else {
          pBVar2 = (BIO *)0x0;
          if (param_2 == 9) {
            pBVar2 = (BIO *)0x1;
            param_1->shutdown = param_3;
          }
        }
        goto LAB_00523aac;
      }
      if (param_2 != 1) {
        if (param_2 == 2) {
          pBVar2 = (BIO *)(*(code *)PTR_feof_006aab44)();
          goto LAB_00523aac;
        }
LAB_00523c1c:
        pBVar2 = (BIO *)0x0;
        goto LAB_00523aac;
      }
LAB_00523bb8:
      pBVar2 = (BIO *)(*(code *)PTR_fseek_006aab9c)(pvVar5,param_3,0);
      param_2 = param_3;
      goto LAB_00523aac;
    }
  }
  else {
    if (param_2 == 0x6b) {
      if (param_4 == (void **)0x0) {
        pBVar2 = (BIO *)0x1;
      }
      else {
        *param_4 = pvVar5;
        pBVar2 = (BIO *)0x1;
      }
      goto LAB_00523aac;
    }
    if ((int)param_2 < 0x6c) {
      pBVar2 = (BIO *)0x1;
      if ((param_2 != 0xc) && (pBVar2 = (BIO *)0x0, param_2 == 0x6a)) {
        if ((param_1->shutdown != 0) && ((param_1->init != 0 && (pvVar5 != (void *)0x0)))) {
          (*(code *)PTR_fclose_006aaaa4)();
          param_1->flags = 0;
        }
        param_1->ptr = param_4;
        pBVar2 = (BIO *)0x1;
        param_1->shutdown = param_3 & 1;
        param_1->init = 1;
      }
      goto LAB_00523aac;
    }
    if (param_2 == 0x80) goto LAB_00523bb8;
    if (param_2 != 0x85) {
      pBVar2 = (BIO *)0x0;
      if (param_2 != 0x6c) goto LAB_00523aac;
      if (param_1->shutdown != 0) {
        if ((param_1->init != 0) && (pvVar5 != (void *)0x0)) {
          (*(code *)PTR_fclose_006aaaa4)();
          param_1->ptr = (void *)0x0;
          param_1->flags = 0;
        }
        param_1->init = 0;
      }
      param_1->shutdown = param_3 & 1;
      if ((param_3 & 8) == 0) {
        if ((param_3 & 6) == 6) {
          BUF_strlcpy(acStack_20,"r+",4);
        }
        else if ((param_3 & 4) == 0) {
          if ((param_3 & 2) == 0) {
            param_2 = 0x74;
            ERR_put_error(0x20,0x74,0x65,"bss_file.c",0x17b);
            goto LAB_00523c1c;
          }
          BUF_strlcpy(acStack_20,"r",4);
        }
        else {
          BUF_strlcpy(acStack_20,"w",4);
        }
      }
      else if ((param_3 & 2) == 0) {
        BUF_strlcpy(acStack_20,"a",4);
      }
      else {
        BUF_strlcpy(acStack_20,"a+",4);
      }
      pvVar5 = (void *)(*(code *)PTR_fopen64_006aaa9c)(param_4,acStack_20);
      if (pvVar5 == (void *)0x0) {
        piVar3 = (int *)(*(code *)PTR___errno_location_006aaaf4)();
        ERR_put_error(2,1,*piVar3,"bss_file.c",0x18e);
        ERR_add_error_data(5,"fopen(\'",param_4,&DAT_00667e84,acStack_20,&DAT_00648304);
        param_2 = 0x74;
        ERR_put_error(0x20,0x74,2,"bss_file.c",400);
        pBVar2 = (BIO *)0x0;
      }
      else {
        param_2 = 0;
        param_1->ptr = pvVar5;
        param_1->init = 1;
        BIO_clear_flags(param_1,0);
        pBVar2 = (BIO *)0x1;
      }
      goto LAB_00523aac;
    }
  }
  pBVar2 = (BIO *)(*(code *)PTR_ftell_006aab14)();
LAB_00523aac:
  if (local_1c == *(int *)puVar1) {
    return pBVar2;
  }
  iVar4 = local_1c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  pvVar5 = (void *)(*(code *)PTR_fopen64_006aaa9c)();
  if (pvVar5 == (void *)0x0) {
    piVar3 = (int *)(*(code *)PTR___errno_location_006aaaf4)();
    ERR_put_error(2,1,*piVar3,"bss_file.c",0xa9);
    ERR_add_error_data(5,"fopen(\'",iVar4,&DAT_00667e84,param_2,&DAT_00648304);
    if (*piVar3 == 2) {
      reason = 0x80;
      iVar4 = 0xac;
    }
    else {
      reason = 2;
      iVar4 = 0xae;
    }
    ERR_put_error(0x20,0x6d,reason,"bss_file.c",iVar4);
    return (BIO *)0x0;
  }
  pBVar2 = BIO_new((BIO_METHOD *)methods_filep);
  if (pBVar2 == (BIO *)0x0) {
    (*(code *)PTR_fclose_006aaaa4)(pvVar5);
    pBVar2 = (BIO *)0x0;
  }
  else {
    BIO_clear_flags(pBVar2,0);
    BIO_ctrl(pBVar2,0x6a,1,pvVar5);
  }
  return pBVar2;
}

