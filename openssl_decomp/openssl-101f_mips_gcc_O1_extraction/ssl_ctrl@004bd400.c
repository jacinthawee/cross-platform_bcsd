
SSL * ssl_ctrl(SSL *param_1,int param_2,SSL *param_3,SSL *param_4)

{
  undefined *puVar1;
  undefined *puVar2;
  SSL *pSVar3;
  int iVar4;
  int *piVar5;
  _func_3149 *p_Var6;
  BIO *pBVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  SSL *pSVar11;
  SSL **ppSVar12;
  
  puVar1 = PTR_time_006aabe4;
  ppSVar12 = (SSL **)param_1->handshake_func;
  pSVar11 = *ppSVar12;
  if (pSVar11 != (SSL *)0x0) {
    puVar2 = (&switchD_004bd454::switchdataD_0064a174)[param_2];
    switch(param_2) {
    default:
      pBVar7 = pSVar11->rbio;
      break;
    case 1:
      SSL_shutdown(pSVar11);
      if (pSVar11->handshake_func == (_func_3149 *)pSVar11->method->ssl_connect) {
        SSL_set_connect_state(pSVar11);
      }
      else if (pSVar11->handshake_func == (_func_3149 *)pSVar11->method->ssl_accept) {
        SSL_set_accept_state(pSVar11);
      }
      SSL_clear(pSVar11);
      pBVar7 = (BIO *)param_1->server;
      if (pBVar7 == (BIO *)0x0) {
        pBVar7 = pSVar11->rbio;
        if (pBVar7 == (BIO *)0x0) {
          return (SSL *)0x1;
        }
        param_2 = 1;
      }
      else {
        param_2 = 1;
      }
      break;
    case 3:
    case 0xe:
      return (SSL *)0x0;
    case 6:
      pBVar7 = (BIO *)param_1->server;
      if (pBVar7 == (BIO *)0x0) {
        return (SSL *)0x1;
      }
      if (pBVar7 == pSVar11->rbio) {
        return (SSL *)0x1;
      }
      SSL_set_bio(pSVar11,pBVar7,pBVar7);
      CRYPTO_add_lock((int *)(param_1->server + 0x2c),1,0x15,"bio_ssl.c",0x191);
      return (SSL *)0x1;
    case 7:
      if (param_1 != param_4) {
        return (SSL *)0x1;
      }
      if (pSVar11->rbio != pSVar11->wbio) {
        (*(code *)PTR_BIO_free_all_006a7f74)();
      }
      if (param_1->server != 0) {
        CRYPTO_add_lock((int *)(param_1->server + 0x2c),-1,0x15,"bio_ssl.c",0x19e);
      }
      pSVar11->wbio = (BIO *)0x0;
      pSVar11->rbio = (BIO *)0x0;
      return (SSL *)0x1;
    case 8:
      return (SSL *)param_1->wbio;
    case 9:
      param_1->wbio = (BIO *)param_3;
      return (SSL *)0x1;
    case 10:
      pSVar3 = (SSL *)SSL_pending(pSVar11);
      if (pSVar3 != (SSL *)0x0) {
        return pSVar3;
      }
      pBVar7 = pSVar11->rbio;
      param_4 = (SSL *)0x0;
      param_3 = (SSL *)0x0;
      param_2 = 10;
      break;
    case 0xb:
      (*(code *)PTR_BIO_clear_flags_006a9260)(param_1,0xf);
      pSVar11 = (SSL *)(*(code *)PTR_BIO_ctrl_006a7f18)(pSVar11->wbio,0xb,param_3,param_4);
      (*(code *)PTR_BIO_copy_next_retry_006a9554)(param_1);
      return pSVar11;
    case 0xc:
      ppSVar12 = (SSL **)param_4->handshake_func;
      if (*ppSVar12 != (SSL *)0x0) {
        SSL_free(*ppSVar12);
        ppSVar12 = (SSL **)param_4->handshake_func;
      }
      pSVar11 = SSL_dup(pSVar11);
      p_Var6 = param_1->handshake_func;
      piVar5 = (int *)param_4->handshake_func;
      iVar10 = *(int *)(p_Var6 + 8);
      iVar9 = *(int *)(p_Var6 + 0xc);
      iVar8 = *(int *)(p_Var6 + 0x10);
      *ppSVar12 = pSVar11;
      iVar4 = *(int *)(p_Var6 + 0x14);
      piVar5[2] = iVar10;
      piVar5[3] = iVar9;
      piVar5[4] = iVar8;
      piVar5[5] = iVar4;
      return (SSL *)(uint)(*piVar5 != 0);
    case 0xd:
      pBVar7 = pSVar11->wbio;
      param_2 = 0xd;
      break;
    case 0xf:
      SSL_get_info_callback(pSVar11,param_2,(int)param_3);
      param_4->version = (int)puVar2;
      return (SSL *)0x1;
    case 0x65:
      (*(code *)PTR_BIO_clear_flags_006a9260)(param_1,0xf);
      param_1->rwstate = 0;
      pSVar3 = (SSL *)SSL_do_handshake(pSVar11);
      iVar4 = SSL_get_error(pSVar11,(int)pSVar3);
      if (iVar4 == 3) {
        (*(code *)PTR_BIO_set_flags_006a8660)(param_1,10);
        return pSVar3;
      }
      if (iVar4 == 7) {
        (*(code *)PTR_BIO_set_flags_006a8660)(param_1,0xc);
        param_1->rwstate = *(int *)(param_1->server + 0x18);
        return pSVar3;
      }
      if (iVar4 == 2) {
        (*(code *)PTR_BIO_set_flags_006a8660)(param_1,9);
        return pSVar3;
      }
      return pSVar3;
    case 0x69:
      pBVar7 = pSVar11->rbio;
      param_2 = 0x69;
      break;
    case 0x6d:
      SSL_shutdown(pSVar11);
      if (param_1->wbio != (BIO *)0x0) {
        if ((param_1->rbio != (BIO *)0x0) && (*ppSVar12 != (SSL *)0x0)) {
          SSL_free(*ppSVar12);
        }
        param_1->rbio = (BIO *)0x0;
        param_1->bbio = (BIO *)0x0;
      }
      if (param_1->handshake_func != (_func_3149 *)0x0) {
        CRYPTO_free(param_1->handshake_func);
      }
      ppSVar12 = (SSL **)CRYPTO_malloc(0x18,"bio_ssl.c",0x6c);
      if (ppSVar12 == (SSL **)0x0) {
        (*(code *)PTR_ERR_put_error_006a9030)(0x20,0x76,0x41,"bio_ssl.c",0x6f);
        return (SSL *)0x0;
      }
      (*(code *)PTR_memset_006aab00)(ppSVar12,0,0x18);
      param_1->rbio = (BIO *)0x0;
      param_1->handshake_func = (_func_3149 *)ppSVar12;
      param_1->bbio = (BIO *)0x0;
      goto LAB_004bd48c;
    case 0x6e:
      if (param_4 == (SSL *)0x0) {
        return (SSL *)0x0;
      }
      param_4->version = (int)pSVar11;
      return (SSL *)0x1;
    case 0x77:
      if (param_3 == (SSL *)0x0) {
        SSL_set_accept_state(pSVar11);
        return (SSL *)0x1;
      }
      SSL_set_connect_state(pSVar11);
      return (SSL *)0x1;
    case 0x7d:
      pSVar11 = ppSVar12[2];
      if (0x1ff < (int)param_3) {
        ppSVar12[2] = param_3;
        return pSVar11;
      }
      return pSVar11;
    case 0x7e:
      return ppSVar12[1];
    case 0x7f:
      pSVar11 = ppSVar12[4];
      if ((int)param_3 < 0x3c) {
        param_3 = (SSL *)&DAT_00000005;
      }
      ppSVar12[4] = param_3;
      pSVar3 = (SSL *)(*(code *)puVar1)(0);
      ppSVar12[5] = pSVar3;
      return pSVar11;
    }
                    /* WARNING: Could not recover jumptable at 0x004bd5c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pSVar11 = (SSL *)(*(code *)PTR_BIO_ctrl_006a7f18)(pBVar7,param_2,param_3,param_4);
    return pSVar11;
  }
  if (param_2 != 0x6d) {
    return (SSL *)0x0;
  }
LAB_004bd48c:
  param_1->wbio = (BIO *)param_3;
  *ppSVar12 = param_4;
  pBVar7 = SSL_get_rbio(param_4);
  if (pBVar7 != (BIO *)0x0) {
    if (param_1->server != 0) {
      (*(code *)PTR_BIO_push_006a85c0)(pBVar7);
    }
    param_1->server = (int)pBVar7;
    CRYPTO_add_lock(&pBVar7->references,1,0x15,"bio_ssl.c",0x16d);
  }
  param_1->rbio = (BIO *)0x1;
  return (SSL *)0x1;
}

