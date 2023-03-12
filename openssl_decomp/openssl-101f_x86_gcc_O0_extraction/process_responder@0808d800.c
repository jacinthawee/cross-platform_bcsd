
OCSP_RESPONSE *
process_responder(BIO *param_1,OCSP_REQUEST *param_2,char *param_3,char *param_4,void *param_5,
                 int param_6,_STACK *param_7,int param_8)

{
  byte bVar1;
  BIO *bp;
  long lVar2;
  int iVar3;
  OCSP_REQ_CTX *rctx;
  void *pvVar4;
  int iVar5;
  SSL_METHOD *meth;
  BIO *b;
  OCSP_RESPONSE *pOVar6;
  __fd_mask *p_Var7;
  int in_GS_OFFSET;
  __fd_mask *__writefds;
  SSL_CTX *local_c8;
  int local_b0;
  OCSP_RESPONSE *local_ac;
  timeval local_a8;
  uint local_a0 [32];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  bp = BIO_new_connect(param_3);
  if (bp == (BIO *)0x0) {
    pOVar6 = (OCSP_RESPONSE *)0x0;
    BIO_printf(param_1,"Error creating connect BIO\n");
    goto LAB_0808da07;
  }
  if (param_5 != (void *)0x0) {
    BIO_ctrl(bp,100,1,param_5);
  }
  local_c8 = (SSL_CTX *)0x0;
  if (param_6 != 1) {
LAB_0808d889:
    local_ac = (OCSP_RESPONSE *)0x0;
    if (param_8 == -1) {
      lVar2 = BIO_ctrl(bp,0x65,0,(void *)0x0);
      if (0 < lVar2) goto LAB_0808da47;
LAB_0808dbb3:
      BIO_puts(param_1,"Error connecting BIO\n");
    }
    else {
      BIO_ctrl(bp,0x66,1,(void *)0x0);
      lVar2 = BIO_ctrl(bp,0x65,0,(void *)0x0);
      if (0 < lVar2) {
LAB_0808da47:
        lVar2 = BIO_ctrl(bp,0x69,0,&local_b0);
        if (0 < lVar2) goto LAB_0808d95f;
LAB_0808da61:
        BIO_puts(param_1,"Can\'t get connection fd\n");
        goto LAB_0808d9d7;
      }
      iVar3 = BIO_test_flags(bp,8);
      if (iVar3 == 0) goto LAB_0808dbb3;
      lVar2 = BIO_ctrl(bp,0x69,0,&local_b0);
      if (lVar2 < 1) goto LAB_0808da61;
      p_Var7 = (__fd_mask *)local_a0;
      for (iVar3 = 0x20; iVar3 != 0; iVar3 = iVar3 + -1) {
        *p_Var7 = 0;
        p_Var7 = p_Var7 + 1;
      }
      iVar3 = __fdelt_chk(local_b0);
      local_a8.tv_usec = 0;
      bVar1 = (byte)(local_b0 >> 0x1f);
      local_a0[iVar3] =
           local_a0[iVar3] | 1 << (((char)local_b0 + (bVar1 >> 3) & 0x1f) - (bVar1 >> 3) & 0x1f);
      local_a8.tv_sec = param_8;
      iVar3 = select(local_b0 + 1,(fd_set *)0x0,(fd_set *)local_a0,(fd_set *)0x0,&local_a8);
      if (iVar3 == 0) {
        BIO_puts(param_1,"Timeout on connect\n");
        goto LAB_0808dbc7;
      }
LAB_0808d95f:
      rctx = OCSP_sendreq_new(bp,param_4,(OCSP_REQUEST *)0x0,-1);
      if (rctx != (OCSP_REQ_CTX *)0x0) {
        for (iVar3 = 0; iVar5 = sk_num(param_7), iVar3 < iVar5; iVar3 = iVar3 + 1) {
          pvVar4 = sk_value(param_7,iVar3);
          iVar5 = OCSP_REQ_CTX_add1_header
                            (rctx,*(char **)((int)pvVar4 + 4),*(char **)((int)pvVar4 + 8));
          if (iVar5 == 0) goto LAB_0808d9cb;
        }
        iVar3 = OCSP_REQ_CTX_set1_req(rctx,param_2);
        if (iVar3 != 0) {
          do {
            if (param_8 == -1) goto LAB_0808dbeb;
            iVar3 = OCSP_sendreq_nbio(&local_ac,rctx);
            if (iVar3 != -1) goto LAB_0808d9cb;
            p_Var7 = (__fd_mask *)local_a0;
            for (iVar3 = 0x20; iVar3 != 0; iVar3 = iVar3 + -1) {
              *p_Var7 = 0;
              p_Var7 = p_Var7 + 1;
            }
            iVar3 = __fdelt_chk(local_b0);
            local_a8.tv_usec = 0;
            local_a8.tv_sec = param_8;
            bVar1 = (byte)(local_b0 >> 0x1f);
            local_a0[iVar3] =
                 local_a0[iVar3] |
                 1 << (((char)local_b0 + (bVar1 >> 3) & 0x1f) - (bVar1 >> 3) & 0x1f);
            iVar3 = BIO_test_flags(bp,1);
            if (iVar3 == 0) {
              iVar3 = BIO_test_flags(bp,2);
              if (iVar3 == 0) {
                BIO_puts(param_1,"Unexpected retry condition\n");
                goto LAB_0808d9cb;
              }
              p_Var7 = ((fd_set *)0x0)->fds_bits;
              __writefds = (__fd_mask *)local_a0;
            }
            else {
              __writefds = (__fd_mask *)0x0;
              p_Var7 = (__fd_mask *)local_a0;
            }
            iVar3 = select(local_b0 + 1,(fd_set *)p_Var7,(fd_set *)__writefds,(fd_set *)0x0,
                           &local_a8);
            if (iVar3 == 0) {
              BIO_puts(param_1,"Timeout on request\n");
              goto LAB_0808d9cb;
            }
          } while (iVar3 != -1);
          BIO_puts(param_1,"Select error\n");
        }
        goto LAB_0808d9cb;
      }
    }
    goto LAB_0808dbc7;
  }
  meth = SSLv23_client_method();
  local_c8 = SSL_CTX_new(meth);
  if (local_c8 != (SSL_CTX *)0x0) {
    SSL_CTX_ctrl(local_c8,0x21,4,(void *)0x0);
    b = BIO_new_ssl(local_c8,1);
    bp = BIO_push(b,bp);
    goto LAB_0808d889;
  }
  pOVar6 = (OCSP_RESPONSE *)0x0;
  BIO_printf(param_1,"Error creating SSL context.\n");
LAB_0808d9e7:
  BIO_free_all(bp);
  goto LAB_0808d9f3;
LAB_0808dbeb:
  do {
    iVar3 = OCSP_sendreq_nbio(&local_ac,rctx);
  } while (iVar3 == -1);
LAB_0808d9cb:
  OCSP_REQ_CTX_free(rctx);
LAB_0808d9d7:
  pOVar6 = local_ac;
  if (local_ac == (OCSP_RESPONSE *)0x0) {
LAB_0808dbc7:
    pOVar6 = (OCSP_RESPONSE *)0x0;
    BIO_printf(bio_err,"Error querying OCSP responsder\n");
  }
  if (bp != (BIO *)0x0) goto LAB_0808d9e7;
LAB_0808d9f3:
  if (local_c8 != (SSL_CTX *)0x0) {
    SSL_CTX_free(local_c8);
  }
LAB_0808da07:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return pOVar6;
}

