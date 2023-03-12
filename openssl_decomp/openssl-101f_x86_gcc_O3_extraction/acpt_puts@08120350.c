
int acpt_puts(BIO *param_1,char *param_2)

{
  int *piVar1;
  size_t len;
  int iVar2;
  callback *callback;
  char *arg;
  BIO *pBVar3;
  BIO *pBVar4;
  int iVar5;
  char *in_stack_ffffffcc;
  int in_stack_ffffffd0;
  long in_stack_ffffffd4;
  char **ip_port;
  BIO *local_24;
  
  len = strlen(param_2);
  BIO_clear_flags(param_1,0xf);
  piVar1 = (int *)param_1->ptr;
  ip_port = (char **)(piVar1 + 4);
  do {
    pBVar3 = param_1->next_bio;
    while( true ) {
      if (pBVar3 != (BIO *)0x0) {
        iVar2 = BIO_write(pBVar3,param_2,len);
        BIO_copy_next_retry(param_1);
        return iVar2;
      }
      iVar2 = *piVar1;
      if (iVar2 == 2) goto LAB_08120427;
      if (iVar2 == 3) break;
      if (iVar2 != 1) {
        return 0;
      }
      if ((char *)piVar1[1] == (char *)0x0) {
        iVar5 = 0xd4;
        iVar2 = 0x6f;
LAB_0812054d:
        ERR_put_error(0x20,100,iVar2,"bss_acpt.c",iVar5);
        return -1;
      }
      iVar2 = BIO_get_accept_socket((char *)piVar1[1],piVar1[6]);
      if (iVar2 == -1) {
        return -1;
      }
      if ((piVar1[3] != 0) && (iVar5 = BIO_socket_nbio(iVar2,1), iVar5 == 0)) {
        close(iVar2);
        iVar5 = 0xe0;
        iVar2 = 0x6a;
        goto LAB_0812054d;
      }
      pBVar3 = param_1->next_bio;
      piVar1[2] = iVar2;
      param_1->num = iVar2;
      *piVar1 = 2;
    }
    *piVar1 = 2;
LAB_08120427:
    BIO_clear_flags(param_1,0xf);
    param_1->retry_reason = 0;
    iVar2 = BIO_accept(piVar1[2],ip_port);
    if (iVar2 == -2) {
      BIO_set_flags(param_1,0xc);
      param_1->retry_reason = 3;
      return -1;
    }
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar5 = 1;
    local_24 = BIO_new_socket(iVar2,1);
    if (local_24 == (BIO *)0x0) {
      return 0;
    }
    callback = (callback *)
               BIO_get_callback(param_1,iVar5,in_stack_ffffffcc,in_stack_ffffffd0,in_stack_ffffffd4,
                                (long)ip_port);
    BIO_set_callback(local_24,callback);
    arg = BIO_get_callback_arg(param_1);
    BIO_set_callback_arg(local_24,arg);
    if ((piVar1[5] != 0) && (iVar2 = BIO_socket_nbio(iVar2,1), iVar2 == 0)) {
      ERR_put_error(0x20,100,0x69,"bss_acpt.c",0x107);
LAB_08120597:
      BIO_free(local_24);
      return 0;
    }
    pBVar3 = local_24;
    if ((((BIO *)piVar1[7] != (BIO *)0x0) &&
        ((pBVar3 = BIO_dup_chain((BIO *)piVar1[7]), pBVar3 == (BIO *)0x0 ||
         (pBVar4 = BIO_push(pBVar3,local_24), pBVar4 == (BIO *)0x0)))) ||
       (pBVar4 = BIO_push(param_1,pBVar3), local_24 = pBVar3, pBVar4 == (BIO *)0x0))
    goto LAB_08120597;
    *piVar1 = 3;
  } while( true );
}

