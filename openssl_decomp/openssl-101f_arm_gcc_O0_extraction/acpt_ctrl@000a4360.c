
int acpt_ctrl(BIO *param_1,int param_2,int param_3,int *param_4)

{
  BIO *b;
  callback *callback;
  BIO *b_00;
  BIO *pBVar1;
  void *ptr;
  char *pcVar2;
  int iVar3;
  int extraout_r1;
  int iVar4;
  int *piVar5;
  long in_stack_ffffffd8;
  long in_stack_ffffffdc;
  
  piVar5 = (int *)param_1->ptr;
  if (param_2 == 0x66) {
    piVar5[5] = param_3;
    return 1;
  }
  if (param_2 < 0x67) {
    if (param_2 == 9) {
      param_1->shutdown = param_3;
      return 1;
    }
    if (param_2 < 10) {
      if (param_2 == 1) {
        *piVar5 = 1;
        if (piVar5[2] != -1) {
          shutdown(piVar5[2],2);
          close(piVar5[2]);
          piVar5[2] = -1;
          param_1->num = -1;
        }
        param_1->flags = 0;
        return 0;
      }
      if (param_2 == 8) {
        return param_1->shutdown;
      }
      return 0;
    }
    if (param_2 < 0xb) {
      return 0;
    }
    if (0xc < param_2) {
      if (param_2 != 0x65) {
        return 0;
      }
      iVar4 = *piVar5;
      pcVar2 = (char *)0x2;
      if (iVar4 == 2) goto LAB_000a4496;
      if (iVar4 != 3) {
        if (iVar4 != 1) {
          return 0;
        }
        if ((char *)piVar5[1] == (char *)0x0) {
          ERR_put_error(0x20,100,0x6f,"bss_acpt.c",0xd4);
          return -1;
        }
        iVar4 = BIO_get_accept_socket((char *)piVar5[1],piVar5[6]);
        if (iVar4 == -1) {
          return -1;
        }
        if ((piVar5[3] != 0) && (iVar3 = BIO_socket_nbio(iVar4,1), iVar3 == 0)) {
          close(iVar4);
          ERR_put_error(0x20,100,0x6a,"bss_acpt.c",0xe0);
          return -1;
        }
        piVar5[2] = iVar4;
        param_1->num = iVar4;
        *piVar5 = 2;
        return 1;
      }
      while (param_1->next_bio == (bio_st *)0x0) {
        *piVar5 = 2;
LAB_000a4496:
        if (param_1->next_bio == (bio_st *)0x0) {
          BIO_clear_flags(param_1,0xf);
          param_1->retry_reason = 0;
          iVar4 = BIO_accept(piVar5[2],(char **)(piVar5 + 4));
          iVar3 = iVar4 + 2;
          if (iVar3 == 0) {
            BIO_set_flags(param_1,0xc);
            param_1->retry_reason = 3;
            return -1;
          }
          if (-1 < iVar4) {
            b = BIO_new_socket(iVar4,1);
            if (b == (BIO *)0x0) {
              return 0;
            }
            callback = (callback *)
                       BIO_get_callback(param_1,extraout_r1,pcVar2,iVar3,in_stack_ffffffd8,
                                        in_stack_ffffffdc);
            BIO_set_callback(b,callback);
            pcVar2 = BIO_get_callback_arg(param_1);
            BIO_set_callback_arg(b,pcVar2);
            if ((piVar5[5] == 0) || (iVar4 = BIO_socket_nbio(iVar4,1), iVar4 != 0)) {
              b_00 = b;
              if ((((BIO *)piVar5[7] == (BIO *)0x0) ||
                  ((b_00 = BIO_dup_chain((BIO *)piVar5[7]), b_00 != (BIO *)0x0 &&
                   (pBVar1 = BIO_push(b_00,b), pBVar1 != (BIO *)0x0)))) &&
                 (pBVar1 = BIO_push(param_1,b_00), b = b_00, pBVar1 != (BIO *)0x0)) {
                *piVar5 = 3;
                return 1;
              }
            }
            else {
              ERR_put_error(0x20,100,0x69,"bss_acpt.c",0x107);
            }
            BIO_free(b);
            return 0;
          }
          return iVar4;
        }
        *piVar5 = 3;
      }
    }
  }
  else {
    if (param_2 != 0x76) {
      if (param_2 < 0x77) {
        if (param_2 == 0x68) {
          param_1->init = 1;
          iVar4 = *param_4;
          param_1->num = iVar4;
          piVar5[2] = iVar4;
          *piVar5 = 2;
          param_1->shutdown = param_3;
          return 1;
        }
        if (param_2 != 0x69) {
          return 0;
        }
        if (param_1->init != 0) {
          if (param_4 != (int *)0x0) {
            *param_4 = piVar5[2];
          }
          return piVar5[2];
        }
      }
      else {
        if (param_2 == 0x83) {
          piVar5[6] = param_3;
          return 1;
        }
        if (param_2 == 0x84) {
          return piVar5[6];
        }
        if (param_2 != 0x7c) {
          return 0;
        }
        if ((param_1->init != 0) && (param_4 != (int *)0x0)) {
          *param_4 = piVar5[1];
          return 1;
        }
      }
      return -1;
    }
    if (param_4 != (int *)0x0) {
      if (param_3 == 0) {
        ptr = (void *)piVar5[1];
        param_1->init = 1;
        if (ptr != (void *)0x0) {
          CRYPTO_free(ptr);
        }
        pcVar2 = BUF_strdup((char *)param_4);
        piVar5[1] = (int)pcVar2;
        return 1;
      }
      if (param_3 == 1) {
        piVar5[3] = 1;
        return 1;
      }
      if (param_3 == 2) {
        if ((BIO *)piVar5[7] != (BIO *)0x0) {
          BIO_free((BIO *)piVar5[7]);
        }
        piVar5[7] = (int)param_4;
        return 1;
      }
    }
  }
  return 1;
}

