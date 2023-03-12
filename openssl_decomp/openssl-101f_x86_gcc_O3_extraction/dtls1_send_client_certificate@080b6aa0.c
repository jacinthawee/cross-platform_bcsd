
undefined4 dtls1_send_client_certificate(SSL *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  ssl3_state_st *psVar5;
  int in_GS_OFFSET;
  X509 *local_18;
  EVP_PKEY *local_14;
  int local_10;
  
  local_18 = (X509 *)0x0;
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_14 = (EVP_PKEY *)0x0;
  iVar3 = param_1->state;
  if (iVar3 == 0x1170) {
    if ((((int **)param_1->cert == (int **)0x0) || (piVar1 = *(int **)param_1->cert, *piVar1 == 0))
       || (piVar1[1] == 0)) {
      param_1->state = 0x1171;
      goto LAB_080b6b77;
    }
LAB_080b6b29:
    psVar5 = param_1->s3;
LAB_080b6b2c:
    uVar2 = 0;
    iVar3 = (psVar5->tmp).cert_req;
    param_1->state = 0x1173;
    if (iVar3 != 2) {
      uVar2 = **(undefined4 **)param_1->cert;
    }
    iVar3 = dtls1_output_cert_chain(param_1,uVar2);
    param_1->init_off = 0;
    param_1->init_num = iVar3;
    dtls1_buffer_message(param_1,0);
  }
  else {
    if (iVar3 == 0x1171) {
LAB_080b6b77:
      uVar4 = ssl_do_client_cert_cb(param_1,&local_18,&local_14);
      if ((int)uVar4 < 0) {
        param_1->rwstate = 4;
        uVar2 = 0xffffffff;
        goto LAB_080b6aef;
      }
      param_1->rwstate = 1;
      if (uVar4 == 1) {
        if ((local_14 == (EVP_PKEY *)0x0) || (local_18 == (X509 *)0x0)) {
          uVar4 = 0;
          ERR_put_error(0x14,0x105,0x6a,"d1_clnt.c",0x68e);
        }
        else {
          param_1->state = 0x1171;
          uVar4 = 0;
          iVar3 = SSL_use_certificate(param_1,local_18);
          if (iVar3 != 0) {
            iVar3 = SSL_use_PrivateKey(param_1,local_14);
            uVar4 = (uint)(iVar3 != 0);
          }
        }
      }
      if (local_18 != (X509 *)0x0) {
        X509_free(local_18);
      }
      if (local_14 != (EVP_PKEY *)0x0) {
        EVP_PKEY_free(local_14);
      }
      if (uVar4 != 0) goto LAB_080b6b29;
      if (param_1->version == 0x300) {
        (param_1->s3->tmp).cert_req = 0;
        ssl3_send_alert(param_1,1,0x29);
        uVar2 = 1;
        goto LAB_080b6aef;
      }
      psVar5 = param_1->s3;
      (psVar5->tmp).cert_req = 2;
      goto LAB_080b6b2c;
    }
    if (iVar3 == 0x1172) goto LAB_080b6b29;
  }
  uVar2 = dtls1_do_write(param_1,0x16);
LAB_080b6aef:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

