
undefined4 ssl_clear_bad_session(SSL *param_1)

{
  uint uVar1;
  int iVar2;
  SSL_SESSION *pSVar3;
  code *pcVar4;
  code *pcVar5;
  _func_3154 *p_Var6;
  SSL_SESSION *data;
  bool bVar7;
  
  if ((((param_1->session != (SSL_SESSION *)0x0) && (-1 < param_1->shutdown << 0x1f)) &&
      (uVar1 = SSL_state(param_1), (uVar1 & 0x3000) == 0)) &&
     (iVar2 = SSL_state(param_1), -1 < iVar2 << 0x11)) {
    data = param_1->session;
    p_Var6 = param_1->psk_server_callback;
    if ((data != (SSL_SESSION *)0x0) && (data->session_id_length != 0)) {
      CRYPTO_lock(9,0xc,"ssl_sess.c",0x2c6);
      pSVar3 = (SSL_SESSION *)lh_retrieve(*(_LHASH **)(p_Var6 + 0x10),data);
      if (data == pSVar3) {
        pSVar3 = (SSL_SESSION *)lh_delete(*(_LHASH **)(p_Var6 + 0x10),data);
        pcVar5 = *(code **)(data->krb5_client_princ + 0x3c);
        if ((pcVar5 != (code *)0x0) &&
           (pcVar4 = *(code **)(data->krb5_client_princ + 0x38), pcVar4 != (code *)0x0)) {
          if (pcVar5 == p_Var6 + 0x1c) {
            bVar7 = pcVar4 != p_Var6 + 0x18;
            if (bVar7) {
              *(code **)(p_Var6 + 0x1c) = pcVar4;
            }
            if (bVar7) {
              *(code **)(pcVar4 + 0xcc) = pcVar5;
            }
            else {
              pcVar5 = (code *)0x0;
            }
            if (!bVar7) {
              *(code **)(p_Var6 + 0x18) = pcVar5;
            }
            if (!bVar7) {
              *(code **)(p_Var6 + 0x1c) = pcVar5;
            }
          }
          else {
            bVar7 = pcVar4 == p_Var6 + 0x18;
            if (!bVar7) {
              *(code **)(pcVar5 + 200) = pcVar4;
            }
            if (bVar7) {
              *(code **)(p_Var6 + 0x18) = pcVar5;
            }
            else {
              pcVar4 = *(code **)(data->krb5_client_princ + 0x38);
            }
            if (bVar7) {
              *(code **)(pcVar5 + 200) = pcVar4;
            }
            if (!bVar7) {
              *(code **)(pcVar4 + 0xcc) = pcVar5;
            }
          }
          *(undefined4 *)(data->krb5_client_princ + 0x3c) = 0;
          *(undefined4 *)(data->krb5_client_princ + 0x38) = 0;
        }
        CRYPTO_lock(10,0xc,"ssl_sess.c",0x2ce);
        pcVar5 = *(code **)(p_Var6 + 0x2c);
        *(undefined4 *)(pSVar3->krb5_client_princ + 4) = 1;
        if (pcVar5 != (code *)0x0) {
          (*pcVar5)(p_Var6,pSVar3);
        }
        SSL_SESSION_free(pSVar3);
      }
      else {
        CRYPTO_lock(10,0xc,"ssl_sess.c",0x2ce);
      }
    }
    return 1;
  }
  return 0;
}

