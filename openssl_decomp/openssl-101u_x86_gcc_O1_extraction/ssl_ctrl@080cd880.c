
SSL * __regparm1 ssl_ctrl(int param_1,SSL *param_2,int param_3,SSL *param_4,SSL *param_5)

{
  _func_3149 *p_Var1;
  int *piVar2;
  _func_599 *UNRECOVERED_JUMPTABLE;
  _func_603 *p_Var3;
  SSL **ppSVar4;
  BIO *pBVar5;
  int iVar6;
  SSL *pSVar7;
  SSL *pSVar8;
  long lVar9;
  uint uVar10;
  int in_stack_ffffffc8;
  int in_stack_ffffffcc;
  
  ppSVar4 = (SSL **)param_2->handshake_func;
  pSVar8 = *ppSVar4;
  if ((pSVar8 == (SSL *)0x0) && (param_1 = 0, param_3 != 0x6d)) {
    return (SSL *)0x0;
  }
  switch(param_3) {
  case 1:
    SSL_shutdown(pSVar8);
    if (pSVar8->handshake_func == (_func_3149 *)pSVar8->method->ssl_connect) {
      SSL_set_connect_state(pSVar8);
    }
    else if (pSVar8->handshake_func == (_func_3149 *)pSVar8->method->ssl_accept) {
      SSL_set_accept_state(pSVar8);
    }
    SSL_clear(pSVar8);
    pBVar5 = (BIO *)param_2->server;
    if ((pBVar5 == (BIO *)0x0) && (pBVar5 = pSVar8->rbio, pBVar5 == (BIO *)0x0)) {
      return (SSL *)0x1;
    }
    param_3 = 1;
    goto LAB_080cd923;
  case 3:
  case 0xe:
    return (SSL *)0x0;
  case 6:
    pBVar5 = (BIO *)param_2->server;
    if (pBVar5 == (BIO *)0x0) {
      return (SSL *)0x1;
    }
    if (pBVar5 == pSVar8->rbio) {
      return (SSL *)0x1;
    }
    SSL_set_bio(pSVar8,pBVar5,pBVar5);
    CRYPTO_add_lock(&((bio_st *)param_2->server)->references,1,0x15,"bio_ssl.c",0x183);
    return (SSL *)0x1;
  case 7:
    if (param_2 == param_5) {
      if (pSVar8->rbio != pSVar8->wbio) {
        BIO_free_all(pSVar8->wbio);
      }
      if ((bio_st *)param_2->server != (bio_st *)0x0) {
        CRYPTO_add_lock(&((bio_st *)param_2->server)->references,-1,0x15,"bio_ssl.c",400);
      }
      pSVar8->wbio = (BIO *)0x0;
      pSVar8->rbio = (BIO *)0x0;
    }
    return (SSL *)0x1;
  case 8:
    return (SSL *)param_2->wbio;
  case 9:
    param_2->wbio = (BIO *)param_4;
    return (SSL *)0x1;
  case 10:
    pSVar7 = (SSL *)SSL_pending(pSVar8);
    if (pSVar7 != (SSL *)0x0) {
      return pSVar7;
    }
    param_5 = (SSL *)0x0;
    param_4 = (SSL *)0x0;
    param_3 = 10;
    break;
  case 0xb:
    BIO_clear_flags((BIO *)param_2,0xf);
    pSVar8 = (SSL *)BIO_ctrl(pSVar8->wbio,0xb,(long)param_4,param_5);
    BIO_copy_next_retry((BIO *)param_2);
    return pSVar8;
  case 0xc:
    ppSVar4 = (SSL **)param_5->handshake_func;
    if (*ppSVar4 != (SSL *)0x0) {
      SSL_free(*ppSVar4);
      ppSVar4 = (SSL **)param_5->handshake_func;
    }
    pSVar8 = SSL_dup(pSVar8);
    p_Var1 = param_2->handshake_func;
    *ppSVar4 = pSVar8;
    piVar2 = (int *)param_5->handshake_func;
    piVar2[2] = *(int *)(p_Var1 + 8);
    piVar2[3] = *(int *)(p_Var1 + 0xc);
    iVar6 = *(int *)(p_Var1 + 0x14);
    piVar2[4] = *(int *)(p_Var1 + 0x10);
    piVar2[5] = iVar6;
    return (SSL *)(uint)(*piVar2 != 0);
  case 0xd:
    param_3 = 0xd;
    pBVar5 = pSVar8->wbio;
    goto LAB_080cd923;
  case 0xf:
    SSL_get_info_callback(pSVar8,in_stack_ffffffc8,in_stack_ffffffcc);
    param_5->version = param_1;
    return (SSL *)0x1;
  case 0x65:
    BIO_clear_flags((BIO *)param_2,0xf);
    param_2->rwstate = 0;
    pSVar7 = (SSL *)SSL_do_handshake(pSVar8);
    iVar6 = SSL_get_error(pSVar8,(int)pSVar7);
    if (iVar6 == 3) {
      BIO_set_flags((BIO *)param_2,10);
      return pSVar7;
    }
    if (iVar6 < 4) {
      if (iVar6 == 2) {
        BIO_set_flags((BIO *)param_2,9);
        return pSVar7;
      }
      return pSVar7;
    }
    if (iVar6 == 4) {
      BIO_set_flags((BIO *)param_2,0xc);
      param_2->rwstate = 1;
      return pSVar7;
    }
    if (iVar6 == 7) {
      BIO_set_flags((BIO *)param_2,0xc);
      param_2->rwstate = ((bio_st *)param_2->server)->retry_reason;
      return pSVar7;
    }
    return pSVar7;
  case 0x69:
    param_3 = 0x69;
    break;
  case 0x6d:
    if (pSVar8 != (SSL *)0x0) {
      SSL_shutdown(pSVar8);
      if (param_2->wbio != (BIO *)0x0) {
        if ((param_2->rbio != (BIO *)0x0) && (*ppSVar4 != (SSL *)0x0)) {
          SSL_free(*ppSVar4);
        }
        param_2->rbio = (BIO *)0x0;
        param_2->bbio = (BIO *)0x0;
      }
      if (param_2->handshake_func != (_func_3149 *)0x0) {
        CRYPTO_free(param_2->handshake_func);
      }
      ppSVar4 = (SSL **)CRYPTO_malloc(0x18,"bio_ssl.c",0x6a);
      if (ppSVar4 == (SSL **)0x0) {
        ERR_put_error(0x20,0x76,0x41,"bio_ssl.c",0x6c);
        return (SSL *)0x0;
      }
      *ppSVar4 = (SSL *)0x0;
      ppSVar4[5] = (SSL *)0x0;
      uVar10 = 0;
      do {
        *(undefined4 *)(((uint)(ppSVar4 + 1) & 0xfffffffc) + uVar10) = 0;
        uVar10 = uVar10 + 4;
      } while (uVar10 < ((int)ppSVar4 + (0x18 - ((uint)(ppSVar4 + 1) & 0xfffffffc)) & 0xfffffffc));
      param_2->rbio = (BIO *)0x0;
      param_2->handshake_func = (_func_3149 *)ppSVar4;
      param_2->bbio = (BIO *)0x0;
    }
    param_2->wbio = (BIO *)param_4;
    *ppSVar4 = param_5;
    pBVar5 = SSL_get_rbio(param_5);
    if (pBVar5 != (BIO *)0x0) {
      if ((BIO *)param_2->server != (BIO *)0x0) {
        BIO_push(pBVar5,(BIO *)param_2->server);
      }
      param_2->server = (int)pBVar5;
      CRYPTO_add_lock(&pBVar5->references,1,0x15,"bio_ssl.c",0x162);
    }
    param_2->rbio = (BIO *)0x1;
    return (SSL *)0x1;
  case 0x6e:
    if (param_5 == (SSL *)0x0) {
      return (SSL *)0x0;
    }
    param_5->version = (int)pSVar8;
    return (SSL *)0x1;
  case 0x77:
    if (param_4 == (SSL *)0x0) {
      SSL_set_accept_state(pSVar8);
      return (SSL *)0x1;
    }
    SSL_set_connect_state(pSVar8);
    return (SSL *)0x1;
  case 0x7d:
    pSVar8 = ppSVar4[2];
    if (0x1ff < (int)param_4) {
      ppSVar4[2] = param_4;
      return pSVar8;
    }
    return pSVar8;
  case 0x7e:
    return ppSVar4[1];
  case 0x7f:
    pSVar8 = ppSVar4[4];
    if ((int)param_4 < 0x3c) {
      param_4 = (SSL *)0x5;
    }
    ppSVar4[4] = param_4;
    pSVar7 = (SSL *)time((time_t *)0x0);
    ppSVar4[5] = pSVar7;
    return pSVar8;
  }
  pBVar5 = pSVar8->rbio;
LAB_080cd923:
  if (pBVar5 == (bio_st *)0x0) {
    return (SSL *)0x0;
  }
  if ((pBVar5->method == (BIO_METHOD *)0x0) ||
     (UNRECOVERED_JUMPTABLE = pBVar5->method->ctrl, UNRECOVERED_JUMPTABLE == (_func_599 *)0x0)) {
    ERR_put_error(0x20,0x67,0x79,"bio_lib.c",0x15d);
    pSVar8 = (SSL *)0xfffffffe;
  }
  else {
    p_Var3 = pBVar5->callback;
    if (p_Var3 == (_func_603 *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x08116477. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      pSVar8 = (SSL *)(*UNRECOVERED_JUMPTABLE)(pBVar5,param_3,(long)param_4,param_5);
      return pSVar8;
    }
    pSVar8 = (SSL *)(*p_Var3)(pBVar5,6,(char *)param_5,param_3,(long)param_4,1);
    if (0 < (int)pSVar8) {
      lVar9 = (*pBVar5->method->ctrl)(pBVar5,param_3,(long)param_4,param_5);
      pSVar8 = (SSL *)(*p_Var3)(pBVar5,0x86,(char *)param_5,param_3,(long)param_4,lVar9);
    }
  }
  return pSVar8;
}

