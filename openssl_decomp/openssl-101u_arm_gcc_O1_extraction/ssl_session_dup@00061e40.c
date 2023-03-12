
SSL_SESSION * ssl_session_dup(void *param_1,int param_2)

{
  SSL_SESSION *ses;
  int iVar1;
  char *pcVar2;
  _STACK *p_Var3;
  void *pvVar4;
  
  ses = (SSL_SESSION *)CRYPTO_malloc(0xf4,"ssl_sess.c",0xee);
  if (ses != (SSL_SESSION *)0x0) {
    memcpy(ses,param_1,0xf4);
    ses->krb5_client_princ[0x30] = '\0';
    ses->krb5_client_princ[0x31] = '\0';
    ses->krb5_client_princ[0x32] = '\0';
    ses->krb5_client_princ[0x33] = '\0';
    ses->krb5_client_princ[0x34] = '\0';
    ses->krb5_client_princ[0x35] = '\0';
    ses->krb5_client_princ[0x36] = '\0';
    ses->krb5_client_princ[0x37] = '\0';
    iVar1 = *(int *)((int)param_1 + 0x98);
    ses->krb5_client_princ_len = 0;
    *(undefined4 *)ses->krb5_client_princ = 0;
    *(undefined4 *)(ses->krb5_client_princ + 0x2c) = 0;
    *(undefined4 *)(ses->krb5_client_princ + 0x40) = 0;
    *(undefined4 *)(ses->krb5_client_princ + 0x48) = 0;
    *(undefined4 *)(ses->krb5_client_princ + 0x50) = 0;
    *(undefined4 *)(ses->krb5_client_princ + 0x54) = 0;
    *(undefined4 *)(ses->krb5_client_princ + 0x60) = 0;
    *(undefined4 *)(ses->krb5_client_princ + 0x38) = 0;
    *(undefined4 *)(ses->krb5_client_princ + 0x3c) = 0;
    *(undefined4 *)(ses->krb5_client_princ + 0x14) = 1;
    if (iVar1 != 0) {
      CRYPTO_add_lock((int *)(iVar1 + 0x78),1,0xf,"ssl_sess.c",0x111);
    }
    if (*(int *)((int)param_1 + 0x9c) != 0) {
      CRYPTO_add_lock((int *)(*(int *)((int)param_1 + 0x9c) + 0x10),1,3,"ssl_sess.c",0x114);
    }
    if (*(char **)((int)param_1 + 0x8c) != (char *)0x0) {
      pcVar2 = BUF_strdup(*(char **)((int)param_1 + 0x8c));
      ses->krb5_client_princ_len = (uint)pcVar2;
      if (pcVar2 == (char *)0x0) goto LAB_00061fa8;
    }
    if (*(char **)((int)param_1 + 0x90) != (char *)0x0) {
      pcVar2 = BUF_strdup(*(char **)((int)param_1 + 0x90));
      *(char **)ses->krb5_client_princ = pcVar2;
      if (pcVar2 == (char *)0x0) goto LAB_00061fa8;
    }
    if (*(_STACK **)((int)param_1 + 0xbc) != (_STACK *)0x0) {
      p_Var3 = sk_dup(*(_STACK **)((int)param_1 + 0xbc));
      *(_STACK **)(ses->krb5_client_princ + 0x2c) = p_Var3;
      if (p_Var3 == (_STACK *)0x0) goto LAB_00061fa8;
    }
    iVar1 = CRYPTO_dup_ex_data(3,(CRYPTO_EX_DATA *)(ses->krb5_client_princ + 0x30),
                               (CRYPTO_EX_DATA *)((int)param_1 + 0xc0));
    if (iVar1 != 0) {
      if (*(char **)((int)param_1 + 0xd0) != (char *)0x0) {
        pcVar2 = BUF_strdup(*(char **)((int)param_1 + 0xd0));
        *(char **)(ses->krb5_client_princ + 0x40) = pcVar2;
        if (pcVar2 == (char *)0x0) goto LAB_00061fa8;
      }
      if (*(void **)((int)param_1 + 0xd8) != (void *)0x0) {
        pvVar4 = BUF_memdup(*(void **)((int)param_1 + 0xd8),*(size_t *)((int)param_1 + 0xd4));
        *(void **)(ses->krb5_client_princ + 0x48) = pvVar4;
        if (pvVar4 == (void *)0x0) goto LAB_00061fa8;
      }
      if (*(void **)((int)param_1 + 0xe0) != (void *)0x0) {
        pvVar4 = BUF_memdup(*(void **)((int)param_1 + 0xe0),*(size_t *)((int)param_1 + 0xdc));
        *(void **)(ses->krb5_client_princ + 0x50) = pvVar4;
        if (pvVar4 == (void *)0x0) goto LAB_00061fa8;
      }
      if (param_2 == 0) {
        *(undefined4 *)(ses->krb5_client_princ + 0x5c) = 0;
        *(undefined4 *)(ses->krb5_client_princ + 0x58) = 0;
      }
      else {
        pvVar4 = BUF_memdup(*(void **)((int)param_1 + 0xe4),*(size_t *)((int)param_1 + 0xe8));
        *(void **)(ses->krb5_client_princ + 0x54) = pvVar4;
        if (pvVar4 == (void *)0x0) goto LAB_00061fa8;
      }
      if (*(char **)((int)param_1 + 0xf0) != (char *)0x0) {
        pcVar2 = BUF_strdup(*(char **)((int)param_1 + 0xf0));
        *(char **)(ses->krb5_client_princ + 0x60) = pcVar2;
        if (pcVar2 == (char *)0x0) goto LAB_00061fa8;
      }
      return ses;
    }
  }
LAB_00061fa8:
  ERR_put_error(0x14,0x15c,0x41,"ssl_sess.c",0x15d);
  SSL_SESSION_free(ses);
  return (SSL_SESSION *)0x0;
}

