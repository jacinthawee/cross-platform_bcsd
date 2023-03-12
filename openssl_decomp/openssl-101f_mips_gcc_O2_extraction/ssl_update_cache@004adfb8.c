
void ssl_update_cache(int param_1,uint param_2)

{
  char cVar1;
  int iVar2;
  long tm;
  SSL_CTX *pSVar3;
  uint uVar4;
  
  if ((*(SSL_SESSION **)(param_1 + 0xc0))->session_id_length == 0) {
    return;
  }
  pSVar3 = *(SSL_CTX **)(param_1 + 0x170);
  uVar4 = pSVar3->session_cache_mode;
  if (((uVar4 & param_2) != 0) && (*(int *)(param_1 + 0x6c) == 0)) {
    if ((uVar4 & 0x200) == 0) {
      iVar2 = SSL_CTX_add_session(pSVar3,*(SSL_SESSION **)(param_1 + 0xc0));
      if (iVar2 == 0) goto LAB_004ae064;
      pSVar3 = *(SSL_CTX **)(param_1 + 0x170);
    }
    if (pSVar3->new_session_cb != (_func_3087 *)0x0) {
      CRYPTO_add_lock((int *)(*(int *)(param_1 + 0xc0) + 0xa4),1,0xe,"ssl_lib.c",0x96d);
      iVar2 = (**(code **)(*(int *)(param_1 + 0x170) + 0x28))
                        (param_1,*(undefined4 *)(param_1 + 0xc0));
      if (iVar2 == 0) {
        SSL_SESSION_free(*(SSL_SESSION **)(param_1 + 0xc0));
      }
    }
  }
LAB_004ae064:
  if (((uVar4 & 0x80) == 0) && (param_2 == (uVar4 & param_2))) {
    pSVar3 = *(SSL_CTX **)(param_1 + 0x170);
    if ((param_2 & 1) == 0) {
      cVar1 = *(char *)((int)&(pSVar3->stats).sess_accept_good + 3);
    }
    else {
      cVar1 = *(char *)((int)&(pSVar3->stats).sess_connect_good + 3);
    }
    if (cVar1 == -1) {
      tm = (*(code *)PTR_time_006aabe4)(0);
      SSL_CTX_flush_sessions(pSVar3,tm);
      return;
    }
  }
  return;
}

