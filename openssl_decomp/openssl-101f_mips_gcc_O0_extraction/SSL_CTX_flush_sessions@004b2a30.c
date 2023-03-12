
void SSL_CTX_flush_sessions(SSL_CTX *ctx,long tm)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  SSL_SESSION *pSVar4;
  code *pcVar5;
  int iVar6;
  code *pcVar7;
  SSL_SESSION *pSVar8;
  int iVar9;
  _func_3154 *p_Var10;
  SSL_CTX *local_20;
  long local_1c;
  lhash_st_SSL_SESSION *local_18;
  int local_14;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  local_18 = ctx->sessions;
  local_14 = *(int *)PTR___stack_chk_guard_006aabf0;
  local_20 = ctx;
  if (local_18 != (lhash_st_SSL_SESSION *)0x0) {
    local_1c = tm;
    CRYPTO_lock(9,0xc,"ssl_sess.c",0x3e2);
    puVar1 = PTR_lh_doall_arg_006a94bc;
    iVar9 = local_18[8].dummy;
    local_18[8].dummy = 0;
    (*(code *)puVar1)(local_18,timeout_LHASH_DOALL_ARG,&local_20);
    ctx = (SSL_CTX *)&DAT_0000000a;
    local_18[8].dummy = iVar9;
    CRYPTO_lock(10,0xc,"ssl_sess.c",1000);
  }
  if (local_14 != *(int *)puVar2) {
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    if ((((SSL *)ctx)->session != (SSL_SESSION *)0x0) && ((((SSL *)ctx)->shutdown & 1U) == 0)) {
      uVar3 = SSL_state((SSL *)ctx);
      if (((((uVar3 & 0x3000) == 0) && (uVar3 = SSL_state((SSL *)ctx), (uVar3 & 0x4000) == 0)) &&
          (pSVar8 = ((SSL *)ctx)->session, pSVar8 != (SSL_SESSION *)0x0)) &&
         (pSVar8->session_id_length != 0)) {
        p_Var10 = ((SSL *)ctx)->psk_server_callback;
        CRYPTO_lock(9,0xc,"ssl_sess.c",0x2c6);
        pSVar4 = (SSL_SESSION *)
                 (*(code *)PTR_lh_retrieve_006a84b0)(*(undefined4 *)(p_Var10 + 0x10),pSVar8);
        if (pSVar8 == pSVar4) {
          iVar9 = (*(code *)PTR_lh_delete_006a94ac)(*(undefined4 *)(p_Var10 + 0x10),pSVar8);
          pcVar7 = *(code **)(pSVar8->krb5_client_princ + 0x3c);
          if (pcVar7 != (code *)0x0) {
            pcVar5 = *(code **)(pSVar8->krb5_client_princ + 0x38);
            if (pcVar5 != (code *)0x0) {
              if (pcVar7 == p_Var10 + 0x1c) {
                if (pcVar5 == p_Var10 + 0x18) {
                  *(undefined4 *)(p_Var10 + 0x18) = 0;
                  *(undefined4 *)(p_Var10 + 0x1c) = 0;
                }
                else {
                  *(code **)(p_Var10 + 0x1c) = pcVar5;
                  *(code **)(pcVar5 + 0xcc) = pcVar7;
                }
              }
              else if (pcVar5 == p_Var10 + 0x18) {
                *(code **)(p_Var10 + 0x18) = pcVar7;
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
          CRYPTO_lock(10,0xc,"ssl_sess.c",0x2ce);
          pcVar7 = *(code **)(p_Var10 + 0x2c);
          *(undefined4 *)(iVar9 + 0x94) = 1;
          if (pcVar7 != (code *)0x0) {
            (*pcVar7)(p_Var10,iVar9);
          }
          iVar6 = CRYPTO_add_lock((int *)(iVar9 + 0xa4),-1,0xe,"ssl_sess.c",0x2e4);
          if (iVar6 < 1) {
            SSL_SESSION_free_part_2(iVar9);
          }
        }
        else {
          CRYPTO_lock(10,0xc,"ssl_sess.c",0x2ce);
        }
      }
      return;
    }
    return;
  }
  return;
}

