
SSL * ssl_ctrl(SSL *param_1,int param_2,SSL *param_3,SSL *param_4)

{
  BIO *pBVar1;
  _func_3149 *p_Var2;
  SSL *pSVar3;
  SSL **ppSVar4;
  SSL *pSVar5;
  SSL *ret_code;
  SSL *pSVar6;
  SSL *pSVar7;
  SSL **ppSVar8;
  int iVar9;
  SSL *pSVar10;
  
  iVar9 = param_2 + -0x6d;
  ppSVar8 = (SSL **)param_1->handshake_func;
  if (iVar9 != 0) {
    iVar9 = 1;
  }
  pSVar6 = *ppSVar8;
  if (pSVar6 != (SSL *)0x0) {
    iVar9 = 0;
  }
  if (iVar9 != 0) {
LAB_0006a97c:
    return (SSL *)0x0;
  }
  switch(param_2) {
  case 1:
    SSL_shutdown(pSVar6);
    if (pSVar6->handshake_func == (_func_3149 *)pSVar6->method->ssl_connect) {
      SSL_set_connect_state(pSVar6);
    }
    else if (pSVar6->handshake_func == (_func_3149 *)pSVar6->method->ssl_accept) {
      SSL_set_accept_state(pSVar6);
    }
    SSL_clear(pSVar6);
    pBVar1 = (BIO *)param_1->server;
    if ((pBVar1 != (bio_st *)0x0) || (pBVar1 = pSVar6->rbio, pBVar1 != (bio_st *)0x0)) {
      param_2 = 1;
      goto LAB_0006aa20;
    }
    goto LAB_0006aa3a;
  default:
    pBVar1 = pSVar6->rbio;
    goto LAB_0006aa20;
  case 3:
  case 0xe:
    goto LAB_0006a97c;
  case 6:
    pBVar1 = (BIO *)param_1->server;
    if ((pBVar1 != (BIO *)0x0) && (pBVar1 != pSVar6->rbio)) {
      SSL_set_bio(pSVar6,pBVar1,pBVar1);
      CRYPTO_add_lock(&((bio_st *)param_1->server)->references,1,0x15,"bio_ssl.c",0x191);
      return (SSL *)0x1;
    }
    goto LAB_0006aa3a;
  case 7:
    if (param_1 == param_4) {
      if (pSVar6->rbio != pSVar6->wbio) {
        BIO_free_all(pSVar6->wbio);
      }
      if ((bio_st *)param_1->server != (bio_st *)0x0) {
        CRYPTO_add_lock(&((bio_st *)param_1->server)->references,-1,0x15,"bio_ssl.c",0x19e);
      }
      pSVar6->wbio = (BIO *)0x0;
      pSVar6->rbio = (BIO *)0x0;
      return (SSL *)0x1;
    }
    goto LAB_0006aa3a;
  case 8:
    ret_code = (SSL *)param_1->wbio;
    break;
  case 9:
    param_1->wbio = (BIO *)param_3;
    ret_code = (SSL *)0x1;
    break;
  case 10:
    ret_code = (SSL *)SSL_pending(pSVar6);
    if (ret_code == (SSL *)0x0) {
      pBVar1 = pSVar6->rbio;
      param_2 = 10;
      param_3 = ret_code;
      param_4 = ret_code;
      goto LAB_0006aa20;
    }
    break;
  case 0xb:
    BIO_clear_flags((BIO *)param_1,0xf);
    ret_code = (SSL *)BIO_ctrl(pSVar6->wbio,0xb,(long)param_3,param_4);
    BIO_copy_next_retry((BIO *)param_1);
    break;
  case 0xc:
    ppSVar8 = (SSL **)param_4->handshake_func;
    if (*ppSVar8 != (SSL *)0x0) {
      SSL_free(*ppSVar8);
      ppSVar8 = (SSL **)param_4->handshake_func;
    }
    pSVar6 = SSL_dup(pSVar6);
    p_Var2 = param_1->handshake_func;
    ppSVar4 = (SSL **)param_4->handshake_func;
    pSVar10 = *(SSL **)(p_Var2 + 8);
    pSVar7 = *(SSL **)(p_Var2 + 0xc);
    pSVar5 = *(SSL **)(p_Var2 + 0x10);
    pSVar3 = *(SSL **)(p_Var2 + 0x14);
    *ppSVar8 = pSVar6;
    ret_code = *ppSVar4;
    ppSVar4[2] = pSVar10;
    ppSVar4[3] = pSVar7;
    ppSVar4[4] = pSVar5;
    if (ret_code != (SSL *)0x0) {
      ret_code = (SSL *)0x1;
    }
    ppSVar4[5] = pSVar3;
    break;
  case 0xd:
    pBVar1 = pSVar6->wbio;
    param_2 = 0xd;
    goto LAB_0006aa20;
  case 0xf:
    SSL_get_info_callback(pSVar6,param_2,(int)param_3);
    ret_code = (SSL *)0x1;
    param_4->version = (int)pSVar6;
    break;
  case 0x65:
    BIO_clear_flags((BIO *)param_1,0xf);
    param_1->rwstate = 0;
    ret_code = (SSL *)SSL_do_handshake(pSVar6);
    iVar9 = SSL_get_error(pSVar6,(int)ret_code);
    if (iVar9 == 3) {
      BIO_set_flags((BIO *)param_1,10);
    }
    else if (iVar9 == 7) {
      BIO_set_flags((BIO *)param_1,0xc);
      param_1->rwstate = ((bio_st *)param_1->server)->retry_reason;
    }
    else if (iVar9 == 2) {
      BIO_set_flags((BIO *)param_1,9);
    }
    break;
  case 0x69:
    pBVar1 = pSVar6->rbio;
    param_2 = 0x69;
LAB_0006aa20:
    pSVar6 = (SSL *)BIO_ctrl(pBVar1,param_2,(long)param_3,param_4);
    return pSVar6;
  case 0x6d:
    if (pSVar6 != (SSL *)0x0) {
      SSL_shutdown(pSVar6);
      if (param_1->wbio != (BIO *)0x0) {
        if ((param_1->rbio != (BIO *)0x0) && (*ppSVar8 != (SSL *)0x0)) {
          SSL_free(*ppSVar8);
        }
        param_1->rbio = (BIO *)0x0;
        param_1->bbio = (BIO *)0x0;
      }
      if (param_1->handshake_func != (_func_3149 *)0x0) {
        CRYPTO_free(param_1->handshake_func);
      }
      ppSVar8 = (SSL **)CRYPTO_malloc(0x18,"bio_ssl.c",0x6c);
      if (ppSVar8 == (SSL **)0x0) {
        ERR_put_error(0x20,0x76,0x41,"bio_ssl.c",0x6f);
        return (SSL *)0x0;
      }
      memset(ppSVar8,0,0x18);
      param_1->handshake_func = (_func_3149 *)ppSVar8;
      param_1->rbio = (BIO *)0x0;
      param_1->bbio = (BIO *)0x0;
    }
    param_1->wbio = (BIO *)param_3;
    *ppSVar8 = param_4;
    pBVar1 = SSL_get_rbio(param_4);
    if (pBVar1 != (BIO *)0x0) {
      if ((BIO *)param_1->server != (BIO *)0x0) {
        BIO_push(pBVar1,(BIO *)param_1->server);
      }
      param_1->server = (int)pBVar1;
      CRYPTO_add_lock(&pBVar1->references,1,0x15,"bio_ssl.c",0x16d);
    }
    ret_code = (SSL *)0x1;
    param_1->rbio = (BIO *)0x1;
    break;
  case 0x6e:
    ret_code = param_4;
    if (param_4 != (SSL *)0x0) {
      param_4->version = (int)pSVar6;
      ret_code = (SSL *)0x1;
    }
    break;
  case 0x77:
    if (param_3 != (SSL *)0x0) {
      SSL_set_connect_state(pSVar6);
      return (SSL *)0x1;
    }
    SSL_set_accept_state(pSVar6);
LAB_0006aa3a:
    ret_code = (SSL *)0x1;
    break;
  case 0x7d:
    ret_code = ppSVar8[2];
    if (0x1ff < (int)param_3) {
      ppSVar8[2] = param_3;
    }
    break;
  case 0x7e:
    ret_code = ppSVar8[1];
    break;
  case 0x7f:
    ret_code = ppSVar8[4];
    if ((int)param_3 < 0x3c) {
      param_3 = (SSL *)0x5;
    }
    ppSVar8[4] = param_3;
    pSVar6 = (SSL *)time((time_t *)0x0);
    ppSVar8[5] = pSVar6;
  }
  return ret_code;
}

