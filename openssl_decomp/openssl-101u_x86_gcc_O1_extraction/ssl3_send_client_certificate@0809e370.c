
undefined4 ssl3_send_client_certificate(SSL *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  stack_st_X509_NAME *ca_dn;
  uint uVar4;
  _func_3154 *p_Var5;
  ssl3_state_st *psVar6;
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
      goto LAB_0809e447;
    }
LAB_0809e3f9:
    psVar6 = param_1->s3;
LAB_0809e3fc:
    uVar2 = 0;
    iVar3 = (psVar6->tmp).cert_req;
    param_1->state = 0x1173;
    if (iVar3 != 2) {
      uVar2 = **(undefined4 **)param_1->cert;
    }
    iVar3 = ssl3_output_cert_chain(param_1,uVar2);
    if (iVar3 == 0) {
      ERR_put_error(0x14,0x97,0x44,"s3_clnt.c",0xcd8);
      ssl3_send_alert(param_1,2,0x50);
      param_1->state = 5;
      uVar2 = 0;
      goto LAB_0809e3bf;
    }
    param_1->init_num = iVar3;
    param_1->init_off = 0;
  }
  else {
    if (iVar3 == 0x1171) {
LAB_0809e447:
      p_Var5 = param_1->psk_server_callback;
      if (*(int *)(p_Var5 + 0xfc) == 0) {
LAB_0809e492:
        if (*(code **)(p_Var5 + 0x74) != (code *)0x0) {
          uVar4 = (**(code **)(p_Var5 + 0x74))(param_1,&local_18,&local_14);
          goto LAB_0809e4b2;
        }
        param_1->rwstate = 1;
        uVar4 = 0;
      }
      else {
        ca_dn = SSL_get_client_CA_list(param_1);
        uVar4 = ENGINE_load_ssl_client_cert
                          (*(ENGINE **)(param_1->psk_server_callback + 0xfc),param_1,ca_dn,&local_18
                           ,&local_14,(stack_st_X509 **)0x0,(UI_METHOD *)0x0,(void *)0x0);
        if (uVar4 == 0) {
          p_Var5 = param_1->psk_server_callback;
          goto LAB_0809e492;
        }
LAB_0809e4b2:
        if ((int)uVar4 < 0) {
          param_1->rwstate = 4;
          uVar2 = 0xffffffff;
          goto LAB_0809e3bf;
        }
        param_1->rwstate = 1;
        if (uVar4 == 1) {
          if ((local_14 == (EVP_PKEY *)0x0) || (local_18 == (X509 *)0x0)) {
            uVar4 = 0;
            ERR_put_error(0x14,0x97,0x6a,"s3_clnt.c",0xcbd);
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
      }
      if (local_18 != (X509 *)0x0) {
        X509_free(local_18);
      }
      if (local_14 != (EVP_PKEY *)0x0) {
        EVP_PKEY_free(local_14);
      }
      if (uVar4 != 0) goto LAB_0809e3f9;
      if (param_1->version == 0x300) {
        (param_1->s3->tmp).cert_req = 0;
        ssl3_send_alert(param_1,1,0x29);
        uVar2 = 1;
        goto LAB_0809e3bf;
      }
      psVar6 = param_1->s3;
      (psVar6->tmp).cert_req = 2;
      goto LAB_0809e3fc;
    }
    if (iVar3 == 0x1172) goto LAB_0809e3f9;
  }
  uVar2 = ssl3_do_write(param_1,0x16);
LAB_0809e3bf:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

