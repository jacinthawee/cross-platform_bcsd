
int acpt_read(BIO *param_1,void *param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  BIO *pBVar3;
  callback *callback;
  char *arg;
  BIO *b;
  BIO *pBVar4;
  int iVar5;
  char *in_stack_ffffffcc;
  int in_stack_ffffffd0;
  long in_stack_ffffffd4;
  long in_stack_ffffffd8;
  
  BIO_clear_flags(param_1,0xf);
  piVar1 = (int *)param_1->ptr;
  do {
    pBVar3 = param_1->next_bio;
    while( true ) {
      if (pBVar3 != (BIO *)0x0) {
        iVar2 = BIO_read(pBVar3,param_2,param_3);
        BIO_copy_next_retry(param_1);
        return iVar2;
      }
      iVar2 = *piVar1;
      if (iVar2 == 2) goto LAB_0811dce6;
      if (iVar2 == 3) break;
      if (iVar2 != 1) {
        return 0;
      }
      if ((char *)piVar1[1] == (char *)0x0) {
        iVar5 = 0xd2;
        iVar2 = 0x6f;
LAB_0811ddfd:
        ERR_put_error(0x20,100,iVar2,"bss_acpt.c",iVar5);
        return -1;
      }
      iVar2 = BIO_get_accept_socket((char *)piVar1[1],piVar1[6]);
      if (iVar2 == -1) {
        return -1;
      }
      if ((piVar1[3] != 0) && (iVar5 = BIO_socket_nbio(iVar2,1), iVar5 == 0)) {
        close(iVar2);
        iVar5 = 0xdd;
        iVar2 = 0x6a;
        goto LAB_0811ddfd;
      }
      pBVar3 = param_1->next_bio;
      piVar1[2] = iVar2;
      param_1->num = iVar2;
      *piVar1 = 2;
    }
    *piVar1 = 2;
LAB_0811dce6:
    BIO_clear_flags(param_1,0xf);
    param_1->retry_reason = 0;
    iVar2 = BIO_accept(piVar1[2],(char **)(piVar1 + 4));
    if (iVar2 == -2) {
      BIO_set_flags(param_1,0xc);
      param_1->retry_reason = 3;
      return -1;
    }
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar5 = 1;
    pBVar3 = BIO_new_socket(iVar2,1);
    if (pBVar3 == (BIO *)0x0) {
      return 0;
    }
    callback = (callback *)
               BIO_get_callback(param_1,iVar5,in_stack_ffffffcc,in_stack_ffffffd0,in_stack_ffffffd4,
                                in_stack_ffffffd8);
    BIO_set_callback(pBVar3,callback);
    arg = BIO_get_callback_arg(param_1);
    BIO_set_callback_arg(pBVar3,arg);
    if ((piVar1[5] != 0) && (iVar2 = BIO_socket_nbio(iVar2,1), iVar2 == 0)) {
      ERR_put_error(0x20,100,0x69,"bss_acpt.c",0x103);
LAB_0811de47:
      BIO_free(pBVar3);
      return 0;
    }
    b = pBVar3;
    if ((((BIO *)piVar1[7] != (BIO *)0x0) &&
        ((b = BIO_dup_chain((BIO *)piVar1[7]), b == (BIO *)0x0 ||
         (pBVar4 = BIO_push(b,pBVar3), pBVar4 == (BIO *)0x0)))) ||
       (pBVar4 = BIO_push(param_1,b), pBVar3 = b, pBVar4 == (BIO *)0x0)) goto LAB_0811de47;
    *piVar1 = 3;
  } while( true );
}

