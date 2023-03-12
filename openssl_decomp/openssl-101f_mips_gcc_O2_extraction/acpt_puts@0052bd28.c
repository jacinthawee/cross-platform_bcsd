
int acpt_puts(BIO *param_1,void *param_2,BIO *param_3,char *param_4)

{
  int iVar1;
  int iVar2;
  callback *callback;
  char *arg;
  BIO *pBVar3;
  int iVar4;
  BIO *pBVar5;
  int *piVar6;
  long in_stack_ffffffc0;
  long in_stack_ffffffc4;
  
  iVar1 = (*(code *)PTR_strlen_006aab30)(param_2);
  BIO_clear_flags(param_1,0xf);
  piVar6 = (int *)param_1->ptr;
  do {
    pBVar5 = param_1->next_bio;
    while( true ) {
      if (pBVar5 != (BIO *)0x0) {
        iVar1 = BIO_write(pBVar5,param_2,iVar1);
        BIO_copy_next_retry(param_1);
        return iVar1;
      }
      iVar2 = *piVar6;
      if (iVar2 == 2) goto LAB_0052beac;
      if (iVar2 == 3) break;
      if (iVar2 != 1) {
        return 0;
      }
      param_4 = "7 datafinal";
      if ((char *)piVar6[1] == (char *)0x0) {
        iVar2 = 0x6f;
        iVar1 = 0xd4;
LAB_0052bfec:
        ERR_put_error(0x20,100,iVar2,"bss_acpt.c",iVar1);
        return -1;
      }
      iVar2 = BIO_get_accept_socket((char *)piVar6[1],piVar6[6]);
      if (iVar2 == -1) {
        return -1;
      }
      if ((piVar6[3] != 0) && (iVar4 = BIO_socket_nbio(iVar2,1), iVar4 == 0)) {
        (*(code *)PTR_close_006aaa5c)(iVar2);
        iVar2 = 0x6a;
        iVar1 = 0xe0;
        goto LAB_0052bfec;
      }
      pBVar5 = param_1->next_bio;
      piVar6[2] = iVar2;
      param_1->num = iVar2;
      *piVar6 = 2;
    }
    *piVar6 = 2;
LAB_0052beac:
    BIO_clear_flags(param_1,0xf);
    iVar2 = piVar6[2];
    param_1->retry_reason = 0;
    iVar2 = BIO_accept(iVar2,(char **)(piVar6 + 4));
    if (iVar2 == -2) {
      BIO_set_flags(param_1,0xc);
      param_1->retry_reason = 3;
      return -1;
    }
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar4 = 1;
    pBVar5 = BIO_new_socket(iVar2,1);
    if (pBVar5 == (BIO *)0x0) {
      return 0;
    }
    callback = (callback *)
               BIO_get_callback(param_1,iVar4,(char *)param_3,(int)param_4,in_stack_ffffffc0,
                                in_stack_ffffffc4);
    BIO_set_callback(pBVar5,callback);
    arg = BIO_get_callback_arg(param_1);
    BIO_set_callback_arg(pBVar5,arg);
    if ((piVar6[5] != 0) && (iVar2 = BIO_socket_nbio(iVar2,1), iVar2 == 0)) {
      ERR_put_error(0x20,100,0x69,"bss_acpt.c",0x107);
LAB_0052c070:
      BIO_free(pBVar5);
      return 0;
    }
    param_3 = pBVar5;
    if ((((BIO *)piVar6[7] != (BIO *)0x0) &&
        ((param_3 = BIO_dup_chain((BIO *)piVar6[7]), param_3 == (BIO *)0x0 ||
         (pBVar3 = BIO_push(param_3,pBVar5), pBVar3 == (BIO *)0x0)))) ||
       (pBVar3 = BIO_push(param_1,param_3), pBVar5 = param_3, pBVar3 == (BIO *)0x0))
    goto LAB_0052c070;
    *piVar6 = 3;
  } while( true );
}

