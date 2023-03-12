
int acpt_write(BIO *param_1,void *param_2,BIO *param_3,int param_4)

{
  int iVar1;
  callback *callback;
  char *arg;
  BIO *b;
  BIO *pBVar2;
  int iVar3;
  BIO *pBVar4;
  int *piVar5;
  long in_stack_ffffffc0;
  long in_stack_ffffffc4;
  
  b = param_3;
  BIO_clear_flags(param_1,0xf);
  piVar5 = (int *)param_1->ptr;
  do {
    pBVar4 = param_1->next_bio;
    while( true ) {
      if (pBVar4 != (BIO *)0x0) {
        iVar1 = BIO_write(pBVar4,param_2,(int)param_3);
        BIO_copy_next_retry(param_1);
        return iVar1;
      }
      iVar1 = *piVar5;
      if (iVar1 == 2) goto LAB_00529194;
      if (iVar1 == 3) break;
      if (iVar1 != 1) {
        return 0;
      }
      param_4 = 0x660000;
      if ((char *)piVar5[1] == (char *)0x0) {
        iVar3 = 0x6f;
        iVar1 = 0xd2;
LAB_005292d4:
        ERR_put_error(0x20,100,iVar3,"bss_acpt.c",iVar1);
        return -1;
      }
      iVar1 = BIO_get_accept_socket((char *)piVar5[1],piVar5[6]);
      if (iVar1 == -1) {
        return -1;
      }
      if ((piVar5[3] != 0) && (iVar3 = BIO_socket_nbio(iVar1,1), iVar3 == 0)) {
        (*(code *)PTR_close_006a994c)(iVar1);
        iVar3 = 0x6a;
        iVar1 = 0xdd;
        goto LAB_005292d4;
      }
      pBVar4 = param_1->next_bio;
      piVar5[2] = iVar1;
      param_1->num = iVar1;
      *piVar5 = 2;
    }
    *piVar5 = 2;
LAB_00529194:
    BIO_clear_flags(param_1,0xf);
    iVar1 = piVar5[2];
    param_1->retry_reason = 0;
    iVar1 = BIO_accept(iVar1,(char **)(piVar5 + 4));
    if (iVar1 == -2) {
      BIO_set_flags(param_1,0xc);
      param_1->retry_reason = 3;
      return -1;
    }
    if (iVar1 < 0) {
      return iVar1;
    }
    iVar3 = 1;
    pBVar4 = BIO_new_socket(iVar1,1);
    if (pBVar4 == (BIO *)0x0) {
      return 0;
    }
    callback = (callback *)
               BIO_get_callback(param_1,iVar3,(char *)b,param_4,in_stack_ffffffc0,in_stack_ffffffc4)
    ;
    BIO_set_callback(pBVar4,callback);
    arg = BIO_get_callback_arg(param_1);
    BIO_set_callback_arg(pBVar4,arg);
    if ((piVar5[5] != 0) && (iVar1 = BIO_socket_nbio(iVar1,1), iVar1 == 0)) {
      ERR_put_error(0x20,100,0x69,"bss_acpt.c",0x103);
LAB_00529358:
      BIO_free(pBVar4);
      return 0;
    }
    b = pBVar4;
    if ((((BIO *)piVar5[7] != (BIO *)0x0) &&
        ((b = BIO_dup_chain((BIO *)piVar5[7]), b == (BIO *)0x0 ||
         (pBVar2 = BIO_push(b,pBVar4), pBVar2 == (BIO *)0x0)))) ||
       (pBVar2 = BIO_push(param_1,b), pBVar4 = b, pBVar2 == (BIO *)0x0)) goto LAB_00529358;
    *piVar5 = 3;
  } while( true );
}

