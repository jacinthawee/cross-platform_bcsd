
undefined4 ssl_clear_bad_session(SSL *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  SSL_SESSION *pSVar3;
  int iVar4;
  code *pcVar5;
  int iVar6;
  code *pcVar7;
  SSL_SESSION *pSVar8;
  _func_3154 *p_Var9;
  
  if ((param_1->session == (SSL_SESSION *)0x0) || ((param_1->shutdown & 1U) != 0)) {
    return 0;
  }
  uVar1 = SSL_state(param_1);
  if (((uVar1 & 0x3000) == 0) && (uVar1 = SSL_state(param_1), (uVar1 & 0x4000) == 0)) {
    pSVar8 = param_1->session;
    uVar2 = 1;
    if (pSVar8 != (SSL_SESSION *)0x0) {
      if (pSVar8->session_id_length != 0) {
        p_Var9 = param_1->psk_server_callback;
        CRYPTO_lock(9,0xc,"ssl_sess.c",0x350);
        pSVar3 = (SSL_SESSION *)
                 (*(code *)PTR_lh_retrieve_006a73b0)(*(undefined4 *)(p_Var9 + 0x10),pSVar8);
        if (pSVar8 != pSVar3) {
          CRYPTO_lock(10,0xc,"ssl_sess.c",0x358);
          return 1;
        }
        iVar4 = (*(code *)PTR_lh_delete_006a8390)(*(undefined4 *)(p_Var9 + 0x10),pSVar8);
        pcVar7 = *(code **)(pSVar8->krb5_client_princ + 0x3c);
        if (pcVar7 != (code *)0x0) {
          pcVar5 = *(code **)(pSVar8->krb5_client_princ + 0x38);
          if (pcVar5 != (code *)0x0) {
            if (pcVar7 == p_Var9 + 0x1c) {
              if (pcVar5 == p_Var9 + 0x18) {
                *(undefined4 *)(p_Var9 + 0x18) = 0;
                *(undefined4 *)(p_Var9 + 0x1c) = 0;
              }
              else {
                *(code **)(p_Var9 + 0x1c) = pcVar5;
                *(code **)(pcVar5 + 0xcc) = pcVar7;
              }
            }
            else if (pcVar5 == p_Var9 + 0x18) {
              *(code **)(p_Var9 + 0x18) = pcVar7;
              *(code **)(pcVar7 + 200) = pcVar5;
            }
            else {
              *(code **)(pcVar7 + 200) = pcVar5;
              *(code **)(*(int *)(pSVar8->krb5_client_princ + 0x38) + 0xcc) = pcVar7;
            }
            *(undefined4 *)(pSVar8->krb5_client_princ + 0x3c) = 0;
            *(undefined4 *)(pSVar8->krb5_client_princ + 0x38) = 0;
          }
        }
        CRYPTO_lock(10,0xc,"ssl_sess.c",0x358);
        pcVar7 = *(code **)(p_Var9 + 0x2c);
        *(undefined4 *)(iVar4 + 0x94) = 1;
        if (pcVar7 != (code *)0x0) {
          (*pcVar7)(p_Var9,iVar4);
        }
        iVar6 = CRYPTO_add_lock((int *)(iVar4 + 0xa4),-1,0xe,"ssl_sess.c",0x36c);
        if (iVar6 < 1) {
          SSL_SESSION_free_part_2(iVar4);
          return 1;
        }
      }
      uVar2 = 1;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

