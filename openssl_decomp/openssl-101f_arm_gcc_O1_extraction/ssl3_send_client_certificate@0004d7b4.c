
X509 * ssl3_send_client_certificate(SSL *param_1)

{
  X509 *pXVar1;
  X509 *pXVar2;
  undefined4 uVar3;
  stack_st_X509_NAME *ca_dn;
  int iVar4;
  stack_st_X509_NAME **ppsVar5;
  ssl3_state_st *psVar6;
  X509 **pcert;
  bool bVar7;
  X509 *local_18;
  EVP_PKEY *local_14 [2];
  
  iVar4 = param_1->state;
  ca_dn = (stack_st_X509_NAME *)0x0;
  local_18 = (X509 *)0x0;
  local_14[0] = (EVP_PKEY *)0x0;
  if (iVar4 == 0x1170) {
    if ((undefined4 *)param_1->cert != (undefined4 *)0x0) {
      ppsVar5 = *(stack_st_X509_NAME ***)param_1->cert;
      ca_dn = *ppsVar5;
      if ((ca_dn != (stack_st_X509_NAME *)0x0) && (ppsVar5[1] != (stack_st_X509_NAME *)0x0))
      goto LAB_0004d7f8;
    }
    param_1->state = 0x1171;
LAB_0004d826:
    pcert = (X509 **)param_1->psk_server_callback;
    pXVar1 = pcert[0x3f];
    if (pXVar1 == (X509 *)0x0) {
LAB_0004d856:
      pXVar1 = pcert[0x1d];
      if (pXVar1 != (X509 *)0x0) {
        ca_dn = (stack_st_X509_NAME *)local_14;
        pXVar1 = (X509 *)(*(code *)pXVar1)(param_1,&local_18);
        goto LAB_0004d866;
      }
      param_1->rwstate = 1;
    }
    else {
      ca_dn = SSL_get_client_CA_list(param_1);
      pcert = &local_18;
      pXVar1 = (X509 *)ENGINE_load_ssl_client_cert
                                 ((ENGINE *)pXVar1,param_1,ca_dn,pcert,local_14,
                                  (stack_st_X509 **)0x0,(UI_METHOD *)0x0,(void *)0x0);
      if (pXVar1 == (X509 *)0x0) {
        pcert = (X509 **)param_1->psk_server_callback;
        goto LAB_0004d856;
      }
LAB_0004d866:
      pXVar2 = pXVar1;
      if ((int)pXVar1 < 0) {
        pcert = (X509 **)&DAT_00000004;
        pXVar2 = (X509 *)0xffffffff;
      }
      if ((int)pXVar1 < 0) {
        param_1->rwstate = (int)pcert;
        return pXVar2;
      }
      param_1->rwstate = 1;
      if (pXVar1 == (X509 *)0x1) {
        if ((local_14[0] == (EVP_PKEY *)0x0) || (local_18 == (X509 *)0x0)) {
          ca_dn = (stack_st_X509_NAME *)0x6a;
          pXVar1 = (X509 *)0x0;
          ERR_put_error(0x14,0x97,0x6a,"s3_clnt.c",0xc35);
        }
        else {
          param_1->state = 0x1171;
          pXVar1 = (X509 *)SSL_use_certificate(param_1,local_18);
          if ((pXVar1 != (X509 *)0x0) &&
             (pXVar1 = (X509 *)SSL_use_PrivateKey(param_1,local_14[0]), pXVar1 != (X509 *)0x0)) {
            pXVar1 = (X509 *)0x1;
          }
        }
      }
    }
    if (local_18 != (X509 *)0x0) {
      X509_free(local_18);
    }
    if (local_14[0] != (EVP_PKEY *)0x0) {
      EVP_PKEY_free(local_14[0]);
    }
    if (pXVar1 != (X509 *)0x0) goto LAB_0004d7f8;
    bVar7 = param_1->version != 0x300;
    psVar6 = param_1->s3;
    if (bVar7) {
      ca_dn = (stack_st_X509_NAME *)0x2;
    }
    if (!bVar7) {
      (psVar6->tmp).cert_req = 0;
      ssl3_send_alert(param_1,1,0x29);
      return (X509 *)0x1;
    }
    (psVar6->tmp).cert_req = (int)ca_dn;
  }
  else {
    ca_dn = (stack_st_X509_NAME *)0x1171;
    if (iVar4 == 0x1171) goto LAB_0004d826;
    if (iVar4 != 0x1172) goto LAB_0004d7dc;
LAB_0004d7f8:
    psVar6 = param_1->s3;
  }
  iVar4 = (psVar6->tmp).cert_req;
  param_1->state = 0x1173;
  if (iVar4 == 2) {
    uVar3 = 0;
  }
  else {
    uVar3 = **(undefined4 **)param_1->cert;
  }
  iVar4 = ssl3_output_cert_chain(param_1,uVar3);
  param_1->init_off = 0;
  param_1->init_num = iVar4;
LAB_0004d7dc:
  pXVar1 = (X509 *)ssl3_do_write(param_1,0x16);
  return pXVar1;
}

