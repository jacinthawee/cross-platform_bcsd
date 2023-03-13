
_STACK * load_crls(BIO *param_1,undefined4 *param_2,int param_3,undefined4 param_4,
                  undefined4 param_5,char *param_6)

{
  BIO *bp;
  _STACK *st;
  _STACK *st_00;
  void *pvVar1;
  int iVar2;
  int iVar3;
  int in_GS_OFFSET;
  char *format;
  undefined4 local_28;
  undefined4 *local_24;
  int local_20;
  
  local_24 = param_2;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_28 = param_4;
  if (param_3 == 3) {
    if (param_2 == (undefined4 *)0x0) {
      bp = BIO_new_fp(stdin,0);
      if (bp != (BIO *)0x0) goto LAB_0807b8af;
      param_2 = (undefined4 *)0x81ed476;
LAB_0807b9e8:
      format = "Error opening %s %s\n";
    }
    else {
      bp = BIO_new_file((char *)param_2,"r");
      if (bp == (BIO *)0x0) goto LAB_0807b9e8;
LAB_0807b8af:
      param_2 = &local_28;
      st = (_STACK *)PEM_X509_INFO_read_bio(bp,(stack_st_X509_INFO *)0x0,password_callback,param_2);
      BIO_free(bp);
      st_00 = sk_new_null();
      if (st_00 != (_STACK *)0x0) {
        for (iVar3 = 0; iVar2 = sk_num(st), iVar3 < iVar2; iVar3 = iVar3 + 1) {
          pvVar1 = sk_value(st,iVar3);
          if (*(void **)((int)pvVar1 + 4) != (void *)0x0) {
            iVar2 = sk_push(st_00,*(void **)((int)pvVar1 + 4));
            if (iVar2 == 0) goto LAB_0807b978;
            *(undefined4 *)((int)pvVar1 + 4) = 0;
          }
        }
        iVar3 = sk_num(st_00);
        if (0 < iVar3) {
          if (st != (_STACK *)0x0) {
            sk_pop_free(st,X509_INFO_free);
          }
          goto LAB_0807b95c;
        }
      }
LAB_0807b978:
      if (st != (_STACK *)0x0) {
        sk_pop_free(st,X509_INFO_free);
      }
      sk_pop_free(st_00,X509_CRL_free);
      param_6 = "CRLs";
      format = "unable to load %s\n";
    }
    BIO_printf(param_1,format,param_6,param_2);
    ERR_print_errors(param_1);
  }
  else {
    BIO_printf(param_1,"bad input format specified for %s\n",param_6);
  }
  st_00 = (_STACK *)0x0;
LAB_0807b95c:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return st_00;
}

