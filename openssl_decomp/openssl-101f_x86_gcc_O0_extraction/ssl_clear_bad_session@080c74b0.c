
undefined4 ssl_clear_bad_session(SSL *param_1)

{
  SSL_SESSION *data;
  _func_3154 *p_Var1;
  code *pcVar2;
  code *pcVar3;
  uint uVar4;
  SSL_SESSION *mode;
  void *pvVar5;
  int iVar6;
  char *pcVar7;
  undefined4 uVar8;
  
  if ((((param_1->session == (SSL_SESSION *)0x0) || ((*(byte *)&param_1->shutdown & 1) != 0)) ||
      (uVar4 = SSL_state(param_1), (uVar4 & 0x3000) != 0)) ||
     (uVar4 = SSL_state(param_1), (uVar4 & 0x4000) != 0)) {
    return 0;
  }
  data = param_1->session;
  if ((data != (SSL_SESSION *)0x0) && (data->session_id_length != 0)) {
    p_Var1 = param_1->psk_server_callback;
    CRYPTO_lock(uVar4,9,&DAT_0000000c,(int)"ssl_sess.c");
    mode = (SSL_SESSION *)lh_retrieve(*(_LHASH **)(p_Var1 + 0x10),data);
    if (data == mode) {
      pvVar5 = lh_delete(*(_LHASH **)(p_Var1 + 0x10),data);
      pcVar2 = *(code **)(data->krb5_client_princ + 0x3c);
      if ((pcVar2 != (code *)0x0) &&
         (pcVar3 = *(code **)(data->krb5_client_princ + 0x38), pcVar3 != (code *)0x0)) {
        if (pcVar2 == p_Var1 + 0x1c) {
          if (pcVar3 == p_Var1 + 0x18) {
            *(undefined4 *)(p_Var1 + 0x18) = 0;
            *(undefined4 *)(p_Var1 + 0x1c) = 0;
          }
          else {
            *(code **)(p_Var1 + 0x1c) = pcVar3;
            *(code **)(pcVar3 + 0xcc) = pcVar2;
          }
        }
        else if (pcVar3 == p_Var1 + 0x18) {
          *(code **)(p_Var1 + 0x18) = pcVar2;
          *(code **)(pcVar2 + 200) = pcVar3;
        }
        else {
          *(code **)(pcVar2 + 200) = pcVar3;
          *(code **)(*(int *)(data->krb5_client_princ + 0x38) + 0xcc) = pcVar2;
        }
        *(undefined4 *)(data->krb5_client_princ + 0x3c) = 0;
        *(undefined4 *)(data->krb5_client_princ + 0x38) = 0;
      }
      uVar8 = 0x2ce;
      pcVar7 = "ssl_sess.c";
      CRYPTO_lock((int)pcVar2,10,&DAT_0000000c,(int)"ssl_sess.c");
      pcVar2 = *(code **)(p_Var1 + 0x2c);
      *(undefined4 *)((int)pvVar5 + 0x94) = 1;
      if (pcVar2 != (code *)0x0) {
        (*pcVar2)(p_Var1,pvVar5,pcVar7,uVar8);
      }
      iVar6 = CRYPTO_add_lock((int *)((int)pvVar5 + 0xa4),-1,0xe,"ssl_sess.c",0x2e4);
      if (iVar6 < 1) {
        SSL_SESSION_free_part_2();
        return 1;
      }
    }
    else {
      CRYPTO_lock((int)mode,10,&DAT_0000000c,(int)"ssl_sess.c");
    }
  }
  return 1;
}

