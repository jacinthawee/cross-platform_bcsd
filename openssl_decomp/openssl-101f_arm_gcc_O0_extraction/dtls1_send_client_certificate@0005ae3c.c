
int dtls1_send_client_certificate(SSL *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  EVP_PKEY **ppEVar4;
  int iVar5;
  int *piVar6;
  ssl3_state_st *psVar7;
  bool bVar8;
  X509 *local_18;
  EVP_PKEY *local_14 [2];
  
  iVar5 = param_1->state;
  local_18 = (X509 *)0x0;
  local_14[0] = (EVP_PKEY *)0x0;
  if (iVar5 == 0x1170) {
    if ((((int **)param_1->cert == (int **)0x0) || (piVar6 = *(int **)param_1->cert, *piVar6 == 0))
       || (piVar6[1] == 0)) {
      iVar5 = 0x1171;
      param_1->state = 0x1171;
      goto LAB_0005aeb6;
    }
LAB_0005ae80:
    psVar7 = param_1->s3;
  }
  else {
    if (iVar5 != 0x1171) {
      if (iVar5 != 0x1172) goto LAB_0005ae64;
      goto LAB_0005ae80;
    }
LAB_0005aeb6:
    ppEVar4 = local_14;
    iVar1 = ssl_do_client_cert_cb(param_1,&local_18);
    iVar2 = iVar1;
    if (iVar1 < 0) {
      iVar5 = 4;
      iVar2 = -1;
    }
    if (iVar1 < 0) {
      param_1->rwstate = iVar5;
      return iVar2;
    }
    param_1->rwstate = 1;
    if (iVar1 == 1) {
      if ((local_14[0] == (EVP_PKEY *)0x0) || (local_18 == (X509 *)0x0)) {
        ppEVar4 = (EVP_PKEY **)0x6a;
        iVar1 = 0;
        ERR_put_error(0x14,0x105,0x6a,"d1_clnt.c",0x68e);
      }
      else {
        param_1->state = 0x1171;
        iVar1 = SSL_use_certificate(param_1,local_18);
        if ((iVar1 != 0) && (iVar1 = SSL_use_PrivateKey(param_1,local_14[0]), iVar1 != 0)) {
          iVar1 = 1;
        }
      }
    }
    if (local_18 != (X509 *)0x0) {
      X509_free(local_18);
    }
    if (local_14[0] != (EVP_PKEY *)0x0) {
      EVP_PKEY_free(local_14[0]);
    }
    if (iVar1 != 0) goto LAB_0005ae80;
    bVar8 = param_1->version != 0x300;
    psVar7 = param_1->s3;
    if (bVar8) {
      ppEVar4 = (EVP_PKEY **)0x2;
    }
    if (!bVar8) {
      (psVar7->tmp).cert_req = 0;
      ssl3_send_alert(param_1,1,0x29);
      return 1;
    }
    (psVar7->tmp).cert_req = (int)ppEVar4;
  }
  iVar5 = (psVar7->tmp).cert_req;
  param_1->state = 0x1173;
  if (iVar5 == 2) {
    uVar3 = 0;
  }
  else {
    uVar3 = **(undefined4 **)param_1->cert;
  }
  iVar5 = dtls1_output_cert_chain(param_1,uVar3);
  param_1->init_off = 0;
  param_1->init_num = iVar5;
  dtls1_buffer_message(param_1,0);
LAB_0005ae64:
  iVar5 = dtls1_do_write(param_1,0x16);
  return iVar5;
}

