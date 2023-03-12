
int file_ctrl(BIO *param_1,int param_2,uint param_3,FILE **param_4)

{
  int iVar1;
  FILE *pFVar2;
  int *piVar3;
  int in_GS_OFFSET;
  int line;
  char local_14 [4];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  pFVar2 = (FILE *)param_1->ptr;
  if (param_2 == 0xb) {
    fflush(pFVar2);
    iVar1 = 1;
    goto LAB_081195e8;
  }
  if (param_2 < 0xc) {
    if (param_2 == 3) {
LAB_081197d0:
      iVar1 = ftell(pFVar2);
      goto LAB_081195e8;
    }
    if (param_2 < 4) {
      if (param_2 == 1) goto LAB_08119710;
      if (param_2 == 2) {
        iVar1 = feof(pFVar2);
        goto LAB_081195e8;
      }
    }
    else {
      if (param_2 == 8) {
        iVar1 = param_1->shutdown;
        goto LAB_081195e8;
      }
      if (param_2 == 9) {
        param_1->shutdown = param_3;
        iVar1 = 1;
        goto LAB_081195e8;
      }
    }
  }
  else {
    if (param_2 == 0x6b) {
      if (param_4 == (FILE **)0x0) {
        iVar1 = 1;
      }
      else {
        *param_4 = pFVar2;
        iVar1 = 1;
      }
      goto LAB_081195e8;
    }
    if (param_2 < 0x6c) {
      iVar1 = 1;
      if (param_2 == 0xc) goto LAB_081195e8;
      if (param_2 == 0x6a) {
        if (((param_1->shutdown != 0) && (param_1->init != 0)) && (pFVar2 != (FILE *)0x0)) {
          fclose(pFVar2);
          param_1->flags = 0;
        }
        param_1->ptr = param_4;
        param_1->init = 1;
        param_1->shutdown = param_3 & 1;
        iVar1 = 1;
        goto LAB_081195e8;
      }
      goto LAB_081197a8;
    }
    if (param_2 == 0x80) {
LAB_08119710:
      iVar1 = fseek(pFVar2,param_3,0);
      goto LAB_081195e8;
    }
    if (param_2 == 0x85) goto LAB_081197d0;
    if (param_2 != 0x6c) goto LAB_081197a8;
    if (param_1->shutdown != 0) {
      if ((param_1->init != 0) && (pFVar2 != (FILE *)0x0)) {
        fclose(pFVar2);
        param_1->ptr = (void *)0x0;
        param_1->flags = 0;
      }
      param_1->init = 0;
    }
    param_1->shutdown = param_3 & 1;
    if ((param_3 & 8) == 0) {
      if ((param_3 & 6) == 6) {
        BUF_strlcpy(local_14,"r+",4);
        goto LAB_081196ae;
      }
      if ((param_3 & 4) != 0) {
        BUF_strlcpy(local_14,"w",4);
        goto LAB_081196ae;
      }
      if ((param_3 & 2) != 0) {
        BUF_strlcpy(local_14,"r",4);
        goto LAB_081196ae;
      }
      line = 0x17b;
      iVar1 = 0x65;
    }
    else {
      if ((param_3 & 2) == 0) {
        BUF_strlcpy(local_14,"a",4);
      }
      else {
        BUF_strlcpy(local_14,"a+",4);
      }
LAB_081196ae:
      pFVar2 = fopen64((char *)param_4,local_14);
      if (pFVar2 != (FILE *)0x0) {
        param_1->ptr = pFVar2;
        param_1->init = 1;
        BIO_clear_flags(param_1,0);
        iVar1 = 1;
        goto LAB_081195e8;
      }
      piVar3 = __errno_location();
      ERR_put_error(2,1,*piVar3,"bss_file.c",0x18e);
      ERR_add_error_data(5,"fopen(\'",param_4,&DAT_0822334b,local_14,&DAT_081ffd8b);
      line = 400;
      iVar1 = 2;
    }
    ERR_put_error(0x20,0x74,iVar1,"bss_file.c",line);
  }
LAB_081197a8:
  iVar1 = 0;
LAB_081195e8:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

