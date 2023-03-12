
SSL_CTX * process_responder(BIO *param_1,OCSP_REQUEST *param_2,char *param_3,char *param_4,
                           void *param_5,int param_6,_STACK *param_7,int param_8)

{
  BIO *bp;
  long lVar1;
  long lVar2;
  int iVar3;
  OCSP_REQ_CTX *rctx;
  void *pvVar4;
  int iVar5;
  SSL_METHOD *meth;
  BIO *b;
  SSL_CTX *ctx;
  SSL_CTX *pSVar6;
  int local_b8;
  SSL_CTX *local_b4;
  timeval local_b0;
  fd_set fStack_a8;
  
  bp = BIO_new_connect(param_3);
  if (bp == (BIO *)0x0) {
    BIO_printf(param_1,"Error creating connect BIO\n");
    return (SSL_CTX *)0x0;
  }
  if (param_5 != (void *)0x0) {
    BIO_ctrl(bp,100,1,param_5);
  }
  if (param_6 != 1) {
    ctx = (SSL_CTX *)0x0;
    if (param_8 != -1) goto LAB_0003fd1a;
LAB_0003fe9c:
    local_b4 = (SSL_CTX *)0x0;
    lVar1 = BIO_ctrl(bp,0x65,0,(void *)0x0);
    pSVar6 = ctx;
    if (lVar1 < 1) goto LAB_0003fe40;
LAB_0003fd36:
    lVar2 = BIO_ctrl(bp,0x69,0,&local_b8);
    if (lVar2 < 0) {
      BIO_puts(bio_err,"Can\'t get connection fd\n");
      goto LAB_0003fe12;
    }
    if (param_8 != -1 && lVar1 < 1) {
      memset(&fStack_a8,0,0x80);
      iVar3 = __fdelt_chk(local_b8);
      local_b0.tv_usec = 0;
      local_b0.tv_sec = param_8;
      fStack_a8.fds_bits[iVar3] = fStack_a8.fds_bits[iVar3] | 1 << (local_b8 % 0x20 & 0xffU);
      iVar3 = select(local_b8 + 1,(fd_set *)0x0,&fStack_a8,(fd_set *)0x0,&local_b0);
      if (iVar3 == 0) {
        BIO_puts(param_1,"Timeout on connect\n");
        goto LAB_0003fe4e;
      }
    }
    rctx = OCSP_sendreq_new(bp,param_4,(OCSP_REQUEST *)0x0,-1);
    if (rctx != (OCSP_REQ_CTX *)0x0) {
      iVar3 = 0;
      do {
        iVar5 = sk_num(param_7);
        if (iVar5 <= iVar3) {
          iVar3 = OCSP_REQ_CTX_set1_req(rctx,param_2);
          if (iVar3 != 0) {
            if (param_8 == -1) goto LAB_0003fe00;
            goto LAB_0003febc;
          }
          break;
        }
        pvVar4 = sk_value(param_7,iVar3);
        iVar5 = OCSP_REQ_CTX_add1_header
                          (rctx,*(char **)((int)pvVar4 + 4),*(char **)((int)pvVar4 + 8));
        iVar3 = iVar3 + 1;
      } while (iVar5 != 0);
      goto LAB_0003fe0c;
    }
    goto LAB_0003fe4e;
  }
  meth = SSLv23_client_method();
  ctx = SSL_CTX_new(meth);
  if (ctx != (SSL_CTX *)0x0) {
    SSL_CTX_ctrl(ctx,0x21,4,(void *)0x0);
    b = BIO_new_ssl(ctx,1);
    bp = BIO_push(b,bp);
    if (param_8 == -1) goto LAB_0003fe9c;
LAB_0003fd1a:
    local_b4 = (SSL_CTX *)0x0;
    BIO_ctrl(bp,0x66,1,(void *)0x0);
    lVar1 = BIO_ctrl(bp,0x65,0,(void *)0x0);
    pSVar6 = ctx;
    if ((0 < lVar1) || (iVar3 = BIO_test_flags(bp,8), iVar3 != 0)) goto LAB_0003fd36;
LAB_0003fe40:
    BIO_puts(param_1,"Error connecting BIO\n");
    pSVar6 = ctx;
    goto LAB_0003fe4e;
  }
  BIO_printf(param_1,"Error creating SSL context.\n");
  pSVar6 = ctx;
  goto LAB_0003fe18;
LAB_0003fe00:
  do {
    iVar3 = OCSP_sendreq_nbio((OCSP_RESPONSE **)&local_b4,rctx);
  } while (iVar3 == -1);
  goto LAB_0003fe0c;
  while( true ) {
    memset(&fStack_a8,0,0x80);
    iVar3 = __fdelt_chk(local_b8);
    local_b0.tv_usec = 0;
    local_b0.tv_sec = param_8;
    fStack_a8.fds_bits[iVar3] = fStack_a8.fds_bits[iVar3] | 1 << (local_b8 % 0x20 & 0xffU);
    iVar3 = BIO_test_flags(bp,1);
    if (iVar3 == 0) {
      iVar3 = BIO_test_flags(bp,2);
      if (iVar3 == 0) {
        BIO_puts(param_1,"Unexpected retry condition\n");
        goto LAB_0003fe0c;
      }
      iVar3 = select(local_b8 + 1,(fd_set *)0x0,&fStack_a8,(fd_set *)0x0,&local_b0);
    }
    else {
      iVar3 = select(local_b8 + 1,&fStack_a8,(fd_set *)0x0,(fd_set *)0x0,&local_b0);
    }
    if (iVar3 == 0) {
      BIO_puts(param_1,"Timeout on request\n");
      goto LAB_0003fe0c;
    }
    if (iVar3 == -1) break;
LAB_0003febc:
    iVar3 = OCSP_sendreq_nbio((OCSP_RESPONSE **)&local_b4,rctx);
    if (iVar3 != -1) goto LAB_0003fe0c;
  }
  BIO_puts(param_1,"Select error\n");
LAB_0003fe0c:
  OCSP_REQ_CTX_free(rctx);
LAB_0003fe12:
  ctx = local_b4;
  if (local_b4 == (SSL_CTX *)0x0) {
LAB_0003fe4e:
    ctx = (SSL_CTX *)0x0;
    BIO_printf(bio_err,"Error querying OCSP responder\n");
  }
  if (bp != (BIO *)0x0) {
LAB_0003fe18:
    BIO_free_all(bp);
  }
  if (pSVar6 != (SSL_CTX *)0x0) {
    SSL_CTX_free(pSVar6);
  }
  return ctx;
}

