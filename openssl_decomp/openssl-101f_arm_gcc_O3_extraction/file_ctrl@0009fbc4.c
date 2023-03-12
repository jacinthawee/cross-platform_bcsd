
void file_ctrl(BIO *param_1,int param_2,uint param_3,FILE **param_4)

{
  FILE *pFVar1;
  int *piVar2;
  char *src;
  char acStack_20 [4];
  int local_1c;
  
  pFVar1 = (FILE *)param_1->ptr;
  local_1c = __TMC_END__;
  if (param_2 == 0xb) {
    fflush(pFVar1);
    pFVar1 = (FILE *)0x1;
    goto LAB_0009fc2a;
  }
  if (param_2 < 0xc) {
    if (param_2 == 3) {
LAB_0009fcdc:
      pFVar1 = (FILE *)ftell(pFVar1);
      goto LAB_0009fc2a;
    }
    if (param_2 < 4) {
      if (param_2 == 1) goto LAB_0009fcc4;
      if (param_2 == 2) {
        pFVar1 = (FILE *)feof(pFVar1);
        goto LAB_0009fc2a;
      }
    }
    else {
      if (param_2 == 8) {
        pFVar1 = (FILE *)param_1->shutdown;
        goto LAB_0009fc2a;
      }
      if (param_2 == 9) {
        param_1->shutdown = param_3;
        pFVar1 = (FILE *)0x1;
        goto LAB_0009fc2a;
      }
    }
  }
  else {
    if (param_2 == 0x6b) {
      if (param_4 != (FILE **)0x0) {
        *param_4 = pFVar1;
        pFVar1 = (FILE *)0x1;
        goto LAB_0009fc2a;
      }
LAB_0009fcb2:
      pFVar1 = (FILE *)0x1;
      goto LAB_0009fc2a;
    }
    if (param_2 < 0x6c) {
      if (param_2 == 0xc) goto LAB_0009fcb2;
      if (param_2 == 0x6a) {
        if (((param_1->shutdown != 0) && (param_1->init != 0)) && (pFVar1 != (FILE *)0x0)) {
          fclose(pFVar1);
          param_1->flags = 0;
        }
        param_1->ptr = param_4;
        pFVar1 = (FILE *)0x1;
        param_1->shutdown = param_3 & 1;
        param_1->init = 1;
        goto LAB_0009fc2a;
      }
    }
    else {
      if (param_2 == 0x80) {
LAB_0009fcc4:
        pFVar1 = (FILE *)fseek(pFVar1,param_3,0);
        goto LAB_0009fc2a;
      }
      if (param_2 == 0x85) goto LAB_0009fcdc;
      if (param_2 == 0x6c) {
        if (param_1->shutdown != 0) {
          if ((param_1->init != 0) && (pFVar1 != (FILE *)0x0)) {
            fclose(pFVar1);
            param_1->ptr = (void *)0x0;
            param_1->flags = 0;
          }
          param_1->init = 0;
        }
        param_1->shutdown = param_3 & 1;
        if ((int)(param_3 << 0x1c) < 0) {
          if ((int)(param_3 << 0x1e) < 0) {
            src = "a+";
          }
          else {
            src = "a";
          }
          BUF_strlcpy(acStack_20,src,4);
        }
        else if ((param_3 & 6) == 6) {
          BUF_strlcpy(acStack_20,"r+",4);
        }
        else if ((int)(param_3 << 0x1d) < 0) {
          BUF_strlcpy(acStack_20,"w",4);
        }
        else {
          pFVar1 = (FILE *)(param_3 & 2);
          if (pFVar1 == (FILE *)0x0) {
            ERR_put_error(0x20,0x74,0x65,"bss_file.c",0x17b);
            goto LAB_0009fc2a;
          }
          BUF_strlcpy(acStack_20,"r",4);
        }
        pFVar1 = fopen64((char *)param_4,acStack_20);
        if (pFVar1 == (FILE *)0x0) {
          piVar2 = __errno_location();
          ERR_put_error(2,1,*piVar2,"bss_file.c",0x18e);
          ERR_add_error_data(5,"fopen(\'",param_4,&DAT_0015f0a8,acStack_20,&DAT_0013adec);
          ERR_put_error(0x20,0x74,2,"bss_file.c",400);
        }
        else {
          param_1->ptr = pFVar1;
          pFVar1 = (FILE *)0x1;
          param_1->init = 1;
          BIO_clear_flags(param_1,0);
        }
        goto LAB_0009fc2a;
      }
    }
  }
  pFVar1 = (FILE *)0x0;
LAB_0009fc2a:
  if (local_1c != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(pFVar1);
  }
  return;
}

